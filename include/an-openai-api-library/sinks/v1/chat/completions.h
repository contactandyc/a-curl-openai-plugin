// SPDX-FileCopyrightText: 2025 Andy Curtis <contactandyc@gmail.com>
// SPDX-License-Identifier: Apache-2.0

#ifndef AN_OPENAI_API_SINK_V1_CHAT_COMPLETIONS_H
#define AN_OPENAI_API_SINK_V1_CHAT_COMPLETIONS_H

#include "a-curl-library/curl_event_loop.h"
#include "a-curl-library/curl_event_request.h"
#include <stdbool.h>

// Callback type for OpenAI Chat completion
typedef void (*openai_v1_chat_completions_complete_callback_t)(
    void *arg, curl_event_request_t *request,
    bool success,
    const char *assistant_response,
    int prompt_tokens,
    int completion_tokens,
    int total_tokens
);

curl_sink_interface_t *openai_v1_chat_completions_sink(
    curl_event_request_t *req,
    openai_v1_chat_completions_complete_callback_t complete_callback,
    void *complete_callback_arg);

#endif // AN_OPENAI_API_SINK_V1_CHAT_COMPLETIONS_H
