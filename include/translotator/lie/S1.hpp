#pragma once

namespace translotator
{
    template <typename Type>
    struct LieOperator<ObjectType::UNIT_COMPLEX_NUM, Type>
    {
        static_assert(is_float_v<Type>, "Invalid data type for LieOperator. Must be float type");

        using LieGroupType = UnitComplexNum<Type>;
        using LieAlgebraType = ComplexNum<Type>;
        using VectorType = Vector<1, Type>;

        static LieAlgebraType Vector2LieAlgebra(const VectorType &isomorphicVec)
        {
            return LieAlgebraType{static_cast<Type>(0), isomorphicVec.toScalar()};
        }

        static VectorType LieAlgebra2Vector(const LieAlgebraType &lieAlgebra)
        {
            return VectorType{lieAlgebra.Im()};
        }

        static LieGroupType Exp(const VectorType &vec)
        {
            return LieGroupType{vec.toScalar()};
        }

        static VectorType Log(const LieGroupType &lieGroup)
        {
            return VectorType{translotator::acos(lieGroup.Re())};
        }

        static LieGroupType exp(const LieAlgebraType &lieAlgebra)
        {
            return Exp(LieAlgebra2Vector(lieAlgebra));
        }

        static VectorType log(const LieGroupType &lieGroup)
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