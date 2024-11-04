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
    template <size_t N, size_t M, typename Type, typename Derived>
    inline Matrix<N, M, Type> MatrixBase<N, M, Type, Derived>::toMatrix() const
    {
        static_assert(!is_same_v<Derived, Matrix<N, M, Type>>, "Cannot cast to same type");
        return castContainer<Matrix<N, M, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline SquareMatrix<N, Type> MatrixBase<N, M, Type, Derived>::toSquareMatrix() const
    {
        static_assert(!is_same_v<Derived, SquareMatrix<N, Type>>, "Cannot cast to same type");
        return castContainer<SquareMatrix<N, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t Dim, typename>
    inline Vector<N, Type> MatrixBase<N, M, Type, Derived>::toVector() const
    {
        static_assert(!is_same_v<Derived, Vector<N, Type>>, "Cannot cast to same type");
        return castContainer<Vector<N, Type>>();
    }

    template <size_t N, size_t M, typename Type, typename Derived>
    template <typename NewDerived>
    inline NewDerived &MatrixBase<N, M, Type, Derived>::castContainerRef()
    {
        static_assert(NewDerived::ROWS == N, "Matrix dimensions must be the same");
        static_assert(NewDerived::COLS == M, "Matrix dimensions must be the same");
        static_assert(is_same_v<typename NewDerived::DATATYPE, Type>, "Matrix data types must be the same");

        return reinterpret_cast<NewDerived &>(*this);
    };
    template <size_t N, size_t M, typename Type, typename Derived>
    inline Matrix<N, M, Type> &MatrixBase<N, M, Type, Derived>::toMatrixRef()
    {
        return castContainerRef<Matrix<N, M, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline SquareMatrix<N, Type> &MatrixBase<N, M, Type, Derived>::toSquareMatrixRef()
    {
        static_assert(N == M, "Matrix must be square");
        return castContainerRef<SquareMatrix<N, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t Dim, typename>
    inline Vector<N, Type> &MatrixBase<N, M, Type, Derived>::toVectorRef()
    {
        static_assert(M == 1, "Matrix must be a column vector");
        return castContainerRef<Vector<N, Type>>();
    }

}
