# SPDX-FileCopyrightText: 2024–2026 Andy Curtis <contactandyc@gmail.com>
# SPDX-FileCopyrightText: 2024–2025 Knode.ai
# SPDX-License-Identifier: Apache-2.0
#
# Maintainer: Andy Curtis <contactandyc@gmail.com>

cmake_minimum_required(VERSION 3.20)

# A dynamically generated examples project.
project(a_curl_openai_plugin_embeddings LANGUAGES C)

find_library(M_LIB m)

find_package(a_curl_library CONFIG REQUIRED)
find_package(a_json_schema_builder_library CONFIG REQUIRED)

# ---- Targets ----
add_executable(embed_test
  src/embed_test.c
)

target_include_directories(embed_test PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

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

# Ensure examples running in library stacks link the main library!
if(NOT TARGET a_curl_openai_plugin::a_curl_openai_plugin)
  find_package(a_curl_openai_plugin CONFIG REQUIRED)
endif()
target_link_libraries(embed_test PRIVATE a_curl_openai_plugin::a_curl_openai_plugin)

target_link_libraries(embed_test PRIVATE
  a_curl_library::a_curl_library
  a_json_schema_builder_library::a_json_schema_builder_library
  a_curl_openai_plugin::a_curl_openai_plugin
)

if(M_LIB)
  target_link_libraries(embed_test PRIVATE ${M_LIB})
endif()

if(MSVC)
  target_compile_options(embed_test PRIVATE /W4)
else()
  target_compile_options(embed_test PRIVATE -Wall -Wextra -Wpedantic)
endif()

install(TARGETS embed_test RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
