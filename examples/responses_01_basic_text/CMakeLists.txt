# SPDX-FileCopyrightText: 2024–2026 Andy Curtis <contactandyc@gmail.com>
# SPDX-FileCopyrightText: 2024–2025 Knode.ai
# SPDX-License-Identifier: Apache-2.0
#
# Maintainer: Andy Curtis <contactandyc@gmail.com>

cmake_minimum_required(VERSION 3.20)

# A dynamically generated examples project.
project(a_curl_openai_plugin_responses_01_basic_text LANGUAGES C)

if(CMAKE_PREFIX_PATH)
  include_directories("${CMAKE_PREFIX_PATH}/include")
  link_directories("${CMAKE_PREFIX_PATH}/lib")
endif()

find_library(M_LIB m)

find_package(a_curl_library CONFIG REQUIRED)
find_package(a_json_schema_builder_library CONFIG REQUIRED)

# ---- Targets ----
add_executable(basic_text
  src/basic_text.c
)

target_include_directories(basic_text PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(basic_text PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
)

# Ensure examples running in library stacks link the main library!
if(NOT TARGET a_curl_openai_plugin::a_curl_openai_plugin)
  find_package(a_curl_openai_plugin CONFIG REQUIRED)
endif()
# target_link_libraries(basic_text PRIVATE a_curl_openai_plugin::a_curl_openai_plugin)

target_link_libraries(basic_text PRIVATE
  a_curl_library::a_curl_library
  a_json_schema_builder_library::a_json_schema_builder_library
  a_curl_openai_plugin::a_curl_openai_plugin
)

if(M_LIB)
  target_link_libraries(basic_text PRIVATE ${M_LIB})
endif()

if(MSVC)
  target_compile_options(basic_text PRIVATE /W4)
else()
  target_compile_options(basic_text PRIVATE -Wall -Wextra -Wpedantic)
endif()

install(TARGETS basic_text RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_cache_miss
  src/basic_text_cache_miss.c
)

target_include_directories(basic_text_cache_miss PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(basic_text_cache_miss PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
)

# Ensure examples running in library stacks link the main library!
if(NOT TARGET a_curl_openai_plugin::a_curl_openai_plugin)
  find_package(a_curl_openai_plugin CONFIG REQUIRED)
endif()
# target_link_libraries(basic_text_cache_miss PRIVATE a_curl_openai_plugin::a_curl_openai_plugin)

target_link_libraries(basic_text_cache_miss PRIVATE
  a_curl_library::a_curl_library
  a_json_schema_builder_library::a_json_schema_builder_library
  a_curl_openai_plugin::a_curl_openai_plugin
)

if(M_LIB)
  target_link_libraries(basic_text_cache_miss PRIVATE ${M_LIB})
endif()

if(MSVC)
  target_compile_options(basic_text_cache_miss PRIVATE /W4)
else()
  target_compile_options(basic_text_cache_miss PRIVATE -Wall -Wextra -Wpedantic)
endif()

install(TARGETS basic_text_cache_miss RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_chain
  src/basic_text_chain.c
)

target_include_directories(basic_text_chain PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(basic_text_chain PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
)

# Ensure examples running in library stacks link the main library!
if(NOT TARGET a_curl_openai_plugin::a_curl_openai_plugin)
  find_package(a_curl_openai_plugin CONFIG REQUIRED)
endif()
# target_link_libraries(basic_text_chain PRIVATE a_curl_openai_plugin::a_curl_openai_plugin)

target_link_libraries(basic_text_chain PRIVATE
  a_curl_library::a_curl_library
  a_json_schema_builder_library::a_json_schema_builder_library
  a_curl_openai_plugin::a_curl_openai_plugin
)

if(M_LIB)
  target_link_libraries(basic_text_chain PRIVATE ${M_LIB})
endif()

if(MSVC)
  target_compile_options(basic_text_chain PRIVATE /W4)
else()
  target_compile_options(basic_text_chain PRIVATE -Wall -Wextra -Wpedantic)
endif()

install(TARGETS basic_text_chain RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_error
  src/basic_text_error.c
)

target_include_directories(basic_text_error PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(basic_text_error PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
)

# Ensure examples running in library stacks link the main library!
if(NOT TARGET a_curl_openai_plugin::a_curl_openai_plugin)
  find_package(a_curl_openai_plugin CONFIG REQUIRED)
endif()
# target_link_libraries(basic_text_error PRIVATE a_curl_openai_plugin::a_curl_openai_plugin)

target_link_libraries(basic_text_error PRIVATE
  a_curl_library::a_curl_library
  a_json_schema_builder_library::a_json_schema_builder_library
  a_curl_openai_plugin::a_curl_openai_plugin
)

if(M_LIB)
  target_link_libraries(basic_text_error PRIVATE ${M_LIB})
endif()

if(MSVC)
  target_compile_options(basic_text_error PRIVATE /W4)
else()
  target_compile_options(basic_text_error PRIVATE -Wall -Wextra -Wpedantic)
endif()

install(TARGETS basic_text_error RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_instructions
  src/basic_text_instructions.c
)

target_include_directories(basic_text_instructions PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(basic_text_instructions PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
)

# Ensure examples running in library stacks link the main library!
if(NOT TARGET a_curl_openai_plugin::a_curl_openai_plugin)
  find_package(a_curl_openai_plugin CONFIG REQUIRED)
endif()
# target_link_libraries(basic_text_instructions PRIVATE a_curl_openai_plugin::a_curl_openai_plugin)

target_link_libraries(basic_text_instructions PRIVATE
  a_curl_library::a_curl_library
  a_json_schema_builder_library::a_json_schema_builder_library
  a_curl_openai_plugin::a_curl_openai_plugin
)

if(M_LIB)
  target_link_libraries(basic_text_instructions PRIVATE ${M_LIB})
endif()

if(MSVC)
  target_compile_options(basic_text_instructions PRIVATE /W4)
else()
  target_compile_options(basic_text_instructions PRIVATE -Wall -Wextra -Wpedantic)
endif()

install(TARGETS basic_text_instructions RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_logprobs
  src/basic_text_logprobs.c
)

target_include_directories(basic_text_logprobs PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(basic_text_logprobs PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
)

# Ensure examples running in library stacks link the main library!
if(NOT TARGET a_curl_openai_plugin::a_curl_openai_plugin)
  find_package(a_curl_openai_plugin CONFIG REQUIRED)
endif()
# target_link_libraries(basic_text_logprobs PRIVATE a_curl_openai_plugin::a_curl_openai_plugin)

target_link_libraries(basic_text_logprobs PRIVATE
  a_curl_library::a_curl_library
  a_json_schema_builder_library::a_json_schema_builder_library
  a_curl_openai_plugin::a_curl_openai_plugin
)

if(M_LIB)
  target_link_libraries(basic_text_logprobs PRIVATE ${M_LIB})
endif()

if(MSVC)
  target_compile_options(basic_text_logprobs PRIVATE /W4)
else()
  target_compile_options(basic_text_logprobs PRIVATE -Wall -Wextra -Wpedantic)
endif()

install(TARGETS basic_text_logprobs RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_max_tokens
  src/basic_text_max_tokens.c
)

target_include_directories(basic_text_max_tokens PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(basic_text_max_tokens PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
)

# Ensure examples running in library stacks link the main library!
if(NOT TARGET a_curl_openai_plugin::a_curl_openai_plugin)
  find_package(a_curl_openai_plugin CONFIG REQUIRED)
endif()
# target_link_libraries(basic_text_max_tokens PRIVATE a_curl_openai_plugin::a_curl_openai_plugin)

target_link_libraries(basic_text_max_tokens PRIVATE
  a_curl_library::a_curl_library
  a_json_schema_builder_library::a_json_schema_builder_library
  a_curl_openai_plugin::a_curl_openai_plugin
)

if(M_LIB)
  target_link_libraries(basic_text_max_tokens PRIVATE ${M_LIB})
endif()

if(MSVC)
  target_compile_options(basic_text_max_tokens PRIVATE /W4)
else()
  target_compile_options(basic_text_max_tokens PRIVATE -Wall -Wextra -Wpedantic)
endif()

install(TARGETS basic_text_max_tokens RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_parallel
  src/basic_text_parallel.c
)

target_include_directories(basic_text_parallel PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(basic_text_parallel PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
)

# Ensure examples running in library stacks link the main library!
if(NOT TARGET a_curl_openai_plugin::a_curl_openai_plugin)
  find_package(a_curl_openai_plugin CONFIG REQUIRED)
endif()
# target_link_libraries(basic_text_parallel PRIVATE a_curl_openai_plugin::a_curl_openai_plugin)

target_link_libraries(basic_text_parallel PRIVATE
  a_curl_library::a_curl_library
  a_json_schema_builder_library::a_json_schema_builder_library
  a_curl_openai_plugin::a_curl_openai_plugin
)

if(M_LIB)
  target_link_libraries(basic_text_parallel PRIVATE ${M_LIB})
endif()

if(MSVC)
  target_compile_options(basic_text_parallel PRIVATE /W4)
else()
  target_compile_options(basic_text_parallel PRIVATE -Wall -Wextra -Wpedantic)
endif()

install(TARGETS basic_text_parallel RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_temperature_sweep
  src/basic_text_temperature_sweep.c
)

target_include_directories(basic_text_temperature_sweep PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(basic_text_temperature_sweep PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
)

# Ensure examples running in library stacks link the main library!
if(NOT TARGET a_curl_openai_plugin::a_curl_openai_plugin)
  find_package(a_curl_openai_plugin CONFIG REQUIRED)
endif()
# target_link_libraries(basic_text_temperature_sweep PRIVATE a_curl_openai_plugin::a_curl_openai_plugin)

target_link_libraries(basic_text_temperature_sweep PRIVATE
  a_curl_library::a_curl_library
  a_json_schema_builder_library::a_json_schema_builder_library
  a_curl_openai_plugin::a_curl_openai_plugin
)

if(M_LIB)
  target_link_libraries(basic_text_temperature_sweep PRIVATE ${M_LIB})
endif()

if(MSVC)
  target_compile_options(basic_text_temperature_sweep PRIVATE /W4)
else()
  target_compile_options(basic_text_temperature_sweep PRIVATE -Wall -Wextra -Wpedantic)
endif()

install(TARGETS basic_text_temperature_sweep RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
