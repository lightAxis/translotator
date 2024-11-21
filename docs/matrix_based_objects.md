# Matrix Based Objects

There are many objects in this library. And many of them are based on the matrix structure.

These are the matrix-based objects in this library.

- Matrix<N,M,Type> (N x M)
- SquareMatriu<N,Type> (N x N)
- Vector<N,Type> (N x 1)
- ComplexNum<Type> (2 x 1)
- Quaternion<Type> (4 x 1)
- DualNumber<Type> (2 x 1)
- DualQuaternion<Type> (8 x 1)
- SOGroup<N, Type> (N x N)
- UnitComplexNum<Type> (2 x 1)
- UnitQuaternion<Type> (4 x 1)
- UnitDualQuaternion<Type> (8 x 1)

These are not matrix-based objects, but they are also available in this library. Manual conversion is available between these objects and matrix-based objects.

- EulerAngle<Type, EULER_ORDER>
- AxisAngle<Type>
- SEGroup<N, Type>

## Automatic Return Type Deduction by Dimension & lhs

There are many matrix-based objects in this library.  
Every time you create a matrix-based object, you don't need to specify the data type and optimized container every time.  
To avoid the casting overhead and make the code more readable, the library automatically deduces the data type and optimized container by the dimension and lhs.

There's some examples below.

- Matrix (N x M)
- SquareMatrix (N x N)
- Vector (N x 1)
- Scalar

Every result type and dimension and return types are deduced at compile time.  

### operator +,-

If the lhs and rhs have the same dimension, the return type is the same as the lhs type.  

```cpp
// same dimension
Matrix<2,3,float> m23;
Matrix<2,3,float> m23_res = m23 + m23;

// same but different type, following the lhs type
Vector<3,float> v31;
Matrix<3,1,float> m31;
Vector<3,float> v31_res = v31 + m31;
Matrix<3,1,float> m31_res = m31 + v31;

// different dimension, following the lhs type. 
Quaternion<float> q;
Vector<4,float> v41;
Quaternion<float> q_res = q + v41;
Vector<4,float> v41_res = v41 + q;

// some objects those are constrainted type (e.g. UnitQuaternion) can be different
UnitQuaternion<float> uq;
Vector<4,float> v41_res2 = uq + v41;
```

### operator *, /

If the result dimension is 1x1, return type is scalar.  

```cpp
float scalar1 = Matrix<1,3,float>{} * Matrix<3,1,float>{};
float scalar2 = Matrix<1,3,float>{} * Vector<3, float>{};
```

If the result dimension is Nx1, return type is vector.  

```cpp
Vector<3,float> vec1 = Matrix<3,2,float>{} * Matrix<2,1,float>{};
Vector<3,float> vec2 = Vector<3,float> * 10.f;
```

If the result dimension is NxN, return type is square matrix.  

```cpp
Matrix<3,2,float> m32;
Vector<2,float> v21;
Matrix<1,3,float> m13;

SquareMatrix<3,float> sq33 = m32 * v21 * m13 / 10.f;
```

If the result dimension is NxM, return type is matrix.  

```cpp
Matrix<3,3,float> m33;
Vector<3,float> v31;
Matrix<1,2,float> m12;

Matrix<3,2,float> m34 = sq32 * v31 * m12 * 10.f;
```

If the lhs is special constrainted type (e.g. UnitQuaternion), the return type can be different. If the operation does not preserves the constraint of the lhs, the return type is deduced as the next most general type.

If the lhs is mathmatically closed to the operation, the return type is deduced as the lhs type.

Or, some case like UnitQuaternion, operator* is Quaternion Multiplication, not Matrix Multiplication. So, the return type is deduced as Quaternion.

These objects are closed to multiplication operation. So, unique multiplication rules can be applied to these operator* between objects.

- UnitComplexNum
- UnitQuaternion
- UnitDualQuaternion
- SOGroup
- SEGroup

```cpp
UnitComplexNum<float> uc;
ComplexNum<float> c;

// unit * unit = unit (closed to multiplication)
UnitComplexNum<float> uc2 = uc * uc; 
// complex * unit = complex
ComplexNum<float> c2 = c * uc; 
// unit * scalar = complex
ComplexNum<float> c4 = uc * 1.f; 

// unit(2x1) * matrix(1x2) = square(2x2)
SquareMatrix<2,float> sq22 = uc * Matrix<1,2,float>{};
```

