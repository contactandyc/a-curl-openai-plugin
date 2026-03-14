// SPDX-FileCopyrightText: 2025-2026 Andy Curtis <contactandyc@gmail.com>
// SPDX-License-Identifier: Apache-2.0
//
// SPDX-FileComment: This project is an independent library for interacting with the OpenAI API.
// It is not affiliated with, endorsed by, or sponsored by OpenAI.
// "OpenAI" and related marks are trademarks of OpenAI OpCo, LLC.

#include "a-curl-library/curl_event_loop.h"
#include "a-curl-library/curl_event_request.h"
#include "a-curl-library/curl_resource.h"
#include "a-curl-openai-plugin/plugins/v1/responses.h"
#include "a-curl-openai-plugin/sinks/v1/responses.h"
#include <stdio.h>
#include <stdlib.h>

static const char *MODEL_ID = "gpt-4o-mini";
static const char *PROMPT   = "Explain quantum tunnelling in one paragraph";

static void on_done(void*, curl_event_request_t*, bool success,
                    const char *out, int p_tok,int c_tok,int t_tok)
{
    if (!success) { fprintf(stderr,"❌ request failed\n"); return; }
    puts("\n──────────────────────────────────────────────"); puts(out);
    printf("\n(prompt=%d  completion=%d  total=%d tokens)\n",
           p_tok,c_tok,t_tok);
}
int main(void)
{
    const char *key = getenv("OPENAI_API_KEY");
    if(!key||!*key){ fprintf(stderr,"OPENAI_API_KEY not set\n"); return 1;}

    curl_event_loop_t *loop = curl_event_loop_init(NULL,NULL);
    curl_event_res_id key_res = curl_event_res_register(loop,strdup(key),free);

    curl_event_request_t *req =
        openai_v1_responses_init(loop,key_res,MODEL_ID);

    openai_v1_responses_sink(req, on_done,NULL);
    openai_v1_responses_input_text(req,PROMPT);
    openai_v1_responses_submit(loop,req,0);

    curl_event_loop_run(loop);
    curl_event_loop_destroy(loop);
    return 0;
}
