#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

TEST_CASE("ComplexNum", "[objects]")
{
    ComplexNumf c1{1.0f, 2.0f};

    SECTION("constructor")
    {
        ComplexNumf c2;
        ComplexNumf c3{};
        ComplexNumf c23_{{0.0f, 0.0f}};
        REQUIRE_THAT(c2, EqualsMatrix(c23_));
        REQUIRE_THAT(c3, EqualsMatrix(c23_));

        ComplexNumf c4{c1};
        ComplexNumf c5 = c1;
        REQUIRE_THAT(c4, EqualsMatrix(c1));
        REQUIRE_THAT(c5, EqualsMatrix(c1));

        ComplexNumf c6{11.0f, 22.0f};
        ComplexNumf c6_{{11.0f, 22.0f}};
        REQUIRE_THAT(c6, EqualsMatrix(c6_));
    }

    SECTION("accessor")
    {
        ComplexNumf c2 = c1;
        REQUIRE(c2.Re() == 1.0f);
        REQUIRE(c2.Im() == 2.0f);
        REQUIRE(c2[0] == 1.0f);
        REQUIRE(c2[1] == 2.0f);

        ComplexNumf c3 = c1;
        c3.Re() = 11.0f;
        c3.Im() = 22.0f;
        REQUIRE(c3.Re() == 11.0f);
        REQUIRE(c3.Im() == 22.0f);
        REQUIRE(c3[0] == 11.0f);
        REQUIRE(c3[1] == 22.0f);

        ComplexNumf c4 = c1;
        c4[0] = 111.0f;
        c4[1] = 222.0f;
        REQUIRE(c4.Re() == 111.0f);
        REQUIRE(c4.Im() == 222.0f);
    }

    SECTION("operator")
    {
        ComplexNumf c2{1.0f, 2.0f};
        ComplexNumf c3{3.0f, 4.0f};
        ComplexNumf c23 = c2 * c3;
        ComplexNumf c32 = c3 * c2;
        REQUIRE_THAT(c23, EqualsMatrix(ComplexNumf{-5.0f, 10.0f}));
        REQUIRE_THAT(c23, EqualsMatrix(c32));
        ComplexNumf c23_alias = c2.complexNumMul(c3);
        REQUIRE_THAT(c23_alias, EqualsMatrix(c23));

        ComplexNumf c23__ = c2;
        c23__ *= c3;
        REQUIRE_THAT(c23__, EqualsMatrix(c23));
        ComplexNumf c23__alias = c2;
        c23__alias.complexNumMulEq(c3);
        REQUIRE_THAT(c23__alias, EqualsMatrix(c23));

        ComplexNumf c2_3 = c2 / c3;
        REQUIRE_THAT(c2_3, EqualsMatrix(ComplexNumf{0.44f, 0.08f}));
        ComplexNumf c2_3_alias = c2.complexNumDiv(c3);
        REQUIRE_THAT(c2_3_alias, EqualsMatrix(c2_3));
        c2_3 *= c3;
        REQUIRE_THAT(c2_3, EqualsMatrix(c2));

        ComplexNumf c2_3__ = c2;
        c2_3__ /= c3;
        c2_3 = c2 / c3;
        REQUIRE_THAT(c2_3__, EqualsMatrix(c2_3));
        ComplexNumf c2_3__alias = c2;
        c2_3__alias.complexNumDivEq(c3);
        REQUIRE_THAT(c2_3__alias, EqualsMatrix(c2_3__));

        ComplexNumf c4 = c2 + c3;
        REQUIRE_THAT(c4, EqualsMatrix(ComplexNumf{4.0f, 6.0f}));
        ComplexNumf c5 = c2 - c3;
        REQUIRE_THAT(c5, EqualsMatrix(ComplexNumf{-2.0f, -2.0f}));

        ComplexNumf c6 = c2 * 2.0f;
        REQUIRE_THAT(c6, EqualsMatrix(ComplexNumf{2.0f, 4.0f}));
        ComplexNumf c66 = 2.0f * c2;
        REQUIRE_THAT(c66, EqualsMatrix(c6));

        ComplexNumf c7 = c2 / 2.0f;
        REQUIRE_THAT(c7, EqualsMatrix(ComplexNumf{0.5f, 1.0f}));
        ComplexNumf c77 = (1.f / 2.0f) * c2;
        REQUIRE_THAT(c77, EqualsMatrix(c7));
    }

    SECTION("utils")
    {
        const float normsquared = c1.normSquared();
        REQUIRE(close_enough(normsquared, 5.0f));
        const float norm = c1.norm();
        REQUIRE(close_enough(norm, 2.2360679774997896964091736687313f));

        ComplexNumf c2 = c1.normalized();
        REQUIRE(close_enough(c2.norm(), 1.0f));
        REQUIRE_THAT(c2, EqualsMatrix(ComplexNumf{0.44721359549995793928183473374626f, 0.89442719099991587856366946749252f}));

        ComplexNumf c22 = c1;
        c22.normalize();
        REQUIRE_THAT(c22, EqualsMatrix(c2));

        ComplexNumf c3 = c1.conjugated();
        REQUIRE_THAT(c3, EqualsMatrix(ComplexNumf{1.0f, -2.0f}));

        ComplexNumf c4 = c1;
        c4.conjugate();
        REQUIRE_THAT(c4, EqualsMatrix(c3));

        ComplexNumf c5 = c1.inversed();
        REQUIRE_THAT(c5, EqualsMatrix(ComplexNumf{0.2f, -0.4f}));

        ComplexNumf c6 = c1;
        c6.inverse();
        REQUIRE_THAT(c6, EqualsMatrix(c5));
    }

    SECTION("casting")
    {
        ComplexNumf c2 = c1.normalized();

        SquareMatrix<2, float> m = c2.toMulMatrix();
        const float c = 0.44721359549995793928183473374626f;
        const float s = 0.89442719099991587856366946749252f;
        REQUIRE_THAT(m, EqualsMatrix(SquareMatrix<2, float>{{c, -s,
                                                             s, c}}));
    }
}