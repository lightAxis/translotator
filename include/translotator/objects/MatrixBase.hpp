#pragma once

// #include <assert.h>
// #include <stddef.h>

// #include "../utils/default_type.hpp"
// #include "../utils/micro_math.hpp"
// #include "../utils/epsilon.hpp"

// #include "objectdefs.hpp"
// #include "MatrixBaseInternal.hpp"

namespace translotator
{

    template <size_t N, size_t M, typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE, typename Derived>
    class MatrixBase
    {
    protected:
        Type data_[N * M];

    public:
        constexpr static size_t ROWS = N;
        constexpr static size_t COLS = M;
        using DATATYPE = Type;

        /**
         * Constructors and destructor
         */
        MatrixBase() = default;
        MatrixBase(const MatrixBase &other) = default;
        MatrixBase(const Type data[N * M])
        {
            memcpy(data_, data, N * M * sizeof(Type));
        }
        MatrixBase(const Type data[N][M])
        {
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    data_[i * M + j] = data[i][j];
        }

        /**
         * Constant Matrices
         */

        static Derived eye()
        {
            Derived result;
            result.fill(static_cast<Type>(0));
            for (size_t i = 0; i < N; i++)
                result(i, i) = 1;
            return result;
        }

        static Derived zeros()
        {
            Derived result;
            result.fill(static_cast<Type>(0));
            return result;
        }

        static Derived ones()
        {
            Derived result;
            result.fill(static_cast<Type>(1));
            return result;
        }

        static Derived NaN()
        {
            Derived result;
            result.fill(static_cast<Type>(NAN));
            return result;
        }

        /**
         * Accessors
         */
        inline const Type &operator()(size_t i, size_t j) const
        {
            return data_[i * M + j];
        }
        inline Type &operator()(size_t i, size_t j)
        {
            return data_[i * M + j];
        }
        inline Matrix<N, 1, Type> col(size_t j) const
        {
            assert(j < M);
            Matrix<N, 1, Type> result;
            for (size_t i = 0; i < N; i++)
                result(i, 0) = data_[i * M + j];
            return result;
        }
        inline Matrix<1, M, Type> row(size_t i) const
        {
            assert(i < N);
            Matrix<1, M, Type> result;
            for (size_t j = 0; j < M; j++)
                result(0, j) = data_[i * M + j];
            return result;
        }
        template <size_t P, size_t Q>
        inline Matrix<P, Q, Type> block(size_t i, size_t j) const
        {
            static_assert(P <= N, "Block out of bounds, Row");
            static_assert(Q <= M, "Block out of bounds, Col");
            assert(i + P <= N);
            assert(j + Q <= M);
            Matrix<P, Q, Type> result;
            for (size_t ii = 0; ii < P; ii++)
                for (size_t jj = 0; jj < Q; jj++)
                    result(ii, jj) = data_[(i + ii) * M + j + jj];
            return result;
        }

        template <size_t i, size_t j, size_t P, size_t Q>
        inline Matrix<P, Q, Type> block() const
        {
            static_assert(i + P <= N, "Block out of bounds, Row");
            static_assert(j + Q <= M, "Block out of bounds, Col");
            return block<P, Q>(i, j);
        }

        /**
         * Assignments
         */
        inline Derived &operator=(const Derived &other)
        {
            memcpy(data_, other.data_, N * M * sizeof(Type));
            return static_cast<Derived &>(*this);
        }

        template <size_t P, size_t Q>
        inline Derived &setBlock(size_t i, size_t j, const Matrix<P, Q, Type> &block)
        {
            static_assert(P <= N, "Block out of bounds, Row");
            static_assert(Q <= M, "Block out of bounds, Col");
            assert(i + P <= N);
            assert(j + Q <= M);
            for (size_t ii = 0; ii < P; ii++)
                for (size_t jj = 0; jj < Q; jj++)
                    data_[(i + ii) * M + j + jj] = block(ii, jj);
            return static_cast<Derived &>(*this);
        }

        inline Derived &setRow(size_t i, const Matrix<1, M, Type> &row)
        {
            assert(i < N);
            for (size_t j = 0; j < M; j++)
                data_[i * M + j] = row(0, j);
            return static_cast<Derived &>(*this);
        }

        inline Derived &setCol(size_t j, const Matrix<N, 1, Type> &col)
        {
            assert(j < M);
            for (size_t i = 0; i < N; i++)
                data_[i * M + j] = col(i, 0);
            return static_cast<Derived &>(*this);
        }

        template <size_t i, size_t j, size_t P, size_t Q>
        inline Derived &setBlock(const Matrix<P, Q, Type> &block)
        {
            static_assert(i + P <= N, "Block out of bounds, Row");
            static_assert(j + Q <= M, "Block out of bounds, Col");
            return setBlock(i, j, block);
        }

