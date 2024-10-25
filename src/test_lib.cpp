#include <cmake-cpp-template/test_lib.hpp>
#include <iostream>

namespace test_lib
{
  TESTCLASS::TESTCLASS()
  {
    std::cout << "TESTCLASS constructor called" << std::endl;
  }
  TESTCLASS ::~TESTCLASS() {}
} // namespace test_lib