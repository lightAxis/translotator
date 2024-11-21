/*
 * The MIT License (MIT)
 * Copyright (c) 2024 Jiseok Lee
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Created on Tue Nov 19 2024
 * @file : MatrixBase.hpp
 */

#pragma once

namespace translotator
{

    /**
     * @brief Base class for all matrix objects
     * @tparam N Number of rows
     * @tparam M Number of columns
     * @tparam Type Data type of the matrix
     * @tparam Derived Derived class, CRTP
     * @note This class is not meant to be used directly, use other matrix-based object classes instead.
     * @details This class provides basic matrix operations and functionalities.
     */
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

        constexpr static size_t rowSize() { return N; } /// Returns the number of rows

        constexpr static size_t colSize() { return M; } /// Returns the number of columns

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
        explicit MatrixBase(const initializer_list<N * M, Type> &list) /// Initializer list constructor
        {
            memcpy(data_, list.data, N * M * sizeof(Type));
        }

        /**
         * Constant Matrices
         */

        static Derived eye() /// Returns an identity matrix
        {
            Derived result;
            result.fill(static_cast<Type>(0));
            const size_t smaller = N < M ? N : M;
            for (size_t i = 0; i < smaller; i++)
                result(i, i) = 1;
            return result;
        }

        static Derived zeros() /// Returns a matrix filled with zeros
        {
            Derived result;
            result.fill(static_cast<Type>(0));
            return result;
        }

        static Derived ones() /// Returns a matrix filled with ones
        {
            Derived result;
            result.fill(static_cast<Type>(1));
            return result;
        }

        static Derived NaN() /// Returns a matrix filled with NaN
        {
            Derived result;
            result.fill(static_cast<Type>(NAN));
            return result;
        }

        /**
         * Accessors
         */

        inline const Type &operator()(size_t i, size_t j) const /// Accesses the element at (i, j)
        {
            return data_[i * M + j];
        }
        inline Type &operator()(size_t i, size_t j) /// Accesses the element at (i, j)
        {
            return data_[i * M + j];
        }
        inline Matrix<N, 1, Type> col(size_t j) const /// Returns the j-th column
        {
            assert(j < M);
            Matrix<N, 1, Type> result;
            for (size_t i = 0; i < N; i++)
                result(i, 0) = data_[i * M + j];
            return result;
        }
        inline Matrix<1, M, Type> row(size_t i) const /// Returns the i-th row
        {
            assert(i < N);
            Matrix<1, M, Type> result;
            for (size_t j = 0; j < M; j++)
                result(0, j) = data_[i * M + j];
            return result;
        }

        /**
         * @brief Returns a block of the matrix
         * @tparam P Number of rows in the block
         * @tparam Q Number of columns in the block
         * @param i Starting row index
         * @param j Starting column index
         */
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

        /**
         * @brief Returns a block of the matrix
         * @tparam i Starting row index
         * @tparam j Starting column index
         * @tparam P Number of rows in the block
         * @tparam Q Number of columns in the block
         */
        template <size_t i, size_t j, size_t P, size_t Q>
        inline Matrix<P, Q, Type> block() const
        {
            static_assert(i + P <= N, "Block out of bounds, Row");
            static_assert(j + Q <= M, "Block out of bounds, Col");
            return block<P, Q>(i, j);
        }

        inline Type *getData() const { return data_; } /// Returns the raw data pointer

        inline void copyTo(Type *data) const { memcpy(data, data_, N * M * sizeof(Type)); } /// Copies the data to the given pointer

        /**
         * Assignments
         */

        inline Derived &operator=(const Derived &other) /// Copy assignment
        {
            memcpy(data_, other.data_, N * M * sizeof(Type));
            return static_cast<Derived &>(*this);
        }

        /**
         * @brief Sets the element at (i, j)
         * @param i Row index
         * @param j Column index
         * @tparam OtherDerived Matrix Derived class to set the element from
         */
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

