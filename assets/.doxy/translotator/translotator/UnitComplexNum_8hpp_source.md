

# File UnitComplexNum.hpp

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**translotator**](dir_ffa3503b73a46a1fbf73d754da62ba14.md) **>** [**objects**](dir_d5306d4012edd8106bd4452d9b4e4e98.md) **>** [**UnitComplexNum.hpp**](UnitComplexNum_8hpp.md)

[Go to the documentation of this file](UnitComplexNum_8hpp.md)


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
        inline UnitComplexNum() : ComplexNum<Type>(static_cast<Type>(1), static_cast<Type>(0)) {}
        explicit UnitComplexNum(const Type &angle) : ComplexNum<Type>(translotator::cos(angle), translotator::sin(angle)) {}

        using ComplexNum<Type>::Re;
        using ComplexNum<Type>::Im;

        template <typename OtherContainer>
        inline ComplexNum<Type> operator+(const OtherContainer &other) const
        {
            static_assert(is_matrix_base_v<OtherContainer>, "Invalid type for operator+. Must have matrix base");
            return ComplexNum<Type>::operator+(other);
        }

        template <typename OtherContainer>
        inline auto operator-(const OtherContainer &other) const
        {
            static_assert(is_matrix_base_v<OtherContainer>, "Invalid type for operator-. Must have matrix base");
            return ComplexNum<Type>::operator-(other);
        }

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
        inline friend ComplexNum<Type> operator*(const ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs) 
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->cast2ComplexNumRef();
            return lhs * rhs_;
        }
        inline friend ComplexNum<Type> operator*(const Type &lhs, const UnitComplexNum<Type> &rhs) 
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->cast2ComplexNumRef();
            return lhs * rhs_;
        }
        inline void operator*=(const UnitComplexNum<Type> &other) 
        {
            *this = *this * other;
        }
        inline friend void operator*=(ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs) 
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->cast2ComplexNumRef();
            lhs = lhs * rhs_;
        }

        inline UnitComplexNum<Type> complexNumMul(const UnitComplexNum<Type> &other) const { return *this * other; } // alias for operator* for readability

        inline ComplexNum<Type> complexNumMul(const ComplexNum<Type> &other) const { return *this * other; } 

        inline friend ComplexNum<Type> complexNumMul(const ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs) 
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->cast2ComplexNumRef();
            return lhs * rhs_;
        }
        inline void complexNumMulEq(const UnitComplexNum<Type> &other) { *this *= other; } // alias for operator*= for readability

        inline friend void complexNumMulEq(ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs) 
        {
            lhs *= rhs.cast2ComplexNumRef();
        }

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
        inline friend ComplexNum<Type> operator/(const ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs) 
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->cast2ComplexNumRef();
            return lhs * rhs_.conjugated();
        }
        inline void operator/=(const UnitComplexNum<Type> &other) 
        {
            *this = *this / other;
        }
        inline friend void operator/=(ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs) 
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->cast2ComplexNumRef();
            lhs *= rhs_.conjugated();
        }
        inline UnitComplexNum<Type> complexNumDiv(const UnitComplexNum<Type> &other) const { return *this / other; } // alias for operator/ for readability

        inline ComplexNum<Type> complexNumDiv(const ComplexNum<Type> &other) const { return *this / other; } 

        inline void complexNumDivEq(const UnitComplexNum<Type> &other) { *this /= other; } // alias for operator/= for readability

        inline friend void complexNumDivEq(ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs) 
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->cast2ComplexNumRef();
            lhs *= rhs_.conjugated();
        }
        inline UnitComplexNum<Type> normalized() const 
        {
            return UnitComplexNum<Type>{ComplexNum<Type>::normalized()};
        }
        inline UnitComplexNum<Type> conjugated() const 
        {
            return UnitComplexNum<Type>{ComplexNum<Type>::conjugated()};
        }
        inline UnitComplexNum<Type> inversed() const 
        {
            return conjugated();
        }
        inline void inverse() { *this = inversed(); } 

        inline Vector<2, Type> rotateVector2D(const Vector<2, Type> &v) const 
        {
            return Vector<2, Type>{{Re() * v.x() - Im() * v.y(),
                                    Im() * v.x() + Re() * v.y()}};
        }
        inline UnitComplexNum<Type> pow(const Type t) const 
        {
            using LieOp = lie::LieOperator<ObjectType::UNIT_COMPLEX_NUM, Type>;
            return LieOp::Exp(LieOp::Log(*this) * t);
        }

        static inline UnitComplexNum<Type> identity() { return UnitComplexNum<Type>(static_cast<Type>(1), static_cast<Type>(0)); } 

        inline SOGroup<2, Type> toRotMatrix2D() const 
        {
            return SOGroup<2, Type>{{Re(), -Im(),
                                     Im(), Re()}};
        }
        inline AxisAngle<Type> toAxisAngle() const 
        {
            const Type angle = translotator::acos(Re());
            return AxisAngle<Type>{angle};
        }
        template <EULER_ORDER AxisOrder>
        inline EulerAngle<Type, AxisOrder> toEulerAngle2D() const 
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
```

