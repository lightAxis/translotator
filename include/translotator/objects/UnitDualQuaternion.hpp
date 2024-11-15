#pragma once

namespace translotator
{
    template <typename Type>
    class UnitDualQuaternion : public DualQuaternion<Type>
    {
    private:
        explicit UnitDualQuaternion(const DualQuaternion<Type> &dq)
            : DualQuaternion<Type>(dq) {}

    public:
        constexpr static ObjectType OBJECT_TYPE = ObjectType::UNIT_DUAL_QUATERNION;
        using DualQuaternion<Type>::DualQuaternion;

        /**
         * constructors
         */
        inline UnitDualQuaternion() : DualQuaternion<Type>(static_cast<Type>(1),
                                                           static_cast<Type>(0),
                                                           static_cast<Type>(0),
                                                           static_cast<Type>(0),
                                                           static_cast<Type>(0),
                                                           static_cast<Type>(0),
                                                           static_cast<Type>(0),
                                                           static_cast<Type>(0)) {}
        inline UnitDualQuaternion(const UnitQuaternion<Type> &re, const Quaternion<Type> &du)
            : DualQuaternion<Type>(re, du) {}
        inline UnitDualQuaternion(const UnitQuaternion<Type> &rot, const Vector<3, Type> &t)
            : DualQuaternion<Type>(rot, Quaternion<Type>{static_cast<Type>(0), static_cast<Type>(0.5) * t} * rot) {}
        /**
         * accessors
         */
        inline const UnitQuaternion<Type> &Re() const
        {
            return reinterpret_cast<const UnitQuaternion<Type> &>(DualQuaternion<Type>::Re());
        }
        inline UnitQuaternion<Type> &Re() { return reinterpret_cast<UnitQuaternion<Type> &>(DualQuaternion<Type>::Re()); }
        using DualQuaternion<Type>::Du;
        using DualQuaternion<Type>::rw;
        using DualQuaternion<Type>::rx;
        using DualQuaternion<Type>::ry;
        using DualQuaternion<Type>::rz;
        using DualQuaternion<Type>::dw;
        using DualQuaternion<Type>::dx;
        using DualQuaternion<Type>::dy;
        using DualQuaternion<Type>::dz;

        /**
         * operators
         */
        template <typename OtherContainer>
        inline DualQuaternion<Type> operator+(const OtherContainer &other) const
        {
            return DualQuaternion<Type>::operator+(other);
        }

        template <typename OtherContainer>
        inline DualQuaternion<Type> operator-(const OtherContainer &other) const
        {
            return DualQuaternion<Type>::operator-(other);
        }

        template <typename OtherContainer>
        inline auto operator*(const OtherContainer &other) const
        {
            if constexpr (is_same_v<OtherContainer, UnitDualQuaternion<Type>>)
            {
                const DualQuaternion<Type> &other_ = const_cast<UnitDualQuaternion<Type> *>(&other)->cast2DualQuaternionRef();
                return UnitDualQuaternion<Type>{DualQuaternion<Type>::operator*(other_)};
            }
            else if constexpr (is_same_v<OtherContainer, DualQuaternion<Type>>)
            {
                return DualQuaternion<Type>::operator*(other);
            }
            else if constexpr (is_same_v<OtherContainer, Type>)
            {
                return DualQuaternion<Type>::operator*(other);
            }
            else
            {
                return Matrix<8, 1, Type>();
            }
        }
        inline friend DualQuaternion<Type> operator*(const DualQuaternion<Type> &lhs, const UnitDualQuaternion<Type> &rhs)
        {
            const DualQuaternion<Type> &rhs_ = const_cast<UnitDualQuaternion<Type> *>(&rhs)->cast2DualQuaternionRef();
            return lhs * rhs_;
        }
        inline friend DualQuaternion<Type> operator*(const Type &lhs, const UnitDualQuaternion<Type> &rhs)
        {
            const DualQuaternion<Type> &rhs_ = const_cast<UnitDualQuaternion<Type> *>(&rhs)->cast2DualQuaternionRef();
            return lhs * rhs_;
        }
        inline void operator*=(const UnitDualQuaternion<Type> &other)
        {
            *this = *this * other;
        }
        inline friend void operator*=(DualQuaternion<Type> &lhs, const UnitDualQuaternion<Type> &rhs)
        {
            const DualQuaternion<Type> &rhs_ = const_cast<UnitDualQuaternion<Type> *>(&rhs)->cast2DualQuaternionRef();
            lhs *= rhs_;
        }
        inline UnitDualQuaternion<Type> dualQuatMul(const UnitDualQuaternion<Type> &other) const { return (*this) * other; } // alias for operator* for readability
        inline DualQuaternion<Type> dualQuatMul(const DualQuaternion<Type> &other) const { return (*this) * other; }
        inline friend DualQuaternion<Type> dualQuatMul(const DualQuaternion<Type> &lhs, const UnitDualQuaternion<Type> &rhs)
        {
            const DualQuaternion<Type> &rhs_ = const_cast<UnitDualQuaternion<Type> *>(&rhs)->cast2DualQuaternionRef();
            return lhs * rhs_;
        }
        inline void dualQuatMulEq(const UnitDualQuaternion<Type> &other) { *this *= other; } // alias for operator*= for readability
        inline friend void dualQuatMulEq(DualQuaternion<Type> &lhs, const UnitDualQuaternion<Type> &rhs)
        {
            lhs *= rhs.cast2DualQuaternionRef();
        }

