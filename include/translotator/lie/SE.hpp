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
 * @file : SE.hpp
 */

#pragma once

namespace translotator::lie
{
    /**
     * @brief Lie Operator for SE
     * @tparam Type Data type
     * @details SE is a Special Euclidean Group
     */
    template <typename Type>
    struct LieOperator<ObjectType::SE_GROUP, Type>
    {
        template <size_t N>
        using LieGroupType = SEGroup<N, Type>;
        template <size_t N>
        using LieAlgebraType = SquareMatrix<N + 1, Type>;
        template <size_t N>
        using VectorType = Vector<N == 2 ? 3 : 6, Type>;

        /**
         * @brief Convert SE(2) Lie Algebra to Vector
         * @param lieAlgebra Lie Algebra [theta Vt; 0 0]
         * @return Vector [3x1], [theta, x, y]
         */
        static VectorType<2> LieAlgebra2Vector(const LieAlgebraType<2> &lieAlgebra)
        {
            return VectorType<2>{{lieAlgebra(1, 0),
                                  lieAlgebra(0, 2), lieAlgebra(1, 2)}};
        }

        /**
         * @brief Convert SE(3) Lie Algebra to Vector
         * @param lieAlgebra Lie Algebra [theta Vt; 0 0]
         * @return Vector [6x1], [theta_x, theta_y, theta_z, x, y, z]
         */
        static VectorType<3> LieAlgebra2Vector(const LieAlgebraType<3> &lieAlgebra)
        {
            return VectorType<3>{{lieAlgebra(2, 1), lieAlgebra(0, 2), lieAlgebra(1, 0),
                                  lieAlgebra(0, 3), lieAlgebra(1, 3), lieAlgebra(2, 3)}};
        }

        /**
         * @brief Convert Vector to SE(2) Lie Algebra
         * @param isomorphicVec Vector [3x1], [theta, x, y]
         * @return Lie Algebra [3x3] [theta Vt; 0 0]
         */
        static LieAlgebraType<2> Vector2LieAlgebra(const VectorType<2> &isomorphicVec) // [theta, x, y]
        {
            constexpr Type O = static_cast<Type>(0);
            return LieAlgebraType<2>{{O, -isomorphicVec[0], isomorphicVec[1],
                                      isomorphicVec[0], O, isomorphicVec[2],
                                      O, O, O}};
        }

        /**
         * @brief Convert Vector to SE(3) Lie Algebra
         * @param isomorphicVec Vector [6x1], [theta_x, theta_y, theta_z, x, y, z]
         * @return Lie Algebra [4x4] [theta Vt; 0 0]
         */
        static LieAlgebraType<3> Vector2LieAlgebra(const VectorType<3> &isomorphicVec) // [theta_x, theta_y, theta_z, x, y, z]
        {
            constexpr Type O = static_cast<Type>(0);
            return LieAlgebraType<3>{{O, -isomorphicVec[2], isomorphicVec[1], isomorphicVec[3],
                                      isomorphicVec[2], O, -isomorphicVec[0], isomorphicVec[4],
                                      -isomorphicVec[1], isomorphicVec[0], O, isomorphicVec[5],
                                      O, O, O, O}};
        }

        /**
         * @brief Exponential map
         * @param isomorphicVec Vector [3x1], [theta, x, y]
         * @return Lie Group SE(2)
         */
        static LieGroupType<2> Exp(const VectorType<2> &isomorphicVec)
        {
            constexpr Type O = static_cast<Type>(0);
            constexpr Type l = static_cast<Type>(1);
            const Type &theta = isomorphicVec[0];

            if (translotator::abs(theta) < epsilon<Type>())
            {
                return LieGroupType<2>{SOGroup<2, Type>::identity(), Vector<2, Type>{{isomorphicVec[1], isomorphicVec[2]}}};
            }
            const Type s_ = translotator::sin(theta) / theta;
            const Type c_ = (l - translotator::cos(theta)) / (theta);
            const SquareMatrix<2, Type> J{{s_, -c_,
                                           c_, s_}};
            return LieGroupType<2>{SO2Group<Type>{isomorphicVec[0]}, J * Vector<2, Type>{{isomorphicVec[1], isomorphicVec[2]}}};
        }

