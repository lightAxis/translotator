

# Class translotator::UnitQuaternion

**template &lt;typename Type&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)



[_**UnitQuaternion**_](classtranslotator_1_1UnitQuaternion.md) _class._[More...](#detailed-description)

* `#include <UnitQuaternion.hpp>`



Inherits the following classes: [translotator::Quaternion](classtranslotator_1_1Quaternion.md)


















## Public Types inherited from translotator::MatrixBase

See [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)

| Type | Name |
| ---: | :--- |
| typedef Type | [**DATATYPE**](classtranslotator_1_1MatrixBase.md#typedef-datatype)  <br> |














## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr static ObjectType | [**OBJECT\_TYPE**](#variable-object_type)   = = ObjectType::UNIT\_QUATERNION<br> |


## Public Static Attributes inherited from translotator::Quaternion

See [translotator::Quaternion](classtranslotator_1_1Quaternion.md)

| Type | Name |
| ---: | :--- |
|  constexpr static ObjectType | [**OBJECT\_TYPE**](classtranslotator_1_1Quaternion.md#variable-object_type)   = = ObjectType::QUATERNION<br> |


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
|   | [**UnitQuaternion**](#function-unitquaternion-23) () <br> |
|   | [**UnitQuaternion**](#function-unitquaternion-33) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & angleVec) <br> |
|  void | [**canonicalize**](#function-canonicalize) () <br> |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; | [**canonicalized**](#function-canonicalized) () const<br>_return canonicalized unit quaternion. if w &lt; 0, negate all components._  |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; | [**conjugated**](#function-conjugated) () const<br>_return conjugated unit quaternion. Primary conjugated._  |
|  void | [**inverse**](#function-inverse) () <br> |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; | [**inversed**](#function-inversed) () const<br>_return inversed unit quaternion. It is same as conjugated._  |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; | [**normalized**](#function-normalized) () const<br>_return normalized unit quaternion_  |
|  auto | [**operator\***](#function-operator) (const OtherContainer & other) const<br>_operator\* operator_  |
|  void | [**operator\*=**](#function-operator_1) (const [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; & other) <br>_Unit \* Unit = Unit._  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**operator+**](#function-operator_2) (const OtherContainer & other) const<br>_operator+ operator_  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**operator-**](#function-operator_3) (const OtherContainer & other) const<br>_operator- operator_  |
|  auto | [**operator/**](#function-operator_4) (const OtherContainer & other) const<br>_operator/ operator_  |
|  void | [**operator/=**](#function-operator_5) (const [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; & other) <br>_Unit / Unit = Unit._  |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; | [**pow**](#function-pow) (const Type & t) const<br>_canonicalize this unit quaternion_  |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; | [**quatNumDiv**](#function-quatnumdiv-12) (const [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; & other) const<br> |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**quatNumDiv**](#function-quatnumdiv-22) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & other) const<br>_alias for operator/ for readability_  |
|  void | [**quatNumDivEq**](#function-quatnumdiveq-12) (const [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; & other) <br>_alias for operator/ for readability_  |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; | [**quatNumMul**](#function-quatnummul-13) (const [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; & other) const<br> |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**quatNumMul**](#function-quatnummul-23) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & other) const<br>_alias for operator\* for readability_  |
|  void | [**quatNumMulEq**](#function-quatnummuleq-12) (const [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; & other) <br> |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 2, Type &gt; | [**rotateVector2D**](#function-rotatevector2d) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; 2, Type &gt; & v) const<br>_rotate 2D vector. Using only w, z component._  |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; | [**rotateVector3D**](#function-rotatevector3d) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & v) const<br>_inverse this unit quaternion_  |
|  [**AxisAngle**](classtranslotator_1_1AxisAngle.md)&lt; Type &gt; | [**toAxisAngle**](#function-toaxisangle) () const<br>_convert to axis angle_  |
|  [**EulerAngle**](classtranslotator_1_1EulerAngle.md)&lt; Type, AxisOrder &gt; | [**toEulerAngle2D**](#function-toeulerangle2d) () const<br>_convert to euler angle_  |
|  [**EulerAngle**](classtranslotator_1_1EulerAngle.md)&lt; Type, NewOrder &gt; | [**toEulerAngle3D**](#function-toeulerangle3d) () const<br>_convert to euler angle_  |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; 2, Type &gt; | [**toRotMatrix2D**](#function-torotmatrix2d) () const<br>_convert to SO(2) group, Using only z axis rotation_  |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; 3, Type &gt; | [**toRotMatrix3D**](#function-torotmatrix3d) () const<br>_convert to SO(3) group_  |


## Public Functions inherited from translotator::Quaternion

See [translotator::Quaternion](classtranslotator_1_1Quaternion.md)

| Type | Name |
| ---: | :--- |
|  const [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; | [**Im**](classtranslotator_1_1Quaternion.md#function-im-12) () const<br> |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & | [**Im**](classtranslotator_1_1Quaternion.md#function-im-22) () <br> |
|   | [**Quaternion**](classtranslotator_1_1Quaternion.md#function-quaternion-14) () <br> |
|   | [**Quaternion**](classtranslotator_1_1Quaternion.md#function-quaternion-24) (Type w, Type x, Type y, Type z) <br> |
|   | [**Quaternion**](classtranslotator_1_1Quaternion.md#function-quaternion-34) (Type w, const [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & v) <br> |
|   | [**Quaternion**](classtranslotator_1_1Quaternion.md#function-quaternion-44) (const [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; & cplx) <br> |
|  const Type | [**Re**](classtranslotator_1_1Quaternion.md#function-re-12) () const<br> |
|  Type & | [**Re**](classtranslotator_1_1Quaternion.md#function-re-22) () <br> |
|  void | [**canonicalize**](classtranslotator_1_1Quaternion.md#function-canonicalize) () <br> |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**canonicalized**](classtranslotator_1_1Quaternion.md#function-canonicalized) () const<br>_normalize the quaternion_  |
|  void | [**conjugate**](classtranslotator_1_1Quaternion.md#function-conjugate) () <br>_get the conjugated quaternion_  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**conjugated**](classtranslotator_1_1Quaternion.md#function-conjugated) () const<br>_canonicalize the quaternion_  |
|  void | [**inverse**](classtranslotator_1_1Quaternion.md#function-inverse) () <br>_get the inversed quaternion_  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**inversed**](classtranslotator_1_1Quaternion.md#function-inversed) () const<br>_conjugate the quaternion_  |
|  Type | [**norm**](classtranslotator_1_1Quaternion.md#function-norm) () const<br>_get the squared norm of the quaternion_  |
|  Type | [**normSquared**](classtranslotator_1_1Quaternion.md#function-normsquared) () const<br> |
|  void | [**normalize**](classtranslotator_1_1Quaternion.md#function-normalize) () <br>_get the normalized quaternion_  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**normalized**](classtranslotator_1_1Quaternion.md#function-normalized) () const<br>_get the norm of the quaternion_  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**operator\***](classtranslotator_1_1Quaternion.md#function-operator) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) const<br>_quaternion multiplication_  |
|  void | [**operator\*=**](classtranslotator_1_1Quaternion.md#function-operator_1) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) <br>_quaternion division_  |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**operator/**](classtranslotator_1_1Quaternion.md#function-operator_2) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) const<br> |
|  void | [**operator/=**](classtranslotator_1_1Quaternion.md#function-operator_3) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) <br>_quaternion multiplication_  |
|  Type | [**operator[]**](classtranslotator_1_1Quaternion.md#function-operator_4) (size\_t i) const<br> |
|  Type & | [**operator[]**](classtranslotator_1_1Quaternion.md#function-operator_5) (size\_t i) <br> |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**quatNumDiv**](classtranslotator_1_1Quaternion.md#function-quatnumdiv) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) const<br> |
|  void | [**quatNumDivEq**](classtranslotator_1_1Quaternion.md#function-quatnumdiveq) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) <br> |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**quatNumMul**](classtranslotator_1_1Quaternion.md#function-quatnummul) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) const<br>_quaternion division_  |
|  void | [**quatNumMulEq**](classtranslotator_1_1Quaternion.md#function-quatnummuleq) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & q) <br> |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; 4, Type &gt; | [**toMulMatrix**](classtranslotator_1_1Quaternion.md#function-tomulmatrix) () const<br>_get the matrix that represents the quaternion multiplication_  |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; 4, Type &gt; | [**toRightMulMatrix**](classtranslotator_1_1Quaternion.md#function-torightmulmatrix) () const<br>_get the matrix that represents the quaternion multiplication from the right_  |
|  Type | [**w**](classtranslotator_1_1Quaternion.md#function-w-12) () const<br> |
|  Type & | [**w**](classtranslotator_1_1Quaternion.md#function-w-22) () <br> |
|  Type | [**x**](classtranslotator_1_1Quaternion.md#function-x-12) () const<br> |
|  Type & | [**x**](classtranslotator_1_1Quaternion.md#function-x-22) () <br> |
|  Type | [**y**](classtranslotator_1_1Quaternion.md#function-y-12) () const<br> |
|  Type & | [**y**](classtranslotator_1_1Quaternion.md#function-y-22) () <br> |
|  Type | [**z**](classtranslotator_1_1Quaternion.md#function-z-12) () const<br> |
|  Type & | [**z**](classtranslotator_1_1Quaternion.md#function-z-22) () <br> |


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
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; | [**axisRotation**](#function-axisrotation) (const Type & angle) <br>_axis rotation unit quaternion_  |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; | [**identity**](#function-identity) () <br>_identity unit quaternion_  |




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

[**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md) class is a class that represents a unit quaternion. A unit quaternion is a quaternion that has a length of 1. 


    
## Public Static Attributes Documentation




### variable OBJECT\_TYPE 

```C++
constexpr static ObjectType translotator::UnitQuaternion< Type >::OBJECT_TYPE;
```




<hr>
## Public Functions Documentation




### function UnitQuaternion [2/3]


```C++
inline translotator::UnitQuaternion::UnitQuaternion () 
```



constructors 


        

<hr>



### function UnitQuaternion [3/3]

```C++
inline translotator::UnitQuaternion::UnitQuaternion (
    const Vector < 3, Type > & angleVec
) 
```




<hr>



### function canonicalize 

```C++
inline void translotator::UnitQuaternion::canonicalize () 
```




<hr>



### function canonicalized 

```C++
inline UnitQuaternion < Type > translotator::UnitQuaternion::canonicalized () const
```




<hr>



### function conjugated 

```C++
inline UnitQuaternion < Type > translotator::UnitQuaternion::conjugated () const
```




<hr>



### function inverse 

```C++
inline void translotator::UnitQuaternion::inverse () 
```




<hr>



### function inversed 

```C++
inline UnitQuaternion < Type > translotator::UnitQuaternion::inversed () const
```




<hr>



### function normalized 

_return normalized unit quaternion_ 
```C++
inline UnitQuaternion < Type > translotator::UnitQuaternion::normalized () const
```



utils 


        

<hr>



### function operator\* 

_operator\* operator_ 
```C++
template<typename OtherContainer>
inline auto translotator::UnitQuaternion::operator* (
    const OtherContainer & other
) const
```





**Template parameters:**


* `OtherContainer` other container matrix-base type

This operator is used to multiply two quaternions. 

**Note:**

Unit \* Unit = Unit, 




**Note:**

Unit \* [**Quaternion**](classtranslotator_1_1Quaternion.md) = [**Quaternion**](classtranslotator_1_1Quaternion.md), 




**Note:**

Unit \* Type = [**Quaternion**](classtranslotator_1_1Quaternion.md), 




**Note:**

else, follows the matrix multiplication rule 





        

<hr>



### function operator\*= 

```C++
inline void translotator::UnitQuaternion::operator*= (
    const UnitQuaternion < Type > & other
) 
```




<hr>



### function operator+ 

_operator+ operator_ 
```C++
template<typename OtherContainer>
inline Quaternion < Type > translotator::UnitQuaternion::operator+ (
    const OtherContainer & other
) const
```



operators 

**Template parameters:**


* `OtherContainer` other container matrix-base type 




        

<hr>



### function operator- 

_operator- operator_ 
```C++
template<typename OtherContainer>
inline Quaternion < Type > translotator::UnitQuaternion::operator- (
    const OtherContainer & other
) const
```





**Template parameters:**


* `OtherContainer` other container matrix-base type 




        

<hr>



### function operator/ 

_operator/ operator_ 
```C++
template<typename OtherContainer>
inline auto translotator::UnitQuaternion::operator/ (
    const OtherContainer & other
) const
```





**Template parameters:**


* `OtherContainer` other container matrix-base type

This operator is used to divide two quaternions. 

**Note:**

Unit / Unit = Unit, 




**Note:**

Unit / [**Quaternion**](classtranslotator_1_1Quaternion.md) = [**Quaternion**](classtranslotator_1_1Quaternion.md), 




**Note:**

Unit / Type = [**Quaternion**](classtranslotator_1_1Quaternion.md), 




**Note:**

else, follows the matrix multiplication rule 





        

<hr>



### function operator/= 

```C++
inline void translotator::UnitQuaternion::operator/= (
    const UnitQuaternion < Type > & other
) 
```




<hr>



### function pow 

_canonicalize this unit quaternion_ 
```C++
inline UnitQuaternion < Type > translotator::UnitQuaternion::pow (
    const Type & t
) const
```



return t-th power of this unit quaternion. Using Lie operation Exp, Log 


        

<hr>



### function quatNumDiv [1/2]

```C++
inline UnitQuaternion < Type > translotator::UnitQuaternion::quatNumDiv (
    const UnitQuaternion < Type > & other
) const
```




<hr>



### function quatNumDiv [2/2]

```C++
inline Quaternion < Type > translotator::UnitQuaternion::quatNumDiv (
    const Quaternion < Type > & other
) const
```




<hr>



### function quatNumDivEq [1/2]

```C++
inline void translotator::UnitQuaternion::quatNumDivEq (
    const UnitQuaternion < Type > & other
) 
```




<hr>



### function quatNumMul [1/3]

```C++
inline UnitQuaternion < Type > translotator::UnitQuaternion::quatNumMul (
    const UnitQuaternion < Type > & other
) const
```




<hr>



### function quatNumMul [2/3]

```C++
inline Quaternion < Type > translotator::UnitQuaternion::quatNumMul (
    const Quaternion < Type > & other
) const
```




<hr>



### function quatNumMulEq [1/2]

```C++
inline void translotator::UnitQuaternion::quatNumMulEq (
    const UnitQuaternion < Type > & other
) 
```




<hr>



### function rotateVector2D 

```C++
inline Vector < 2, Type > translotator::UnitQuaternion::rotateVector2D (
    const Vector < 2, Type > & v
) const
```




<hr>



### function rotateVector3D 

_inverse this unit quaternion_ 
```C++
inline Vector < 3, Type > translotator::UnitQuaternion::rotateVector3D (
    const Vector < 3, Type > & v
) const
```



rotate 3D vector 


        

<hr>



### function toAxisAngle 

```C++
inline AxisAngle < Type > translotator::UnitQuaternion::toAxisAngle () const
```




<hr>



### function toEulerAngle2D 

_convert to euler angle_ 
```C++
template<EULER_ORDER AxisOrder>
inline EulerAngle < Type, AxisOrder > translotator::UnitQuaternion::toEulerAngle2D () const
```





**Template parameters:**


* `AxisOrder` euler angle order 



**Note:**

Using only z axis rotation 





        

<hr>



### function toEulerAngle3D 

_convert to euler angle_ 
```C++
template<EULER_ORDER NewOrder>
inline EulerAngle < Type, NewOrder > translotator::UnitQuaternion::toEulerAngle3D () const
```





**Template parameters:**


* `NewOrder` euler angle order 




        

<hr>



### function toRotMatrix2D 

_convert to SO(2) group, Using only z axis rotation_ 
```C++
inline SOGroup < 2, Type > translotator::UnitQuaternion::toRotMatrix2D () const
```



casting 


        

<hr>



### function toRotMatrix3D 

```C++
inline SOGroup < 3, Type > translotator::UnitQuaternion::toRotMatrix3D () const
```




<hr>
## Public Static Functions Documentation




### function axisRotation 

_axis rotation unit quaternion_ 
```C++
template<AXIS Axis>
static inline UnitQuaternion < Type > translotator::UnitQuaternion::axisRotation (
    const Type & angle
) 
```





**Template parameters:**


* `Axis` axis to rotate 




        

<hr>



### function identity 

_identity unit quaternion_ 
```C++
static inline UnitQuaternion < Type > translotator::UnitQuaternion::identity () 
```



static functions 


        

<hr>## Friends Documentation





### friend operator\* 

```C++
inline Quaternion < Type > translotator::UnitQuaternion::operator* (
    const Quaternion < Type > & lhs,
    const UnitQuaternion < Type > & rhs
) 
```




<hr>



### friend operator\* 

```C++
inline Quaternion < Type > translotator::UnitQuaternion::operator* (
    const Type & lhs,
    const UnitQuaternion < Type > & rhs
) 
```




<hr>



### friend operator\*= 

```C++
inline void translotator::UnitQuaternion::operator*= (
    Quaternion < Type > & lhs,
    const UnitQuaternion < Type > & rhs
) 
```




<hr>



### friend operator/ 

```C++
inline Quaternion < Type > translotator::UnitQuaternion::operator/ (
    const Quaternion < Type > & lhs,
    const UnitQuaternion < Type > & rhs
) 
```




<hr>



### friend operator/= 

```C++
inline void translotator::UnitQuaternion::operator/= (
    Quaternion < Type > & lhs,
    const UnitQuaternion < Type > & rhs
) 
```




<hr>



### friend quatNumDivEq [2/2]

_alias for operator/= for readability_ 
```C++
inline void translotator::UnitQuaternion::quatNumDivEq (
    Quaternion < Type > & lhs,
    const UnitQuaternion < Type > & rhs
) 
```



alias for operator/= for readability 


        

<hr>



### friend quatNumMul [3/3]

_alias for operator\* for readability_ 
```C++
inline Quaternion < Type > translotator::UnitQuaternion::quatNumMul (
    const Quaternion < Type > & lhs,
    const UnitQuaternion < Type > & rhs
) 
```



alias for operator\* for readability 


        

<hr>



### friend quatNumMulEq [2/2]

_alias for operator\*= for readability_ 
```C++
inline void translotator::UnitQuaternion::quatNumMulEq (
    Quaternion < Type > & lhs,
    const UnitQuaternion < Type > & rhs
) 
```



alias for operator\*= for readability 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/UnitQuaternion.hpp`

