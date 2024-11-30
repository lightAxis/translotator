

# Class translotator::DualNumber

**template &lt;typename Type&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**DualNumber**](classtranslotator_1_1DualNumber.md)



_Represents a dual number._ [More...](#detailed-description)

* `#include <DualNumber.hpp>`



Inherits the following classes: [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)
















## Public Types inherited from translotator::MatrixBase

See [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)

| Type | Name |
| ---: | :--- |
| typedef Type | [**DATATYPE**](classtranslotator_1_1MatrixBase.md#typedef-datatype)  <br> |










## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr static ObjectType | [**OBJECT\_TYPE**](#variable-object_type)   = = ObjectType::DUAL\_NUMBER<br> |


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
|  Type | [**Du**](#function-du-12) () const<br> |
|  Type & | [**Du**](#function-du-22) () <br> |
|   | [**DualNumber**](#function-dualnumber-12) () <br> |
|   | [**DualNumber**](#function-dualnumber-22) (const Type & r, const Type & d) <br> |
|  Type | [**Re**](#function-re-12) () const<br> |
|  Type & | [**Re**](#function-re-22) () <br> |
|  void | [**conjugate**](#function-conjugate) () <br>_return the conjugate of this dual number_  |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; | [**conjugated**](#function-conjugated) () const<br> |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; | [**dualNumDiv**](#function-dualnumdiv) (const [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; & other) const<br>_multiply this dual number with another dual number_  |
|  void | [**dualNumDivEq**](#function-dualnumdiveq) (const [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; & other) <br>_return the division of two dual numbers_  |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; | [**dualNumMul**](#function-dualnummul) (const [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; & other) const<br>_divide this dual number with another dual number_  |
|  void | [**dualNumMulEq**](#function-dualnummuleq) (const [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; & other) <br>_return the multiplication of two dual numbers_  |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; | [**inversed**](#function-inversed) () const<br>_normalize the real part of this dual number_  |
|  Type | [**norm**](#function-norm) () const<br>_return the squared norm of this dual number_  |
|  Type | [**normSquared**](#function-normsquared) () const<br>_conjugate this dual number_  |
|  void | [**normalize**](#function-normalize) () <br>_return a new_ [_**DualNumber**_](classtranslotator_1_1DualNumber.md) _with normalized real part_ |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; | [**normalized**](#function-normalized) () const<br>_return the norm of this dual number_  |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; | [**operator\***](#function-operator) (const [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; & other) const<br>_return the multiplication of two dual numbers_  |
|  void | [**operator\*=**](#function-operator_1) (const [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; & other) <br> |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; | [**operator/**](#function-operator_2) (const [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; & other) const<br>_return the division of two dual numbers_  |
|  void | [**operator/=**](#function-operator_3) (const [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; & other) <br>_multiply this dual number with another dual number_  |
|  Type | [**operator[]**](#function-operator_4) (size\_t i) const<br> |
|  Type & | [**operator[]**](#function-operator_5) (size\_t i) <br> |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; 2, Type &gt; | [**toMulMatrix**](#function-tomulmatrix) () const<br>_return a 2x2 matrix that represents the multiplication of this dual number_  |


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


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; | [**sqrt**](#function-sqrt) (const [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; & dn) <br>_divide this dual number with another dual number_  |


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


[**DualNumber**](classtranslotator_1_1DualNumber.md) 

**Template parameters:**


* `Type` floating point type

A dual number is a pair of real numbers, where one is the real part and the other is the dual part. The dual part is a number that squares to zero, i.e., e^2 = 0. It is used to represent infinitesimal quantities. 

**Note:**

Data structure : [real, dual], (2 x 1) 





    
## Public Static Attributes Documentation




### variable OBJECT\_TYPE 

```C++
constexpr static ObjectType translotator::DualNumber< Type >::OBJECT_TYPE;
```




<hr>
## Public Functions Documentation




### function Du [1/2]

```C++
inline Type translotator::DualNumber::Du () const
```




<hr>



### function Du [2/2]

```C++
inline Type & translotator::DualNumber::Du () 
```




<hr>



### function DualNumber [1/2]

```C++
inline translotator::DualNumber::DualNumber () 
```




<hr>



### function DualNumber [2/2]

```C++
inline translotator::DualNumber::DualNumber (
    const Type & r,
    const Type & d
) 
```




<hr>



### function Re [1/2]


```C++
inline Type translotator::DualNumber::Re () const
```



accessors 


        

<hr>



### function Re [2/2]

```C++
inline Type & translotator::DualNumber::Re () 
```




<hr>



### function conjugate 

```C++
inline void translotator::DualNumber::conjugate () 
```




<hr>



### function conjugated 


```C++
inline DualNumber < Type > translotator::DualNumber::conjugated () const
```



utils 


        

<hr>



### function dualNumDiv 

```C++
inline DualNumber < Type > translotator::DualNumber::dualNumDiv (
    const DualNumber < Type > & other
) const
```




<hr>



### function dualNumDivEq 

```C++
inline void translotator::DualNumber::dualNumDivEq (
    const DualNumber < Type > & other
) 
```




<hr>



### function dualNumMul 

```C++
inline DualNumber < Type > translotator::DualNumber::dualNumMul (
    const DualNumber < Type > & other
) const
```




<hr>



### function dualNumMulEq 

```C++
inline void translotator::DualNumber::dualNumMulEq (
    const DualNumber < Type > & other
) 
```




<hr>



### function inversed 

```C++
inline DualNumber < Type > translotator::DualNumber::inversed () const
```




<hr>



### function norm 

```C++
inline Type translotator::DualNumber::norm () const
```




<hr>



### function normSquared 

```C++
inline Type translotator::DualNumber::normSquared () const
```




<hr>



### function normalize 

```C++
inline void translotator::DualNumber::normalize () 
```




<hr>



### function normalized 

```C++
inline DualNumber < Type > translotator::DualNumber::normalized () const
```




<hr>



### function operator\* 

```C++
inline DualNumber < Type > translotator::DualNumber::operator* (
    const DualNumber < Type > & other
) const
```




<hr>



### function operator\*= 

```C++
inline void translotator::DualNumber::operator*= (
    const DualNumber < Type > & other
) 
```




<hr>



### function operator/ 

```C++
inline DualNumber < Type > translotator::DualNumber::operator/ (
    const DualNumber < Type > & other
) const
```




<hr>



### function operator/= 

```C++
inline void translotator::DualNumber::operator/= (
    const DualNumber < Type > & other
) 
```




<hr>



### function operator[] 

```C++
inline Type translotator::DualNumber::operator[] (
    size_t i
) const
```




<hr>



### function operator[] 

```C++
inline Type & translotator::DualNumber::operator[] (
    size_t i
) 
```




<hr>



### function toMulMatrix 

_return a 2x2 matrix that represents the multiplication of this dual number_ 
```C++
inline SquareMatrix < 2, Type > translotator::DualNumber::toMulMatrix () const
```



casts 


        

<hr>
## Public Static Functions Documentation




### function sqrt 

_divide this dual number with another dual number_ 
```C++
static inline DualNumber < Type > translotator::DualNumber::sqrt (
    const DualNumber < Type > & dn
) 
```



static functions return the square root of a dual number. Re &gt; 0 is required 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/DualNumber.hpp`

