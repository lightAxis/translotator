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
    /**
     * @brief Vector class
     * @tparam N vector size
     * @tparam Type floating point type
     * @details Vector class is a class that represents a vector.
     */
    template <size_t N, typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class Vector : public MatrixBase<N, 1, Type, Vector<N, Type>>
    {
    public:
        constexpr static ObjectType OBJECT_TYPE = ObjectType::VECTOR;
        using MatrixBase<N, 1, Type, Vector<N, Type>>::MatrixBase;

        inline Type norm() const { return this->frobeniusNorm(); } /// return norm of vector

        inline Type normSquared() const { return this->frobeniusNormSquared(); } /// return squared norm of vector

        inline Vector<N, Type> normalized() const /// return normalized vector
        {
            Vector<N, Type> result;
            Type norm = this->norm();
            for (size_t i = 0; i < N; i++)
                result[i] = this->data_[i] / norm;
            return result;
        }
        inline void normalize() { *this = normalized(); } /// in-place normalize

        /**
         * Vector utils
         */

        inline Type dot(const Vector<N, Type> &other) const /// dot product
        {
            Type result = 0;
            for (size_t i = 0; i < N; i++)
                result += this->data_[i] * other[i];
            return result;
        }

        /**
         * @brief cross product operation
         * @note only for 3D vector
         */
        template <size_t Dim = N, typename = enable_if_t<Dim == 3, true_type>>
        inline Vector<3, Type> cross(const Vector<3, Type> &other) const
        {
            Vector<3, Type> result;
            result[0] = y() * other.z() - z() * other.y();
            result[1] = z() * other.x() - x() * other.z();
            result[2] = x() * other.y() - y() * other.x();
            return result;
        }

        /**
         * @brief convert to cross matrix
         * @note only for 3D vector
         */
        template <size_t Dim = N, typename = enable_if_t<Dim == 3, true_type>>
        inline SquareMatrix<3, Type> toCrossMatrix() const
        {
            return SquareMatrix<3, Type>{{static_cast<Type>(0), -z(), y(),
                                          z(), static_cast<Type>(0), -x(),
                                          -y(), x(), static_cast<Type>(0)}};
        }
        inline SquareMatrix<N, Type> toDiagMatrix() const /// convert to diagonal matrix
        {
            SquareMatrix<N, Type> result{SquareMatrix<N, Type>::zeros()};
            for (size_t i = 0; i < N; i++)
                result(i, i) = this->data_[i];
            return result;
        }

        /**
         * Vector Specialized Accessors
         */

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

        /**
         * Vector static functions
         */

        /**
         * @brief element axis vector
         * @note only for 1D~3D vector
         */
        template <size_t Dim = N, typename = enable_if_t<1 <= Dim && Dim <= 3, true_type>>
        static inline Vector<N, Type> xAxis()
        {
            Vector<N, Type> v{Vector<N, Type>::zeros()};
            v.x() = static_cast<Type>(1);
            return v;
        }

        /**
         * @brief element axis vector
         * @note only for 2D~3D vector
         */
        template <size_t Dim = N, typename = enable_if_t<2 <= Dim && Dim <= 3, true_type>>
        static inline Vector<N, Type> yAxis()
        {
            Vector<N, Type> v{Vector<N, Type>::zeros()};
            v.y() = static_cast<Type>(1);
            return v;
        }

        /**
         * @brief element axis vector
         * @note only for 3D vector
         */
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