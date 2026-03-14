// SPDX-FileCopyrightText: 2025-2026 Andy Curtis <contactandyc@gmail.com>
// SPDX-License-Identifier: Apache-2.0
//
// SPDX-FileComment: This project is an independent library for interacting with the OpenAI API.
// It is not affiliated with, endorsed by, or sponsored by OpenAI.
// "OpenAI" and related marks are trademarks of OpenAI OpCo, LLC.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "a-curl-library/curl_event_loop.h"
#include "a-curl-library/curl_resource.h"
#include "a-curl-openai-plugin/plugins/v1/embeddings.h"
#include "a-curl-openai-plugin/sinks/v1/embeddings.h"

/* --------------------------------------------------------------------- */
/* Completion callback                                                   */
static void on_embeddings_done(void *arg,
                               curl_event_request_t *req,
                               bool   success,
                               float **embeddings,
                               size_t  n_vec,
                               size_t  dim)
{
    (void)arg; (void)req;

    if (!success) {
        fprintf(stderr, "[test] embeddings request FAILED\n");
        return;
    }

    printf("[test] received %zu embeddings (dim = %zu)\n", n_vec, dim);
    for (size_t i = 0; i < n_vec; ++i) {
        printf("  vec[%zu]:", i);
        size_t preview = dim < 5 ? dim : 5;
        for (size_t j = 0; j < preview; ++j)
            printf(" %.4f", embeddings[i][j]);
        if (dim > preview) printf(" …");
        putchar('\n');
    }
}

/* --------------------------------------------------------------------- */
int main(void)
{
    /* 1. API key from env */
    const char *api_key = getenv("OPENAI_API_KEY");
    if (!api_key || !*api_key) {
        fprintf(stderr, "Set OPENAI_API_KEY in your environment first.\n");
        return EXIT_FAILURE;
    }

    /* 2. Create event-loop: no tick, no user data */
    curl_event_loop_t *loop = curl_event_loop_init(/*tick=*/NULL, /*userdata=*/NULL);
    if (!loop) {
        fprintf(stderr, "Failed to create curl_event_loop\n");
        return EXIT_FAILURE;
    }

    /* 3. Register key resource */
    curl_event_res_id api_key_res =
        curl_event_res_register(loop, strdup(api_key), free);

    /* 4. Build sink */
    curl_sink_interface_t *sink =
        openai_v1_embeddings_sink(/*expected_dim=*/512,
                            on_embeddings_done,
                            /*cb_arg=*/NULL);

    /* 5. Build request */
    curl_event_request_t *req =
        openai_v1_embeddings_init(loop, api_key_res,
                         /*model*/ "text-embedding-3-small",
                         sink);
    if (!req) {
        fprintf(stderr, "Failed to create embeddings request\n");
        return EXIT_FAILURE;
    }

    openai_v1_embeddings_set_dimensions(req, 512);
    openai_v1_embeddings_add_text(req, "Hello world!");
    openai_v1_embeddings_add_text(req,
        "Embeddings are dense vectors that capture semantic meaning.");

    /* 6. Submit and run */
    openai_v1_embeddings_submit(loop, req, /*priority=*/0);
    curl_event_loop_run(loop);      /* loop exits once all requests finish */

    /* 7. Cleanup */
    curl_event_loop_destroy(loop);
    return EXIT_SUCCESS;
}
