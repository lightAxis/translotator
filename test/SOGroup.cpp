#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

TEST_CASE("SOGroup", "[objects]")
{
    Vectorf<2> vec2{{1.0f, 2.0f}};
    Vectorf<3> vec3{{1.0f, 2.0f, 3.0f}};

    // test1 //(0,0,1) * 1 angle and vector
    SOGroupf<2> so2_{{+0.5403023f, -0.8414710f,
                      +0.8414710f, +0.5403023f}};
    UnitComplexNumf so2_uc{0.5403023f, 0.8414710f};
    UnitQuaternionf so2_uq{0.8775826f, Vectorf<3>{{0.f, 0.f, 0.4794225f}}};
    Vectorf<2> vec2_rot = so2_uc.rotateVector2D(vec2);

    // test2 //(0.8122105f, -0.2217897f, 0.5395585f), 3.8971816f angle and vector
    SOGroupf<3> so3_{{+0.4119822f, +0.0587266f, +0.9092974f,
                      -0.6812427f, -0.6428728f, +0.3501755f,
                      +0.6051273f, -0.7637183f, -0.2248451f}};
    UnitQuaternionf so3_q{-0.3688714f, Vectorf<3>{{0.7549338f, -0.2061492f, 0.5015091f}}};
    Vectorf<3> vec3_rot = so3_q.rotateVector3D(vec3);

    // test3 // [ 0.2672612, 0.5345225, 0.8017837 ], 1 angle and vector
    SOGroupf<3> so33_{{+0.5731379f, -0.6090066f, +0.5482918f,
                       +0.7403488f, +0.6716445f, -0.0278793f,
                       -0.3512785f, +0.4219059f, +0.8358222f}};
    UnitQuaternionf so33_q{0.8775826f, Vectorf<3>{{0.1281319f, 0.2562637f, 0.3843956f}}};
    Vectorf<3> vec33_rot = so33_q.rotateVector3D(vec3);

    SECTION("constructors")
    {
        Vectorf<2> vecinit_1{{1.f, 2.f}};
        Vectorf<2> vecinit_2{{3.f, 4.f}};

        SOGroupf<2> so2_initcol{vecinit_1, vecinit_2, true};
        SOGroupf<2> so2_initcol_{{1.f, 3.f,
                                  2.f, 4.f}};
        REQUIRE_THAT(so2_initcol, EqualsMatrix(so2_initcol_));

        SOGroupf<2> so2_initrow(vecinit_1, vecinit_2, false);
        SOGroupf<2> so2_initrow_{{1.f, 2.f,
                                  3.f, 4.f}};
        REQUIRE_THAT(so2_initrow, EqualsMatrix(so2_initrow_));

        SOGroupf<2> so2_inittheta{1.f};
        REQUIRE_THAT(so2_inittheta, EqualsMatrix(so2_));

        Vectorf<3> vecinit_11{{1.f, 2.f, 3.f}};
        Vectorf<3> vecinit_12{{4.f, 5.f, 6.f}};
        Vectorf<3> vecinit_13{{7.f, 8.f, 9.f}};

        SOGroupf<3> so3_initcol{vecinit_11, vecinit_12, vecinit_13, true};
        SOGroupf<3> so3_initcol_{{1.f, 4.f, 7.f,
                                  2.f, 5.f, 8.f,
                                  3.f, 6.f, 9.f}};
        REQUIRE_THAT(so3_initcol, EqualsMatrix(so3_initcol_));

        SOGroupf<3> so3_initrow(vecinit_11, vecinit_12, vecinit_13, false);
        SOGroupf<3> so3_initrow_{{1.f, 2.f, 3.f,
                                  4.f, 5.f, 6.f,
                                  7.f, 8.f, 9.f}};
        REQUIRE_THAT(so3_initrow, EqualsMatrix(so3_initrow_));

        SOGroupf<3> so3_initanglevector{Vectorf<3>{{0.8122105f, -0.2217897f, 0.5395585f}} * 3.8971816f};
        REQUIRE_THAT(so3_initanglevector, EqualsMatrix(so3_));
    }

    SECTION("operators")
    {
        auto so3_sq = so3_.cast2SquareMatrix();
        auto so33_sq = so33_.cast2SquareMatrix();

        { // operator +
            SquareMatrixf<3> operator_plus_res = (so3_sq + so33_sq);
            auto res1 = so3_ + so33_; // so3 + so3 = sq
            REQUIRE(is_same_v<decltype(res1), SquareMatrixf<3>>);
            REQUIRE_THAT(res1, EqualsMatrix(operator_plus_res));

            auto res2 = so3_ + so33_.cast2SquareMatrix(); // so3 + sq = sq
            REQUIRE(is_same_v<decltype(res2), SquareMatrixf<3>>);
            REQUIRE_THAT(res2, EqualsMatrix(operator_plus_res));

            auto res3 = so3_.cast2SquareMatrix() + so33_; // sq + so3 = sq
            REQUIRE(is_same_v<decltype(res3), SquareMatrixf<3>>);
            REQUIRE_THAT(res3, EqualsMatrix(operator_plus_res));

            auto res4 = so3_.cast2Matrix() + so33_; // other + so3 = other
            REQUIRE(is_same_v<decltype(res4), Matrixf<3, 3>>);
            REQUIRE_THAT(res4, EqualsMatrix(operator_plus_res.cast2MatrixRef()));

            auto res5 = so3_ + so33_.cast2Matrix(); // so3 + other = sq
            REQUIRE(is_same_v<decltype(res5), SquareMatrixf<3>>);
            REQUIRE_THAT(res5, EqualsMatrix(operator_plus_res));
        }

        { // operator -
            SquareMatrixf<3> operator_minus_res = (so3_sq - so33_sq);
            auto res1 = so3_ - so33_; // so3 - so3 = sq
            REQUIRE(is_same_v<decltype(res1), SquareMatrixf<3>>);
            REQUIRE_THAT(res1, EqualsMatrix(operator_minus_res));

            auto res2 = so3_ - so33_.cast2SquareMatrix(); // so3 - sq = sq
            REQUIRE(is_same_v<decltype(res2), SquareMatrixf<3>>);
            REQUIRE_THAT(res2, EqualsMatrix(operator_minus_res));

            auto res3 = so3_.cast2SquareMatrix() - so33_; // sq - so3 = sq
            REQUIRE(is_same_v<decltype(res3), SquareMatrixf<3>>);
            REQUIRE_THAT(res3, EqualsMatrix(operator_minus_res));

            auto res4 = so3_.cast2Matrix() - so33_; // other - so3 = other
            REQUIRE(is_same_v<decltype(res4), Matrixf<3, 3>>);
            REQUIRE_THAT(res4, EqualsMatrix(operator_minus_res.cast2MatrixRef()));

            auto res5 = so3_ - so33_.cast2Matrix(); // so3 - other = sq
            REQUIRE(is_same_v<decltype(res5), SquareMatrixf<3>>);
            REQUIRE_THAT(res5, EqualsMatrix(operator_minus_res));
        }

        { // operator *
            SquareMatrixf<3> operator_mul_res = (so3_sq * so33_sq);
            auto res1 = so3_ * so33_; // so3 * so3 = so3
            REQUIRE(is_same_v<decltype(res1), SOGroupf<3>>);
            REQUIRE_THAT(res1, EqualsMatrix(operator_mul_res));

            auto res2 = so3_ * so33_.cast2SquareMatrix(); // so3 * sq = sq3;
            REQUIRE(is_same_v<decltype(res2), SquareMatrixf<3>>);
            REQUIRE_THAT(res2, EqualsMatrix(operator_mul_res));

            auto res3 = so3_.cast2SquareMatrix() * so33_; // sq * so3 = sq
            REQUIRE(is_same_v<decltype(res3), SquareMatrixf<3>>);
            REQUIRE_THAT(res3, EqualsMatrix(operator_mul_res));

            auto res4 = so3_.cast2Matrix() * so33_; // other * so3 = other
            REQUIRE(is_same_v<decltype(res4), SquareMatrixf<3>>);
            REQUIRE_THAT(res4, EqualsMatrix(operator_mul_res.cast2SquareMatrixRef()));

            auto res56_ = so3_.cast2SquareMatrixRef() * 2.0f;

            auto res5 = so3_ * 2.f; // so3 * scalar = sq
            REQUIRE(is_same_v<decltype(res5), SquareMatrixf<3>>);
            REQUIRE_THAT(res5, EqualsMatrix(res56_));

            auto res6 = 2.f * so3_; // scalar * so3 = sq
            REQUIRE(is_same_v<decltype(res6), SquareMatrixf<3>>);
            REQUIRE_THAT(res6, EqualsMatrix(res56_));

            SOGroupf<3> so3_2 = so3_;
            so3_2 *= so33_;
            REQUIRE_THAT(so3_2, EqualsMatrix(so3_ * so33_));
        }

        { // operator /

            auto so3_div_so33 = so3_ / so33_; // so3/ so3 = so3 * so3.inverse() = so3 (orthogonality preserved)
            REQUIRE(is_same_v<decltype(so3_div_so33), SOGroupf<3>>);
            REQUIRE_THAT(so3_, EqualsMatrix(so3_div_so33 * so33_));

            auto res2 = so3_ / 2.f; // so3 / scalar = sq
            SquareMatrixf<3> res2_ = so3_.cast2SquareMatrixRef() / 2.f;
            REQUIRE(is_same_v<decltype(res2), SquareMatrixf<3>>);
            REQUIRE_THAT(res2, EqualsMatrix(res2_));
        }
    }

    SECTION("utils")
    {
        SquareMatrixf<3> so3_errored = so3_.cast2SquareMatrixRef() + 0.01f * Matrixf<3, 3>::eye();
        auto so3_errored_sq = so3_errored * so3_errored.T();

        SOGroupf<3> so3_casted = so3_errored.cast2SOGroup(); // during cast, this will be normalized
        auto so3_casted_sq = so3_casted * so3_casted.T();

        REQUIRE_THAT(so3_casted_sq, EqualsMatrix(SOGroupf<3>::eye()));
    }

    SECTION("static functions")
    {
    }

    SECTION("casts")
    {
        UnitComplexNumf so2_uc_casted = so2_.toUnitComplexNum();
        REQUIRE_THAT(so2_uc_casted, EqualsMatrix(so2_uc));

        UnitQuaternionf so2_uq_casted = so2_.toUnitQuaternion();
        REQUIRE_THAT(so2_uq_casted, EqualsMatrix(so2_uq));

        AxisAnglef so2_aa_casted = so2_.toAxisAngle();
        REQUIRE_THAT(so2_aa_casted, EqualsMatrix(AxisAnglef{1.f}));

        UnitQuaternionf so3_uq_casted = so3_.toUnitQuaternion();
        REQUIRE_THAT(so3_uq_casted, EqualsMatrix(so3_q));
    }
}