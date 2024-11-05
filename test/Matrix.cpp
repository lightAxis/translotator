
#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

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
        Matrixf<3, 3> m5({1.f, 2.f, 3.f,
                          4.f, 5.f, 6.f,
                          7.f, 8.f, 9.f});

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
        REQUIRE_THAT(m1, EqualsMatrix(m5));
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

    SECTION("Assignments")
    {
        auto m2 = m1;
        REQUIRE_THAT(m1, EqualsMatrix(m2));

        float block[2][3] = {{11, 22, 33}, {44, 55, 66}};
        Matrixf<2, 3> blockm(block);
        m2.setBlock(0, 0, blockm);

        REQUIRE(m2(0, 0) == 11);
        REQUIRE(m2(0, 1) == 22);
        REQUIRE(m2(0, 2) == 33);
        REQUIRE(m2(1, 0) == 44);
        REQUIRE(m2(1, 1) == 55);
        REQUIRE(m2(1, 2) == 66);

        float row[1][3] = {{77, 88, 99}};
        Matrixf<1, 3> rowm(row);
        m2.setRow(1, rowm);

        REQUIRE(m2(1, 0) == 77);
        REQUIRE(m2(1, 1) == 88);
        REQUIRE(m2(1, 2) == 99);
        float col[3][1] = {{111}, {222}, {333}};
        Matrixf<3, 1> colm(col);
        m2.setCol(2, colm);

        REQUIRE(m2(0, 2) == 111);
        REQUIRE(m2(1, 2) == 222);
        REQUIRE(m2(2, 2) == 333);
    }

    SECTION("Operators")
    {
        // ops with scalar
        auto m2 = m1 * 2.f;
        float data2[3][3] = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
        Matrixf<3, 3> m2_(data2);
        REQUIRE_THAT(m2, EqualsMatrix(m2_));
        auto m22 = m1;
        m22 *= 2.f;
        REQUIRE_THAT(m22, EqualsMatrix(m2_));

        auto m3 = m1 / 2;
        float data3[3][3] = {{0.5, 1, 1.5}, {2, 2.5, 3}, {3.5, 4, 4.5}};
        Matrixf<3, 3> m3_(data3);
        REQUIRE_THAT(m3, EqualsMatrix(m3_));
        auto m33 = m1;
        m33 /= 2;
        REQUIRE_THAT(m33, EqualsMatrix(m3_));

        auto m4 = 2.f * m1;
        REQUIRE_THAT(m4, EqualsMatrix(m2_));

        // ops with matrix
        auto m5 = m1 + m2;
        float data5[3][3] = {{3, 6, 9}, {12, 15, 18}, {21, 24, 27}};
        Matrixf<3, 3> m5_(data5);
        REQUIRE_THAT(m5, EqualsMatrix(m5_));
        auto m55 = m1;
        m55 += m2;
        REQUIRE_THAT(m55, EqualsMatrix(m5_));

        auto m6 = m1 - m2;
        float data6[3][3] = {{-1, -2, -3}, {-4, -5, -6}, {-7, -8, -9}};
        Matrixf<3, 3> m6_(data6);
        REQUIRE_THAT(m6, EqualsMatrix(m6_));
        auto m66 = m1;
        m66 -= m2;
        REQUIRE_THAT(m66, EqualsMatrix(m6_));

        auto m7 = m1 * m1;
        float data7[3][3] = {{30, 36, 42}, {66, 81, 96}, {102, 126, 150}};
        Matrixf<3, 3> m7_(data7);
        REQUIRE_THAT(m7, EqualsMatrix(m7_));
        auto m77 = m1;
        m77 *= m1;
        REQUIRE_THAT(m77, EqualsMatrix(m7_));

        float data8[2][3] = {{1, 2, 3}, {4, 5, 6}};
        Matrixf<2, 3> m8(data8);
        auto m9 = m8 * m1;
        float data9[2][3] = {{30, 36, 42}, {66, 81, 96}};
        Matrixf<2, 3> m9_(data9);
        REQUIRE_THAT(m9, EqualsMatrix(m9_));

        // matrix muliply dimension match
        Matrixf<2, 4> m24;
        Matrixf<4, 3> m43;
        REQUIRE(is_same_v<decltype(m24 * m43), Matrixf<2, 3>> == true);
    }

    SECTION("Utils")
    {
        // transpose
        auto m2 = m1.T();
        float data2[3][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
        Matrixf<3, 3> m2_(data2);
        REQUIRE_THAT(m2, EqualsMatrix(m2_));

        // fill
        m2.fill(100.f);
        float data2_[3][3] = {{100.f, 100.f, 100.f}, {100.f, 100.f, 100.f}, {100.f, 100.f, 100.f}};
        Matrixf<3, 3> m22_(data2_);
        REQUIRE_THAT(m2, EqualsMatrix(m22_));

        // swap rows
        auto m3 = m1;
        m3.swapRows(0, 2);
        float data3[3][3] = {{7, 8, 9}, {4, 5, 6}, {1, 2, 3}};
        Matrixf<3, 3> m3_(data3);
        REQUIRE_THAT(m3, EqualsMatrix(m3_));

        // swap cols
        auto m4 = m1;
        m4.swapCols(0, 2);
        float data4[3][3] = {{3, 2, 1}, {6, 5, 4}, {9, 8, 7}};
        Matrixf<3, 3> m4_(data4);
        REQUIRE_THAT(m4, EqualsMatrix(m4_));

        // frobenius norm
        REQUIRE(close_enough(m4.frobeniusNormSquared(), 285.f));
        REQUIRE(close_enough(m4.frobeniusNorm(), translotator::sqrt(285.f)));
    }

    SECTION("Casting")
    {
        // to double
        auto md = m1.cast<double>();
        REQUIRE(is_same_v<decltype(md)::DATATYPE, double> == true);

        // to long double
        auto mld = m1.cast<long double>();
        REQUIRE(is_same_v<decltype(mld)::DATATYPE, long double> == true);

        // to vector
        float data[3] = {1, 2, 3};
        Matrixf<3, 1> m2(data);
        auto v = m2.castContainer<Vector<3, float>>();
        Vector<3, float> v_(data);
        REQUIRE_THAT(v, EqualsMatrix(v_));
    }

    SECTION("Type Casting Vector")
    {
        Matrixf<3, 1> m2{{1.f, 2.f, 3.f}};
        Vectorf<3> v_{{1.f, 2.f, 3.f}};

        // to vector Ref
        Vector<3, float> v2 = m2.toVector();
        Vector<3, float> &v2_ref = m2.toVectorRef();
        const Vector<3, float> &v2_ref_const = m2.toVectorRef();

        REQUIRE_THAT(v2, EqualsMatrix(v_));
        REQUIRE_THAT(v2_ref, EqualsMatrix(v_));

        v2[0] = 100.f;
        REQUIRE(v2(0, 0) == 100.f);
        REQUIRE(m2(0, 0) == 1.f);

        v2_ref[0] = 200.f;
        REQUIRE(v2_ref(0, 0) == 200.f);
        REQUIRE(m2(0, 0) == 200.f);

        REQUIRE(v2_ref_const(0, 0) == 200.f);

        Matrixf<1, 3> m3{{1.f, 2.f, 3.f}};
        REQUIRE(decltype(m3)::COLS == 3);
        REQUIRE(decltype(m3)::ROWS == 1);
        const auto &vv = m3.T().toVector();
        REQUIRE(vv.ROWS == 3);
        REQUIRE(vv.COLS == 1);

        Matrixf<3, 3> m33{{1.f, 2.f, 3.f,
                           4.f, 5.f, 6.f,
                           7.f, 8.f, 9.f}};
        const auto &v3 = (m33 * m3.T()).toVector();
        REQUIRE(is_same_v<decltype(v3), const Vector<3, float> &> == true);

        Matrixf<3, 3> m4{{1.f, 2.f, 3.f,
                          4.f, 5.f, 6.f,
                          7.f, 8.f, 9.f}};
        float data4[3 * 3];
        m4.copyTo(data4);
        Matrixf<3, 3> m44{{data4}};
        Matrixf<3, 3> m44_{{1.f, 2.f, 3.f,
                            4.f, 5.f, 6.f,
                            7.f, 8.f, 9.f}};
        REQUIRE_THAT(m44, EqualsMatrix(m44_));
    }
}