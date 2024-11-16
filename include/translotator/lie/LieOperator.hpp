#pragma once

namespace translotator
{
    template <ObjectType oType, typename dataType>
    struct LieOperator
    {
        static_assert(oType == ObjectType::UNIT_COMPLEX_NUM ||
                          oType == ObjectType::UNIT_QUATERNION ||
                          oType == ObjectType::SO_GROUP ||
                          oType == ObjectType::SE_GROUP,
                      "Invalid type for LieOperator. Must have unit complex number, unit quaternion, SO group, or SE group");

        static_assert(is_float_v<dataType>, "Invalid data type for LieOperator. Must be float");
    };

}

#include "S1.hpp"
#include "S3.hpp"
#include "SO.hpp"
#include "SE.hpp"