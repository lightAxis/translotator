#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

TEST_CASE("UnitDualQuaternion", "[objects]")
{
    UnitQuaternionf qre_ans{0.9818562f, 0.0640713f, 0.0911575f, 0.1534393f};
    SO3Groupf R_ans{{0.9362934f, -0.2896295f, 0.1986693f,
                     0.3129918f, 0.9447025f, -0.0978434f,
                     -0.1593451f, 0.1537920f, 0.9751703f}};
    Vectorf<3> t_ans{{1.f, 2.f, 3.f}};
    UnitDualQuaternionf udq{qre_ans, Vectorf<3>{{1.f, 2.f, 3.f}}};
    SE3Groupf se3_ans{R_ans, t_ans};

    SECTION("constructor")
    {
        UnitDualQuaternionf udq1{};
        REQUIRE_THAT(udq1, EqualsMatrix(
                               UnitDualQuaternionf{1.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f}));

        UnitQuaternionf uq{0.9818562f, 0.0640713f, 0.0911575f, 0.1534393f};
        Quaternionf dq{0.f, 0.5f, 1.f, 1.5f};
        UnitDualQuaternionf udq2{uq, dq};
        REQUIRE_THAT(udq2.Re(), EqualsMatrix(uq));
        REQUIRE_THAT(udq2.Du(), EqualsMatrix(dq));

        UnitDualQuaternionf udq3{qre_ans, t_ans};
        Quaternionf dual_ans = 0.5f * Quaternionf{0.f, t_ans} * qre_ans;
        REQUIRE_THAT(udq3.Re(), EqualsMatrix(qre_ans));
        REQUIRE_THAT(udq3.Du(), EqualsMatrix(dual_ans));
    }

    SECTION("accessors")
    {
        UnitDualQuaternionf udq1 = udq;
        auto RE = udq1.Re();
        REQUIRE(is_same_v<decltype(RE), UnitQuaternionf>);

        udq1.Re() = UnitQuaternionf{0.1f, 0.2f, 0.3f, 0.4f};
        auto RE2 = udq1.Re();
        REQUIRE_THAT(RE2, EqualsMatrix(UnitQuaternionf{0.1f, 0.2f, 0.3f, 0.4f}));
    }

    SECTION("operators")
    {
        UnitDualQuaternionf udq1{qre_ans, t_ans};
        UnitQuaternionf qre2_ans{0.9833474f, 0.0342708f, 0.1060205f, 0.1435722f};
        Vectorf<3> t2{{11.f, 12.f, 13.f}};
        Quaternionf t2_ans = 0.5f * Quaternionf{0.f, t2} * qre2_ans;
        UnitDualQuaternionf udq2{qre2_ans, t2_ans};

        { // operator+
            Vectorf<8> operator_plus_res = (udq1 + udq2).cast2Vector();
            auto res1 = udq1 + udq2; // unit + unit = non-unit (specialized operator+)
            REQUIRE(is_same_v<decltype(res1), DualQuaternionf>);
            REQUIRE_THAT(res1.cast2Vector(), EqualsMatrix(operator_plus_res));

            auto res2 = udq1 + udq2.cast2DualQuaternion(); // unit + non-unit = non-unit (specialized operator+)
            REQUIRE(is_same_v<decltype(res2), DualQuaternionf>);
            REQUIRE_THAT(res2.cast2Vector(), EqualsMatrix(operator_plus_res));

            auto res3 = udq1.cast2DualQuaternion() + udq2; // non-unit + unit = non-unit (inherited from matrixbase operator+, always follows the left instance's type)
            REQUIRE(is_same_v<decltype(res3), DualQuaternionf>);
            REQUIRE_THAT(res3.cast2Vector(), EqualsMatrix(operator_plus_res));

            auto res4 = udq1.cast2Vector() + udq2; // other + unit = other
            REQUIRE(is_same_v<decltype(res4), Vectorf<8>>);
            REQUIRE_THAT(res4.cast2Vector(), EqualsMatrix(operator_plus_res));

            auto res5 = udq1 + udq2.cast2Vector(); // unit + other = non-unit
            REQUIRE(is_same_v<decltype(res5), DualQuaternionf>);
            REQUIRE_THAT(res5.cast2Vector(), EqualsMatrix(operator_plus_res));
        }

        { // operator -
            Vectorf<8> operator_minus_res = (udq1 - udq2).cast2Vector();
            auto res1 = udq1 - udq2; // unit - unit = non-unit (specialized operator-)
            REQUIRE(is_same_v<decltype(res1), DualQuaternionf>);
            REQUIRE_THAT(res1.cast2Vector(), EqualsMatrix(operator_minus_res));

            auto res2 = udq1 - udq2.cast2DualQuaternion(); // unit - non-unit = non-unit (specialized operator-)
            REQUIRE(is_same_v<decltype(res2), DualQuaternionf>);
            REQUIRE_THAT(res2.cast2Vector(), EqualsMatrix(operator_minus_res));

            auto res3 = udq1.cast2DualQuaternion() - udq2; // non-unit - unit = non-unit (inherited from matrixbase operator-, always follows the left instance's type)
            REQUIRE(is_same_v<decltype(res3), DualQuaternionf>);
            REQUIRE_THAT(res3.cast2Vector(), EqualsMatrix(operator_minus_res));

            auto res4 = udq1.cast2Vector() - udq2; // other - unit = other
            REQUIRE(is_same_v<decltype(res4), Vectorf<8>>);
            REQUIRE_THAT(res4.cast2Vector(), EqualsMatrix(operator_minus_res));

            auto res5 = udq1 - udq2.cast2Vector(); // unit - other = non-unit
            REQUIRE(is_same_v<decltype(res5), DualQuaternionf>);
            REQUIRE_THAT(res5.cast2Vector(), EqualsMatrix(operator_minus_res));
        }

        { // operator *
            Vectorf<8> operator_mul_res = (udq1.cast2DualQuaternionRef() * udq2.cast2DualQuaternionRef()).cast2Vector();

            auto res1 = udq1 * udq2; // unit * unit = unit;
            REQUIRE(is_same_v<decltype(res1), UnitDualQuaternionf>);
            REQUIRE_THAT(res1.cast2Vector(), EqualsMatrix(operator_mul_res));

            auto res2 = udq1 * udq2.cast2DualQuaternion(); // unit * non-unit = non-unit
            REQUIRE(is_same_v<decltype(res2), DualQuaternionf>);
            REQUIRE_THAT(res2.cast2Vector(), EqualsMatrix(operator_mul_res));

            auto res3 = udq1.cast2DualQuaternion() * udq2; // non-unit * unit = non-unit
            REQUIRE(is_same_v<decltype(res3), DualQuaternionf>);
            REQUIRE_THAT(res3.cast2Vector(), EqualsMatrix(operator_mul_res));

            auto res4 = udq1.cast2Vector().T() * udq2; // other * unit = other (1x1 is scalar)
            auto operator_mul_res2 = udq1.cast2Vector().T() * udq2.cast2Vector();
            REQUIRE(is_same_v<decltype(res4), float>);
            REQUIRE_THAT(res4, EqualsMatrix(operator_mul_res2));

            auto res5 = udq1 * 2.f; // unit * scalar = non-unit
            REQUIRE(is_same_v<decltype(res5), DualQuaternionf>);
            REQUIRE_THAT(res5.cast2Vector(), EqualsMatrix(udq1.cast2Vector() * 2.f));

            auto res6 = 2.f * udq1; // scalar * unit = non-unit (derived from matrixbase operator*)
            REQUIRE(is_same_v<decltype(res6), DualQuaternionf>);
            REQUIRE_THAT(res6.cast2Vector(), EqualsMatrix(udq1.cast2Vector() * 2.f));

            DualQuaternionf dq11 = udq1.cast2DualQuaternion();
            dq11 *= udq2;
            REQUIRE_THAT(dq11.cast2Vector(), EqualsMatrix((udq1 * udq2).cast2Vector()));

            // alias for operator* for readability
            auto res11 = udq1.dualQuatMul(udq2);
            REQUIRE(is_same_v<decltype(res11), UnitDualQuaternionf>);
            REQUIRE_THAT(res11.cast2Vector(), EqualsMatrix(operator_mul_res));

            auto res22 = udq1.dualQuatMul(udq2.cast2DualQuaternion()); // unit * unit = unit;
            REQUIRE(is_same_v<decltype(res22), DualQuaternionf>);
            REQUIRE_THAT(res22.cast2Vector(), EqualsMatrix(operator_mul_res));

            auto res333 = udq1.cast2DualQuaternion().dualQuatMul(udq2);
            REQUIRE(is_same_v<decltype(res333), DualQuaternionf>);
            REQUIRE_THAT(res333.cast2Vector(), EqualsMatrix(operator_mul_res));
        }

        { // operator /
            Vectorf<8> operator_div_res = (udq1.cast2DualQuaternionRef() / udq2.cast2DualQuaternionRef()).cast2Vector();

            auto res1 = udq1 / udq2; // unit / unit = unit;
            REQUIRE(is_same_v<decltype(res1), UnitDualQuaternionf>);
            REQUIRE_THAT(res1.cast2Vector(), EqualsMatrix(operator_div_res));

            auto res2 = udq1 / udq2.cast2DualQuaternion(); // unit / non-unit = non-unit
            REQUIRE(is_same_v<decltype(res2), DualQuaternionf>);
            REQUIRE_THAT(res2.cast2Vector(), EqualsMatrix(operator_div_res));

            auto res3 = udq1.cast2DualQuaternion() / udq2; // non-unit / unit = non-unit
            REQUIRE(is_same_v<decltype(res3), DualQuaternionf>);
            REQUIRE_THAT(res3.cast2Vector(), EqualsMatrix(operator_div_res));

            auto res5 = udq1 / 2.f; // unit / scalar = non-unit
            REQUIRE(is_same_v<decltype(res5), DualQuaternionf>);
            REQUIRE_THAT(res5.cast2Vector(), EqualsMatrix(udq1.cast2Vector() / 2.f));

            DualQuaternionf qd11 = udq1.cast2DualQuaternion();
            qd11 /= udq2;
            REQUIRE_THAT(qd11.cast2Vector(), EqualsMatrix((udq1 / udq2).cast2Vector()));

            // alias for operator/ for readability

            auto res11 = udq1.dualQuatDiv(udq2);
            REQUIRE(is_same_v<decltype(res11), UnitDualQuaternionf>);
            REQUIRE_THAT(res11.cast2Vector(), EqualsMatrix(operator_div_res));

            auto res22 = udq1.dualQuatDiv(udq2.cast2DualQuaternion()); // unit / unit = unit;
            REQUIRE(is_same_v<decltype(res22), DualQuaternionf>);
            REQUIRE_THAT(res22.cast2Vector(), EqualsMatrix(operator_div_res));

            auto res333 = udq1.cast2DualQuaternion().dualQuatDiv(udq2);
            REQUIRE(is_same_v<decltype(res333), DualQuaternionf>);
            REQUIRE_THAT(res333.cast2Vector(), EqualsMatrix(operator_div_res));

            auto res33 = udq1.cast2DualQuaternion().dualQuatDiv(udq2);
            REQUIRE(is_same_v<decltype(res33), DualQuaternionf>);
            REQUIRE_THAT(res33.cast2Vector(), EqualsMatrix(operator_div_res));
        }
    }

    SECTION("translation")
    {
    }
}