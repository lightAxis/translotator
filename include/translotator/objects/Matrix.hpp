#pragma once

// #include "MatrixBase.hpp"

namespace translotator
{
    template <size_t N, size_t M, typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class Matrix : public MatrixBase<N, M, Type, Matrix<N, M, Type>>
    {
    public:
        using MatrixBase<N, M, Type, Matrix<N, M, Type>>::MatrixBase;
    };

    template <size_t N, size_t M>
    using Matrixf = Matrix<N, M, float>;
    template <size_t N, size_t M>
    using Matrixd = Matrix<N, M, double>;
    template <size_t N, size_t M>
    using Matrixld = Matrix<N, M, long double>;
}