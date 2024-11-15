#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

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