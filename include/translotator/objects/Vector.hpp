#pragma once

// #include "Matrix.hpp"

namespace translotator
{
    template <size_t N, typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class Vector : public MatrixBase<N, 1, Type, Vector<N, Type>>
    {
    public:
        using MatrixBase<N, 1, Type, Vector<N, Type>>::MatrixBase;

        inline Type &operator[](size_t i)
        {
            return this->data_[i];
        }
        inline const Type &operator[](size_t i) const
        {
            return this->data_[i];
        }

        inline Vector<N, Type> normalized() const
        {
            Vector<N, Type> result;
            Type norm = 0;
            for (size_t i = 0; i < N; i++)
                norm += this->data_[i] * this->data_[i];
            norm = translotator::sqrt(norm);
            for (size_t i = 0; i < N; i++)
                result[i] = this->data_[i] / norm;
            return result;
        }

        inline void normalize() { *this = normalized(); }

        inline Type dot(const Vector<N, Type> &other) const
        {
            Type result = 0;
            for (size_t i = 0; i < N; i++)
                result += this->data_[i] * other[i];
            return result;
        }

        template <size_t Dim = N, typename = enable_if_t<Dim == 3, true_type>>
        inline Vector<3, Type> cross(const Vector<3, Type> &other) const
        {
            Vector<3, Type> result;
            result[0] = this->data_[1] * other[2] - this->data_[2] * other[1];
            result[1] = this->data_[2] * other[0] - this->data_[0] * other[2];
            result[2] = this->data_[0] * other[1] - this->data_[1] * other[0];
            return result;
        }
    };

    template <size_t N>
    using Vectorf = Vector<N, float>;
    template <size_t N>
    using Vectord = Vector<N, double>;
    template <size_t N>
    using Vectorld = Vector<N, long double>;

}