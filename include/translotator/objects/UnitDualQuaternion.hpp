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
 * @file : UnitDualQuaternion.hpp
 */

#pragma once

namespace translotator
{
    /**
     * @brief Represents a unit dual quaternion
     * @tparam Type floating point type
     * @details UnitDualQuaternion is a class that represents a unit dual quaternion.
     * It is a subclass of DualQuaternion and has a unit length. It is used to represent a rigid transformation in 3D space.
     *
     */
    template <typename Type>
    class UnitDualQuaternion : public DualQuaternion<Type>
    {
    private:
        explicit UnitDualQuaternion(const DualQuaternion<Type> &dq)
            : DualQuaternion<Type>(dq) {}

    public:
        constexpr static ObjectType OBJECT_TYPE = ObjectType::UNIT_DUAL_QUATERNION;
        using DualQuaternion<Type>::DualQuaternion;

        /**
         * constructors
         */

        inline UnitDualQuaternion() : DualQuaternion<Type>(static_cast<Type>(1),
                                                           static_cast<Type>(0),
                                                           static_cast<Type>(0),
                                                           static_cast<Type>(0),
                                                           static_cast<Type>(0),
                                                           static_cast<Type>(0),
                                                           static_cast<Type>(0),
                                                           static_cast<Type>(0)) {}
        inline UnitDualQuaternion(const UnitQuaternion<Type> &re, const Quaternion<Type> &du)
            : DualQuaternion<Type>(re, du) {}
        inline UnitDualQuaternion(const UnitQuaternion<Type> &rot, const Vector<3, Type> &t)
            : DualQuaternion<Type>(rot, Quaternion<Type>{static_cast<Type>(0), static_cast<Type>(0.5) * t} * rot) {}
        /**
         * accessors
         */

        inline const UnitQuaternion<Type> &Re() const /// return real part of unit dual quaternion, UnitQuaternion
        {
            return reinterpret_cast<const UnitQuaternion<Type> &>(DualQuaternion<Type>::Re());
        }
        inline UnitQuaternion<Type> &Re() { return reinterpret_cast<UnitQuaternion<Type> &>(DualQuaternion<Type>::Re()); }
        using DualQuaternion<Type>::Du;
        using DualQuaternion<Type>::rw;
        using DualQuaternion<Type>::rx;
        using DualQuaternion<Type>::ry;
        using DualQuaternion<Type>::rz;
        using DualQuaternion<Type>::dw;
        using DualQuaternion<Type>::dx;
        using DualQuaternion<Type>::dy;
        using DualQuaternion<Type>::dz;

        /**
         * operators
         */

        /**
         * @brief operator+ operator
         * @tparam OtherContainer other container matrix-base type
         * @details This operator is used to add two dual quaternions.
         */
        template <typename OtherContainer>
        inline DualQuaternion<Type> operator+(const OtherContainer &other) const
        {
            return DualQuaternion<Type>::operator+(other);
        }

        /**
         * @brief operator- operator
         * @tparam OtherContainer other container matrix-base type
         * @details This operator is used to subtract two dual quaternions.
         */
        template <typename OtherContainer>
        inline DualQuaternion<Type> operator-(const OtherContainer &other) const
        {
            return DualQuaternion<Type>::operator-(other);
        }

