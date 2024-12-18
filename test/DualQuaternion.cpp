#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

TEST_CASE("DualQuaternion", "[objects]")
{
    DualQuaternionf dq{Quaternionf{1.f, 2.f, 3.f, 4.f}, Quaternionf{5.f, 6.f, 7.f, 8.f}};

    SECTION("constructor")
    {
        DualQuaternionf dq1 = dq;
        REQUIRE_THAT(dq1, EqualsMatrix(dq));

        DualQuaternionf dq2{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f};
        REQUIRE_THAT(dq2, EqualsMatrix(dq));

        DualQuaternionf dq3{Quaternionf{1.f, 2.f, 3.f, 4.f}, Quaternionf{5.f, 6.f, 7.f, 8.f}};
        REQUIRE_THAT(dq3, EqualsMatrix(dq));

        DualQuaternionf dq4 = (Vectorf<8>{{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f}}).cast2DualQuaternion();
        REQUIRE_THAT(dq4, EqualsMatrix(dq));
    }

    SECTION("accessors")
    {
        DualQuaternionf dq1 = dq;
        REQUIRE(close_enough(dq1.Re().w(), 1.f));
        REQUIRE(close_enough(dq1.Re().x(), 2.f));
        REQUIRE(close_enough(dq1.Re().y(), 3.f));
        REQUIRE(close_enough(dq1.Re().z(), 4.f));
        REQUIRE(close_enough(dq1.Du().w(), 5.f));
        REQUIRE(close_enough(dq1.Du().x(), 6.f));
        REQUIRE(close_enough(dq1.Du().y(), 7.f));
        REQUIRE(close_enough(dq1.Du().z(), 8.f));

        dq1.Re().w() = 11.f;
        dq1.Re().x() = 12.f;
        dq1.Re().y() = 13.f;
        dq1.Re().z() = 14.f;
        dq1.Du().w() = 15.f;
        dq1.Du().x() = 16.f;
        dq1.Du().y() = 17.f;
        dq1.Du().z() = 18.f;

        REQUIRE(close_enough(dq1.rw(), 11.f));
        REQUIRE(close_enough(dq1.rx(), 12.f));
        REQUIRE(close_enough(dq1.ry(), 13.f));
        REQUIRE(close_enough(dq1.rz(), 14.f));
        REQUIRE(close_enough(dq1.dw(), 15.f));
        REQUIRE(close_enough(dq1.dx(), 16.f));
        REQUIRE(close_enough(dq1.dy(), 17.f));
        REQUIRE(close_enough(dq1.dz(), 18.f));
    }

    SECTION("operators")
    {
        DualQuaternionf dq1 = dq;
        DualQuaternionf dq2{11.f, 12.f, 13.f, 14.f, 15.f, 16.f, 17.f, 18.f};
        { // operator +
            auto res1 = dq1 + dq2;
            REQUIRE(is_same_v<decltype(res1), DualQuaternionf>);
            REQUIRE_THAT(res1, EqualsMatrix(DualQuaternionf{12.f, 14.f, 16.f, 18.f, 20.f, 22.f, 24.f, 26.f}));

            auto res2 = dq1;
            res2 += dq2;
            REQUIRE_THAT(res2, EqualsMatrix(DualQuaternionf{12.f, 14.f, 16.f, 18.f, 20.f, 22.f, 24.f, 26.f}));
        }

        { // operator -
            auto res1 = dq1 - dq2;
            REQUIRE(is_same_v<decltype(res1), DualQuaternionf>);
            REQUIRE_THAT(res1, EqualsMatrix(DualQuaternionf{-10.f, -10.f, -10.f, -10.f, -10.f, -10.f, -10.f, -10.f}));

            auto res2 = dq1;
            res2 -= dq2;
            REQUIRE_THAT(res2, EqualsMatrix(DualQuaternionf{-10.f, -10.f, -10.f, -10.f, -10.f, -10.f, -10.f, -10.f}));
        }

        { // operator *
            auto res1 = dq1 * dq2;
            REQUIRE(is_same_v<decltype(res1), DualQuaternionf>);
            REQUIRE_THAT(res1, EqualsMatrix(DualQuaternionf{-108.f, 24.f, 66.f, 48.f, -360.f, 152.f, 244.f, 216.f}));

            auto res2 = dq1;
            res2 *= dq2;
            REQUIRE_THAT(res2, EqualsMatrix(DualQuaternionf{-108.f, 24.f, 66.f, 48.f, -360.f, 152.f, 244.f, 216.f}));

            auto res3 = dq1.dualQuatMul(dq2);
            REQUIRE(is_same_v<decltype(res3), DualQuaternionf>);
            REQUIRE_THAT(res3, EqualsMatrix(DualQuaternionf{-108.f, 24.f, 66.f, 48.f, -360.f, 152.f, 244.f, 216.f}));

            auto res4 = dq1;
            res4.dualQuatMulEq(dq2);
            REQUIRE_THAT(res4, EqualsMatrix(DualQuaternionf{-108.f, 24.f, 66.f, 48.f, -360.f, 152.f, 244.f, 216.f}));
        }

        { // operator /
            auto res1 = dq1 / dq2;
            REQUIRE(is_same_v<decltype(res1), DualQuaternionf>);
            REQUIRE_THAT(res1 * dq2, EqualsMatrix(dq1));

            auto res2 = dq1;
            res2 /= dq2;
            REQUIRE_THAT(res2 * dq2, EqualsMatrix(dq1));

            auto res3 = dq1.dualQuatDiv(dq2);
            REQUIRE(is_same_v<decltype(res3), DualQuaternionf>);
            REQUIRE_THAT(res3 * dq2, EqualsMatrix(dq1));

            auto res4 = dq1;
            res4.dualQuatDivEq(dq2);
            REQUIRE_THAT(res4 * dq2, EqualsMatrix(dq1));
        }
    }

    SECTION("utils")
    {
        DualQuaternionf dq1 = dq;
        DualQuaternionf dq1_prim = dq1.conjugatedPrimary();
        DualQuaternionf dq1_prim_ans{1.f, -2.f, -3.f, -4.f, 5.f, -6.f, -7.f, -8.f};
        REQUIRE_THAT(dq1_prim, EqualsMatrix(dq1_prim_ans));

        DualQuaternionf dq11 = dq;
        dq11.conjugatePrimary();
        REQUIRE_THAT(dq11, EqualsMatrix(dq1_prim_ans));

        DualQuaternionf dq2 = dq;
        DualQuaternionf dq2_dual = dq2.conjugatedDual();
        DualQuaternionf dq2_dual_ans{1.f, 2.f, 3.f, 4.f, -5.f, -6.f, -7.f, -8.f};
        REQUIRE_THAT(dq2_dual, EqualsMatrix(dq2_dual_ans));

        DualQuaternionf dq22 = dq;
        dq22.conjugateDual();
        REQUIRE_THAT(dq22, EqualsMatrix(dq2_dual_ans));

        DualQuaternionf dq3 = dq;
        DualQuaternionf dq3_full = dq3.conjugatedFull();
        DualQuaternionf dq3_full_ans{1.f, -2.f, -3.f, -4.f, -5.f, 6.f, 7.f, 8.f};
        REQUIRE_THAT(dq3_full, EqualsMatrix(dq3_full_ans));

        DualQuaternionf dq33 = dq;
        dq33.conjugateFull();
        REQUIRE_THAT(dq33, EqualsMatrix(dq3_full_ans));

        DualQuaternionf dq4 = dq;
        DualQuaternionf dq4_norm = dq4.normalized();
        DualQuaternionf dq4_norm_real_norm = dq4_norm * dq4_norm.conjugatedPrimary();
        REQUIRE_THAT(dq4_norm_real_norm, EqualsMatrix(DualQuaternionf{1.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f}));
    }

    SECTION("static functions")
    {
        DualQuaternionf dq2 = DualQuaternionf::zeros();
        REQUIRE_THAT(dq2, EqualsMatrix(DualQuaternionf{0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f}));
    }
    SECTION("casts")
    {
        SquareMatrixf<8> m = dq.toMulMatrix();
        DualQuaternionf dq2{11.f, 12.f, 13.f, 14.f, 15.f, 16.f, 17.f, 18.f};
        Vectorf<8> v = m * dq2.cast2Vector();
        DualQuaternionf dqdq2 = dq * dq2;
        REQUIRE_THAT(v.cast2DualQuaternion(), EqualsMatrix(dqdq2));

        SquareMatrixf<8> dq2_right = dq2.toRightMulMatrix();
        Vectorf<8> v2 = dq2_right * dq;
        REQUIRE_THAT(v2.cast2DualQuaternion(), EqualsMatrix(dqdq2));
    }
}