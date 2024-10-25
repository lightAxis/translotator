#include <cmake-cpp-template/test_header_only_lib.hpp>
#include <cmake-cpp-template/test_lib.hpp>
#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  test_lib::TESTCLASS test;
  std::cout << "Hello, World!" << std::endl;
  return 0;
}