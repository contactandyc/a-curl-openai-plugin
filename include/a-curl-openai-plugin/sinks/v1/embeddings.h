// SPDX-FileCopyrightText: 2025-2026 Andy Curtis <contactandyc@gmail.com>
// SPDX-License-Identifier: Apache-2.0
//
// SPDX-FileComment: This project is an independent library for interacting with the OpenAI API.
// It is not affiliated with, endorsed by, or sponsored by OpenAI.
// "OpenAI" and related marks are trademarks of OpenAI OpCo, LLC.

#ifndef A_CURL_OPENAI_PLUGIN_SINK_V1_EMBEDDINGS_H
#define A_CURL_OPENAI_PLUGIN_SINK_V1_EMBEDDINGS_H

#include "a-curl-library/curl_event_loop.h"
#include "a-curl-library/curl_event_request.h"
#include <stdbool.h>
#include <stddef.h>

/* Callback signature ------------------------------------------------------ */
typedef void (*openai_v1_embeddings_complete_callback_t)(
    void *arg,
    curl_event_request_t *request,
    bool   success,
    float **embeddings,           /* NULL on failure */
    size_t  num_embeddings,
    size_t  embedding_size        /* 0 if unknown or failure */
);

/* Factory ----------------------------------------------------------------- */
curl_sink_interface_t *openai_v1_embeddings_sink(
    curl_event_request_t *req,
    size_t expected_embedding_size,                  /* 0 = accept any */
    openai_v1_embeddings_complete_callback_t complete_cb,
    void *complete_cb_arg);

#endif /* A_CURL_OPENAI_PLUGIN_SINK_V1_EMBEDDINGS_H */
