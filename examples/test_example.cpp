#include <cmake-cpp-template/test_header_only_lib.hpp>
#include <cmake-cpp-template/test_lib.hpp>
#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    test_lib::TESTCLASS test;

    int c = test_header_only_lib::add(1, 2);
    std::cout << "Result: " << c << std::endl;
    return 0;
}