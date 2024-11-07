#pragma once

// #include "../utils/micro_type_traits.hpp"
// #include "objectdefs.hpp"

namespace translotator::MatrixBaseInternal
{
    template <typename Derived, typename OtherDerived, typename Enable = void>
    struct operator_mul_typemapper
    {
    };

    template <typename Derived, typename OtherDerived>
    struct operator_mul_typemapper<Derived, OtherDerived,
                                   enable_if_t<Derived::ROWS != OtherDerived::COLS && OtherDerived::COLS != 1, void>>
    {
        using type = Matrix<Derived::ROWS, OtherDerived::COLS, typename Derived::DATATYPE>;
    };

    template <typename Derived, typename OtherDerived>
    struct operator_mul_typemapper<Derived, OtherDerived,
                                   enable_if_t<Derived::ROWS == OtherDerived::COLS && OtherDerived::COLS != 1, void>>
    {
        using type = SquareMatrix<Derived::ROWS, typename Derived::DATATYPE>;
    };

    template <typename Derived, typename OtherDerived>
    struct operator_mul_typemapper<Derived, OtherDerived,
                                   enable_if_t<Derived::ROWS == 1 && OtherDerived::COLS == 1, void>>
    {
        using type = typename Derived::DATATYPE;
    };

    template <typename Derived, typename OtherDerived>
    struct operator_mul_typemapper<Derived, OtherDerived,
                                   enable_if_t<Derived::ROWS != 1 && OtherDerived::COLS == 1, void>>
    {
        using type = Vector<Derived::ROWS, typename Derived::DATATYPE>;
    };

    // template <typename Derived, typename OtherDerived>
    //     struct operator_mul_typemapper < Derived,
    //     OtherDerived, enable_if_t < Derived::ROWS == 1 && OtherDerived::COL

    // template <size_t N, typename Type>
    // struct operator_mul_typemapper<SquareMatrix<N, Type>, SquareMatrix<N, Type>>
    // {
    //     using type = SquareMatrix<N, Type>;
    // };

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