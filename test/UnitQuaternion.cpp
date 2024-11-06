
#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

TEST_CASE("UnitQuaternion", "[objects]")
{
    Quaternionf q1{1.0f, 2.0f, 3.0f, 4.0f};
    Quaternionf q1_normed = q1.normalized();

    SECTION("constructor")
    {
        UnitQuaternionf uq0;
        REQUIRE_THAT(uq0.toVector(), EqualsMatrix(Vectorf<4>{{1.0f, 0.0f, 0.0f, 0.0f}}));

        UnitQuaternionf uq1 = q1.toUnitQuaternion();
        UnitQuaternionf uq2 = q1_normed.toUnitQuaternion();

        REQUIRE(close_enough(q1.norm(), 5.4772255750516611345696978280085f));
        REQUIRE(close_enough(uq1.norm(), 1.0f));
        REQUIRE(close_enough(q1_normed.norm(), 1.0f));
        REQUIRE(close_enough(uq2.norm(), 1.0f));

        REQUIRE(close_enough(uq1.Re(), q1_normed.Re()));
        REQUIRE_THAT(uq1.Im(), EqualsMatrix(q1_normed.Im()));

        Vectorf<4> vec1{{1.0f, 2.0f, 3.0f, 4.0f}};
        Vectorf<4> vec1_normed = vec1.normalized();

        UnitQuaternionf uq3 = vec1.toUnitQuaternion();
        REQUIRE_THAT(uq3.toVector(), EqualsMatrix(vec1_normed));

        const UnitQuaternionf &uq4 = vec1.toUnitQuaternion();
        REQUIRE_THAT(uq4.toVector(), EqualsMatrix(vec1_normed));

        UnitQuaternionf &uq5 = vec1.toUnitQuaternionRef(); // this also normalizes the original vector too
        REQUIRE_THAT(uq5.toVector(), EqualsMatrix(vec1_normed));
        REQUIRE_THAT(vec1, EqualsMatrix(vec1_normed));

        const UnitQuaternionf &uq6 = vec1.toUnitQuaternionRef(); // this also normalizes the original vector too
        REQUIRE_THAT(uq6.toVector(), EqualsMatrix(vec1_normed));
        REQUIRE_THAT(vec1, EqualsMatrix(vec1_normed));

        uq5.Re() = 2.f; // force a change
        REQUIRE(close_enough(uq3.Re(), 2.f) == false);
        REQUIRE(close_enough(uq4.Re(), 2.f) == false);
        REQUIRE(close_enough(uq5.Re(), 2.f));
        REQUIRE(close_enough(uq6.Re(), 2.f));
    }

    SECTION("accessor")
    {
        UnitQuaternionf uq1 = q1.toUnitQuaternion();
        REQUIRE(close_enough(uq1.Re(), 0.1825741858350553711523232609336f));
        REQUIRE_THAT(uq1.Im(), EqualsMatrix(Vectorf<3>{{0.3651483716701107423046465218672f, 0.54772255750516611345696978280085f, 0.7302967433402214846092930437344f}}));
    }

    SECTION("operator")
    {
        UnitQuaternionf uq1 = q1.toUnitQuaternion();
        Matrix<4, 1, float> m41{{1.0f, 2.0f, 3.0f, 4.0f}};
        UnitQuaternionf uq2 = m41.toUnitQuaternion();

        { // operator +
            Vectorf<4> operator_plus_res = (uq1 + uq2).toVector();
            auto res1 = uq1 + uq2; // unit + unit = non-unit (specialized operator+)
            REQUIRE(is_same_v<decltype(res1), Quaternionf>);
            REQUIRE_THAT(res1.toVector(), EqualsMatrix(operator_plus_res));

            auto res2 = uq1 + uq2.toQuaternion(); // unit + non-unit = non-unit (specialized operator+)
            REQUIRE(is_same_v<decltype(res2), Quaternionf>);
            REQUIRE_THAT(res2.toVector(), EqualsMatrix(operator_plus_res));

            auto res3 = uq1.toQuaternion() + uq2; // non-unit + unit = non-unit (inherited from matrixbase operator+, always follows the left instance's type)
            REQUIRE(is_same_v<decltype(res3), Quaternionf>);
            REQUIRE_THAT(res3.toVector(), EqualsMatrix(operator_plus_res));

            auto res4 = uq1.toVector() + uq2; // other + unit = other
            REQUIRE(is_same_v<decltype(res4), Vectorf<4>>);
            REQUIRE_THAT(res4.toVector(), EqualsMatrix(operator_plus_res));
        }

        { // operator -
            Vectorf<4> operator_minus_res = (uq1 - uq2).toVector();
            auto res1 = uq1 - uq2; // unit - unit = non-unit (specialized operator-)
            REQUIRE(is_same_v<decltype(res1), Quaternionf>);
            REQUIRE_THAT(res1.toVector(), EqualsMatrix(operator_minus_res));

            auto res2 = uq1 - uq2.toQuaternion(); // unit - non-unit = non-unit (specialized operator-)
            REQUIRE(is_same_v<decltype(res2), Quaternionf>);
            REQUIRE_THAT(res2.toVector(), EqualsMatrix(operator_minus_res));

            auto res3 = uq1.toQuaternion() - uq2; // non-unit - unit = non-unit (inherited from matrixbase operator-, always follows the left instance's type)
            REQUIRE(is_same_v<decltype(res3), Quaternionf>);
            REQUIRE_THAT(res3.toVector(), EqualsMatrix(operator_minus_res));

            auto res4 = uq1.toVector() - uq2; // other - unit = other
            REQUIRE(is_same_v<decltype(res4), Vectorf<4>>);
        }

        { // operator *
            Vectorf<4> operator_mul_res = (uq1.toQuaternionRef() * uq2.toQuaternionRef()).toVector();
            auto res1 = uq1 * uq2; // unit * unit = unit;
            REQUIRE(is_same_v<decltype(res1), UnitQuaternionf>);
            REQUIRE_THAT(res1.toVector(), EqualsMatrix(operator_mul_res));

            auto res2 = uq1 * uq2.toQuaternion(); // unit * non-unit = non-unit
            REQUIRE(is_same_v<decltype(res2), Quaternionf>);
            REQUIRE_THAT(res2.toVector(), EqualsMatrix(operator_mul_res));

            auto res3 = uq1.toQuaternion() * uq2; // non-unit * unit = non-unit
            REQUIRE(is_same_v<decltype(res3), Quaternionf>);
            REQUIRE_THAT(res3.toVector(), EqualsMatrix(operator_mul_res));

            auto res4 = uq1.toVector().T() * uq2; // other * unit = other
            Vectorf<1> operator_mul_res2 = uq1.toVector().T() * uq2.toVector();
            REQUIRE(is_same_v<decltype(res4), Matrixf<1, 1>>);
            REQUIRE_THAT(res4.toVector(), EqualsMatrix(operator_mul_res2));

            auto res5 = uq1 * 2.f; // unit * scalar = non-unit
            REQUIRE(is_same_v<decltype(res5), Quaternionf>);
            REQUIRE_THAT(res5.toVector(), EqualsMatrix(uq1.toVector() * 2.f));

            auto res6 = 2.f * uq1; // scalar * unit = non-unit (derived from matrixbase operator*)
            REQUIRE(is_same_v<decltype(res6), Quaternionf>);
            REQUIRE_THAT(res6.toVector(), EqualsMatrix(uq1.toVector() * 2.f));

            // alias for operator* for readability
            auto res11 = uq1.quatNumMul(uq2);
            REQUIRE(is_same_v<decltype(res11), UnitQuaternionf>);
            REQUIRE_THAT(res11.toVector(), EqualsMatrix(operator_mul_res));

            auto res22 = uq1.quatNumMul(uq2.toQuaternion()); // unit * unit = unit;
            REQUIRE(is_same_v<decltype(res22), Quaternionf>);
            REQUIRE_THAT(res22.toVector(), EqualsMatrix(operator_mul_res));

            auto res33 = uq1.toQuaternion().quatNumMul(uq2); // non-unit * unit = non-unit
            REQUIRE(is_same_v<decltype(res33), Quaternionf>);
            REQUIRE_THAT(res33.toVector(), EqualsMatrix(operator_mul_res));
        }

        { // operator /

            Vectorf<4> operator_div_res = (uq1.toQuaternionRef() / uq2.toQuaternionRef()).toVector();
            auto res1 = uq1 / uq2; //  unit / unit = unit;
            REQUIRE(is_same_v<decltype(res1), UnitQuaternionf>);
            REQUIRE_THAT(res1.toVector(), EqualsMatrix(operator_div_res));

            auto res2 = uq1 / uq2.toQuaternion(); // unit / non-unit = non-unit
            REQUIRE(is_same_v<decltype(res2), Quaternionf>);
            REQUIRE_THAT(res2.toVector(), EqualsMatrix(operator_div_res));

            auto res3 = uq1.toQuaternion() / uq2; // non-unit / unit = non-unit (specialized operator/ in unitcomplexnum)
            REQUIRE(is_same_v<decltype(res3), Quaternionf>);
            REQUIRE_THAT(res3.toVector(), EqualsMatrix(operator_div_res));

            auto res5 = uq1 / 2.f; // unit / scalar = non-unit
            REQUIRE(is_same_v<decltype(res5), Quaternionf>);
            REQUIRE_THAT(res5.toVector(), EqualsMatrix(uq1.toVector() / 2.f));

            // alias for operator/ for readability
            auto res11 = uq1.quatNumDiv(uq2);
            REQUIRE(is_same_v<decltype(res11), UnitQuaternionf>);
            REQUIRE_THAT(res11.toVector(), EqualsMatrix(operator_div_res));

            auto res22 = uq1.quatNumDiv(uq2.toQuaternion()); // unit / unit = unit;
            REQUIRE(is_same_v<decltype(res22), Quaternionf>);
            REQUIRE_THAT(res22.toVector(), EqualsMatrix(operator_div_res));

            auto res33 = uq1.toQuaternion().quatNumDiv(uq2); // non-unit / unit = non-unit
            REQUIRE(is_same_v<decltype(res33), Quaternionf>);
            REQUIRE_THAT(res33.toVector(), EqualsMatrix(operator_div_res));
        }
    }

    SECTION("rotation")
    {
        Vectorf<3> v{{1.0f, 2.0f, 3.0f}};
        v.normalize();
        const float angle = 1.0f;
        UnitQuaternionf uq1{translotator::cos(angle / 2.0f), translotator::sin(angle / 2.0f) * v};

        AxisAnglef ag1 = uq1.toAxisAngle();
        REQUIRE(close_enough(ag1.angle(), angle));
        REQUIRE_THAT(ag1.axis(), EqualsMatrix(v));

        Vectorf<3> vec{{1.0f, 2.0f, 3.0f}};
        Vectorf<3> vec_rot = uq1.rotateVector3D(vec);

        SquareMatrixf<3> rot_mat = uq1.toRotMatrix3D();
        Vectorf<3> vec_rot_mat = rot_mat * vec;

        REQUIRE_THAT(vec_rot, EqualsMatrix(vec_rot_mat));
    }
}