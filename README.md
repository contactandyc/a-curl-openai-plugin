# An OpenAI API Library (C)

A small, fast **C** library for OpenAI’s HTTP APIs built on an evented cURL layer.
It provides a builder-style request API, streaming sinks, and helpers for **/v1/responses**, **/v1/chat/completions**, and **/v1/embeddings**—plus utilities for **structured outputs (JSON Schema)**.

> **Non‑affiliation:** This project is an independent library for interacting with the OpenAI API. It is not affiliated with, endorsed by, or sponsored by OpenAI. “OpenAI” and related marks are trademarks of OpenAI OpCo, LLC.

---

## Highlights

* **Event‑loop friendly**: built on `a-curl-library`’s `curl_event_loop_t`.
* **Builder API** per endpoint (init → configure → submit).
* **Streaming** via SSE with simple callbacks (text deltas, events, usage, errors).
* **Structured Outputs**: request validated JSON per schema; strict mode supported.
* **Chaining**: pass `previous_response_id` across calls.
* **Includes**: opt into specific streamed envelopes (e.g., text deltas, tool args).
* **Typed message parts**: text, image URLs, file IDs.
* **Utilities**: parsing helpers for usage, errors, and incomplete details.

---

## Requirements

* CMake ≥ **3.20**
* C compiler with **C23** (examples set `C_STANDARD 23`)
* Dependencies (as separate libraries):

    * `a-curl-library` (event loop, requests, resources)
    * `a-json-library` (JSON builder/parser)
    * `a-memory-library` (pool/buffer utilities)
* **Environment**: `OPENAI_API_KEY` must be set

---

## Getting started

### Install / link

If you’ve built and installed the library (and its deps) with CMake packages:

```cmake
find_package(an_openai_api_library CONFIG REQUIRED)
add_executable(app main.c)
target_link_libraries(app PRIVATE an_openai_api_library::an_openai_api_library)
```

> See `examples/` for complete, working CMake projects.

### Minimal text request (`/v1/responses`)

```c
#include "a-curl-library/curl_event_loop.h"
#include "a-curl-library/curl_event_request.h"
#include "a-curl-library/curl_resource.h"
#include "an-openai-api-library/plugins/v1/responses.h"
#include "an-openai-api-library/sinks/v1/responses.h"
#include <stdio.h>
#include <stdlib.h>

static void done(void*, curl_event_request_t*, bool ok,
                 const char* txt, int p, int c, int t) {
  if (!ok) { fputs("request failed\n", stderr); return; }
  puts(txt);
  fprintf(stderr, "(prompt=%d completion=%d total=%d)\n", p, c, t);
}

int main(void) {
  const char* key = getenv("OPENAI_API_KEY");
  if (!key || !*key) { fputs("OPENAI_API_KEY?\n", stderr); return 1; }

  curl_event_loop_t* loop = curl_event_loop_init(NULL,NULL);
  curl_event_res_id  kid  = curl_event_res_register(loop, strdup(key), free);

  curl_event_request_t* r =
      openai_v1_responses_init(loop, kid, "gpt-4o-mini");
  openai_v1_responses_sink(r, done, NULL);
  openai_v1_responses_input_text(r, "Explain quantum tunnelling briefly.");
  openai_v1_responses_submit(loop, r, 0);

  curl_event_loop_run(loop);
  curl_event_loop_destroy(loop);
}
```

### Streaming text (SSE)

```c
#include "an-openai-api-library/sinks/v1/responses_stream.h"

static void on_delta(void*, const char* utf8, size_t n) {
  fwrite(utf8, 1, n, stdout); fflush(stdout);
}
static void on_done(void*) { puts("\n[done]"); }

void example_stream(curl_event_loop_t* loop, curl_event_res_id kid) {
  curl_event_request_t* r = openai_v1_responses_init(loop, kid, "gpt-4o-mini");
  openai_v1_responses_set_stream(r, true);
  openai_v1_responses_include_stream_text_minimal(r); /* helper preset */

  openai_v1_responses_stream_callbacks_t cbs = {
    .on_text_delta = on_delta,
    .on_message_done = on_done
  };
  openai_v1_responses_stream_sink_init(r, &cbs, NULL);

  openai_v1_responses_input_text(r, "Write a haiku about autumn.");
  openai_v1_responses_submit(loop, r, 0);
}
```

### Structured Outputs (validated JSON)

