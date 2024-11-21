/*
 * The MIT License (MIT)
 * Copyright (c) 2024 Jiseok Lee
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Created on Tue Nov 19 2024
 * @file : LieOperator.hpp
 */

#pragma once

namespace translotator::lie
{
    /**
     * @brief Lie Operator for Lie Group and Lie Algebra
     * @tparam oType Object type
     * @tparam dataType Data type
     */
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