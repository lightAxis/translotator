#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

TEST_CASE("Quaternion", "[objects]")
{
    Quaternionf q1{1.0f, 2.0f, 3.0f, 4.0f};  // quaternion specific initializer (w,x,y,z)
    Quaternionf q1_{{1.0f, 2.0f, 3.f, 4.f}}; // matrix form initializer ([0],[1],[2],[3])

    SECTION("constructos")
    {
        Quaternionf q2{};
        Quaternionf q2_{{0.f, 0.f, 0.f, 0.f}};
        REQUIRE_THAT(q2, EqualsMatrix(q2_));

        Quaternionf q3;
        Quaternionf q3_{0.0f, 0.f, 0.f, 0.f};
        REQUIRE_THAT(q3, EqualsMatrix(q3_));

        Vectorf<3> v{{1.0f, 2.0f, 3.0f}};
        Quaternionf q4{0.0f, v};
        Quaternionf q4_{0.0f, 1.0f, 2.0f, 3.0f};
        REQUIRE_THAT(q4, EqualsMatrix(q4_));
    }

    SECTION("accessors")
    {
        Quaternion q2 = q1;
        REQUIRE(q2.w() == 1.0f);
        REQUIRE(q2.x() == 2.0f);
        REQUIRE(q2.y() == 3.0f);
        REQUIRE(q2.z() == 4.0f);
        REQUIRE(close_enough(q2.Re(), 1.0f));
        REQUIRE_THAT(q2.Im(), EqualsMatrix(Vectorf<3>{{2.0f, 3.0f, 4.0f}}));

        q2.w() = 11.f;
        q2.x() = 12.f;
        q2.y() = 13.f;
        q2.z() = 14.f;
        REQUIRE(q2.w() == 11.0f);
        REQUIRE(q2.x() == 12.0f);
        REQUIRE(q2.y() == 13.0f);
        REQUIRE(q2.z() == 14.0f);
        REQUIRE(close_enough(q2.Re(), 11.0f));
        REQUIRE_THAT(q2.Im(), EqualsMatrix(Vectorf<3>{{12.0f, 13.0f, 14.0f}}));

        q2.Re() = 21.f;
        REQUIRE(close_enough(q2.Re(), 21.0f));

        q2.Im() = Vectorf<3>{{22.0f, 23.0f, 24.0f}};
        REQUIRE(q2.w() == 21.0f);
        REQUIRE(q2.x() == 22.0f);
        REQUIRE(q2.y() == 23.0f);
        REQUIRE(q2.z() == 24.0f);
        REQUIRE_THAT(q2.Im(), EqualsMatrix(Vectorf<3>{{22.0f, 23.0f, 24.0f}}));
    }

    SECTION("casting")
    {
        SquareMatrixf<4> q1_mulmat = q1.toMulMatrix();
        SquareMatrixf<4> q1_mulmat_{{1.0f, -2.0f, -3.0f, -4.0f,
                                     2.0f, 1.0f, -4.0f, 3.0f,
                                     3.0f, 4.0f, 1.0f, -2.0f,
                                     4.0f, -3.0f, 2.0f, 1.0f}};
        REQUIRE_THAT(q1_mulmat, EqualsMatrix(q1_mulmat_));
    }

    SECTION("operators")
    {
        // Quternion Multiplication
        Quaternionf q2{1.0f, 2.0f, 3.0f, 4.0f};
        Quaternionf q3{5.0f, 6.0f, 7.0f, 8.0f};

        Quaternionf q23 = q2 * q3;
        Quaternionf q23_{-60.0f, 12.0f, 30.0f, 24.0f};
        REQUIRE_THAT(q23, EqualsMatrix(q23_));
        Quaternionf q32 = q3 * q2;
        Quaternionf q32_{-60.0f, 20.0f, 14.0f, 32.0f};
        REQUIRE_THAT(q32, EqualsMatrix(q32_));

        Quaternionf q4 = q2 * 2.f;
        Quaternionf q4_{2.0f, 4.0f, 6.0f, 8.0f};
        REQUIRE_THAT(q4, EqualsMatrix(q4_));

        Quaternionf q5 = q2 / 2.f;
        Quaternionf q5_{0.5f, 1.0f, 1.5f, 2.0f};
        REQUIRE_THAT(q5, EqualsMatrix(q5_));

        Quaternionf q6 = q2 * q2.inversed();
        Quaternionf q6_{1.0f, 0.0f, 0.0f, 0.0f};
        REQUIRE_THAT(q6, EqualsMatrix(q6_));

        Quaternion q7 = q2.inversed() * q2;
        Quaternion q7_{1.0f, 0.0f, 0.0f, 0.0f};
        REQUIRE_THAT(q7, EqualsMatrix(q7_));

        Quaternion q8 = q2;
        Quaternion q9{5.f, 6.f, 7.f, 8.f};
        Quaternion q89 = q8 / q9;
        Quaternion q899 = q89 * q9;
        REQUIRE_THAT(q899, EqualsMatrix(q8));
    }

    SECTION("utils")
    {
        const float norm = q1.norm();
        const float norm_squared = q1.normSquared();
        REQUIRE(close_enough(norm, 5.4772255750516611345696978280085f));
        REQUIRE(close_enough(norm_squared, 30.0f));

        Quaternionf q2 = q1.conjugated();
        Quaternionf q2_{1.0f, -2.0f, -3.0f, -4.0f};
        REQUIRE_THAT(q2, EqualsMatrix(q2_));

        Quaternionf q22 = q1;
        q22.conjugate();
        REQUIRE_THAT(q22, EqualsMatrix(q2_));

        Quaternionf q3 = q1.inversed();
        const float q1_normSq = q1.normSquared();
        Quaternionf q3_{1.0f / q1_normSq, -2.0f / q1_normSq, -3.0f / q1_normSq, -4.0f / q1_normSq};
        REQUIRE_THAT(q3, EqualsMatrix(q3_));

        Quaternionf q4 = q1.normalized();
        const float q1_norm = q1.norm();
        Quaternionf q4_{1.0f / q1_norm, 2.0f / q1_norm, 3.0f / q1_norm, 4.0f / q1_norm};
        REQUIRE_THAT(q4, EqualsMatrix(q4_));

        Quaternionf q5 = q1;
        q5.normalize();
        REQUIRE_THAT(q5, EqualsMatrix(q4_));

        Quaternionf q6 = q1.canonicalized();
        Quaternionf q6_{1.0f, 2.0f, 3.0f, 4.0f};
        REQUIRE_THAT(q6, EqualsMatrix(q6_));

        Quaternionf q7{-1.0f, 2.0f, 3.0f, 4.0f};
        q7.canonicalize();
        Quaternionf q7_{1.0f, -2.0f, -3.0f, -4.0f};
        REQUIRE_THAT(q7, EqualsMatrix(q7_));
    }

    SECTION("rotation")
    {
        Vectorf<3> v{{1.0f, 2.0f, 3.0f}};
        v.normalize();
        const float angle = 1.0f;
        Quaternionf q2{translotator::cos(angle / 2.0f), translotator::sin(angle / 2.0f) * v};

        AxisAnglef ag2 = q2.toAxisAngle();
        REQUIRE(close_enough(ag2.getAngle(), angle));
        REQUIRE_THAT(ag2.getAxis(), EqualsMatrix(v));

        Vectorf<3> vec{{1.0f, 2.0f, 3.0f}};
        Vectorf<3> vec_rot = q2.rotateVector3D(vec);

        SquareMatrixf<3> rot_mat = q2.toRotMatrix3D();
        Vectorf<3> vec_rot_mat = rot_mat * vec;

        REQUIRE_THAT(vec_rot, EqualsMatrix(vec_rot_mat));
    }
}