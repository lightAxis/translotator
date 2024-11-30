

# Class translotator::AxisAngle

**template &lt;typename Type&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**AxisAngle**](classtranslotator_1_1AxisAngle.md)



_Represents a rotation in 3D space by an angle around an axis._ [More...](#detailed-description)

* `#include <AxisAngle.hpp>`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr static ObjectType | [**OBJECT\_TYPE**](#variable-object_type)   = = ObjectType::AXIS\_ANGLE<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**AxisAngle**](#function-axisangle-14) (const Type & angle, const Type & x, const Type & y, const Type & z) <br> |
|   | [**AxisAngle**](#function-axisangle-24) (const Type & angle, const [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & axis) <br> |
|   | [**AxisAngle**](#function-axisangle-34) (const Type & angle) <br> |
|   | [**AxisAngle**](#function-axisangle-44) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & angleVector) <br> |
|  Type | [**angle**](#function-angle-12) () const<br> |
|  Type & | [**angle**](#function-angle-22) () <br> |
|  const [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & | [**axis**](#function-axis-12) () const<br> |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & | [**axis**](#function-axis-22) () <br> |
|  void | [**axisNormalize**](#function-axisnormalize) () <br> |
|  [**AxisAngle**](classtranslotator_1_1AxisAngle.md) | [**axisNormalized**](#function-axisnormalized) () const<br>_normalize the axis inside_  |
|  [**AxisAngle**](classtranslotator_1_1AxisAngle.md)&lt; Type &gt; | [**axisRotation**](#function-axisrotation) (const Type & angle) const<br>_return a new_ [_**AxisAngle**_](classtranslotator_1_1AxisAngle.md) _with the unit axis and a angle_ |
|  [**AxisAngle**](classtranslotator_1_1AxisAngle.md)&lt; NewType &gt; | [**castDataType**](#function-castdatatype) () const<br>_convert to a new_ [_**AxisAngle**_](classtranslotator_1_1AxisAngle.md) _with a different data type_ |
|  void | [**inverse**](#function-inverse) () <br>_return a new_ [_**AxisAngle**_](classtranslotator_1_1AxisAngle.md) _with normalized axis_ |
|  [**AxisAngle**](classtranslotator_1_1AxisAngle.md) | [**inversed**](#function-inversed) () const<br>_invert the angle_  |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 2, Type &gt; | [**rotateVector2D**](#function-rotatevector2d) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; 2, Type &gt; & v) const<br>_rotate a 2D vector. Using only the z-axis of the_ [_**AxisAngle**_](classtranslotator_1_1AxisAngle.md) __ |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; | [**rotateVector3D**](#function-rotatevector3d) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; & v) const<br>_return a new_ [_**AxisAngle**_](classtranslotator_1_1AxisAngle.md) _with inverted angle_ |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; | [**toAngleVector**](#function-toanglevector) () const<br>_convert to a Vector&lt;3, Type&gt; with the angle as the norm_  |
|  [**EulerAngle**](classtranslotator_1_1EulerAngle.md)&lt; Type, AxisOrder &gt; | [**toEulerAngle2D**](#function-toeulerangle2d) () const<br>_convert to EulerAngle2D. Using only the z-axis of the_ [_**AxisAngle**_](classtranslotator_1_1AxisAngle.md) __ |
|  [**EulerAngle**](classtranslotator_1_1EulerAngle.md)&lt; Type, AxisOrder &gt; | [**toEulerAngle3D**](#function-toeulerangle3d) () const<br>_convert to EulerAngle3D_  |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; 2, Type &gt; | [**toRotMatrix2D**](#function-torotmatrix2d) () const<br>_convert to SOGroup&lt;2, Type&gt;. Using only the z-axis of the_ [_**AxisAngle**_](classtranslotator_1_1AxisAngle.md) __ |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; 3, Type &gt; | [**toRotMatrix3D**](#function-torotmatrix3d) () const<br>_convert to SOGroup&lt;3, Type&gt;_  |
|  [**UnitComplexNum**](classtranslotator_1_1UnitComplexNum.md)&lt; Type &gt; | [**toUnitComplexNum**](#function-tounitcomplexnum) () const<br>_convert to_ [_**UnitComplexNum**_](classtranslotator_1_1UnitComplexNum.md) _. Using only z-axis of the_[_**AxisAngle**_](classtranslotator_1_1AxisAngle.md) __ |
|  [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; | [**toUnitQuaternion**](#function-tounitquaternion) () const<br>_convert to_ [_**UnitQuaternion**_](classtranslotator_1_1UnitQuaternion.md) __ |
|  Type | [**x**](#function-x-12) () const<br> |
|  Type & | [**x**](#function-x-22) () <br> |
|  Type | [**y**](#function-y-12) () const<br> |
|  Type & | [**y**](#function-y-22) () <br> |
|  Type | [**z**](#function-z-12) () const<br> |
|  Type & | [**z**](#function-z-22) () <br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  [**AxisAngle**](classtranslotator_1_1AxisAngle.md)&lt; Type &gt; | [**identity**](#function-identity) () <br>_Returns the identity of_ [_**AxisAngle**_](classtranslotator_1_1AxisAngle.md) _, which is a rotation of 0 degrees around the x-axis._ |


























# Detailed Description


[**AxisAngle**](classtranslotator_1_1AxisAngle.md) 

**Template parameters:**


* `Type` floating point type

The axis is a unit vector. The angle is in radians. The rotation is counter-clockwise when looking from the positive side of the axis. 


    
## Public Static Attributes Documentation




### variable OBJECT\_TYPE 

```C++
constexpr static ObjectType translotator::AxisAngle< Type >::OBJECT_TYPE;
```




<hr>
## Public Functions Documentation




### function AxisAngle [1/4]


```C++
inline translotator::AxisAngle::AxisAngle (
    const Type & angle,
    const Type & x,
    const Type & y,
    const Type & z
) 
```



Constructors 


        

<hr>



### function AxisAngle [2/4]

```C++
inline explicit translotator::AxisAngle::AxisAngle (
    const Type & angle,
    const Vector < 3, Type > & axis
) 
```




<hr>



### function AxisAngle [3/4]

```C++
inline explicit translotator::AxisAngle::AxisAngle (
    const Type & angle
) 
```




<hr>



### function AxisAngle [4/4]

```C++
inline explicit translotator::AxisAngle::AxisAngle (
    const Vector < 3, Type > & angleVector
) 
```




<hr>



### function angle [1/2]


```C++
inline Type translotator::AxisAngle::angle () const
```



accessors 


        

<hr>



### function angle [2/2]

```C++
inline Type & translotator::AxisAngle::angle () 
```




<hr>



### function axis [1/2]

```C++
inline const Vector < 3, Type > & translotator::AxisAngle::axis () const
```




<hr>



### function axis [2/2]

```C++
inline Vector < 3, Type > & translotator::AxisAngle::axis () 
```




<hr>



### function axisNormalize 


```C++
inline void translotator::AxisAngle::axisNormalize () 
```



Utils 


        

<hr>



### function axisNormalized 

```C++
inline AxisAngle translotator::AxisAngle::axisNormalized () const
```




<hr>



### function axisRotation 

```C++
template<AXIS Axis>
inline AxisAngle < Type > translotator::AxisAngle::axisRotation (
    const Type & angle
) const
```




<hr>



### function castDataType 

```C++
template<typename NewType>
inline AxisAngle < NewType > translotator::AxisAngle::castDataType () const
```




<hr>



### function inverse 

```C++
inline void translotator::AxisAngle::inverse () 
```




<hr>



### function inversed 

```C++
inline AxisAngle translotator::AxisAngle::inversed () const
```




<hr>



### function rotateVector2D 

```C++
inline Vector < 2, Type > translotator::AxisAngle::rotateVector2D (
    const Vector < 2, Type > & v
) const
```




<hr>



### function rotateVector3D 

_return a new_ [_**AxisAngle**_](classtranslotator_1_1AxisAngle.md) _with inverted angle_
```C++
inline Vector < 3, Type > translotator::AxisAngle::rotateVector3D (
    const Vector < 3, Type > & v
) const
```



rotate a 3D vector 


        

<hr>



### function toAngleVector 

```C++
inline Vector < 3, Type > translotator::AxisAngle::toAngleVector () const
```




<hr>



### function toEulerAngle2D 

```C++
template<EULER_ORDER AxisOrder>
inline EulerAngle < Type, AxisOrder > translotator::AxisAngle::toEulerAngle2D () const
```




<hr>



### function toEulerAngle3D 

```C++
template<EULER_ORDER AxisOrder>
inline EulerAngle < Type, AxisOrder > translotator::AxisAngle::toEulerAngle3D () const
```




<hr>



### function toRotMatrix2D 

```C++
inline SOGroup < 2, Type > translotator::AxisAngle::toRotMatrix2D () const
```




<hr>



### function toRotMatrix3D 

```C++
inline SOGroup < 3, Type > translotator::AxisAngle::toRotMatrix3D () const
```




<hr>



### function toUnitComplexNum 

```C++
inline UnitComplexNum < Type > translotator::AxisAngle::toUnitComplexNum () const
```




<hr>



### function toUnitQuaternion 

_convert to_ [_**UnitQuaternion**_](classtranslotator_1_1UnitQuaternion.md) __
```C++
inline UnitQuaternion < Type > translotator::AxisAngle::toUnitQuaternion () const
```



Casting 


        

<hr>



### function x [1/2]

```C++
inline Type translotator::AxisAngle::x () const
```




<hr>



### function x [2/2]

```C++
inline Type & translotator::AxisAngle::x () 
```




<hr>



### function y [1/2]

```C++
inline Type translotator::AxisAngle::y () const
```




<hr>



### function y [2/2]

```C++
inline Type & translotator::AxisAngle::y () 
```




<hr>



### function z [1/2]

```C++
inline Type translotator::AxisAngle::z () const
```




<hr>



### function z [2/2]

```C++
inline Type & translotator::AxisAngle::z () 
```




<hr>
## Public Static Functions Documentation




### function identity 

_Returns the identity of_ [_**AxisAngle**_](classtranslotator_1_1AxisAngle.md) _, which is a rotation of 0 degrees around the x-axis._
```C++
static inline AxisAngle < Type > translotator::AxisAngle::identity () 
```



static functions 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/AxisAngle.hpp`

