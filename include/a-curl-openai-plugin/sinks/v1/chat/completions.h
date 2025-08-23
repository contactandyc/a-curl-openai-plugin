// SPDX-FileCopyrightText: 2025 Andy Curtis <contactandyc@gmail.com>
// SPDX-License-Identifier: Apache-2.0
//
// SPDX-FileComment: This project is an independent library for interacting with the OpenAI API.
// It is not affiliated with, endorsed by, or sponsored by OpenAI.
// "OpenAI" and related marks are trademarks of OpenAI OpCo, LLC.

#ifndef A_CURL_OPENAI_PLUGIN_SINK_V1_CHAT_COMPLETIONS_H
#define A_CURL_OPENAI_PLUGIN_SINK_V1_CHAT_COMPLETIONS_H

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

#endif // A_CURL_OPENAI_PLUGIN_SINK_V1_CHAT_COMPLETIONS_H
