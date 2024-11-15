
#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

TEST_CASE("Lie Operator", "[lie group operations]")
{
    Vectorf<1> vec1{{1.f}};
    Vectorf<3> vec3{{0.1f, 0.2f, 0.3f}};

    auto S1 = LieOperator<ObjectType::UNIT_COMPLEX_NUM, float>::Exp(vec1);
    auto S3 = LieOperator<ObjectType::UNIT_QUATERNION, float>::Exp(vec3 / 2.f);
    auto SO2 = LieOperator<ObjectType::SO_GROUP, float>::Exp(vec1);
    auto SO3 = LieOperator<ObjectType::SO_GROUP, float>::Exp(vec3);
}