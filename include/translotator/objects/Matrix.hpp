#pragma once

#include "../utils/default_type.hpp"
#include "../utils/micro_math.hpp"
#include "../utils/epsilon.hpp"

#include <stddef.h>
#include <assert.h>

namespace translotator
{
    template <size_t N, size_t M, typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class Matrix
    {
    protected:
        Type data_[N][M]{};

    public:
        /**
         * Constructor
         */

        Matrix() = default;
        Matrix(const Matrix &other);
        Matrix(const Type data[N][M]);
        Matrix(const Type data[N * M]);

        /**
         * Constant Matrices
         */
        static Matrix eye();   // Identity matrix
        static Matrix zeros(); // Zero matrix
        static Matrix ones();  // Ones matrix
        static Matrix NaN();   // NaN matrix

        /**
         * Accessors
         */
        inline const Type &operator()(size_t i, size_t j) const;
        inline Type &operator()(size_t i, size_t j);
        inline Matrix<N, 1, Type> col(size_t j) const;
        inline Matrix<1, M, Type> row(size_t i) const;
        template <size_t P, size_t Q>
        inline Matrix<P, Q, Type> block(size_t i, size_t j) const;
        template <size_t i, size_t j, size_t P, size_t Q>
        inline Matrix<P, Q, Type> block() const;

        /**
         * Assignments
         */
        inline Matrix &operator=(const Matrix &other);
        template <size_t P, size_t Q>
        inline Matrix &setBlock(size_t i, size_t j, const Matrix<P, Q, Type> &block);
        inline Matrix &setRow(size_t i, const Matrix<1, M, Type> &row);
        inline Matrix &setCol(size_t j, const Matrix<N, 1, Type> &col);
        template <size_t i, size_t j, size_t P, size_t Q>
        inline Matrix &setBlock(const Matrix<P, Q, Type> &block);
        template <size_t i>
        inline Matrix &setRow(const Matrix<1, M, Type> &row);
        template <size_t j>
        inline Matrix &setCol(const Matrix<N, 1, Type> &col);

        /**
         * Operators
         */
        inline Matrix operator*(Type v) const;
        inline Matrix operator/(Type v) const;
        inline void operator*=(Type v);
        inline void operator/=(Type v);
        inline Matrix operator+(const Matrix &other) const;
        inline Matrix operator-(const Matrix &other) const;
        template <size_t L>
        inline Matrix<N, L, Type> operator*(const Matrix<N, L, Type> &other) const;
        inline void operator+=(const Matrix &other);
        inline void operator-=(const Matrix &other);
        inline void operator*=(const Matrix<N, M, Type> &other);

        inline friend Matrix operator*(Type lhs, const Matrix &rhs) { return rhs * lhs; }

        /**
         * Utils
         */
        inline Matrix<M, N, Type> T() const; // Transpose
        inline void fill(const Type &v);
        inline void print() const;

    private:
        template <size_t N_, size_t M_, typename Type_>
        friend class Matrix;

        template <size_t N_, typename Type_>
        friend class Vector;
    };

    template <size_t N, size_t M>
    using Matrixf = Matrix<N, M, float>;
    template <size_t N, size_t M>
    using Matrixd = Matrix<N, M, double>;
    template <size_t N, size_t M>
    using Matrixld = Matrix<N, M, long double>;

    // ############################################
    // ##              IMPLEMENTATION            ##
    // ############################################

    /**
     * Constructor
     */
    template <size_t N, size_t M, typename Type>
    Matrix<N, M, Type>::Matrix(const Matrix &other)
    {
        memcpy(data_, other.data_, N * M * sizeof(Type));
    }

    template <size_t N, size_t M, typename Type>
    Matrix<N, M, Type>::Matrix(const Type data[N * M])
    {
        memcpy(data_, data, N * M * sizeof(Type));
    }

    template <size_t N, size_t M, typename Type>
    Matrix<N, M, Type>::Matrix(const Type data[N][M])
    {
        memcpy(data_, data, N * M * sizeof(Type));
    }

    /**
     * Constant Matrices
     */
    template <size_t N, size_t M, typename Type>
    Matrix<N, M, Type> Matrix<N, M, Type>::eye() // Identity matrix
    {
        size_t min = N < M ? N : M;
        Matrix<N, M, Type> result;
        result.fill(static_cast<Type>(0));
        for (size_t i = 0; i < min; i++)
        {
            result(i, i) = 1;
        }
        return result;
    }

