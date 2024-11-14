#pragma once

#include <stddef.h>

namespace translotator
{
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