```c
#include "a-json-library/ajson.h"
#include "a-memory-library/aml_pool.h"

/* Ask for a strict object: { city, tempC, conditions } */
static const char *SCHEMA =
  "{"
  " \"type\":\"object\","
  " \"properties\":{"
  "  \"city\":{\"type\":\"string\"},"
  "  \"tempC\":{\"type\":\"number\"},"
  "  \"conditions\":{\"type\":\"string\"}"
  " },"
  " \"required\":[\"city\",\"tempC\",\"conditions\"],"
  " \"additionalProperties\":false"
  "}";

static void done_struct(void*, curl_event_request_t*, bool ok,
                        const char* txt, int, int, int) {
  if (!ok || !txt) { fputs("fail\n", stderr); return; }
  aml_pool_t* pool = aml_pool_init(1024);
  ajson_t* obj = ajson_parse_string(pool, txt);  /* txt is JSON text */
  puts(ajson_stringify(pool, obj));
  aml_pool_destroy(pool);
}

/* ... create loop/kid ... */
curl_event_request_t* r = openai_v1_responses_init(loop, kid, "gpt-4o-mini");
openai_v1_responses_sink(r, done_struct, NULL);
openai_v1_responses_set_structured_output(r, "weather", SCHEMA, /*strict*/true);
openai_v1_responses_input_text(r, "Return today's Paris weather per schema.");
openai_v1_responses_submit(loop, r, 0);
```

---

## API surface (selected)

`/v1/responses` (builder):

* `openai_v1_responses_init(loop, api_key_id, model_id)`
* Inputs: `openai_v1_responses_input_text`, message builder (`begin_message`, `message_add_text`, `message_add_image_url`, `message_add_file_id`, `end_message`)
* Core knobs: `set_temperature`, `set_top_p`, `set_max_output_tokens`, `set_instructions`, `set_top_logprobs`, `set_truncation`
* Streaming & includes: `set_stream`, `set_stream_options_json`, `add_include`, `set_includes`, presets like `include_stream_text_minimal`, `include_reasoning_encrypted`, `include_refusal`
* Structured outputs: `set_structured_output(name, schema_json, strict)`, `set_structured_output_json`
* Tools: `add_tool_json`, `set_tool_choice_json`; parallel control (`set_parallel_tool_calls`, `set_max_tool_calls`)
* Chaining & deps: `chain_previous_response`, `add_dependency`
* Other: `set_metadata_kv`, `set_prompt_cache_key`, `set_service_tier`, `set_store`, `set_background`, `set_reasoning_json`, `set_safety_identifier`, prompt templates (`set_prompt`, `set_prompt_vars_json`, `set_prompt_var`)
* Submit: `openai_v1_responses_submit(loop, req, priority)`

Sinks (responses):

* **Blocking summary**: `openai_v1_responses_sink(req, complete_cb, arg)` → aggregated text + token usage.
* **Streaming**: `openai_v1_responses_stream_sink_init(req, &callbacks, arg)` with `on_text_delta`, `on_event`, `on_usage`, `on_error`, `on_completed`.

Companions:

* `openai_v1_responses_get/delete/cancel(loop, api_key_id, response_id, sink)`.

Chat Completions (`/v1/chat/completions`):

* `openai_v1_chat_completions_init`, `*_add_message`, knobs (`set_temperature`, `set_top_p`, `set_max_tokens`, penalties, `stream`, `set_user`), sink: `openai_v1_chat_completions_sink`.

Embeddings (`/v1/embeddings`):

* `openai_v1_embeddings_init`, inputs (`add_text`, `add_texts`), params (`set_dimensions`, `set_encoding_format`, `set_user`), sink: `openai_v1_embeddings_sink`.

Parsing helpers:

* `openai_responses_parse_output(pool, raw_json, &out)` → items, roles, aggregated text, usage.
* Optionals: `openai_responses_parse_error`, `openai_responses_parse_incomplete`, `openai_responses_parse_usage`.

---

## Examples

Two sets of ready‑to‑run samples:

* **Basic text**: `examples/responses_01_basic_text`
  Small blocking calls, temperature sweep, logprobs, chaining, cache key, etc.

* **Structured output**: `examples/responses_02_structured_output`
  Single object/arrays, nested shapes, validation errors, streaming entities, and chain/fan‑out demos.

Build any set:

```bash
cd examples/responses_01_basic_text
./build.sh

cd ../responses_02_structured_output
./build.sh
```

---

## Error handling & usage

* The blocking responses sink returns `success` and token counts `(prompt, completion, total)`.
* For raw JSON access (e.g., to inspect HTTP errors), use `a-curl-library`’s `memory_sink` and parse with:

    * `openai_responses_parse_error(...)`
    * `openai_responses_parse_incomplete(...)`
    * `openai_responses_parse_usage(...)`

---

## Security notes

* Keep `OPENAI_API_KEY` out of source control.
* Consider `openai_v1_responses_set_store(req, false)` if you do **not** want server‑side storage of responses.
* Use `set_safety_identifier` and refusal includes/presets to inspect safety outcomes.

---

## License

Apache-2.0. See `LICENSE`.
Copyright © 2025 Andy Curtis.

> Non‑affiliation: This project is an independent library for interacting with the OpenAI API. It is not affiliated with, endorsed by, or sponsored by OpenAI. “OpenAI” and related marks are trademarks of OpenAI OpCo, LLC.
