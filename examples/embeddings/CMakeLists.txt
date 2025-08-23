# SPDX-FileCopyrightText: 2025 Andy Curtis <contactandyc@gmail.com>
# SPDX-License-Identifier: Apache-2.0
#
# SPDX-FileComment: This project is an independent library for interacting with the OpenAI API.
# It is not affiliated with, endorsed by, or sponsored by OpenAI.
# "OpenAI" and related marks are trademarks of OpenAI OpCo, LLC.

cmake_minimum_required(VERSION 3.20)

# A small "apps" project that builds example/demo binaries.
project(a-curl-openai-plugin_embeddings LANGUAGES C)

# Optional math lib on POSIX
find_library(M_LIB m)

# Bring in suite-level dependencies derived by the renderer
find_package(a_curl_openai_plugin CONFIG REQUIRED)

# ---- Binaries ----
add_executable(embed_test  src/embed_test.c)

# Language standards
set_target_properties(embed_test PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(embed_test PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(embed_test PRIVATE  a_curl_openai_plugin::a_curl_openai_plugin)

# Optional libm
if(M_LIB)
  target_link_libraries(embed_test PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(embed_test PRIVATE /W4)
else()
  target_compile_options(embed_test PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS embed_test RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
