#pragma once

namespace translotator
{
    template <typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class Quaternion : public MatrixBase<4, 1, Type, Quaternion<Type>>
    {
    public:
        using MatrixBase<4, 1, Type, Quaternion<Type>>::MatrixBase;

        /**
         * constructors
         */
        inline Quaternion() : MatrixBase<4, 1, Type, Quaternion<Type>>({static_cast<Type>(0), static_cast<Type>(0), static_cast<Type>(0), static_cast<Type>(0)}) {}
        explicit inline Quaternion(Type w, Type x, Type y, Type z) : MatrixBase<4, 1, Type, Quaternion<Type>>({w, x, y, z}) {}
        explicit inline Quaternion(Type w, const Vector<3, Type> &v) : MatrixBase<4, 1, Type, Quaternion<Type>>({w, v[0], v[1], v[2]}) {}
        explicit inline Quaternion(const Vector<4, Type> &w_v) : MatrixBase<4, 1, Type, Quaternion<Type>>({w_v[0], w_v[1], w_v[2], w_v[3]}) {}

        /**
         * accessors
         */
        inline Type w() const { return this->data_[0]; }
        inline Type x() const { return this->data_[1]; }
        inline Type y() const { return this->data_[2]; }
        inline Type z() const { return this->data_[3]; }
        inline const Type Re() const { return w(); }
        inline const Vector<3, Type> Im() const { return Vector<3, Type>({this->data_[1], this->data_[2], this->data_[3]}); }
        inline Type &w() { return this->data_[0]; }
        inline Type &x() { return this->data_[1]; }
        inline Type &y() { return this->data_[2]; }
        inline Type &z() { return this->data_[3]; }
        inline Type &Re() { return w(); }
        inline Vector<3, Type> &Im() { return reinterpret_cast<Vector<3, Type> &>(this->data_[1]); }

        inline Type operator[](size_t i) const { return this->data_[i]; }
        inline Type &operator[](size_t i) { return this->data_[i]; }

        /**
         * casting
         */
        inline SquareMatrix<4, Type> toMulMatrix() const
        {
            return SquareMatrix<4, Type>{{w(), -x(), -y(), -z(),
                                          x(), w(), -z(), y(),
                                          y(), z(), w(), -x(),
                                          z(), -y(), x(), w()}};
        }
        inline SquareMatrix<4, Type> toRightMulMatrix() const
        {
            return SquareMatrix<4, Type>{{w(), -x(), -y(), -z(),
                                          x(), w(), z(), -y(),
                                          y(), -z(), w(), x(),
                                          z(), y(), -x(), w()}};
        }

        /**
         * operators
         */
        using MatrixBase<4, 1, Type, Quaternion<Type>>::operator*;
        using MatrixBase<4, 1, Type, Quaternion<Type>>::operator/;
        using MatrixBase<4, 1, Type, Quaternion<Type>>::operator*=;
        using MatrixBase<4, 1, Type, Quaternion<Type>>::operator/=;
        inline Quaternion<Type> operator*(const Quaternion<Type> &q) const
        {
            return Quaternion<Type>(w() * q.w() - x() * q.x() - y() * q.y() - z() * q.z(),
                                    x() * q.w() + w() * q.x() - z() * q.y() + y() * q.z(),
                                    y() * q.w() + z() * q.x() + w() * q.y() - x() * q.z(),
                                    z() * q.w() - y() * q.x() + x() * q.y() + w() * q.z());
        }
        inline Quaternion<Type> operator/(const Quaternion<Type> &q) const { return *this * q.inversed(); }
        inline void operator*=(const Quaternion<Type> &q) { *this = *this * q; }
        inline void operator/=(const Quaternion<Type> &q) { *this = *this / q; }
        inline Quaternion<Type> quatNumMul(const Quaternion<Type> &q) const { return *this * q; } // alias for operator* for readability
        inline void quatNumMulEq(const Quaternion<Type> &q) { *this *= q; }                       // alias for operator*= for readability
        inline Quaternion<Type> quatNumDiv(const Quaternion<Type> &q) const { return *this / q; } // alias for operator/ for readability
        inline void quatNumDivEq(const Quaternion<Type> &q) { *this /= q; }                       // alias for operator/= for readability

        /**
         * utils
         */

        inline Quaternion<Type> identity() const { return Quaternion<Type>(static_cast<Type>(1), static_cast<Type>(0), static_cast<Type>(0), static_cast<Type>(0)); }
        inline Type normSquared() const { return this->frobeniusNormSquared(); }
        inline Type norm() const { return this->frobeniusNorm(); }
        inline Quaternion<Type> normalized() const { return *this / norm(); }
        inline void normalize() { *this = normalized(); }
        inline Quaternion<Type> canonicalized() const
        {
            if (w() < static_cast<Type>(0))
            {
                return -(*this);
            }
            return *this;
        }
        inline void canonicalize() { *this = canonicalized(); }
        inline Quaternion<Type> conjugated() const { return Quaternion<Type>(w(), -x(), -y(), -z()); }
        inline void conjugate() { *this = conjugated(); }
        inline Quaternion<Type> inversed() const { return conjugated() / normSquared(); }
        inline void inverse() { *this = inversed(); }
    };

    using Quaternionf = Quaternion<float>;
    using Quaterniond = Quaternion<double>;
    using Quaternionld = Quaternion<long double>;
}