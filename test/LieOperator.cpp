
#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

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
}