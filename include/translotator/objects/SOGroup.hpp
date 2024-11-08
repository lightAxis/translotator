#pragma once

namespace translotator
{
    template <size_t N, typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class SOGroup : public SquareMatrix<N, Type>
    {
        static_assert(N == 2 || N == 3, "Supports only SO(2) & SO(3) Groups");

    private:
        inline Type &Data_(size_t i, size_t j) { return SquareMatrix<N, Type>::operator()(i, j); }
        inline const Type &Data_(size_t i, size_t j) const { return SquareMatrix<N, Type>::operator()(i, j); }

        explicit SOGroup(const SquareMatrix<N, Type> &mat) : SquareMatrix<N, Type>(mat) {}

    public:
        using SquareMatrix<N, Type>::SquareMatrix;

        /**
         * constructors
         */
        template <size_t N_ = N, typename = enable_if_t<N_ == 2, true_type>>
        SOGroup(const Vector<N, Type> &vec1, const Vector<N, Type> &vec2, bool col = true)
        {
            if (col)
            {
                this->setCol(0, vec1);
                this->setCol(1, vec2);
            }
            else
            {
                this->setRow(0, vec1.T());
                this->setRow(1, vec2.T());
            }
        }
        template <size_t N_ = N, typename = enable_if_t<N_ == 3, true_type>>
        SOGroup(const Vector<N, Type> &vec1, const Vector<N, Type> &vec2, const Vector<N, Type> &vec3,
                bool col = true)
        {
            if (col)
            {
                this->setCol(0, vec1);
                this->setCol(1, vec2);
                this->setCol(2, vec3);
            }
            else
            {
                this->setRow(0, vec1.T());
                this->setRow(1, vec2.T());
                this->setRow(2, vec3.T());
            }
        }

        template <size_t N_ = N, typename = enable_if_t<N_ == 2, true_type>>
        explicit SOGroup(const Type &theta)
        {
            Data_(0, 0) = cos(theta);
            Data_(0, 1) = -sin(theta);
            Data_(1, 0) = sin(theta);
            Data_(1, 1) = cos(theta);
        }
        template <size_t N_ = N, typename = enable_if_t<N_ == 3, true_type>>
        explicit SOGroup(const Vector<N, Type> &angleVector)
        {
            if (angleVector.normSquared() <= translotator::epsilon<Type>())
            {
                (*this) = SOGroup<N, Type>{SquareMatrix<N, Type>::eye()};
            }
            else
            {
                (*this) = AxisAngle<Type>{angleVector}.toRotMatrix3D();
            }
        }

        /**
         * operators
         */
        template <typename OtherContainer>
        inline SquareMatrix<N, Type> operator+(const OtherContainer &other) const
        {
            static_assert(is_matrix_base_v<OtherContainer>, "Invalid type for operator+. Must have matrix base");
            return SquareMatrix<N, Type>::operator+(other);
        }

        template <typename OtherContainer>
        inline SquareMatrix<N, Type> operator-(const OtherContainer &other) const
        {
            static_assert(is_matrix_base_v<OtherContainer>, "Invalid type for operator-. Must have matrix base");
            return SquareMatrix<N, Type>::operator-(other);
        }

        template <typename OtherContainer>
        inline auto operator*(const OtherContainer &other) const
        {
            if constexpr (is_same_v<OtherContainer, SOGroup<N, Type>>)
            {
                const SquareMatrix<N, Type> &other_ = const_cast<SOGroup<N, Type> *>(&other)->cast2SquareMatrixRef();
                return SOGroup<N, Type>{SquareMatrix<N, Type>::operator*(other_)};
            }
            else if constexpr (is_same_v<OtherContainer, SquareMatrix<N, Type>>)
            {
                return SquareMatrix<N, Type>::operator*(other);
            }
            else if constexpr (is_same_v<OtherContainer, Type>)
            {
                return SquareMatrix<N, Type>::operator*(other);
            }
            else
            {
                return SquareMatrix<N, Type>::operator*(other);
            }
        }
        inline void operator*=(const SOGroup<N, Type> &other)
        {
            *this = *this * other;
        }
        inline friend SquareMatrix<N, Type> operator*(const Type &lhs, const SOGroup &rhs)
        {
            SquareMatrix<N, Type> &rhs_ = const_cast<SOGroup *>(&rhs)->cast2SquareMatrixRef();
            return rhs_ * lhs;
        }

        template <typename OtherContainer>
        inline auto operator/(const OtherContainer &other) const
        {
            if constexpr (is_same_v<OtherContainer, SOGroup<N, Type>>)
            {
                return (*this) * other.inversed();
            }
            else
            {
                return SquareMatrix<N, Type>::operator/(other);
            }
        }

        /**
         * utils
         */
        inline SOGroup<N, Type> normalized() const
        {
            if constexpr (N == 2)
            {
                return this->toUnitComplexNum().toRotMatrix2D();
            }
            else if constexpr (N == 3)
            {
                return this->toUnitQuaternion().toRotMatrix3D();
            }
            else
            {
                static_assert(N == 2 || N == 3, "Supports only SO(2) & SO(3) Groups");
                return SOGroup<N, Type>();
            }
        }
        inline void normalize()
        {
            (*this) = this->normalized();
        }
        inline SOGroup<N, Type> inversed() const
        {
            return SOGroup<N, Type>{SquareMatrix<N, Type>::T()};
        }
        inline void inverse()
        {
            (*this) = this->inversed();
        }
        inline SOGroup<N, Type> T() const
        {
            return SOGroup<N, Type>{SquareMatrix<N, Type>::T()};
        }

        /**
         * static functions
         */
        static inline SOGroup<N, Type> identity()
        {
            static_assert(N == 2 || N == 3, "Supports only SO(2) & SO(3) Groups");
            return SOGroup<N, Type>{SquareMatrix<N, Type>::eye()};
        }

        /**
         * casts
         */
        template <size_t N_ = N, typename = enable_if_t<N_ == 2, true_type>>
        inline UnitComplexNum<Type> toUnitComplexNum() const
        {
            return UnitComplexNum<Type>{Data_(0, 0), Data_(1, 0)};
        }
        template <size_t N_ = N, typename = enable_if_t<N_ == 2 || N_ == 3, true_type>>
        inline UnitQuaternion<Type> toUnitQuaternion() const
        {
            if constexpr (N == 2)
            {
                Type cos_theta = Data_(0, 0) < static_cast<Type>(-1) ? static_cast<Type>(-1) : Data_(0, 0);
                cos_theta = cos_theta > static_cast<Type>(1) ? static_cast<Type>(1) : cos_theta;
                const Type angle = translotator::acos(cos_theta);
                return UnitQuaternion<Type>{translotator::cos(angle / 2), 0, 0, translotator::sin(angle / 2)};
            }
            else if constexpr (N == 3)
            {
                UnitQuaternion<Type> q;
                const Type tr = this->trace();
                if (tr > 0)
                {
                    Type S = translotator::sqrt(tr + 1) * static_cast<Type>(2); // S=4*qw
                    q.w() = static_cast<Type>(0.25) * S;
                    q.x() = (Data_(2, 1) - Data_(1, 2)) / S;
                    q.y() = (Data_(0, 2) - Data_(2, 0)) / S;
                    q.z() = (Data_(1, 0) - Data_(0, 1)) / S;
                }
                else if ((Data_(0, 0) > Data_(1, 1)) && (Data_(0, 0) > Data_(2, 2)))
                {
                    Type S = translotator::sqrt(static_cast<Type>(1.0) + Data_(0, 0) - Data_(1, 1) - Data_(2, 2)) * static_cast<Type>(2); // S=4*qx
                    q.w() = (Data_(2, 1) - Data_(1, 2)) / S;
                    q.x() = static_cast<Type>(0.25) * S;
                    q.y() = (Data_(0, 1) + Data_(1, 0)) / S;
                    q.z() = (Data_(0, 2) + Data_(2, 0)) / S;
                }
                else if (Data_(1, 1) > Data_(2, 2))
                {
                    Type S = translotator::sqrt(static_cast<Type>(1.0) + Data_(1, 1) - Data_(0, 0) - Data_(2, 2)) * static_cast<Type>(2); // S=4*qy
                    q.w() = (Data_(0, 2) - Data_(2, 0)) / S;
                    q.x() = (Data_(0, 1) + Data_(1, 0)) / S;
                    q.y() = static_cast<Type>(0.25) * S;
                    q.z() = (Data_(1, 2) + Data_(2, 1)) / S;
                }
                else
                {
                    Type S = translotator::sqrt(static_cast<Type>(1.0) + Data_(2, 2) - Data_(0, 0) - Data_(1, 1)) * static_cast<Type>(2); // S=4*qz
                    q.w() = (Data_(1, 0) - Data_(0, 1)) / S;
                    q.x() = (Data_(0, 2) + Data_(2, 0)) / S;
                    q.y() = (Data_(1, 2) + Data_(2, 1)) / S;
                    q.z() = static_cast<Type>(0.25) * S;
                }
                q.normalize();
                return q;
            }
            else
                static_assert(N == 2 || N == 3, "Supports only SO(2) & SO(3) Groups");
        }
        template <size_t N_ = N, typename = enable_if_t<N_ == 2 || N_ == 3, true_type>>
        inline AxisAngle<Type> toAxisAngle() const
        {
            if constexpr (N == 2)
            {
                const Type angle = translotator::acos(Data_(0, 0));
                return AxisAngle<Type>{angle};
            }
            else if constexpr (N == 3)
            {
                return toUnitQuaternion().toAxisAngle();
            }
            else
                static_assert(N == 2 || N == 3, "Supports only SO(2) & SO(3) Groups");
        }
    };

    template <size_t N>
    using SOGroupf = SOGroup<N, float>;
    template <size_t N>
    using SOGroupd = SOGroup<N, double>;
    template <size_t N>
    using SOGroupld = SOGroup<N, long double>;

    template <size_t N>
    using RotationMatrixf = SOGroupf<N>;
    template <size_t N>
    using RotationMatrixd = SOGroupd<N>;
    template <size_t N>
    using RotationMatrixld = SOGroupld<N>;
}