        /**
         * @brief Sets the i-th row
         * @param i Row index
         * @tparam OtherDerived Matrix Derived class to set the row from
         */
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

        /**
         * @brief Sets the j-th column
         * @param j Column index
         * @tparam OtherDerived Matrix Derived class to set the column from
         */
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

        /**
         * @brief Sets the i-th row
         * @tparam i Row index
         * @tparam j Column index
         * @tparam OtherDerived Matrix Derived class to set the row from
         * @details This function is a compile-time version of setRow
         */
        template <size_t i, size_t j, typename OtherDerived>
        inline Derived &setBlock(const OtherDerived &block)
        {
            static_assert(is_same_v<typename Derived::DATATYPE, Type>, "Matrix data types must be the same");
            static_assert(i + OtherDerived::ROWS <= N, "Block out of bounds, Row");
            static_assert(j + OtherDerived::COLS <= M, "Block out of bounds, Col");
            return setBlock(i, j, block);
        }

        /**
         * @brief Sets the i-th row
         * @tparam i Row index
         * @tparam OtherDerived Matrix Derived class to set the row from
         * @details This function is a compile-time version of setRow
         */
        template <size_t i, typename OtherDerived>
        inline Derived &setRow(const OtherDerived &row)
        {
            static_assert(i < N, "Row out of bounds");
            return setRow(i, row);
        }

        /**
         * @brief Sets the j-th column
         * @tparam j Column index
         * @tparam OtherDerived Matrix Derived class to set the column from
         * @details This function is a compile-time version of setCol
         */
        template <size_t j, typename OtherDerived>
        inline Derived &setCol(const OtherDerived &col)
        {
            static_assert(j < M, "Col out of bounds");
            return setCol(j, col);
        }

        /**
         * operators Scalar
         */

        inline Derived operator/(Type v) const /// Division by scalar
        {
            Derived result;
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    result(i, j) = data_[i * M + j] / v;
            return result;
        }
        inline void operator/=(Type v) /// Division by scalar
        {
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    data_[i * M + j] /= v;
        }
        inline friend Derived operator*(Type lhs, const Derived &rhs) { return rhs * lhs; } /// Multiplication by scalar

        /**
         * Operator Objects
         */

        /**
         * @brief Matrix addition
         * @tparam OtherDerived Matrix Derived class to add
         * @param other Matrix Derived class to add
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

        /**
         * @brief Matrix subtraction
         * @tparam OtherDerived Matrix Derived class to subtract
         * @param other Matrix Derived class to subtract
         */
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

        /**
         * @brief Matrix multiplication
         * @tparam OtherDerived Matrix Derived class to multiply
         * @param other Matrix Derived class to multiply
         */
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

        /**
         * @brief Matrix multiplication by scalar
         * @param v Scalar value
         * @details Multiplies the matrix by a scalar value
         */
        inline Derived operator*(const Type &v) const
        {
            Derived result;
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    result(i, j) = data_[i * M + j] * v;
            return result;
        }

        /**
         * @brief Matrix division by scalar
         * @param v Scalar value
         * @details Divides the matrix by a scalar value
         */
        template <typename OtherDerived>
        inline void operator+=(const OtherDerived &other)
        {
            static_assert(Derived::ROWS == OtherDerived::ROWS && Derived::COLS == OtherDerived::COLS, "Matrix dimensions must be the same");
            static_assert(is_same_v<typename Derived::DATATYPE, typename OtherDerived::DATATYPE>, "Matrix data types must be the same");

            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    data_[i * M + j] += other(i, j);
        }

        /**
         * @brief Matrix subtraction by scalar
         * @param v Scalar value
         * @details Subtracts the matrix by a scalar value
         */
        template <typename OtherDerived>
        inline void operator-=(const OtherDerived &other)
        {
            static_assert(Derived::ROWS == OtherDerived::ROWS && Derived::COLS == OtherDerived::COLS, "Matrix dimensions must be the same");
            static_assert(is_same_v<typename Derived::DATATYPE, typename OtherDerived::DATATYPE>, "Matrix data types must be the same");

            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    data_[i * M + j] -= other(i, j);
        }

