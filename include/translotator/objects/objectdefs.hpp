#pragma once

#include <stddef.h>

namespace translotator
{
    template <size_t N, size_t M, typename Type>
    class Matrix;

    template <size_t N, typename Type>
    class SquareMatrix;

    template <size_t N, typename Type>
    class Vector;

    template <size_t N, size_t M, typename Type, typename Derived>
    class MatrixBase;

    template <typename Type>
    class ComplexNum;

    template <typename Type>
    class UnitComplexNum;

    template <typename Type>
    class Quaternion;

    template <typename Type>
    class UnitQuaternion;

    template <typename Type>
    class AxisAngle;
}