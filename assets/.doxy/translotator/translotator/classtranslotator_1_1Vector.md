

# Class translotator::Vector

**template &lt;size\_t N, typename Type&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**Vector**](classtranslotator_1_1Vector.md)



[_**Vector**_](classtranslotator_1_1Vector.md) _class._[More...](#detailed-description)

* `#include <Vector.hpp>`



Inherits the following classes: [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)
















## Public Types inherited from translotator::MatrixBase

See [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)

| Type | Name |
| ---: | :--- |
| typedef Type | [**DATATYPE**](classtranslotator_1_1MatrixBase.md#typedef-datatype)  <br> |










## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr static ObjectType | [**OBJECT\_TYPE**](#variable-object_type)   = = ObjectType::VECTOR<br> |


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
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; | [**cross**](#function-cross) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & other) const<br>_cross product operation_  |
|  Type | [**dot**](#function-dot) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; & other) const<br>_in-place normalize_  |
|  Type | [**norm**](#function-norm) () const<br> |
|  Type | [**normSquared**](#function-normsquared) () const<br>_return norm of vector_  |
|  void | [**normalize**](#function-normalize) () <br> |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; | [**normalized**](#function-normalized) () const<br>_return squared norm of vector_  |
|  Type & | [**operator[]**](#function-operator) (size\_t i) <br> |
|  const Type & | [**operator[]**](#function-operator_1) (size\_t i) const<br> |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; 3, Type &gt; | [**toCrossMatrix**](#function-tocrossmatrix) () const<br>_convert to cross matrix_  |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; N, Type &gt; | [**toDiagMatrix**](#function-todiagmatrix) () const<br>_convert to diagonal matrix_  |


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


* `N` vector size 
* `Type` floating point type

[**Vector**](classtranslotator_1_1Vector.md) class is a class that represents a vector. 


    
## Public Static Attributes Documentation




### variable OBJECT\_TYPE 

```C++
constexpr static ObjectType translotator::Vector< N, Type >::OBJECT_TYPE;
```




<hr>
## Public Functions Documentation




### function cross 

_cross product operation_ 
```C++
template<size_t Dim, typename>
inline Vector < 3, Type > translotator::Vector::cross (
    const Vector < 3, Type > & other
) const
```





**Note:**

only for 3D vector 





        

<hr>



### function dot 

_in-place normalize_ 
```C++
inline Type translotator::Vector::dot (
    const Vector < N, Type > & other
) const
```



[**Vector**](classtranslotator_1_1Vector.md) utils dot product 


        

<hr>



### function norm 

```C++
inline Type translotator::Vector::norm () const
```




<hr>



### function normSquared 

```C++
inline Type translotator::Vector::normSquared () const
```




<hr>



### function normalize 

```C++
inline void translotator::Vector::normalize () 
```




<hr>



### function normalized 

_return squared norm of vector_ 
```C++
inline Vector < N, Type > translotator::Vector::normalized () const
```



return normalized vector 


        

<hr>



### function operator[] 


```C++
inline Type & translotator::Vector::operator[] (
    size_t i
) 
```



[**Vector**](classtranslotator_1_1Vector.md) Specialized Accessors 


        

<hr>



### function operator[] 

```C++
inline const Type & translotator::Vector::operator[] (
    size_t i
) const
```




<hr>



### function toCrossMatrix 

_convert to cross matrix_ 
```C++
template<size_t Dim, typename>
inline SquareMatrix < 3, Type > translotator::Vector::toCrossMatrix () const
```





**Note:**

only for 3D vector 





        

<hr>



### function toDiagMatrix 

```C++
inline SquareMatrix < N, Type > translotator::Vector::toDiagMatrix () const
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/Vector.hpp`
