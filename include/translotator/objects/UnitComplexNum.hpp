#pragma once

namespace translotator
{
    template <typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class UnitComplexNum : public ComplexNum<Type>
    {
    public:
        using ComplexNum<Type>::ComplexNum;
        /**
         * constructors
         */
        inline UnitComplexNum() : ComplexNum<Type>(static_cast<Type>(1), static_cast<Type>(0)) {}

        /**
         * accessors
         */
        using ComplexNum<Type>::Re;
        using ComplexNum<Type>::Im;

        /**
         * operators
         */
        template <typename OtherContainer>
        inline auto operator+(const OtherContainer &other) const
        {
            if constexpr (is_same_v<OtherContainer, UnitComplexNum<Type>> ||
                          is_same_v<OtherContainer, ComplexNum<Type>>)
            {
                const ComplexNum<Type> &me = const_cast<UnitComplexNum<Type> *>(this)->toComplexNumRef();
                return me + other;
            }
            else
            {
                return other + (*this);
            }
        }

        template <typename OtherContainer>
        inline auto operator-(const OtherContainer &other) const
        {
            if constexpr (is_same_v<OtherContainer, UnitComplexNum<Type>> ||
                          is_same_v<OtherContainer, ComplexNum<Type>>)
            {
                const ComplexNum<Type> &me = const_cast<UnitComplexNum<Type> *>(this)->toComplexNumRef();
                return me - other;
            }
            else
            {
                return other - (*this);
            }
        }

        inline UnitComplexNum<Type> operator*(const UnitComplexNum<Type> &other) const
        {
            const ComplexNum<Type> &me = const_cast<UnitComplexNum<Type> *>(this)->toComplexNumRef();
            const ComplexNum<Type> &other_ = const_cast<UnitComplexNum<Type> *>(&other)->toComplexNumRef();
            return (me * other_).toUnitComplexNum();
        }
        inline ComplexNum<Type> operator*(const ComplexNum<Type> &other) const
        {
            const ComplexNum<Type> &me = const_cast<UnitComplexNum<Type> *>(this)->toComplexNumRef();
            return me * other;
        }
        template <typename OtherContainer>
        inline auto operator*(const OtherContainer &other) const
        {
            const Matrix<2, 1, Type> &me = const_cast<UnitComplexNum<Type> *>(this)->toMatrixRef();
            return me * other;
        }
        inline ComplexNum<Type> operator*(const Type &v) const
        {
            const ComplexNum<Type> &me = const_cast<UnitComplexNum<Type> *>(this)->toComplexNumRef();
            return me * v;
        }
        inline void operator*=(const UnitComplexNum<Type> &other)
        {
            *this = *this * other;
        }
        inline friend ComplexNum<Type> operator*(const ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs)
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->toComplexNumRef();
            return lhs * rhs_;
        }
        inline UnitComplexNum<Type> complexNumMul(const UnitComplexNum<Type> &other) const { return *this * other; } // alias for operator* for readability
        inline ComplexNum<Type> complexNumMul(const ComplexNum<Type> &other) const { return *this * other; }
        inline friend ComplexNum<Type> complexNumMul(const ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs)
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->toComplexNumRef();
            return lhs * rhs_;
        }
        inline void complexNumMulEq(const UnitComplexNum<Type> &other) { *this *= other; } // alias for operator*= for readability
        inline friend void complexNumMulEq(ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs)
        {
            lhs *= rhs.toComplexNumRef();
        }

        inline UnitComplexNum<Type> operator/(const UnitComplexNum<Type> &other) const
        {
            const ComplexNum<Type> &me = const_cast<UnitComplexNum<Type> *>(this)->toComplexNumRef();
            const ComplexNum<Type> &other_ = const_cast<UnitComplexNum<Type> *>(&other)->toComplexNumRef();
            return (me * other_.conjugated()).toUnitComplexNum();
        }
        inline ComplexNum<Type> operator/(const ComplexNum<Type> &other) const
        {
            const ComplexNum<Type> &me = const_cast<UnitComplexNum<Type> *>(this)->toComplexNumRef();
            return me / other;
        }
        inline ComplexNum<Type> operator/(const Type &v) const
        {
            const ComplexNum<Type> &me = const_cast<UnitComplexNum<Type> *>(this)->toComplexNumRef();
            return me / v;
        }
        inline friend ComplexNum<Type> operator/(const ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs)
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->toComplexNumRef();
            return lhs / rhs_;
        }
        inline friend ComplexNum<Type> operator/(const Type &lhs, const UnitComplexNum<Type> &rhs)
        {
            const ComplexNum<Type> &rhs_ = const_cast<UnitComplexNum<Type> *>(&rhs)->toComplexNumRef();
            return lhs / rhs_;
        }
        inline void operator/=(const UnitComplexNum<Type> &other)
        {
            *this = *this / other;
        }
        inline friend void operator/=(ComplexNum<Type> &lhs, const UnitComplexNum<Type> &rhs)
        {
            lhs /= rhs.toComplexNumRef();
        }
        inline UnitComplexNum<Type> complexNumDiv(const UnitComplexNum<Type> &other) const { return *this / other; } // alias for operator/ for readability
        inline ComplexNum<Type> complexNumDiv(const ComplexNum<Type> &other) const { return *this / other; }
        inline void complexNumDivEq(const UnitComplexNum<Type> &other) { *this /= other; } // alias for operator/= for readability

        /**
         * utils
         */
        inline UnitComplexNum<Type> normalized() const
        {
            const ComplexNum<Type> &me = const_cast<UnitComplexNum<Type> *>(this)->toComplexNumRef();
            return me.normalized().toUnitComplexNum();
        }
        inline UnitComplexNum<Type> conjugated() const
        {
            const ComplexNum<Type> &me = const_cast<UnitComplexNum<Type> *>(this)->toComplexNumRef();
            return me.conjugated().toUnitComplexNum();
        }
        inline UnitComplexNum<Type> inversed() const
        {
            const ComplexNum<Type> &me = const_cast<UnitComplexNum<Type> *>(this)->toComplexNumRef();
            return me.inversed().toUnitComplexNum();
        }
        inline void inverse() { *this = inversed(); }
        inline Vector<2, Type> rotateVector2D(const Vector<2, Type> &v) const
        {
            return Vector<2, Type>{{Re() * v.x() - Im() * v.y(),
                                    Im() * v.x() + Re() * v.y()}};
        }

        /**
         * static functions
         */
        static inline UnitComplexNum<Type> identity() { return UnitComplexNum<Type>(static_cast<Type>(1), static_cast<Type>(0)); }

        /**
         * casting
         */
        inline SquareMatrix<2, Type> toRotMatrix2D() const { return ComplexNum<Type>::toMulMatrix(); }
        inline AxisAngle<Type> toAxisAngle() const
        {
            const Type angle = translotator::acos(Re());
            return AxisAngle<Type>{angle};
        }
    };

    using UnitComplexNumf = UnitComplexNum<float>;
    using UnitComplexNumd = UnitComplexNum<double>;
    using UnitComplexNumld = UnitComplexNum<long double>;
    using S1f = UnitComplexNumf;
    using S1d = UnitComplexNumd;
    using S1ld = UnitComplexNumld;
}