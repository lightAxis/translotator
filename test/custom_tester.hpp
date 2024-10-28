#pragma once

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#endif

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_template_test_macros.hpp>
#include <catch2/matchers/catch_matchers_all.hpp>

#include <translotator/objects/objectdefs.hpp>

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

template <typename T>
bool close_enough(T lhs, T rhs)
{
    return std::abs(lhs - rhs) < static_cast<T>(0.0001f);
}

template <size_t N, size_t M, typename Type>
bool close_enough(const translotator::Matrix<N, M, Type> &lhs, const translotator::Matrix<N, M, Type> &rhs)
{
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < M; j++)
            if (!close_enough(lhs(i, j), rhs(i, j)))
                return false;
    return true;
}

template <size_t N, typename Type>
bool close_enough(const translotator::Vector<N, Type> &lhs, const translotator::Vector<N, Type> &rhs)
{
    for (size_t i = 0; i < N; i++)
        if (!close_enough(lhs[i], rhs[i]))
            return false;
    return true;
}

template <typename T>
struct EqualsMatrixMatcher : Catch::Matchers::MatcherGenericBase
{
    EqualsMatrixMatcher(T const &v) : val{v} {}

    bool match(T const &other) const
    {
        return close_enough(val, other);
    }

    std::string describe() const override
    {
        // std::stringstream ss0;
        // ss0 << val;
        return "no\n";
    }

private:
    T const &val;
};

template <typename T>
auto EqualsMatrix(const T &v) -> EqualsMatrixMatcher<T>
{
    return EqualsMatrixMatcher<T>{v};
}
