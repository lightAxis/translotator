#pragma once

namespace translotator
{
    template <size_t N, typename Type>
    struct initializer_list
    {
        Type data[N];

        template <typename... Args>
        initializer_list(Args... args) : data{args...}
        {
            static_assert(all_same_v<Type, Args...>, "Initializer list must have the same type");
            static_assert(sizeof...(args) == N, "Initializer list size must match matrix size");
        }
    };
}