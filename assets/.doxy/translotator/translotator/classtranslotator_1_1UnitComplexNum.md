

# Class translotator::UnitComplexNum

**template &lt;typename Type&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)








Inherits the following classes: [translotator::ComplexNum](classtranslotator_1_1ComplexNum.md)


















## Public Types inherited from translotator::MatrixBase

See [translotator::MatrixBase](classtranslotator_1_1MatrixBase.md)

| Type | Name |
| ---: | :--- |
| typedef Type | [**DATATYPE**](classtranslotator_1_1MatrixBase.md#typedef-datatype)  <br> |














## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr static ObjectType | [**objType**](#variable-objtype)   = = ObjectType::UNIT\_COMPLEX\_NUM<br> |


## Public Static Attributes inherited from translotator::ComplexNum

See [translotator::ComplexNum](classtranslotator_1_1ComplexNum.md)

| Type | Name |
| ---: | :--- |
|  constexpr static ObjectType | [**OBJECT\_TYPE**](classtranslotator_1_1ComplexNum.md#variable-object_type)   = = ObjectType::COMPLEX\_NUM<br> |


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
|   | [**UnitComplexNum**](#function-unitcomplexnum-23) () <br> |
|   | [**UnitComplexNum**](#function-unitcomplexnum-33) (const Type & angle) <br> |
|  [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; | [**complexNumDiv**](#function-complexnumdiv-12) (const [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; & other) const<br> |
|  [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; | [**complexNumDiv**](#function-complexnumdiv-22) (const [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; & other) const<br> |
|  void | [**complexNumDivEq**](#function-complexnumdiveq-12) (const [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; & other) <br>_alias for operator/ for readability_  |
|  [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; | [**complexNumMul**](#function-complexnummul-13) (const [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; & other) const<br> |
|  [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; | [**complexNumMul**](#function-complexnummul-23) (const [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; & other) const<br> |
|  void | [**complexNumMulEq**](#function-complexnummuleq-12) (const [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; & other) <br> |
|  [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; | [**conjugated**](#function-conjugated) () const<br>_return conjugated unit complex number_  |
|  void | [**inverse**](#function-inverse) () <br> |
|  [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; | [**inversed**](#function-inversed) () const<br>_return inversed unit complex number. It is same as conjugated._  |
|  [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; | [**normalized**](#function-normalized) () const<br>_return normalized unit complex number_  |
|  auto | [**operator\***](#function-operator) (const OtherContainer & other) const<br>_operator\* operator_  |
|  void | [**operator\*=**](#function-operator_1) (const [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; & other) <br>_Unit \* Unit = Unit._  |
|  [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; | [**operator+**](#function-operator_2) (const OtherContainer & other) const<br>_operator+ operator_  |
|  auto | [**operator-**](#function-operator_3) (const OtherContainer & other) const<br>_operator- operator_  |
|  auto | [**operator/**](#function-operator_4) (const OtherContainer & other) const<br>_operator/ operator_  |
|  void | [**operator/=**](#function-operator_5) (const [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; & other) <br>_Unit / Unit = Unit._  |
|  [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; | [**pow**](#function-pow) (const Type t) const<br>_return this unit complex number to the power of t. Using Lie algebra._  |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 2, Type &gt; | [**rotateVector2D**](#function-rotatevector2d) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; 2, Type &gt; & v) const<br>_inverse this unit complex number_  |
|  [**AxisAngle**](classtranslotator_1_1AxisAngle.md)&lt; Type &gt; | [**toAxisAngle**](#function-toaxisangle) () const<br>_return axis angle representation_  |
|  [**EulerAngle**](classtranslotator_1_1EulerAngle.md)&lt; Type, AxisOrder &gt; | [**toEulerAngle2D**](#function-toeulerangle2d) () const<br>_return euler angle representation_  |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; 2, Type &gt; | [**toRotMatrix2D**](#function-torotmatrix2d) () const<br>_return identity unit complex number_  |


## Public Functions inherited from translotator::ComplexNum

See [translotator::ComplexNum](classtranslotator_1_1ComplexNum.md)

| Type | Name |
| ---: | :--- |
|   | [**ComplexNum**](classtranslotator_1_1ComplexNum.md#function-complexnum-12) () <br> |
|   | [**ComplexNum**](classtranslotator_1_1ComplexNum.md#function-complexnum-22) (Type real, Type imag) <br> |
|  Type | [**Im**](classtranslotator_1_1ComplexNum.md#function-im-12) () const<br> |
|  Type & | [**Im**](classtranslotator_1_1ComplexNum.md#function-im-22) () <br> |
|  Type | [**Re**](classtranslotator_1_1ComplexNum.md#function-re-12) () const<br> |
|  Type & | [**Re**](classtranslotator_1_1ComplexNum.md#function-re-22) () <br> |
|  [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; | [**complexNumDiv**](classtranslotator_1_1ComplexNum.md#function-complexnumdiv) (const [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; & c) const<br>_alias for operator\*= for readability_  |
|  void | [**complexNumDivEq**](classtranslotator_1_1ComplexNum.md#function-complexnumdiveq) (const [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; & c) <br>_alias for operator/ for readability_  |
|  [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; | [**complexNumMul**](classtranslotator_1_1ComplexNum.md#function-complexnummul) (const [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; & c) const<br>_divide and assign two complex numbers_  |
|  void | [**complexNumMulEq**](classtranslotator_1_1ComplexNum.md#function-complexnummuleq) (const [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; & c) <br>_alias for operator\* for readability_  |
|  void | [**conjugate**](classtranslotator_1_1ComplexNum.md#function-conjugate) () <br>_return the conjugated complex number_  |
|  [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; | [**conjugated**](classtranslotator_1_1ComplexNum.md#function-conjugated) () const<br>_normalize the complex number_  |
|  void | [**inverse**](classtranslotator_1_1ComplexNum.md#function-inverse) () <br>_return the inversed complex number_  |
|  [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; | [**inversed**](classtranslotator_1_1ComplexNum.md#function-inversed) () const<br>_conjugate the complex number_  |
|  Type | [**norm**](classtranslotator_1_1ComplexNum.md#function-norm) () const<br>_return the squared norm of the complex number_  |
|  Type | [**normSquared**](classtranslotator_1_1ComplexNum.md#function-normsquared) () const<br> |
|  void | [**normalize**](classtranslotator_1_1ComplexNum.md#function-normalize) () <br>_return the normalized complex number_  |
|  [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; | [**normalized**](classtranslotator_1_1ComplexNum.md#function-normalized) () const<br>_return the norm of the complex number_  |
|  [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; | [**operator\***](classtranslotator_1_1ComplexNum.md#function-operator) (const [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; & c) const<br>_multiply two complex numbers_  |
|  void | [**operator\*=**](classtranslotator_1_1ComplexNum.md#function-operator_1) (const [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; & c) <br> |
|  [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; | [**operator/**](classtranslotator_1_1ComplexNum.md#function-operator_2) (const [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; & c) const<br>_divide two complex numbers_  |
|  void | [**operator/=**](classtranslotator_1_1ComplexNum.md#function-operator_3) (const [**ComplexNum**](classtranslotator_1_1ComplexNum.md)&lt; Type &gt; & c) <br>_multiply and assign two complex numbers_  |
|  Type | [**operator[]**](classtranslotator_1_1ComplexNum.md#function-operator_4) (size\_t i) const<br> |
|  Type & | [**operator[]**](classtranslotator_1_1ComplexNum.md#function-operator_5) (size\_t i) <br> |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; 2, Type &gt; | [**toMulMatrix**](classtranslotator_1_1ComplexNum.md#function-tomulmatrix) () const<br>_inverse the complex number_  |


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
|  [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; | [**identity**](#function-identity) () <br> |




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
























































## Public Static Attributes Documentation




### variable objType 

```C++
constexpr static ObjectType translotator::UnitComplexNum< Type >::objType;
```




<hr>
## Public Functions Documentation




### function UnitComplexNum [2/3]


```C++
inline translotator::UnitComplexNum::UnitComplexNum () 
```



constructors 


        

<hr>



### function UnitComplexNum [3/3]

```C++
inline explicit translotator::UnitComplexNum::UnitComplexNum (
    const Type & angle
) 
```




<hr>



### function complexNumDiv [1/2]

```C++
inline UnitComplexNum < Type > translotator::UnitComplexNum::complexNumDiv (
    const UnitComplexNum < Type > & other
) const
```




<hr>



### function complexNumDiv [2/2]

```C++
inline ComplexNum < Type > translotator::UnitComplexNum::complexNumDiv (
    const ComplexNum < Type > & other
) const
```




<hr>



### function complexNumDivEq [1/2]

```C++
inline void translotator::UnitComplexNum::complexNumDivEq (
    const UnitComplexNum < Type > & other
) 
```




<hr>



### function complexNumMul [1/3]

```C++
inline UnitComplexNum < Type > translotator::UnitComplexNum::complexNumMul (
    const UnitComplexNum < Type > & other
) const
```




<hr>



### function complexNumMul [2/3]

```C++
inline ComplexNum < Type > translotator::UnitComplexNum::complexNumMul (
    const ComplexNum < Type > & other
) const
```




<hr>



### function complexNumMulEq [1/2]

```C++
inline void translotator::UnitComplexNum::complexNumMulEq (
    const UnitComplexNum < Type > & other
) 
```




<hr>



### function conjugated 

```C++
inline UnitComplexNum < Type > translotator::UnitComplexNum::conjugated () const
```




<hr>



### function inverse 

```C++
inline void translotator::UnitComplexNum::inverse () 
```




<hr>



### function inversed 

```C++
inline UnitComplexNum < Type > translotator::UnitComplexNum::inversed () const
```




<hr>



### function normalized 

_return normalized unit complex number_ 
```C++
inline UnitComplexNum < Type > translotator::UnitComplexNum::normalized () const
```



utils 


        

<hr>



### function operator\* 

_operator\* operator_ 
```C++
template<typename OtherContainer>
inline auto translotator::UnitComplexNum::operator* (
    const OtherContainer & other
) const
```





**Template parameters:**


* `OtherContainer` other container matrix-base type 



**Note:**

Unit \* Unit = Unit, 




**Note:**

Unit \* Complex = Complex, 




**Note:**

Unit \* Type = Complex, 




**Note:**

else, follows the matrix multiplication rule 





        

<hr>



### function operator\*= 

```C++
inline void translotator::UnitComplexNum::operator*= (
    const UnitComplexNum < Type > & other
) 
```




<hr>



### function operator+ 

_operator+ operator_ 
```C++
template<typename OtherContainer>
inline ComplexNum < Type > translotator::UnitComplexNum::operator+ (
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
inline auto translotator::UnitComplexNum::operator- (
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
inline auto translotator::UnitComplexNum::operator/ (
    const OtherContainer & other
) const
```





**Template parameters:**


* `OtherContainer` other container matrix-base type 



**Note:**

Unit / Unit = Unit, 




**Note:**

Unit / Complex = Complex, 




**Note:**

Unit / Type = Complex, 




**Note:**

else, follows the matrix multiplication rule 





        

<hr>



### function operator/= 

```C++
inline void translotator::UnitComplexNum::operator/= (
    const UnitComplexNum < Type > & other
) 
```




<hr>



### function pow 

```C++
inline UnitComplexNum < Type > translotator::UnitComplexNum::pow (
    const Type t
) const
```




<hr>



### function rotateVector2D 

_inverse this unit complex number_ 
```C++
inline Vector < 2, Type > translotator::UnitComplexNum::rotateVector2D (
    const Vector < 2, Type > & v
) const
```



rotate 2D vector 


        

<hr>



### function toAxisAngle 

```C++
inline AxisAngle < Type > translotator::UnitComplexNum::toAxisAngle () const
```




<hr>



### function toEulerAngle2D 

```C++
template<EULER_ORDER AxisOrder>
inline EulerAngle < Type, AxisOrder > translotator::UnitComplexNum::toEulerAngle2D () const
```




<hr>



### function toRotMatrix2D 

_return identity unit complex number_ 
```C++
inline SOGroup < 2, Type > translotator::UnitComplexNum::toRotMatrix2D () const
```



casting return 2D rotation matrix 


        

<hr>
## Public Static Functions Documentation




### function identity 


```C++
static inline UnitComplexNum < Type > translotator::UnitComplexNum::identity () 
```



static functions 


        

<hr>## Friends Documentation





### friend complexNumDivEq [2/2]

```C++
inline void translotator::UnitComplexNum::complexNumDivEq (
    ComplexNum < Type > & lhs,
    const UnitComplexNum < Type > & rhs
) 
```




<hr>



### friend complexNumMul [3/3]

_alias for operator\* for readability_ 
```C++
inline ComplexNum < Type > translotator::UnitComplexNum::complexNumMul (
    const ComplexNum < Type > & lhs,
    const UnitComplexNum < Type > & rhs
) 
```



alias for operator\* for readability 


        

<hr>



### friend complexNumMulEq [2/2]

```C++
inline void translotator::UnitComplexNum::complexNumMulEq (
    ComplexNum < Type > & lhs,
    const UnitComplexNum < Type > & rhs
) 
```




<hr>



### friend operator\* 

```C++
inline ComplexNum < Type > translotator::UnitComplexNum::operator* (
    const ComplexNum < Type > & lhs,
    const UnitComplexNum < Type > & rhs
) 
```




<hr>



### friend operator\* 

```C++
inline ComplexNum < Type > translotator::UnitComplexNum::operator* (
    const Type & lhs,
    const UnitComplexNum < Type > & rhs
) 
```




<hr>



### friend operator\*= 

```C++
inline void translotator::UnitComplexNum::operator*= (
    ComplexNum < Type > & lhs,
    const UnitComplexNum < Type > & rhs
) 
```




<hr>



### friend operator/ 

```C++
inline ComplexNum < Type > translotator::UnitComplexNum::operator/ (
    const ComplexNum < Type > & lhs,
    const UnitComplexNum < Type > & rhs
) 
```




<hr>



### friend operator/= 

```C++
inline void translotator::UnitComplexNum::operator/= (
    ComplexNum < Type > & lhs,
    const UnitComplexNum < Type > & rhs
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/UnitComplexNum.hpp`

