#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

TEST_CASE("AxisAngle", "[objects]")
{
    AxisAnglef a(1.0f, 2.0f, 3.0f, 4.0f);

    SECTION("constructor")
    {
        REQUIRE(a.angle() == 1.0f);
        REQUIRE(a.axis().x() == 2.0f);
        REQUIRE(a.axis().y() == 3.0f);
        REQUIRE(a.axis().z() == 4.0f);

        AxisAnglef a2 = a;
        REQUIRE_THAT(a2, EqualsMatrix(a));
        AxisAnglef a3{a};
        REQUIRE_THAT(a3, EqualsMatrix(a));
        AxisAnglef a4(a);
        REQUIRE_THAT(a4, EqualsMatrix(a));

        const float angle = 1.0f;
        const Vectorf<3> axis{{2.0f, 3.0f, 4.0f}};
        const Vectorf<3> axis_normed = axis.normalized();
        AxisAnglef a5(angle, axis);
        REQUIRE_THAT(a5, EqualsMatrix(AxisAnglef(angle, axis_normed.x(), axis_normed.y(), axis_normed.z())));

        Vectorf<3> angleVector = axis_normed * angle;
        AxisAnglef a6(angleVector);
        REQUIRE(close_enough(a6.angle(), angle));
        REQUIRE_THAT(a6.axis(), EqualsMatrix(axis_normed));
        Vectorf<3> angleVectorget = a6.toAngleVector();
        REQUIRE_THAT(angleVectorget, EqualsMatrix(angleVector));
    }

    SECTION("getter setter")
    {
        REQUIRE(a.angle() == 1.0f);
        REQUIRE(a.axis().x() == 2.0f);
        REQUIRE(a.axis().y() == 3.0f);
        REQUIRE(a.axis().z() == 4.0f);
        REQUIRE_THAT(a.axis(), EqualsMatrix(Vectorf<3>{{2.0f, 3.0f, 4.0f}}));

        auto a2 = a;
        a2.angle() = 11.f;
        a2.axis().x() = 22.f;
        REQUIRE_THAT(a2, EqualsMatrix(AxisAnglef(11.f, 22.f, 3.f, 4.f)));

        a2.y() = 33.f;
        a2.z() = 44.f;
        REQUIRE_THAT(a2, EqualsMatrix(AxisAnglef(11.f, 22.f, 33.f, 44.f)));
    }

    SECTION("utils")
    {
        // site : https://www.andre-gaschler.com/rotationconverter/

        AxisAnglef a_normed = a.axisNormalized();

        Vectorf<3> v = a.axis();
        v.normalize();

        REQUIRE_THAT(a_normed.axis(), EqualsMatrix(v));
        REQUIRE(a_normed.angle() == 1.0f);
        REQUIRE_THAT(a_normed.axis(), EqualsMatrix(v));

        AxisAnglef a_inv = a.inversed();
        Vectorf<3> v_inv = Vectorf<3>{{2.f, 3.f, 4.f}}.normalized();
        REQUIRE_THAT(a_inv, EqualsMatrix(AxisAnglef(-1.0f, v_inv.x(), v_inv.y(), v_inv.z())));

        AxisAnglef a2 = a;
        a2.axisNormalize();
        AxisAnglef a2_inv = a2.inversed();
        UnitQuaternionf uq = a2.toUnitQuaternion();
        UnitQuaternionf uq_inv = a2_inv.toUnitQuaternion();
        uq.canonicalize();
        uq_inv.canonicalize();
        REQUIRE_THAT(uq, EqualsMatrix(UnitQuaternionf{0.8775826f, 0.1780542f, 0.2670813f, 0.3561084f}));

        Vectorf<3> vec{{1.f, 2.f, 3.f}};
        Vectorf<3> vec_rot = uq.rotateVector3D(vec);
        Vectorf<3> vec_rot_inv = uq_inv.rotateVector3D(vec_rot);
        REQUIRE_THAT(vec_rot_inv, EqualsMatrix(vec));

        Vectorf<3> vecrot2 = a2.rotateVector3D(vec);
        Vectorf<3> vector2_inv = a2_inv.rotateVector3D(vecrot2);
        REQUIRE_THAT(vector2_inv, EqualsMatrix(vec));

        REQUIRE_THAT(vec_rot, EqualsMatrix(vecrot2));

        Vectorf<3> vec_rot_true{{1.33062533f, 1.7191888111f, 3.0452957267f}};
        REQUIRE_THAT(vec_rot, EqualsMatrix(vec_rot_true));
    }

    SECTION("casting")
    {
        AxisAnglef a2 = a;
        AxisAngled a2d = a2.castDataType<double>();
        a2.axisNormalize();

        REQUIRE(close_enough(static_cast<double>(a2.angle()), a2d.angle()));
        REQUIRE_THAT(a2.axis().castDataType<double>(), EqualsMatrix(a2d.axis()));
    }
}