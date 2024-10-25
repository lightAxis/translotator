#include <cmake-cpp-template/test_header_only_lib.hpp>
#include <cmake-cpp-template/test_lib.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test example", "[example]")
{
  test_lib::TESTCLASS test;

  int c = test_header_only_lib::add(1, 2);
  REQUIRE(c == 3);
}