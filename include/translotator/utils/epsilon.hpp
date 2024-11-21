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
 * @file : epsilon.hpp
 */

#pragma once

#include "../config.hpp"
#include "micro_type_traits.hpp"
#include <cstddef>

namespace translotator
{
    /**
     * @brief epsilon for floating point
     */
    template <typename T, size_t N>
    constexpr T exponent_epsilon()
    {
        static_assert(is_float_v<T> && 1U <= N && N <= 20U, "exponent_epsilon only supports float, double, long double and 1 <= N <= 20");
        if constexpr (N == 1U) // TODO change all template variables + U for neat and clean code
            return static_cast<T>(1e-1L);
        else if constexpr (N == 2U)
            return static_cast<T>(1e-2L);
        else if constexpr (N == 3U)
            return static_cast<T>(1e-3L);
        else if constexpr (N == 4U)
            return static_cast<T>(1e-4L);
        else if constexpr (N == 5U)
            return static_cast<T>(1e-5L);
        else if constexpr (N == 6U)
            return static_cast<T>(1e-6L);
        else if constexpr (N == 7U)
            return static_cast<T>(1e-7L);
        else if constexpr (N == 8U)
            return static_cast<T>(1e-8L);
        else if constexpr (N == 9U)
            return static_cast<T>(1e-9L);
        else if constexpr (N == 10U)
            return static_cast<T>(1e-10L);
        else if constexpr (N == 11U)
            return static_cast<T>(1e-11L);
        else if constexpr (N == 12U)
            return static_cast<T>(1e-12L);
        else if constexpr (N == 13U)
            return static_cast<T>(1e-13L);
        else if constexpr (N == 14U)
            return static_cast<T>(1e-14L);
        else if constexpr (N == 15U)
            return static_cast<T>(1e-15L);
        else if constexpr (N == 16U)
            return static_cast<T>(1e-16L);
        else if constexpr (N == 17U)
            return static_cast<T>(1e-17L);
        else if constexpr (N == 18U)
            return static_cast<T>(1e-18L);
        else if constexpr (N == 19U)
            return static_cast<T>(1e-19L);
        else if constexpr (N == 20U)
            return static_cast<T>(1e-20L);
    }

    /**
     * @brief epsilon for floating point
     * @tparam T floating point type
     * @details epsilon is a small value that is used to compare floating point numbers.
     */
    template <typename T>
    constexpr T epsilon()
    {
        static_assert(is_float_v<T>, "epsilon only supports float, double, long double");

        if constexpr (is_same_v<T, float>)
            return exponent_epsilon<float, CONFIG_TRANSLOTATOR_DEFAULT_FLOATING_POINT_PRECISION_32_EPSILON>();
        if constexpr (is_same_v<T, double>)
            return exponent_epsilon<double, CONFIG_TRANSLOTATOR_DEFAULT_FLOATING_POINT_PRECISION_64_EPSILON>();
        if constexpr (is_same_v<T, long double>)
            return exponent_epsilon<long double, CONFIG_TRANSLOTATOR_DEFAULT_FLOATING_POINT_PRECISION_128_EPSILON>();
        else
            static_assert(is_float_v<T>, "epsilon only supports float, double, long double");
    }
}