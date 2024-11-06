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
            {
                const Type a = lhs(i, j);
                const Type b = rhs(i, j);
                printf("lhs(%zu, %zu) = %f, rhs(%zu, %zu) = %f\n", i, j, static_cast<double>(a), i, j, static_cast<double>(b));
                lhs.print();
                rhs.print();
                return false;
            }

    return true;
}

template <size_t N, typename Type>
bool close_enough(const translotator::SquareMatrix<N, Type> &lhs, const translotator::SquareMatrix<N, Type> &rhs)
{
    return close_enough(lhs.cast2Matrix(), rhs.cast2Matrix());
}

template <size_t N, typename Type>
bool close_enough(const translotator::Vector<N, Type> &lhs, const translotator::Vector<N, Type> &rhs)
{
    return close_enough(lhs.cast2Matrix(), rhs.cast2Matrix());
}

template <typename Type>
bool close_enough(const translotator::ComplexNum<Type> &lhs, const translotator::ComplexNum<Type> &rhs)
{
    return close_enough(lhs.cast2Matrix(), rhs.cast2Matrix());
}

template <typename Type>
bool close_enough(const translotator::Quaternion<Type> &lhs, const translotator::Quaternion<Type> &rhs)
{
    return close_enough(lhs.cast2Matrix(), rhs.cast2Matrix());
}

template <typename Type>
bool close_enough(const translotator::UnitComplexNum<Type> &lhs, const translotator::UnitComplexNum<Type> &rhs)
{
    return close_enough(lhs.cast2Matrix(), rhs.cast2Matrix());
}

template <typename Type>
bool close_enough(const translotator::UnitQuaternion<Type> &lhs, const translotator::UnitQuaternion<Type> &rhs)
{
    return close_enough(lhs.cast2Matrix(), rhs.cast2Matrix());
}

template <typename Type>
bool close_enough(const translotator::AxisAngle<Type> &lhs, const translotator::AxisAngle<Type> &rhs)
{
    return close_enough(lhs.angle(), rhs.angle()) && close_enough(lhs.axis(), rhs.axis());
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
    T val;
};

template <typename T>
auto EqualsMatrix(const T &v) -> EqualsMatrixMatcher<T>
{
    return EqualsMatrixMatcher<T>{v};
}