        /**
         * @brief Matrix multiplication by scalar
         * @param v Scalar value
         * @details Multiplies the matrix by a scalar value
         */
        template <typename OtherDerived>
        inline void operator*=(const OtherDerived &other)
        {
            *this = *this * other;
        }

        /**
         * @brief Matrix multiplication by scalar
         * @param v Scalar value
         * @details Multiplies the matrix by a scalar value
         */
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

        inline auto T() const /// Transpose
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

        inline void fill(const Type &v) /// Fills the matrix with a value
        {
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    data_[i * M + j] = v;
        }

        inline void print() const /// Prints the matrix
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

        inline void swapRows(size_t i1, size_t i2) /// Swaps two rows
        {
            for (size_t j = 0; j < M; j++)
            {
                Type temp = data_[i1 * M + j];
                data_[i1 * M + j] = data_[i2 * M + j];
                data_[i2 * M + j] = temp;
            }
        }

        inline void swapCols(size_t j1, size_t j2) /// Swaps two columns
        {
            for (size_t i = 0; i < N; i++)
            {
                Type temp = data_[i * M + j1];
                data_[i * M + j1] = data_[i * M + j2];
                data_[i * M + j2] = temp;
            }
        }

        inline Type frobeniusNormSquared() const /// Returns the squared Frobenius norm
        {
            Type result = static_cast<Type>(0);
            for (size_t i = 0; i < N; i++)
                for (size_t j = 0; j < M; j++)
                    result += data_[i * M + j] * data_[i * M + j];
            return result;
        }
        inline Type frobeniusNorm() const { return translotator::sqrt(frobeniusNormSquared()); } /// Returns the Frobenius norm

        /**
         * Type Casting
         */

        /**
         * @brief Casts the matrix to a different data type
         * @tparam NewType New data type
         * @details This function is only available for floating point types
         */
        template <typename NewType>
        inline auto castDataType() const
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

        /**
         * @brief Casts the matrix to a different container type by copying
         * @tparam NewContainer New container type
         * @details This function is only available for containers with the same size as the matrix
         */
        template <typename NewContainer>
        inline NewContainer castContainer() const;

        /**
         * @brief Casts the object to a different matrix type by copying
         * @tparam NewContainer New matrix type
         * @return Matrix object with same dimensions and data type
         * @note This functions is alias of castContainer<Matrix<N, M, Type>>() function
         */
        inline Matrix<N, M, Type> cast2Matrix() const;
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == M_, true_type>>

        /**
         * @brief Casts the object to a square matrix by copying
         * @return Square matrix object with same dimensions and data type
         * @note This function is only available for N x N dimensions
         * @note This functions is alias of castContainer<SquareMatrix<N, Type>>() function
         */
        inline SquareMatrix<N, Type> cast2SquareMatrix() const;

