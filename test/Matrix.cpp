
#include "custom_tester.hpp"

#include <translotator/objects/Matrix.hpp>

using namespace translotator;

TEST_CASE("Matrix", "[objects]")
{
    float data1[3 * 3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrixf<3, 3> m1(data1);

    SECTION("basic constructors")
    {
        float data2[3][3] = {{11, 22, 33}, {44, 55, 66}, {77, 88, 99}};
        Matrixf<3, 3> m2(data2);
        Matrixf<3, 3> m3 = m1;
        Matrixf<3, 3> m4(m2);

        REQUIRE(m1(0, 0) == 1);
        REQUIRE(m1(0, 1) == 2);
        REQUIRE(m1(0, 2) == 3);
        REQUIRE(m1(1, 0) == 4);
        REQUIRE(m1(1, 1) == 5);
        REQUIRE(m1(1, 2) == 6);
        REQUIRE(m1(2, 0) == 7);
        REQUIRE(m1(2, 1) == 8);
        REQUIRE(m1(2, 2) == 9);

        REQUIRE(m2(0, 0) == 11);
        REQUIRE(m2(0, 1) == 22);
        REQUIRE(m2(0, 2) == 33);
        REQUIRE(m2(1, 0) == 44);
        REQUIRE(m2(1, 1) == 55);
        REQUIRE(m2(1, 2) == 66);
        REQUIRE(m2(2, 0) == 77);
        REQUIRE(m2(2, 1) == 88);
        REQUIRE(m2(2, 2) == 99);

        REQUIRE_THAT(m1, EqualsMatrix(m3));
        REQUIRE_THAT(m2, EqualsMatrix(m4));
    }

    SECTION("constants")
    {
        auto eye = Matrixf<3, 3>::eye();
        float data_eye[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        Matrixf<3, 3> eye_(data_eye);
        REQUIRE_THAT(eye, EqualsMatrix(eye_));

        auto eye34 = Matrixf<3, 4>::eye();
        float data_eye34[3][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
        Matrixf<3, 4> eye34_(data_eye34);
        REQUIRE_THAT(eye34, EqualsMatrix(eye34_));

        auto eye43 = Matrixf<4, 3>::eye();
        float data_eye43[4][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0, 0, 0}};
        Matrixf<4, 3> eye43_(data_eye43);
        REQUIRE_THAT(eye43, EqualsMatrix(eye43_));

        auto zeros = Matrixf<3, 3>::zeros();
        float data_zeros[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        Matrixf<3, 3> zeros_(data_zeros);
        REQUIRE_THAT(zeros, EqualsMatrix(zeros_));

        auto ones = Matrixf<3, 3>::ones();
        float data_ones[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
        Matrixf<3, 3> ones_(data_ones);
        REQUIRE_THAT(ones, EqualsMatrix(ones_));
    }

    SECTION("Accessors")
    {
        float row1[1][3] = {{1, 2, 3}};
        float row2[1][3] = {{4, 5, 6}};
        float row3[1][3] = {{7, 8, 9}};

        float col1[3][1] = {{1}, {4}, {7}};
        float col2[3][1] = {{2}, {5}, {8}};
        float col3[3][1] = {{3}, {6}, {9}};

        REQUIRE_THAT(m1.row(0), EqualsMatrix(Matrixf<1, 3>(row1)));
        REQUIRE_THAT(m1.row(1), EqualsMatrix(Matrixf<1, 3>(row2)));
        REQUIRE_THAT(m1.row(2), EqualsMatrix(Matrixf<1, 3>(row3)));

        REQUIRE_THAT(m1.col(0), EqualsMatrix(Matrixf<3, 1>(col1)));
        REQUIRE_THAT(m1.col(1), EqualsMatrix(Matrixf<3, 1>(col2)));
        REQUIRE_THAT(m1.col(2), EqualsMatrix(Matrixf<3, 1>(col3)));

        float block1[2][2] = {{1, 2}, {4, 5}};
        float block2[2][2] = {{2, 3}, {5, 6}};
        float block3[1][2] = {{4, 5}};

        REQUIRE_THAT((m1.block<2, 2>(0, 0)), EqualsMatrix(Matrixf<2, 2>(block1)));
        REQUIRE_THAT((m1.block<2, 2>(0, 1)), EqualsMatrix(Matrixf<2, 2>(block2)));
        REQUIRE_THAT((m1.block<1, 2>(1, 0)), EqualsMatrix(Matrixf<1, 2>(block3)));

        REQUIRE_THAT((m1.block<0, 0, 2, 2>()), EqualsMatrix(Matrixf<2, 2>(block1)));
        REQUIRE_THAT((m1.block<0, 1, 2, 2>()), EqualsMatrix(Matrixf<2, 2>(block2)));
        REQUIRE_THAT((m1.block<1, 0, 1, 2>()), EqualsMatrix(Matrixf<1, 2>(block3)));
    }
}