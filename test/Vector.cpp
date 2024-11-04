
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
        Vectorf<1> v1{{4.f}};
        REQUIRE_THAT(v1[0], Catch::Matchers::WithinRel(4.f, 0.0001f));
        REQUIRE_THAT(v1.x(), Catch::Matchers::WithinRel(4.f, 0.0001f));
        v1.x() = 100.f;
        REQUIRE_THAT(v1[0], Catch::Matchers::WithinRel(100.f, 0.0001f));
        REQUIRE_THAT(v1.x(), Catch::Matchers::WithinRel(100.f, 0.0001f));

        Vectorf<2> v2{{1.f, 2.f}};
        REQUIRE(v2[0] == 1.f);
        REQUIRE(v2[1] == 2.f);
        REQUIRE_THAT(v2.x(), Catch::Matchers::WithinRel(1.f, 0.0001f));
        REQUIRE_THAT(v2.y(), Catch::Matchers::WithinRel(2.f, 0.0001f));
        v2.y() = 200.f;
        REQUIRE(v2[1] == 200.f);
        REQUIRE_THAT(v2.y(), Catch::Matchers::WithinRel(200.f, 0.0001f));

        Vectorf<3> v3{{1.f, 2.f, 3.f}};
        REQUIRE(v3[0] == 1.f);
        REQUIRE(v3[1] == 2.f);
        REQUIRE(v3[2] == 3.f);
        REQUIRE_THAT(v3.x(), Catch::Matchers::WithinRel(1.f, 0.0001f));
        REQUIRE_THAT(v3.y(), Catch::Matchers::WithinRel(2.f, 0.0001f));
        REQUIRE_THAT(v3.z(), Catch::Matchers::WithinRel(3.f, 0.0001f));
        v3.z() = 300.f;
        REQUIRE(v3[2] == 300.f);
        REQUIRE_THAT(v3.z(), Catch::Matchers::WithinRel(300.f, 0.0001f));

        Vectorf<4> v4{{1.f, 2.f, 3.f, 4.f}};
        REQUIRE(v4[0] == 1.f);
        REQUIRE(v4[1] == 2.f);
        REQUIRE(v4[2] == 3.f);
        REQUIRE(v4[3] == 4.f);
        // REQUIRE_THAT(v4.x(), Catch::Matchers::WithinRel(1.f, 0.0001f));
        // REQUIRE_THAT(v4.y(), Catch::Matchers::WithinRel(2.f, 0.0001f));
        // REQUIRE_THAT(v4.z(), Catch::Matchers::WithinRel(3.f, 0.0001f));
    }

    SECTION("Vector specialized operatotions")
    {
        Vectorf<4> v1{{1.f, 2.f, 3.f, 4.f}};
        Vectorf<4> v2{{5.f, 6.f, 7.f, 8.f}};

        Vectorf<4> v3 = v1 + v2;
        Vectorf<4> v3_{{6.f, 8.f, 10.f, 12.f}};
        REQUIRE_THAT(v3, EqualsMatrix(v3_));

        Vectorf<4> v4 = v1 - v2;
        Vectorf<4> v4_{{-4.f, -4.f, -4.f, -4.f}};
        REQUIRE_THAT(v4, EqualsMatrix(v4_));

        Vectorf<1> v5 = v1.T() * v2;
        Vectorf<1> v5_{{70.f}};
        REQUIRE_THAT(v5, EqualsMatrix(v5_));

        float v55_f = v1.dot(v2);
        float v55f2 = v2.dot(v1);
        REQUIRE_THAT(v55_f, Catch::Matchers::WithinRel(70.f, 0.0001f));
        Vectorf<1> v55{{v1.dot(v2)}};
        Vectorf<1> v55_{{v2.dot(v1)}};
        REQUIRE_THAT(v55, EqualsMatrix(v55_));

        Vectorf<3> v6{{1.f, 2.f, 3.f}};
        Vectorf<3> v7{{4.f, 5.f, 6.f}};

        Vectorf<3> v67 = v6.cross(v7);
        Vectorf<3> v67_{{-3.f, 6.f, -3.f}};
        REQUIRE_THAT(v67, EqualsMatrix(v67_));

        Vectorf<3> v76 = v7.cross(v6);
        Vectorf<3> v76_ = -v67_;
        REQUIRE_THAT(v76, EqualsMatrix(v76_));

        SquareMatrixf<3> m1 = v6.toCrossMatrix();
        SquareMatrixf<3> m1_{{0.f, -3.f, 2.f,
                              3.f, 0.f, -1.f,
                              -2.f, 1.f, 0.f}};
        REQUIRE_THAT(m1, EqualsMatrix(m1_));
        Vectorf<3> v67__ = m1 * v7;
        REQUIRE_THAT(v67__, EqualsMatrix(v67_));

        SquareMatrixf<3> m2 = v7.toDiagMatrix();
        SquareMatrixf<3> m2_{{4.f, 0.f, 0.f,
                              0.f, 5.f, 0.f,
                              0.f, 0.f, 6.f}};
        REQUIRE_THAT(m2, EqualsMatrix(m2_));
    }

    SECTION("vector static function")
    {
        auto vx = Vectorf<3>::xAxis();
        auto vy = Vectorf<2>::yAxis();
        auto vz = Vectorf<3>::zAxis();

        REQUIRE_THAT(vx, EqualsMatrix(Vectorf<3>{{1.f, 0.f, 0.f}}));
        REQUIRE_THAT(vy, EqualsMatrix(Vectorf<2>{{0.f, 1.f}}));
        REQUIRE_THAT(vz, EqualsMatrix(Vectorf<3>{{0.f, 0.f, 1.f}}));
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