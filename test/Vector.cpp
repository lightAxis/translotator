
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

        Vector<3, float> v4{{1.f, 2.f, 3.f}};
        REQUIRE_THAT(v, EqualsMatrix(v4));
    }

    SECTION("Base Operations-Constants")
    {
        Vectorf<3> v1 = Vectorf<3>::zeros();
        Vectorf<3> v1_{{0.f, 0.f, 0.f}};
        REQUIRE_THAT(v1, EqualsMatrix(v1_));

        Vectorf<3> v2 = Vectorf<3>::ones();
        Vectorf<3> v2_{{1.f, 1.f, 1.f}};
        REQUIRE_THAT(v2, EqualsMatrix(v2_));

        Vectorf<3> v4 = Vectorf<3>::eye();
        Vectorf<3> v4_{{1.f, 0.f, 0.f}};
        REQUIRE_THAT(v4, EqualsMatrix(v4_));
    }

    SECTION("Base operations-Assignments")
    {
        Vectorf<3> v1{{0.f, 0.f, 0.f}};
        v1.setRow(0, Matrixf<1, 1>{{1.f}});
        Vectorf<3> v1_{{1.f, 0.f, 0.f}};
        REQUIRE_THAT(v1, EqualsMatrix(v1_));

        v1.setRow(1, Matrixf<1, 1>{{3.f}});
        Vectorf<3> v1_2{{1.f, 3.f, 0.f}};
        REQUIRE_THAT(v1, EqualsMatrix(v1_2));

        v1.setCol(0, Matrixf<3, 1>{{1.f, 2.f, 3.f}});
        Vectorf<3> v1_3{{1.f, 2.f, 3.f}};
        REQUIRE_THAT(v1, EqualsMatrix(v1_3));

        v1.setBlock(1, 0, Matrixf<2, 1>{{4.f, 5.f}});
        Vectorf<3> v1_4{{1.f, 4.f, 5.f}};
        REQUIRE_THAT(v1, EqualsMatrix(v1_4));

        v1.setBlock(0, 0, Vectorf<2>{{6.f, 7.f}});
        Vectorf<3> v1_5{{6.f, 7.f, 5.f}};
        REQUIRE_THAT(v1, EqualsMatrix(v1_5));
    }

    SECTION("Base operations-Accessors")
    {
        Vectorf<4> v1{{1.f, 2.f, 3.f, 4.f}};
        v1(0, 0) = 5.f;
        v1(1, 0) = 6.f;
        Vectorf<4> v1_{{5.f, 6.f, 3.f, 4.f}};
        REQUIRE_THAT(v1, EqualsMatrix(v1_));

        REQUIRE(is_same_v<decltype(v1.col(0)), Matrixf<4, 1>> == true);
        REQUIRE(is_same_v<decltype(v1.col(0).castContainer<Vectorf<4>>()), Vectorf<4>> == true);
        REQUIRE(is_same_v<decltype(v1.row(0)), Matrixf<1, 1>> == true);
        REQUIRE(is_same_v<decltype(v1.block<2, 1>(0, 0)), Matrixf<2, 1>> == true);

        Matrixf<4, 1> m1 = v1.col(0);
        REQUIRE_THAT(m1, EqualsMatrix(Matrixf<4, 1>{{5.f, 6.f, 3.f, 4.f}}));
        Vectorf<4> v1_2 = v1.col(0).castContainer<Vectorf<4>>();
        REQUIRE_THAT(v1_2, EqualsMatrix(v1_));
        Matrixf<1, 1> m2 = v1.row(0);
        REQUIRE_THAT(m2, EqualsMatrix(Matrixf<1, 1>{{5.f}}));
        Matrixf<2, 1> m3 = v1.block<2, 1>(0, 0);
        REQUIRE_THAT(m3, EqualsMatrix(Matrixf<2, 1>{{5.f, 6.f}}));
    }

    SECTION("Vector Specialized Accessors")
    {
        Vectorf<3> v1{{1.f, 2.f, 3.f}};
        REQUIRE(v1[0] == 1.f);
        REQUIRE(v1[1] == 2.f);
        REQUIRE(v1[2] == 3.f);
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