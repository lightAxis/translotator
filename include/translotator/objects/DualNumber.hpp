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
    /**
     * DualNumber
     * @tparam Type floating point type
     * @brief Represents a dual number.
     * @details A dual number is a pair of real numbers, where one is the real part and the other is the dual part.
     * The dual part is a number that squares to zero, i.e., e^2 = 0. It is used to represent infinitesimal quantities.
     * @note Data structure : [real, dual], (2 x 1)
     */
    template <typename Type>
    class DualNumber : public MatrixBase<2, 1, Type, DualNumber<Type>>
    {
    public:
        constexpr static ObjectType OBJECT_TYPE = ObjectType::DUAL_NUMBER;
        /**
         * constructor
         */
        using MatrixBase<2, 1, Type, DualNumber<Type>>::MatrixBase;
        DualNumber() : MatrixBase<2, 1, Type, DualNumber<Type>>({static_cast<Type>(0), static_cast<Type>(0)}) {}
        DualNumber(const Type &r, const Type &d) : MatrixBase<2, 1, Type, DualNumber<Type>>({r, d}) {}
        /**
         * accessors
         */
        inline Type Re() const { return this->data_[0]; }
        inline Type Du() const { return this->data_[1]; }
        inline Type &Re() { return this->data_[0]; }
        inline Type &Du() { return this->data_[1]; }
        inline Type operator[](size_t i) const { return this->data_[i]; }
        inline Type &operator[](size_t i) { return this->data_[i]; }

        /**
         * casts
         */
        inline SquareMatrix<2, Type> toMulMatrix() const /// return a 2x2 matrix that represents the multiplication of this dual number
        {
            return SquareMatrix<2, Type>{{Re(), static_cast<Type>(0),
                                          Du(), Re()}};
        }

        /**
         * operators
         */
        using MatrixBase<2, 1, Type, DualNumber<Type>>::operator*;
        using MatrixBase<2, 1, Type, DualNumber<Type>>::operator/;
        using MatrixBase<2, 1, Type, DualNumber<Type>>::operator*=;
        using MatrixBase<2, 1, Type, DualNumber<Type>>::operator/=;

        inline DualNumber<Type> operator*(const DualNumber<Type> &other) const /// return the multiplication of two dual numbers
        {
            return DualNumber<Type>{Re() * other.Re(),
                                    Re() * other.Du() + Du() * other.Re()};
        }
        inline DualNumber<Type> operator/(const DualNumber<Type> &other) const /// return the division of two dual numbers
        {
            return DualNumber<Type>{Re() / other.Re(),
                                    (Du() * other.Re() - Re() * other.Du()) / (other.Re() * other.Re())};
        }
        inline void operator*=(const DualNumber<Type> &other) { *this = *this * other; } /// multiply this dual number with another dual number

        inline void operator/=(const DualNumber<Type> &other) { *this = *this / other; } /// divide this dual number with another dual number

        inline DualNumber<Type> dualNumMul(const DualNumber<Type> &other) const { return *this * other; } /// return the multiplication of two dual numbers

        inline void dualNumMulEq(const DualNumber<Type> &other) { *this *= other; } /// multiply this dual number with another dual number

        inline DualNumber<Type> dualNumDiv(const DualNumber<Type> &other) const { return *this / other; } /// return the division of two dual numbers

        inline void dualNumDivEq(const DualNumber<Type> &other) { *this /= other; } /// divide this dual number with another dual number

        /**
         * static functions
         */
        static inline DualNumber<Type> sqrt(const DualNumber<Type> &dn) /// return the square root of a dual number. Re > 0 is required
        {
            const Type root = translotator::sqrt(dn.Re());
            return DualNumber<Type>{root, dn.Du() / (static_cast<Type>(2) * root)};
        }
        /**
         * utils
         */
        inline DualNumber<Type> conjugated() const { return DualNumber<Type>{Re(), -Du()}; } /// return the conjugate of this dual number

        inline void conjugate() { Du() = -Du(); } /// conjugate this dual number

        inline Type normSquared() const { return Re() * Re(); } /// return the squared norm of this dual number

        inline Type norm() const { return translotator::abs(Re()); } /// return the norm of this dual number

        inline DualNumber<Type> normalized() const { return DualNumber<Type>{static_cast<Type>(1), Du() / Re()}; } /// return a new DualNumber with normalized real part

        inline void normalize() { *this = normalized(); } /// normalize the real part of this dual number

        inline DualNumber<Type> inversed() const { return DualNumber<Type>{static_cast<Type>(1) / Re(), -Du() / (Re() * Re())}; } /// return the inverse of this dual number
    };

    using DualNumberf = DualNumber<float>;
    using DualNumberd = DualNumber<double>;
    using DualNumberld = DualNumber<long double>;
}