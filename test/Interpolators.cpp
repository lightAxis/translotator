#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;
using namespace translotator::interpolators;
using namespace translotator::lie;

TEST_CASE("Lerp", "[interpolators]")
{
    Matrixf<2, 3> startMat{{1.f, 2.f, 3.f,
                            4.f, 5.f, 6.f}};
    Matrixf<2, 3> endMat{{7.f, 8.f, 9.f,
                          10.f, 11.f, 12.f}};

    Vectorf<3> startVec{{1.f, 2.f, 3.f}};
    Vectorf<3> endVec{{4.f, 5.f, 6.f}};

    SquareMatrixf<3> startSqMat{{1.f, 2.f, 3.f,
                                 4.f, 5.f, 6.f,
                                 7.f, 8.f, 9.f}};
    SquareMatrixf<3> endSqMat{{10.f, 11.f, 12.f,
                               13.f, 14.f, 15.f,
                               16.f, 17.f, 18.f}};

    ComplexNumf startCplx{1.f, 2.f};
    ComplexNumf endCplx{3.f, 4.f};

    Quaternionf startQuat{1.f, 2.f, 3.f, 4.f};
    Quaternionf endQuat{5.f, 6.f, 7.f, 8.f};

    DualNumberf startDual{1.f, 2.f};
    DualNumberf endDual{3.f, 4.f};

    DualQuaternionf startDualQuat{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f};
    DualQuaternionf endDualQuat{9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f, 16.f};

    SECTION("constructor")
    {
        { // matrix
            interpolators::Lerper<Matrixf<2, 3>> lerpMat{startMat, endMat};
            REQUIRE_THAT(lerpMat.getStart(), EqualsMatrix(startMat));
            REQUIRE_THAT(lerpMat.getEnd(), EqualsMatrix(endMat));
            REQUIRE_THAT(lerpMat.getDiff(), EqualsMatrix(endMat - startMat));

            auto lerped = lerpMat(0.5f);
            REQUIRE(is_same_v<decltype(lerped), Matrixf<2, 3>>);
            REQUIRE_THAT(lerped, EqualsMatrix(Matrixf<2, 3>{{4.f, 5.f, 6.f,
                                                             7.f, 8.f, 9.f}}));
            REQUIRE_THAT(lerpMat(0.f), EqualsMatrix(startMat));
            REQUIRE_THAT(lerpMat(1.f), EqualsMatrix(endMat));
        }

        {
            interpolators::Lerper<Vectorf<3>> lerpVec{startVec, endVec};
            auto lerped = lerpVec(0.5f);
            REQUIRE(is_same_v<decltype(lerped), Vectorf<3>>);
            REQUIRE_THAT(lerped, EqualsMatrix(Vectorf<3>{{2.5f, 3.5f, 4.5f}}));
        }

        {
            interpolators::Lerper<SquareMatrixf<3>> lerpSqMat{startSqMat, endSqMat};
            auto lerped = lerpSqMat(0.5f);
            REQUIRE(is_same_v<decltype(lerped), SquareMatrixf<3>>);
            REQUIRE_THAT(lerped, EqualsMatrix(SquareMatrixf<3>{{5.5f, 6.5f, 7.5f,
                                                                8.5f, 9.5f, 10.5f,
                                                                11.5f, 12.5f, 13.5f}}));
        }

        {
            interpolators::Lerper<ComplexNumf> lerpCplx{startCplx, endCplx};
            auto lerped = lerpCplx(0.5f);
            REQUIRE(is_same_v<decltype(lerped), ComplexNumf>);
            REQUIRE_THAT(lerped, EqualsMatrix(ComplexNumf{2.f, 3.f}));
        }

        {
            interpolators::Lerper<Quaternionf> lerpQuat{startQuat, endQuat};
            auto lerped = lerpQuat(0.5f);
            REQUIRE(is_same_v<decltype(lerped), Quaternionf>);
            REQUIRE_THAT(lerped, EqualsMatrix(Quaternionf{3.f, 4.f, 5.f, 6.f}));
        }

        {
            interpolators::Lerper<DualNumberf> lerpDual{startDual, endDual};
            auto lerped = lerpDual(0.5f);
            REQUIRE(is_same_v<decltype(lerped), DualNumberf>);
            REQUIRE_THAT(lerped, EqualsMatrix(DualNumberf{2.f, 3.f}));
        }

        {
            interpolators::Lerper<DualQuaternionf> lerpDualQuat{startDualQuat, endDualQuat};
            auto lerped = lerpDualQuat(0.5f);
            REQUIRE(is_same_v<decltype(lerped), DualQuaternionf>);
            REQUIRE_THAT(lerped, EqualsMatrix(DualQuaternionf{5.f, 6.f, 7.f, 8.f, 9.f, 10.f, 11.f, 12.f}));
        }
    }

    SECTION("getter setter")
    {
        interpolators::Lerper<Matrixf<2, 3>> lerpMat{startMat, endMat};
        REQUIRE_THAT(lerpMat.getStart(), EqualsMatrix(startMat));
        REQUIRE_THAT(lerpMat.getEnd(), EqualsMatrix(endMat));
        REQUIRE_THAT(lerpMat.getDiff(), EqualsMatrix(endMat - startMat));

        Matrixf<2, 3> startMat2{{11.f, 12.f, 13.f,
                                 14.f, 15.f, 16.f}};
        Matrixf<2, 3> endMat2{{17.f, 18.f, 19.f,
                               20.f, 21.f, 22.f}};

        lerpMat.setStart(startMat2);
        lerpMat.setEnd(endMat2);
        lerpMat.updateDiff();

        REQUIRE_THAT(lerpMat.getStart(), EqualsMatrix(startMat2));
        REQUIRE_THAT(lerpMat.getEnd(), EqualsMatrix(endMat2));
        REQUIRE_THAT(lerpMat.getDiff(), EqualsMatrix(endMat2 - startMat2));

        auto lerped = lerpMat(0.5f);
        REQUIRE_THAT(lerped, EqualsMatrix(Matrixf<2, 3>{{14.f, 15.f, 16.f,
                                                         17.f, 18.f, 19.f}}));
        REQUIRE_THAT(lerpMat(0.f), EqualsMatrix(startMat2));
        REQUIRE_THAT(lerpMat(1.f), EqualsMatrix(endMat2));
    }

    SECTION("static function")
    {
        interpolators::Lerper<Matrixf<2, 3>> LerpMat(startMat, endMat);
        auto lerped = LerpMat(0.5f);
        auto lerped2 = interpolators::Lerping(startMat, endMat, 0.5f);
        REQUIRE_THAT(lerped, EqualsMatrix(lerped2));
    }
}