        /**
         * @brief Casts the object to a vector by copying
         * @return Vector object with same dimensions and data type
         * @note This function is only available for M x 1 dimensions
         * @note This functions is alias of castContainer<Vector<N, Type>>() function
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<M_ == 1, true_type>>
        inline Vector<N, Type> cast2Vector() const;

        /**
         * @brief Casts the object to a complex number by copying
         * @return Complex number object with same data type
         * @note This function is only available for 2 x 1 dimensions
         * @note This functions is alias of castContainer<ComplexNum<Type>>() function
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 2 && M_ == 1, true_type>>
        inline ComplexNum<Type> cast2ComplexNum() const;

        /**
         * @brief Casts the object to a unit complex number by copying
         * @return Unit complex number object with same data type
         * @note This function is only available for 2 x 1 dimensions
         * @note This functions is alias of castContainer<UnitComplexNum<Type>>() function
         * @note If the input is not a unit complex number, the output will be normalized to be a unit complex number
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 2 && M_ == 1, true_type>>
        inline UnitComplexNum<Type> cast2UnitComplexNum() const;

        /**
         * @brief Casts the object to a quaternion by copying
         * @return Quaternion object with same data type
         * @note This function is only available for 4 x 1 dimensions
         * @note This functions is alias of castContainer<Quaternion<Type>>() function
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 4 && M_ == 1, true_type>>
        inline Quaternion<Type> cast2Quaternion() const;

        /**
         * @brief Casts the object to a unit quaternion by copying
         * @return Unit quaternion object with same data type
         * @note This function is only available for 4 x 1 dimensions
         * @note This functions is alias of castContainer<UnitQuaternion<Type>>() function
         * @note If the input is not a unit quaternion, the output will be normalized to be a unit quaternion
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 4 && M_ == 1, true_type>>
        inline UnitQuaternion<Type> cast2UnitQuaternion() const;

        /**
         * @brief Casts the object to a special orthogonal group by copying
         * @return SOGroup object with same data type
         * @note This function is only available for 2 x 2 or 3 x 3 dimensions
         * @note This functions is alias of castContainer<SOGroup<N, Type>>() function
         * @note If the input is not a special orthogonal group, the output will be normalized to be a special orthogonal group
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<(N_ == 2 && M_ == 2) || (N_ == 3 && M_ == 3), true_type>>
        inline SOGroup<N, Type> cast2SOGroup() const;

        /**
         * @brief Casts the object to a dual number by copying
         * @return Dual number object with same data type
         * @note This function is only available for 2 x 1 dimensions
         * @note This functions is alias of castContainer<DualNumber<Type>>() function
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 2 && M_ == 1, true_type>>
        inline DualNumber<Type> cast2DualNumber() const;

        /**
         * @brief Casts the object to a dual quaternion by copying
         * @return Dual quaternion object with same data type
         * @note This function is only available for 8 x 1 dimensions
         * @note This functions is alias of castContainer<DualQuaternion<Type>>() function
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 8 && M_ == 1, true_type>>
        inline DualQuaternion<Type> cast2DualQuaternion() const;

        /**
         * @brief Casts the object to a unit dual quaternion by copying
         * @return Unit dual quaternion object with same data type
         * @note This function is only available for 8 x 1 dimensions
         * @note This functions is alias of castContainer<UnitDualQuaternion<Type>>() function
         * @note If the input is not a unit dual quaternion, the output will be normalized to be a unit dual quaternion
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 8 && M_ == 1, true_type>>
        inline UnitDualQuaternion<Type> cast2UnitDualQuaternion() const;

        /**
         * @brief Casts the object to a different container reference without copying
         * @tparam NewContainer New container type
         * @details This function is only available for containers with the same size as the matrix
         * @note This function is recommended for temporary objects. Use castContainer() and alias functions for permanent objects.
         */
        template <typename NewContainer>
        inline NewContainer &castContainerRef();

        /**
         * @brief Casts the object to a matrix reference without copying
         * @return Matrix object with same dimensions and data type
         * @note This function is only available for N x M dimensions. Not recommended for temporary objects.
         * @note This function is alias of castContainerRef<Matrix<N, M, Type>>() function
         */
        inline Matrix<N, M, Type> &cast2MatrixRef();

