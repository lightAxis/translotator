

# Class translotator::UnitDualQuaternion

**template &lt;typename Type&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)



_Represents a unit dual quaternion._ [More...](#detailed-description)

* `#include <UnitDualQuaternion.hpp>`



Inherits the following classes: [translotator::DualQuaternion](classtranslotator_1_1DualQuaternion.md)


















## Public Types inherited from translotator::MatrixBase

See [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)

| Type | Name |
| ---: | :--- |
| typedef Type | [**DATATYPE**](classtranslotator_1_1MatrixBase.md#typedef-datatype)  <br> |














## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr static ObjectType | [**OBJECT\_TYPE**](#variable-object_type)   = = ObjectType::UNIT\_DUAL\_QUATERNION<br> |


## Public Static Attributes inherited from translotator::DualQuaternion

See [translotator::DualQuaternion](classtranslotator_1_1DualQuaternion.md)

| Type | Name |
| ---: | :--- |
|  constexpr static ObjectType | [**OBJECT\_TYPE**](classtranslotator_1_1DualQuaternion.md#variable-object_type)   = = ObjectType::DUAL\_QUATERNION<br> |


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
|  const [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; & | [**Re**](#function-re-12) () const<br>_return real part of unit dual quaternion,_ [_**UnitQuaternion**_](classtranslotator_1_1UnitQuaternion.md) __ |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; & | [**Re**](#function-re-22) () <br> |
|   | [**UnitDualQuaternion**](#function-unitdualquaternion-24) () <br> |
|   | [**UnitDualQuaternion**](#function-unitdualquaternion-34) (const [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; & re, const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & du) <br> |
|   | [**UnitDualQuaternion**](#function-unitdualquaternion-44) (const [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; & rot, const [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & t) <br> |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 2, Type &gt; | [**actOnVector2D**](#function-actonvector2d) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; 2, Type &gt; & v) const<br>_inverse this unit dual quaternion_  |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; | [**actOnVector3D**](#function-actonvector3d) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & v) const<br>_act on 3D vector_  |
|  void | [**conjugate**](#function-conjugate) () <br> |
|  [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; | [**conjugated**](#function-conjugated) () const<br>_normalize unit dual quaternion_  |
|  [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; | [**dualQuatDiv**](#function-dualquatdiv-12) (const [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; & other) const<br> |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**dualQuatDiv**](#function-dualquatdiv-22) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & other) const<br> |
|  void | [**dualQuatDivEq**](#function-dualquatdiveq-12) (const [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; & other) <br>_alias for operator/ for readability_  |
|  [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; | [**dualQuatMul**](#function-dualquatmul-13) (const [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; & other) const<br> |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**dualQuatMul**](#function-dualquatmul-23) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & other) const<br> |
|  void | [**dualQuatMulEq**](#function-dualquatmuleq-12) (const [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; & other) <br> |
|  void | [**inverse**](#function-inverse) () <br> |
|  [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; | [**inversed**](#function-inversed) () const<br>_conjugate unit dual quaternion_  |
|  void | [**normalize**](#function-normalize) () <br> |
|  [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; | [**normalized**](#function-normalized) () const<br>_return normalized unit dual quaternion_  |
|  auto | [**operator\***](#function-operator) (const OtherContainer & other) const<br>_operator\* operator_  |
|  void | [**operator\*=**](#function-operator_1) (const [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; & other) <br>_Unit \* Unit = Unit._  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**operator+**](#function-operator_2) (const OtherContainer & other) const<br>_operator+ operator_  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**operator-**](#function-operator_3) (const OtherContainer & other) const<br>_operator- operator_  |
|  auto | [**operator/**](#function-operator_4) (const OtherContainer & other) const<br>_operator/ operator_  |
|  void | [**operator/=**](#function-operator_5) (const [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; & other) <br>_Unit / Unit = Unit._  |
|  [**SEGroup**](classtranslotator_1_1SEGroup.md)&lt; 2, Type &gt; | [**toSE2Group**](#function-tose2group) () const<br>_convert to SE(2) group, Using only z axis rotation_  |
|  [**SEGroup**](classtranslotator_1_1SEGroup.md)&lt; 3, Type &gt; | [**toSE3Group**](#function-tose3group) () const<br>_convert to SE(3) group_  |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 2, Type &gt; | [**toTranslationVec2D**](#function-totranslationvec2d) () const<br>_return translation vector in 2D_  |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; | [**toTranslationVec3D**](#function-totranslationvec3d) () const<br>_return translation vector in 3D_  |


## Public Functions inherited from translotator::DualQuaternion

See [translotator::DualQuaternion](classtranslotator_1_1DualQuaternion.md)

| Type | Name |
| ---: | :--- |
|  const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & | [**Du**](classtranslotator_1_1DualQuaternion.md#function-du-12) () const<br> |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & | [**Du**](classtranslotator_1_1DualQuaternion.md#function-du-22) () <br> |
|   | [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md#function-dualquaternion-14) () = default<br> |
|   | [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md#function-dualquaternion-24) (const Type & rw, const Type & rx, const Type & ry, const Type & rz, const Type & dw, const Type & dx, const Type & dy, const Type & dz) <br> |
|   | [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md#function-dualquaternion-34) (const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & r, const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & d) <br> |
|   | [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md#function-dualquaternion-44) (const [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; & dn) <br> |
|  const [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & | [**Re**](classtranslotator_1_1DualQuaternion.md#function-re-12) () const<br> |
|  [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; & | [**Re**](classtranslotator_1_1DualQuaternion.md#function-re-22) () <br> |
|  void | [**conjugateDual**](classtranslotator_1_1DualQuaternion.md#function-conjugatedual) () <br> |
|  void | [**conjugateFull**](classtranslotator_1_1DualQuaternion.md#function-conjugatefull) () <br> |
|  void | [**conjugatePrimary**](classtranslotator_1_1DualQuaternion.md#function-conjugateprimary) () <br> |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**conjugatedDual**](classtranslotator_1_1DualQuaternion.md#function-conjugateddual) () const<br>_qr + qd e =&gt; qr\* + qd\* e_  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**conjugatedFull**](classtranslotator_1_1DualQuaternion.md#function-conjugatedfull) () const<br>_qr + qd e =&gt; qr - qd e_  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**conjugatedPrimary**](classtranslotator_1_1DualQuaternion.md#function-conjugatedprimary) () const<br>_dual quaternion division_  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**dualQuatDiv**](classtranslotator_1_1DualQuaternion.md#function-dualquatdiv) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & dq) const<br>_dual quaternion multiplication_  |
|  void | [**dualQuatDivEq**](classtranslotator_1_1DualQuaternion.md#function-dualquatdiveq) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & dq) <br>_dual quaternion division_  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**dualQuatMul**](classtranslotator_1_1DualQuaternion.md#function-dualquatmul) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & dq) const<br>_dual quaternion division_  |
|  void | [**dualQuatMulEq**](classtranslotator_1_1DualQuaternion.md#function-dualquatmuleq) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & dq) <br>_dual quaternion multiplication_  |
|  const Type & | [**dw**](classtranslotator_1_1DualQuaternion.md#function-dw-12) () const<br> |
|  Type & | [**dw**](classtranslotator_1_1DualQuaternion.md#function-dw-22) () <br> |
|  const Type & | [**dx**](classtranslotator_1_1DualQuaternion.md#function-dx-12) () const<br> |
|  Type & | [**dx**](classtranslotator_1_1DualQuaternion.md#function-dx-22) () <br> |
|  const Type & | [**dy**](classtranslotator_1_1DualQuaternion.md#function-dy-12) () const<br> |
|  Type & | [**dy**](classtranslotator_1_1DualQuaternion.md#function-dy-22) () <br> |
|  const Type & | [**dz**](classtranslotator_1_1DualQuaternion.md#function-dz-12) () const<br> |
|  Type & | [**dz**](classtranslotator_1_1DualQuaternion.md#function-dz-22) () <br> |
|  void | [**inverse**](classtranslotator_1_1DualQuaternion.md#function-inverse) () <br> |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**inversed**](classtranslotator_1_1DualQuaternion.md#function-inversed) () const<br>_dual quaternion inverse_  |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; | [**normDualNum**](classtranslotator_1_1DualQuaternion.md#function-normdualnum) () const<br>_qr + qd e =&gt; qr\* - qd\* e_  |
|  [**DualNumber**](classtranslotator_1_1DualNumber.md)&lt; Type &gt; | [**normDualNumSquared**](classtranslotator_1_1DualQuaternion.md#function-normdualnumsquared) () const<br>_original dual quaternion norm squared with primary conjugate_  |
|  Type | [**normScalar**](classtranslotator_1_1DualQuaternion.md#function-normscalar) () const<br> |
|  Type | [**normScalarSquared**](classtranslotator_1_1DualQuaternion.md#function-normscalarsquared) () const<br>_dual quaternion norm squared, dual number norm squared again_  |
|  void | [**normalize**](classtranslotator_1_1DualQuaternion.md#function-normalize) () const<br> |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**normalized**](classtranslotator_1_1DualQuaternion.md#function-normalized) () const<br>_dual quaternion inverse in place_  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**operator\***](classtranslotator_1_1DualQuaternion.md#function-operator) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & other) const<br>_dual quaternion multiplication_  |
|  void | [**operator\*=**](classtranslotator_1_1DualQuaternion.md#function-operator_1) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & q) <br>_dual quaternion division_  |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**operator/**](classtranslotator_1_1DualQuaternion.md#function-operator_2) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & other) const<br> |
|  void | [**operator/=**](classtranslotator_1_1DualQuaternion.md#function-operator_3) (const [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; & q) <br>_dual quaternion multiplication_  |
|  const Type & | [**operator[]**](classtranslotator_1_1DualQuaternion.md#function-operator_4) (const size\_t & idx) const<br> |
|  Type & | [**operator[]**](classtranslotator_1_1DualQuaternion.md#function-operator_5) (const size\_t & idx) <br> |
|  const Type & | [**rw**](classtranslotator_1_1DualQuaternion.md#function-rw-12) () const<br> |
|  Type & | [**rw**](classtranslotator_1_1DualQuaternion.md#function-rw-22) () <br> |
|  const Type & | [**rx**](classtranslotator_1_1DualQuaternion.md#function-rx-12) () const<br> |
|  Type & | [**rx**](classtranslotator_1_1DualQuaternion.md#function-rx-22) () <br> |
|  const Type & | [**ry**](classtranslotator_1_1DualQuaternion.md#function-ry-12) () const<br> |
|  Type & | [**ry**](classtranslotator_1_1DualQuaternion.md#function-ry-22) () <br> |
|  const Type & | [**rz**](classtranslotator_1_1DualQuaternion.md#function-rz-12) () const<br> |
|  Type & | [**rz**](classtranslotator_1_1DualQuaternion.md#function-rz-22) () <br> |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; 8, Type &gt; | [**toMulMatrix**](classtranslotator_1_1DualQuaternion.md#function-tomulmatrix) () const<br>_dual quaternion to multiplication matrix_  |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; 8, Type &gt; | [**toRightMulMatrix**](classtranslotator_1_1DualQuaternion.md#function-torightmulmatrix) () const<br>_dual quaternion to multiplication matrix from right_  |
|   | [**~DualQuaternion**](classtranslotator_1_1DualQuaternion.md#function-dualquaternion) () = default<br> |


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
|  [**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md)&lt; Type &gt; | [**identity**](#function-identity) () <br>_identity unit dual quaternion_  |


## Public Static Functions inherited from translotator::DualQuaternion

See [translotator::DualQuaternion](classtranslotator_1_1DualQuaternion.md)

| Type | Name |
| ---: | :--- |
|  [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md)&lt; Type &gt; | [**zeros**](classtranslotator_1_1DualQuaternion.md#function-zeros) () <br>_dual quaternion normalization_  |


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

[**UnitDualQuaternion**](classtranslotator_1_1UnitDualQuaternion.md) is a class that represents a unit dual quaternion. It is a subclass of [**DualQuaternion**](classtranslotator_1_1DualQuaternion.md) and has a unit length. It is used to represent a rigid transformation in 3D space. 


    
## Public Static Attributes Documentation




### variable OBJECT\_TYPE 

```C++
constexpr static ObjectType translotator::UnitDualQuaternion< Type >::OBJECT_TYPE;
```




<hr>
## Public Functions Documentation




### function Re [1/2]

_return real part of unit dual quaternion,_ [_**UnitQuaternion**_](classtranslotator_1_1UnitQuaternion.md) __
```C++
inline const UnitQuaternion < Type > & translotator::UnitDualQuaternion::Re () const
```



accessors 


        

<hr>



### function Re [2/2]

```C++
inline UnitQuaternion < Type > & translotator::UnitDualQuaternion::Re () 
```




<hr>



### function UnitDualQuaternion [2/4]


```C++
inline translotator::UnitDualQuaternion::UnitDualQuaternion () 
```



constructors 


        

<hr>



### function UnitDualQuaternion [3/4]

```C++
inline translotator::UnitDualQuaternion::UnitDualQuaternion (
    const UnitQuaternion < Type > & re,
    const Quaternion < Type > & du
) 
```




<hr>



### function UnitDualQuaternion [4/4]

```C++
inline translotator::UnitDualQuaternion::UnitDualQuaternion (
    const UnitQuaternion < Type > & rot,
    const Vector < 3, Type > & t
) 
```




<hr>



### function actOnVector2D 

_inverse this unit dual quaternion_ 
```C++
inline Vector < 2, Type > translotator::UnitDualQuaternion::actOnVector2D (
    const Vector < 2, Type > & v
) const
```



act on 2D vector 


        

<hr>



### function actOnVector3D 

```C++
inline Vector < 3, Type > translotator::UnitDualQuaternion::actOnVector3D (
    const Vector < 3, Type > & v
) const
```




<hr>



### function conjugate 

```C++
inline void translotator::UnitDualQuaternion::conjugate () 
```




<hr>



### function conjugated 

_normalize unit dual quaternion_ 
```C++
inline UnitDualQuaternion < Type > translotator::UnitDualQuaternion::conjugated () const
```



return conjugated unit dual quaternion. Primary conjugated. 


        

<hr>



### function dualQuatDiv [1/2]

```C++
inline UnitDualQuaternion < Type > translotator::UnitDualQuaternion::dualQuatDiv (
    const UnitDualQuaternion < Type > & other
) const
```




<hr>



### function dualQuatDiv [2/2]

```C++
inline DualQuaternion < Type > translotator::UnitDualQuaternion::dualQuatDiv (
    const DualQuaternion < Type > & other
) const
```




<hr>



### function dualQuatDivEq [1/2]

```C++
inline void translotator::UnitDualQuaternion::dualQuatDivEq (
    const UnitDualQuaternion < Type > & other
) 
```




<hr>



### function dualQuatMul [1/3]

```C++
inline UnitDualQuaternion < Type > translotator::UnitDualQuaternion::dualQuatMul (
    const UnitDualQuaternion < Type > & other
) const
```




<hr>



### function dualQuatMul [2/3]

```C++
inline DualQuaternion < Type > translotator::UnitDualQuaternion::dualQuatMul (
    const DualQuaternion < Type > & other
) const
```




<hr>



### function dualQuatMulEq [1/2]

```C++
inline void translotator::UnitDualQuaternion::dualQuatMulEq (
    const UnitDualQuaternion < Type > & other
) 
```




<hr>



### function inverse 

```C++
inline void translotator::UnitDualQuaternion::inverse () 
```




<hr>



### function inversed 

_conjugate unit dual quaternion_ 
```C++
inline UnitDualQuaternion < Type > translotator::UnitDualQuaternion::inversed () const
```



return inversed unit dual quaternion. It is same as conjugated. 


        

<hr>



### function normalize 

```C++
inline void translotator::UnitDualQuaternion::normalize () 
```




<hr>



### function normalized 

_return normalized unit dual quaternion_ 
```C++
inline UnitDualQuaternion < Type > translotator::UnitDualQuaternion::normalized () const
```



utils 


        

<hr>



### function operator\* 

_operator\* operator_ 
```C++
template<typename OtherContainer>
inline auto translotator::UnitDualQuaternion::operator* (
    const OtherContainer & other
) const
```





**Template parameters:**


* `OtherContainer` other container matrix-base type 



**Note:**

Unit \* Unit = Unit, 




**Note:**

Unit \* Dual = Dual, 




**Note:**

Unit \* Type = Dual, 




**Note:**

else, follows the matrix multiplication rule 





        

<hr>



### function operator\*= 

```C++
inline void translotator::UnitDualQuaternion::operator*= (
    const UnitDualQuaternion < Type > & other
) 
```




<hr>



### function operator+ 

_operator+ operator_ 
```C++
template<typename OtherContainer>
inline DualQuaternion < Type > translotator::UnitDualQuaternion::operator+ (
    const OtherContainer & other
) const
```



operators 

**Template parameters:**


* `OtherContainer` other container matrix-base type

This operator is used to add two dual quaternions. 


        

<hr>



### function operator- 

_operator- operator_ 
```C++
template<typename OtherContainer>
inline DualQuaternion < Type > translotator::UnitDualQuaternion::operator- (
    const OtherContainer & other
) const
```





**Template parameters:**


* `OtherContainer` other container matrix-base type

This operator is used to subtract two dual quaternions. 


        

<hr>



### function operator/ 

_operator/ operator_ 
```C++
template<typename OtherContainer>
inline auto translotator::UnitDualQuaternion::operator/ (
    const OtherContainer & other
) const
```





**Template parameters:**


* `OtherContainer` other container matrix-base type 



**Note:**

Unit / Unit = Unit, 




**Note:**

Unit / Dual = Dual, 




**Note:**

Unit / Type = Dual, 




**Note:**

else, follows the matrix multiplication rule 





        

<hr>



### function operator/= 

```C++
inline void translotator::UnitDualQuaternion::operator/= (
    const UnitDualQuaternion < Type > & other
) 
```




<hr>



### function toSE2Group 

_convert to SE(2) group, Using only z axis rotation_ 
```C++
inline SEGroup < 2, Type > translotator::UnitDualQuaternion::toSE2Group () const
```



casting 


        

<hr>



### function toSE3Group 

```C++
inline SEGroup < 3, Type > translotator::UnitDualQuaternion::toSE3Group () const
```




<hr>



### function toTranslationVec2D 

```C++
inline Vector < 2, Type > translotator::UnitDualQuaternion::toTranslationVec2D () const
```




<hr>



### function toTranslationVec3D 

```C++
inline Vector < 3, Type > translotator::UnitDualQuaternion::toTranslationVec3D () const
```




<hr>
## Public Static Functions Documentation




### function identity 

_identity unit dual quaternion_ 
```C++
static inline UnitDualQuaternion < Type > translotator::UnitDualQuaternion::identity () 
```



static functions 


        

<hr>## Friends Documentation





### friend dualQuatDivEq [2/2]

```C++
inline void translotator::UnitDualQuaternion::dualQuatDivEq (
    DualQuaternion < Type > & lhs,
    const UnitDualQuaternion < Type > & rhs
) 
```




<hr>



### friend dualQuatMul [3/3]

_alias for operator\* for readability_ 
```C++
inline DualQuaternion < Type > translotator::UnitDualQuaternion::dualQuatMul (
    const DualQuaternion < Type > & lhs,
    const UnitDualQuaternion < Type > & rhs
) 
```



alias for operator\* for readability 


        

<hr>



### friend dualQuatMulEq [2/2]

```C++
inline void translotator::UnitDualQuaternion::dualQuatMulEq (
    DualQuaternion < Type > & lhs,
    const UnitDualQuaternion < Type > & rhs
) 
```




<hr>



### friend operator\* 

```C++
inline DualQuaternion < Type > translotator::UnitDualQuaternion::operator* (
    const DualQuaternion < Type > & lhs,
    const UnitDualQuaternion < Type > & rhs
) 
```




<hr>



### friend operator\* 

```C++
inline DualQuaternion < Type > translotator::UnitDualQuaternion::operator* (
    const Type & lhs,
    const UnitDualQuaternion < Type > & rhs
) 
```




<hr>



### friend operator\*= 

```C++
inline void translotator::UnitDualQuaternion::operator*= (
    DualQuaternion < Type > & lhs,
    const UnitDualQuaternion < Type > & rhs
) 
```




<hr>



### friend operator/ 

```C++
inline DualQuaternion < Type > translotator::UnitDualQuaternion::operator/ (
    const DualQuaternion < Type > & lhs,
    const UnitDualQuaternion < Type > & rhs
) 
```




<hr>



### friend operator/= 

```C++
inline void translotator::UnitDualQuaternion::operator/= (
    DualQuaternion < Type > & lhs,
    const UnitDualQuaternion < Type > & rhs
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/UnitDualQuaternion.hpp`