        /**
         * @brief Exponential map
         * @param isomorphicVec Vector [6x1], [theta_x, theta_y, theta_z, x, y, z]
         * @return Lie Group SE(3)
         */
        static LieGroupType<3> Exp(const VectorType<3> &isomorphicVec)
        {
            // TODO optimize this with sympy cse
            constexpr Type O = static_cast<Type>(0);
            constexpr Type l = static_cast<Type>(1);
            const Vector<3, Type> thetaVec = isomorphicVec.template block<0, 0, 3, 1>().cast2Vector();
            const Type theta = thetaVec.norm();
            const Vector<3, Type> tVec = isomorphicVec.template block<3, 0, 3, 1>().cast2Vector();

            if (translotator::abs(theta) < epsilon<Type>())
            {
                return LieGroupType<3>{SOGroup<3, Type>::identity(), tVec};
            }

            const Type c_ = (l - translotator::cos(theta)) / (theta * theta);
            const Type s_ = (theta - translotator::sin(theta)) / (theta * theta * theta);
            const Vector<3, Type> omega_cross_tVec = thetaVec.cross(tVec);
            const Vector<3, Type> omega_2cross_tVec = thetaVec.cross(omega_cross_tVec);

            return LieGroupType<3>{SO3Group<Type>{thetaVec},
                                   tVec + c_ * omega_cross_tVec + s_ * omega_2cross_tVec};
        }

        /**
         * @brief Logarithm map
         * @param lieGroup Lie Group SE(2)
         * @return Vector [3x1], [theta, x, y]
         */
        static VectorType<2> Log(const LieGroupType<2> &lieGroup)
        {
            const Type theta = translotator::atan2(lieGroup.rotation()(1, 0), lieGroup.rotation()(0, 0));

            if (translotator::abs(theta) < epsilon<Type>())
            {
                return VectorType<2>{{static_cast<Type>(0), lieGroup.translation()[0], lieGroup.translation()[1]}};
            }
            const Type theta_2 = theta * static_cast<Type>(0.5);
            const Type s_ = theta_2 * translotator::sin(theta) / (static_cast<Type>(1) - translotator::cos(theta));
            const SquareMatrix<2, Type> J_inv{{s_, theta_2,
                                               -theta_2, s_}};
            const Vector<2, Type> tVec = J_inv * lieGroup.translation();

            return VectorType<2>{{theta, tVec[0], tVec[1]}};
        }

        /**
         * @brief Logarithm map
         * @param lieGroup Lie Group SE(3)
         * @return Vector [6x1], [theta_x, theta_y, theta_z, x, y, z]
         */
        static VectorType<3> Log(const LieGroupType<3> &lieGroup)
        {
            const Vector<3, Type> thetaVec = LieOperator_SO<Type>::Log(lieGroup.rotation());
            const Type theta = thetaVec.norm();

            if (translotator::abs(theta) < epsilon<Type>())
            {
                return VectorType<3>{{static_cast<Type>(0), static_cast<Type>(0), static_cast<Type>(0),
                                      lieGroup.translation()[0], lieGroup.translation()[1], lieGroup.translation()[2]}};
            }

            const Type a = (static_cast<Type>(1) - (theta * translotator::sin(theta)) / (static_cast<Type>(2) * (static_cast<Type>(1) - translotator::cos(theta)))) / (theta * theta);
            const Vector<3, Type> omega_cross_t = thetaVec.cross(lieGroup.translation());
            const Vector<3, Type> tVec = lieGroup.translation() - static_cast<Type>(0.5) * omega_cross_t + a * thetaVec.cross(omega_cross_t);

            return VectorType<3>{{thetaVec[0], thetaVec[1], thetaVec[2],
                                  tVec[0], tVec[1], tVec[2]}};
        }

        /**
         * @brief Exponential map
         * @param lieAlgebra Lie Algebra [3x3] [theta Vt; 0 0]
         * @return Lie Group SE(2)
         */
        static LieGroupType<2> exp(const LieAlgebraType<2> &lieAlgebra)
        {
            return Exp(LieAlgebra2Vector(lieAlgebra));
        }

        /**
         * @brief Exponential map
         * @param lieAlgebra Lie Algebra [4x4] [theta Vt; 0 0]
         * @return Lie Group SE(3)
         */
        static LieGroupType<3> exp(const LieAlgebraType<3> &lieAlgebra)
        {
            return Exp(LieAlgebra2Vector(lieAlgebra));
        }

        /**
         * @brief Logarithm map
         * @param lieGroup Lie Group SE(2)
         * @return Lie Algebra [3x3] [theta Vt; 0 0]
         */
        static LieAlgebraType<2> log(const LieGroupType<2> &lieGroup)
        {
            return Vector2LieAlgebra(Log(lieGroup));
        }

        /**
         * @brief Logarithm map
         * @param lieGroup Lie Group SE(3)
         * @return Lie Algebra [4x4] [theta Vt; 0 0]
         */
        static LieAlgebraType<3> log(const LieGroupType<3> &lieGroup)
        {
            return Vector2LieAlgebra(Log(lieGroup));
        }
    };

    template <typename Type>
    using LieOperator_SE = LieOperator<ObjectType::SE_GROUP, Type>;
    using LieOperator_SEf = LieOperator_SE<float>;
    using LieOperator_SEd = LieOperator_SE<double>;
    using LieOperator_SEld = LieOperator_SE<long double>;
}