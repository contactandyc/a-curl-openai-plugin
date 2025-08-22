# SPDX-FileCopyrightText: 2025 Andy Curtis <contactandyc@gmail.com>
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20)

# A small "apps" project that builds example/demo binaries.
project(an-openai-api-library_responses_02_structured_output LANGUAGES C)

# Optional math lib on POSIX
find_library(M_LIB m)

# Bring in suite-level dependencies derived by the renderer
find_package(an_openai_api_library CONFIG REQUIRED)

# ---- Binaries ----
add_executable(structured_single_object  src/structured_single_object.c)

# Language standards
set_target_properties(structured_single_object PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_single_object PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_single_object PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_single_object PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_single_object PRIVATE /W4)
else()
  target_compile_options(structured_single_object PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_single_object RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(structured_array  src/structured_array.c)

# Language standards
set_target_properties(structured_array PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_array PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_array PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_array PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_array PRIVATE /W4)
else()
  target_compile_options(structured_array PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_array RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(structured_nested  src/structured_nested.c)

# Language standards
set_target_properties(structured_nested PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_nested PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_nested PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_nested PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_nested PRIVATE /W4)
else()
  target_compile_options(structured_nested PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_nested RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(structured_chain_single_followup  src/structured_chain_single_followup.c)

# Language standards
set_target_properties(structured_chain_single_followup PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_chain_single_followup PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_chain_single_followup PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_chain_single_followup PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_chain_single_followup PRIVATE /W4)
else()
  target_compile_options(structured_chain_single_followup PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_chain_single_followup RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(structured_chain_parallel_followup  src/structured_chain_parallel_followup.c)

# Language standards
set_target_properties(structured_chain_parallel_followup PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_chain_parallel_followup PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_chain_parallel_followup PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_chain_parallel_followup PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_chain_parallel_followup PRIVATE /W4)
else()
  target_compile_options(structured_chain_parallel_followup PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_chain_parallel_followup RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(structured_validation_error  src/structured_validation_error.c)

# Language standards
set_target_properties(structured_validation_error PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_validation_error PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_validation_error PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_validation_error PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_validation_error PRIVATE /W4)
else()
  target_compile_options(structured_validation_error PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_validation_error RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(structured_contact_form  src/structured_contact_form.c)

# Language standards
set_target_properties(structured_contact_form PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_contact_form PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_contact_form PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_contact_form PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_contact_form PRIVATE /W4)
else()
  target_compile_options(structured_contact_form PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_contact_form RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(structured_calendar_event  src/structured_calendar_event.c)

# Language standards
set_target_properties(structured_calendar_event PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_calendar_event PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_calendar_event PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_calendar_event PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_calendar_event PRIVATE /W4)
else()
  target_compile_options(structured_calendar_event PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_calendar_event RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(structured_invoice_line_items  src/structured_invoice_line_items.c)

# Language standards
set_target_properties(structured_invoice_line_items PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_invoice_line_items PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_invoice_line_items PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_invoice_line_items PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_invoice_line_items PRIVATE /W4)
else()
  target_compile_options(structured_invoice_line_items PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_invoice_line_items RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(structured_moderation_report  src/structured_moderation_report.c)

# Language standards
set_target_properties(structured_moderation_report PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_moderation_report PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_moderation_report PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_moderation_report PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_moderation_report PRIVATE /W4)
else()
  target_compile_options(structured_moderation_report PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_moderation_report RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(structured_ui_tree  src/structured_ui_tree.c)

# Language standards
set_target_properties(structured_ui_tree PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_ui_tree PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_ui_tree PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_ui_tree PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_ui_tree PRIVATE /W4)
else()
  target_compile_options(structured_ui_tree PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_ui_tree RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(structured_search_query  src/structured_search_query.c)

# Language standards
set_target_properties(structured_search_query PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_search_query PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_search_query PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_search_query PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_search_query PRIVATE /W4)
else()
  target_compile_options(structured_search_query PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_search_query RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(structured_options_with_null  src/structured_options_with_null.c)

# Language standards
set_target_properties(structured_options_with_null PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_options_with_null PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_options_with_null PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_options_with_null PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_options_with_null PRIVATE /W4)
else()
  target_compile_options(structured_options_with_null PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_options_with_null RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(structured_streaming_entities  src/structured_streaming_entities.c)

# Language standards
set_target_properties(structured_streaming_entities PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_streaming_entities PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_streaming_entities PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_streaming_entities PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_streaming_entities PRIVATE /W4)
else()
  target_compile_options(structured_streaming_entities PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_streaming_entities RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(structured_chain_generate_then_expand  src/structured_chain_generate_then_expand.c)

# Language standards
set_target_properties(structured_chain_generate_then_expand PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_chain_generate_then_expand PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_chain_generate_then_expand PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_chain_generate_then_expand PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_chain_generate_then_expand PRIVATE /W4)
else()
  target_compile_options(structured_chain_generate_then_expand PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_chain_generate_then_expand RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
add_executable(structured_validation_showcase  src/structured_validation_showcase.c)

# Language standards
set_target_properties(structured_validation_showcase PROPERTIES
  C_STANDARD 23
  C_STANDARD_REQUIRED YES
)
if("CXX" IN_LIST CMAKE_PROJECT_LANGUAGES)
  set_target_properties(structured_validation_showcase PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endif()

# Link the union of deps computed for this app context
target_link_libraries(structured_validation_showcase PRIVATE  an_openai_api_library::an_openai_api_library)

# Optional libm
if(M_LIB)
  target_link_libraries(structured_validation_showcase PRIVATE ${M_LIB})
endif()

# Warnings
if(MSVC)
  target_compile_options(structured_validation_showcase PRIVATE /W4)
else()
  target_compile_options(structured_validation_showcase PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install each app binary (handy for packaging examples)
install(TARGETS structured_validation_showcase RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
