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
    };

}