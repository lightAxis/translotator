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
 * @file : UnitComplexNum.hpp
 */

#pragma once

namespace translotator
{
    /***
     * @brief UnitComplexNum class
     * @tparam Type floating point type
     * @details UnitComplexNum is a class that represents a unit complex number.
     * It is a subclass of ComplexNum and has a unit length. It is used to represent a rotation in 2D space.
     */
    template <typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class UnitComplexNum : public ComplexNum<Type>
    {
    private:
        explicit UnitComplexNum(const ComplexNum<Type> &cplx) : ComplexNum<Type>(cplx) {}

    public:
        constexpr static ObjectType objType = ObjectType::UNIT_COMPLEX_NUM;
        using ComplexNum<Type>::ComplexNum;
        /**
         * constructors
         */

        inline UnitComplexNum() : ComplexNum<Type>(static_cast<Type>(1), static_cast<Type>(0)) {}
        explicit UnitComplexNum(const Type &angle) : ComplexNum<Type>(translotator::cos(angle), translotator::sin(angle)) {}

        /**
         * accessors
         */

        using ComplexNum<Type>::Re;
        using ComplexNum<Type>::Im;

        /**
         * operators
         */

        /**
         * @brief operator+ operator
         * @tparam OtherContainer other container matrix-base type
         */
        template <typename OtherContainer>
        inline ComplexNum<Type> operator+(const OtherContainer &other) const
        {
            static_assert(is_matrix_base_v<OtherContainer>, "Invalid type for operator+. Must have matrix base");
            return ComplexNum<Type>::operator+(other);
        }

        /**
         * @brief operator- operator
         * @tparam OtherContainer other container matrix-base type
         */
        template <typename OtherContainer>
        inline auto operator-(const OtherContainer &other) const
        {
            static_assert(is_matrix_base_v<OtherContainer>, "Invalid type for operator-. Must have matrix base");
            return ComplexNum<Type>::operator-(other);
        }

        /**
         * @brief operator* operator
         * @tparam OtherContainer other container matrix-base type
         * @note Unit * Unit = Unit,
         * @note Unit * Complex = Complex,
         * @note Unit * Type = Complex,
         * @note else, follows the matrix multiplication rule
         */
        template <typename OtherContainer>
        inline auto operator*(const OtherContainer &other) const
        {
            if constexpr (is_same_v<OtherContainer, UnitComplexNum<Type>>)
            {
                const ComplexNum<Type> &other_ = const_cast<UnitComplexNum<Type> *>(&other)->cast2ComplexNumRef();
                return UnitComplexNum<Type>{ComplexNum<Type>::operator*(other_)};
            }
            else if constexpr (is_same_v<OtherContainer, ComplexNum<Type>>)
            {
                return ComplexNum<Type>::operator*(other);
            }
            else if constexpr (is_same_v<OtherContainer, Type>)
            {
                return ComplexNum<Type>::operator*(other);
            }
            else
            {
                return ComplexNum<Type>::operator*(other);
            }
        }
        inline friend ComplexNum<Type> operator*(const ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs) /// Complex * Unit = Complex
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->cast2ComplexNumRef();
            return lhs * rhs_;
        }
        inline friend ComplexNum<Type> operator*(const Type &lhs, const UnitComplexNum<Type> &rhs) /// Type * Unit = Complex
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->cast2ComplexNumRef();
            return lhs * rhs_;
        }
        inline void operator*=(const UnitComplexNum<Type> &other) /// Unit * Unit = Unit
        {
            *this = *this * other;
        }
        inline friend void operator*=(ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs) /// Complex * Unit = Complex
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->cast2ComplexNumRef();
            lhs = lhs * rhs_;
        }

        inline UnitComplexNum<Type> complexNumMul(const UnitComplexNum<Type> &other) const { return *this * other; } // alias for operator* for readability

        inline ComplexNum<Type> complexNumMul(const ComplexNum<Type> &other) const { return *this * other; } /// alias for operator* for readability

        inline friend ComplexNum<Type> complexNumMul(const ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs) /// alias for operator* for readability
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->cast2ComplexNumRef();
            return lhs * rhs_;
        }
        inline void complexNumMulEq(const UnitComplexNum<Type> &other) { *this *= other; } // alias for operator*= for readability

        inline friend void complexNumMulEq(ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs) /// alias for operator*= for readability
        {
            lhs *= rhs.cast2ComplexNumRef();
        }

        /**
         * @brief operator/ operator
         * @tparam OtherContainer other container matrix-base type
         * @note Unit / Unit = Unit,
         * @note Unit / Complex = Complex,
         * @note Unit / Type = Complex,
         * @note else, follows the matrix multiplication rule
         */
        template <typename OtherContainer>
        inline auto operator/(const OtherContainer &other) const
        {
            if constexpr (is_same_v<OtherContainer, UnitComplexNum<Type>>)
            {
                return (*this) * other.conjugated();
            }
            else if constexpr (is_same_v<OtherContainer, ComplexNum<Type>>)
            {
                return ComplexNum<Type>::operator/(other);
            }
            else if constexpr (is_same_v<OtherContainer, Type>)
            {
                return ComplexNum<Type>::operator/(other);
            }
            else
            {
                static_assert(is_same_v<OtherContainer, UnitComplexNum<Type>> ||
                                  is_same_v<OtherContainer, ComplexNum<Type>> ||
                                  is_same_v<OtherContainer, Type>,
                              "Invalid type for operator/ must be UnitComplexNum, ComplexNum or Type");
                return Matrix<2, 1, Type>();
            }
        }
        inline friend ComplexNum<Type> operator/(const ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs) /// Complex / Unit = Complex
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->cast2ComplexNumRef();
            return lhs * rhs_.conjugated();
        }
        inline void operator/=(const UnitComplexNum<Type> &other) /// Unit / Unit = Unit
        {
            *this = *this / other;
        }
        inline friend void operator/=(ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs) /// Complex / Unit = Complex
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->cast2ComplexNumRef();
            lhs *= rhs_.conjugated();
        }
        inline UnitComplexNum<Type> complexNumDiv(const UnitComplexNum<Type> &other) const { return *this / other; } // alias for operator/ for readability

        inline ComplexNum<Type> complexNumDiv(const ComplexNum<Type> &other) const { return *this / other; } /// alias for operator/ for readability

        inline void complexNumDivEq(const UnitComplexNum<Type> &other) { *this /= other; } // alias for operator/= for readability

        inline friend void complexNumDivEq(ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs) /// alias for operator/= for readability
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->cast2ComplexNumRef();
            lhs *= rhs_.conjugated();
        }
        /**
         * utils
         */

        inline UnitComplexNum<Type> normalized() const /// return normalized unit complex number
        {
            return UnitComplexNum<Type>{ComplexNum<Type>::normalized()};
        }
        inline UnitComplexNum<Type> conjugated() const /// return conjugated unit complex number
        {
            return UnitComplexNum<Type>{ComplexNum<Type>::conjugated()};
        }
        inline UnitComplexNum<Type> inversed() const /// return inversed unit complex number. It is same as conjugated.
        {
            return conjugated();
        }
        inline void inverse() { *this = inversed(); } /// inverse this unit complex number

        inline Vector<2, Type> rotateVector2D(const Vector<2, Type> &v) const /// rotate 2D vector
        {
            return Vector<2, Type>{{Re() * v.x() - Im() * v.y(),
                                    Im() * v.x() + Re() * v.y()}};
        }
        inline UnitComplexNum<Type> pow(const Type t) const /// return this unit complex number to the power of t. Using Lie algebra.
        {
            using LieOp = lie::LieOperator<ObjectType::UNIT_COMPLEX_NUM, Type>;
            return LieOp::Exp(LieOp::Log(*this) * t);
        }

        /**
         * static functions
         */

        static inline UnitComplexNum<Type> identity() { return UnitComplexNum<Type>(static_cast<Type>(1), static_cast<Type>(0)); } /// return identity unit complex number

        /**
         * casting
         */

        inline SOGroup<2, Type> toRotMatrix2D() const /// return 2D rotation matrix
        {
            return SOGroup<2, Type>{{Re(), -Im(),
                                     Im(), Re()}};
        }
        inline AxisAngle<Type> toAxisAngle() const /// return axis angle representation
        {
            const Type angle = translotator::acos(Re());
            return AxisAngle<Type>{angle};
        }
        template <EULER_ORDER AxisOrder>
        inline EulerAngle<Type, AxisOrder> toEulerAngle2D() const /// return euler angle representation
        {
            const Type angle = translotator::acos(Re());
            return EulerAngle<Type, AxisOrder>{angle};
        }
    };

    using UnitComplexNumf = UnitComplexNum<float>;
    using UnitComplexNumd = UnitComplexNum<double>;
    using UnitComplexNumld = UnitComplexNum<long double>;

    using S1f = UnitComplexNumf;
    using S1d = UnitComplexNumd;
    using S1ld = UnitComplexNumld;
}