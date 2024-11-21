
#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;
using namespace translotator::lie;

TEST_CASE("Lie Operator", "[lie group operations]")
{
    Vectorf<1> vec1{{1.f}};
    Vectorf<3> vec3{{0.1f, 0.2f, 0.3f}};

    Vectorf<6> vec6{{0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f}};

    auto S1 = LieOperator<ObjectType::UNIT_COMPLEX_NUM, float>::Exp(vec1);
    auto S3 = LieOperator<ObjectType::UNIT_QUATERNION, float>::Exp(vec3);

    auto SO2 = LieOperator<ObjectType::SO_GROUP, float>::Exp(vec1);
    auto SO3 = LieOperator<ObjectType::SO_GROUP, float>::Exp(vec3);

    auto SE2 = LieOperator<ObjectType::SE_GROUP, float>::Exp(vec3);
    auto SE3 = LieOperator<ObjectType::SE_GROUP, float>::Exp(vec6);

    auto se2Vec = LieOperator<ObjectType::SE_GROUP, float>::Log(SE2);
    auto se3Vec = LieOperator<ObjectType::SE_GROUP, float>::Log(SE3);

    SECTION("S1")
    {
        Vectorf<1> s1_vec_ans = vec1;
        ComplexNumf s1_lieAlgebra_ans{0.f, 1.f};
        UnitComplexNumf s1_group_ans{0.540302f, 0.841471f};

        auto s1_lieAlgebra = LieOperator_S1f::Vector2LieAlgebra(vec1);
        REQUIRE(is_same_v<decltype(s1_lieAlgebra), ComplexNumf>);
        REQUIRE_THAT(s1_lieAlgebra, EqualsMatrix(s1_lieAlgebra_ans));

        auto s1_vector = LieOperator_S1f::LieAlgebra2Vector(s1_lieAlgebra);
        REQUIRE(is_same_v<decltype(s1_vector), Vectorf<1>>);
        REQUIRE_THAT(s1_vector, EqualsMatrix(s1_vec_ans));

        auto s1_group = LieOperator_S1f::Exp(vec1);
        REQUIRE(is_same_v<decltype(s1_group), UnitComplexNumf>);
        REQUIRE_THAT(s1_group, EqualsMatrix(s1_group_ans));

        auto s1_vector_ = LieOperator_S1f::Log(s1_group);
        REQUIRE(is_same_v<decltype(s1_vector_), Vectorf<1>>);
        REQUIRE_THAT(s1_vector_, EqualsMatrix(s1_vec_ans));

        auto s1_group_ = LieOperator_S1f::exp(s1_lieAlgebra);
        REQUIRE_THAT(s1_group_, EqualsMatrix(s1_group_ans));

        auto s1_lieAlgebra_ = LieOperator_S1f::log(s1_group_);
        REQUIRE_THAT(s1_lieAlgebra_, EqualsMatrix(s1_lieAlgebra_ans));
    }

    SECTION("S3")
    {
        Vectorf<3> s3_vec_ans = vec3;
        Quaternionf s3_lieAlgebra_ans{0.f, Vectorf<3>{{0.1f, 0.2f, 0.3f}}};
        UnitQuaternionf s3_group_ans{0.9308129f, 0.0976829f, 0.1953659f, 0.2930488f};

        auto s3_lieAlgebra = LieOperator_S3f::Vector2LieAlgebra(vec3);
        REQUIRE(is_same_v<decltype(s3_lieAlgebra), Quaternionf>);
        REQUIRE_THAT(s3_lieAlgebra, EqualsMatrix(s3_lieAlgebra_ans));

        auto s3_vector = LieOperator_S3f::LieAlgebra2Vector(s3_lieAlgebra);
        REQUIRE(is_same_v<decltype(s3_vector), Vectorf<3>>);
        REQUIRE_THAT(s3_vector, EqualsMatrix(s3_vec_ans));

        auto s3_group = LieOperator_S3f::Exp(vec3);
        REQUIRE(is_same_v<decltype(s3_group), UnitQuaternionf>);
        REQUIRE_THAT(s3_group, EqualsMatrix(s3_group_ans));

        auto s3_vector_ = LieOperator_S3f::Log(s3_group);
        REQUIRE(is_same_v<decltype(s3_vector_), Vectorf<3>>);
        REQUIRE_THAT(s3_vector_, EqualsMatrix(s3_vec_ans));

        auto s3_group_ = LieOperator_S3f::exp(s3_lieAlgebra);
        REQUIRE_THAT(s3_group_, EqualsMatrix(s3_group_ans));
    }

    SECTION("SO2")
    {
        Vectorf<1> so2_vec_ans = vec1;
        SquareMatrixf<2> so2_lieAlgebra_ans{{0.f, -1.f,
                                             1.f, 0.f}};
        SO2Groupf so2_group_ans{{0.540302f, -0.841471f,
                                 0.841471f, 0.540302f}};

        auto so2_lieAlgebra = LieOperator_SOf::Vector2LieAlgebra(vec1);
        REQUIRE(is_same_v<decltype(so2_lieAlgebra), SquareMatrixf<2>>);
        REQUIRE_THAT(so2_lieAlgebra, EqualsMatrix(so2_lieAlgebra_ans));

        auto so2_vector = LieOperator_SOf::LieAlgebra2Vector(so2_lieAlgebra);
        REQUIRE(is_same_v<decltype(so2_vector), Vectorf<1>>);
        REQUIRE_THAT(so2_vector, EqualsMatrix(so2_vec_ans));

        auto so2_group = LieOperator_SOf::Exp(vec1);
        REQUIRE(is_same_v<decltype(so2_group), SO2Groupf>);
        REQUIRE_THAT(so2_group, EqualsMatrix(so2_group_ans));

        auto so2_vector_ = LieOperator_SOf::Log(so2_group);
        REQUIRE(is_same_v<decltype(so2_vector_), Vectorf<1>>);
        REQUIRE_THAT(so2_vector_, EqualsMatrix(so2_vec_ans));

        auto so2_group_ = LieOperator_SOf::exp(so2_lieAlgebra);
        REQUIRE_THAT(so2_group_, EqualsMatrix(so2_group_ans));

        auto so2_lieAlgebra_ = LieOperator_SOf::log(so2_group_);
        REQUIRE_THAT(so2_lieAlgebra_, EqualsMatrix(so2_lieAlgebra_ans));
    }

    SECTION("SO3")
    {
        Vectorf<3> so3_vec_ans = vec3;
        SquareMatrixf<3> so3_lieAlgebra_ans{{0.f, -0.3f, 0.2f,
                                             0.3f, 0.f, -0.1f,
                                             -0.2f, 0.1f, 0.f}};
        SO3Groupf so3_group_ans{{0.9357548f, -0.2831649f, 0.2101917f,
                                 0.3029327f, 0.9505806f, -0.0680313f,
                                 -0.1805401f, 0.1273346f, 0.9752903f}};

        auto so3_lieAlgebra = LieOperator_SOf::Vector2LieAlgebra(vec3);
        REQUIRE(is_same_v<decltype(so3_lieAlgebra), SquareMatrixf<3>>);
        REQUIRE_THAT(so3_lieAlgebra, EqualsMatrix(so3_lieAlgebra_ans));

        auto so3_vector = LieOperator_SOf::LieAlgebra2Vector(so3_lieAlgebra);
        REQUIRE(is_same_v<decltype(so3_vector), Vectorf<3>>);
        REQUIRE_THAT(so3_vector, EqualsMatrix(so3_vec_ans));

        auto so3_group = LieOperator_SOf::Exp(vec3);
        REQUIRE(is_same_v<decltype(so3_group), SO3Groupf>);
        REQUIRE_THAT(so3_group, EqualsMatrix(so3_group_ans));

        auto so3_vector_ = LieOperator_SOf::Log(so3_group);
        REQUIRE(is_same_v<decltype(so3_vector_), Vectorf<3>>);
        REQUIRE_THAT(so3_vector_, EqualsMatrix(so3_vec_ans));

        auto so3_group_ = LieOperator_SOf::exp(so3_lieAlgebra);
        REQUIRE_THAT(so3_group_, EqualsMatrix(so3_group_ans));

        auto so3_lieAlgebra_ = LieOperator_SOf::log(so3_group_);
        REQUIRE_THAT(so3_lieAlgebra_, EqualsMatrix(so3_lieAlgebra_ans));
    }

    SECTION("SE2")
    {
        Vectorf<3> se2_vec_ans = vec3;
        SquareMatrixf<3> se2_lieAlgebra_ans{{0.f, -0.1f, 0.2f,
                                             0.1f, 0.f, 0.3f,
                                             0.f, 0.f, 0.f}};
        SquareMatrixf<3> se2_group_ans_mat{{0.995f, -0.099833f, 0.18468f,
                                            0.099833f, 0.995f, 0.30949f,
                                            0.f, 0.f, 1.f}};
        SEGroupf<2> se2_group_ans{se2_group_ans_mat};

        auto se2_lieAlgebra = LieOperator_SEf::Vector2LieAlgebra(vec3);
        REQUIRE(is_same_v<decltype(se2_lieAlgebra), SquareMatrixf<3>>);
        REQUIRE_THAT(se2_lieAlgebra, EqualsMatrix(se2_lieAlgebra_ans));

        auto se2_vector = LieOperator_SEf::LieAlgebra2Vector(se2_lieAlgebra);
        REQUIRE(is_same_v<decltype(se2_vector), Vectorf<3>>);
        REQUIRE_THAT(se2_vector, EqualsMatrix(se2_vec_ans));

        auto se2_group = LieOperator_SEf::Exp(vec3);
        REQUIRE(is_same_v<decltype(se2_group), SEGroupf<2>>);
        REQUIRE_THAT(se2_group, EqualsMatrix(se2_group_ans));

        auto se2_vector_ = LieOperator_SEf::Log(se2_group);
        REQUIRE(is_same_v<decltype(se2_vector_), Vectorf<3>>);
        REQUIRE_THAT(se2_vector_, EqualsMatrix(se2_vec_ans));

        auto se2_group_ = LieOperator_SEf::exp(se2_lieAlgebra);
        REQUIRE_THAT(se2_group_, EqualsMatrix(se2_group_ans));

        auto se2_lieAlgebra_ = LieOperator_SEf::log(se2_group_);
        REQUIRE_THAT(se2_lieAlgebra_, EqualsMatrix(se2_lieAlgebra_ans));
    }

    SECTION("SE3")
    {
        Vectorf<6> se3_vec_ans = vec6;
        SquareMatrixf<4> se3_lieAlgebra_ans{{0.f, -0.3f, 0.2f, 0.4f,
                                             0.3f, 0.f, -0.1f, 0.5f,
                                             -0.2f, 0.1f, 0.f, 0.6f,
                                             0.f, 0.f, 0.f, 0.f}};
        SquareMatrixf<4> se3_group_ans_mat{{0.9357548f, -0.2831649f, 0.2101917f, 0.38120f,
                                            0.3029327f, 0.9505806f, -0.0680313f, 0.52866f,
                                            -0.1805401f, 0.1273346f, 0.9752903f, 0.58716f,
                                            0.f, 0.f, 0.f, 1.f}};

        SEGroupf<3> se3_group_ans{se3_group_ans_mat};

        auto se3_lieAlgebra = LieOperator_SEf::Vector2LieAlgebra(vec6);
        REQUIRE(is_same_v<decltype(se3_lieAlgebra), SquareMatrixf<4>>);
        REQUIRE_THAT(se3_lieAlgebra, EqualsMatrix(se3_lieAlgebra_ans));

        auto se3_vector = LieOperator_SEf::LieAlgebra2Vector(se3_lieAlgebra);
        REQUIRE(is_same_v<decltype(se3_vector), Vectorf<6>>);
        REQUIRE_THAT(se3_vector, EqualsMatrix(se3_vec_ans));

        auto se3_group = LieOperator_SEf::Exp(vec6);
        REQUIRE(is_same_v<decltype(se3_group), SEGroupf<3>>);
        REQUIRE_THAT(se3_group, EqualsMatrix(se3_group_ans));

        auto se3_vector_ = LieOperator_SEf::Log(se3_group);
        REQUIRE(is_same_v<decltype(se3_vector_), Vectorf<6>>);
        REQUIRE_THAT(se3_vector_, EqualsMatrix(se3_vec_ans));

        auto se3_group_ = LieOperator_SEf::exp(se3_lieAlgebra);
        REQUIRE_THAT(se3_group_, EqualsMatrix(se3_group_ans));

        auto se3_lieAlgebra_ = LieOperator_SEf::log(se3_group_);
        REQUIRE_THAT(se3_lieAlgebra_, EqualsMatrix(se3_lieAlgebra_ans));
    }
}
