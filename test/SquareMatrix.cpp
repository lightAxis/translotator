
#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

void asdf(const SquareMatrixf<2> &m)
{
    m.print();
}

TEST_CASE("SquareMatrix", "[objects]")
{
    SquareMatrixf<2> m1{{1.f, 2.f,
                         3.f, 4.f}};

    SquareMatrixf<3> m2{{1.f, 2.f, 3.f,
                         1.f, -3.f, -2.f,
                         5.f, 2.f, -1.f}};

    SquareMatrixf<4> m3{{1.f, 2.f, 3.f, 4.f,
                         1.f, 3.f, 5.f, 7.f,
                         9.f, 5.f, 7.f, 8.f,
                         1.f, 5.f, 8.f, 2.f}};

    SECTION("Determinant")
    {
        const float m1_det = m1.determinant();
        REQUIRE(close_enough(m1_det, -2.f));

        const float m2_det = m2.determinant();
        REQUIRE(close_enough(m2_det, 40.f));

        // const float m3_det = m3.determinant();
        // REQUIRE(close_enough(m3_det, -55.f));

        SquareMatrixf<2> m11{{11.f, 12.f,
                              13.f, 14.f}};
        const float m11_det = m11.determinant();
        REQUIRE(close_enough(m11_det, -2.f));

        SquareMatrixf<2> m111 = (m1 * m11).cast2SquareMatrix();
        const float m111_det = m111.determinant();
        REQUIRE(close_enough(m111_det, -2.f * -2.f));

        SquareMatrixf<3> m22{{11.f, 12.f, 13.f,
                              11.f, -13.f, -12.f,
                              15.f, 12.f, -11.f}};
        const float m22_det = m22.determinant();
        REQUIRE(close_enough(m22_det, 6700.f));

        SquareMatrixf<3> m222 = (m2 * m22).cast2SquareMatrix();
        const float m222_det = m222.determinant();
        REQUIRE(close_enough(m222_det, 40.f * 6700.f));

        // SquareMatrixf<4> m33{{11.f, 12.f, 13.f, 14.f,
        //                       11.f, 13.f, 15.f, 17.f,
        //                       19.f, 15.f, 17.f, 18.f,
        //                       11.f, 15.f, 18.f, 12.f}};
        // const float m33_det = m33.determinant();
        // REQUIRE(close_enough(m33_det, -605.f));

        // SquareMatrixf<4> m333 = (m3 * m33).cast2SquareMatrix();
        // m333.print();
        // const float m333_det = m333.determinant();
        // printf("m333_det = %f\n", m333_det);
        // REQUIRE(close_enough(m333_det, -55.f * -605.f));
    }

    SECTION("Inverse")
    {
        bool result{false};

        SquareMatrixf<2> m1_inv = m1.inversed(result);
        REQUIRE(result);

        auto m1m1inv = m1 * m1_inv;
        const SquareMatrixf<2> &m1m1inv_ref = m1m1inv.cast2SquareMatrix();
        const auto &m1m1inv_ref2 = (m1 * m1_inv).cast2SquareMatrix();
        m1m1inv_ref2.print();
        REQUIRE_THAT(m1m1inv_ref.cast2Matrix(), EqualsMatrix(Matrixf<2, 2>::eye()));
        asdf(m1m1inv_ref2);
        REQUIRE_THAT(m1m1inv_ref2.cast2Matrix(), EqualsMatrix(Matrixf<2, 2>::eye()));

        SquareMatrixf<3> m2_inv = m2.inversed(result);
        REQUIRE(result);

        auto m2m2inv = m2 * m2_inv;
        const SquareMatrixf<3> &m2m2inv_ref = m2m2inv.cast2SquareMatrix();
        const SquareMatrixf<3> &m2m2inv_ref2 = (m2 * m2_inv).cast2SquareMatrix();
        REQUIRE_THAT(m2m2inv_ref.cast2Matrix(), EqualsMatrix(Matrixf<3, 3>::eye()));
        REQUIRE_THAT(m2m2inv_ref2.cast2Matrix(), EqualsMatrix(Matrixf<3, 3>::eye()));

        SquareMatrixf<4> m3_inv = m3.inversed(result);
        REQUIRE(result);

        auto m3m3inv = m3 * m3_inv;
        const SquareMatrixf<4> &m3m3inv_ref = m3m3inv.cast2SquareMatrix();
        const SquareMatrixf<4> &m3m3inv_ref2 = (m3 * m3_inv).cast2SquareMatrix();
        REQUIRE_THAT(m3m3inv_ref.cast2Matrix(), EqualsMatrix(Matrixf<4, 4>::eye()));
        REQUIRE_THAT(m3m3inv_ref2.cast2Matrix(), EqualsMatrix(Matrixf<4, 4>::eye()));
    }
}