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
        explicit inline ComplexNum(const Vector<2, Type> &v) : MatrixBase<2, 1, Type, ComplexNum<Type>>({v[0], v[1]}) {}

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
        using MatrixBase<2, 1, Type, ComplexNum<Type>>::operator*;
        using MatrixBase<2, 1, Type, ComplexNum<Type>>::operator/;
        using MatrixBase<2, 1, Type, ComplexNum<Type>>::operator*=;
        using MatrixBase<2, 1, Type, ComplexNum<Type>>::operator/=;

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
        inline Vector<2, Type> rotateVector2D(const Vector<2, Type> &v) const
        {
            return Vector<2, Type>{{Re() * v.x() - Im() * v.y(),
                                    Im() * v.x() + Re() * v.y()}};
        }

        /**
         * casting
         */
        inline SquareMatrix<2, Type> toMulMatrix() const
        {
            return SquareMatrix<2, Type>{{Re(), -Im(),
                                          Im(), Re()}};
        }
        inline SquareMatrix<2, Type> toRotMatrix2D() const { return toMulMatrix(); }
    };

    using ComplexNumf = ComplexNum<float>;
    using ComplexNumd = ComplexNum<double>;
    using ComplexNumld = ComplexNum<long double>;
}