        /**
         * @brief Casts the object to a square matrix reference without copying
         * @return Square matrix object with same dimensions and data type
         * @note This function is only available for N x N dimensions. Not recommended for temporary objects.
         * @note This function is alias of castContainerRef<SquareMatrix<N, Type>>() function
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<M_ == N_, true_type>>
        inline SquareMatrix<N, Type> &cast2SquareMatrixRef();

        /**
         * @brief Casts the object to a vector reference without copying
         * @return Vector object with same dimensions and data type
         * @note This function is only available for M x 1 dimensions. Not recommended for temporary objects.
         * @note This function is alias of castContainerRef<Vector<N, Type>>() function
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<M_ == 1, true_type>>
        inline Vector<N, Type> &cast2VectorRef();

        /**
         * @brief Casts the object to a complex number reference without copying
         * @return Complex number object with same data type
         * @note This function is only available for 2 x 1 dimensions. Not recommended for temporary objects.
         * @note This function is alias of castContainerRef<ComplexNum<Type>>() function
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 2 && M_ == 1, true_type>>
        inline ComplexNum<Type> &cast2ComplexNumRef();

        /**
         * @brief Casts the object to a unit complex number reference without copying
         * @return Unit complex number object with same data type
         * @note This function is only available for 2 x 1 dimensions. Not recommended for temporary objects.
         * @note This function is alias of castContainerRef<UnitComplexNum<Type>>() function
         * @note If the input is not a unit complex number, the output & original object will be normalized to be a unit complex number
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 2 && M_ == 1, true_type>>
        inline UnitComplexNum<Type> &cast2UnitComplexNumRef();

        /**
         * @brief Casts the object to a quaternion reference without copying
         * @return Quaternion object with same data type
         * @note This function is only available for 4 x 1 dimensions. Not recommended for temporary objects.
         * @note This function is alias of castContainerRef<Quaternion<Type>>() function
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 4 && M_ == 1, true_type>>
        inline Quaternion<Type> &cast2QuaternionRef();

        /**
         * @brief Casts the object to a unit quaternion reference without copying
         * @return Unit quaternion object with same data type
         * @note This function is only available for 4 x 1 dimensions. Not recommended for temporary objects.
         * @note This function is alias of castContainerRef<UnitQuaternion<Type>>() function
         * @note If the input is not a unit quaternion, the output & original object will be normalized to be a unit quaternion
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 4 && M_ == 1, true_type>>
        inline UnitQuaternion<Type> &cast2UnitQuaternionRef();

        /**
         * @brief Casts the object to a special orthogonal group reference without copying
         * @return SOGroup object with same data type
         * @note This function is only available for 2 x 2 or 3 x 3 dimensions. Not recommended for temporary objects.
         * @note This function is alias of castContainerRef<SOGroup<N, Type>>() function
         * @note If the input is not a special orthogonal group, the output & original object will be normalized to be a special orthogonal group
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<(N_ == 2 && M_ == 2) || (N_ == 3 && M_ == 3), true_type>>
        inline SOGroup<N, Type> &cast2SOGroupRef();

        /**
         * @brief Casts the object to a dual number reference without copying
         * @return Dual number object with same data type
         * @note This function is only available for 2 x 1 dimensions. Not recommended for temporary objects.
         * @note This function is alias of castContainerRef<DualNumber<Type>>() function
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 2 && M_ == 1, true_type>>
        inline DualNumber<Type> &cast2DualNumberRef();

        /**
         * @brief Casts the object to a dual quaternion reference without copying
         * @return Dual quaternion object with same data type
         * @note This function is only available for 8 x 1 dimensions. Not recommended for temporary objects.
         * @note This function is alias of castContainerRef<DualQuaternion<Type>>() function
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 8 && M_ == 1, true_type>>
        inline DualQuaternion<Type> &cast2DualQuaternionRef();

        /**
         * @brief Casts the object to a unit dual quaternion reference without copying
         * @return Unit dual quaternion object with same data type
         * @note This function is only available for 8 x 1 dimensions. Not recommended for temporary objects.
         * @note This function is alias of castContainerRef<UnitDualQuaternion<Type>>() function
         * @note If the input is not a unit dual quaternion, the output & original object will be normalized to be a unit dual quaternion
         */
        template <size_t N_ = N, size_t M_ = M, typename = enable_if_t<N_ == 8 && M_ == 1, true_type>>
        inline UnitDualQuaternion<Type> &cast2UnitDualQuaternionRef();
    };

}