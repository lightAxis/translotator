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
 * @file : UnitQuaternion.hpp
 */

#pragma once

namespace translotator
{
    /**
     * @brief UnitQuaternion class
     * @tparam Type floating point type
     * @details UnitQuaternion class is a class that represents a unit quaternion.
     * A unit quaternion is a quaternion that has a length of 1.
     */
    template <typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class UnitQuaternion : public Quaternion<Type>
    {
    private:
        explicit UnitQuaternion(const Quaternion<Type> &quat) : Quaternion<Type>(quat) {}

    public:
        constexpr static ObjectType OBJECT_TYPE = ObjectType::UNIT_QUATERNION;
        using Quaternion<Type>::Quaternion;

        /**
         * constructors
         */
        inline UnitQuaternion() : Quaternion<Type>(static_cast<Type>(1),
                                                   static_cast<Type>(0),
                                                   static_cast<Type>(0),
                                                   static_cast<Type>(0)) {}
        inline UnitQuaternion(const Vector<3, Type> &angleVec) : Quaternion<Type>(AxisAngle<Type>{angleVec}.toUnitQuaternion()) {}

        /**
         * accessors
         */
        using Quaternion<Type>::Re;
        using Quaternion<Type>::Im;
        using Quaternion<Type>::w;
        using Quaternion<Type>::x;
        using Quaternion<Type>::y;
        using Quaternion<Type>::z;

        /**
         * operators
         */

        /**
         * @brief operator+ operator
         * @tparam OtherContainer other container matrix-base type
         */
        template <typename OtherContainer>
        inline Quaternion<Type> operator+(const OtherContainer &other) const
        {
            static_assert(is_matrix_base_v<OtherContainer>, "Invalid type for operator+. Must have matrix base");
            return Quaternion<Type>::operator+(other);
        }

        /**
         * @brief operator- operator
         * @tparam OtherContainer other container matrix-base type
         */
        template <typename OtherContainer>
        inline Quaternion<Type> operator-(const OtherContainer &other) const
        {
            static_assert(is_matrix_base_v<OtherContainer>, "Invalid type for operator-. Must have matrix base");
            return Quaternion<Type>::operator-(other);
        }

        /**
         * @brief operator* operator
         * @tparam OtherContainer other container matrix-base type
         * @details This operator is used to multiply two quaternions.
         * @note Unit * Unit = Unit,
         * @note Unit * Quaternion = Quaternion,
         * @note Unit * Type = Quaternion,
         * @note else, follows the matrix multiplication rule
         */
        template <typename OtherContainer>
        inline auto operator*(const OtherContainer &other) const
        {
            if constexpr (is_same_v<OtherContainer, UnitQuaternion<Type>>)
            {
                const Quaternion<Type> &other_ = const_cast<UnitQuaternion<Type> *>(&other)->cast2QuaternionRef();
                return UnitQuaternion<Type>{Quaternion<Type>::operator*(other_)};
            }
            else if constexpr (is_same_v<OtherContainer, Quaternion<Type>>)
            {
                return Quaternion<Type>::operator*(other);
            }
            else if constexpr (is_same_v<OtherContainer, Type>)
            {
                return Quaternion<Type>::operator*(other);
            }
            else
            {
                return Quaternion<Type>::operator*(other);
            }
        }
        inline friend Quaternion<Type> operator*(const Quaternion<Type> &lhs, const UnitQuaternion<Type> &rhs) /// Quaternion * Unit = Quaternion
        {
            const Quaternion<Type> &rhs_ = const_cast<UnitQuaternion<Type> *>(&rhs)->cast2QuaternionRef();
            return lhs * rhs_;
        }
        inline friend Quaternion<Type> operator*(const Type &lhs, const UnitQuaternion<Type> &rhs) /// Type * Unit = Quaternion
        {
            const Quaternion<Type> &rhs_ = const_cast<UnitQuaternion<Type> *>(&rhs)->cast2QuaternionRef();
            return lhs * rhs_;
        }
        inline void operator*=(const UnitQuaternion<Type> &other) /// Unit * Unit = Unit
        {
            *this = *this * other;
        }
        inline friend void operator*=(Quaternion<Type> &lhs, const UnitQuaternion<Type> &rhs) /// Unit * Unit = Unit
        {
            const Quaternion<Type> &rhs_ = const_cast<UnitQuaternion<Type> *>(&rhs)->cast2QuaternionRef();
            lhs *= rhs_;
        }
        inline UnitQuaternion<Type> quatNumMul(const UnitQuaternion<Type> &other) const { return (*this) * other; } /// alias for operator* for readability

        inline Quaternion<Type> quatNumMul(const Quaternion<Type> &other) const { return (*this) * other; } /// alias for operator* for readability

        inline friend Quaternion<Type> quatNumMul(const Quaternion<Type> &lhs, const UnitQuaternion<Type> &rhs) /// alias for operator* for readability
        {
            const Quaternion<Type> &rhs_ = const_cast<UnitQuaternion<Type> *>(&rhs)->cast2QuaternionRef();
            return lhs * rhs_;
        }
        inline void quatNumMulEq(const UnitQuaternion<Type> &other) { *this *= other; } /// alias for operator*= for readability

        inline friend void quatNumMulEq(Quaternion<Type> &lhs, const UnitQuaternion<Type> &rhs) /// alias for operator*= for readability
        {
            lhs *= rhs.cast2QuaternionRef();
        }

        /**
         * @brief operator/ operator
         * @tparam OtherContainer other container matrix-base type
         * @details This operator is used to divide two quaternions.
         * @note Unit / Unit = Unit,
         * @note Unit / Quaternion = Quaternion,
         * @note Unit / Type = Quaternion,
         * @note else, follows the matrix multiplication rule
         */
        template <typename OtherContainer>
        inline auto operator/(const OtherContainer &other) const
        {
            if constexpr (is_same_v<OtherContainer, UnitQuaternion<Type>>)
            {
                return (*this) * other.conjugated();
            }
            else if constexpr (is_same_v<OtherContainer, Quaternion<Type>>)
            {
                return Quaternion<Type>::operator/(other);
            }
            else if constexpr (is_same_v<OtherContainer, Type>)
            {
                return Quaternion<Type>::operator/(other);
            }
            else
            {
                static_assert(is_same_v<OtherContainer, UnitQuaternion<Type>> ||
                                  is_same_v<OtherContainer, Quaternion<Type>> ||
                                  is_same_v<OtherContainer, Type>,
                              "Invalid type for operator/ must be UnitQuaternion, Quaternion or Type");
                return Matrix<4, 1, Type>();
            }
        }
        inline friend Quaternion<Type> operator/(const Quaternion<Type> &lhs, const UnitQuaternion<Type> &rhs) /// Quaternion / Unit = Quaternion
        {
            const Quaternion<Type> &rhs_ = const_cast<UnitQuaternion<Type> *>(&rhs)->cast2QuaternionRef();
            return lhs * rhs_.conjugated();
        }
        inline void operator/=(const UnitQuaternion<Type> &other) /// Unit / Unit = Unit
        {
            *this = *this / other;
        }
        inline friend void operator/=(Quaternion<Type> &lhs, const UnitQuaternion<Type> &rhs) /// Quaternion / Unit = Quaternion
        {
            const Quaternion<Type> &rhs_ = const_cast<UnitQuaternion<Type> *>(&rhs)->cast2QuaternionRef();
            lhs *= rhs_.conjugated();
        }
        inline UnitQuaternion<Type> quatNumDiv(const UnitQuaternion<Type> &other) const { return (*this) / other; } /// alias for operator/ for readability

        inline Quaternion<Type> quatNumDiv(const Quaternion<Type> &other) const { return (*this) / other; } /// alias for operator/ for readability

        inline void quatNumDivEq(const UnitQuaternion<Type> &other) { *this /= other; } /// alias for operator/= for readability

        inline friend void quatNumDivEq(Quaternion<Type> &lhs, const UnitQuaternion<Type> &rhs) /// alias for operator/= for readability
        {
            const Quaternion<Type> &rhs_ = const_cast<UnitQuaternion<Type> *>(&rhs)->cast2QuaternionRef();
            lhs *= rhs_.conjugated();
        }

        /**
         * utils
         */

        inline UnitQuaternion<Type> normalized() const /// return normalized unit quaternion
        {
            return UnitQuaternion<Type>(Quaternion<Type>::normalized());
        }
        inline UnitQuaternion<Type> conjugated() const /// return conjugated unit quaternion. Primary conjugated.
        {
            return UnitQuaternion<Type>(Quaternion<Type>::conjugated());
        }
        inline UnitQuaternion<Type> inversed() const /// return inversed unit quaternion. It is same as conjugated.
        {
            return conjugated();
        }
        inline void inverse() { *this = inversed(); } /// inverse this unit quaternion

        inline Vector<3, Type> rotateVector3D(const Vector<3, Type> &v) const /// rotate 3D vector
        {
            const Quaternion<Type> qv{static_cast<Type>(0), v};
            const Quaternionf q_res = ((*this) * qv * conjugated());
            return q_res.Im();
        }
        inline Vector<2, Type> rotateVector2D(const Vector<2, Type> &v) const /// rotate 2D vector. Using only w, z component.
        {
            const Type angle = static_cast<Type>(2) * translotator::acos(w());
            const Type c = translotator::cos(angle);
            const Type s = translotator::sin(angle);
            return Vector<2, Type>{{c * v.x() - s * v.y(),
                                    s * v.x() + c * v.y()}};
        }
        inline UnitQuaternion<Type> canonicalized() const /// return canonicalized unit quaternion. if w < 0, negate all components.
        {
            return UnitQuaternion<Type>(Quaternion<Type>::canonicalized());
        }
        inline void canonicalize() { *this = canonicalized(); } /// canonicalize this unit quaternion

        inline UnitQuaternion<Type> pow(const Type &t) const /// return t-th power of this unit quaternion. Using Lie operation Exp, Log
        {
            using LieOp = lie::LieOperator<ObjectType::UNIT_QUATERNION, Type>;
            return LieOp::Exp(LieOp::Log(*this) * t);
        }

        /**
         * static functions
         */

        /**
         * @brief identity unit quaternion
         */
        static inline UnitQuaternion<Type> identity() { return UnitQuaternion<Type>(static_cast<Type>(1), static_cast<Type>(0), static_cast<Type>(0), static_cast<Type>(0)); }

        /**
         * @brief axis rotation unit quaternion
         * @tparam Axis axis to rotate
         */
        template <AXIS Axis>
        static inline UnitQuaternion<Type> axisRotation(const Type &angle)
        { // TODO add test code for this
            const Type half_angle = angle / static_cast<Type>(2);
            const Type c = translotator::cos(half_angle);
            const Type s = translotator::sin(half_angle);
            if constexpr (Axis == AXIS::X)
                return UnitQuaternion<Type>{c, s, static_cast<Type>(0), static_cast<Type>(0)};
            else if constexpr (Axis == AXIS::Y)
                return UnitQuaternion<Type>{c, static_cast<Type>(0), s, static_cast<Type>(0)};
            else if constexpr (Axis == AXIS::Z)
                return UnitQuaternion<Type>{c, static_cast<Type>(0), static_cast<Type>(0), s};
            else
                static_assert(Axis == AXIS::X || Axis == AXIS::Y || Axis == AXIS::Z, "Invalid Axis");
        }

        /**
         * casting
         */

        inline SOGroup<2, Type> toRotMatrix2D() const /// convert to SO(2) group, Using only z axis rotation
        {
            const Type angle = static_cast<Type>(2) * translotator::acos(w());
            const Type c = translotator::cos(angle);
            const Type s = translotator::sin(angle);
            return SOGroup<2, Type>{{+c, -s,
                                     +s, +c}};
        }
        inline SOGroup<3, Type> toRotMatrix3D() const /// convert to SO(3) group
        {
            const Type xx = x() * x();
            const Type xy = x() * y();
            const Type xz = x() * z();
            const Type xw = x() * w();
            const Type yy = y() * y();
            const Type yz = y() * z();
            const Type yw = y() * w();
            const Type zz = z() * z();
            const Type zw = z() * w();
            return SOGroup<3, Type>{{1 - 2 * (yy + zz), 2 * (xy - zw), 2 * (xz + yw),
                                     2 * (xy + zw), 1 - 2 * (xx + zz), 2 * (yz - xw),
                                     2 * (xz - yw), 2 * (yz + xw), 1 - 2 * (xx + yy)}};
        }
        inline AxisAngle<Type> toAxisAngle() const /// convert to axis angle
        {
            const Type angle = static_cast<Type>(2) * translotator::acos(w());
            if (translotator::abs(angle) < translotator::epsilon<Type>())
            {
                return AxisAngle<Type>::identity();
            }

            return AxisAngle<Type>{angle, Im() / translotator::sin(angle / static_cast<Type>(2))};
        }

        /**
         * @brief convert to euler angle
         * @tparam AxisOrder euler angle order
         * @note Using only z axis rotation
         */
        template <EULER_ORDER AxisOrder>
        inline EulerAngle<Type, AxisOrder> toEulerAngle2D() const
        {
            return toRotMatrix2D().template toEulerAngle<AxisOrder>();
        }

        /**
         * @brief convert to euler angle
         * @tparam NewOrder euler angle order
         */
        template <EULER_ORDER NewOrder>
        inline EulerAngle<Type, NewOrder> toEulerAngle3D() const
        {
            return toRotMatrix3D().template toEulerAngle<NewOrder>();
        }

    private:
    };

    using UnitQuaternionf = UnitQuaternion<float>;
    using UnitQuaterniond = UnitQuaternion<double>;
    using UnitQuaternionld = UnitQuaternion<long double>;

    using S3f = UnitQuaternionf;
    using S3d = UnitQuaterniond;
    using S3ld = UnitQuaternionld;
}