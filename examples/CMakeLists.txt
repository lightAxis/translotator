message(STATUS "Configuring examples..")

# =============================================================================
#
# add_example
#
# This function add test executable and link it with the given dependencies.
#
# Usage: add_example(TARGET_SRC [DEPS dep1 dep2 ...])
#
function(add_test TARGET_SRC)
  cmake_parse_arguments("ARG" "" "" "DEPS" ${ARGN})

  get_filename_component(TARGET_NAME ${TARGET_SRC} NAME_WE)
  message(STATUS "Adding example: ${TARGET_NAME} /DEPS: ${ARG_DEPS}")
  set(TARGET_NAME "example_${TARGET_NAME}")
  add_executable(${TARGET_NAME} ${TARGET_SRC})
  target_compile_options(
    ${TARGET_NAME} PRIVATE -Wno-double-promotion -Wno-unused-variable
    -Wno-unused-but-set-variable)
  target_link_libraries(${TARGET_NAME} PRIVATE ${ARG_DEPS})
endfunction()

# add test sources here
add_test(test_example.cpp DEPS TEST_LIB TEST_HEADER_LIB)