        template <typename OtherContainer>
        inline auto operator/(const OtherContainer &other) const
        {
            if constexpr (is_same_v<OtherContainer, UnitDualQuaternion<Type>>)
            {
                return (*this) * other.inversed();
            }
            else if constexpr (is_same_v<OtherContainer, DualQuaternion<Type>>)
            {
                return DualQuaternion<Type>::operator/(other);
            }
            else if constexpr (is_same_v<OtherContainer, Type>)
            {
                return DualQuaternion<Type>::operator/(other);
            }
            else
            {
                static_assert(is_same_v<OtherContainer, UnitDualQuaternion<Type>> ||
                                  is_same_v<OtherContainer, DualQuaternion<Type>>,
                              "Invalid type for operator/ must be UnitDualQuaternion or Quaternion");
                return Matrix<8, 1, Type>();
            }
        }
        inline friend DualQuaternion<Type> operator/(const DualQuaternion<Type> &lhs, const UnitDualQuaternion<Type> &rhs)
        {
            const DualQuaternion<Type> &rhs_ = const_cast<UnitDualQuaternion<Type> *>(&rhs)->cast2DualQuaternionRef();
            return lhs * rhs_.inversed();
        }
        inline void operator/=(const UnitDualQuaternion<Type> &other)
        {
            *this = *this / other;
        }
        inline friend void operator/=(DualQuaternion<Type> &lhs, const UnitDualQuaternion<Type> &rhs)
        {
            const DualQuaternion<Type> &rhs_ = const_cast<UnitDualQuaternion<Type> *>(&rhs)->cast2DualQuaternionRef();
            lhs *= rhs_.inversed();
        }
        inline UnitDualQuaternion<Type> dualQuatDiv(const UnitDualQuaternion<Type> &other) const { return (*this) / other; } // alias for operator/ for readability
        inline DualQuaternion<Type> dualQuatDiv(const DualQuaternion<Type> &other) const { return (*this) / other; }
        inline void dualQuatDivEq(const UnitDualQuaternion<Type> &other) { *this /= other; } // alias for operator/= for readability
        inline friend void dualQuatDivEq(DualQuaternion<Type> &lhs, const UnitDualQuaternion<Type> &rhs)
        {
            const DualQuaternion<Type> &rhs_ = const_cast<UnitDualQuaternion<Type> *>(&rhs)->cast2DualQuaternionRef();
            lhs *= rhs_.inversed();
        }

        /**
         * utils
         */
        inline UnitDualQuaternion<Type> normalized() const
        {
            return UnitDualQuaternion<Type>(DualQuaternion<Type>::normalized());
        }
        inline void normalize() { *this = normalized(); }
        inline UnitDualQuaternion<Type> conjugated() const
        {
            return UnitDualQuaternion<Type>(DualQuaternion<Type>::conjugatedPrimary());
        }
        inline void conjugate() { *this = conjugated(); }
        inline UnitDualQuaternion<Type> inversed() const
        {
            return conjugated();
        }
        inline void inverse() { *this = inversed(); }
        inline Vector<2, Type> actOnVector2D(const Vector<2, Type> &v) const
        {
            return Re().rotateVector2D(v) + toTranslationVec2D();
        }
        inline Vector<3, Type> actOnVector3D(const Vector<3, Type> &v) const
        {
            // 1. dv = 1+q_vE
            // 2. d dv d* = 1 + q_v'E. (full conjugated)

            // DualQuaternion<Type> qv{UnitQuaternion<Type>::identity(), Quaternion<Type>{static_cast<Type>(0), v}};
            // DualQuaternion<Type> q_res = (*this) * qv * conjugatedFull();
            // return q_res.Du().Im();

            return Re().rotateVector3D(v) + toTranslationVec3D();
        }

        /**
         * static functions
         */
        static inline UnitDualQuaternion<Type> identity() { return UnitDualQuaternion<Type>{UnitQuaternion<Type>::identity(), Quaternion<Type>::zeros()}; }

        /**
         * casting
         */
        inline SEGroup<2, Type> toSE2Group() const
        {
            return SEGroup<2, Type>{Re().toRotMatrix2D(), toTranslationVec2D()};
        }

        inline SEGroup<3, Type> toSE3Group() const
        {
            return SEGroup<3, Type>{Re().toRotMatrix3D(), toTranslationVec3D()};
        }

        inline Vector<2, Type> toTranslationVec2D() const
        {
            return Vector<2, Type>{{2 * (rw() * dx() - rz() * dy()), 2 * (rz() * dx() + rw() * dy())}};
        }

        inline Vector<3, Type> toTranslationVec3D() const
        {
            return 2 * (Du() * Re().inversed()).Im();
        }
    };

    using UnitDualQuaternionf = UnitDualQuaternion<float>;
    using UnitDualQuaterniond = UnitDualQuaternion<double>;
    using UnitDualQuaternionld = UnitDualQuaternion<long double>;
}