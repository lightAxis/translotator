

# File DualNumber.hpp

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**translotator**](dir_ffa3503b73a46a1fbf73d754da62ba14.md) **>** [**objects**](dir_d5306d4012edd8106bd4452d9b4e4e98.md) **>** [**DualNumber.hpp**](DualNumber_8hpp.md)

[Go to the documentation of this file](DualNumber_8hpp.md)


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
 * @file : DualNumber.hpp
 */

#pragma once

namespace translotator
{
    template <typename Type>
    class DualNumber : public MatrixBase<2, 1, Type, DualNumber<Type>>
    {
    public:
        constexpr static ObjectType OBJECT_TYPE = ObjectType::DUAL_NUMBER;
        using MatrixBase<2, 1, Type, DualNumber<Type>>::MatrixBase;
        DualNumber() : MatrixBase<2, 1, Type, DualNumber<Type>>({static_cast<Type>(0), static_cast<Type>(0)}) {}
        DualNumber(const Type &r, const Type &d) : MatrixBase<2, 1, Type, DualNumber<Type>>({r, d}) {}
        inline Type Re() const { return this->data_[0]; }
        inline Type Du() const { return this->data_[1]; }
        inline Type &Re() { return this->data_[0]; }
        inline Type &Du() { return this->data_[1]; }
        inline Type operator[](size_t i) const { return this->data_[i]; }
        inline Type &operator[](size_t i) { return this->data_[i]; }

        inline SquareMatrix<2, Type> toMulMatrix() const 
        {
            return SquareMatrix<2, Type>{{Re(), static_cast<Type>(0),
                                          Du(), Re()}};
        }

        using MatrixBase<2, 1, Type, DualNumber<Type>>::operator*;
        using MatrixBase<2, 1, Type, DualNumber<Type>>::operator/;
        using MatrixBase<2, 1, Type, DualNumber<Type>>::operator*=;
        using MatrixBase<2, 1, Type, DualNumber<Type>>::operator/=;

        inline DualNumber<Type> operator*(const DualNumber<Type> &other) const 
        {
            return DualNumber<Type>{Re() * other.Re(),
                                    Re() * other.Du() + Du() * other.Re()};
        }
        inline DualNumber<Type> operator/(const DualNumber<Type> &other) const 
        {
            return DualNumber<Type>{Re() / other.Re(),
                                    (Du() * other.Re() - Re() * other.Du()) / (other.Re() * other.Re())};
        }
        inline void operator*=(const DualNumber<Type> &other) { *this = *this * other; } 

        inline void operator/=(const DualNumber<Type> &other) { *this = *this / other; } 

        inline DualNumber<Type> dualNumMul(const DualNumber<Type> &other) const { return *this * other; } 

        inline void dualNumMulEq(const DualNumber<Type> &other) { *this *= other; } 

        inline DualNumber<Type> dualNumDiv(const DualNumber<Type> &other) const { return *this / other; } 

        inline void dualNumDivEq(const DualNumber<Type> &other) { *this /= other; } 

        static inline DualNumber<Type> sqrt(const DualNumber<Type> &dn) 
        {
            const Type root = translotator::sqrt(dn.Re());
            return DualNumber<Type>{root, dn.Du() / (static_cast<Type>(2) * root)};
        }
        inline DualNumber<Type> conjugated() const { return DualNumber<Type>{Re(), -Du()}; } 

        inline void conjugate() { Du() = -Du(); } 

        inline Type normSquared() const { return Re() * Re(); } 

        inline Type norm() const { return translotator::abs(Re()); } 

        inline DualNumber<Type> normalized() const { return DualNumber<Type>{static_cast<Type>(1), Du() / Re()}; } 

        inline void normalize() { *this = normalized(); } 

        inline DualNumber<Type> inversed() const { return DualNumber<Type>{static_cast<Type>(1) / Re(), -Du() / (Re() * Re())}; } 
    };

    using DualNumberf = DualNumber<float>;
    using DualNumberd = DualNumber<double>;
    using DualNumberld = DualNumber<long double>;
}
```


