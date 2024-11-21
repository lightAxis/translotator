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
 * @file : Matrix.hpp
 */

#pragma once

// #include "MatrixBase.hpp"

namespace translotator
{
    template <size_t N, size_t M, typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class Matrix : public MatrixBase<N, M, Type, Matrix<N, M, Type>>
    {
    public:
        constexpr static ObjectType OBJECT_TYPE = ObjectType::MATRIX;
        using MatrixBase<N, M, Type, Matrix<N, M, Type>>::MatrixBase;
    };

    template <size_t N, size_t M>
    using Matrixf = Matrix<N, M, float>;
    template <size_t N, size_t M>
    using Matrixd = Matrix<N, M, double>;
    template <size_t N, size_t M>
    using Matrixld = Matrix<N, M, long double>;
}