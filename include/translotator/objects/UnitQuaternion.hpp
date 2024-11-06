#pragma once

namespace translotator
{
    template <typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class UnitQuaternion : public Quaternion<Type>
    {
    private:
        explicit UnitQuaternion(const Quaternion<Type> &quat) : Quaternion<Type>(quat) {}

    public:
        using Quaternion<Type>::Quaternion;

        /**
         * constructors
         */
        inline UnitQuaternion() : Quaternion<Type>(static_cast<Type>(1),
                                                   static_cast<Type>(0),
                                                   static_cast<Type>(0),
                                                   static_cast<Type>(0)) {}

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
        template <typename OtherContainer>
        inline Quaternion<Type> operator+(const OtherContainer &other) const
        {
            static_assert(is_matrix_base_v<OtherContainer>, "Invalid type for operator+. Must have matrix base");
            const Quaternion<Type> &me = const_cast<UnitQuaternion<Type> *>(this)->cast2QuaternionRef();
            return me + other;
        }

        template <typename OtherContainer>
        inline Quaternion<Type> operator-(const OtherContainer &other) const
        {
            static_assert(is_matrix_base_v<OtherContainer>, "Invalid type for operator-. Must have matrix base");
            const Quaternion<Type> &me = const_cast<UnitQuaternion<Type> *>(this)->cast2QuaternionRef();
            return me - other;
        }

        template <typename OtherContainer>
        inline auto operator*(const OtherContainer &other) const
        {
            const Matrix<4, 1, Type> &me_mat = const_cast<UnitQuaternion<Type> *>(this)->cast2MatrixRef();
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
                return me_mat * other;
            }
        }
        inline friend Quaternion<Type> operator*(const Quaternion<Type> &lhs, const UnitQuaternion<Type> &rhs)
        {
            const Quaternion<Type> &rhs_ = const_cast<UnitQuaternion<Type> *>(&rhs)->cast2QuaternionRef();
            return lhs * rhs_;
        }
        inline friend Quaternion<Type> operator*(const Type &lhs, const UnitQuaternion<Type> &rhs)
        {
            const Quaternion<Type> &rhs_ = const_cast<UnitQuaternion<Type> *>(&rhs)->cast2QuaternionRef();
            return lhs * rhs_;
        }
        inline void operator*=(const UnitQuaternion<Type> &other)
        {
            *this = *this * other;
        }
        inline friend void operator*=(Quaternion<Type> &lhs, const UnitQuaternion<Type> &rhs)
        {
            const Quaternion<Type> &rhs_ = const_cast<UnitQuaternion<Type> *>(&rhs)->cast2QuaternionRef();
            lhs *= rhs_;
        }
        inline UnitQuaternion<Type> quatNumMul(const UnitQuaternion<Type> &other) const { return (*this) * other; } // alias for operator* for readability
        inline Quaternion<Type> quatNumMul(const Quaternion<Type> &other) const { return (*this) * other; }
        inline friend Quaternion<Type> quatNumMul(const Quaternion<Type> &lhs, const UnitQuaternion<Type> &rhs)
        {
            const Quaternion<Type> &rhs_ = const_cast<UnitQuaternion<Type> *>(&rhs)->cast2QuaternionRef();
            return lhs * rhs_;
        }
        inline void quatNumMulEq(const UnitQuaternion<Type> &other) { *this *= other; } // alias for operator*= for readability
        inline friend void quatNumMulEq(Quaternion<Type> &lhs, const UnitQuaternion<Type> &rhs)
        {
            lhs *= rhs.cast2QuaternionRef();
        }

        template <typename OtherContainer>
        inline auto operator/(const OtherContainer &other) const
        {
            const Quaternion<Type> &me_quat = const_cast<UnitQuaternion<Type> *>(this)->cast2QuaternionRef();
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
        inline friend Quaternion<Type> operator/(const Quaternion<Type> &lhs, const UnitQuaternion<Type> &rhs)
        {
            const Quaternion<Type> &rhs_ = const_cast<UnitQuaternion<Type> *>(&rhs)->cast2QuaternionRef();
            return lhs * rhs_.conjugated();
        }
        inline void operator/=(const UnitQuaternion<Type> &other)
        {
            *this = *this / other;
        }
        inline friend void operator/=(Quaternion<Type> &lhs, const UnitQuaternion<Type> &rhs)
        {
            const Quaternion<Type> &rhs_ = const_cast<UnitQuaternion<Type> *>(&rhs)->cast2QuaternionRef();
            lhs *= rhs_.conjugated();
        }
        inline UnitQuaternion<Type> quatNumDiv(const UnitQuaternion<Type> &other) const { return (*this) / other; } // alias for operator/ for readability
        inline Quaternion<Type> quatNumDiv(const Quaternion<Type> &other) const { return (*this) / other; }
        inline void quatNumDivEq(const UnitQuaternion<Type> &other) { *this /= other; } // alias for operator/= for readability
        inline friend void quatNumDivEq(Quaternion<Type> &lhs, const UnitQuaternion<Type> &rhs)
        {
            const Quaternion<Type> &rhs_ = const_cast<UnitQuaternion<Type> *>(&rhs)->cast2QuaternionRef();
            lhs *= rhs_.conjugated();
        }

        /**
         * utils
         */
        inline UnitQuaternion<Type> normalized() const
        {
            return UnitQuaternion<Type>(Quaternion<Type>::normalized());
        }
        inline UnitQuaternion<Type> conjugated() const
        {
            return UnitQuaternion<Type>(Quaternion<Type>::conjugated());
        }
        inline UnitQuaternion<Type> inversed() const
        {
            return conjugated();
        }
        inline Vector<3, Type> rotateVector3D(const Vector<3, Type> &v) const
        {
            const Quaternion<Type> qv{static_cast<Type>(0), v};
            return ((*this * qv) * conjugated()).Im();
        }
        inline Vector<2, Type> rotateVector2D(const Vector<2, Type> &v) const
        {
            const Type angle = static_cast<Type>(2) * translotator::acos(w());
            const Type c = translotator::cos(angle);
            const Type s = translotator::sin(angle);
            return Vector<2, Type>{{c * v.x() - s * v.y(),
                                    s * v.x() + c * v.y()}};
        }

        /**
         * static functions
         */
        static inline UnitQuaternion<Type> identity() { return UnitQuaternion<Type>(static_cast<Type>(1), static_cast<Type>(0), static_cast<Type>(0), static_cast<Type>(0)); }

        /**
         * casting
         */

        inline SquareMatrix<2, Type> toRotMatrix2D() const
        {
            const Type angle = static_cast<Type>(2) * translotator::acos(w());
            const Type c = translotator::cos(angle);
            const Type s = translotator::sin(angle);
            return SquareMatrix<2, Type>{{+c, -s,
                                          +s, +c}};
        }
        inline SquareMatrix<3, float> toRotMatrix3D() const
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
            return SquareMatrix<3, Type>{{1 - 2 * (yy + zz), 2 * (xy - zw), 2 * (xz + yw),
                                          2 * (xy + zw), 1 - 2 * (xx + zz), 2 * (yz - xw),
                                          2 * (xz - yw), 2 * (yz + xw), 1 - 2 * (xx + yy)}};
        }
        inline AxisAngle<Type> toAxisAngle() const
        {
            const Type angle = static_cast<Type>(2) * translotator::acos(w());
            if (translotator::abs(angle) < translotator::epsilon<Type>())
            {
                return AxisAngle<Type>::identity();
            }

            return AxisAngle<Type>{angle, Im() / translotator::sin(angle / static_cast<Type>(2))};
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