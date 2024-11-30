

# File SO.hpp

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**translotator**](dir_ffa3503b73a46a1fbf73d754da62ba14.md) **>** [**lie**](dir_8ed321f5373998308f124cc3f5af3597.md) **>** [**SO.hpp**](SO_8hpp.md)

[Go to the documentation of this file](SO_8hpp.md)


```C++
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
 * @file : SO.hpp
 */

#pragma once

namespace translotator::lie
{
    template <typename Type>
    struct LieOperator<ObjectType::SO_GROUP, Type>
    {
        template <size_t N>
        using LieAlgebraType = SquareMatrix<N, Type>;
        template <size_t N>
        using LieGroupType = SOGroup<N, Type>;
        template <size_t N>
        using VectorType = Vector<N == 2 ? 1 : 3, Type>;

        static LieAlgebraType<2> Vector2LieAlgebra(const VectorType<2> &isomorphicVec)
        {
            constexpr Type O = static_cast<Type>(0);
            return LieAlgebraType<2>{{O, -isomorphicVec.x(),
                                      isomorphicVec.x(), O}};
        }

        static LieAlgebraType<3> Vector2LieAlgebra(const VectorType<3> &isomorphicVec)
        {
            return isomorphicVec.toCrossMatrix();
        }

        static VectorType<2> LieAlgebra2Vector(const LieAlgebraType<2> &lieAlgebra)
        {
            return VectorType<2>{{lieAlgebra(1, 0)}};
        }

        static VectorType<3> LieAlgebra2Vector(const LieAlgebraType<3> &lieAlgebra)
        {
            return VectorType<3>{{lieAlgebra(2, 1), lieAlgebra(0, 2), lieAlgebra(1, 0)}}; // x, y, z
        }

        static LieGroupType<2> Exp(const VectorType<2> &isomorphicVec)
        {
            if (isomorphicVec.normSquared() <= epsilon<Type>())
            {
                return LieGroupType<2>::identity();
            }
            const Type s = translotator::sin(isomorphicVec.x());
            const Type c = translotator::cos(isomorphicVec.x());
            return LieGroupType<2>{{c, -s,
                                    s, c}};
        }

        static LieGroupType<3> Exp(const VectorType<3> &isomorphicVec)
        {
            return UnitQuaternion<Type>{isomorphicVec}.toRotMatrix3D();
        }

        static VectorType<2> Log(const LieGroupType<2> &lieGroup)
        {
            return VectorType<2>{{translotator::atan2(lieGroup(1, 0), lieGroup(0, 0))}};
        }

        static VectorType<3> Log(const LieGroupType<3> &lieGroup)
        {
            const Type trace = lieGroup.trace();
            const Type t = translotator::acos((trace - static_cast<Type>(1)) / static_cast<Type>(2));
            if (translotator::abs(t) <= epsilon<Type>())
            {
                return VectorType<3>{{0.f, 0.f, 0.f}};
            }
            const Type k = t / (static_cast<Type>(2) * translotator::sin(t));

            return k * VectorType<3>{{lieGroup(2, 1) - lieGroup(1, 2),
                                      lieGroup(0, 2) - lieGroup(2, 0),
                                      lieGroup(1, 0) - lieGroup(0, 1)}};
        }

        static LieGroupType<2> exp(const LieAlgebraType<2> &lieAlgebra)
        {
            return Exp(LieAlgebra2Vector(lieAlgebra));
        }

        static LieGroupType<3> exp(const LieAlgebraType<3> &lieAlgebra)
        {
            return Exp(LieAlgebra2Vector(lieAlgebra));
        }

        static LieAlgebraType<2> log(const LieGroupType<2> &lieGroup)
        {
            return Vector2LieAlgebra(Log(lieGroup));
        }

        static LieAlgebraType<3> log(const LieGroupType<3> &lieGroup)
        {
            return Vector2LieAlgebra(Log(lieGroup));
        }
    };

    template <typename Type>
    using LieOperator_SO = LieOperator<ObjectType::SO_GROUP, Type>;
    using LieOperator_SOf = LieOperator_SO<float>;
    using LieOperator_SOd = LieOperator_SO<double>;
    using LieOperator_SOld = LieOperator_SO<long double>;
}
```


