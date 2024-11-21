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
 * @file : Quaternion.hpp
 */

#pragma once

namespace translotator
{
    /**
     * @brief Representing a quaternion
     * @tparam Type floating point type
     * @details A quaternion is a hypercomplex number that extends the complex numbers. It can be represented as a 4-dimensional vector.
     * The quaternion is defined as q = w + xi + yj + zk, where w, x, y, and z are real numbers, and i, j, and k are the fundamental quaternion units.
     * The quaternion has the following properties: i^2 = j^2 = k^2 = ijk = -1. (Hamillton representation)
     * This can be used to represent rotations in 3D space. Also can be used to represent rotations in 3D space.
     */
    template <typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class Quaternion : public MatrixBase<4, 1, Type, Quaternion<Type>>
    {
    public:
        constexpr static ObjectType OBJECT_TYPE = ObjectType::QUATERNION;
        using MatrixBase<4, 1, Type, Quaternion<Type>>::MatrixBase;

        /**
         * constructors
         */

        inline Quaternion() : MatrixBase<4, 1, Type, Quaternion<Type>>({static_cast<Type>(0), static_cast<Type>(0), static_cast<Type>(0), static_cast<Type>(0)}) {}
        explicit inline Quaternion(Type w, Type x, Type y, Type z) : MatrixBase<4, 1, Type, Quaternion<Type>>({w, x, y, z}) {}
        explicit inline Quaternion(Type w, const Vector<3, Type> &v) : MatrixBase<4, 1, Type, Quaternion<Type>>({w, v[0], v[1], v[2]}) {}
        explicit inline Quaternion(const ComplexNum<Type> &cplx) : MatrixBase<4, 1, Type, Quaternion<Type>>({cplx.Re(), cplx.Im(), static_cast<Type>(0), static_cast<Type>(0)}) {}

        /**
         * accessors
         */

        inline Type w() const { return this->data_[0]; }
        inline Type x() const { return this->data_[1]; }
        inline Type y() const { return this->data_[2]; }
        inline Type z() const { return this->data_[3]; }
        inline const Type Re() const { return w(); }
        inline const Vector<3, Type> Im() const { return Vector<3, Type>({this->data_[1], this->data_[2], this->data_[3]}); }
        inline Type &w() { return this->data_[0]; }
        inline Type &x() { return this->data_[1]; }
        inline Type &y() { return this->data_[2]; }
        inline Type &z() { return this->data_[3]; }
        inline Type &Re() { return w(); }
        inline Vector<3, Type> &Im() { return reinterpret_cast<Vector<3, Type> &>(this->data_[1]); }

        inline Type operator[](size_t i) const { return this->data_[i]; }
        inline Type &operator[](size_t i) { return this->data_[i]; }

        /**
         * casting
         */

        inline SquareMatrix<4, Type> toMulMatrix() const /// get the matrix that represents the quaternion multiplication
        {
            return SquareMatrix<4, Type>{{w(), -x(), -y(), -z(),
                                          x(), w(), -z(), y(),
                                          y(), z(), w(), -x(),
                                          z(), -y(), x(), w()}};
        }
        inline SquareMatrix<4, Type> toRightMulMatrix() const /// get the matrix that represents the quaternion multiplication from the right
        {
            return SquareMatrix<4, Type>{{w(), -x(), -y(), -z(),
                                          x(), w(), z(), -y(),
                                          y(), -z(), w(), x(),
                                          z(), y(), -x(), w()}};
        }

        /**
         * operators
         */

        using MatrixBase<4, 1, Type, Quaternion<Type>>::operator*;
        using MatrixBase<4, 1, Type, Quaternion<Type>>::operator/;
        using MatrixBase<4, 1, Type, Quaternion<Type>>::operator*=;
        using MatrixBase<4, 1, Type, Quaternion<Type>>::operator/=;

        inline Quaternion<Type> operator*(const Quaternion<Type> &q) const /// quaternion multiplication
        {
            return Quaternion<Type>(w() * q.w() - x() * q.x() - y() * q.y() - z() * q.z(),
                                    x() * q.w() + w() * q.x() - z() * q.y() + y() * q.z(),
                                    y() * q.w() + z() * q.x() + w() * q.y() - x() * q.z(),
                                    z() * q.w() - y() * q.x() + x() * q.y() + w() * q.z());
        }
        inline Quaternion<Type> operator/(const Quaternion<Type> &q) const { return *this * q.inversed(); } /// quaternion division

        inline void operator*=(const Quaternion<Type> &q) { *this = *this * q; } /// quaternion multiplication

        inline void operator/=(const Quaternion<Type> &q) { *this = *this / q; } /// quaternion division

        inline Quaternion<Type> quatNumMul(const Quaternion<Type> &q) const { return *this * q; } // alias for operator* for readability

        inline void quatNumMulEq(const Quaternion<Type> &q) { *this *= q; } // alias for operator*= for readability

        inline Quaternion<Type> quatNumDiv(const Quaternion<Type> &q) const { return *this / q; } // alias for operator/ for readability

        inline void quatNumDivEq(const Quaternion<Type> &q) { *this /= q; } // alias for operator/= for readability

        /**
         * utils
         */

        inline Type normSquared() const { return this->frobeniusNormSquared(); } /// get the squared norm of the quaternion

        inline Type norm() const { return this->frobeniusNorm(); } /// get the norm of the quaternion

        inline Quaternion<Type> normalized() const { return *this / norm(); } /// get the normalized quaternion

        inline void normalize() { *this = normalized(); } /// normalize the quaternion

        inline Quaternion<Type> canonicalized() const /// get the canonicalized quaternion
        {
            if (w() < static_cast<Type>(0))
            {
                return -(*this);
            }
            return *this;
        }

        inline void canonicalize() { *this = canonicalized(); } /// canonicalize the quaternion

        inline Quaternion<Type> conjugated() const { return Quaternion<Type>(w(), -x(), -y(), -z()); } /// get the conjugated quaternion

        inline void conjugate() { *this = conjugated(); } /// conjugate the quaternion

        inline Quaternion<Type> inversed() const { return conjugated() / normSquared(); } /// get the inversed quaternion

        inline void inverse() { *this = inversed(); } /// inverse the quaternion
    };

    using Quaternionf = Quaternion<float>;
    using Quaterniond = Quaternion<double>;
    using Quaternionld = Quaternion<long double>;
}