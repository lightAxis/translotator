#pragma once

namespace translotator
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
            return LieAlgebraType<2>{{0.f, -isomorphicVec.x(),
                                      isomorphicVec.x(), 0.f}};
        }
        static LieAlgebraType<3> Vector2LieAlgebra(const VectorType<3> &isomorphicVec)
        {
            return isomorphicVec.toCrossMatrix();
        }

        static VectorType<2> LieAlgebra2Vector(const LieAlgebraType<2> &lieAlgebra)
        {
            return VectorType<2>{{lieAlgebra(1, 2)}};
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