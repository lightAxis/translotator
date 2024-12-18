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
 * @file : DualQuaternion.hpp
 */

#pragma once

namespace translotator
{
    // https://faculty.sites.iastate.edu/jia/files/inline-files/dual-quaternion.pdf

    /**
     * @brief Represents a dual quaternion
     * @tparam Type data type
     * @details Dual quaternion is a hypercomplex number system that extends the idea of quaternion. Unit form is used to represent rigid transformations in 3D space.
     * Dual quaternion is a pair of two quaternions, extension of dual number.
     * @note Data structure : [rw, rx, ry, rz, dw, dx, dy, dz], (8 x 1)
     */
    template <typename Type>
    class DualQuaternion : public MatrixBase<8, 1, Type, DualQuaternion<Type>>
    {
    private:
        using MatrixBase<8, 1, Type, DualQuaternion<Type>>::data_;

    public:
        constexpr static ObjectType OBJECT_TYPE = ObjectType::DUAL_QUATERNION;

        /**
         * constructor
         */

        using MatrixBase<8, 1, Type, DualQuaternion<Type>>::MatrixBase;
        DualQuaternion() = default;
        DualQuaternion(const Type &rw, const Type &rx, const Type &ry, const Type &rz,
                       const Type &dw, const Type &dx, const Type &dy, const Type &dz)
            : MatrixBase<8, 1, Type, DualQuaternion<Type>>({rw, rx, ry, rz, dw, dx, dy, dz}) {}
        DualQuaternion(const Quaternion<Type> &r, const Quaternion<Type> &d)
            : MatrixBase<8, 1, Type, DualQuaternion<Type>>{{r.w(), r.x(), r.y(), r.z(), d.w(), d.x(), d.y(), d.z()}} {}
        DualQuaternion(const DualNumber<Type> &dn)
            : MatrixBase<8, 1, Type, DualQuaternion<Type>>{{dn[0], static_cast<Type>(0), static_cast<Type>(0), static_cast<Type>(0),
                                                            dn[1], static_cast<Type>(0), static_cast<Type>(0), static_cast<Type>(0)}} {}
        ~DualQuaternion() = default;

        /**
         * accessors
         */

        inline const Quaternion<Type> &Re() const { return reinterpret_cast<const Quaternion<Type> &>(data_[0]); }
        inline const Quaternion<Type> &Du() const { return reinterpret_cast<const Quaternion<Type> &>(data_[4]); }
        inline Quaternion<Type> &Re() { return reinterpret_cast<Quaternion<Type> &>(data_[0]); }
        inline Quaternion<Type> &Du() { return reinterpret_cast<Quaternion<Type> &>(data_[4]); }
        inline const Type &rw() const { return data_[0]; }
        inline const Type &rx() const { return data_[1]; }
        inline const Type &ry() const { return data_[2]; }
        inline const Type &rz() const { return data_[3]; }
        inline const Type &dw() const { return data_[4]; }
        inline const Type &dx() const { return data_[5]; }
        inline const Type &dy() const { return data_[6]; }
        inline const Type &dz() const { return data_[7]; }
        inline Type &rw() { return data_[0]; }
        inline Type &rx() { return data_[1]; }
        inline Type &ry() { return data_[2]; }
        inline Type &rz() { return data_[3]; }
        inline Type &dw() { return data_[4]; }
        inline Type &dx() { return data_[5]; }
        inline Type &dy() { return data_[6]; }
        inline Type &dz() { return data_[7]; }
        inline const Type &operator[](const size_t &idx) const { return data_[idx]; }
        inline Type &operator[](const size_t &idx) { return data_[idx]; }

        /**
         * operators
         */

        using MatrixBase<8, 1, Type, DualQuaternion<Type>>::operator*;
        using MatrixBase<8, 1, Type, DualQuaternion<Type>>::operator/;
        using MatrixBase<8, 1, Type, DualQuaternion<Type>>::operator*=;
        using MatrixBase<8, 1, Type, DualQuaternion<Type>>::operator/=;
        inline DualQuaternion<Type> operator*(const DualQuaternion<Type> &other) const /// dual quaternion multiplication
        {
            return DualQuaternion<Type>(Re() * other.Re(), Re() * other.Du() + Du() * other.Re());
        }
        inline DualQuaternion<Type> operator/(const DualQuaternion<Type> &other) const { return *this * other.inversed(); } /// dual quaternion division

        inline void operator*=(const DualQuaternion<Type> &q) { *this = *this * q; } /// dual quaternion multiplication

        inline void operator/=(const DualQuaternion<Type> &q) { *this = *this / q; } /// dual quaternion division

        inline DualQuaternion<Type> dualQuatMul(const DualQuaternion<Type> &dq) const { return *this * dq; } /// dual quaternion multiplication

        inline void dualQuatMulEq(const DualQuaternion<Type> &dq) { *this *= dq; } /// dual quaternion multiplication

        inline DualQuaternion<Type> dualQuatDiv(const DualQuaternion<Type> &dq) const { return *this / dq; } /// dual quaternion division

        inline void dualQuatDivEq(const DualQuaternion<Type> &dq) { *this /= dq; } /// dual quaternion division

        // /**
        //  * utils
        //  */

        inline DualQuaternion<Type> conjugatedPrimary() const /// qr + qd e => qr* + qd* e
        {
            return DualQuaternion<Type>{Re().conjugated(), Du().conjugated()};
        }
        inline void conjugatePrimary() { *this = conjugatedPrimary(); } /// qr + qd e => qr* + qd* e