TEST_CASE("Slerp", "[interpolators]")
{
    Vectorf<1> vec_1s{{0.1f}};
    Vectorf<1> vec_1e{{0.5f}};
    Vectorf<3> vec_3s{{0.1f, 0.2f, 0.3f}};
    Vectorf<3> vec_3e{{0.4f, 0.5f, 0.6f}};
    Vectorf<6> vec_6s{{0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f}};
    Vectorf<6> vec_6e{{0.7f, 0.8f, 0.9f, 1.0f, 1.1f, 1.2f}};

    SECTION("unit complex num")
    {
        UnitComplexNumf uc_start = LieOperator_S1f::Exp(vec_1s);
        UnitComplexNumf uc_end = LieOperator_S1f::Exp(vec_1e);

        Slerper<UnitComplexNumf> slerper(uc_start, uc_end);
        UnitComplexNumf uc_mid = slerper.interpolate(0.5f);

        Vectorf<1> vec_1mid = LieOperator_S1f::Log(uc_mid);
        Vectorf<1> vec_1mid_ans = (vec_1s + vec_1e) / 2.f;
        REQUIRE_THAT(vec_1mid, EqualsMatrix(vec_1mid_ans));
    }

    SECTION("unit quaternion")
    {
        UnitQuaternionf uq_start{vec_3s};
        UnitQuaternionf uq_end{vec_3e};

        Slerper<UnitQuaternionf> slerper(uq_start, uq_end);
        UnitQuaternionf uq_mid = slerper.interpolate(0.5f);
    }

    SECTION("SO2 group")
    {
        SOGroupf<2> so2_start = LieOperator_SOf::Exp(vec_1s);
        SOGroupf<2> so2_end = LieOperator_SOf::Exp(vec_1e);

        Slerper<SOGroupf<2>> slerper(so2_start, so2_end);
        SOGroupf<2> so2_mid = slerper.interpolate(0.5f);
    }

    SECTION("SO3 group")
    {

        SOGroupf<3> so3_start = LieOperator_SOf::Exp(vec_3s);
        SOGroupf<3> so3_end = LieOperator_SOf::Exp(vec_3e);

        Slerper<SOGroupf<3>> slerper(so3_start, so3_end);
        SOGroupf<3> so3_mid = slerper.interpolate(0.5f);
    }
}