        /**
         * @brief operator* operator
         * @tparam OtherContainer other container matrix-base type
         * @note Unit * Unit = Unit,
         * @note Unit * Dual = Dual,
         * @note Unit * Type = Dual,
         * @note else, follows the matrix multiplication rule
         */
        template <typename OtherContainer>
        inline auto operator*(const OtherContainer &other) const
        {
            if constexpr (is_same_v<OtherContainer, UnitDualQuaternion<Type>>)
            {
                const DualQuaternion<Type> &other_ = const_cast<UnitDualQuaternion<Type> *>(&other)->cast2DualQuaternionRef();
                return UnitDualQuaternion<Type>{DualQuaternion<Type>::operator*(other_)};
            }
            else if constexpr (is_same_v<OtherContainer, DualQuaternion<Type>>)
            {
                return DualQuaternion<Type>::operator*(other);
            }
            else if constexpr (is_same_v<OtherContainer, Type>)
            {
                return DualQuaternion<Type>::operator*(other);
            }
            else
            {
                return Matrix<8, 1, Type>();
            }
        }
        inline friend DualQuaternion<Type> operator*(const DualQuaternion<Type> &lhs, const UnitDualQuaternion<Type> &rhs) /// Dual * Unit = Dual
        {
            const DualQuaternion<Type> &rhs_ = const_cast<UnitDualQuaternion<Type> *>(&rhs)->cast2DualQuaternionRef();
            return lhs * rhs_;
        }
        inline friend DualQuaternion<Type> operator*(const Type &lhs, const UnitDualQuaternion<Type> &rhs) /// Type * Unit = Dual
        {
            const DualQuaternion<Type> &rhs_ = const_cast<UnitDualQuaternion<Type> *>(&rhs)->cast2DualQuaternionRef();
            return lhs * rhs_;
        }
        inline void operator*=(const UnitDualQuaternion<Type> &other) /// Unit * Unit = Unit
        {
            *this = *this * other;
        }
        inline friend void operator*=(DualQuaternion<Type> &lhs, const UnitDualQuaternion<Type> &rhs) /// Dual * Unit = Dual
        {
            const DualQuaternion<Type> &rhs_ = const_cast<UnitDualQuaternion<Type> *>(&rhs)->cast2DualQuaternionRef();
            lhs *= rhs_;
        }
        inline UnitDualQuaternion<Type> dualQuatMul(const UnitDualQuaternion<Type> &other) const { return (*this) * other; } // alias for operator* for readability

        inline DualQuaternion<Type> dualQuatMul(const DualQuaternion<Type> &other) const { return (*this) * other; } /// alias for operator* for readability

        inline friend DualQuaternion<Type> dualQuatMul(const DualQuaternion<Type> &lhs, const UnitDualQuaternion<Type> &rhs) /// alias for operator* for readability
        {
            const DualQuaternion<Type> &rhs_ = const_cast<UnitDualQuaternion<Type> *>(&rhs)->cast2DualQuaternionRef();
            return lhs * rhs_;
        }
        inline void dualQuatMulEq(const UnitDualQuaternion<Type> &other) { *this *= other; } // alias for operator*= for readability

        inline friend void dualQuatMulEq(DualQuaternion<Type> &lhs, const UnitDualQuaternion<Type> &rhs) /// alias for operator*= for readability
        {
            lhs *= rhs.cast2DualQuaternionRef();
        }

        /**
         * @brief operator/ operator
         * @tparam OtherContainer other container matrix-base type
         * @note Unit / Unit = Unit,
         * @note Unit / Dual = Dual,
         * @note Unit / Type = Dual,
         * @note else, follows the matrix multiplication rule
         */
        template <typename OtherContainer>
        inline auto operator/(const OtherContainer &other) const
        {
            if constexpr (is_same_v<OtherContainer, UnitDualQuaternion<Type>>)
            {
                return (*this) * other.inversed();
            }
            else if constexpr (is_same_v<OtherContainer, DualQuaternion<Type>>)
            {
                return DualQuaternion<Type>::operator/(other);
            }
            else if constexpr (is_same_v<OtherContainer, Type>)
            {
                return DualQuaternion<Type>::operator/(other);
            }
            else
            {
                static_assert(is_same_v<OtherContainer, UnitDualQuaternion<Type>> ||
                                  is_same_v<OtherContainer, DualQuaternion<Type>>,
                              "Invalid type for operator/ must be UnitDualQuaternion or Quaternion");
                return Matrix<8, 1, Type>();
            }
        }
        inline friend DualQuaternion<Type> operator/(const DualQuaternion<Type> &lhs, const UnitDualQuaternion<Type> &rhs) /// Dual / Unit = Dual
        {
            const DualQuaternion<Type> &rhs_ = const_cast<UnitDualQuaternion<Type> *>(&rhs)->cast2DualQuaternionRef();
            return lhs * rhs_.inversed();
        }
        inline void operator/=(const UnitDualQuaternion<Type> &other) /// Unit / Unit = Unit
        {
            *this = *this / other;
        }
        inline friend void operator/=(DualQuaternion<Type> &lhs, const UnitDualQuaternion<Type> &rhs) /// Dual / Unit = Dual
        {
            const DualQuaternion<Type> &rhs_ = const_cast<UnitDualQuaternion<Type> *>(&rhs)->cast2DualQuaternionRef();
            lhs *= rhs_.inversed();
        }
        inline UnitDualQuaternion<Type> dualQuatDiv(const UnitDualQuaternion<Type> &other) const { return (*this) / other; } // alias for operator/ for readability