        inline DualQuaternion<Type> conjugatedDual() const /// qr + qd e => qr - qd e
        {
            return DualQuaternion<Type>{Re(), -Du()};
        }
        inline void conjugateDual() { *this = conjugatedDual(); } /// qr + qd e => qr - qd e

        inline DualQuaternion<Type> conjugatedFull() const /// qr + qd e => qr* - qd* e
        {
            return DualQuaternion<Type>{Re().conjugated(), Quaternion<Type>{-Du().w(), Du().x(), Du().y(), Du().z()}};
        }
        inline void conjugateFull() { *this = conjugatedFull(); } /// qr + qd e => qr* - qd* e

        inline DualNumber<Type> normDualNum() const // original dual quaternion norm with primary conjugate
        {
            const Type re_norm = Re().norm();
            const Type du_dot = Re().w() * Du().w() + Re().x() * Du().x() + Re().y() * Du().y() + Re().z() * Du().z();
            return DualNumber<Type>{re_norm, du_dot / re_norm};
        }
        inline DualNumber<Type> normDualNumSquared() const ///  original dual quaternion norm squared with primary conjugate
        {
            const Type du_dot = Re().w() * Du().w() + Re().x() * Du().x() + Re().y() * Du().y() + Re().z() * Du().z();
            return DualNumber<Type>{Re().normSquared(), 2 * du_dot};
        }
        inline Type normScalar() const // dual quaternion norm, dual number norm again
        {
            return Re().norm();
        }
        inline Type normScalarSquared() const /// dual quaternion norm squared, dual number norm squared again
        {
            return Re().normSquared();
        }
        inline DualQuaternion<Type> inversed() const /// dual quaternion inverse
        {
            const Type re_normsq = Re().normSquared();
            const Type du_dot = Re().w() * Du().w() + Re().x() * Du().x() + Re().y() * Du().y() + Re().z() * Du().z();
            return DualQuaternion<Type>{Re().conjugated() / re_normsq,
                                        Du().conjugated() / re_normsq - Re().conjugated() * (2 * du_dot / (re_normsq * re_normsq))};
        }
        inline void inverse() { *this = inversed(); } /// dual quaternion inverse in place

        /**
         * @brief Dual Quaternion Normalization.
         * @details Using primary conjugate for norm.
         * Dual quaternion normalization can be derived from division by norm
         * Determine the real part for ordinary quaternion normlization.
         * Determine the dual part in closed-form solution,
         * ,which is 4 dimensional projection with scaled real part.
         * @return normalized dual quaternion
         */
        inline DualQuaternion<Type> normalized() const
        {
            const Quaternion<Type> re_normed = Re().normalized();
            const Type du_dot = re_normed.w() * Du().w() + re_normed.x() * Du().x() + re_normed.y() * Du().y() + re_normed.z() * Du().z();
            const Quaternion<Type> du_normed = Re().norm() * (Du() - du_dot * re_normed);
            return DualQuaternion<Type>{re_normed, du_normed};
        }
        inline void normalize() const { *this = normalized(); } /// dual quaternion normalization

        /**
         * static functions
         */

        /**
         * @brief zero dual quaternion
         */
        static DualQuaternion<Type> zeros() { return DualQuaternion<Type>(Quaternion<Type>::zeros(), Quaternion<Type>::zeros()); }

        /**
         * casts
         */

        /**
         * @brief dual quaternion to multiplication matrix
         */
        inline SquareMatrix<8, Type> toMulMatrix() const
        {

            const Type zero_ = static_cast<Type>(0);
            // | [r]_x    0  |
            // | [d]_x [r]_x |
            return SquareMatrix<8, Type>{{rw(), -rx(), -ry(), -rz(), zero_, zero_, zero_, zero_,
                                          rx(), +rw(), -rz(), +ry(), zero_, zero_, zero_, zero_,
                                          ry(), +rz(), +rw(), -rx(), zero_, zero_, zero_, zero_,
                                          rz(), -ry(), +rx(), +rw(), zero_, zero_, zero_, zero_,
                                          dw(), -dx(), -dy(), -dz(), +rw(), -rx(), -ry(), -rz(),
                                          dx(), +dw(), -dz(), +dy(), +rx(), +rw(), -rz(), +ry(),
                                          dy(), +dz(), +dw(), -dx(), +ry(), +rz(), +rw(), -rx(),
                                          dz(), -dy(), +dx(), +dw(), +rz(), -ry(), +rx(), +rw()}};
        }
        inline SquareMatrix<8, Type> toRightMulMatrix() const /// dual quaternion to multiplication matrix from right
        {
            const Type zero_ = static_cast<Type>(0);
            // | [r]_xr    0   |
            // | [d]_xr [r]_xr |
            return SquareMatrix<8, Type>{{rw(), -rx(), -ry(), -rz(), zero_, zero_, zero_, zero_,
                                          rx(), +rw(), +rz(), -ry(), zero_, zero_, zero_, zero_,
                                          ry(), -rz(), +rw(), +rx(), zero_, zero_, zero_, zero_,
                                          rz(), +ry(), -rx(), +rw(), zero_, zero_, zero_, zero_,
                                          dw(), -dx(), -dy(), -dz(), +rw(), -rx(), -ry(), -rz(),
                                          dx(), +dw(), +dz(), -dy(), +rx(), +rw(), +rz(), -ry(),
                                          dy(), -dz(), +dw(), +dx(), +ry(), -rz(), +rw(), +rx(),
                                          dz(), +dy(), -dx(), +dw(), +rz(), +ry(), -rx(), +rw()}};
        }
    };

    using DualQuaternionf = DualQuaternion<float>;
    using DualQuaterniond = DualQuaternion<double>;
    using DualQuaternionld = DualQuaternion<long double>;
}