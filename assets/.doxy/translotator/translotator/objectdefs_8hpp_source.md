

# File objectdefs.hpp

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**translotator**](dir_ffa3503b73a46a1fbf73d754da62ba14.md) **>** [**objects**](dir_d5306d4012edd8106bd4452d9b4e4e98.md) **>** [**objectdefs.hpp**](objectdefs_8hpp.md)

[Go to the documentation of this file](objectdefs_8hpp.md)


```C++
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
 * @file : objectdefs.hpp
 */

#pragma once

#include <stddef.h>

namespace translotator
{

    enum class ObjectType
    {
        MATRIX,
        VECTOR,
        SQUARE_MATRIX,
        COMPLEX_NUM,
        QUATERNION,
        DUAL_NUMBER,
        DUAL_QUATERNION,
        UNIT_COMPLEX_NUM,
        UNIT_QUATERNION,
        AXIS_ANGLE,
        EULER_ANGLE,
        SO_GROUP,
        SE_GROUP,
        UNIT_DUAL_QUATERNION,
    };

    enum class AXIS
    {
        X = 0x1,
        Y = 0x2,
        Z = 0x3,
    };

    enum class EULER_ORDER
    {
        XYZ = 0x123,
        XZY = 0x132,
        YXZ = 0x213,
        YZX = 0x231,
        ZXY = 0x312,
        ZYX = 0x321,
    };

    namespace EULER_CONSTEXPR
    {
        template <size_t N, EULER_ORDER Order>
        constexpr AXIS AXIS_AT() noexcept
        {
            static_assert(N < 3, "N must be less than 3");
            return static_cast<AXIS>((static_cast<uint32_t>(Order) >> (4 * (2 - N))) & 0xF);
        }

        template <AXIS Axis>
        constexpr size_t AXIS_TO_IDX() noexcept { return static_cast<size_t>(Axis) - 1; }

        template <size_t N, EULER_ORDER Order>
        constexpr size_t AXIS_IDX_AT() noexcept
        {
            return AXIS_TO_IDX<AXIS_AT<N, Order>()>();
        }
    }
    namespace lie
    {
        template <ObjectType oType, typename dataType>
        struct LieOperator;
    }

    // ####################
    // ## matrix objects ##
    // ####################

    template <size_t N, size_t M, typename Type, typename Derived>
    class MatrixBase;

    template <size_t N, size_t M, typename Type>
    class Matrix;

    template <size_t N, typename Type>
    class SquareMatrix;

    template <size_t N, typename Type>
    class Vector;

    // ###################
    // ## number system ##
    // ###################

    template <typename Type>
    class ComplexNum;

    template <typename Type>
    class Quaternion;

    template <typename Type>
    class DualNumber;

    template <typename Type>
    class DualQuaternion;

    // ######################
    // ## rotation objects ##
    // ######################

    template <typename Type>
    class UnitComplexNum;

    template <typename Type>
    class UnitQuaternion;

    template <typename Type>
    class AxisAngle;

    template <typename Type, EULER_ORDER AxisOrder>
    class EulerAngle;

    template <size_t N, typename Type>
    class SOGroup;

    // ########################################
    // ## homogeneous transformation objects ##
    // ########################################

    template <size_t N, typename Type>
    class SEGroup;

    template <typename Type>
    class UnitDualQuaternion;

}
```

