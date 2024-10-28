#pragma once

namespace translotator
{
    template <size_t N, size_t M, typename Type, typename Derived>
    template <typename NewContainer>
    inline NewContainer MatrixBase<N, M, Type, Derived>::castContainer() const
    {
        static_assert(NewContainer::ROWS == N, "Matrix dimensions must be the same");
        static_assert(NewContainer::COLS == M, "Matrix dimensions must be the same");
        static_assert(is_same_v<typename NewContainer::DATATYPE, Type>, "Matrix data types must be the same");

        return NewContainer(data_);
    };
}