        template <size_t i>
        inline Derived &setRow(const Matrix<1, M, Type> &row)
        {
            static_assert(i < N, "Row out of bounds");
            return setRow(i, row);
        }

        template <size_t j>
        inline Derived &setCol(const Matrix<N, 1, Type> &col)
        {
            static_assert(j < M, "Col out of bounds");
            return setCol(j, col);
        }

        /**
         * operators Scalar
         */
        inline Derived operator/(Type v) const
        {
            Derived result;
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    result(i, j) = data_[i * M + j] / v;
            return result;
        }
        inline void operator/=(Type v)
        {
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    data_[i * M + j] /= v;
        }
        inline friend Derived operator*(Type lhs, const Derived &rhs) { return rhs * lhs; }

        /**
         * Operator Objects
         */
        template <typename OtherDerived>
        inline Derived operator+(const OtherDerived &other) const
        {
            static_assert(Derived::ROWS == OtherDerived::ROWS && Derived::COLS == OtherDerived::COLS, "Matrix dimensions must be the same");
            static_assert(is_same_v<typename Derived::DATATYPE, typename OtherDerived::DATATYPE>, "Matrix data types must be the same");

            Derived result;
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    result(i, j) = data_[i * M + j] + other(i, j);
            return result;
        }
        template <typename OtherDerived>
        inline Derived operator-(const OtherDerived &other) const
        {
            static_assert(Derived::ROWS == OtherDerived::ROWS && Derived::COLS == OtherDerived::COLS, "Matrix dimensions must be the same");
            static_assert(is_same_v<typename Derived::DATATYPE, typename OtherDerived::DATATYPE>, "Matrix data types must be the same");

            Derived result;
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    result(i, j) = data_[i * M + j] - other(i, j);
            return result;
        }
        template <typename OtherDerived>
        inline auto operator*(const OtherDerived &other) const
        {
            static_assert(Derived::COLS == OtherDerived::ROWS, "Matrix dimensions must be the same");
            static_assert(is_same_v<typename Derived::DATATYPE, typename OtherDerived::DATATYPE>, "Matrix data types must be the same");

            typename MatrixBaseInternal::operator_mul_typemapper<Derived, OtherDerived>::type result;
            result.fill(static_cast<Type>(0));
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < OtherDerived::COLS; j++)
                    for (size_t k = 0; k < M; k++)
                        result(i, j) += (*this)(i, k) * other(k, j);
            return result;
        }
        inline Derived operator*(const Type &v) const
        {
            Derived result;
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    result(i, j) = data_[i * M + j] * v;
            return result;
        }
        template <typename OtherDerived>
        inline void operator+=(const OtherDerived &other)
        {
            static_assert(Derived::ROWS == OtherDerived::ROWS && Derived::COLS == OtherDerived::COLS, "Matrix dimensions must be the same");
            static_assert(is_same_v<typename Derived::DATATYPE, typename OtherDerived::DATATYPE>, "Matrix data types must be the same");

            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    data_[i * M + j] += other(i, j);
        }
        template <typename OtherDerived>
        inline void operator-=(const OtherDerived &other)
        {
            static_assert(Derived::ROWS == OtherDerived::ROWS && Derived::COLS == OtherDerived::COLS, "Matrix dimensions must be the same");
            static_assert(is_same_v<typename Derived::DATATYPE, typename OtherDerived::DATATYPE>, "Matrix data types must be the same");

            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    data_[i * M + j] -= other(i, j);
        }
        template <typename OtherDerived>
        inline void operator*=(const OtherDerived &other)
        {
            *this = *this * other;
        }

        /**
         * Utils
         */

        inline Matrix<M, N, Type> T() const
        {
            Matrix<M, N, Type> result;
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    result(j, i) = data_[i * M + j];
            return result;
        }

        inline Vector<M, Type> T_toVec() const
        {
            Vector<M, Type> result;
            for (size_t i = 0; i < M; i++)
                result(i) = data_[i];
            return result;
        }

        inline void fill(const Type &v)
        {
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    data_[i * M + j] = v;
        }

        inline void print()
        {
            for (size_t i = 0; i < N; i++)
            {
                for (size_t j = 0; j < M; j++)
                {
                    printf("%f ", static_cast<double>(data_[i * M + j]));
                }
                printf("\n");
            }
        }

        /**
         * Type Casting
         */
        template <typename NewType>
        inline auto cast() const
        {
            typename MatrixBaseInternal::operator_cast_typemapper<Derived, NewType>::type result;
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    result(i, j) = static_cast<NewType>(data_[i * M + j]);
            return result;
        }

        template <typename NewContainer>
        inline NewContainer castContainer() const;

    private:
    };

}