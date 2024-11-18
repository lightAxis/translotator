#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

TEST_CASE("SEGroup", "[objects]")
{
    EulerAngleXYZf euler{1.f, 2.f, 3.f};
    SOGroupf<2> so2 = euler.toSO2Group();
    SOGroupf<3> so3 = euler.toSO3Group();
    Vector<2> t2{{1.f, 2.f}};
    Vector<3> t3{{1.f, 2.f, 3.f}};
    SEGroupf<2> se2{so2, t2};
    SEGroupf<3> se3{so3, t3};

    SECTION("constructor")
    {
        SEGroupf<2> se2_{so2, t2};
        REQUIRE_THAT(se2.rotation(), EqualsMatrix(so2));
        REQUIRE_THAT(se2.translation(), EqualsMatrix(t2));

        SEGroupf<3> se3_{so3, t3};
        REQUIRE_THAT(se3.rotation(), EqualsMatrix(so3));
        REQUIRE_THAT(se3.translation(), EqualsMatrix(t3));

        SquareMatrixf<4> mat44;
        mat44.setBlockStatic<0, 0>(so3);
        mat44.setBlockStatic<0, 3>(t3);
        mat44.setBlockStatic<3, 0>(Matrix<1, 3>::zeros());
        mat44(3, 3) = 1.f;
        SEGroupf<3> se3__{mat44};
        REQUIRE_THAT(se3, EqualsMatrix(se3__));
    }

    SECTION("accessors")
    {
        REQUIRE_THAT(se2.rotation(), EqualsMatrix(so2));
        REQUIRE_THAT(se2.translation(), EqualsMatrix(t2));

        SEGroupf<2> se2_ = se2;
        se2_.rotation()(0, 0) = 100.f;
        se2_.translation()[1] = 200.f;
        SOGroupf<2> so2_ = so2;
        so2_(0, 0) = 100.f;
        Vectorf<2> t2_ = t2;
        t2_[1] = 200.f;
        SEGroupf<2> se2_ans = {so2_, t2_};
        REQUIRE_THAT(se2_, EqualsMatrix(se2_ans));

        REQUIRE_THAT(se3.rotation(), EqualsMatrix(so3));
        REQUIRE_THAT(se3.translation(), EqualsMatrix(t3));

        SEGroupf<3> se3_ = se3;
        se3_.rotation()(0, 0) = 100.f;
        se3_.translation()[1] = 200.f;
        SOGroup<3> so3_ = so3;
        so3_(0, 0) = 100.f;
        Vectorf<3> t3_ = t3;
        t3_[1] = 200.f;
        SEGroupf<3> se3_ans = {so3_, t3_};
        REQUIRE_THAT(se3_, EqualsMatrix(se3_ans));
    }

    SECTION("operator")
    {
        SEGroupf<3> se3_b{so3, t3};

        SEGroupf<3> se3_se3b = se3 * se3_b;
        SOGroupf<3> R = so3 * so3;
        Vectorf<3> T = so3 * t3 + t3;
        REQUIRE_THAT(se3_se3b, EqualsMatrix(SEGroupf<3>{R, T}));

        SEGroupf<3> se3_div_se3b = se3 / se3_b;
        REQUIRE_THAT(se3_div_se3b, EqualsMatrix(SEGroupf<3>::identity()));
    }

    SECTION("utils")
    {
        SOGroupf<3> so3_inv = so3.inversed();
        SEGroupf<3> se3_inv = se3.inversed();
        REQUIRE_THAT(se3_inv, EqualsMatrix(SEGroupf<3>{so3_inv, -so3_inv * t3}));

        Vectorf<3> vec_acted = se3.actOnVector(t3);
        Vectorf<3> vec_acted_ans = so3 * t3 + t3;
        REQUIRE_THAT(vec_acted, EqualsMatrix(vec_acted_ans));

        SEGroupf<3> se3_2 = se3.pow(0.5f);
        SEGroupf<3> se3_22 = se3_2.pow(2.f);
        SEGroupf<3> se3_22_ = se3_2 * se3_2;
        REQUIRE_THAT(se3_22, EqualsMatrix(se3_22_));
        REQUIRE_THAT(se3, EqualsMatrix(se3_22));
    }

    SECTION("static functions")
    {
        SEGroupf<3> se3_iden = SEGroupf<3>::identity();
        REQUIRE_THAT(se3_iden.toSquareMatrix(), EqualsMatrix(SquareMatrixf<4>::eye()));
    }

    SECTION("casts")
    {
    }
}