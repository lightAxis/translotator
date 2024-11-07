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
        constexpr static bool MATRIX_BASE = true;

        constexpr static size_t rowSize() { return N; }
        constexpr static size_t colSize() { return M; }

        /**
         * Constructors and destructor
         */
        MatrixBase() = default;
        explicit MatrixBase(const MatrixBase &other) = default;
        explicit MatrixBase(const Type data[N * M])
        {
            memcpy(data_, data, N * M * sizeof(Type));
        }
        explicit MatrixBase(const Type data[N][M])
        {
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    data_[i * M + j] = data[i][j];
        }
        explicit MatrixBase(const initializer_list<N * M, Type> &list)
        {
            memcpy(data_, list.data, N * M * sizeof(Type));
        }

        /**
         * Constant Matrices
         */

        static Derived
        eye()
        {
            Derived result;
            result.fill(static_cast<Type>(0));
            const size_t smaller = N < M ? N : M;
            for (size_t i = 0; i < smaller; i++)
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

        inline Type *getData() const { return data_; }
        inline void copyTo(Type *data) const { memcpy(data, data_, N * M * sizeof(Type)); }

        /**
         * Assignments
         */
        inline Derived &operator=(const Derived &other)
        {
            memcpy(data_, other.data_, N * M * sizeof(Type));
            return static_cast<Derived &>(*this);
        }

        template <typename OtherDerived>
        inline Derived &setBlock(size_t i, size_t j, const OtherDerived &block)
        {
            constexpr size_t P = OtherDerived::ROWS;
            constexpr size_t Q = OtherDerived::COLS;
            static_assert(is_same_v<typename OtherDerived::DATATYPE, Type>, "Matrix data types must be the same");
            static_assert(P <= N, "Block out of bounds, Row");
            static_assert(Q <= M, "Block out of bounds, Col");
            assert(i + P <= N);
            assert(j + Q <= M);
            for (size_t ii = 0; ii < P; ii++)
                for (size_t jj = 0; jj < Q; jj++)
                    data_[(i + ii) * M + j + jj] = block(ii, jj);
            return static_cast<Derived &>(*this);
        }

        template <typename OtherDerived>
        inline Derived &setRow(size_t i, const OtherDerived &row)
        {
            assert(i < N);
            static_assert(is_same_v<typename Derived::DATATYPE, Type>, "Matrix data types must be the same");
            static_assert(row.COLS == M, "Matrix Col dimension must be the same");
            static_assert(row.ROWS == 1, "Matrix Row dimension must be 1");
            for (size_t j = 0; j < M; j++)
                data_[i * M + j] = row(0, j);
            return static_cast<Derived &>(*this);
        }

        template <typename OtherDerived>
        inline Derived &setCol(size_t j, const OtherDerived &col)
        {
            assert(j < M);
            static_assert(is_same_v<typename OtherDerived::DATATYPE, Type>, "Matrix data types must be the same");
            static_assert(OtherDerived::ROWS == N, "Matrix Row dimension must be same");
            static_assert(OtherDerived::COLS == 1, "Matrix Col dimension must be 1");
            for (size_t i = 0; i < N; i++)
                data_[i * M + j] = col(i, 0);
            return static_cast<Derived &>(*this);
        }

        template <size_t i, size_t j, typename OtherDerived>
        inline Derived &setBlock(const OtherDerived &block)
        {
            static_assert(is_same_v<typename Derived::DATATYPE, Type>, "Matrix data types must be the same");
            static_assert(i + OtherDerived::ROWS <= N, "Block out of bounds, Row");
            static_assert(j + OtherDerived::COLS <= M, "Block out of bounds, Col");
            return setBlock(i, j, block);
        }

        template <size_t i, typename OtherDerived>
        inline Derived &setRow(const OtherDerived &row)
        {
            static_assert(i < N, "Row out of bounds");
            return setRow(i, row);
        }

        template <size_t j, typename OtherDerived>
        inline Derived &setCol(const OtherDerived &col)
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
            if constexpr (is_matrix_base_v<decltype(result)>)
            {
                result.fill(static_cast<Type>(0));
                for (size_t i = 0; i < N; i++)
                    for (size_t j = 0; j < OtherDerived::COLS; j++)
                        for (size_t k = 0; k < M; k++)
                            result(i, j) += (*this)(i, k) * other(k, j);
                return result;
            }
            else if constexpr (is_same_v<decltype(result), Type>)
            {
                result = static_cast<Type>(0);
                for (size_t i = 0; i < N; i++)
                    for (size_t j = 0; j < OtherDerived::COLS; j++)
                        for (size_t k = 0; k < M; k++)
                            result += (*this)(i, k) * other(k, j);
                return result;
            }
            else
            {
                static_assert(is_matrix_base_v<decltype(result)> || is_same_v<decltype(result), Type>,
                              "Invalid type for operator*");
                return static_cast<Type>(0);
            }
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

        inline Derived operator-() const
        {
            static_assert(Derived::ROWS > 0 && Derived::COLS > 0, "Matrix dimensions must be exist");
            static_assert(is_same_v<typename Derived::DATATYPE, Type>, "Matrix data types must be the same");
            Derived result;
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    result(i, j) = -data_[i * M + j];
            return result;
        }

        /**
         * Utils
         */

        inline auto T() const
        {
            if constexpr (N == 1)
            {
                Vector<M, Type> result;
                for (size_t i = 0; i < M; i++)
                    result(i, 0) = data_[i];
                return result;
            }
            else if constexpr (N == M)
            {
                SquareMatrix<M, Type> result;
                for (size_t i = 0; i < N; i++)
                    for (size_t j = 0; j < N; j++)
                        result(j, i) = data_[i * M + j];
                return result;
            }
            else
            {
                Matrix<M, N, Type> result;
                for (size_t i = 0; i < N; i++)
                    for (size_t j = 0; j < M; j++)
                        result(j, i) = data_[i * M + j];
                return result;
            }
        }

        inline void fill(const Type &v)
        {
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    data_[i * M + j] = v;
        }

        inline void print() const
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

        inline void swapRows(size_t i1, size_t i2)
        {
            for (size_t j = 0; j < M; j++)
            {
                Type temp = data_[i1 * M + j];
                data_[i1 * M + j] = data_[i2 * M + j];
                data_[i2 * M + j] = temp;
            }
        }

        inline void swapCols(size_t j1, size_t j2)
        {
            for (size_t i = 0; i < N; i++)
            {
                Type temp = data_[i * M + j1];
                data_[i * M + j1] = data_[i * M + j2];
                data_[i * M + j2] = temp;
            }
        }

        inline Type frobeniusNormSquared() const
        {
            Type result = static_cast<Type>(0);
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    result += data_[i * M + j] * data_[i * M + j];
            return result;
        }
        inline Type frobeniusNorm() const { return translotator::sqrt(frobeniusNormSquared()); }

        /**
         * Type Casting
         */
        template <typename NewType>
        inline auto castDatatype() const
        {
            static_assert(!is_same_v<Type, NewType>, "NewType must be different from current type");
            static_assert(is_float_v<NewType>, "NewType must be a floating point type");

            typename MatrixBaseInternal::operator_cast_typemapper<Derived, NewType>::type result;
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    result(i, j) = static_cast<NewType>(data_[i * M + j]);
            return result;
        }

        /**
         * @brief Casts the matrix to a scalar if it is a 1x1 matrix
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 1 && M_ == 1, true_type>>
        inline Type toScalar() const { return data_[0]; }

        template <typename NewContainer>
        inline NewContainer castContainer() const;
        inline Matrix<N, M, Type> cast2Matrix() const;
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == M_, true_type>>
        inline SquareMatrix<N, Type> cast2SquareMatrix() const;
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<M_ == 1, true_type>>
        inline Vector<N, Type> cast2Vector() const;
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 2 && M_ == 1, true_type>>
        inline ComplexNum<Type> cast2ComplexNum() const;
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 2 && M_ == 1, true_type>>
        inline UnitComplexNum<Type> cast2UnitComplexNum() const;
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 4 && M_ == 1, true_type>>
        inline Quaternion<Type> cast2Quaternion() const;
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 4 && M_ == 1, true_type>>
        inline UnitQuaternion<Type> cast2UnitQuaternion() const;
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<(N_ == 2 && M_ == 2) || (N_ == 3 && M_ == 3), true_type>>
        inline SOGroup<N, Type> cast2SOGroup() const;

        template <typename NewContainer>
        inline NewContainer &castContainerRef();
        inline Matrix<N, M, Type> &cast2MatrixRef();
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<M_ == N_, true_type>>
        inline SquareMatrix<N, Type> &cast2SquareMatrixRef();
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<M_ == 1, true_type>>
        inline Vector<N, Type> &cast2VectorRef();
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 2 && M_ == 1, true_type>>
        inline ComplexNum<Type> &cast2ComplexNumRef();
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 2 && M_ == 1, true_type>>
        inline UnitComplexNum<Type> &cast2UnitComplexNumRef();
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 4 && M_ == 1, true_type>>
        inline Quaternion<Type> &cast2QuaternionRef();
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 4 && M_ == 1, true_type>>
        inline UnitQuaternion<Type> &cast2UnitQuaternionRef();
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<(N_ == 2 && M_ == 2) || (N_ == 3 && M_ == 3), true_type>>
        inline SOGroup<N, Type> &cast2SOGroupRef();

    protected:
    private:
    };

}