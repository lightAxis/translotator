
# Class Hierarchy

This inheritance list is sorted roughly, but not completely, alphabetically:


* **class** [**translotator::AxisAngle**](classtranslotator_1_1AxisAngle.md) _Represents a rotation in 3D space by an angle around an axis._ 
* **class** [**translotator::MatrixBase**](classtranslotator_1_1MatrixBase.md) _Base class for all matrix objects._     
    * **class** [**translotator::Vector**](classtranslotator_1_1Vector.md) [_**Vector**_](classtranslotator_1_1Vector.md) _class._
* **class** [**translotator::EulerAngle**](classtranslotator_1_1EulerAngle.md) _Represents Euler angle 3D rotation._ 
* **class** [**translotator::SEGroup**](classtranslotator_1_1SEGroup.md) _Special Euclidean Group._ 
* **class** [**translotator::interpolators::Lerper**](classtranslotator_1_1interpolators_1_1Lerper.md) _Linear interpolation class._ 
* **class** [**translotator::interpolators::ScLerper**](classtranslotator_1_1interpolators_1_1ScLerper.md) _Screw linear interpolation class._ 
* **class** [**translotator::interpolators::SlerpLerper**](classtranslotator_1_1interpolators_1_1SlerpLerper.md) _Slerp for rotation component, lerp for translation component class._ 
* **class** [**translotator::interpolators::Slerper**](classtranslotator_1_1interpolators_1_1Slerper.md) _Slerp for rotation component interpolation class._ 
* **class** [**translotator::interpolators::SlerperFast**](classtranslotator_1_1interpolators_1_1SlerperFast.md) _Slerp for rotation component interpolation class. Faster than_ [_**Slerper**_](classtranslotator_1_1interpolators_1_1Slerper.md) _for S1, S3 group._
* **struct** [**translotator::MatrixBaseInternal::operator\_cast\_typemapper**](structtranslotator_1_1MatrixBaseInternal_1_1operator__cast__typemapper.md) 
* **struct** [**translotator::MatrixBaseInternal::operator\_cast\_typemapper&lt; Matrix&lt; N, M, Type &gt;, NewType &gt;**](structtranslotator_1_1MatrixBaseInternal_1_1operator__cast__typemapper_3_01Matrix_3_01N_00_01M_00_01Type_01_4_00_01NewType_01_4.md) 
* **struct** [**translotator::MatrixBaseInternal::operator\_cast\_typemapper&lt; Vector&lt; N, Type &gt;, NewType &gt;**](structtranslotator_1_1MatrixBaseInternal_1_1operator__cast__typemapper_3_01Vector_3_01N_00_01Type_01_4_00_01NewType_01_4.md) 
* **struct** [**translotator::MatrixBaseInternal::operator\_mul\_typemapper**](structtranslotator_1_1MatrixBaseInternal_1_1operator__mul__typemapper.md) 
* **struct** [**translotator::MatrixBaseInternal::operator\_mul\_typemapper&lt; Derived, OtherDerived, enable\_if\_t&lt; Derived::ROWS !=1 &&OtherDerived::COLS==1, void &gt; &gt;**](structtranslotator_1_1MatrixBaseInternal_1_1operator__mul__typemapper_3_01Derived_00_01OtherDeri1b96ed4aed79df1e494374b57efb0a1d.md) 
* **struct** [**translotator::MatrixBaseInternal::operator\_mul\_typemapper&lt; Derived, OtherDerived, enable\_if\_t&lt; Derived::ROWS !=OtherDerived::COLS &&OtherDerived::COLS !=1, void &gt; &gt;**](structtranslotator_1_1MatrixBaseInternal_1_1operator__mul__typemapper_3_01Derived_00_01OtherDeri2a96eb5bfa413dff0cddca3d951d6a71.md) 
* **struct** [**translotator::MatrixBaseInternal::operator\_mul\_typemapper&lt; Derived, OtherDerived, enable\_if\_t&lt; Derived::ROWS==1 &&OtherDerived::COLS==1, void &gt; &gt;**](structtranslotator_1_1MatrixBaseInternal_1_1operator__mul__typemapper_3_01Derived_00_01OtherDeri96d299f5dadca2759194ea845be7ed5c.md) 
* **struct** [**translotator::MatrixBaseInternal::operator\_mul\_typemapper&lt; Derived, OtherDerived, enable\_if\_t&lt; Derived::ROWS==OtherDerived::COLS &&OtherDerived::COLS !=1, void &gt; &gt;**](structtranslotator_1_1MatrixBaseInternal_1_1operator__mul__typemapper_3_01Derived_00_01OtherDeri416034dcdebb2206f870a9ec06949246.md) 
* **struct** [**translotator::all\_same**](structtranslotator_1_1all__same.md) 
* **struct** [**translotator::all\_same&lt; T &gt;**](structtranslotator_1_1all__same_3_01T_01_4.md) 
* **struct** [**translotator::all\_same&lt; T, First, Rest... &gt;**](structtranslotator_1_1all__same_3_01T_00_01First_00_01Rest_8_8_8_01_4.md) 
* **struct** [**translotator::conditional\_if**](structtranslotator_1_1conditional__if.md) 
* **struct** [**translotator::conditional\_if&lt; false, T, F &gt;**](structtranslotator_1_1conditional__if_3_01false_00_01T_00_01F_01_4.md) 
* **struct** [**translotator::enable\_if**](structtranslotator_1_1enable__if.md) 
* **struct** [**translotator::enable\_if&lt; true, T &gt;**](structtranslotator_1_1enable__if_3_01true_00_01T_01_4.md) 
* **struct** [**translotator::initializer\_list**](structtranslotator_1_1initializer__list.md) [_**initializer\_list**_](structtranslotator_1_1initializer__list.md) _struct_
* **struct** [**translotator::integral\_constant**](structtranslotator_1_1integral__constant.md)     
    * **struct** [**translotator::is\_float**](structtranslotator_1_1is__float.md) 
    * **struct** [**translotator::is\_float&lt; double &gt;**](structtranslotator_1_1is__float_3_01double_01_4.md) 
    * **struct** [**translotator::is\_float&lt; float &gt;**](structtranslotator_1_1is__float_3_01float_01_4.md) 
    * **struct** [**translotator::is\_float&lt; long double &gt;**](structtranslotator_1_1is__float_3_01long_01double_01_4.md) 
    * **struct** [**translotator::is\_matrix\_base**](structtranslotator_1_1is__matrix__base.md) 
    * **struct** [**translotator::is\_matrix\_base&lt; T, typename enable\_if&lt; T::MATRIX\_BASE &gt;::type &gt;**](structtranslotator_1_1is__matrix__base_3_01T_00_01typename_01enable__if_3_01T_1_1MATRIX__BASE_01_4_1_1type_01_4.md) 
    * **struct** [**translotator::is\_same**](structtranslotator_1_1is__same.md) 
    * **struct** [**translotator::is\_same&lt; T, T &gt;**](structtranslotator_1_1is__same_3_01T_00_01T_01_4.md) 
* **struct** [**translotator::lie::LieOperator**](structtranslotator_1_1lie_1_1LieOperator.md) _Lie Operator for Lie Group and Lie Algebra._ 
* **struct** [**translotator::lie::LieOperator&lt; ObjectType::SE\_GROUP, Type &gt;**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1SE__GROUP_00_01Type_01_4.md) _Lie Operator for SE._ 
* **struct** [**translotator::lie::LieOperator&lt; ObjectType::SO\_GROUP, Type &gt;**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1SO__GROUP_00_01Type_01_4.md) _Special Orthogonal Group._ 
* **struct** [**translotator::lie::LieOperator&lt; ObjectType::UNIT\_COMPLEX\_NUM, Type &gt;**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1UNIT__COMPLEX__NUM_00_01Type_01_4.md) _Lie Operator for S1._ 
* **struct** [**translotator::lie::LieOperator&lt; ObjectType::UNIT\_QUATERNION, Type &gt;**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1UNIT__QUATERNION_00_01Type_01_4.md) _Lie Operator for S3._ 

