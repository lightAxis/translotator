/**
 * @file micro_type_traits.hpp
 *
 * very small part of std type_traits
 * is_same implementation
 */

#pragma once

namespace translotator
{
    //  enable_if
    template <bool B, typename T = void>
    struct enable_if
    {
    };
    template <typename T>
    struct enable_if<true, T>
    {
        using type = T;
    };

    // enable_if_t
    template <bool B, typename T = void>
    using enable_if_t = typename enable_if<B, T>::type;

    // conditional_if
    template <bool B, typename T, typename F>
    struct conditional_if
    {
        using type = T;
    };
    template <typename T, typename F>
    struct conditional_if<false, T, F>
    {
        using type = F;
    };

    // conditional_if_t
    template <bool B, typename T, typename F>
    using conditional_if_t = typename conditional_if<B, T, F>::type;

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

    // all_same
    template <typename T, typename... Args>
    struct all_same;
    template <typename T>
    struct all_same<T>
    {
        static constexpr bool value = true;
    };
    template <typename T, typename First, typename... Rest>
    struct all_same<T, First, Rest...>
    {
        static constexpr bool value = is_same_v<T, First> && all_same<T, Rest...>::value;
    };

    // all_same_v
    template <typename T, typename... Args>
    inline constexpr bool all_same_v = all_same<T, Args...>::value;

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

    // is_matrix_base

    template <typename T, typename = void>
    struct is_matrix_base : false_type
    {
    };
    template <typename T>
    struct is_matrix_base<T, typename enable_if<T::MATRIX_BASE>::type> : true_type
    {
    };

    // is_matrix_base_v
    template <typename T>
    inline constexpr bool is_matrix_base_v = is_matrix_base<T>::value;
}