    template <size_t N, size_t M, typename Type>
    Matrix<N, M, Type> Matrix<N, M, Type>::zeros() // Zero matrix
    {
        Matrix<N, M, Type> result;
        result.fill(static_cast<Type>(0));
        return result;
    }

    template <size_t N, size_t M, typename Type>
    Matrix<N, M, Type> Matrix<N, M, Type>::ones() // Ones matrix
    {
        Matrix<N, M, Type> result;
        result.fill(static_cast<Type>(1));
        return result;
    }

    template <size_t N, size_t M, typename Type>
    Matrix<N, M, Type> Matrix<N, M, Type>::NaN() // NaN matrix
    {
        Matrix<N, M, Type> result;
        result.fill(static_cast<Type>(NAN));
        return result;
    }

    /**
     * Accessors
     */

    template <size_t N, size_t M, typename Type>
    inline const Type &Matrix<N, M, Type>::operator()(size_t i, size_t j) const
    {
        assert(i < N && j < M);
        return data_[i][j];
    }

    template <size_t N, size_t M, typename Type>
    inline Type &Matrix<N, M, Type>::operator()(size_t i, size_t j)
    {
        assert(i < N && j < M);
        return data_[i][j];
    }

    template <size_t N, size_t M, typename Type>
    inline Matrix<N, 1, Type> Matrix<N, M, Type>::col(size_t j) const
    {
        assert(j < M);
        Matrix<N, 1, Type> result;
        for (size_t i = 0; i < N; i++)
        {
            result(i, 0) = data_[i][j];
        }
        return result;
    }

    template <size_t N, size_t M, typename Type>
    inline Matrix<1, M, Type> Matrix<N, M, Type>::row(size_t i) const
    {
        assert(i < N);
        Matrix<1, M, Type> result;
        for (size_t j = 0; j < M; j++)
        {
            result(0, j) = data_[i][j];
        }
        return result;
    }

    template <size_t N, size_t M, typename Type>
    template <size_t P, size_t Q>
    inline Matrix<P, Q, Type> Matrix<N, M, Type>::block(size_t i, size_t j) const
    {
        assert(i + P <= N);
        assert(j + Q <= M);

        Matrix<P, Q, Type> result;
        for (size_t ii = 0; ii < P; ii++)
        {
            for (size_t jj = 0; jj < Q; jj++)
            {
                result(ii, jj) = data_[i + ii][j + jj];
            }
        }
        return result;
    }

    template <size_t N, size_t M, typename Type>
    template <size_t i, size_t j, size_t P, size_t Q>
    inline Matrix<P, Q, Type> Matrix<N, M, Type>::block() const
    {
        static_assert(i + P <= N, "Block out of bounds, Row");
        static_assert(j + Q <= M, "Block out of bounds, Col");
        return block<P, Q>(i, j);
    }

    /**
     * Assignments
     */
    template <size_t N, size_t M, typename Type>
    inline Matrix<N, M, Type> &Matrix<N, M, Type>::operator=(const Matrix<N, M, Type> &other)
    {
        memcpy(data_, other.data_, N * M * sizeof(Type));
        return *this;
    }

    template <size_t N, size_t M, typename Type>
    template <size_t P, size_t Q>
    inline Matrix<N, M, Type> &Matrix<N, M, Type>::setBlock(size_t i, size_t j, const Matrix<P, Q, Type> &block)
    {
        assert(i + P <= N);
        assert(j + Q <= M);

        for (size_t ii = 0; ii < P; ii++)
        {
            for (size_t jj = 0; jj < Q; jj++)
            {
                data_[i + ii][j + jj] = block(ii, jj);
            }
        }
        return *this;
    }

    template <size_t N, size_t M, typename Type>
    inline Matrix<N, M, Type> &Matrix<N, M, Type>::setRow(size_t i, const Matrix<1, M, Type> &row)
    {
        assert(i < N);
        for (size_t j = 0; j < M; j++)
        {
            data_[i][j] = row(0, j);
        }
        return *this;
    }

    template <size_t N, size_t M, typename Type>
    inline Matrix<N, M, Type> &Matrix<N, M, Type>::setCol(size_t j, const Matrix<N, 1, Type> &col)
    {
        assert(j < M);
        for (size_t i = 0; i < N; i++)
        {
            data_[i][j] = col(i, 0);
        }
        return *this;
    }

