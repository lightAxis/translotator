

# Class translotator::MatrixBase

**template &lt;size\_t N, size\_t M, typename Type, typename Derived&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**MatrixBase**](classtranslotator_1_1MatrixBase.md)



_Base class for all matrix objects._ [More...](#detailed-description)

* `#include <MatrixBase.hpp>`





Inherited by the following classes: [translotator::Vector](classtranslotator_1_1Vector.md)












## Public Types

| Type | Name |
| ---: | :--- |
| typedef Type | [**DATATYPE**](#typedef-datatype)  <br> |






## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr static size\_t | [**COLS**](#variable-cols)   = = M<br> |
|  constexpr static bool | [**MATRIX\_BASE**](#variable-matrix_base)   = = true<br> |
|  constexpr static size\_t | [**ROWS**](#variable-rows)   = = N<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**MatrixBase**](#function-matrixbase-15) () = default<br>_Returns the number of columns._  |
|   | [**MatrixBase**](#function-matrixbase-25) (const [**MatrixBase**](classtranslotator_1_1MatrixBase.md) & other) = default<br> |
|   | [**MatrixBase**](#function-matrixbase-35) (const Type data) <br> |
|   | [**MatrixBase**](#function-matrixbase-45) (const Type data) <br> |
|   | [**MatrixBase**](#function-matrixbase-55) (const [**initializer\_list**](structtranslotator_1_1initializer__list.md)&lt; N \*M, Type &gt; & list) <br>_Initializer list constructor._  |
|  auto | [**T**](#function-t) () const<br>_Transpose._  |
|  [**Matrix**](classtranslotator_1_1Matrix.md)&lt; P, Q, Type &gt; | [**block**](#function-block-12) (size\_t i, size\_t j) const<br>_Returns a block of the matrix._  |
|  [**Matrix**](classtranslotator_1_1Matrix.md)&lt; P, Q, Type &gt; | [**block**](#function-block-22) () const<br>_Returns a block of the matrix._  |
|  [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; | [**cast2ComplexNum**](#function-cast2complexnum) () const<br>_Casts the object to a complex number by copying._  |
|  [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; & | [**cast2ComplexNumRef**](#function-cast2complexnumref) () <br>_Casts the object to a complex number reference without copying._  |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; | [**cast2DualNumber**](#function-cast2dualnumber) () const<br>_Casts the object to a dual number by copying._  |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; & | [**cast2DualNumberRef**](#function-cast2dualnumberref) () <br>_Casts the object to a dual number reference without copying._  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**cast2DualQuaternion**](#function-cast2dualquaternion) () const<br>_Casts the object to a dual quaternion by copying._  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & | [**cast2DualQuaternionRef**](#function-cast2dualquaternionref) () <br>_Casts the object to a dual quaternion reference without copying._  |
|  [**Matrix**](classtranslotator_1_1Matrix.md)&lt; N, M, Type &gt; | [**cast2Matrix**](#function-cast2matrix) () const<br>_Casts the object to a different matrix type by copying._  |
|  [**Matrix**](classtranslotator_1_1Matrix.md)&lt; N, M, Type &gt; & | [**cast2MatrixRef**](#function-cast2matrixref) () <br>_Casts the object to a matrix reference without copying._  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**cast2Quaternion**](#function-cast2quaternion) () const<br>_Casts the object to a quaternion by copying._  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & | [**cast2QuaternionRef**](#function-cast2quaternionref) () <br>_Casts the object to a quaternion reference without copying._  |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; | [**cast2SOGroup**](#function-cast2sogroup) () const<br>_Casts the object to a special orthogonal group by copying._  |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; & | [**cast2SOGroupRef**](#function-cast2sogroupref) () <br>_Casts the object to a special orthogonal group reference without copying._  |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; N, Type &gt; | [**cast2SquareMatrix**](#function-cast2squarematrix) () const<br>_Casts the object to a square matrix by copying._  |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; N, Type &gt; & | [**cast2SquareMatrixRef**](#function-cast2squarematrixref) () <br>_Casts the object to a square matrix reference without copying._  |
|  [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; | [**cast2UnitComplexNum**](#function-cast2unitcomplexnum) () const<br>_Casts the object to a unit complex number by copying._  |
|  [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; & | [**cast2UnitComplexNumRef**](#function-cast2unitcomplexnumref) () <br>_Casts the object to a unit complex number reference without copying._  |
|  [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; | [**cast2UnitDualQuaternion**](#function-cast2unitdualquaternion) () const<br>_Casts the object to a unit dual quaternion by copying._  |
|  [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; & | [**cast2UnitDualQuaternionRef**](#function-cast2unitdualquaternionref) () <br>_Casts the object to a unit dual quaternion reference without copying._  |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; | [**cast2UnitQuaternion**](#function-cast2unitquaternion) () const<br>_Casts the object to a unit quaternion by copying._  |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; & | [**cast2UnitQuaternionRef**](#function-cast2unitquaternionref) () <br>_Casts the object to a unit quaternion reference without copying._  |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; | [**cast2Vector**](#function-cast2vector) () const<br>_Casts the object to a vector by copying._  |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; & | [**cast2VectorRef**](#function-cast2vectorref) () <br>_Casts the object to a vector reference without copying._  |
|  NewContainer | [**castContainer**](#function-castcontainer) () const<br>_Casts the matrix to a different container type by copying._  |
|  NewContainer & | [**castContainerRef**](#function-castcontainerref-12) () <br>_Casts the object to a different container reference without copying._  |
|  NewDerived & | [**castContainerRef**](#function-castcontainerref-22) () <br> |
|  auto | [**castDataType**](#function-castdatatype) () const<br>_Returns the Frobenius norm._  |
|  [**Matrix**](classtranslotator_1_1Matrix.md)&lt; N, 1, Type &gt; | [**col**](#function-col) (size\_t j) const<br>_Returns the j-th column._  |
|  void | [**copyTo**](#function-copyto) (Type \* data) const<br>_Returns the raw data pointer._  |
|  void | [**fill**](#function-fill) (const Type & v) <br>_Fills the matrix with a value._  |
|  Type | [**frobeniusNorm**](#function-frobeniusnorm) () const<br> |
|  Type | [**frobeniusNormSquared**](#function-frobeniusnormsquared) () const<br>_Returns the squared Frobenius norm._  |
|  Type \* | [**getData**](#function-getdata) () const<br> |
|  const Type & | [**operator()**](#function-operator()-12) (size\_t i, size\_t j) const<br>_Accesses the element at (i, j)_  |
|  Type & | [**operator()**](#function-operator()-22) (size\_t i, size\_t j) <br>_Accesses the element at (i, j)_  |
|  auto | [**operator\***](#function-operator) (const OtherDerived & other) const<br>[_**Matrix**_](classtranslotator_1_1Matrix.md) _multiplication._ |
|  Derived | [**operator\***](#function-operator_1) (const Type & v) const<br>[_**Matrix**_](classtranslotator_1_1Matrix.md) _multiplication by scalar._ |
|  void | [**operator\*=**](#function-operator_2) (const OtherDerived & other) <br>[_**Matrix**_](classtranslotator_1_1Matrix.md) _multiplication by scalar._ |
|  Derived | [**operator+**](#function-operator_3) (const OtherDerived & other) const<br>_Multiplication by scalar._  |
|  void | [**operator+=**](#function-operator_4) (const OtherDerived & other) <br>[_**Matrix**_](classtranslotator_1_1Matrix.md) _division by scalar._ |
|  Derived | [**operator-**](#function-operator_5) (const OtherDerived & other) const<br>[_**Matrix**_](classtranslotator_1_1Matrix.md) _subtraction._ |
|  Derived | [**operator-**](#function-operator_6) () const<br>[_**Matrix**_](classtranslotator_1_1Matrix.md) _multiplication by scalar._ |
|  void | [**operator-=**](#function-operator_7) (const OtherDerived & other) <br>[_**Matrix**_](classtranslotator_1_1Matrix.md) _subtraction by scalar._ |
|  Derived | [**operator/**](#function-operator_8) (Type v) const<br>_Division by scalar._  |
|  void | [**operator/=**](#function-operator_9) (Type v) <br>_Division by scalar._  |
|  Derived & | [**operator=**](#function-operator_10) (const Derived & other) <br>_Copies the data to the given pointer._  |
|  void | [**print**](#function-print) () const<br>_Prints the matrix._  |
|  [**Matrix**](classtranslotator_1_1Matrix.md)&lt; 1, M, Type &gt; | [**row**](#function-row) (size\_t i) const<br>_Returns the i-th row._  |
|  Derived & | [**setBlock**](#function-setblock-12) (size\_t i, size\_t j, const OtherDerived & block) <br>_Sets the element at (i, j)_  |
|  Derived & | [**setBlock**](#function-setblock-22) (const OtherDerived & block) <br>_Sets the i-th row._  |
|  Derived & | [**setCol**](#function-setcol-12) (size\_t j, const OtherDerived & col) <br>_Sets the j-th column._  |
|  Derived & | [**setCol**](#function-setcol-22) (const OtherDerived & col) <br>_Sets the j-th column._  |
|  Derived & | [**setRow**](#function-setrow-12) (size\_t i, const OtherDerived & row) <br>_Sets the i-th row._  |
|  Derived & | [**setRow**](#function-setrow-22) (const OtherDerived & row) <br>_Sets the i-th row._  |
|  void | [**swapCols**](#function-swapcols) (size\_t j1, size\_t j2) <br>_Swaps two columns._  |
|  void | [**swapRows**](#function-swaprows) (size\_t i1, size\_t i2) <br>_Swaps two rows._  |
|  Type | [**toScalar**](#function-toscalar) () const<br>_Casts the matrix to a scalar if it is a 1x1 matrix._  |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  Derived | [**NaN**](#function-nan) () <br>_Returns a matrix filled with NaN._  |
|  constexpr static size\_t | [**colSize**](#function-colsize) () <br>_Returns the number of rows._  |
|  Derived | [**eye**](#function-eye) () <br>_Returns an identity matrix._  |
|  Derived | [**ones**](#function-ones) () <br>_Returns a matrix filled with ones._  |
|  constexpr static size\_t | [**rowSize**](#function-rowsize) () <br> |
|  Derived | [**zeros**](#function-zeros) () <br>_Returns a matrix filled with zeros._  |






## Protected Attributes

| Type | Name |
| ---: | :--- |
|  Type | [**data\_**](#variable-data_)  <br> |




















# Detailed Description




**Template parameters:**


* `N` Number of rows 
* `M` Number of columns 
* `Type` Data type of the matrix 
* `Derived` Derived class, CRTP 



**Note:**

This class is not meant to be used directly, use other matrix-based object classes instead.


This class provides basic matrix operations and functionalities. 


    
## Public Types Documentation




### typedef DATATYPE 

```C++
using translotator::MatrixBase< N, M, Type, Derived >::DATATYPE =  Type;
```




<hr>
## Public Static Attributes Documentation




### variable COLS 

```C++
constexpr static size_t translotator::MatrixBase< N, M, Type, Derived >::COLS;
```




<hr>



### variable MATRIX\_BASE 

```C++
constexpr static bool translotator::MatrixBase< N, M, Type, Derived >::MATRIX_BASE;
```




<hr>



### variable ROWS 

```C++
constexpr static size_t translotator::MatrixBase< N, M, Type, Derived >::ROWS;
```




<hr>
## Public Functions Documentation




### function MatrixBase [1/5]

_Returns the number of columns._ 
```C++
translotator::MatrixBase::MatrixBase () = default
```



Constructors and destructor 


        

<hr>



### function MatrixBase [2/5]

```C++
explicit translotator::MatrixBase::MatrixBase (
    const MatrixBase & other
) = default
```




<hr>



### function MatrixBase [3/5]

```C++
inline explicit translotator::MatrixBase::MatrixBase (
    const Type data
) 
```




<hr>



### function MatrixBase [4/5]

```C++
inline explicit translotator::MatrixBase::MatrixBase (
    const Type data
) 
```




<hr>



### function MatrixBase [5/5]

```C++
inline explicit translotator::MatrixBase::MatrixBase (
    const initializer_list < N *M, Type > & list
) 
```




<hr>



### function T 

_Transpose._ 
```C++
inline auto translotator::MatrixBase::T () const
```



Utils 


        

<hr>



### function block [1/2]

_Returns a block of the matrix._ 
```C++
template<size_t P, size_t Q>
inline Matrix < P, Q, Type > translotator::MatrixBase::block (
    size_t i,
    size_t j
) const
```





**Template parameters:**


* `P` Number of rows in the block 
* `Q` Number of columns in the block 



**Parameters:**


* `i` Starting row index 
* `j` Starting column index 




        

<hr>



### function block [2/2]

_Returns a block of the matrix._ 
```C++
template<size_t i, size_t j, size_t P, size_t Q>
inline Matrix < P, Q, Type > translotator::MatrixBase::block () const
```





**Template parameters:**


* `i` Starting row index 
* `j` Starting column index 
* `P` Number of rows in the block 
* `Q` Number of columns in the block 




        

<hr>



### function cast2ComplexNum 

_Casts the object to a complex number by copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline ComplexNum < Type > translotator::MatrixBase::cast2ComplexNum () const
```





**Returns:**

Complex number object with same data type 




**Note:**

This function is only available for 2 x 1 dimensions 




**Note:**

This functions is alias of castContainer&lt;ComplexNum&lt;Type&gt;&gt;() function 





        

<hr>



### function cast2ComplexNumRef 

_Casts the object to a complex number reference without copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline ComplexNum < Type > & translotator::MatrixBase::cast2ComplexNumRef () 
```





**Returns:**

Complex number object with same data type 




**Note:**

This function is only available for 2 x 1 dimensions. Not recommended for temporary objects. 




**Note:**

This function is alias of castContainerRef&lt;ComplexNum&lt;Type&gt;&gt;() function 





        

<hr>



### function cast2DualNumber 

_Casts the object to a dual number by copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline DualNumber < Type > translotator::MatrixBase::cast2DualNumber () const
```





**Returns:**

Dual number object with same data type 




**Note:**

This function is only available for 2 x 1 dimensions 




**Note:**

This functions is alias of castContainer&lt;DualNumber&lt;Type&gt;&gt;() function 





        

<hr>



### function cast2DualNumberRef 

_Casts the object to a dual number reference without copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline DualNumber < Type > & translotator::MatrixBase::cast2DualNumberRef () 
```





**Returns:**

Dual number object with same data type 




**Note:**

This function is only available for 2 x 1 dimensions. Not recommended for temporary objects. 




**Note:**

This function is alias of castContainerRef&lt;DualNumber&lt;Type&gt;&gt;() function 





        

<hr>



### function cast2DualQuaternion 

_Casts the object to a dual quaternion by copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline DualQuaternion < Type > translotator::MatrixBase::cast2DualQuaternion () const
```





**Returns:**

Dual quaternion object with same data type 




**Note:**

This function is only available for 8 x 1 dimensions 




**Note:**

This functions is alias of castContainer&lt;DualQuaternion&lt;Type&gt;&gt;() function 





        

<hr>



### function cast2DualQuaternionRef 

_Casts the object to a dual quaternion reference without copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline DualQuaternion < Type > & translotator::MatrixBase::cast2DualQuaternionRef () 
```





**Returns:**

Dual quaternion object with same data type 




**Note:**

This function is only available for 8 x 1 dimensions. Not recommended for temporary objects. 




**Note:**

This function is alias of castContainerRef&lt;DualQuaternion&lt;Type&gt;&gt;() function 





        

<hr>



### function cast2Matrix 

_Casts the object to a different matrix type by copying._ 
```C++
inline Matrix < N, M, Type > translotator::MatrixBase::cast2Matrix () const
```





**Template parameters:**


* `NewContainer` New matrix type 



**Returns:**

[**Matrix**](classtranslotator_1_1Matrix.md) object with same dimensions and data type 




**Note:**

This functions is alias of castContainer&lt;Matrix&lt;N, M, Type&gt;&gt;() function 





        

<hr>



### function cast2MatrixRef 

_Casts the object to a matrix reference without copying._ 
```C++
inline Matrix < N, M, Type > & translotator::MatrixBase::cast2MatrixRef () 
```





**Returns:**

[**Matrix**](classtranslotator_1_1Matrix.md) object with same dimensions and data type 




**Note:**

This function is only available for N x M dimensions. Not recommended for temporary objects. 




**Note:**

This function is alias of castContainerRef&lt;Matrix&lt;N, M, Type&gt;&gt;() function 





        

<hr>



### function cast2Quaternion 

_Casts the object to a quaternion by copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline Quaternion < Type > translotator::MatrixBase::cast2Quaternion () const
```





**Returns:**

[**Quaternion**](classtranslotator_1_1Quaternion.md) object with same data type 




**Note:**

This function is only available for 4 x 1 dimensions 




**Note:**

This functions is alias of castContainer&lt;Quaternion&lt;Type&gt;&gt;() function 





        

<hr>



### function cast2QuaternionRef 

_Casts the object to a quaternion reference without copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline Quaternion < Type > & translotator::MatrixBase::cast2QuaternionRef () 
```





**Returns:**

[**Quaternion**](classtranslotator_1_1Quaternion.md) object with same data type 




**Note:**

This function is only available for 4 x 1 dimensions. Not recommended for temporary objects. 




**Note:**

This function is alias of castContainerRef&lt;Quaternion&lt;Type&gt;&gt;() function 





        

<hr>



### function cast2SOGroup 

_Casts the object to a special orthogonal group by copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline SOGroup < N, Type > translotator::MatrixBase::cast2SOGroup () const
```





**Returns:**

[**SOGroup**](classtranslotator_1_1SOGroup.md) object with same data type 




**Note:**

This function is only available for 2 x 2 or 3 x 3 dimensions 




**Note:**

This functions is alias of castContainer&lt;[**SOGroup&lt;N, Type&gt;**](classtranslotator_1_1SOGroup.md)&gt;() function 




**Note:**

If the input is not a special orthogonal group, the output will be normalized to be a special orthogonal group 





        

<hr>



### function cast2SOGroupRef 

_Casts the object to a special orthogonal group reference without copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline SOGroup < N, Type > & translotator::MatrixBase::cast2SOGroupRef () 
```





**Returns:**

[**SOGroup**](classtranslotator_1_1SOGroup.md) object with same data type 




**Note:**

This function is only available for 2 x 2 or 3 x 3 dimensions. Not recommended for temporary objects. 




**Note:**

This function is alias of castContainerRef&lt;[**SOGroup&lt;N, Type&gt;**](classtranslotator_1_1SOGroup.md)&gt;() function 




**Note:**

If the input is not a special orthogonal group, the output & original object will be normalized to be a special orthogonal group 





        

<hr>



### function cast2SquareMatrix 

_Casts the object to a square matrix by copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline SquareMatrix < N, Type > translotator::MatrixBase::cast2SquareMatrix () const
```





**Returns:**

Square matrix object with same dimensions and data type 




**Note:**

This function is only available for N x N dimensions 




**Note:**

This functions is alias of castContainer&lt;SquareMatrix&lt;N, Type&gt;&gt;() function 





        

<hr>



### function cast2SquareMatrixRef 

_Casts the object to a square matrix reference without copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline SquareMatrix < N, Type > & translotator::MatrixBase::cast2SquareMatrixRef () 
```





**Returns:**

Square matrix object with same dimensions and data type 




**Note:**

This function is only available for N x N dimensions. Not recommended for temporary objects. 




**Note:**

This function is alias of castContainerRef&lt;SquareMatrix&lt;N, Type&gt;&gt;() function 





        

<hr>



### function cast2UnitComplexNum 

_Casts the object to a unit complex number by copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline UnitComplexNum < Type > translotator::MatrixBase::cast2UnitComplexNum () const
```





**Returns:**

Unit complex number object with same data type 




**Note:**

This function is only available for 2 x 1 dimensions 




**Note:**

This functions is alias of castContainer&lt;UnitComplexNum&lt;Type&gt;&gt;() function 




**Note:**

If the input is not a unit complex number, the output will be normalized to be a unit complex number 





        

<hr>



### function cast2UnitComplexNumRef 

_Casts the object to a unit complex number reference without copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline UnitComplexNum < Type > & translotator::MatrixBase::cast2UnitComplexNumRef () 
```





**Returns:**

Unit complex number object with same data type 




**Note:**

This function is only available for 2 x 1 dimensions. Not recommended for temporary objects. 




**Note:**

This function is alias of castContainerRef&lt;UnitComplexNum&lt;Type&gt;&gt;() function 




**Note:**

If the input is not a unit complex number, the output & original object will be normalized to be a unit complex number 





        

<hr>



### function cast2UnitDualQuaternion 

_Casts the object to a unit dual quaternion by copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline UnitDualQuaternion < Type > translotator::MatrixBase::cast2UnitDualQuaternion () const
```





**Returns:**

Unit dual quaternion object with same data type 




**Note:**

This function is only available for 8 x 1 dimensions 




**Note:**

This functions is alias of castContainer&lt;UnitDualQuaternion&lt;Type&gt;&gt;() function 




**Note:**

If the input is not a unit dual quaternion, the output will be normalized to be a unit dual quaternion 





        

<hr>



### function cast2UnitDualQuaternionRef 

_Casts the object to a unit dual quaternion reference without copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline UnitDualQuaternion < Type > & translotator::MatrixBase::cast2UnitDualQuaternionRef () 
```





**Returns:**

Unit dual quaternion object with same data type 




**Note:**

This function is only available for 8 x 1 dimensions. Not recommended for temporary objects. 




**Note:**

This function is alias of castContainerRef&lt;UnitDualQuaternion&lt;Type&gt;&gt;() function 




**Note:**

If the input is not a unit dual quaternion, the output & original object will be normalized to be a unit dual quaternion 





        

<hr>



### function cast2UnitQuaternion 

_Casts the object to a unit quaternion by copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline UnitQuaternion < Type > translotator::MatrixBase::cast2UnitQuaternion () const
```





**Returns:**

Unit quaternion object with same data type 




**Note:**

This function is only available for 4 x 1 dimensions 




**Note:**

This functions is alias of castContainer&lt;UnitQuaternion&lt;Type&gt;&gt;() function 




**Note:**

If the input is not a unit quaternion, the output will be normalized to be a unit quaternion 





        

<hr>



### function cast2UnitQuaternionRef 

_Casts the object to a unit quaternion reference without copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline UnitQuaternion < Type > & translotator::MatrixBase::cast2UnitQuaternionRef () 
```





**Returns:**

Unit quaternion object with same data type 




**Note:**

This function is only available for 4 x 1 dimensions. Not recommended for temporary objects. 




**Note:**

This function is alias of castContainerRef&lt;UnitQuaternion&lt;Type&gt;&gt;() function 




**Note:**

If the input is not a unit quaternion, the output & original object will be normalized to be a unit quaternion 





        

<hr>



### function cast2Vector 

_Casts the object to a vector by copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline Vector < N, Type > translotator::MatrixBase::cast2Vector () const
```





**Returns:**

[**Vector**](classtranslotator_1_1Vector.md) object with same dimensions and data type 




**Note:**

This function is only available for M x 1 dimensions 




**Note:**

This functions is alias of castContainer&lt;[**Vector&lt;N, Type&gt;**](classtranslotator_1_1Vector.md)&gt;() function 





        

<hr>



### function cast2VectorRef 

_Casts the object to a vector reference without copying._ 
```C++
template<size_t N_, size_t M_, typename>
inline Vector < N, Type > & translotator::MatrixBase::cast2VectorRef () 
```





**Returns:**

[**Vector**](classtranslotator_1_1Vector.md) object with same dimensions and data type 




**Note:**

This function is only available for M x 1 dimensions. Not recommended for temporary objects. 




**Note:**

This function is alias of castContainerRef&lt;[**Vector&lt;N, Type&gt;**](classtranslotator_1_1Vector.md)&gt;() function 





        

<hr>



### function castContainer 

_Casts the matrix to a different container type by copying._ 
```C++
template<typename NewContainer>
inline NewContainer translotator::MatrixBase::castContainer () const
```





**Template parameters:**


* `NewContainer` New container type

This function is only available for containers with the same size as the matrix 


        

<hr>



### function castContainerRef [1/2]

_Casts the object to a different container reference without copying._ 
```C++
template<typename NewContainer>
inline NewContainer & translotator::MatrixBase::castContainerRef () 
```





**Template parameters:**


* `NewContainer` New container type

This function is only available for containers with the same size as the matrix 

**Note:**

This function is recommended for temporary objects. Use [**castContainer()**](classtranslotator_1_1MatrixBase.md#function-castcontainer) and alias functions for permanent objects. 





        

<hr>



### function castContainerRef [2/2]

```C++
template<typename NewDerived>
inline NewDerived & translotator::MatrixBase::castContainerRef () 
```




<hr>



### function castDataType 

_Returns the Frobenius norm._ 
```C++
template<typename NewType>
inline auto translotator::MatrixBase::castDataType () const
```



Type Casting


Casts the matrix to a different data type 

**Template parameters:**


* `NewType` New data type

This function is only available for floating point types 


        

<hr>



### function col 

```C++
inline Matrix < N, 1, Type > translotator::MatrixBase::col (
    size_t j
) const
```




<hr>



### function copyTo 

```C++
inline void translotator::MatrixBase::copyTo (
    Type * data
) const
```




<hr>



### function fill 

```C++
inline void translotator::MatrixBase::fill (
    const Type & v
) 
```




<hr>



### function frobeniusNorm 

```C++
inline Type translotator::MatrixBase::frobeniusNorm () const
```




<hr>



### function frobeniusNormSquared 

```C++
inline Type translotator::MatrixBase::frobeniusNormSquared () const
```




<hr>



### function getData 

```C++
inline Type * translotator::MatrixBase::getData () const
```




<hr>



### function operator() [1/2]

_Accesses the element at (i, j)_ 
```C++
inline const Type & translotator::MatrixBase::operator() (
    size_t i,
    size_t j
) const
```



Accessors 


        

<hr>



### function operator() [2/2]

```C++
inline Type & translotator::MatrixBase::operator() (
    size_t i,
    size_t j
) 
```




<hr>



### function operator\* 

[_**Matrix**_](classtranslotator_1_1Matrix.md) _multiplication._
```C++
template<typename OtherDerived>
inline auto translotator::MatrixBase::operator* (
    const OtherDerived & other
) const
```





**Template parameters:**


* `OtherDerived` [**Matrix**](classtranslotator_1_1Matrix.md) Derived class to multiply 



**Parameters:**


* `other` [**Matrix**](classtranslotator_1_1Matrix.md) Derived class to multiply 




        

<hr>



### function operator\* 

[_**Matrix**_](classtranslotator_1_1Matrix.md) _multiplication by scalar._
```C++
inline Derived translotator::MatrixBase::operator* (
    const Type & v
) const
```





**Parameters:**


* `v` Scalar value

Multiplies the matrix by a scalar value 


        

<hr>



### function operator\*= 

[_**Matrix**_](classtranslotator_1_1Matrix.md) _multiplication by scalar._
```C++
template<typename OtherDerived>
inline void translotator::MatrixBase::operator*= (
    const OtherDerived & other
) 
```





**Parameters:**


* `v` Scalar value

Multiplies the matrix by a scalar value 


        

<hr>



### function operator+ 

_Multiplication by scalar._ 
```C++
template<typename OtherDerived>
inline Derived translotator::MatrixBase::operator+ (
    const OtherDerived & other
) const
```



Operator Objects


[**Matrix**](classtranslotator_1_1Matrix.md) addition 

**Template parameters:**


* `OtherDerived` [**Matrix**](classtranslotator_1_1Matrix.md) Derived class to add 



**Parameters:**


* `other` [**Matrix**](classtranslotator_1_1Matrix.md) Derived class to add 




        

<hr>



### function operator+= 

[_**Matrix**_](classtranslotator_1_1Matrix.md) _division by scalar._
```C++
template<typename OtherDerived>
inline void translotator::MatrixBase::operator+= (
    const OtherDerived & other
) 
```





**Parameters:**


* `v` Scalar value

Divides the matrix by a scalar value 


        

<hr>



### function operator- 

[_**Matrix**_](classtranslotator_1_1Matrix.md) _subtraction._
```C++
template<typename OtherDerived>
inline Derived translotator::MatrixBase::operator- (
    const OtherDerived & other
) const
```





**Template parameters:**


* `OtherDerived` [**Matrix**](classtranslotator_1_1Matrix.md) Derived class to subtract 



**Parameters:**


* `other` [**Matrix**](classtranslotator_1_1Matrix.md) Derived class to subtract 




        

<hr>



### function operator- 

[_**Matrix**_](classtranslotator_1_1Matrix.md) _multiplication by scalar._
```C++
inline Derived translotator::MatrixBase::operator- () const
```





**Parameters:**


* `v` Scalar value

Multiplies the matrix by a scalar value 


        

<hr>



### function operator-= 

[_**Matrix**_](classtranslotator_1_1Matrix.md) _subtraction by scalar._
```C++
template<typename OtherDerived>
inline void translotator::MatrixBase::operator-= (
    const OtherDerived & other
) 
```





**Parameters:**


* `v` Scalar value

Subtracts the matrix by a scalar value 


        

<hr>



### function operator/ 

_Division by scalar._ 
```C++
inline Derived translotator::MatrixBase::operator/ (
    Type v
) const
```



operators Scalar 


        

<hr>



### function operator/= 

```C++
inline void translotator::MatrixBase::operator/= (
    Type v
) 
```




<hr>



### function operator= 

_Copies the data to the given pointer._ 
```C++
inline Derived & translotator::MatrixBase::operator= (
    const Derived & other
) 
```



Assignments Copy assignment 


        

<hr>



### function print 

```C++
inline void translotator::MatrixBase::print () const
```




<hr>



### function row 

```C++
inline Matrix < 1, M, Type > translotator::MatrixBase::row (
    size_t i
) const
```




<hr>



### function setBlock [1/2]

_Sets the element at (i, j)_ 
```C++
template<typename OtherDerived>
inline Derived & translotator::MatrixBase::setBlock (
    size_t i,
    size_t j,
    const OtherDerived & block
) 
```





**Parameters:**


* `i` Row index 
* `j` Column index 



**Template parameters:**


* `OtherDerived` [**Matrix**](classtranslotator_1_1Matrix.md) Derived class to set the element from 




        

<hr>



### function setBlock [2/2]

_Sets the i-th row._ 
```C++
template<size_t i, size_t j, typename OtherDerived>
inline Derived & translotator::MatrixBase::setBlock (
    const OtherDerived & block
) 
```





**Template parameters:**


* `i` Row index 
* `j` Column index 
* `OtherDerived` [**Matrix**](classtranslotator_1_1Matrix.md) Derived class to set the row from

This function is a compile-time version of setRow 


        

<hr>



### function setCol [1/2]

_Sets the j-th column._ 
```C++
template<typename OtherDerived>
inline Derived & translotator::MatrixBase::setCol (
    size_t j,
    const OtherDerived & col
) 
```





**Parameters:**


* `j` Column index 



**Template parameters:**


* `OtherDerived` [**Matrix**](classtranslotator_1_1Matrix.md) Derived class to set the column from 




        

<hr>



### function setCol [2/2]

_Sets the j-th column._ 
```C++
template<size_t j, typename OtherDerived>
inline Derived & translotator::MatrixBase::setCol (
    const OtherDerived & col
) 
```





**Template parameters:**


* `j` Column index 
* `OtherDerived` [**Matrix**](classtranslotator_1_1Matrix.md) Derived class to set the column from

This function is a compile-time version of setCol 


        

<hr>



### function setRow [1/2]

_Sets the i-th row._ 
```C++
template<typename OtherDerived>
inline Derived & translotator::MatrixBase::setRow (
    size_t i,
    const OtherDerived & row
) 
```





**Parameters:**


* `i` Row index 



**Template parameters:**


* `OtherDerived` [**Matrix**](classtranslotator_1_1Matrix.md) Derived class to set the row from 




        

<hr>



### function setRow [2/2]

_Sets the i-th row._ 
```C++
template<size_t i, typename OtherDerived>
inline Derived & translotator::MatrixBase::setRow (
    const OtherDerived & row
) 
```





**Template parameters:**


* `i` Row index 
* `OtherDerived` [**Matrix**](classtranslotator_1_1Matrix.md) Derived class to set the row from

This function is a compile-time version of setRow 


        

<hr>



### function swapCols 

```C++
inline void translotator::MatrixBase::swapCols (
    size_t j1,
    size_t j2
) 
```




<hr>



### function swapRows 

```C++
inline void translotator::MatrixBase::swapRows (
    size_t i1,
    size_t i2
) 
```




<hr>



### function toScalar 

```C++
template<size_t N_, size_t M_, typename>
inline Type translotator::MatrixBase::toScalar () const
```




<hr>
## Public Static Functions Documentation




### function NaN 

```C++
static inline Derived translotator::MatrixBase::NaN () 
```




<hr>



### function colSize 

```C++
static inline constexpr static size_t translotator::MatrixBase::colSize () 
```




<hr>



### function eye 

_Returns an identity matrix._ 
```C++
static inline Derived translotator::MatrixBase::eye () 
```



Constant Matrices 


        

<hr>



### function ones 

```C++
static inline Derived translotator::MatrixBase::ones () 
```




<hr>



### function rowSize 

```C++
static inline constexpr static size_t translotator::MatrixBase::rowSize () 
```




<hr>



### function zeros 

```C++
static inline Derived translotator::MatrixBase::zeros () 
```




<hr>
## Protected Attributes Documentation




### variable data\_ 

```C++
Type translotator::MatrixBase< N, M, Type, Derived >::data_[N *M];
```




<hr>## Friends Documentation





### friend operator\* 

```C++
inline Derived translotator::MatrixBase::operator* (
    Type lhs,
    const Derived & rhs
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/MatrixBase.hpp`

