

# File MatrixBaseInternal.hpp

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**translotator**](dir_ffa3503b73a46a1fbf73d754da62ba14.md) **>** [**objects**](dir_d5306d4012edd8106bd4452d9b4e4e98.md) **>** [**MatrixBaseInternal.hpp**](MatrixBaseInternal_8hpp.md)

[Go to the documentation of this file](MatrixBaseInternal_8hpp.md)


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
 * @file : MatrixBaseInternal.hpp
 */

#pragma once

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
```


