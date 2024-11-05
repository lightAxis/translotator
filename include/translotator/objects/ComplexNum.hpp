#pragma once

namespace translotator
{
    template <typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class ComplexNum : public MatrixBase<2, 1, Type, ComplexNum<Type>>
    {
    public:
        using MatrixBase<2, 1, Type, ComplexNum<Type>>::MatrixBase;

        /**
         * constructors
         */
        // [Re, Im]
        inline ComplexNum() : MatrixBase<2, 1, Type, ComplexNum<Type>>({static_cast<Type>(0), static_cast<Type>(0)}) {}
        explicit inline ComplexNum(Type real, Type imag) : MatrixBase<2, 1, Type, ComplexNum<Type>>({real, imag}) {}

        /**
         * accessors
         */
        inline Type Re() const { return this->data_[0]; }
        inline Type Im() const { return this->data_[1]; }
        inline Type &Re() { return this->data_[0]; }
        inline Type &Im() { return this->data_[1]; }

        inline Type operator[](size_t i) const { return this->data_[i]; }
        inline Type &operator[](size_t i) { return this->data_[i]; }

        /**
         * operators
         */

        inline ComplexNum<Type> operator*(const ComplexNum<Type> &c) const
        {
            return ComplexNum<Type>(Re() * c.Re() - Im() * c.Im(),
                                    Re() * c.Im() + Im() * c.Re());
        }
        inline ComplexNum<Type> operator/(const ComplexNum<Type> &c) const
        {
            const Type den = c.normSquared();
            return ComplexNum<Type>((Re() * c.Re() + Im() * c.Im()) / den,
                                    (Im() * c.Re() - Re() * c.Im()) / den);
        }
        inline void operator*=(const ComplexNum<Type> &c) { *this = *this * c; }
        inline void operator/=(const ComplexNum<Type> &c) { *this = *this / c; }
        inline ComplexNum<Type> complexNumMul(const ComplexNum<Type> &c) const { return *this * c; } // alias for operator* for readability
        inline void complexNumMulEq(const ComplexNum<Type> &c) { *this *= c; }                       // alias for operator*= for readability
        inline ComplexNum<Type> complexNumDiv(const ComplexNum<Type> &c) const { return *this / c; } // alias for operator/ for readability
        inline void complexNumDivEq(const ComplexNum<Type> &c) { *this /= c; }                       // alias for operator/= for readability

        using MatrixBase<2, 1, Type, ComplexNum<Type>>::operator*;
        using MatrixBase<2, 1, Type, ComplexNum<Type>>::operator/;
        using MatrixBase<2, 1, Type, ComplexNum<Type>>::operator*=;
        using MatrixBase<2, 1, Type, ComplexNum<Type>>::operator/=;

        /**
         * utils
         */
        inline Type normSquared() const { return this->frobeniusNormSquared(); }
        inline Type norm() const { return this->frobeniusNorm(); }
        inline ComplexNum<Type> normalized() const { return *this / norm(); }
        inline void normalize() { *this = normalized(); }
        inline ComplexNum<Type> conjugated() const { return ComplexNum<Type>(Re(), -Im()); }
        inline void conjugate() { *this = conjugated(); }
        inline ComplexNum<Type> inversed() const { return conjugated() / normSquared(); }
        inline void inverse() { *this = inversed(); }

        /**
         * casting
         */
        inline SquareMatrix<2, Type> toMulMatrix() const
        {
            return SquareMatrix<2, Type>{{Re(), -Im(),
                                          Im(), Re()}};
        }
    };

    using ComplexNumf = ComplexNum<float>;
    using ComplexNumd = ComplexNum<double>;
    using ComplexNumld = ComplexNum<long double>;

}