// SPDX-FileCopyrightText: 2025 Andy Curtis <contactandyc@gmail.com>
// SPDX-License-Identifier: Apache-2.0
#ifndef AN_OPENAI_API_SINK_V1_RESPONSES_H
#define AN_OPENAI_API_SINK_V1_RESPONSES_H

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
#endif /* AN_OPENAI_API_SINK_V1_RESPONSES_H */