## Object Type Conversion between Matrix Based Objects

There are many matrix-based objects in this library. Every object has a conversion function to convert to another object. Of course, the conversion is defined between the same dimension objects.

There are two versions of conversion functions.  
One is `castContainer<ContainerType>()` ant the other is `castContainerRef<Type>()`.  

### Conversion with Memory Copy

`castContainer<ContainerType>()` returns a new object with the specified container type. **New instance is created and the data is copied.** This is highly recommended most of the time.

```cpp
Matrix<4,1,float> m41;
Vector<4,float> v41 = m41.castContainer<Vector<4,float>>();
Matrix<4,1,float> m41_ = v41.castContainer<Matrix<4,float>>();
```

There's an alias functions for `castContainer<ContainerType>()`.  
function `cast2[ContainerType]()` is available for each object, automatically deduceing the result type & dimensions at complie time.

```cpp
Matrix<4,1,float> m41;
Vector<4,float> v41 = m41.cast2Vector();
Matrix<4,1,float> m41_ = v41.cast2Matrix();
Matrix<4,4,float> m44 = (m41 * m41.T()).cast2SquareMatrix();
```

Some functions are available for specific type of Dimension.  

``` cpp
Vector<2,float> v21
ComplexNum<float> c = v21.cast2ComplexNum();
DualNumber<float> d = v21.cast2DualNumber();

Vector<4,float> v41;
Quaternion<float> q = v41.cast2Quaternion();

Vector<8,float> v81;
DualQuaternion<float> dq = v81.cast2DualQuaternion();
```

Some functions are conducting normalization during the conversion.

```cpp
Matrix<2,1,float> m21;
// automatically normalized
UnitComplexNum<float> uc = m21.cast2UnitComplexNum();

Vector<4,float> v41;
// automatically normalized
UnitQuaternion<float> uq = v41.cast2UnitQuaternion();

DualQuaternion<float> dq;
// automatically normalized
UnitDualQuaternion<float> udq = dq.cast2UnitDualQuaternion();

SquareMatrix<3,float> sq33;
// automatically normalized
SOGroup<3,float> so3 = sq33.cast2SOGroup();
```

### Conversion with Reference (Zero-Copy)

`castContainerRef<ContainerType>()` returns a reference of current object with the specified container type. **Instance is not created and the data is not copied.** This function uses reinterpret_cast to convert the data type.  
I carefully designed the data structures of matrix-based objects to have the same memory layout for same dimension objects.  

**However This conversion is not recommended for temporary instances because it can cause dangling reference.**

Use this method only when :

- If you want to use the same data with different data types
- Save memory or avoid memory copy overhead.
- When Original object is not destroyed until the reference is destroyed.

```cpp
Matrix<4,1,float> m41;
Vector<4,float> &v41 = m41.castContainerRef<Vec tor<4,float>>();
Matrix<4,1,float> &m41_ = v41.castContainerRef<Matrix<4,float>>();
```

There's an alias functions for `castContainerRef<ContainerType>()`.

```cpp
Matrix<4,1,float> m41;
Vector<4,float> &v41 = m41.cast2VectorRef();
Matrix<4,1,float> &m41_ = v41.cast2MatrixRef();
// Not Recommended for temporary instances
// This will cause dangling reference
Matrix<4,4,float> &m44 = (m41 * m41.T()).cast2SquareMatrixRef();
// const Reference can expand the lifetime of the temporary object, (C++17)
// but still not recommended to use.
const Matrix<4,4,float> &m44_constRef = (m41 * m41.T()).cast2SquareMatrixRef();
```

Some functions are available for specific type of Dimension.  

``` cpp
Vector<2,float> v21
ComplexNum<float> &c = v21.cast2ComplexNumRef();
DualNumber<float> &d = v21.cast2DualNumberRef();

Vector<4,float> v41;
Quaternion<float> &q = v41.cast2QuaternionRef();
```

Some functions are conducting normalization during the conversion.

```cpp
Matrix<2,1,float> m21;
// automatically normalized
// This will normalize the original object too.
UnitComplexNum<float> &uc = m21.cast2UnitComplexNumRef();

Vector<4,float> v41;
// automatically normalized
// This will normalize the original object too.
UnitQuaternion<float> &uq = v41.cast2UnitQuaternionRef();
```
