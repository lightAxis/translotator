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
 * @file : S1.hpp
 */

#pragma once

namespace translotator::lie
{
    /**
     * @brief Lie Operator for S1
     * @tparam Type Data type
     * @details S1 is a unit complex number
     */
    template <typename Type>
    struct LieOperator<ObjectType::UNIT_COMPLEX_NUM, Type>
    {
        static_assert(is_float_v<Type>, "Invalid data type for LieOperator. Must be float type");

        using LieGroupType = UnitComplexNum<Type>;
        using LieAlgebraType = ComplexNum<Type>;
        using VectorType = Vector<1, Type>;

        /**
         * @brief Convert Vector to Lie Algebra
         * @param isomorphicVec Vector [1x1], [angle]
         * @return Lie Algebra [2x1] 0+angle*i, pure imaginary number
         */
        static LieAlgebraType Vector2LieAlgebra(const VectorType &isomorphicVec)
        {
            return LieAlgebraType{static_cast<Type>(0), isomorphicVec.toScalar()};
        }

        /**
         * @brief Convert Lie Algebra to Vector
         * @param lieAlgebra Lie Algebra [2x1] 0+angle*i, pure imaginary number
         * @return Vector [1x1], [angle]
         */
        static VectorType LieAlgebra2Vector(const LieAlgebraType &lieAlgebra)
        {
            return VectorType{lieAlgebra.Im()};
        }

        /**
         * @brief Exponential map
         * @param vec Vector [1x1], [angle]
         * @return Lie Group S1, Unit Complex Number
         */
        static LieGroupType Exp(const VectorType &vec)
        {
            return LieGroupType{vec.toScalar()};
        }

        /**
         * @brief Logarithm map
         * @param lieGroup Lie Group S1, Unit Complex Number
         * @return Vector [1x1], [angle]
         */
        static VectorType Log(const LieGroupType &lieGroup)
        {
            return VectorType{translotator::acos(lieGroup.Re())};
        }

        /**
         * @brief Exponential map
         * @param lieAlgebra Lie Algebra [2x1] 0+angle*i, pure imaginary number
         * @return Lie Group S1, Unit Complex Number
         */
        static LieGroupType exp(const LieAlgebraType &lieAlgebra)
        {
            return Exp(LieAlgebra2Vector(lieAlgebra));
        }

        /**
         * @brief Logarithm map
         * @param lieGroup Lie Group S1, Unit Complex Number
         * @return Lie Algebra [2x1] 0+angle*i, pure imaginary number
         */
        static LieAlgebraType log(const LieGroupType &lieGroup)
        {
            return Vector2LieAlgebra(Log(lieGroup));
        }
    };

    template <typename Type>
    using LieOperator_S1 = LieOperator<ObjectType::UNIT_COMPLEX_NUM, Type>;
    using LieOperator_S1f = LieOperator_S1<float>;
    using LieOperator_S1d = LieOperator_S1<double>;
    using LieOperator_S1ld = LieOperator_S1<long double>;
}