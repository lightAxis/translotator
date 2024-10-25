#pragma once

#include "../config.hpp"
#include "micro_type_traits.hpp"

namespace translotator
{
    template <typename T, int N>
    constexpr T exponent_epsilon()
    {
        static_assert(is_float_v<T> && 1 <= N && N <= 20, "exponent_epsilon only supports float, double, long double and 1 <= N <= 20");
        if constexpr (N == 1)
            return static_cast<T>(1e-1L);
        else if constexpr (N == 2)
            return static_cast<T>(1e-2L);
        else if constexpr (N == 3)
            return static_cast<T>(1e-3L);
        else if constexpr (N == 4)
            return static_cast<T>(1e-4L);
        else if constexpr (N == 5)
            return static_cast<T>(1e-5L);
        else if constexpr (N == 6)
            return static_cast<T>(1e-6L);
        else if constexpr (N == 7)
            return static_cast<T>(1e-7L);
        else if constexpr (N == 8)
            return static_cast<T>(1e-8L);
        else if constexpr (N == 9)
            return static_cast<T>(1e-9L);
        else if constexpr (N == 10)
            return static_cast<T>(1e-10L);
        else if constexpr (N == 11)
            return static_cast<T>(1e-11L);
        else if constexpr (N == 12)
            return static_cast<T>(1e-12L);
        else if constexpr (N == 13)
            return static_cast<T>(1e-13L);
        else if constexpr (N == 14)
            return static_cast<T>(1e-14L);
        else if constexpr (N == 15)
            return static_cast<T>(1e-15L);
        else if constexpr (N == 16)
            return static_cast<T>(1e-16L);
        else if constexpr (N == 17)
            return static_cast<T>(1e-17L);
        else if constexpr (N == 18)
            return static_cast<T>(1e-18L);
        else if constexpr (N == 19)
            return static_cast<T>(1e-19L);
        else if constexpr (N == 20)
            return static_cast<T>(1e-20L);
    }

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