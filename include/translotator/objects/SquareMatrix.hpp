#pragma once

namespace translotator
{

    template <size_t N, typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class SquareMatrix : public MatrixBase<N, N, Type, SquareMatrix<N, Type>>
    {
    private:
        inline Type &Data_(size_t i, size_t j) { return (*this)(i, j); }
        inline Type Data_(size_t i, size_t j) const { return (*this)(i, j); }

    public:
        constexpr static ObjectType OBJECT_TYPE = ObjectType::SQUARE_MATRIX;
        using MatrixBase<N, N, Type, SquareMatrix<N, Type>>::MatrixBase;

        inline Type determinant() const
        {
            static_assert(N == 2 || N == 3, "Only 2x2, 3x3 matrices are supported");
            if constexpr (N == 2)
            {
                return Data_(0, 0) * Data_(1, 1) - Data_(0, 1) * Data_(1, 0);
            }
            else if constexpr (N == 3)
            {
                return Data_(0, 0) * (Data_(1, 1) * Data_(2, 2) - Data_(1, 2) * Data_(2, 1)) -
                       Data_(0, 1) * (Data_(1, 0) * Data_(2, 2) - Data_(1, 2) * Data_(2, 0)) +
                       Data_(0, 2) * (Data_(1, 0) * Data_(2, 1) - Data_(1, 1) * Data_(2, 0));
            }

            return 0;
        }

        inline Type trace() const
        {
            Type result = 0;
            for (size_t i = 0; i < N; i++)
                result += Data_(i, i);
            return result;
        }

        /**
         * 1x1 ~ 3x3 closed form solution
         * 4x4 ~ LU factorization with partial pivotting
         * from PX4-Matrix Library
         */
        SquareMatrix<N, Type> inversed(bool &result) const
        {

            if constexpr (N == 1) // special case for 1x1 matrix
            {
                if (translotator::abs(Data_(0, 0)) < translotator::epsilon<Type>())
                {
                    result = false;
                    return SquareMatrix<N, Type>::zero();
                }

                result = true;
                return SquareMatrix<N, Type>{{1.0f / Data_(0, 0)}};
            }
            else if constexpr (N == 2) // special case for 2x2 matrix
            {
                const Type det = determinant();
                if (translotator::abs(det) < translotator::epsilon<Type>())
                {
                    result = false;
                    return SquareMatrix<N, Type>::zeros();
                }

                result = true;
                return SquareMatrix<N, Type>{{Data_(1, 1) / det, -Data_(0, 1) / det,
                                              -Data_(1, 0) / det, Data_(0, 0) / det}};
            }
            else if constexpr (N == 3) // special case for 3x3 matrix
            {
                const Type det = determinant();
                if (translotator::abs(det) < translotator::epsilon<Type>())
                {
                    result = false;
                    return SquareMatrix<N, Type>::zeros();
                }

                result = true;
                return SquareMatrix<N, Type>{{(Data_(1, 1) * Data_(2, 2) - Data_(1, 2) * Data_(2, 1)) / det,
                                              (Data_(0, 2) * Data_(2, 1) - Data_(0, 1) * Data_(2, 2)) / det,
                                              (Data_(0, 1) * Data_(1, 2) - Data_(0, 2) * Data_(1, 1)) / det,
                                              (Data_(1, 2) * Data_(2, 0) - Data_(1, 0) * Data_(2, 2)) / det,
                                              (Data_(0, 0) * Data_(2, 2) - Data_(0, 2) * Data_(2, 0)) / det,
                                              (Data_(0, 2) * Data_(1, 0) - Data_(0, 0) * Data_(1, 2)) / det,
                                              (Data_(1, 0) * Data_(2, 1) - Data_(1, 1) * Data_(2, 0)) / det,
                                              (Data_(0, 1) * Data_(2, 0) - Data_(0, 0) * Data_(2, 1)) / det,
                                              (Data_(0, 0) * Data_(1, 1) - Data_(0, 1) * Data_(1, 0)) / det}};
            }

            constexpr size_t RANK = N;

            SquareMatrix<N, Type> L{SquareMatrix<N, Type>::eye()};
            SquareMatrix<N, Type> U = (*this);
            SquareMatrix<N, Type> P{SquareMatrix<N, Type>::eye()};

            // for all diagonal elements
            for (size_t n = 0; n < RANK; n++)
            {
                // if diagonal is zero, swap with row below
                if (translotator::abs(U(n, n)) < translotator::epsilon<Type>())
                {
                    // printf("trying pivot for row %d\n",n);
                    for (size_t i = n + 1; i < RANK; i++)
                    {

                        // printf("\ttrying row %d\n",i);
                        if (translotator::abs(U(i, n)) > translotator::epsilon<Type>())
                        {
                            // printf("swapped %d\n",i);
                            U.swapRows(i, n);
                            P.swapRows(i, n);
                            L.swapRows(i, n);
                            L.swapCols(i, n);
                            break;
                        }
                    }
                }

                // failsafe, return zero matrix
                if (translotator::abs(U(n, n)) < translotator::epsilon<Type>())
                {
                    result = false;
                    return P;
                }

                // for all rows below diagonal
                for (size_t i = (n + 1); i < RANK; i++)
                {
                    L(i, n) = U(i, n) / U(n, n);

                    // add i-th row and n-th row
                    // multiplied by: -a(i,n)/a(n,n)
                    for (size_t k = n; k < RANK; k++)
                    {
                        U(i, k) -= L(i, n) * U(n, k);
                    }
                }
            }

            // solve LY=P*I for Y by forward subst
            // SquareMatrix<Type, M> Y = P;

            // for all columns of Y
            for (size_t c = 0; c < RANK; c++)
            {
                // for all rows of L
                for (size_t i = 0; i < RANK; i++)
                {
                    // for all columns of L
                    for (size_t j = 0; j < i; j++)
                    {
                        // for all existing y
                        // subtract the component they
                        // contribute to the solution
                        P(i, c) -= (L(i, j) * P(j, c));
                    }

                    // divide by the factor
                    // on current
                    // term to be solved
                    // Y(i,c) /= L(i,i);
                    // but L(i,i) = 1.0
                }
            }

            // solve Ux=y for x by back subst
            // SquareMatrix<Type, M> X = Y;

            // for all columns of X
            for (size_t c = 0; c < RANK; c++)
            {
                // for all rows of U
                for (size_t k = 0; k < RANK; k++)
                {
                    // have to go in reverse order
                    size_t i = RANK - 1 - k;

                    // for all columns of U
                    for (size_t j = i + 1; j < RANK; j++)
                    {
                        // for all existing x
                        // subtract the component they
                        // contribute to the solution
                        P(i, c) -= (U(i, j) * P(j, c));
                    }

                    // divide by the factor
                    // on current
                    // term to be solved
                    //
                    // we know that U(i, i) != 0 from above
                    P(i, c) /= U(i, i);
                }
            }

            // check sanity of results
            for (size_t i = 0; i < RANK; i++)
            {
                for (size_t j = 0; j < RANK; j++)
                {
                    if (!__builtin_isfinite(P(i, j)))
                    {
                        result = false;
                        return P;
                    }
                }
            }
            // printf("X:\n"); X.print();
            result = true;
            return P;
        }

        inline void inverse() { *this = inversed(); }
    };

    template <size_t N>
    using SquareMatrixf = SquareMatrix<N, float>;
    template <size_t N>
    using SquareMatrixd = SquareMatrix<N, double>;
    template <size_t N>
    using SquareMatrixld = SquareMatrix<N, long double>;
}