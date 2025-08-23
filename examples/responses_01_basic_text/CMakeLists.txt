# SPDX-FileCopyrightText: 2025 Andy Curtis <contactandyc@gmail.com>
# SPDX-License-Identifier: Apache-2.0
#
# SPDX-FileComment: This project is an independent library for interacting with the OpenAI API.
# It is not affiliated with, endorsed by, or sponsored by OpenAI.
# "OpenAI" and related marks are trademarks of OpenAI OpCo, LLC.

cmake_minimum_required(VERSION 3.20)

# A small "apps" project that builds example/demo binaries.
project(a-curl-openai-plugin_responses_01_basic_text LANGUAGES C)

# Optional math lib on POSIX
find_library(M_LIB m)

# Bring in suite-level dependencies derived by the renderer
find_package(a_curl_openai_plugin CONFIG REQUIRED)

# ---- Binaries ----
add_executable(basic_text  src/basic_text.c)

# Language standards
set_target_properties(basic_text PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(basic_text PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(basic_text PRIVATE  a_curl_openai_plugin::a_curl_openai_plugin)

# Optional libm
if(M_LIB)
  target_link_libraries(basic_text PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(basic_text PRIVATE /W4)
else()
  target_compile_options(basic_text PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS basic_text RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_cache_miss  src/basic_text_cache_miss.c)

# Language standards
set_target_properties(basic_text_cache_miss PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(basic_text_cache_miss PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(basic_text_cache_miss PRIVATE  a_curl_openai_plugin::a_curl_openai_plugin)

# Optional libm
if(M_LIB)
  target_link_libraries(basic_text_cache_miss PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(basic_text_cache_miss PRIVATE /W4)
else()
  target_compile_options(basic_text_cache_miss PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS basic_text_cache_miss RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_chain  src/basic_text_chain.c)

# Language standards
set_target_properties(basic_text_chain PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(basic_text_chain PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(basic_text_chain PRIVATE  a_curl_openai_plugin::a_curl_openai_plugin)

# Optional libm
if(M_LIB)
  target_link_libraries(basic_text_chain PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(basic_text_chain PRIVATE /W4)
else()
  target_compile_options(basic_text_chain PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS basic_text_chain RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_error  src/basic_text_error.c)

# Language standards
set_target_properties(basic_text_error PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(basic_text_error PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(basic_text_error PRIVATE  a_curl_openai_plugin::a_curl_openai_plugin)

# Optional libm
if(M_LIB)
  target_link_libraries(basic_text_error PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(basic_text_error PRIVATE /W4)
else()
  target_compile_options(basic_text_error PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS basic_text_error RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_instructions  src/basic_text_instructions.c)

# Language standards
set_target_properties(basic_text_instructions PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(basic_text_instructions PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(basic_text_instructions PRIVATE  a_curl_openai_plugin::a_curl_openai_plugin)

# Optional libm
if(M_LIB)
  target_link_libraries(basic_text_instructions PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(basic_text_instructions PRIVATE /W4)
else()
  target_compile_options(basic_text_instructions PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS basic_text_instructions RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_logprobs  src/basic_text_logprobs.c)

# Language standards
set_target_properties(basic_text_logprobs PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(basic_text_logprobs PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(basic_text_logprobs PRIVATE  a_curl_openai_plugin::a_curl_openai_plugin)

# Optional libm
if(M_LIB)
  target_link_libraries(basic_text_logprobs PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(basic_text_logprobs PRIVATE /W4)
else()
  target_compile_options(basic_text_logprobs PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS basic_text_logprobs RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_max_tokens  src/basic_text_max_tokens.c)

# Language standards
set_target_properties(basic_text_max_tokens PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(basic_text_max_tokens PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(basic_text_max_tokens PRIVATE  a_curl_openai_plugin::a_curl_openai_plugin)

# Optional libm
if(M_LIB)
  target_link_libraries(basic_text_max_tokens PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(basic_text_max_tokens PRIVATE /W4)
else()
  target_compile_options(basic_text_max_tokens PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS basic_text_max_tokens RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_parallel  src/basic_text_parallel.c)

# Language standards
set_target_properties(basic_text_parallel PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(basic_text_parallel PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(basic_text_parallel PRIVATE  a_curl_openai_plugin::a_curl_openai_plugin)

# Optional libm
if(M_LIB)
  target_link_libraries(basic_text_parallel PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(basic_text_parallel PRIVATE /W4)
else()
  target_compile_options(basic_text_parallel PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS basic_text_parallel RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(basic_text_temperature_sweep  src/basic_text_temperature_sweep.c)

# Language standards
set_target_properties(basic_text_temperature_sweep PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(basic_text_temperature_sweep PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(basic_text_temperature_sweep PRIVATE  a_curl_openai_plugin::a_curl_openai_plugin)

# Optional libm
if(M_LIB)
  target_link_libraries(basic_text_temperature_sweep PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(basic_text_temperature_sweep PRIVATE /W4)
else()
  target_compile_options(basic_text_temperature_sweep PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS basic_text_temperature_sweep RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
