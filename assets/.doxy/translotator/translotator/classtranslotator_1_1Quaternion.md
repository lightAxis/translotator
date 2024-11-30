

# Class translotator::Quaternion

**template &lt;typename Type&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**Quaternion**](classtranslotator_1_1Quaternion.md)



_Representing a quaternion._ [More...](#detailed-description)

* `#include <Quaternion.hpp>`



Inherits the following classes: [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)
















## Public Types inherited from translotator::MatrixBase

See [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)

| Type | Name |
| ---: | :--- |
| typedef Type | [**DATATYPE**](classtranslotator_1_1MatrixBase.md#typedef-datatype)  <br> |










## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr static ObjectType | [**OBJECT\_TYPE**](#variable-object_type)   = = ObjectType::QUATERNION<br> |


## Public Static Attributes inherited from translotator::MatrixBase

See [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)

| Type | Name |
| ---: | :--- |
|  constexpr static size\_t | [**COLS**](classtranslotator_1_1MatrixBase.md#variable-cols)   = = M<br> |
|  constexpr static bool | [**MATRIX\_BASE**](classtranslotator_1_1MatrixBase.md#variable-matrix_base)   = = true<br> |
|  constexpr static size\_t | [**ROWS**](classtranslotator_1_1MatrixBase.md#variable-rows)   = = N<br> |


























## Public Functions

| Type | Name |
| ---: | :--- |
|  const [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; | [**Im**](#function-im-12) () const<br> |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & | [**Im**](#function-im-22) () <br> |
|   | [**Quaternion**](#function-quaternion-14) () <br> |
|   | [**Quaternion**](#function-quaternion-24) (Type w, Type x, Type y, Type z) <br> |
|   | [**Quaternion**](#function-quaternion-34) (Type w, const [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & v) <br> |
|   | [**Quaternion**](#function-quaternion-44) (const [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; & cplx) <br> |
|  const Type | [**Re**](#function-re-12) () const<br> |
|  Type & | [**Re**](#function-re-22) () <br> |
|  void | [**canonicalize**](#function-canonicalize) () <br> |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**canonicalized**](#function-canonicalized) () const<br>_normalize the quaternion_  |
|  void | [**conjugate**](#function-conjugate) () <br>_get the conjugated quaternion_  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**conjugated**](#function-conjugated) () const<br>_canonicalize the quaternion_  |
|  void | [**inverse**](#function-inverse) () <br>_get the inversed quaternion_  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**inversed**](#function-inversed) () const<br>_conjugate the quaternion_  |
|  Type | [**norm**](#function-norm) () const<br>_get the squared norm of the quaternion_  |
|  Type | [**normSquared**](#function-normsquared) () const<br> |
|  void | [**normalize**](#function-normalize) () <br>_get the normalized quaternion_  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**normalized**](#function-normalized) () const<br>_get the norm of the quaternion_  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**operator\***](#function-operator) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) const<br>_quaternion multiplication_  |
|  void | [**operator\*=**](#function-operator_1) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) <br>_quaternion division_  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**operator/**](#function-operator_2) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) const<br> |
|  void | [**operator/=**](#function-operator_3) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) <br>_quaternion multiplication_  |
|  Type | [**operator[]**](#function-operator_4) (size\_t i) const<br> |
|  Type & | [**operator[]**](#function-operator_5) (size\_t i) <br> |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**quatNumDiv**](#function-quatnumdiv) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) const<br> |
|  void | [**quatNumDivEq**](#function-quatnumdiveq) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) <br> |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**quatNumMul**](#function-quatnummul) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) const<br>_quaternion division_  |
|  void | [**quatNumMulEq**](#function-quatnummuleq) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) <br> |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; 4, Type &gt; | [**toMulMatrix**](#function-tomulmatrix) () const<br>_get the matrix that represents the quaternion multiplication_  |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; 4, Type &gt; | [**toRightMulMatrix**](#function-torightmulmatrix) () const<br>_get the matrix that represents the quaternion multiplication from the right_  |
|  Type | [**w**](#function-w-12) () const<br> |
|  Type & | [**w**](#function-w-22) () <br> |
|  Type | [**x**](#function-x-12) () const<br> |
|  Type & | [**x**](#function-x-22) () <br> |
|  Type | [**y**](#function-y-12) () const<br> |
|  Type & | [**y**](#function-y-22) () <br> |
|  Type | [**z**](#function-z-12) () const<br> |
|  Type & | [**z**](#function-z-22) () <br> |


## Public Functions inherited from translotator::MatrixBase

See [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)

| Type | Name |
| ---: | :--- |
|   | [**MatrixBase**](classtranslotator_1_1MatrixBase.md#function-matrixbase-15) () = default<br>_Returns the number of columns._  |
|   | [**MatrixBase**](classtranslotator_1_1MatrixBase.md#function-matrixbase-25) (const [**MatrixBase**](classtranslotator_1_1MatrixBase.md) & other) = default<br> |
|   | [**MatrixBase**](classtranslotator_1_1MatrixBase.md#function-matrixbase-35) (const Type data) <br> |
|   | [**MatrixBase**](classtranslotator_1_1MatrixBase.md#function-matrixbase-45) (const Type data) <br> |
|   | [**MatrixBase**](classtranslotator_1_1MatrixBase.md#function-matrixbase-55) (const [**initializer\_list**](structtranslotator_1_1initializer__list.md)&lt; N \*M, Type &gt; & list) <br>_Initializer list constructor._  |
|  auto | [**T**](classtranslotator_1_1MatrixBase.md#function-t) () const<br>_Transpose._  |
|  [**Matrix**](classtranslotator_1_1Matrix.md)&lt; P, Q, Type &gt; | [**block**](classtranslotator_1_1MatrixBase.md#function-block-12) (size\_t i, size\_t j) const<br>_Returns a block of the matrix._  |
|  [**Matrix**](classtranslotator_1_1Matrix.md)&lt; P, Q, Type &gt; | [**block**](classtranslotator_1_1MatrixBase.md#function-block-22) () const<br>_Returns a block of the matrix._  |
|  [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; | [**cast2ComplexNum**](classtranslotator_1_1MatrixBase.md#function-cast2complexnum) () const<br>_Casts the object to a complex number by copying._  |
|  [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; & | [**cast2ComplexNumRef**](classtranslotator_1_1MatrixBase.md#function-cast2complexnumref) () <br>_Casts the object to a complex number reference without copying._  |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; | [**cast2DualNumber**](classtranslotator_1_1MatrixBase.md#function-cast2dualnumber) () const<br>_Casts the object to a dual number by copying._  |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; & | [**cast2DualNumberRef**](classtranslotator_1_1MatrixBase.md#function-cast2dualnumberref) () <br>_Casts the object to a dual number reference without copying._  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**cast2DualQuaternion**](classtranslotator_1_1MatrixBase.md#function-cast2dualquaternion) () const<br>_Casts the object to a dual quaternion by copying._  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & | [**cast2DualQuaternionRef**](classtranslotator_1_1MatrixBase.md#function-cast2dualquaternionref) () <br>_Casts the object to a dual quaternion reference without copying._  |
|  [**Matrix**](classtranslotator_1_1Matrix.md)&lt; N, M, Type &gt; | [**cast2Matrix**](classtranslotator_1_1MatrixBase.md#function-cast2matrix) () const<br>_Casts the object to a different matrix type by copying._  |
|  [**Matrix**](classtranslotator_1_1Matrix.md)&lt; N, M, Type &gt; & | [**cast2MatrixRef**](classtranslotator_1_1MatrixBase.md#function-cast2matrixref) () <br>_Casts the object to a matrix reference without copying._  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**cast2Quaternion**](classtranslotator_1_1MatrixBase.md#function-cast2quaternion) () const<br>_Casts the object to a quaternion by copying._  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & | [**cast2QuaternionRef**](classtranslotator_1_1MatrixBase.md#function-cast2quaternionref) () <br>_Casts the object to a quaternion reference without copying._  |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; | [**cast2SOGroup**](classtranslotator_1_1MatrixBase.md#function-cast2sogroup) () const<br>_Casts the object to a special orthogonal group by copying._  |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; & | [**cast2SOGroupRef**](classtranslotator_1_1MatrixBase.md#function-cast2sogroupref) () <br>_Casts the object to a special orthogonal group reference without copying._  |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; N, Type &gt; | [**cast2SquareMatrix**](classtranslotator_1_1MatrixBase.md#function-cast2squarematrix) () const<br>_Casts the object to a square matrix by copying._  |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; N, Type &gt; & | [**cast2SquareMatrixRef**](classtranslotator_1_1MatrixBase.md#function-cast2squarematrixref) () <br>_Casts the object to a square matrix reference without copying._  |
|  [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; | [**cast2UnitComplexNum**](classtranslotator_1_1MatrixBase.md#function-cast2unitcomplexnum) () const<br>_Casts the object to a unit complex number by copying._  |
|  [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; & | [**cast2UnitComplexNumRef**](classtranslotator_1_1MatrixBase.md#function-cast2unitcomplexnumref) () <br>_Casts the object to a unit complex number reference without copying._  |
|  [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; | [**cast2UnitDualQuaternion**](classtranslotator_1_1MatrixBase.md#function-cast2unitdualquaternion) () const<br>_Casts the object to a unit dual quaternion by copying._  |
|  [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; & | [**cast2UnitDualQuaternionRef**](classtranslotator_1_1MatrixBase.md#function-cast2unitdualquaternionref) () <br>_Casts the object to a unit dual quaternion reference without copying._  |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; | [**cast2UnitQuaternion**](classtranslotator_1_1MatrixBase.md#function-cast2unitquaternion) () const<br>_Casts the object to a unit quaternion by copying._  |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; & | [**cast2UnitQuaternionRef**](classtranslotator_1_1MatrixBase.md#function-cast2unitquaternionref) () <br>_Casts the object to a unit quaternion reference without copying._  |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; | [**cast2Vector**](classtranslotator_1_1MatrixBase.md#function-cast2vector) () const<br>_Casts the object to a vector by copying._  |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; & | [**cast2VectorRef**](classtranslotator_1_1MatrixBase.md#function-cast2vectorref) () <br>_Casts the object to a vector reference without copying._  |
|  NewContainer | [**castContainer**](classtranslotator_1_1MatrixBase.md#function-castcontainer) () const<br>_Casts the matrix to a different container type by copying._  |
|  NewContainer & | [**castContainerRef**](classtranslotator_1_1MatrixBase.md#function-castcontainerref-12) () <br>_Casts the object to a different container reference without copying._  |
|  NewDerived & | [**castContainerRef**](classtranslotator_1_1MatrixBase.md#function-castcontainerref-22) () <br> |
|  auto | [**castDataType**](classtranslotator_1_1MatrixBase.md#function-castdatatype) () const<br>_Returns the Frobenius norm._  |
|  [**Matrix**](classtranslotator_1_1Matrix.md)&lt; N, 1, Type &gt; | [**col**](classtranslotator_1_1MatrixBase.md#function-col) (size\_t j) const<br>_Returns the j-th column._  |
|  void | [**copyTo**](classtranslotator_1_1MatrixBase.md#function-copyto) (Type \* data) const<br>_Returns the raw data pointer._  |
|  void | [**fill**](classtranslotator_1_1MatrixBase.md#function-fill) (const Type & v) <br>_Fills the matrix with a value._  |
|  Type | [**frobeniusNorm**](classtranslotator_1_1MatrixBase.md#function-frobeniusnorm) () const<br> |
|  Type | [**frobeniusNormSquared**](classtranslotator_1_1MatrixBase.md#function-frobeniusnormsquared) () const<br>_Returns the squared Frobenius norm._  |
|  Type \* | [**getData**](classtranslotator_1_1MatrixBase.md#function-getdata) () const<br> |
|  const Type & | [**operator()**](classtranslotator_1_1MatrixBase.md#function-operator()-12) (size\_t i, size\_t j) const<br>_Accesses the element at (i, j)_  |
|  Type & | [**operator()**](classtranslotator_1_1MatrixBase.md#function-operator()-22) (size\_t i, size\_t j) <br>_Accesses the element at (i, j)_  |
|  auto | [**operator\***](classtranslotator_1_1MatrixBase.md#function-operator) (const OtherDerived & other) const<br>[_**Matrix**_](classtranslotator_1_1Matrix.md) _multiplication._ |
|  Derived | [**operator\***](classtranslotator_1_1MatrixBase.md#function-operator_1) (const Type & v) const<br>[_**Matrix**_](classtranslotator_1_1Matrix.md) _multiplication by scalar._ |
|  void | [**operator\*=**](classtranslotator_1_1MatrixBase.md#function-operator_2) (const OtherDerived & other) <br>[_**Matrix**_](classtranslotator_1_1Matrix.md) _multiplication by scalar._ |
|  Derived | [**operator+**](classtranslotator_1_1MatrixBase.md#function-operator_3) (const OtherDerived & other) const<br>_Multiplication by scalar._  |
|  void | [**operator+=**](classtranslotator_1_1MatrixBase.md#function-operator_4) (const OtherDerived & other) <br>[_**Matrix**_](classtranslotator_1_1Matrix.md) _division by scalar._ |
|  Derived | [**operator-**](classtranslotator_1_1MatrixBase.md#function-operator_5) (const OtherDerived & other) const<br>[_**Matrix**_](classtranslotator_1_1Matrix.md) _subtraction._ |
|  Derived | [**operator-**](classtranslotator_1_1MatrixBase.md#function-operator_6) () const<br>[_**Matrix**_](classtranslotator_1_1Matrix.md) _multiplication by scalar._ |
|  void | [**operator-=**](classtranslotator_1_1MatrixBase.md#function-operator_7) (const OtherDerived & other) <br>[_**Matrix**_](classtranslotator_1_1Matrix.md) _subtraction by scalar._ |
|  Derived | [**operator/**](classtranslotator_1_1MatrixBase.md#function-operator_8) (Type v) const<br>_Division by scalar._  |
|  void | [**operator/=**](classtranslotator_1_1MatrixBase.md#function-operator_9) (Type v) <br>_Division by scalar._  |
|  Derived & | [**operator=**](classtranslotator_1_1MatrixBase.md#function-operator_10) (const Derived & other) <br>_Copies the data to the given pointer._  |
|  void | [**print**](classtranslotator_1_1MatrixBase.md#function-print) () const<br>_Prints the matrix._  |
|  [**Matrix**](classtranslotator_1_1Matrix.md)&lt; 1, M, Type &gt; | [**row**](classtranslotator_1_1MatrixBase.md#function-row) (size\_t i) const<br>_Returns the i-th row._  |
|  Derived & | [**setBlock**](classtranslotator_1_1MatrixBase.md#function-setblock-12) (size\_t i, size\_t j, const OtherDerived & block) <br>_Sets the element at (i, j)_  |
|  Derived & | [**setBlock**](classtranslotator_1_1MatrixBase.md#function-setblock-22) (const OtherDerived & block) <br>_Sets the i-th row._  |
|  Derived & | [**setCol**](classtranslotator_1_1MatrixBase.md#function-setcol-12) (size\_t j, const OtherDerived & col) <br>_Sets the j-th column._  |
|  Derived & | [**setCol**](classtranslotator_1_1MatrixBase.md#function-setcol-22) (const OtherDerived & col) <br>_Sets the j-th column._  |
|  Derived & | [**setRow**](classtranslotator_1_1MatrixBase.md#function-setrow-12) (size\_t i, const OtherDerived & row) <br>_Sets the i-th row._  |
|  Derived & | [**setRow**](classtranslotator_1_1MatrixBase.md#function-setrow-22) (const OtherDerived & row) <br>_Sets the i-th row._  |
|  void | [**swapCols**](classtranslotator_1_1MatrixBase.md#function-swapcols) (size\_t j1, size\_t j2) <br>_Swaps two columns._  |
|  void | [**swapRows**](classtranslotator_1_1MatrixBase.md#function-swaprows) (size\_t i1, size\_t i2) <br>_Swaps two rows._  |
|  Type | [**toScalar**](classtranslotator_1_1MatrixBase.md#function-toscalar) () const<br>_Casts the matrix to a scalar if it is a 1x1 matrix._  |




## Public Static Functions inherited from translotator::MatrixBase

See [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)

| Type | Name |
| ---: | :--- |
|  Derived | [**NaN**](classtranslotator_1_1MatrixBase.md#function-nan) () <br>_Returns a matrix filled with NaN._  |
|  constexpr static size\_t | [**colSize**](classtranslotator_1_1MatrixBase.md#function-colsize) () <br>_Returns the number of rows._  |
|  Derived | [**eye**](classtranslotator_1_1MatrixBase.md#function-eye) () <br>_Returns an identity matrix._  |
|  Derived | [**ones**](classtranslotator_1_1MatrixBase.md#function-ones) () <br>_Returns a matrix filled with ones._  |
|  constexpr static size\_t | [**rowSize**](classtranslotator_1_1MatrixBase.md#function-rowsize) () <br> |
|  Derived | [**zeros**](classtranslotator_1_1MatrixBase.md#function-zeros) () <br>_Returns a matrix filled with zeros._  |












## Protected Attributes inherited from translotator::MatrixBase

See [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)

| Type | Name |
| ---: | :--- |
|  Type | [**data\_**](classtranslotator_1_1MatrixBase.md#variable-data_)  <br> |






































# Detailed Description




**Template parameters:**


* `Type` floating point type

A quaternion is a hypercomplex number that extends the complex numbers. It can be represented as a 4-dimensional vector. The quaternion is defined as q = w + xi + yj + zk, where w, x, y, and z are real numbers, and i, j, and k are the fundamental quaternion units. The quaternion has the following properties: i^2 = j^2 = k^2 = ijk = -1. (Hamillton representation) This can be used to represent rotations in 3D space. Also can be used to represent rotations in 3D space. 


    
## Public Static Attributes Documentation




### variable OBJECT\_TYPE 

```C++
constexpr static ObjectType translotator::Quaternion< Type >::OBJECT_TYPE;
```




<hr>
## Public Functions Documentation




### function Im [1/2]

```C++
inline const Vector < 3, Type > translotator::Quaternion::Im () const
```




<hr>



### function Im [2/2]

```C++
inline Vector < 3, Type > & translotator::Quaternion::Im () 
```




<hr>



### function Quaternion [1/4]


```C++
inline translotator::Quaternion::Quaternion () 
```



constructors 


        

<hr>



### function Quaternion [2/4]

```C++
inline explicit translotator::Quaternion::Quaternion (
    Type w,
    Type x,
    Type y,
    Type z
) 
```




<hr>



### function Quaternion [3/4]

```C++
inline explicit translotator::Quaternion::Quaternion (
    Type w,
    const Vector < 3, Type > & v
) 
```




<hr>



### function Quaternion [4/4]

```C++
inline explicit translotator::Quaternion::Quaternion (
    const ComplexNum < Type > & cplx
) 
```




<hr>



### function Re [1/2]

```C++
inline const Type translotator::Quaternion::Re () const
```




<hr>



### function Re [2/2]

```C++
inline Type & translotator::Quaternion::Re () 
```




<hr>



### function canonicalize 

```C++
inline void translotator::Quaternion::canonicalize () 
```




<hr>



### function canonicalized 

_normalize the quaternion_ 
```C++
inline Quaternion < Type > translotator::Quaternion::canonicalized () const
```



get the canonicalized quaternion 


        

<hr>



### function conjugate 

```C++
inline void translotator::Quaternion::conjugate () 
```




<hr>



### function conjugated 

```C++
inline Quaternion < Type > translotator::Quaternion::conjugated () const
```




<hr>



### function inverse 

```C++
inline void translotator::Quaternion::inverse () 
```




<hr>



### function inversed 

```C++
inline Quaternion < Type > translotator::Quaternion::inversed () const
```




<hr>



### function norm 

```C++
inline Type translotator::Quaternion::norm () const
```




<hr>



### function normSquared 


```C++
inline Type translotator::Quaternion::normSquared () const
```



utils 


        

<hr>



### function normalize 

```C++
inline void translotator::Quaternion::normalize () 
```




<hr>



### function normalized 

```C++
inline Quaternion < Type > translotator::Quaternion::normalized () const
```




<hr>



### function operator\* 

```C++
inline Quaternion < Type > translotator::Quaternion::operator* (
    const Quaternion < Type > & q
) const
```




<hr>



### function operator\*= 

```C++
inline void translotator::Quaternion::operator*= (
    const Quaternion < Type > & q
) 
```




<hr>



### function operator/ 

```C++
inline Quaternion < Type > translotator::Quaternion::operator/ (
    const Quaternion < Type > & q
) const
```




<hr>



### function operator/= 

```C++
inline void translotator::Quaternion::operator/= (
    const Quaternion < Type > & q
) 
```




<hr>



### function operator[] 

```C++
inline Type translotator::Quaternion::operator[] (
    size_t i
) const
```




<hr>



### function operator[] 

```C++
inline Type & translotator::Quaternion::operator[] (
    size_t i
) 
```




<hr>



### function quatNumDiv 

```C++
inline Quaternion < Type > translotator::Quaternion::quatNumDiv (
    const Quaternion < Type > & q
) const
```




<hr>



### function quatNumDivEq 

```C++
inline void translotator::Quaternion::quatNumDivEq (
    const Quaternion < Type > & q
) 
```




<hr>



### function quatNumMul 

```C++
inline Quaternion < Type > translotator::Quaternion::quatNumMul (
    const Quaternion < Type > & q
) const
```




<hr>



### function quatNumMulEq 

```C++
inline void translotator::Quaternion::quatNumMulEq (
    const Quaternion < Type > & q
) 
```




<hr>



### function toMulMatrix 

_get the matrix that represents the quaternion multiplication_ 
```C++
inline SquareMatrix < 4, Type > translotator::Quaternion::toMulMatrix () const
```



casting 


        

<hr>



### function toRightMulMatrix 

```C++
inline SquareMatrix < 4, Type > translotator::Quaternion::toRightMulMatrix () const
```




<hr>



### function w [1/2]


```C++
inline Type translotator::Quaternion::w () const
```



accessors 


        

<hr>



### function w [2/2]

```C++
inline Type & translotator::Quaternion::w () 
```




<hr>



### function x [1/2]

```C++
inline Type translotator::Quaternion::x () const
```




<hr>



### function x [2/2]

```C++
inline Type & translotator::Quaternion::x () 
```




<hr>



### function y [1/2]

```C++
inline Type translotator::Quaternion::y () const
```




<hr>



### function y [2/2]

```C++
inline Type & translotator::Quaternion::y () 
```




<hr>



### function z [1/2]

```C++
inline Type translotator::Quaternion::z () const
```




<hr>



### function z [2/2]

```C++
inline Type & translotator::Quaternion::z () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/Quaternion.hpp`

