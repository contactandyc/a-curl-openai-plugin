// SPDX-FileCopyrightText: 2025-2026 Andy Curtis <contactandyc@gmail.com>
// SPDX-License-Identifier: Apache-2.0
//
// SPDX-FileComment: This project is an independent library for interacting with the OpenAI API.
// It is not affiliated with, endorsed by, or sponsored by OpenAI.
// "OpenAI" and related marks are trademarks of OpenAI OpCo, LLC.

#ifndef A_CURL_OPENAI_PLUGIN_SINK_V1_RESPONSES_H
#define A_CURL_OPENAI_PLUGIN_SINK_V1_RESPONSES_H

#include "a-curl-library/curl_event_loop.h"
#include "a-curl-library/curl_event_request.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Completion callback for /v1/responses */
typedef void (*openai_v1_responses_complete_callback_t)(
    void                 *arg,
    curl_event_request_t *request,
    bool                  success,
    const char           *sink_text,
    int                   prompt_tokens,
    int                   completion_tokens,
    int                   total_tokens);

/* Factory: returns a sink wired for curl_sink_defaults() */
curl_sink_interface_t *
openai_v1_responses_sink(
    curl_event_request_t *req,
    openai_v1_responses_complete_callback_t complete_cb,
    void *complete_arg);

#ifdef __cplusplus
}
#endif
#endif /* A_CURL_OPENAI_PLUGIN_SINK_V1_RESPONSES_H */
