// SPDX-FileCopyrightText: 2025 Andy Curtis <contactandyc@gmail.com>
// SPDX-License-Identifier: Apache-2.0
//
// SPDX-FileComment: This project is an independent library for interacting with the OpenAI API.
// It is not affiliated with, endorsed by, or sponsored by OpenAI.
// "OpenAI" and related marks are trademarks of OpenAI OpCo, LLC.

// SPDX: Apache-2.0
#ifndef A_CURL_OPENAI_PLUGIN_V1_RESPONSES_GET_H
#define A_CURL_OPENAI_PLUGIN_V1_RESPONSES_GET_H
#include "a-curl-library/curl_event_loop.h"
#include "a-curl-library/curl_event_request.h"
#ifdef __cplusplus
extern "C" {
#endif
curl_event_request_t *openai_v1_responses_get(curl_event_loop_t *loop,
    curl_event_res_id api_key_id, const char *response_id,
    curl_sink_interface_t *sink /* JSON sink or SSE sink if stream=true */);
#ifdef __cplusplus
}
#endif
#endif