        inline DualQuaternion<Type> dualQuatDiv(const DualQuaternion<Type> &other) const { return (*this) / other; } /// alias for operator/ for readability

        inline void dualQuatDivEq(const UnitDualQuaternion<Type> &other) { *this /= other; } // alias for operator/= for readability

        inline friend void dualQuatDivEq(DualQuaternion<Type> &lhs, const UnitDualQuaternion<Type> &rhs) /// alias for operator/= for readability
        {
            const DualQuaternion<Type> &rhs_ = const_cast<UnitDualQuaternion<Type> *>(&rhs)->cast2DualQuaternionRef();
            lhs *= rhs_.inversed();
        }

        /**
         * utils
         */
        inline UnitDualQuaternion<Type> normalized() const /// return normalized unit dual quaternion
        {
            return UnitDualQuaternion<Type>(DualQuaternion<Type>::normalized());
        }
        inline void normalize() { *this = normalized(); } /// normalize unit dual quaternion

        inline UnitDualQuaternion<Type> conjugated() const /// return conjugated unit dual quaternion. Primary conjugated.
        {
            return UnitDualQuaternion<Type>(DualQuaternion<Type>::conjugatedPrimary());
        }

        inline void conjugate() { *this = conjugated(); } /// conjugate unit dual quaternion

        inline UnitDualQuaternion<Type> inversed() const /// return inversed unit dual quaternion. It is same as conjugated.
        {
            return conjugated();
        }

        inline void inverse() { *this = inversed(); } /// inverse this unit dual quaternion

        inline Vector<2, Type> actOnVector2D(const Vector<2, Type> &v) const /// act on 2D vector
        {
            return Re().rotateVector2D(v) + toTranslationVec2D();
        }
        inline Vector<3, Type> actOnVector3D(const Vector<3, Type> &v) const /// act on 3D vector
        {
            // 1. dv = 1+q_vE
            // 2. d dv d* = 1 + q_v'E. (full conjugated)

            return Re().rotateVector3D(v) + toTranslationVec3D();
        }

        /**
         * static functions
         */

        /**
         * @brief identity unit dual quaternion
         */
        static inline UnitDualQuaternion<Type> identity() { return UnitDualQuaternion<Type>{UnitQuaternion<Type>::identity(), Quaternion<Type>::zeros()}; }

        /**
         * casting
         */

        inline SEGroup<2, Type> toSE2Group() const /// convert to SE(2) group, Using only z axis rotation
        {
            return SEGroup<2, Type>{Re().toRotMatrix2D(), toTranslationVec2D()};
        }

        inline SEGroup<3, Type> toSE3Group() const /// convert to SE(3) group
        {
            return SEGroup<3, Type>{Re().toRotMatrix3D(), toTranslationVec3D()};
        }

        inline Vector<2, Type> toTranslationVec2D() const /// return translation vector in 2D
        {
            return Vector<2, Type>{{2 * (rw() * dx() - rz() * dy()), 2 * (rz() * dx() + rw() * dy())}};
        }

        inline Vector<3, Type> toTranslationVec3D() const /// return translation vector in 3D
        {
            return 2 * (Du() * Re().inversed()).Im();
        }
    };

    using UnitDualQuaternionf = UnitDualQuaternion<float>;
    using UnitDualQuaterniond = UnitDualQuaternion<double>;
    using UnitDualQuaternionld = UnitDualQuaternion<long double>;
}