#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

TEST_CASE("DualNumber", "[objects]")
{
    DualNumberf d1{2.f, 3.f};
    DualNumberf d1_{{2.f, 3.f}};

    SECTION("constructors")
    {
        DualNumberf d2{};
        DualNumberf d2_{0.f, 0.f};
        REQUIRE_THAT(d2, EqualsMatrix(d2_));

        DualNumberf d3{};
        DualNumberf d3_{0.f, 0.f};
        REQUIRE_THAT(d3, EqualsMatrix(d3_));

        Vectorf<2> v{{2.f, 3.f}};
        DualNumberf d4 = v.cast2DualNumber();
        DualNumberf d4_{2.f, 3.f};
        REQUIRE_THAT(d4, EqualsMatrix(d4_));
    }

    SECTION("accessors")
    {
        DualNumberf d2 = d1;
        REQUIRE(d2.Re() == 2.f);
        REQUIRE(d2.Du() == 3.f);

        d2.Re() = 12.f;
        d2.Du() = 13.f;
        REQUIRE(d2.Re() == 12.f);
        REQUIRE(d2.Du() == 13.f);

        REQUIRE(close_enough(d2[0], 12.f));
        REQUIRE(close_enough(d2[1], 13.f));
    }

    SECTION("casting")
    {
        SquareMatrixf<2> d1_mulmat = d1.toMulMatrix();
        SquareMatrixf<2> d1_mulmat_{{2.f, 0.f,
                                     3.f, 2.f}};
        REQUIRE_THAT(d1_mulmat, EqualsMatrix(d1_mulmat_));

        DualNumberf d2{12, 13.f};
        DualNumberf d1d2 = d1 * d2;
        DualNumberf d1d2_ans = DualNumberf{24.f, 62.f};
        REQUIRE_THAT(d1d2, EqualsMatrix(d1d2_ans));

        DualNumberf d1d2__2 = d2 * d1;
        REQUIRE_THAT(d1d2__2, EqualsMatrix(d1d2_ans)); // commutative property
    }

    SECTION("operators")
    {
        // operator +
        {
            DualNumberf d2{1.f, 2.f};
            DualNumberf d3{3.f, 4.f};
            Vectorf<2> v{{3.f, 4.f}};

            auto d2d3 = d2 + d3; // dn + dn = dn
            DualNumberf d2d3_{4.f, 6.f};
            REQUIRE(is_same_v<decltype(d2d3), DualNumberf>);
            REQUIRE_THAT(d2d3, EqualsMatrix(d2d3_));

            DualNumber d2_eq = d2;
            d2_eq += d3;
            REQUIRE_THAT(d2_eq, EqualsMatrix(d2d3_));

            auto d2v = d2 + v; // dn + v = dn
            REQUIRE(is_same_v<decltype(d2v), DualNumberf>);
            REQUIRE_THAT(d2v, EqualsMatrix(d2d3_));

            DualNumberf d2v_eq = d2;
            d2v_eq += v;
            REQUIRE_THAT(d2v_eq, EqualsMatrix(d2d3_));
        }

        { // operator -
            DualNumberf d2{1.f, 2.f};
            DualNumberf d3{3.f, 4.f};
            Vectorf<2> v{{3.f, 4.f}};

            auto d2d3 = d2 - d3; // dn - dn = dn
            DualNumberf d2d3_{-2.f, -2.f};
            REQUIRE(is_same_v<decltype(d2d3), DualNumberf>);
            REQUIRE_THAT(d2d3, EqualsMatrix(d2d3_));

            DualNumberf d2_eq = d2;
            d2_eq -= d3;
            REQUIRE_THAT(d2_eq, EqualsMatrix(d2d3_));

            auto d2v = d2 - v; // dn - v = dn
            REQUIRE(is_same_v<decltype(d2v), DualNumberf>);
            REQUIRE_THAT(d2v, EqualsMatrix(d2d3_));

            DualNumberf d2v_eq = d2;
            d2v_eq -= v;
            REQUIRE_THAT(d2v_eq, EqualsMatrix(d2d3_));
        }

        { // operator *
            DualNumberf d2{1.f, 2.f};
            DualNumberf d3{3.f, 4.f};
            Vectorf<2> v{{3.f, 4.f}};

            auto d2d3 = d2 * d3; // dn * dn = dn
            DualNumberf d2d3_{3.f, 10.f};
            REQUIRE(is_same_v<decltype(d2d3), DualNumberf>);
            REQUIRE_THAT(d2d3, EqualsMatrix(d2d3_));

            DualNumberf d2d3_eq = d2;
            d2d3_eq *= d3;
            REQUIRE_THAT(d2d3_eq, EqualsMatrix(d2d3_));

            auto d2d3_2 = d2 * 3.f; // dn * scalar = dn
            DualNumberf d2d3_2_{3.f, 6.f};
            REQUIRE(is_same_v<decltype(d2d3_2), DualNumberf>);
            REQUIRE_THAT(d2d3_2, EqualsMatrix(d2d3_2_));
            DualNumberf d2d3_2_eq = d2;
            d2d3_2_eq *= 3.f;
            REQUIRE_THAT(d2d3_2_eq, EqualsMatrix(d2d3_2_));

            auto d2v = d2 * v.T(); // dn * vector = matrix
            SquareMatrixf<2> d2v_{{3.f, 4.f,
                                   6.f, 8.f}};
            REQUIRE(is_same_v<decltype(d2v), SquareMatrixf<2>>);
            REQUIRE_THAT(d2v, EqualsMatrix(d2v_));
        }

        { // operator /
            DualNumberf d2{1.f, 2.f};
            DualNumberf d3{3.f, 4.f};
            Vectorf<2> v{{3.f, 4.f}};

            auto d2d3 = d2 / d3; // dn / dn = dn
            REQUIRE(is_same_v<decltype(d2d3), DualNumberf>);
            REQUIRE_THAT(d2d3, EqualsMatrix(DualNumberf{1.f / 3.f, 2.f / 9.f}));

            DualNumberf d2d3_eq = d2;
            d2d3_eq /= d3;
            REQUIRE_THAT(d2d3_eq, EqualsMatrix(DualNumberf{1.f / 3.f, 2.f / 9.f}));

            DualNumberf d2d3_inv = d2 * d3.inversed();
            REQUIRE_THAT(d2d3_inv, EqualsMatrix(DualNumberf{1.f / 3.f, 2.f / 9.f}));

            auto d2d3_2 = d2 / 3.f; // dn / scalar = dn
            REQUIRE(is_same_v<decltype(d2d3_2), DualNumberf>);
            REQUIRE_THAT(d2d3_2, EqualsMatrix(DualNumberf{1.f / 3.f, 2.f / 3.f}));

            DualNumberf d2d3_2_eq = d2;
            d2d3_2_eq /= 3.f;
            REQUIRE_THAT(d2d3_2_eq, EqualsMatrix(DualNumberf{1.f / 3.f, 2.f / 3.f}));
        }
    }

    SECTION("utils")
    {
        const float norm = d1.norm();
        const float norm_squared = d1.normSquared();
        REQUIRE(close_enough(norm, 2.f));
        REQUIRE(close_enough(norm_squared, 4.f));

        DualNumberf d2 = d1.conjugated();
        DualNumberf d2_{2.f, -3.f};
        REQUIRE_THAT(d2, EqualsMatrix(d2_));

        DualNumberf d22 = d1;
        d22.conjugate();
        REQUIRE_THAT(d22, EqualsMatrix(d2_));

        DualNumberf d3 = d1.inversed();
        const float d1_normSq = d1.normSquared();
        DualNumberf d3_{2.f / d1_normSq, -3.f / d1_normSq};
        REQUIRE_THAT(d3, EqualsMatrix(d3_));

        DualNumberf d4 = d1.normalized();
        const float d1_norm = d1.norm();
        DualNumberf d4_{2.f / d1_norm, 3.f / d1_norm};
        REQUIRE_THAT(d4, EqualsMatrix(d4_));

        DualNumberf d5 = d1;
        d5.normalize();
        REQUIRE_THAT(d5, EqualsMatrix(d4_));
    }
}