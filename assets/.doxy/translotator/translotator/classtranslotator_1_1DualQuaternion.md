

# Class translotator::DualQuaternion

**template &lt;typename Type&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)



_Represents a dual quaternion._ [More...](#detailed-description)

* `#include <DualQuaternion.hpp>`



Inherits the following classes: [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)


Inherited by the following classes: [translotator::UnitDualQuaternion](classtranslotator_1_1UnitDualQuaternion.md)














## Public Types inherited from translotator::MatrixBase

See [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)

| Type | Name |
| ---: | :--- |
| typedef Type | [**DATATYPE**](classtranslotator_1_1MatrixBase.md#typedef-datatype)  <br> |










## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr static ObjectType | [**OBJECT\_TYPE**](#variable-object_type)   = = ObjectType::DUAL\_QUATERNION<br> |


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
|  const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & | [**Du**](#function-du-12) () const<br> |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & | [**Du**](#function-du-22) () <br> |
|   | [**DualQuaternion**](#function-dualquaternion-14) () = default<br> |
|   | [**DualQuaternion**](#function-dualquaternion-24) (const Type & rw, const Type & rx, const Type & ry, const Type & rz, const Type & dw, const Type & dx, const Type & dy, const Type & dz) <br> |
|   | [**DualQuaternion**](#function-dualquaternion-34) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & r, const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & d) <br> |
|   | [**DualQuaternion**](#function-dualquaternion-44) (const [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; & dn) <br> |
|  const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & | [**Re**](#function-re-12) () const<br> |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & | [**Re**](#function-re-22) () <br> |
|  void | [**conjugateDual**](#function-conjugatedual) () <br> |
|  void | [**conjugateFull**](#function-conjugatefull) () <br> |
|  void | [**conjugatePrimary**](#function-conjugateprimary) () <br> |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**conjugatedDual**](#function-conjugateddual) () const<br>_qr + qd e =&gt; qr\* + qd\* e_  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**conjugatedFull**](#function-conjugatedfull) () const<br>_qr + qd e =&gt; qr - qd e_  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**conjugatedPrimary**](#function-conjugatedprimary) () const<br>_dual quaternion division_  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**dualQuatDiv**](#function-dualquatdiv) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & dq) const<br>_dual quaternion multiplication_  |
|  void | [**dualQuatDivEq**](#function-dualquatdiveq) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & dq) <br>_dual quaternion division_  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**dualQuatMul**](#function-dualquatmul) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & dq) const<br>_dual quaternion division_  |
|  void | [**dualQuatMulEq**](#function-dualquatmuleq) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & dq) <br>_dual quaternion multiplication_  |
|  const Type & | [**dw**](#function-dw-12) () const<br> |
|  Type & | [**dw**](#function-dw-22) () <br> |
|  const Type & | [**dx**](#function-dx-12) () const<br> |
|  Type & | [**dx**](#function-dx-22) () <br> |
|  const Type & | [**dy**](#function-dy-12) () const<br> |
|  Type & | [**dy**](#function-dy-22) () <br> |
|  const Type & | [**dz**](#function-dz-12) () const<br> |
|  Type & | [**dz**](#function-dz-22) () <br> |
|  void | [**inverse**](#function-inverse) () <br> |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**inversed**](#function-inversed) () const<br>_dual quaternion inverse_  |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; | [**normDualNum**](#function-normdualnum) () const<br>_qr + qd e =&gt; qr\* - qd\* e_  |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; | [**normDualNumSquared**](#function-normdualnumsquared) () const<br>_original dual quaternion norm squared with primary conjugate_  |
|  Type | [**normScalar**](#function-normscalar) () const<br> |
|  Type | [**normScalarSquared**](#function-normscalarsquared) () const<br>_dual quaternion norm squared, dual number norm squared again_  |
|  void | [**normalize**](#function-normalize) () const<br> |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**normalized**](#function-normalized) () const<br>_dual quaternion inverse in place_  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**operator\***](#function-operator) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & other) const<br>_dual quaternion multiplication_  |
|  void | [**operator\*=**](#function-operator_1) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & q) <br>_dual quaternion division_  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**operator/**](#function-operator_2) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & other) const<br> |
|  void | [**operator/=**](#function-operator_3) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & q) <br>_dual quaternion multiplication_  |
|  const Type & | [**operator[]**](#function-operator_4) (const size\_t & idx) const<br> |
|  Type & | [**operator[]**](#function-operator_5) (const size\_t & idx) <br> |
|  const Type & | [**rw**](#function-rw-12) () const<br> |
|  Type & | [**rw**](#function-rw-22) () <br> |
|  const Type & | [**rx**](#function-rx-12) () const<br> |
|  Type & | [**rx**](#function-rx-22) () <br> |
|  const Type & | [**ry**](#function-ry-12) () const<br> |
|  Type & | [**ry**](#function-ry-22) () <br> |
|  const Type & | [**rz**](#function-rz-12) () const<br> |
|  Type & | [**rz**](#function-rz-22) () <br> |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; 8, Type &gt; | [**toMulMatrix**](#function-tomulmatrix) () const<br>_dual quaternion to multiplication matrix_  |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; 8, Type &gt; | [**toRightMulMatrix**](#function-torightmulmatrix) () const<br>_dual quaternion to multiplication matrix from right_  |
|   | [**~DualQuaternion**](#function-dualquaternion) () = default<br> |


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
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**zeros**](#function-zeros) () <br>_dual quaternion normalization_  |


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


* `Type` data type

Dual quaternion is a hypercomplex number system that extends the idea of quaternion. Unit form is used to represent rigid transformations in 3D space. Dual quaternion is a pair of two quaternions, extension of dual number. 

**Note:**

Data structure : [rw, rx, ry, rz, dw, dx, dy, dz], (8 x 1) 





    
## Public Static Attributes Documentation




### variable OBJECT\_TYPE 

```C++
constexpr static ObjectType translotator::DualQuaternion< Type >::OBJECT_TYPE;
```




<hr>
## Public Functions Documentation




### function Du [1/2]

```C++
inline const Quaternion < Type > & translotator::DualQuaternion::Du () const
```




<hr>



### function Du [2/2]

```C++
inline Quaternion < Type > & translotator::DualQuaternion::Du () 
```




<hr>



### function DualQuaternion [1/4]

```C++
translotator::DualQuaternion::DualQuaternion () = default
```




<hr>



### function DualQuaternion [2/4]

```C++
inline translotator::DualQuaternion::DualQuaternion (
    const Type & rw,
    const Type & rx,
    const Type & ry,
    const Type & rz,
    const Type & dw,
    const Type & dx,
    const Type & dy,
    const Type & dz
) 
```




<hr>



### function DualQuaternion [3/4]

```C++
inline translotator::DualQuaternion::DualQuaternion (
    const Quaternion < Type > & r,
    const Quaternion < Type > & d
) 
```




<hr>



### function DualQuaternion [4/4]

```C++
inline translotator::DualQuaternion::DualQuaternion (
    const DualNumber < Type > & dn
) 
```




<hr>



### function Re [1/2]


```C++
inline const Quaternion < Type > & translotator::DualQuaternion::Re () const
```



accessors 


        

<hr>



### function Re [2/2]

```C++
inline Quaternion < Type > & translotator::DualQuaternion::Re () 
```




<hr>



### function conjugateDual 

```C++
inline void translotator::DualQuaternion::conjugateDual () 
```




<hr>



### function conjugateFull 

```C++
inline void translotator::DualQuaternion::conjugateFull () 
```




<hr>



### function conjugatePrimary 

```C++
inline void translotator::DualQuaternion::conjugatePrimary () 
```




<hr>



### function conjugatedDual 

_qr + qd e =&gt; qr\* + qd\* e_ 
```C++
inline DualQuaternion < Type > translotator::DualQuaternion::conjugatedDual () const
```



qr + qd e =&gt; qr - qd e 


        

<hr>



### function conjugatedFull 

_qr + qd e =&gt; qr - qd e_ 
```C++
inline DualQuaternion < Type > translotator::DualQuaternion::conjugatedFull () const
```



qr + qd e =&gt; qr\* - qd\* e 


        

<hr>



### function conjugatedPrimary 

_dual quaternion division_ 
```C++
inline DualQuaternion < Type > translotator::DualQuaternion::conjugatedPrimary () const
```



qr + qd e =&gt; qr\* + qd\* e 


        

<hr>



### function dualQuatDiv 

```C++
inline DualQuaternion < Type > translotator::DualQuaternion::dualQuatDiv (
    const DualQuaternion < Type > & dq
) const
```




<hr>



### function dualQuatDivEq 

```C++
inline void translotator::DualQuaternion::dualQuatDivEq (
    const DualQuaternion < Type > & dq
) 
```




<hr>



### function dualQuatMul 

```C++
inline DualQuaternion < Type > translotator::DualQuaternion::dualQuatMul (
    const DualQuaternion < Type > & dq
) const
```




<hr>



### function dualQuatMulEq 

```C++
inline void translotator::DualQuaternion::dualQuatMulEq (
    const DualQuaternion < Type > & dq
) 
```




<hr>



### function dw [1/2]

```C++
inline const Type & translotator::DualQuaternion::dw () const
```




<hr>



### function dw [2/2]

```C++
inline Type & translotator::DualQuaternion::dw () 
```




<hr>



### function dx [1/2]

```C++
inline const Type & translotator::DualQuaternion::dx () const
```




<hr>



### function dx [2/2]

```C++
inline Type & translotator::DualQuaternion::dx () 
```




<hr>



### function dy [1/2]

```C++
inline const Type & translotator::DualQuaternion::dy () const
```




<hr>



### function dy [2/2]

```C++
inline Type & translotator::DualQuaternion::dy () 
```




<hr>



### function dz [1/2]

```C++
inline const Type & translotator::DualQuaternion::dz () const
```




<hr>



### function dz [2/2]

```C++
inline Type & translotator::DualQuaternion::dz () 
```




<hr>



### function inverse 

```C++
inline void translotator::DualQuaternion::inverse () 
```




<hr>



### function inversed 

```C++
inline DualQuaternion < Type > translotator::DualQuaternion::inversed () const
```




<hr>



### function normDualNum 

```C++
inline DualNumber < Type > translotator::DualQuaternion::normDualNum () const
```




<hr>



### function normDualNumSquared 

```C++
inline DualNumber < Type > translotator::DualQuaternion::normDualNumSquared () const
```




<hr>



### function normScalar 

```C++
inline Type translotator::DualQuaternion::normScalar () const
```




<hr>



### function normScalarSquared 

```C++
inline Type translotator::DualQuaternion::normScalarSquared () const
```




<hr>



### function normalize 

```C++
inline void translotator::DualQuaternion::normalize () const
```




<hr>



### function normalized 

_dual quaternion inverse in place_ 
```C++
inline DualQuaternion < Type > translotator::DualQuaternion::normalized () const
```



Dual [**Quaternion**](classtranslotator_1_1Quaternion.md) Normalization.


Using primary conjugate for norm. Dual quaternion normalization can be derived from division by norm Determine the real part for ordinary quaternion normlization. Determine the dual part in closed-form solution, ,which is 4 dimensional projection with scaled real part. 

**Returns:**

normalized dual quaternion 





        

<hr>



### function operator\* 

```C++
inline DualQuaternion < Type > translotator::DualQuaternion::operator* (
    const DualQuaternion < Type > & other
) const
```




<hr>



### function operator\*= 

```C++
inline void translotator::DualQuaternion::operator*= (
    const DualQuaternion < Type > & q
) 
```




<hr>



### function operator/ 

```C++
inline DualQuaternion < Type > translotator::DualQuaternion::operator/ (
    const DualQuaternion < Type > & other
) const
```




<hr>



### function operator/= 

```C++
inline void translotator::DualQuaternion::operator/= (
    const DualQuaternion < Type > & q
) 
```




<hr>



### function operator[] 

```C++
inline const Type & translotator::DualQuaternion::operator[] (
    const size_t & idx
) const
```




<hr>



### function operator[] 

```C++
inline Type & translotator::DualQuaternion::operator[] (
    const size_t & idx
) 
```




<hr>



### function rw [1/2]

```C++
inline const Type & translotator::DualQuaternion::rw () const
```




<hr>



### function rw [2/2]

```C++
inline Type & translotator::DualQuaternion::rw () 
```




<hr>



### function rx [1/2]

```C++
inline const Type & translotator::DualQuaternion::rx () const
```




<hr>



### function rx [2/2]

```C++
inline Type & translotator::DualQuaternion::rx () 
```




<hr>



### function ry [1/2]

```C++
inline const Type & translotator::DualQuaternion::ry () const
```




<hr>



### function ry [2/2]

```C++
inline Type & translotator::DualQuaternion::ry () 
```




<hr>



### function rz [1/2]

```C++
inline const Type & translotator::DualQuaternion::rz () const
```




<hr>



### function rz [2/2]

```C++
inline Type & translotator::DualQuaternion::rz () 
```




<hr>



### function toMulMatrix 

_dual quaternion to multiplication matrix_ 
```C++
inline SquareMatrix < 8, Type > translotator::DualQuaternion::toMulMatrix () const
```



casts 


        

<hr>



### function toRightMulMatrix 

```C++
inline SquareMatrix < 8, Type > translotator::DualQuaternion::toRightMulMatrix () const
```




<hr>



### function ~DualQuaternion 

```C++
translotator::DualQuaternion::~DualQuaternion () = default
```




<hr>
## Public Static Functions Documentation




### function zeros 

_dual quaternion normalization_ 
```C++
static inline DualQuaternion < Type > translotator::DualQuaternion::zeros () 
```



static functions


zero dual quaternion 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/DualQuaternion.hpp`

