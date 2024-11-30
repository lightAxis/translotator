

# File Vector.hpp

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**translotator**](dir_ffa3503b73a46a1fbf73d754da62ba14.md) **>** [**objects**](dir_d5306d4012edd8106bd4452d9b4e4e98.md) **>** [**Vector.hpp**](Vector_8hpp.md)

[Go to the documentation of this file](Vector_8hpp.md)


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
 * @file : Vector.hpp
 */

#pragma once

namespace translotator
{
    template <size_t N, typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class Vector : public MatrixBase<N, 1, Type, Vector<N, Type>>
    {
    public:
        constexpr static ObjectType OBJECT_TYPE = ObjectType::VECTOR;
        using MatrixBase<N, 1, Type, Vector<N, Type>>::MatrixBase;

        inline Type norm() const { return this->frobeniusNorm(); } 

        inline Type normSquared() const { return this->frobeniusNormSquared(); } 

        inline Vector<N, Type> normalized() const 
        {
            Vector<N, Type> result;
            Type norm = this->norm();
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
            result[0] = y() * other.z() - z() * other.y();
            result[1] = z() * other.x() - x() * other.z();
            result[2] = x() * other.y() - y() * other.x();
            return result;
        }

        template <size_t Dim = N, typename = enable_if_t<Dim == 3, true_type>>
        inline SquareMatrix<3, Type> toCrossMatrix() const
        {
            return SquareMatrix<3, Type>{{static_cast<Type>(0), -z(), y(),
                                          z(), static_cast<Type>(0), -x(),
                                          -y(), x(), static_cast<Type>(0)}};
        }
        inline SquareMatrix<N, Type> toDiagMatrix() const 
        {
            SquareMatrix<N, Type> result{SquareMatrix<N, Type>::zeros()};
            for (size_t i = 0; i < N; i++)
                result(i, i) = this->data_[i];
            return result;
        }

        inline Type &operator[](size_t i) { return this->data_[i]; }
        inline const Type &operator[](size_t i) const { return this->data_[i]; }

        template <size_t Dim = N, typename = enable_if_t<1 <= Dim && Dim <= 3, true_type>>
        inline Type x() const { return this->data_[0]; }
        template <size_t Dim = N, typename = enable_if_t<2 <= Dim && Dim <= 3, true_type>>
        inline Type y() const { return this->data_[1]; }
        template <size_t Dim = N, typename = enable_if_t<3 <= Dim && Dim <= 3, true_type>>
        inline Type z() const { return this->data_[2]; }
        template <size_t Dim = N, typename = enable_if_t<1 <= Dim && Dim <= 3, true_type>>
        inline Type &x() { return this->data_[0]; }
        template <size_t Dim = N, typename = enable_if_t<2 <= Dim && Dim <= 3, true_type>>
        inline Type &y() { return this->data_[1]; }
        template <size_t Dim = N, typename = enable_if_t<3 <= Dim && Dim <= 3, true_type>>
        inline Type &z() { return this->data_[2]; }

        template <size_t Dim = N, typename = enable_if_t<1 <= Dim && Dim <= 3, true_type>>
        static inline Vector<N, Type> xAxis()
        {
            Vector<N, Type> v{Vector<N, Type>::zeros()};
            v.x() = static_cast<Type>(1);
            return v;
        }

        template <size_t Dim = N, typename = enable_if_t<2 <= Dim && Dim <= 3, true_type>>
        static inline Vector<N, Type> yAxis()
        {
            Vector<N, Type> v{Vector<N, Type>::zeros()};
            v.y() = static_cast<Type>(1);
            return v;
        }

        template <size_t Dim = N, typename = enable_if_t<3 <= Dim && Dim <= 3, true_type>>
        static inline Vector<N, Type> zAxis()
        {
            Vector<N, Type> v{Vector<N, Type>::zeros()};
            v.z() = static_cast<Type>(1);
            return v;
        }
    };

    template <size_t N>
    using Vectorf = Vector<N, float>;
    template <size_t N>
    using Vectord = Vector<N, double>;
    template <size_t N>
    using Vectorld = Vector<N, long double>;
}
```


