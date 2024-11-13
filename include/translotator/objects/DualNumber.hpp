#pragma once

namespace translotator
{
    template <typename Type>
    class DualNumber : public MatrixBase<2, 1, Type, DualNumber<Type>>
    {
    public:
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
        inline SquareMatrix<2, Type> toMulMatrix() const
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

        /**
         * static functions
         */

        /**
         * utils
         */
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