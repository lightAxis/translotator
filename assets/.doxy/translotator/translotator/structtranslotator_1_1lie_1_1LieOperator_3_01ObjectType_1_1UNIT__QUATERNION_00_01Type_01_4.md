

# Struct translotator::lie::LieOperator&lt; ObjectType::UNIT\_QUATERNION, Type &gt;

**template &lt;typename Type&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**lie**](namespacetranslotator_1_1lie.md) **>** [**LieOperator&lt; ObjectType::UNIT\_QUATERNION, Type &gt;**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1UNIT__QUATERNION_00_01Type_01_4.md)



_Lie Operator for S3._ [More...](#detailed-description)

* `#include <S3.hpp>`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef [**Quaternion**](classtranslotator_1_1Quaternion.md)&lt; Type &gt; | [**LieAlgebraType**](#typedef-liealgebratype)  <br> |
| typedef [**UnitQuaternion**](classtranslotator_1_1UnitQuaternion.md)&lt; Type &gt; | [**LieGroupType**](#typedef-liegrouptype)  <br> |
| typedef [**Vector**](classtranslotator_1_1Vector.md)&lt; 3, Type &gt; | [**VectorType**](#typedef-vectortype)  <br> |






















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  [**LieGroupType**](classtranslotator_1_1UnitQuaternion.md) | [**Exp**](#function-exp) (const [**VectorType**](classtranslotator_1_1Vector.md) & isomorphicVec) <br>_Exponential map._  |
|  [**VectorType**](classtranslotator_1_1Vector.md) | [**LieAlgebra2Vector**](#function-liealgebra2vector) (const [**LieAlgebraType**](classtranslotator_1_1Quaternion.md) & lieAlgebra) <br>_Convert Lie Algebra to_ [_**Vector**_](classtranslotator_1_1Vector.md) _._ |
|  [**VectorType**](classtranslotator_1_1Vector.md) | [**Log**](#function-log) (const [**LieGroupType**](classtranslotator_1_1UnitQuaternion.md) & lieGroup) <br>_Logarithm map._  |
|  [**LieAlgebraType**](classtranslotator_1_1Quaternion.md) | [**Vector2LieAlgebra**](#function-vector2liealgebra) (const [**VectorType**](classtranslotator_1_1Vector.md) & isomorphicVec) <br>_Convert_ [_**Vector**_](classtranslotator_1_1Vector.md) _to Lie Algebra._ |
|  [**LieGroupType**](classtranslotator_1_1UnitQuaternion.md) | [**exp**](#function-exp) (const [**LieAlgebraType**](classtranslotator_1_1Quaternion.md) & lieAlgebra) <br>_Exponential map._  |
|  [**LieAlgebraType**](classtranslotator_1_1Quaternion.md) | [**log**](#function-log) (const [**LieGroupType**](classtranslotator_1_1UnitQuaternion.md) & lieGroup) <br>_Logarithm map._  |


























# Detailed Description




**Template parameters:**


* `Type` Data type

S3 is a unit quaternion 


    
## Public Types Documentation




### typedef LieAlgebraType 

```C++
using translotator::lie::LieOperator< ObjectType::UNIT_QUATERNION, Type >::LieAlgebraType =  Quaternion<Type>;
```




<hr>



### typedef LieGroupType 

```C++
using translotator::lie::LieOperator< ObjectType::UNIT_QUATERNION, Type >::LieGroupType =  UnitQuaternion<Type>;
```




<hr>



### typedef VectorType 

```C++
using translotator::lie::LieOperator< ObjectType::UNIT_QUATERNION, Type >::VectorType =  Vector<3, Type>;
```




<hr>
## Public Static Functions Documentation




### function Exp 

_Exponential map._ 
```C++
static inline LieGroupType translotator::lie::LieOperator< ObjectType::UNIT_QUATERNION, Type >::Exp (
    const VectorType & isomorphicVec
) 
```





**Parameters:**


* `isomorphicVec` [**Vector**](classtranslotator_1_1Vector.md) [3x1], [x, y, z] 



**Returns:**

Lie Group [4x1] Unit [**Quaternion**](classtranslotator_1_1Quaternion.md) 





        

<hr>



### function LieAlgebra2Vector 

_Convert Lie Algebra to_ [_**Vector**_](classtranslotator_1_1Vector.md) _._
```C++
static inline VectorType translotator::lie::LieOperator< ObjectType::UNIT_QUATERNION, Type >::LieAlgebra2Vector (
    const LieAlgebraType & lieAlgebra
) 
```





**Parameters:**


* `lieAlgebra` Lie Algebra [4x1] 0+x\*i+y\*j+z\*k, pure imaginary number 



**Returns:**

[**Vector**](classtranslotator_1_1Vector.md) [3x1], [x, y, z] 





        

<hr>



### function Log 

_Logarithm map._ 
```C++
static inline VectorType translotator::lie::LieOperator< ObjectType::UNIT_QUATERNION, Type >::Log (
    const LieGroupType & lieGroup
) 
```





**Parameters:**


* `lieGroup` Lie Group [4x1] Unit [**Quaternion**](classtranslotator_1_1Quaternion.md) 



**Returns:**

[**Vector**](classtranslotator_1_1Vector.md) [3x1], [x, y, z] 





        

<hr>



### function Vector2LieAlgebra 

_Convert_ [_**Vector**_](classtranslotator_1_1Vector.md) _to Lie Algebra._
```C++
static inline LieAlgebraType translotator::lie::LieOperator< ObjectType::UNIT_QUATERNION, Type >::Vector2LieAlgebra (
    const VectorType & isomorphicVec
) 
```





**Parameters:**


* `isomorphicVec` [**Vector**](classtranslotator_1_1Vector.md) [3x1], [x, y, z] 



**Returns:**

Lie Algebra [4x1] 0+x\*i+y\*j+z\*k, pure imaginary number 





        

<hr>



### function exp 

_Exponential map._ 
```C++
static inline LieGroupType translotator::lie::LieOperator< ObjectType::UNIT_QUATERNION, Type >::exp (
    const LieAlgebraType & lieAlgebra
) 
```





**Parameters:**


* `lieAlgebra` Lie Algebra [4x1] 0+x\*i+y\*j+z\*k, pure imaginary number 



**Returns:**

Lie Group [4x1] Unit [**Quaternion**](classtranslotator_1_1Quaternion.md) 





        

<hr>



### function log 

_Logarithm map._ 
```C++
static inline LieAlgebraType translotator::lie::LieOperator< ObjectType::UNIT_QUATERNION, Type >::log (
    const LieGroupType & lieGroup
) 
```





**Parameters:**


* `lieGroup` Lie Group [4x1] Unit [**Quaternion**](classtranslotator_1_1Quaternion.md) 



**Returns:**

Lie Algebra [4x1] 0+x\*i+y\*j+z\*k, pure imaginary number 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/lie/S3.hpp`

