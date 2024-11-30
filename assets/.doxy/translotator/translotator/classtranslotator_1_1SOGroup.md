

# Class translotator::SOGroup

**template &lt;size\_t N, typename Type&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**SOGroup**](classtranslotator_1_1SOGroup.md)



_Special Orthogonal Group._ [More...](#detailed-description)

* `#include <SOGroup.hpp>`



Inherits the following classes: [translotator::SquareMatrix](classtranslotator_1_1SquareMatrix.md)


















## Public Types inherited from translotator::MatrixBase

See [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)

| Type | Name |
| ---: | :--- |
| typedef Type | [**DATATYPE**](classtranslotator_1_1MatrixBase.md#typedef-datatype)  <br> |














## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr static ObjectType | [**OBJECT\_TYPE**](#variable-object_type)   = = ObjectType::SO\_GROUP<br> |


## Public Static Attributes inherited from translotator::SquareMatrix

See [translotator::SquareMatrix](classtranslotator_1_1SquareMatrix.md)

| Type | Name |
| ---: | :--- |
|  constexpr static ObjectType | [**OBJECT\_TYPE**](classtranslotator_1_1SquareMatrix.md#variable-object_type)   = = ObjectType::SQUARE\_MATRIX<br> |


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
|   | [**SOGroup**](#function-sogroup-25) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; & vec1, const [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; & vec2, bool col=true) <br> |
|   | [**SOGroup**](#function-sogroup-35) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; & vec1, const [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; & vec2, const [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; & vec3, bool col=true) <br> |
|   | [**SOGroup**](#function-sogroup-45) (const Type & theta) <br> |
|   | [**SOGroup**](#function-sogroup-55) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; & angleVector) <br> |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; | [**T**](#function-t) () const<br>_transpose_  |
|  void | [**inverse**](#function-inverse) () <br>_inverse this matrix_  |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; | [**inversed**](#function-inversed) () const<br>_inverse is same as transpose in_ [_**SOGroup**_](classtranslotator_1_1SOGroup.md) __ |
|  void | [**normalize**](#function-normalize) () <br>_normalize this matrix_  |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; | [**normalized**](#function-normalized) () const<br>_Get the orthogonalized matrix._  |
|  auto | [**operator\***](#function-operator) (const OtherContainer & other) const<br>[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _\*_[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _=&gt;_[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _._ |
|  void | [**operator\*=**](#function-operator_1) (const [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; & other) <br>[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _\*=_[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _._ |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; N, Type &gt; | [**operator+**](#function-operator_2) (const OtherContainer & other) const<br>[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _+_[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _=&gt;_[_**SquareMatrix**_](classtranslotator_1_1SquareMatrix.md) _._ |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; N, Type &gt; | [**operator-**](#function-operator_3) (const OtherContainer & other) const<br>[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _-_[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _=&gt;_[_**SquareMatrix**_](classtranslotator_1_1SquareMatrix.md) _._ |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; | [**operator-**](#function-operator_4) () const<br>_-_ [_**SOGroup**_](classtranslotator_1_1SOGroup.md) __ |
|  auto | [**operator/**](#function-operator_5) (const OtherContainer & other) const<br>[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _/_[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _=&gt;_[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _._ |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; | [**pow**](#function-pow) (const Type & t) const<br>_power of_ [_**SOGroup**_](classtranslotator_1_1SOGroup.md) _. Using Exponential & Logarithm Map of Lie Group_ |
|  [**AxisAngle**](classtranslotator_1_1AxisAngle.md)&lt; Type &gt; | [**toAxisAngle**](#function-toaxisangle) () const<br>_convert to_ [_**AxisAngle**_](classtranslotator_1_1AxisAngle.md) __ |
|  [**EulerAngle**](classtranslotator_1_1EulerAngle.md)&lt; Type, NewOrder &gt; | [**toEulerAngle**](#function-toeulerangle) () const<br>_Convert to Euler Angle._  |
|  [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; | [**toUnitComplexNum**](#function-tounitcomplexnum) () const<br>_convert to_ [_**UnitComplexNum**_](classtranslotator_1_1UnitComplexNum.md) _. Using only z-axis_ |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; | [**toUnitQuaternion**](#function-tounitquaternion) () const<br>_convert to_ [_**UnitQuaternion**_](classtranslotator_1_1UnitQuaternion.md) __ |


## Public Functions inherited from translotator::SquareMatrix

See [translotator::SquareMatrix](classtranslotator_1_1SquareMatrix.md)

| Type | Name |
| ---: | :--- |
|  Type | [**determinant**](classtranslotator_1_1SquareMatrix.md#function-determinant) () const<br>_determinant of a square matrix. Only 2x2, 3x3 matrices are supported_  |
|  void | [**inverse**](classtranslotator_1_1SquareMatrix.md#function-inverse) () <br> |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; N, Type &gt; | [**inversed**](classtranslotator_1_1SquareMatrix.md#function-inversed) (bool & result) const<br>_1x1 ~ 3x3 closed form solution 4x4 ~ LU factorization with partial pivotting from PX4-Matrix Library_  |
|  Type | [**trace**](classtranslotator_1_1SquareMatrix.md#function-trace) () const<br>_trace of a square matrix_  |


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
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; | [**axisRotation**](#function-axisrotation) (const Type & angle) <br>_Create a rotation matrix around the axis._  |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; | [**identity**](#function-identity) () <br>_identity rotation element, which is identity matrix_  |




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


* `N` dimension 
* `Type` data type

Special Orthogonal Group is a group of rotation in N dimension. It is a group of orthogonal matrices with determinant 1. Subgroup of [**SOGroup**](classtranslotator_1_1SOGroup.md) is SO(2) and SO(3). Also [**SOGroup**](classtranslotator_1_1SOGroup.md) is a Lie Group. Exponential and Logarithm map can be defined. 


    
## Public Static Attributes Documentation




### variable OBJECT\_TYPE 

```C++
constexpr static ObjectType translotator::SOGroup< N, Type >::OBJECT_TYPE;
```




<hr>
## Public Functions Documentation




### function SOGroup [2/5]


```C++
template<size_t N_, typename>
inline translotator::SOGroup::SOGroup (
    const Vector < N, Type > & vec1,
    const Vector < N, Type > & vec2,
    bool col=true
) 
```



constructors 


        

<hr>



### function SOGroup [3/5]

```C++
template<size_t N_, typename>
inline translotator::SOGroup::SOGroup (
    const Vector < N, Type > & vec1,
    const Vector < N, Type > & vec2,
    const Vector < N, Type > & vec3,
    bool col=true
) 
```




<hr>



### function SOGroup [4/5]

```C++
template<size_t N_, typename>
inline explicit translotator::SOGroup::SOGroup (
    const Type & theta
) 
```




<hr>



### function SOGroup [5/5]

```C++
template<size_t N_, typename>
inline explicit translotator::SOGroup::SOGroup (
    const Vector < N, Type > & angleVector
) 
```




<hr>



### function T 

```C++
inline SOGroup < N, Type > translotator::SOGroup::T () const
```




<hr>



### function inverse 

```C++
inline void translotator::SOGroup::inverse () 
```




<hr>



### function inversed 

```C++
inline SOGroup < N, Type > translotator::SOGroup::inversed () const
```




<hr>



### function normalize 

```C++
inline void translotator::SOGroup::normalize () 
```




<hr>



### function normalized 

_Get the orthogonalized matrix._ 
```C++
inline SOGroup < N, Type > translotator::SOGroup::normalized () const
```



utils 

**Returns:**

[**SOGroup&lt;N, Type&gt;**](classtranslotator_1_1SOGroup.md) 




**Note:**

This function uses [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md) & UnitQuternion internally. Not a mathmatically correct way, but it works. 





        

<hr>



### function operator\* 

[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _\*_[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _=&gt;_[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _._
```C++
template<typename OtherContainer>
inline auto translotator::SOGroup::operator* (
    const OtherContainer & other
) const
```





**Template parameters:**


* `OtherContainer` [**Matrix**](classtranslotator_1_1Matrix.md) based object with same dimension [**SOGroup**](classtranslotator_1_1SOGroup.md) \* [**SOGroup**](classtranslotator_1_1SOGroup.md) =&gt; [**SOGroup**](classtranslotator_1_1SOGroup.md) 




        

<hr>



### function operator\*= 

```C++
inline void translotator::SOGroup::operator*= (
    const SOGroup < N, Type > & other
) 
```




<hr>



### function operator+ 

[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _+_[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _=&gt;_[_**SquareMatrix**_](classtranslotator_1_1SquareMatrix.md) _._
```C++
template<typename OtherContainer>
inline SquareMatrix < N, Type > translotator::SOGroup::operator+ (
    const OtherContainer & other
) const
```



operators 

**Template parameters:**


* `OtherContainer` [**Matrix**](classtranslotator_1_1Matrix.md) based object with same dimension 




        

<hr>



### function operator- 

[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _-_[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _=&gt;_[_**SquareMatrix**_](classtranslotator_1_1SquareMatrix.md) _._
```C++
template<typename OtherContainer>
inline SquareMatrix < N, Type > translotator::SOGroup::operator- (
    const OtherContainer & other
) const
```





**Template parameters:**


* `OtherContainer` [**Matrix**](classtranslotator_1_1Matrix.md) based object with same dimension [**SOGroup**](classtranslotator_1_1SOGroup.md) - [**SOGroup**](classtranslotator_1_1SOGroup.md) =&gt; [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md) 




        

<hr>



### function operator- 

```C++
inline SOGroup < N, Type > translotator::SOGroup::operator- () const
```




<hr>



### function operator/ 

[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _/_[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _=&gt;_[_**SOGroup**_](classtranslotator_1_1SOGroup.md) _._
```C++
template<typename OtherContainer>
inline auto translotator::SOGroup::operator/ (
    const OtherContainer & other
) const
```





**Template parameters:**


* `OtherContainer` [**Matrix**](classtranslotator_1_1Matrix.md) based object with same dimension 




        

<hr>



### function pow 

```C++
inline SOGroup < N, Type > translotator::SOGroup::pow (
    const Type & t
) const
```




<hr>



### function toAxisAngle 

```C++
inline AxisAngle < Type > translotator::SOGroup::toAxisAngle () const
```




<hr>



### function toEulerAngle 

_Convert to Euler Angle._ 
```C++
template<EULER_ORDER NewOrder>
inline EulerAngle < Type, NewOrder > translotator::SOGroup::toEulerAngle () const
```





**Template parameters:**


* `NewOrder` New Euler Order 




        

<hr>



### function toUnitComplexNum 

_convert to_ [_**UnitComplexNum**_](classtranslotator_1_1UnitComplexNum.md) _. Using only z-axis_
```C++
inline UnitComplexNum < Type > translotator::SOGroup::toUnitComplexNum () const
```



casts 


        

<hr>



### function toUnitQuaternion 

```C++
inline UnitQuaternion < Type > translotator::SOGroup::toUnitQuaternion () const
```




<hr>
## Public Static Functions Documentation




### function axisRotation 

_Create a rotation matrix around the axis._ 
```C++
template<AXIS Axis>
static inline SOGroup < N, Type > translotator::SOGroup::axisRotation (
    const Type & angle
) 
```





**Template parameters:**


* `Axis` Axis to rotate 



**Parameters:**


* `angle` angle in radian 




        

<hr>



### function identity 

_identity rotation element, which is identity matrix_ 
```C++
static inline SOGroup < N, Type > translotator::SOGroup::identity () 
```



static functions 


        

<hr>## Friends Documentation





### friend operator\* 

```C++
inline SquareMatrix < N, Type > translotator::SOGroup::operator* (
    const Type & lhs,
    const SOGroup & rhs
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/SOGroup.hpp`

