
#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

// TODO : Implement test cases for EulerAngle

TEST_CASE("EulerAngle", "[objects]")
{
    Vectorf<3> testvec{{1.f, 2.f, 3.f}};
    Vectorf<2> testvec2{{1.f, 2.f}};

    // test1
    EulerAngle<float, EULER_ORDER::XYZ> euler1{0.1f, 0.2f, 0.3f};
    SO3Groupf so31_ans{{+0.9362934f, -0.2896295f, +0.1986693f,
                        +0.3129918f, +0.9447025f, -0.0978434f,
                        -0.1593451f, +0.1537920f, +0.9751703f}};
    AxisAnglef axis1_ans{0.3815648f, Vectorf<3>{{0.3378807f, 0.4807199f, 0.8091632f}}};
    Vectorf<3> angvec1_ans{{0.1289234f, 0.1834258f, 0.3087482f}};
    UnitQuaternionf quat1_ans{0.9818562f, Vectorf<3>{{0.0640713f, 0.0911575f, 0.1534393f}}};
    Vectorf<3> testvec_rot1_ans{{0.95304234f, 1.90886658f, 3.07374994f}};

    // test2
    EulerAngle<float, EULER_ORDER::XYZ> euler2d{0, 0, 1.f};
    SO2Groupf so22_ans{{0.5403023f, -0.8414710f,
                        0.8414710f, +0.5403023f}};
    SO3Groupf so32_ans{{0.5403023f, -0.8414710f, 0.0000000f,
                        0.8414710f, +0.5403023f, 0.0000000f,
                        0.0000000f, +0.0000000f, 1.0000000f}};
    AxisAnglef axis2_ans{1.f, Vectorf<3>{{0.f, 0.f, 1.f}}};
    Vectorf<3> angvec2_ans{{0.f, 0.f, 1.f}};
    UnitComplexNumf cplx2_ans{0.5403023f, 0.8414710f};
    UnitQuaternionf quat2_ans{0.8775826f, Vectorf<3>{{0.f, 0.f, 0.4794255f}}};
    Vectorf<2> testvec2_rot2_ans{{-1.14263966f, 1.9220756f}};

    SECTION("constructor")
    {
        // euler is not a matrix based object
        REQUIRE(is_matrix_base_v<decltype(euler1)> == false);

        EulerAngleXYZf euler2{};
        REQUIRE_THAT(euler2, EqualsMatrix(EulerAngleXYZf{0, 0, 0}));

        EulerAngleXYZf euler3{0.1f};
        REQUIRE_THAT(euler3, EqualsMatrix(EulerAngleXYZf{0, 0, 0.1f}));

        EulerAngleXYZf euler4{0.1f, 0.2f, 0.3f};
        REQUIRE_THAT(euler4.toVector(), EqualsMatrix(Vectorf<3>{{0.1f, 0.2f, 0.3f}}));

        EulerAngleXYZf euler5{Vectorf<3>{{0.1f, 0.2f, 0.3f}}};
        REQUIRE_THAT(euler5.toVector(), EqualsMatrix(Vectorf<3>{{0.1f, 0.2f, 0.3f}}));
    }

    SECTION("accessor")
    {
        EulerAngleXYZf euler2 = euler1;
        REQUIRE(close_enough(euler2.x(), 0.1f));
        REQUIRE(close_enough(euler2.y(), 0.2f));
        REQUIRE(close_enough(euler2.z(), 0.3f));

        REQUIRE(close_enough(euler2[0], 0.1f));
        REQUIRE(close_enough(euler2[1], 0.2f));
        REQUIRE(close_enough(euler2[2], 0.3f));

        REQUIRE(close_enough(euler2.roll(), 0.1f));
        REQUIRE(close_enough(euler2.pitch(), 0.2f));
        REQUIRE(close_enough(euler2.yaw(), 0.3f));

        REQUIRE(close_enough(euler2.getAngleInOrder<0>(), 0.1f));
        REQUIRE(close_enough(euler2.getAngleInOrder<1>(), 0.2f));
        REQUIRE(close_enough(euler2.getAngleInOrder<2>(), 0.3f));

        euler2.x() = 1.1f;
        euler2.y() = 1.2f;
        euler2.z() = 1.3f;
        REQUIRE(close_enough(euler2.x(), 1.1f));
        REQUIRE(close_enough(euler2.y(), 1.2f));
        REQUIRE(close_enough(euler2.z(), 1.3f));

        euler2[0] = 2.1f;
        euler2[1] = 2.2f;
        euler2[2] = 2.3f;
        REQUIRE(close_enough(euler2[0], 2.1f));
        REQUIRE(close_enough(euler2[1], 2.2f));
        REQUIRE(close_enough(euler2[2], 2.3f));

        euler2.roll() = 3.1f;
        euler2.pitch() = 3.2f;
        euler2.yaw() = 3.3f;
        REQUIRE(close_enough(euler2.roll(), 3.1f));
        REQUIRE(close_enough(euler2.pitch(), 3.2f));
        REQUIRE(close_enough(euler2.yaw(), 3.3f));

        euler2.getAngleInOrder<0>() = 4.1f;
        euler2.getAngleInOrder<1>() = 4.2f;
        euler2.getAngleInOrder<2>() = 4.3f;
        REQUIRE(close_enough(euler2.x(), 4.1f));
        REQUIRE(close_enough(euler2.y(), 4.2f));
        REQUIRE(close_enough(euler2.z(), 4.3f));

        REQUIRE(euler2.getAxisInOrder<0>() == AXIS::X);
        REQUIRE(euler2.getAxisInOrder<1>() == AXIS::Y);
        REQUIRE(euler2.getAxisInOrder<2>() == AXIS::Z);

        EulerAngleZYXf euler3{0.1f, 0.2f, 0.3f};
        REQUIRE(close_enough(euler3.x(), 0.1f));
        REQUIRE(close_enough(euler3.y(), 0.2f));
        REQUIRE(close_enough(euler3.z(), 0.3f));

        REQUIRE(close_enough(euler3[0], 0.1f));
        REQUIRE(close_enough(euler3[1], 0.2f));
        REQUIRE(close_enough(euler3[2], 0.3f));

        REQUIRE(close_enough(euler3.roll(), 0.1f));
        REQUIRE(close_enough(euler3.pitch(), 0.2f));
        REQUIRE(close_enough(euler3.yaw(), 0.3f));

        REQUIRE(close_enough(euler3.getAngleInOrder<0>(), 0.3f));
        REQUIRE(close_enough(euler3.getAngleInOrder<1>(), 0.2f));
        REQUIRE(close_enough(euler3.getAngleInOrder<2>(), 0.1f));

        euler3.x() = 1.1f;
        euler3.y() = 1.2f;
        euler3.z() = 1.3f;
        REQUIRE(close_enough(euler3.getAngleInOrder<0>(), 1.3f));
        REQUIRE(close_enough(euler3.getAngleInOrder<1>(), 1.2f));
        REQUIRE(close_enough(euler3.getAngleInOrder<2>(), 1.1f));

        REQUIRE(euler3.getAxisInOrder<0>() == AXIS::Z);
        REQUIRE(euler3.getAxisInOrder<1>() == AXIS::Y);
        REQUIRE(euler3.getAxisInOrder<2>() == AXIS::X);
    }

    SECTION("utils")
    {
        Vectorf<3> vec1 = testvec;
        Vectorf<3> vec1_rot = euler1.rotateVec3D(vec1);
        Vectorf<3> vec1_rot_ans = testvec_rot1_ans;
        REQUIRE_THAT(vec1_rot, EqualsMatrix(vec1_rot_ans));

        Vectorf<2> vec2 = testvec2;
        Vectorf<2> vec2_rot = euler2d.rotateVec2D(vec2);
        Vectorf<2> vec2_rot_ans = testvec2_rot2_ans;
        REQUIRE_THAT(vec2_rot, EqualsMatrix(vec2_rot_ans));
    }

    SECTION("static functions")
    {
        EulerAngleXYZf res1 = EulerAngleXYZf::axisRotation<AXIS::X>(0.1f);
        REQUIRE_THAT(res1, EqualsMatrix(EulerAngleXYZf{0.1f, 0.f, 0.f}));

        EulerAngleXYZf res2 = EulerAngleXYZf::axisRotation<AXIS::Y>(0.2f);
        REQUIRE_THAT(res2, EqualsMatrix(EulerAngleXYZf{0.f, 0.2f, 0.f}));

        EulerAngleXYZf res3 = EulerAngleXYZf::axisRotation<AXIS::Z>(0.3f);
        REQUIRE_THAT(res3, EqualsMatrix(EulerAngleXYZf{0.f, 0.f, 0.3f}));
    }

    SECTION("casts")
    {
        { // 3d euler
            auto so31 = euler1.toSO3Group();
            auto axisangle1 = euler1.toAxisAngle();
            auto angvec1 = euler1.toAxisAngle().toAngleVector();
            auto quat1 = euler1.toUnitQuaternion();

            REQUIRE_THAT(so31, EqualsMatrix(so31_ans));
            REQUIRE_THAT(axisangle1, EqualsMatrix(axis1_ans));
            REQUIRE_THAT(angvec1, EqualsMatrix(angvec1_ans));
            REQUIRE_THAT(quat1, EqualsMatrix(quat1_ans));

            auto so31_reversed = so31.toEulerAngle<EULER_ORDER::XYZ>();
            auto axisangle1_reversed = axisangle1.toEulerAngle3D<EULER_ORDER::XYZ>();
            auto angvec1_reversed = AxisAnglef{angvec1}.toEulerAngle3D<EULER_ORDER::XYZ>();
            auto quat1_reversed = quat1.toEulerAngle3D<EULER_ORDER::XYZ>();

            REQUIRE_THAT(so31_reversed, EqualsMatrix(euler1));
            REQUIRE_THAT(axisangle1_reversed, EqualsMatrix(euler1));
            REQUIRE_THAT(angvec1_reversed, EqualsMatrix(euler1));
            REQUIRE_THAT(quat1_reversed, EqualsMatrix(euler1));
        }

        { // 2d euler
            auto so22 = euler2d.toSO2Group();
            auto so32 = euler2d.toSO3Group();
            auto axisangle2 = euler2d.toAxisAngle();
            auto angvec2 = euler2d.toAxisAngle().toAngleVector();
            auto cplx2 = euler2d.toUnitComplexNum();
            auto quat2 = euler2d.toUnitQuaternion();

            REQUIRE_THAT(so22, EqualsMatrix(so22_ans));
            REQUIRE_THAT(so32, EqualsMatrix(so32_ans));
            REQUIRE_THAT(axisangle2, EqualsMatrix(axis2_ans));
            REQUIRE_THAT(angvec2, EqualsMatrix(angvec2_ans));
            REQUIRE_THAT(cplx2, EqualsMatrix(cplx2_ans));
            REQUIRE_THAT(quat2, EqualsMatrix(quat2_ans));

            auto so31_reversed = so22.toEulerAngle<EULER_ORDER::XYZ>();
            auto so32_reversed = so32.toEulerAngle<EULER_ORDER::XYZ>();
            auto axisangle2_reversed = axisangle2.toEulerAngle3D<EULER_ORDER::XYZ>();
            auto angvec2_reversed = AxisAnglef{angvec2}.toEulerAngle3D<EULER_ORDER::XYZ>();
            auto cplx2_reversed = cplx2.toEulerAngle2D<EULER_ORDER::XYZ>();
            auto quat2_reversed = quat2.toEulerAngle3D<EULER_ORDER::XYZ>();

            REQUIRE_THAT(so31_reversed, EqualsMatrix(euler2d));
            REQUIRE_THAT(so32_reversed, EqualsMatrix(euler2d));
            REQUIRE_THAT(axisangle2_reversed, EqualsMatrix(euler2d));
            REQUIRE_THAT(angvec2_reversed, EqualsMatrix(euler2d));
            REQUIRE_THAT(cplx2_reversed, EqualsMatrix(euler2d));
            REQUIRE_THAT(quat2_reversed, EqualsMatrix(euler2d));
        }
    }
}