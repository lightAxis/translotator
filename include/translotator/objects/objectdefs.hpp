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

    /**
     * @brief Enum class for object types
     * @details This enum class is used to identify the type of the object
     */
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

    /**
     * @brief Enum class for axis
     * @details This enum class is used to identify the axis
     */
    enum class AXIS
    {
        X = 0x1,
        Y = 0x2,
        Z = 0x3,
    };

    /**
     * @brief Enum class for euler angle order
     * @details This enum class is used to identify the euler angle order
     * @note The order is represented as 3 digits, where each digit represents the axis
     * @note All intrinsic orders, Tait-Bryan angles
     * @note For example, XYZ order means the rotation is applied in the order of intrinsic X, Y, Z axis
     */
    enum class EULER_ORDER
    {
        XYZ = 0x123,
        XZY = 0x132,
        YXZ = 0x213,
        YZX = 0x231,
        ZXY = 0x312,
        ZYX = 0x321,
    };

    /**
     * @brief Namespace for Euler Order constexpr functions
     */
    namespace EULER_CONSTEXPR
    {
        /**
         * @brief Get the axis at Nth index in the euler order
         * @tparam N Nth index
         * @tparam Order Euler order
         * @return Axis at Nth index
         */
        template <size_t N, EULER_ORDER Order>
        constexpr AXIS AXIS_AT() noexcept
        {
            static_assert(N < 3, "N must be less than 3");
            return static_cast<AXIS>((static_cast<uint32_t>(Order) >> (4 * (2 - N))) & 0xF);
        }

        /**
         * @brief Get the index of the axis in the euler order
         * @tparam Axis Axis
         * @tparam Order Euler order
         * @return Index of the axis
         */
        template <AXIS Axis>
        constexpr size_t AXIS_TO_IDX() noexcept { return static_cast<size_t>(Axis) - 1; }

        /**
         * @brief Get the index of the axis at Nth index in the euler order
         * @tparam N Nth index
         * @tparam Order Euler order
         * @return Index of the axis
         */
        template <size_t N, EULER_ORDER Order>
        constexpr size_t AXIS_IDX_AT() noexcept
        {
            return AXIS_TO_IDX<AXIS_AT<N, Order>()>();
        }
    }
    /**
     * @brief Namespace for Lie Group and Algebra Operations
     */
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