TEST_CASE("ScLerp", "[interpolators]")
{
    Vectorf<3> vec_3s{{0.1f, 0.2f, 0.3f}};
    Vectorf<3> vec_3e{{0.4f, 0.5f, 0.6f}};
    Vectorf<6> vec_6s{{0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f}};
    Vectorf<6> vec_6e{{0.7f, 0.8f, 0.9f, 1.0f, 1.1f, 1.2f}};

    SECTION("SE2 Group")
    {
        SEGroupf<2> se2_start = LieOperator_SEf::Exp(vec_3s);
        SEGroupf<2> se2_end = LieOperator_SEf::Exp(vec_3s);

        ScLerper<SEGroupf<2>> sclerper(se2_start, se2_end);
        SEGroupf<2> se2_mid = sclerper.interpolate(0.5f);
    }

    SECTION("SE3 Group")
    {
        SEGroupf<3> se3_start = LieOperator_SEf::Exp(vec_6s);
        SEGroupf<3> se3_end = LieOperator_SEf::Exp(vec_6e);

        ScLerper<SEGroupf<3>> sclerper(se3_start, se3_end);
        SEGroupf<3> se3_mid = sclerper.interpolate(0.5f);
    }
}

TEST_CASE("Slerp x Lerp", "[interpolators]")
{
    Vectorf<3> vec_3s{{0.1f, 0.2f, 0.3f}};
    Vectorf<3> vec_3e{{0.4f, 0.5f, 0.6f}};
    Vectorf<6> vec_6s{{0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f}};
    Vectorf<6> vec_6e{{0.7f, 0.8f, 0.9f, 1.0f, 1.1f, 1.2f}};

    SECTION("SE2 Group")
    {
        SEGroupf<2> se2_start{LieOperator_SOf::Exp(Vectorf<1>{{vec_3s[0]}}), Vectorf<2>{{vec_3s[1], vec_3s[2]}}};
        SEGroupf<2> se2_end{LieOperator_SOf::Exp(Vectorf<1>{{vec_3e[0]}}), Vectorf<2>{{vec_3e[1], vec_3e[2]}}};

        SlerpLerper<SEGroupf<2>> slerplerper(se2_start, se2_end);
        SEGroupf<2> se2_mid = slerplerper.interpolate(0.5f);
    }

    SECTION("SE3 Group")
    {
        SEGroupf<3> se3_start{LieOperator_SOf::Exp(Vectorf<3>{{vec_6s[0], vec_6s[1], vec_6s[2]}}), Vectorf<3>{{vec_6s[3], vec_6s[4], vec_6s[5]}}};
        SEGroupf<3> se3_end{LieOperator_SOf::Exp(Vectorf<3>{{vec_6e[0], vec_6e[1], vec_6e[2]}}), Vectorf<3>{{vec_6e[3], vec_6e[4], vec_6e[5]}}};

        SlerpLerper<SEGroupf<3>> slerplerper(se3_start, se3_end);
        SEGroupf<3> se3_mid = slerplerper.interpolate(0.5f);
    }
}