    template <size_t N, size_t M, typename Type>
    template <size_t i, size_t j, size_t P, size_t Q>
    inline Matrix<N, M, Type> &Matrix<N, M, Type>::setBlock(const Matrix<P, Q, Type> &block)
    {
        static_assert(i + P <= N, "Block out of bounds, Row");
        static_assert(j + Q <= M, "Block out of bounds, Col");
        return setBlock(i, j, block);
    }

    template <size_t N, size_t M, typename Type>
    template <size_t i>
    inline Matrix<N, M, Type> &Matrix<N, M, Type>::setRow(const Matrix<1, M, Type> &row)
    {
        static_assert(i < N, "Row out of bounds");
        return setRow(i, row);
    }

    template <size_t N, size_t M, typename Type>
    template <size_t j>
    inline Matrix<N, M, Type> &Matrix<N, M, Type>::setCol(const Matrix<N, 1, Type> &col)
    {
        static_assert(j < M, "Col out of bounds");
        return setCol(j, col);
    }

    /**
     * Operators
     */
    template <size_t N, size_t M, typename Type>
    inline Matrix<N, M, Type> Matrix<N, M, Type>::operator*(Type v) const
    {
        Matrix<N, M, Type> result;
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                result(i, j) = data_[i][j] * v;
        return result;
    }

    template <size_t N, size_t M, typename Type>
    inline Matrix<N, M, Type> Matrix<N, M, Type>::operator/(Type v) const
    {
        Matrix<N, M, Type> result;
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                result(i, j) = data_[i][j] / v;
        return result;
    }

    template <size_t N, size_t M, typename Type>
    inline void Matrix<N, M, Type>::operator*=(Type v)
    {
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                data_[i][j] *= v;
    }

    template <size_t N, size_t M, typename Type>
    inline void Matrix<N, M, Type>::operator/=(Type v)
    {
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                data_[i][j] /= v;
    }

    template <size_t N, size_t M, typename Type>
    inline Matrix<N, M, Type> Matrix<N, M, Type>::operator+(const Matrix<N, M, Type> &other) const
    {
        Matrix<N, M, Type> result;
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                result(i, j) = data_[i][j] + other(i, j);
        return result;
    }

    template <size_t N, size_t M, typename Type>
    inline Matrix<N, M, Type> Matrix<N, M, Type>::operator-(const Matrix<N, M, Type> &other) const
    {
        Matrix<N, M, Type> result;
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                result(i, j) = data_[i][j] - other(i, j);
        return result;
    }

    template <size_t N, size_t M, typename Type>
    template <size_t L>
    inline Matrix<N, L, Type> Matrix<N, M, Type>::operator*(const Matrix<N, L, Type> &other) const
    {
        Matrix<N, L, Type> result;
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < L; j++)
                for (size_t k = 0; k < M; k++)
                    result(i, j) += data_[i][k] * other(k, j);
        return result;
    }

    template <size_t N, size_t M, typename Type>
    inline void Matrix<N, M, Type>::operator+=(const Matrix<N, M, Type> &other)
    {
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                data_[i][j] += other(i, j);
    }

    template <size_t N, size_t M, typename Type>
    inline void Matrix<N, M, Type>::operator-=(const Matrix<N, M, Type> &other)
    {
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                data_[i][j] -= other(i, j);
    }

    template <size_t N, size_t M, typename Type>
    inline void Matrix<N, M, Type>::operator*=(const Matrix<N, M, Type> &other)
    {
        *this = *this * other;
    }

    /**
     * Utils
     */
    template <size_t N, size_t M, typename Type>
    inline Matrix<M, N, Type> Matrix<N, M, Type>::T() const // Transpose
    {
        Matrix<M, N, Type> result;
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                result(j, i) = data_[i][j];
        return result;
    }

    template <size_t N, size_t M, typename Type>
    inline void Matrix<N, M, Type>::fill(const Type &v)
    {
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                data_[i][j] = v;
    }

    template <size_t N, size_t M, typename Type>
    inline void Matrix<N, M, Type>::print() const
    {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                printf("%f ", static_cast<float>(data_[i][j]));
            }
            printf("\n");
        }
    }
}
