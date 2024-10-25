/**
 * @file micro_type_traits.hpp
 *
 * very small part of std type_traits
 * is_same implementation
 */

#pragma once

namespace translotator
{
    // integral constant
    template <typename T, T v>
    struct integral_constant
    {
        static constexpr T value = v;
        using value_type = T;
        using type = integral_constant;
        constexpr operator value_type() const noexcept { return value; }
        constexpr value_type operator()() const noexcept { return value; }
    };

    // true false type
    using true_type = integral_constant<bool, true>;
    using false_type = integral_constant<bool, false>;

    // is_same
    template <typename T, typename U>
    struct is_same : false_type
    {
    };

    template <typename T>
    struct is_same<T, T> : true_type
    {
    };

    // is_same_v
    template <typename T, typename U>
    inline constexpr bool is_same_v = is_same<T, U>::value;

    // is_float
    template <typename T>
    struct is_float : false_type
    {
    };

    template <>
    struct is_float<float> : true_type
    {
    };

    template <>
    struct is_float<double> : true_type
    {
    };

    template <>
    struct is_float<long double> : true_type
    {
    };

    // is_float_v
    template <typename T>
    inline constexpr bool is_float_v = is_float<T>::value;
}