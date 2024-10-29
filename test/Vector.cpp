
#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

TEST_CASE("Vector", "[objects]")
{
    float data[3] = {1, 2, 3};
    Vector<3, float> v{data};

    SECTION("constructors")
    {
        float data2[3] = {1, 2, 3};
        Vector<3, float> v2{data2};
        REQUIRE_THAT(v, EqualsMatrix(v2));

        float data3[3][1] = {{1}, {2}, {3}};
        Vector<3, float> v3{data3};
        REQUIRE_THAT(v, EqualsMatrix(v3));

        auto m3 = v3.castContainer<Matrix<3, 1, float>>();
        Matrixf<3, 1> m3_(data3);
        REQUIRE_THAT(m3, EqualsMatrix(m3_));
    }

    SECTION("Casting")
    {
        auto vd = v.cast<double>();
        REQUIRE(is_same_v<decltype(vd)::DATATYPE, double>);

        auto vld = v.cast<long double>();
        REQUIRE(is_same_v<decltype(vld)::DATATYPE, long double>);

        auto m2 = v.castContainer<Matrix<3, 1, float>>();
        float data2[3][1] = {{1}, {2}, {3}};
        Matrixf<3, 1> m2_(data2);
        REQUIRE_THAT(m2, EqualsMatrix(m2_));
    }
}