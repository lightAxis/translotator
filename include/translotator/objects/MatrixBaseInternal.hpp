#pragma once

// #include "../utils/micro_type_traits.hpp"
// #include "objectdefs.hpp"

namespace translotator::MatrixBaseInternal
{
    template <typename Derived, typename OtherDerived>
    struct operator_mul_typemapper
    {
        using type = Matrix<Derived::ROWS, OtherDerived::COLS, typename Derived::DATATYPE>;
    };

    template <size_t N, size_t M, typename Type>
    struct operator_mul_typemapper<Matrix<N, M, Type>, Vector<M, Type>>
    {
        using type = Vector<N, Type>;
    };

    template <typename Derived, typename NewType>
    struct operator_cast_typemapper
    {
    };

    template <typename NewType, size_t N, size_t M, typename Type>
    struct operator_cast_typemapper<Matrix<N, M, Type>, NewType>
    {
        using type = Matrix<N, M, NewType>;
    };

    template <typename NewType, size_t N, typename Type>
    struct operator_cast_typemapper<Vector<N, Type>, NewType>
    {
        using type = Vector<N, NewType>;
    };

}