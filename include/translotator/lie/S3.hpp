#pragma once

namespace translotator
{
    template <typename Type>
    struct LieOperator<ObjectType::UNIT_QUATERNION, Type>
    {
        static_assert(is_float_v<Type>, "Invalid data type for LieOperator. Must be float type");
        using LieGroupType = UnitQuaternion<Type>;
        using LieAlgebraType = Quaternion<Type>;
        using VectorType = Vector<3, Type>;

        static LieAlgebraType Vector2LieAlgebra(const VectorType &isomorphicVec)
        {
            return LieAlgebraType{static_cast<Type>(0), isomorphicVec};
        }

        static VectorType LieAlgebra2Vector(const LieAlgebraType &lieAlgebra)
        {
            return lieAlgebra.Im();
        }

        static LieGroupType Exp(const VectorType &isomorphicVec)
        {
            return LieGroupType{2 * isomorphicVec};
        }

        static VectorType Log(const LieGroupType &lieGroup)
        {
            const Type w = lieGroup.Re();
            if ((translotator::abs(w) - static_cast<Type>(1)) < epsilon<Type>())
            {
                return VectorType::zeros();
            }

            const VectorType v = lieGroup.Im();

            if (v.norm() < epsilon<Type>())
            {
                return VectorType::zeros();
            }

            return v.normalized() * translotator::acos(w);
        }

        static LieGroupType exp(const LieAlgebraType &lieAlgebra)
        {
            return Exp(LieAlgebra2Vector(lieAlgebra));
        }

        static LieAlgebraType log(const LieGroupType &lieGroup)
        {
            return Vector2LieAlgebra(Log(lieGroup));
        }
    };

    template <typename Type>
    using LieOperator_S3 = LieOperator<ObjectType::UNIT_QUATERNION, Type>;
    using LieOperator_S3f = LieOperator_S3<float>;
    using LieOperator_S3d = LieOperator_S3<double>;
    using LieOperator_S3ld = LieOperator_S3<long double>;
}