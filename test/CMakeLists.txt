message(STATUS "Configuring tests..")

find_package(Catch2 3 REQUIRED)
include(Catch)

# =============================================================================
#
# add_test
#
# This function add test executable with Catch2 and link with DEPS
#
# Usage: add_test(TARGET_SRC [DEPS dep1 dep2 ...])
#
function(add_test TARGET_SRC)
  cmake_parse_arguments("ARG" "" "" "DEPS" ${ARGN})

  get_filename_component(TARGET_NAME ${TARGET_SRC} NAME_WE)
  set(TARGET_NAME "test_${TARGET_NAME}")
  message(STATUS "Adding test: ${TARGET_NAME} /DEPS: ${ARG_DEPS}")

  add_executable(${TARGET_NAME} ${TARGET_SRC})
  target_compile_options(
    ${TARGET_NAME} PRIVATE -Wno-double-promotion -Wno-unused-variable
    -Wno-unused-but-set-variable)
  target_link_libraries(${TARGET_NAME} PRIVATE Catch2::Catch2WithMain)
  target_link_libraries(${TARGET_NAME} PRIVATE ${ARG_DEPS})

  catch_discover_tests(${TARGET_NAME})
endfunction()

# add test sources here
add_test(epsilon.cpp DEPS translotator)
add_test(Matrix.cpp DEPS translotator)
