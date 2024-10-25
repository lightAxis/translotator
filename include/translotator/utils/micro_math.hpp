#pragma once

#include <math.h>
#include "micro_type_traits.hpp"

namespace translotator
{

    template <typename T>
    inline T sqrt(const T &v)
    {

        if constexpr (is_same_v<T, float>)
            return ::sqrtf(v);
        else if constexpr (is_same_v<T, double>)
            return ::sqrt(v);
        else if constexpr (is_same_v<T, long double>)
            return ::sqrtl(v);
        else
            return static_cast<T>(0);
    }

    template <typename T>
    inline T sin(const T &v)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::sinf(v);
        else if constexpr (is_same_v<T, double>)
            return ::sin(v);
        else if constexpr (is_same_v<T, long double>)
            return ::sinl(v);
        return static_cast<T>(0);
    }

    template <typename T>
    inline T cos(const T &v)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::cosf(v);
        else if constexpr (is_same_v<T, double>)
            return ::cos(v);
        else if constexpr (is_same_v<T, long double>)
            return ::cosl(v);
        return static_cast<T>(0);
    }

    template <typename T>
    inline T tan(const T &v)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::tanf(v);
        else if constexpr (is_same_v<T, double>)
            return ::tan(v);
        else if constexpr (is_same_v<T, long double>)
            return ::tanl(v);
        return static_cast<T>(0);
    }

    template <typename T>
    inline T asin(const T &v)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::asinf(v);
        else if constexpr (is_same_v<T, double>)
            return ::asin(v);
        else if constexpr (is_same_v<T, long double>)
            return ::asinl(v);
        return static_cast<T>(0);
    }

    template <typename T>
    inline T acos(const T &v)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::acosf(v);
        else if constexpr (is_same_v<T, double>)
            return ::acos(v);
        else if constexpr (is_same_v<T, long double>)
            return ::acosl(v);
        return static_cast<T>(0);
    }

    template <typename T>
    inline T atan(const T &v)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::atanf(v);
        else if constexpr (is_same_v<T, double>)
            return ::atan(v);
        else if constexpr (is_same_v<T, long double>)
            return ::atanl(v);
        return static_cast<T>(0);
    }

    template <typename T>
    inline T atan2(const T &y, const T &x)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::atan2f(y, x);
        else if constexpr (is_same_v<T, double>)
            return ::atan2(y, x);
        else if constexpr (is_same_v<T, long double>)
            return ::atan2l(y, x);
        return static_cast<T>(0);
    }

    template <typename T>
    inline T fmin(const T &x, const T &y)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::fminf(x, y);
        else if constexpr (is_same_v<T, double>)
            return ::fmin(x, y);
        else if constexpr (is_same_v<T, long double>)
            return ::fminl(x, y);
        return static_cast<T>(0);
    }

    template <typename T>
    inline T fmax(const T &x, const T &y)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::fmaxf(x, y);
        else if constexpr (is_same_v<T, double>)
            return ::fmax(x, y);
        else if constexpr (is_same_v<T, long double>)
            return ::fmaxl(x, y);
        return static_cast<T>(0);
    }

    template <typename T>
    inline T powf(const T &x, const T &y)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::powf(x, y);
        else if constexpr (is_same_v<T, double>)
            return ::pow(x, y);
        else if constexpr (is_same_v<T, long double>)
            return ::powl(x, y);
        return static_cast<T>(0);
    }

    template <typename T>
    inline T square(const T &v) { return v * v; }

    template <typename T>
    inline T cube(const T &v) { return v * v * v; }

    template <typename T>
    inline T abs(const T &v) { return v < 0 ? -v : v; }

    template <typename T>
    inline T exp(const T &v)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::expf(v);
        else if constexpr (is_same_v<T, double>)
            return ::exp(v);
        else if constexpr (is_same_v<T, long double>)
            return ::expl(v);
        return static_cast<T>(0);
    }

    template <typename T>
    inline T ceil(const T &v)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::ceilf(v);
        else if constexpr (is_same_v<T, double>)
            return ::ceil(v);
        else if constexpr (is_same_v<T, long double>)
            return ::ceill(v);
        return static_cast<T>(0);
    }

    template <typename T>
    inline T floorf(const T &v)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::floorf(v);
        else if constexpr (is_same_v<T, double>)
            return ::floor(v);
        else if constexpr (is_same_v<T, long double>)
            return ::floorl(v);
        return static_cast<T>(0);
    }

    template <typename T>
    inline T ceilf(const T &v)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::ceilf(v);
        else if constexpr (is_same_v<T, double>)
            return ::ceil(v);
        else if constexpr (is_same_v<T, long double>)
            return ::ceill(v);
        return static_cast<T>(0);
    }

    template <typename T>
    inline T roundf(const T &v)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::roundf(v);
        else if constexpr (is_same_v<T, double>)
            return ::round(v);
        else if constexpr (is_same_v<T, long double>)
            return ::roundl(v);
        return static_cast<T>(0);
    }

    template <typename T>
    inline T truncf(const T &v)
    {
        static_assert(is_float_v<T>, "Unsupported type");
        if constexpr (is_same_v<T, float>)
            return ::truncf(v);
        else if constexpr (is_same_v<T, double>)
            return ::trunc(v);
        else if constexpr (is_same_v<T, long double>)
            return ::truncl(v);
        return static_cast<T>(0);
    }
}