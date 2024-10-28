
#include "custom_tester.hpp"

#include <translotator/objects/testBase.hpp>

using namespace test;

TEST_CASE("Matrix", "[objects]")
{
    Matrix<3, 3, float> m1;
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    m1(2, 0) = 7;
    m1(2, 1) = 8;
    m1(2, 2) = 9;

    Vector<3, float> v1;
    v1(0, 0) = 11;
    v1(1, 0) = 12;
    v1(2, 0) = 13;

    auto v2 = v1 + v1;
}