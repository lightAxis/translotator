

# Class translotator::EulerAngle

**template &lt;typename Type, EULER\_ORDER AxisOrder&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**EulerAngle**](classtranslotator_1_1EulerAngle.md)



_Represents Euler angle 3D rotation._ [More...](#detailed-description)

* `#include <EulerAngle.hpp>`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr static ObjectType | [**OBJECT\_TYPE**](#variable-object_type)   = = ObjectType::EULER\_ANGLE<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**EulerAngle**](#function-eulerangle-14) () <br> |
|   | [**EulerAngle**](#function-eulerangle-24) (const Type & angle) <br> |
|   | [**EulerAngle**](#function-eulerangle-34) (const Type & x, const Type & y, const Type & z) <br> |
|   | [**EulerAngle**](#function-eulerangle-44) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & angles) <br> |
|  [**EulerAngle**](classtranslotator_1_1EulerAngle.md)&lt; Type, NewAxisOrder &gt; | [**castAxisOrder**](#function-castaxisorder) () const<br>_convert to_ [_**EulerAngle**_](classtranslotator_1_1EulerAngle.md) _with new axis order_ |
|  [**EulerAngle**](classtranslotator_1_1EulerAngle.md)&lt; NewType, AxisOrder &gt; | [**castDataType**](#function-castdatatype) () const<br>_convert to_ [_**EulerAngle**_](classtranslotator_1_1EulerAngle.md) _with new axis order_ |
|  Type | [**getAngleInOrder**](#function-getangleinorder-12) () const<br>_get angle in axis order (AXIS1, AXIS2, AXIS3)_  |
|  Type & | [**getAngleInOrder**](#function-getangleinorder-22) () <br>_get angle in axis order (AXIS1, AXIS2, AXIS3)_  |
|  constexpr AXIS | [**getAxisInOrder**](#function-getaxisinorder) () const<br>_get axis enum in axis order (AXIS1, AXIS2, AXIS3)_  |
|  Type | [**operator[]**](#function-operator) (size\_t idx) const<br> |
|  Type & | [**operator[]**](#function-operator_1) (size\_t idx) <br> |
|  Type | [**pitch**](#function-pitch-12) () const<br> |
|  Type & | [**pitch**](#function-pitch-22) () <br> |
|  Type | [**roll**](#function-roll-12) () const<br> |
|  Type & | [**roll**](#function-roll-22) () <br> |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 2, Type &gt; | [**rotateVec2D**](#function-rotatevec2d) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; 2, Type &gt; & vec) const<br>_2D rotation. Using only z angle._  |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; | [**rotateVec3D**](#function-rotatevec3d) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & vec) const<br>_3D rotation_  |
|  [**AxisAngle**](classtranslotator_1_1AxisAngle.md)&lt; Type &gt; | [**toAxisAngle**](#function-toaxisangle) () const<br>_convert to axis angle_  |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; 2, Type &gt; | [**toSO2Group**](#function-toso2group) () const<br>_convert to SO2 group. Using only z angle._  |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; 3, Type &gt; | [**toSO3Group**](#function-toso3group) () const<br>_convert to SO3 group_  |
|  [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; | [**toUnitComplexNum**](#function-tounitcomplexnum) () const<br>_convert to unit complex number. Using only z angle._  |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; | [**toUnitQuaternion**](#function-tounitquaternion) () const<br>_convert to unit quaternion_  |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; | [**toVector**](#function-tovector) () const<br>_convert to vector (x, y, z)_  |
|  Type | [**x**](#function-x-12) () const<br> |
|  Type & | [**x**](#function-x-22) () <br> |
|  Type | [**y**](#function-y-12) () const<br> |
|  Type & | [**y**](#function-y-22) () <br> |
|  Type | [**yaw**](#function-yaw-12) () const<br> |
|  Type & | [**yaw**](#function-yaw-22) () <br> |
|  Type | [**z**](#function-z-12) () const<br> |
|  Type & | [**z**](#function-z-22) () <br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  [**EulerAngle**](classtranslotator_1_1EulerAngle.md)&lt; Type, AxisOrder &gt; | [**axisRotation**](#function-axisrotation) (const Type & angle) <br>_axis rotation with angle_  |


























# Detailed Description




**Template parameters:**


* `Type` data type 
* `AxisOrder` Euler angle order

Euler angle class with 3 angles. The order of angles is determined by AxisOrder. The default order is ZYX. Intrinsic, tait-brayan angles are used. ex, XYZ means that the rotation is first around X axis, then Y axis, and finally Z axis intrinsically. Euler angle is a representation of orientation in 3D space. It is a set of three angles that specify the orientation of a rigid body in 3D space. Angles are typically in the range of [-pi, pi]. The order of angles is important because the rotation matrix is not commutative. 


    
## Public Static Attributes Documentation




### variable OBJECT\_TYPE 

```C++
constexpr static ObjectType translotator::EulerAngle< Type, AxisOrder >::OBJECT_TYPE;
```




<hr>
## Public Functions Documentation




### function EulerAngle [1/4]


```C++
inline translotator::EulerAngle::EulerAngle () 
```



constructor 


        

<hr>



### function EulerAngle [2/4]

```C++
inline explicit translotator::EulerAngle::EulerAngle (
    const Type & angle
) 
```




<hr>



### function EulerAngle [3/4]

```C++
inline translotator::EulerAngle::EulerAngle (
    const Type & x,
    const Type & y,
    const Type & z
) 
```




<hr>



### function EulerAngle [4/4]

```C++
inline explicit translotator::EulerAngle::EulerAngle (
    const Vector < 3, Type > & angles
) 
```




<hr>



### function castAxisOrder 

_convert to_ [_**EulerAngle**_](classtranslotator_1_1EulerAngle.md) _with new axis order_
```C++
template<EULER_ORDER NewAxisOrder>
inline EulerAngle < Type, NewAxisOrder > translotator::EulerAngle::castAxisOrder () const
```





**Template parameters:**


* `NewAxisOrder` new axis order cast to new axis order 




        

<hr>



### function castDataType 

_convert to_ [_**EulerAngle**_](classtranslotator_1_1EulerAngle.md) _with new axis order_
```C++
template<typename NewType>
inline EulerAngle < NewType, AxisOrder > translotator::EulerAngle::castDataType () const
```





**Template parameters:**


* `NewAxisOrder` new axis order 




        

<hr>



### function getAngleInOrder [1/2]

_get angle in axis order (AXIS1, AXIS2, AXIS3)_ 
```C++
template<size_t N>
inline Type translotator::EulerAngle::getAngleInOrder () const
```





**Template parameters:**


* `N` index of angle 




        

<hr>



### function getAngleInOrder [2/2]

_get angle in axis order (AXIS1, AXIS2, AXIS3)_ 
```C++
template<size_t N>
inline Type & translotator::EulerAngle::getAngleInOrder () 
```





**Template parameters:**


* `N` index of angle 




        

<hr>



### function getAxisInOrder 

_get axis enum in axis order (AXIS1, AXIS2, AXIS3)_ 
```C++
template<size_t N>
inline constexpr AXIS translotator::EulerAngle::getAxisInOrder () const
```





**Template parameters:**


* `N` index of axis 




        

<hr>



### function operator[] 

```C++
inline Type translotator::EulerAngle::operator[] (
    size_t idx
) const
```




<hr>



### function operator[] 

```C++
inline Type & translotator::EulerAngle::operator[] (
    size_t idx
) 
```




<hr>



### function pitch [1/2]

```C++
inline Type translotator::EulerAngle::pitch () const
```




<hr>



### function pitch [2/2]

```C++
inline Type & translotator::EulerAngle::pitch () 
```




<hr>



### function roll [1/2]

```C++
inline Type translotator::EulerAngle::roll () const
```




<hr>



### function roll [2/2]

```C++
inline Type & translotator::EulerAngle::roll () 
```




<hr>



### function rotateVec2D 

_2D rotation. Using only z angle._ 
```C++
inline Vector < 2, Type > translotator::EulerAngle::rotateVec2D (
    const Vector < 2, Type > & vec
) const
```



utils 


        

<hr>



### function rotateVec3D 

```C++
inline Vector < 3, Type > translotator::EulerAngle::rotateVec3D (
    const Vector < 3, Type > & vec
) const
```




<hr>



### function toAxisAngle 

```C++
inline AxisAngle < Type > translotator::EulerAngle::toAxisAngle () const
```




<hr>



### function toSO2Group 

```C++
inline SOGroup < 2, Type > translotator::EulerAngle::toSO2Group () const
```




<hr>



### function toSO3Group 

```C++
inline SOGroup < 3, Type > translotator::EulerAngle::toSO3Group () const
```




<hr>



### function toUnitComplexNum 

```C++
inline UnitComplexNum < Type > translotator::EulerAngle::toUnitComplexNum () const
```




<hr>



### function toUnitQuaternion 

_convert to unit quaternion_ 
```C++
inline UnitQuaternion < Type > translotator::EulerAngle::toUnitQuaternion () const
```



casts 


        

<hr>



### function toVector 

```C++
inline Vector < 3, Type > translotator::EulerAngle::toVector () const
```




<hr>



### function x [1/2]


```C++
inline Type translotator::EulerAngle::x () const
```



accessor 


        

<hr>



### function x [2/2]

```C++
inline Type & translotator::EulerAngle::x () 
```




<hr>



### function y [1/2]

```C++
inline Type translotator::EulerAngle::y () const
```




<hr>



### function y [2/2]

```C++
inline Type & translotator::EulerAngle::y () 
```




<hr>



### function yaw [1/2]

```C++
inline Type translotator::EulerAngle::yaw () const
```




<hr>



### function yaw [2/2]

```C++
inline Type & translotator::EulerAngle::yaw () 
```




<hr>



### function z [1/2]

```C++
inline Type translotator::EulerAngle::z () const
```




<hr>



### function z [2/2]

```C++
inline Type & translotator::EulerAngle::z () 
```




<hr>
## Public Static Functions Documentation




### function axisRotation 

_axis rotation with angle_ 
```C++
template<AXIS Axis>
static inline EulerAngle < Type, AxisOrder > translotator::EulerAngle::axisRotation (
    const Type & angle
) 
```



static functions 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/EulerAngle.hpp`

