// SPDX-FileCopyrightText: 2025 Andy Curtis <contactandyc@gmail.com>
// SPDX-License-Identifier: Apache-2.0
//
// SPDX-FileComment: This project is an independent library for interacting with the OpenAI API.
// It is not affiliated with, endorsed by, or sponsored by OpenAI.
// "OpenAI" and related marks are trademarks of OpenAI OpCo, LLC.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#include "a-curl-library/curl_event_loop.h"
#include "a-curl-openai-plugin/plugins/v1/embeddings.h"
#include "a-curl-openai-plugin/sinks/v1/embeddings.h"

/* Callback when embeddings are complete */
static void on_embeddings_complete(
    void *arg,
    curl_event_request_t *req,
    bool success,
    float **embeddings,
    size_t num_embeddings,
    size_t embedding_size)
{
    (void)req; (void)arg;
    if (!success) {
        fprintf(stderr, "Embedding request failed!\n");
        return;
    }

    printf("Got %zu embeddings, each of size %zu\n", num_embeddings, embedding_size);
    for (size_t i = 0; i < num_embeddings; i++) {
        printf("Embedding %zu first 5 dims:", i);
        for (size_t j = 0; j < (embedding_size < 5 ? embedding_size : 5); j++) {
            printf(" %.6f", embeddings[i][j]);
        }
        printf("\n");
    }
}

/* Main program */
int main(void)
{
    const char *api_key = getenv("OPENAI_API_KEY");
    if (!api_key) {
        fprintf(stderr, "Please set OPENAI_API_KEY in your environment.\n");
        return 1;
    }

    /* Initialize libcurl globally */
    curl_global_init(CURL_GLOBAL_DEFAULT);

    /* Create the event loop */
    curl_event_loop_t *loop = curl_event_loop_init(NULL, NULL);


    curl_event_res_id api_key_id =
        curl_event_res_register(loop,
                                api_key,   /* payload (dup so it survives) */
                                NULL);             /* cleanup function */

    /* Create embeddings request for "text-embedding-3-small" */
    curl_event_request_t *req = openai_v1_embeddings_init(
        loop,
        api_key_id,
        "text-embedding-3-small"
    );
    if (!req) {
        fprintf(stderr, "Failed to init embeddings request\n");
        return 1;
    }

    /* Add input text */
    openai_v1_embeddings_add_text(req, "Hello world");

    /* Attach sink to parse embeddings */
    openai_v1_embeddings_sink(req,
                              1536, /* expected embedding size (0 = accept any) */
                              on_embeddings_complete,
                              NULL);

    /* Enqueue and run loop */
    openai_v1_embeddings_submit(loop, req, 0);
    curl_event_loop_run(loop);

    curl_event_loop_destroy(loop);
    curl_global_cleanup();
    return 0;
}
