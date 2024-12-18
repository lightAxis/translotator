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
 * @file : SOGroup.hpp
 */

#pragma once

namespace translotator
{
    /**
     * @brief Special Orthogonal Group
     * @tparam N dimension
     * @tparam Type data type
     * @details Special Orthogonal Group is a group of rotation in N dimension.
     * It is a group of orthogonal matrices with determinant 1. Subgroup of SOGroup is SO(2) and SO(3).
     * Also SOGroup is a Lie Group. Exponential and Logarithm map can be defined.
     */
    template <size_t N, typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class SOGroup : public SquareMatrix<N, Type>
    {
        static_assert(N == 2 || N == 3, "Supports only SO(2) & SO(3) Groups");

    private:
        inline Type &Data_(size_t i, size_t j) { return SquareMatrix<N, Type>::operator()(i, j); }
        inline const Type &Data_(size_t i, size_t j) const { return SquareMatrix<N, Type>::operator()(i, j); }

        explicit SOGroup(const SquareMatrix<N, Type> &mat) : SquareMatrix<N, Type>(mat) {}

    public:
        constexpr static ObjectType OBJECT_TYPE = ObjectType::SO_GROUP;
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

        /**
         * @brief SOGroup + SOGroup => SquareMatrix
         * @tparam OtherContainer Matrix based object with same dimension
         */
        template <typename OtherContainer>
        inline SquareMatrix<N, Type> operator+(const OtherContainer &other) const
        {
            static_assert(is_matrix_base_v<OtherContainer>, "Invalid type for operator+. Must have matrix base");
            return SquareMatrix<N, Type>::operator+(other);
        }

        /**
         * @brief SOGroup - SOGroup => SquareMatrix
         * @tparam OtherContainer Matrix based object with same dimension
         */
        template <typename OtherContainer>
        inline SquareMatrix<N, Type> operator-(const OtherContainer &other) const /// SOGroup - SOGroup => SquareMatrix
        {
            static_assert(is_matrix_base_v<OtherContainer>, "Invalid type for operator-. Must have matrix base");
            return SquareMatrix<N, Type>::operator-(other);
        }

        /**
         * @brief SOGroup * SOGroup => SOGroup
         * @tparam OtherContainer Matrix based object with same dimension
         */
        template <typename OtherContainer>
        inline auto operator*(const OtherContainer &other) const /// SOGroup * SOGroup => SOGroup
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
        inline void operator*=(const SOGroup<N, Type> &other) /// SOGroup *= SOGroup
        {
            *this = *this * other;
        }
        inline friend SquareMatrix<N, Type> operator*(const Type &lhs, const SOGroup &rhs) /// Type * SOGroup
        {
            SquareMatrix<N, Type> &rhs_ = const_cast<SOGroup *>(&rhs)->cast2SquareMatrixRef();
            return rhs_ * lhs;
        }

        /**
         * @brief SOGroup / SOGroup => SOGroup
         * @tparam OtherContainer Matrix based object with same dimension
         */
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

        inline SOGroup<N, Type> operator-() const /// -SOGroup
        {
            return SOGroup<N, Type>{SquareMatrix<N, Type>::operator-()};
        }

        /**
         * utils
         */

        /**
         * @brief Get the orthogonalized matrix
         * @return SOGroup<N, Type>
         * @note This function uses UnitComplexNum & UnitQuternion internally. Not a mathmatically correct way, but it works.
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

        inline void normalize() /// normalize this matrix
        {
            (*this) = this->normalized();
        }

        inline SOGroup<N, Type> inversed() const /// inverse is same as transpose in SOGroup
        {
            return SOGroup<N, Type>{SquareMatrix<N, Type>::T()};
        }

        inline void inverse() /// inverse this matrix
        {
            (*this) = this->inversed();
        }

        inline SOGroup<N, Type> T() const /// transpose
        {
            return SOGroup<N, Type>{SquareMatrix<N, Type>::T()};
        }

        inline SOGroup<N, Type> pow(const Type &t) const /// power of SOGroup. Using Exponential & Logarithm Map of Lie Group
        {
            using LieOp = lie::LieOperator<ObjectType::SO_GROUP, Type>;
            return LieOp::Exp(LieOp::Log(*this) * t);
        }

        /**
         * static functions
         */

        static inline SOGroup<N, Type> identity() /// identity rotation element, which is identity matrix
        {
            static_assert(N == 2 || N == 3, "Supports only SO(2) & SO(3) Groups");
            return SOGroup<N, Type>{SquareMatrix<N, Type>::eye()};
        }

        /**
         * @brief Create a rotation matrix around the axis
         * @tparam Axis Axis to rotate
         * @param angle angle in radian
         */
        template <AXIS Axis>
        static SOGroup<N, Type> axisRotation(const Type &angle)
        {
            // TODO add testcode for this
            static_assert(N == 3, "Supports only SO(3) Groups");
            const Type c = translotator::cos(angle);
            const Type s = translotator::sin(angle);
            const Type o = static_cast<Type>(0);
            const Type l = static_cast<Type>(1);
            if constexpr (Axis == AXIS::X)
            {
                return SOGroup<N, Type>{{l, o, o,
                                         o, c, -s,
                                         o, s, c}};
            }
            else if constexpr (Axis == AXIS::Y)
            {
                return SOGroup<N, Type>{{c, o, s,
                                         o, l, o,
                                         -s, o, c}};
            }
            else if constexpr (Axis == AXIS::Z)
            {
                return SOGroup<N, Type>{{c, -s, o,
                                         s, c, o,
                                         o, o, l}};
            }
            else
            {
                static_assert(Axis == AXIS::X || Axis == AXIS::Y || Axis == AXIS::Z, "Invalid Axis");
            }
        }

        /**
         * casts
         */

        inline UnitComplexNum<Type> toUnitComplexNum() const /// convert to UnitComplexNum. Using only z-axis
        {
            static_assert(N == 2, "Supports only SO(2) Groups");
            return UnitComplexNum<Type>{Data_(0, 0), Data_(1, 0)};
        }

        inline UnitQuaternion<Type> toUnitQuaternion() const /// convert to UnitQuaternion
        {
            if constexpr (N == 2)
            {
                Type cos_theta = Data_(0, 0) < static_cast<Type>(-1) ? static_cast<Type>(-1) : Data_(0, 0);
                cos_theta = cos_theta > static_cast<Type>(1) ? static_cast<Type>(1) : cos_theta;
                const Type angle = translotator::acos(cos_theta);
                return UnitQuaternion<Type>{translotator::cos(angle / 2), 0, 0, translotator::sin(angle / 2)}.canonicalized();
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
                q.canonicalize();
                return q;
            }
            else
                static_assert(N == 2 || N == 3, "Supports only SO(2) & SO(3) Groups");
        }

        inline AxisAngle<Type> toAxisAngle() const /// convert to AxisAngle
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

        /**
         * @brief Convert to Euler Angle
         * @tparam NewOrder New Euler Order
         */
        template <EULER_ORDER NewOrder>
        EulerAngle<Type, NewOrder> toEulerAngle() const
        {
            if constexpr (N == 2)
            {
                const Type angle = translotator::acos(Data_(0, 0));
                return EulerAngle<Type, NewOrder>{static_cast<Type>(0), static_cast<Type>(0), angle};
            }
            else if constexpr (N == 3)
            {
                EulerAngle<Type, NewOrder> euler;
                constexpr size_t AXIS_FIRST = EULER_CONSTEXPR::AXIS_IDX_AT<0, NewOrder>();
                constexpr size_t AXIS_SECOND = EULER_CONSTEXPR::AXIS_IDX_AT<1, NewOrder>();
                constexpr size_t AXIS_THIRD = EULER_CONSTEXPR::AXIS_IDX_AT<2, NewOrder>();
                constexpr Type SIGN = (((AXIS_SECOND - AXIS_FIRST) == 1) ||
                                       ((static_cast<int>(AXIS_SECOND) - static_cast<int>(AXIS_FIRST)) == -2))
                                          ? Type(1)
                                          : Type(-1);

                // Tait-Bryan angles
                euler.template getAngleInOrder<0>() = translotator::atan2(-SIGN * Data_(AXIS_SECOND, AXIS_THIRD), Data_(AXIS_THIRD, AXIS_THIRD));
                euler.template getAngleInOrder<1>() = SIGN * translotator::asin(Data_(AXIS_FIRST, AXIS_THIRD));
                euler.template getAngleInOrder<2>() = translotator::atan2(-SIGN * Data_(AXIS_FIRST, AXIS_SECOND), Data_(AXIS_FIRST, AXIS_FIRST));

                /**
                 * In case of gimbal lock.
                 */
                // Tait-Bryan angles
                if (translotator::abs(euler.y() - Type(M_PI_2)) < epsilon<Type>())
                {
                    euler.template getAngleInOrder<0>() = Type(0);
                    euler.template getAngleInOrder<2>() = translotator::atan2(Data_(AXIS_THIRD, AXIS_SECOND), -SIGN * Data_(AXIS_THIRD, AXIS_FIRST));
                }
                else if (translotator::abs(euler.y() + Type(M_PI_2)) < epsilon<Type>())
                {
                    euler.template getAngleInOrder<0>() = Type(0);
                    euler.template getAngleInOrder<2>() = translotator::atan2(-Data_(AXIS_THIRD, AXIS_SECOND), SIGN * Data_(AXIS_THIRD, AXIS_FIRST));
                }

                return euler;
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

    template <typename Type>
    using SO2Group = SOGroup<2, Type>;
    template <typename Type>
    using SO3Group = SOGroup<3, Type>;

    using SO3Groupf = SO3Group<float>;
    using SO3Groupd = SO3Group<double>;
    using SO3Groupld = SO3Group<long double>;

    using SO2Groupf = SO2Group<float>;
    using SO2Groupd = SO2Group<double>;
    using SO2Groupld = SO2Group<long double>;

    template <size_t N>
    using RotationMatrixf = SOGroupf<N>;
    template <size_t N>
    using RotationMatrixd = SOGroupd<N>;
    template <size_t N>
    using RotationMatrixld = SOGroupld<N>;

    template <typename Type>
    using RotationMatrix2D = SO2Group<Type>;
    template <typename Type>
    using RotationMatrix3D = SO3Group<Type>;

    using RotationMatrix2Df = SO2Groupf;
    using RotationMatrix2Dd = SO2Groupd;
    using RotationMatrix2Dld = SO2Groupld;

    using RotationMatrix3Df = SO3Groupf;
    using RotationMatrix3Dd = SO3Groupd;
    using RotationMatrix3Dld = SO3Groupld;
}