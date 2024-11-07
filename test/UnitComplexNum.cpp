
#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

TEST_CASE("UnitComplexNum", "[objects]")
{
    ComplexNumf c1{1.0f, 2.0f};
    ComplexNumf c1_normed = c1.normalized();

    SECTION("constructor")
    {
        UnitComplexNumf uc0;
        REQUIRE_THAT(uc0.cast2Vector(), EqualsMatrix(Vectorf<2>{{1.0f, 0.0f}}));

        UnitComplexNumf uc1 = c1.cast2UnitComplexNum();
        UnitComplexNumf uc2 = c1_normed.cast2UnitComplexNum();

        REQUIRE(close_enough(c1.norm(), 2.2360679774997896964091736687313f));
        REQUIRE(close_enough(uc1.norm(), 1.0f));
        REQUIRE(close_enough(c1_normed.norm(), 1.0f));
        REQUIRE(close_enough(uc2.norm(), 1.0f));

        REQUIRE(close_enough(uc1.Re(), c1_normed.Re()));
        REQUIRE(close_enough(uc1.Im(), c1_normed.Im()));

        Vectorf<2> vec1{{1.0f, 2.0f}};
        Vectorf<2> vec1_normed = vec1.normalized();

        UnitComplexNum uc3 = vec1.cast2UnitComplexNum();
        REQUIRE_THAT(uc3.cast2Vector(), EqualsMatrix(vec1_normed));

        const UnitComplexNumf &uc4 = vec1.cast2UnitComplexNum();
        REQUIRE_THAT(uc4.cast2Vector(), EqualsMatrix(vec1_normed));

        UnitComplexNumf &uc5 = vec1.cast2UnitComplexNumRef(); // this also normalizes the original vector too
        REQUIRE_THAT(uc5.cast2Vector(), EqualsMatrix(vec1_normed));
        REQUIRE_THAT(vec1, EqualsMatrix(vec1_normed));

        const UnitComplexNumf &uc6 = vec1.cast2UnitComplexNumRef(); // this also normalizes the original vector too
        REQUIRE_THAT(uc6.cast2Vector(), EqualsMatrix(vec1_normed));
        REQUIRE_THAT(vec1, EqualsMatrix(vec1_normed));

        uc5.Re() = 2.f; // force a change
        REQUIRE(close_enough(uc3.Re(), 2.f) == false);
        REQUIRE(close_enough(uc4.Re(), 2.f) == false);
        REQUIRE(close_enough(uc5.Re(), 2.f));
        REQUIRE(close_enough(uc6.Re(), 2.f));
    }

    SECTION("accessor")
    {
        UnitComplexNumf uc1 = c1.cast2UnitComplexNum();
        REQUIRE(close_enough(uc1.Re(), 0.44721359549995793928183473374626f));
        REQUIRE(close_enough(uc1.Im(), 0.89442719099991587856366946749226f));
    }

    SECTION("operator")
    {
        // all operation from matrixbase is deleted, redefined inside the class
        UnitComplexNumf uc1 = c1.cast2UnitComplexNum();
        Matrix<2, 1, float> m21{{2.f, 3.f}};
        UnitComplexNumf uc2 = m21.cast2UnitComplexNum();

        { // operator +
            Vectorf<2> operator_plus_res = (uc1 + uc2).cast2Vector();
            auto res1 = uc1 + uc2; // unit + unit = non-unit (specialized operator+)
            REQUIRE(is_same_v<decltype(res1), ComplexNumf>);
            REQUIRE_THAT(res1.cast2Vector(), EqualsMatrix(operator_plus_res));

            auto res2 = uc1 + uc2.cast2ComplexNum(); // unit + non-unit = non-unit (specialized operator+)
            REQUIRE(is_same_v<decltype(res2), ComplexNumf>);
            REQUIRE_THAT(res2.cast2Vector(), EqualsMatrix(operator_plus_res));

            auto res3 = uc1.cast2ComplexNum() + uc2; // non-unit + unit = non-unit (inherited from matrixbase operator+, always follows the left instance's type)
            REQUIRE(is_same_v<decltype(res3), ComplexNumf>);
            REQUIRE_THAT(res3.cast2Vector(), EqualsMatrix(operator_plus_res));

            auto res4 = uc1.cast2Vector() + uc2; // other + unit = other
            REQUIRE(is_same_v<decltype(res4), Vectorf<2>>);
            REQUIRE_THAT(res4.cast2Vector(), EqualsMatrix(operator_plus_res));

            auto res5 = uc1 + uc2.cast2Vector();
            REQUIRE(is_same_v<decltype(res5), ComplexNumf>);
            REQUIRE_THAT(res5.cast2Vector(), EqualsMatrix(operator_plus_res));
        }

        { // operator -
            Vectorf<2> operator_minus_res = (uc1 - uc2).cast2Vector();
            auto res1 = uc1 - uc2; // unit - unit = non-unit (specialized operator-)
            REQUIRE(is_same_v<decltype(res1), ComplexNumf>);
            REQUIRE_THAT(res1.cast2Vector(), EqualsMatrix(operator_minus_res));

            auto res2 = uc1 - uc2.cast2ComplexNum(); // unit - non-unit = non-unit (specialized operator-)
            REQUIRE(is_same_v<decltype(res2), ComplexNumf>);
            REQUIRE_THAT(res2.cast2Vector(), EqualsMatrix(operator_minus_res));

            auto res3 = uc1.cast2ComplexNum() - uc2; // non-unit - unit = non-unit (inherited from matrixbase operator-, always follows the left instance's type)
            REQUIRE(is_same_v<decltype(res3), ComplexNumf>);
            REQUIRE_THAT(res3.cast2Vector(), EqualsMatrix(operator_minus_res));

            auto res4 = uc1.cast2Vector() - uc2; // other - unit = other
            REQUIRE(is_same_v<decltype(res4), Vectorf<2>>);
            REQUIRE_THAT(res4.cast2Vector(), EqualsMatrix(operator_minus_res));

            auto res5 = uc1 - uc2.cast2Vector();
            REQUIRE(is_same_v<decltype(res5), ComplexNumf>);
            REQUIRE_THAT(res5.cast2Vector(), EqualsMatrix(operator_minus_res));
        }

        { // operator *
            Vectorf<2> operator_mul_res = (uc1.cast2ComplexNumRef() * uc2.cast2ComplexNumRef()).cast2Vector();
            auto res1 = uc1 * uc2; // unit * unit = unit;
            REQUIRE(is_same_v<decltype(res1), UnitComplexNumf>);
            REQUIRE_THAT(res1.cast2Vector(), EqualsMatrix(operator_mul_res));

            auto res2 = uc1 * uc2.cast2ComplexNum(); // unit * non-unit = non-unit
            REQUIRE(is_same_v<decltype(res2), ComplexNumf>);
            REQUIRE_THAT(res2.cast2Vector(), EqualsMatrix(operator_mul_res));

            auto res3 = uc1.cast2ComplexNum() * uc2; // non-unit * unit = non-unit (specialized operator* in unitcomplexnum)
            REQUIRE(is_same_v<decltype(res3), ComplexNumf>);
            REQUIRE_THAT(res3.cast2Vector(), EqualsMatrix(operator_mul_res));

            auto res4 = uc1.cast2Vector().T() * uc2; // other * unit = other
            auto operator_mul_res2 = uc1.cast2Vector().T() * uc2.cast2Vector();
            REQUIRE(is_same_v<decltype(res4), float>);
            REQUIRE_THAT(res4, EqualsMatrix(operator_mul_res2));

            UnitComplexNumf uc3 = uc1; // only unit *= unit allowed
            uc3 *= uc2;
            REQUIRE(is_same_v<decltype(uc3), UnitComplexNumf>);
            REQUIRE_THAT(uc3.cast2Vector(), EqualsMatrix(operator_mul_res));

            auto res5 = uc1 * 2.f; // unit * scalar = non-unit
            REQUIRE(is_same_v<decltype(res5), ComplexNumf>);
            REQUIRE_THAT(res5.cast2Vector(), EqualsMatrix(uc1.cast2Vector() * 2.f));

            auto res6 = 2.f * uc1; // scalar * unit = non-unit (derived from matrixbase operator*)
            REQUIRE(is_same_v<decltype(res6), ComplexNumf>);
            REQUIRE_THAT(res6.cast2Vector(), EqualsMatrix(uc1.cast2Vector() * 2.f));

            ComplexNumf c11 = c1;
            c11 *= uc1;
            REQUIRE_THAT(c11.cast2Vector(), EqualsMatrix((c1 * uc1).cast2Vector()));

            // alias for operator* for readability
            auto res11 = uc1.complexNumMul(uc2);
            REQUIRE(is_same_v<decltype(res11), UnitComplexNumf>);
            REQUIRE_THAT(res11.cast2Vector(), EqualsMatrix(operator_mul_res));

            auto res22 = uc1.complexNumMul(uc2.cast2ComplexNum()); // unit * unit = unit;
            REQUIRE(is_same_v<decltype(res22), ComplexNumf>);
            REQUIRE_THAT(res22.cast2Vector(), EqualsMatrix(operator_mul_res));

            auto res33 = uc1.cast2ComplexNum().complexNumMul(uc2); // non-unit * unit = non-unit
            REQUIRE(is_same_v<decltype(res33), ComplexNumf>);
            REQUIRE_THAT(res33.cast2Vector(), EqualsMatrix(operator_mul_res));
        }

        { // operator /
            Vectorf<2> operator_div_res = (uc1.cast2ComplexNumRef() / uc2.cast2ComplexNumRef()).cast2Vector();
            auto res1 = uc1 / uc2; //  unit / unit = unit;
            REQUIRE(is_same_v<decltype(res1), UnitComplexNumf>);
            REQUIRE_THAT(res1.cast2Vector(), EqualsMatrix(operator_div_res));

            auto res2 = uc1 / uc2.cast2ComplexNum(); // unit / non-unit = non-unit
            REQUIRE(is_same_v<decltype(res2), ComplexNumf>);
            REQUIRE_THAT(res2.cast2Vector(), EqualsMatrix(operator_div_res));

            auto res3 = uc1.cast2ComplexNum() / uc2; // non-unit / unit = non-unit (specialized operator/ in unitcomplexnum)
            REQUIRE(is_same_v<decltype(res3), ComplexNumf>);
            REQUIRE_THAT(res3.cast2Vector(), EqualsMatrix(operator_div_res));

            auto res5 = uc1 / 2.f; // unit / scalar = non-unit
            REQUIRE(is_same_v<decltype(res5), ComplexNumf>);
            REQUIRE_THAT(res5.cast2Vector(), EqualsMatrix(uc1.cast2Vector() / 2.f));

            ComplexNumf c11 = c1;
            c11 /= uc1;
            REQUIRE_THAT(c11.cast2Vector(), EqualsMatrix((c1 / uc1).cast2Vector()));

            // alias for operator/ for readability
            auto res11 = uc1.complexNumDiv(uc2);
            REQUIRE(is_same_v<decltype(res11), UnitComplexNumf>);
            REQUIRE_THAT(res11.cast2Vector(), EqualsMatrix(operator_div_res));

            auto res22 = uc1.complexNumDiv(uc2.cast2ComplexNum()); // unit / unit = unit;
            REQUIRE(is_same_v<decltype(res22), ComplexNumf>);
            REQUIRE_THAT(res22.cast2Vector(), EqualsMatrix(operator_div_res));

            auto res333 = uc1.cast2ComplexNum().complexNumDiv(uc2);
            REQUIRE(is_same_v<decltype(res333), ComplexNumf>);
            REQUIRE_THAT(res333.cast2Vector(), EqualsMatrix(operator_div_res));

            auto res33 = uc1.cast2ComplexNum().complexNumDiv(uc2); // non-unit / unit = non-unit
            REQUIRE(is_same_v<decltype(res33), ComplexNumf>);
            REQUIRE_THAT(res33.cast2Vector(), EqualsMatrix(operator_div_res));
        }
    }

    SECTION("utils")
    {
        UnitComplexNumf uc1 = c1.cast2UnitComplexNum();
        UnitComplexNumf uc1_inv = uc1.inversed();
        UnitComplexNumf uc1_inv2 = uc1.conjugated();
        Vectorf<2> v{{1.0f, 2.0f}};

        Vectorf<2> v_rot = uc1.rotateVector2D(v);
        Vectorf<2> v_rot_inv = uc1_inv.rotateVector2D(v_rot);
        Vectorf<2> v_rot_inv2 = uc1_inv2.rotateVector2D(v_rot);
        REQUIRE_THAT(v_rot_inv, EqualsMatrix(v));
        REQUIRE_THAT(v_rot_inv2, EqualsMatrix(v));
    }

    SECTION("static functions")
    {
        auto uc_id = UnitComplexNumf::identity();
        UnitComplexNumf uc_id2{1.f, 0.f};
        REQUIRE_THAT(uc_id2, EqualsMatrix(uc_id));
    }

    SECTION("casting")
    {
        UnitComplexNumf uc1 = c1.cast2UnitComplexNum();
        auto m = uc1.toRotMatrix2D();
        REQUIRE(is_same_v<decltype(m), SOGroupf<2>>);
        Vectorf<2> vec{{1.0f, 2.0f}};
        Vectorf<2> vec_rot = uc1.rotateVector2D(vec);
        Vectorf<2> vec_rot_ = m * vec;
        REQUIRE_THAT(vec_rot, EqualsMatrix(vec_rot_));

        SquareMatrixf<2> m2 = uc1.toMulMatrix();
        REQUIRE_THAT(m2.cast2Matrix(), EqualsMatrix(m.cast2Matrix()));
    }
}