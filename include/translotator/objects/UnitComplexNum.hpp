#pragma once

namespace translotator
{
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
        /**
         * utils
         */
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
            using LieOp = LieOperator<ObjectType::UNIT_COMPLEX_NUM, Type>;
            return LieOp::Exp(LieOp::Log(*this) * t);
        }

        /**
         * static functions
         */
        static inline UnitComplexNum<Type> identity() { return UnitComplexNum<Type>(static_cast<Type>(1), static_cast<Type>(0)); }

        /**
         * casting
         */
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