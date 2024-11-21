# Matrix

Matrix is a two-dimensional array of numbers. It is a fundamental mathematical concept that is used in many fields such as physics, computer graphics, and machine learning. In this article, we will discuss the basics of matrices, matrix operations, and their applications.

Many operations can be performed on matrices, such as addition, subtraction, multiplication, sometimes division.

## Matrix Class

Basically, I denote row dimension as $N$, col dimension as $M$.  
All Matrices are represented in the Matrix<N, M, Type> class.

Almost every methods and functions in Matrix Class are implemented to other matrix-based objects, such as Vector, SquareMatrix, etc.  
For example, if you want to cast data type of a matrix-based object, you can use `castType<Type>()` method

### Matrix Template

```cpp
// Matrix<N,M,Type>
constexpr size_t RowSize = 3;
constexpr size_t ColSize = 4;
using DataType = float; // float, double, long double is available
Matrix<RowSize,ColSize,DataType> mat;
```

### Matrix DataType Casting

```cpp
Matrix<3,4,float> m34f;
Matrix<3,4,double> m34d = m32f.castType<double>();
Matrix<3,4,long double> m34ld = m32f.castContainer<Matrix<3,4,long double>>();

// Matrixf<N,M> is an alias of Matrix<N,M,float>
Matrixf<3,4> m34f_alias = m34f;
// Matrixd<N,M> is an alias of Matrix<N,M,double>
Matrixd<3,4> m34d_alias = m34d;
// Matrixld<N,M> is an alias of Matrix<N,M,long double>
Matrixld<3,4> m34ld_alias = m34ld;
```

### Initialize with initializer_list

```cpp
Matrix<3,4,float> M34{{11.f, 12.f, 13.f, 14.f,
                       21.f, 22.f, 23.f, 24.f,
                       31.f, 32.f, 33.f, 34.f}};

Matrix<3,2,float> M32{{1.f, 2.f, 3.f, 4.f, 5.f, 6.f}};
```

$$\begin{align}
\text{M34} &= \begin{bmatrix} 11 & 12 & 13 & 14 \\ 21 & 22 & 23 & 24 \\ 31 & 32 & 33 & 34 \end{bmatrix}
\\[10pt]
\text{M32} &= \begin{bmatrix} 1 & 2 \\ 3 & 4 \\ 5 & 6 \end{bmatrix}
\end{align}$$

```cpp
// *** Indexing ***
Matrix<3, 4, float> M34{{11.f, 12.f, 13.f, 14.f,
                         21.f, 22.f, 23.f, 24.f,
                         31.f, 32.f, 33.f, 34.f}};

// get element
float e23 = M34(1, 2); // 23.f
// set element
M34(1, 2) = 100.f; // 23.f -> 100.f

// get row
Matrix<1, 4, float> r2 = M34.row(1); // start from idx 0, 2nd row is idx 1
// set row
M34.setRow(0, r2); // first row

// get col
Matrix<3, 1, float> c2 = M34.col(1); // start from idx 0, 1 is 2nd col
// set col
M34.setCol(0, c2); // first col

// get block
Matrix<2, 3, float> b = M34.block<2, 3>(0, 1); // shape : 2x3, start from 0, 1
// set block
M34.setBlock(1, 0, b); // start from 1, 0

// get block with fixed size, compiler will deduce and check the size for you
b = M34.block<0, 1, 2, 3>(); // shape : 2x3, start from 0, 1
// set block with size, compiler will deduce and check the size for you
M34.setBlock<0, 1>(b);
```

### Matrix Operations

```cpp
// with matrices
Matrix<3, 4, float> M34;
Matrix<2, 3, float> M23;
Matrix<2, 4, float> M24;

Matrix<2, 4, float> M24_Res = M23 * M34 + M24;

// with scalar
float a;
Matrix<3, 4, float> M34_Res = a * M34;

// other operators, such as +, -, /, +=, -=, *=, /= are also available if the size is matched
```

$$\begin{align}
M_{24, Res} &= M_{23} \times M_{34} + M_{24} \\[10pt]
M_{34, Res} &= a M_{34}
\end{align}$$

### Matrix Utils

```cpp
// transpose
Matrix<4, 3, float> M43 = M34.transpose();

// fill
M34.fill(1.f);

// print
M34.print();

// swap rows & cols
M34.swapRows(0, 1);
M34.swapCols(0, 1);

// frobeniusNorm
float norm = M34.frobeniusNorm();

// to scalar. If the matrix is 1x1, it can be casted to scalar
float scalar = M34.toScalar();
```

## Square Matrix Class

If $N=M$, the matrix is called a square matrix $N$ . This instance can be casted to SquareMatrix<N,M,Type> class, or vice versa.

This is a matrix-based object. So, all methods in Matrix class are also available too.

```cpp
SquareMatrix<3, float> sq33{{1.f, 2.f, 3.f,
                             4.f, 5.f, 6.f,
                             7.f, 8.f, 9.f}};

// cast to Matrix
Matrix<3,3,float> m33 = sq33.castContainer<Matrix<3,3,float>>();
// vice versa
SquareMatrix<3,float> sq33_casted = m33.castContainer<SquareMatrix<3,float>>();

// cast to matrix by alias
Matrixf<3,3> m33_alias = sq33.cast2Matrix();
SquareMatrixf<3> sq33_alias = m33_alias.cast2SquareMatrix();

// cast to matrix with reference. zero-copy
// This is not recommended for temporary instances because it can cause dangling reference
// Use this method when :
// 1. If you want to use the same data with different data types
// 2. Save memory or avoid memory copy overhead.
// 3. When Original object is not destroyed until the reference is destroyed.
Matrixf<3,3> m33_ref = sq33.castContainerRef<Matrixf<3,3>>();
// vice versa
SquareMatrixf<3> sq33_ref = m33_ref.castContainerRef<SquareMatrixf<3>>();

// by alias
Matrixf<3,3> m33_ref_alias = sq33.cast2MatrixRef();
SquareMatrixf<3> sq33_ref_alias = m33_ref_alias.cast2SquareMatrixRef();
```

### Square Matrix Special Methods

```cpp
// determinant
// only implemented for 2x2, 3x3
float det = sq33.determinant();

// inverse
// fast closed-form solution for 1x1, 2x2, 3x3.
// Otherwise, use LU decomposition
SquareMatrix<3, float> inv = sq33.inverse();

// trace
float trace = sq33.trace();
```
## Vector Class

if $M=1$, the matrix is called a vector. This instance can be casted to `Vector<N,Type>` class, or vice versa.

This is a matrix-based object. So, all methods in Matrix class are also available too.

```cpp
Vector<3, float> vec3{{1.f, 2.f, 3.f}};
// cast to Matrix
Matrix<3,1,float> m31 = vec3.castContainer<Matrix<3,1,float>>();
// vice versa
Vector<3,float> vec3_casted = m31.castContainer<Vector<3,float>>();

// cast to matrix by alias
Matrixf<3,1> m31_alias = vec3.cast2Matrix();
Vectorf<3> vec3_alias = m31_alias.cast2Vector();
```

### Vector Special Methods

```cpp
/// norm
Vector<3, float> vec3{{1.f, 2.f, 3.f}};
float norm = vec3.norm();

/// dot product
Vector<3, float> vec3_2{{4.f, 5.f, 6.f}};
float dot = vec3.dot(vec3_2);

/// cross product
Vector<3, float> cross = vec3.cross(vec3_2);

// to cross product matrix
SquareMatrix<3,3,float> crossMat = vec3.toCrossMatrix();

// to diagonal matrix
SquareMatrix<3,float> diagMat = vec3.toDiagonalMatrix();

// accessors
float x = vec3.x();
float y = vec3.y();
float z = vec3.z();

// set
vec3.x() = x;
vec3.y() = y;
vec3.z() = z;

// array like access
float x = vec3[0];
float y = vec3[1];
float z = vec3[2];

// array like set
vec3[0] = x;
vec3[1] = y;
vec3[2] = z;

// element axis
Vector<3, float> xAxis = vec3.xAxis();
Vector<3, float> yAxis = vec3.yAxis();
Vector<3, float> zAxis = vec3.zAxis();
```
