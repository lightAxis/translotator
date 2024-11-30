

# Struct translotator::lie::LieOperator&lt; ObjectType::SE\_GROUP, Type &gt;

**template &lt;typename Type&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**lie**](namespacetranslotator_1_1lie.md) **>** [**LieOperator&lt; ObjectType::SE\_GROUP, Type &gt;**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1SE__GROUP_00_01Type_01_4.md)



_Lie Operator for SE._ [More...](#detailed-description)

* `#include <SE.hpp>`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; N+1, Type &gt; | [**LieAlgebraType**](#typedef-liealgebratype)  <br> |
| typedef [**SEGroup**](classtranslotator_1_1SEGroup.md)&lt; N, Type &gt; | [**LieGroupType**](#typedef-liegrouptype)  <br> |
| typedef [**Vector**](classtranslotator_1_1Vector.md)&lt; N==2 ? 3 :6, Type &gt; | [**VectorType**](#typedef-vectortype)  <br> |






















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  [**LieGroupType**](classtranslotator_1_1SEGroup.md)&lt; 2 &gt; | [**Exp**](#function-exp-12) (const [**VectorType**](classtranslotator_1_1Vector.md)&lt; 2 &gt; & isomorphicVec) <br>_Exponential map._  |
|  [**LieGroupType**](classtranslotator_1_1SEGroup.md)&lt; 3 &gt; | [**Exp**](#function-exp-22) (const [**VectorType**](classtranslotator_1_1Vector.md)&lt; 3 &gt; & isomorphicVec) <br>_Exponential map._  |
|  [**VectorType**](classtranslotator_1_1Vector.md)&lt; 2 &gt; | [**LieAlgebra2Vector**](#function-liealgebra2vector-12) (const [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 2 &gt; & lieAlgebra) <br>_Convert SE(2) Lie Algebra to_ [_**Vector**_](classtranslotator_1_1Vector.md) _._ |
|  [**VectorType**](classtranslotator_1_1Vector.md)&lt; 3 &gt; | [**LieAlgebra2Vector**](#function-liealgebra2vector-22) (const [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 3 &gt; & lieAlgebra) <br>_Convert SE(3) Lie Algebra to_ [_**Vector**_](classtranslotator_1_1Vector.md) _._ |
|  [**VectorType**](classtranslotator_1_1Vector.md)&lt; 2 &gt; | [**Log**](#function-log-12) (const [**LieGroupType**](classtranslotator_1_1SEGroup.md)&lt; 2 &gt; & lieGroup) <br>_Logarithm map._  |
|  [**VectorType**](classtranslotator_1_1Vector.md)&lt; 3 &gt; | [**Log**](#function-log-22) (const [**LieGroupType**](classtranslotator_1_1SEGroup.md)&lt; 3 &gt; & lieGroup) <br>_Logarithm map._  |
|  [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 2 &gt; | [**Vector2LieAlgebra**](#function-vector2liealgebra-12) (const [**VectorType**](classtranslotator_1_1Vector.md)&lt; 2 &gt; & isomorphicVec) <br>_Convert_ [_**Vector**_](classtranslotator_1_1Vector.md) _to SE(2) Lie Algebra._ |
|  [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 3 &gt; | [**Vector2LieAlgebra**](#function-vector2liealgebra-22) (const [**VectorType**](classtranslotator_1_1Vector.md)&lt; 3 &gt; & isomorphicVec) <br>_Convert_ [_**Vector**_](classtranslotator_1_1Vector.md) _to SE(3) Lie Algebra._ |
|  [**LieGroupType**](classtranslotator_1_1SEGroup.md)&lt; 2 &gt; | [**exp**](#function-exp-12) (const [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 2 &gt; & lieAlgebra) <br>_Exponential map._  |
|  [**LieGroupType**](classtranslotator_1_1SEGroup.md)&lt; 3 &gt; | [**exp**](#function-exp-22) (const [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 3 &gt; & lieAlgebra) <br>_Exponential map._  |
|  [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 2 &gt; | [**log**](#function-log-12) (const [**LieGroupType**](classtranslotator_1_1SEGroup.md)&lt; 2 &gt; & lieGroup) <br>_Logarithm map._  |
|  [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 3 &gt; | [**log**](#function-log-22) (const [**LieGroupType**](classtranslotator_1_1SEGroup.md)&lt; 3 &gt; & lieGroup) <br>_Logarithm map._  |


























# Detailed Description




**Template parameters:**


* `Type` Data type

SE is a Special Euclidean Group 


    
## Public Types Documentation




### typedef LieAlgebraType 

```C++
using translotator::lie::LieOperator< ObjectType::SE_GROUP, Type >::LieAlgebraType =  SquareMatrix<N + 1, Type>;
```




<hr>



### typedef LieGroupType 

```C++
using translotator::lie::LieOperator< ObjectType::SE_GROUP, Type >::LieGroupType =  SEGroup<N, Type>;
```




<hr>



### typedef VectorType 

```C++
using translotator::lie::LieOperator< ObjectType::SE_GROUP, Type >::VectorType =  Vector<N == 2 ? 3 : 6, Type>;
```




<hr>
## Public Static Functions Documentation




### function Exp [1/2]

_Exponential map._ 
```C++
static inline LieGroupType < 2 > translotator::lie::LieOperator< ObjectType::SE_GROUP, Type >::Exp (
    const VectorType < 2 > & isomorphicVec
) 
```





**Parameters:**


* `isomorphicVec` [**Vector**](classtranslotator_1_1Vector.md) [3x1], [theta, x, y] 



**Returns:**

Lie Group SE(2) 





        

<hr>



### function Exp [2/2]

_Exponential map._ 
```C++
static inline LieGroupType < 3 > translotator::lie::LieOperator< ObjectType::SE_GROUP, Type >::Exp (
    const VectorType < 3 > & isomorphicVec
) 
```





**Parameters:**


* `isomorphicVec` [**Vector**](classtranslotator_1_1Vector.md) [6x1], [theta\_x, theta\_y, theta\_z, x, y, z] 



**Returns:**

Lie Group SE(3) 





        

<hr>



### function LieAlgebra2Vector [1/2]

_Convert SE(2) Lie Algebra to_ [_**Vector**_](classtranslotator_1_1Vector.md) _._
```C++
static inline VectorType < 2 > translotator::lie::LieOperator< ObjectType::SE_GROUP, Type >::LieAlgebra2Vector (
    const LieAlgebraType < 2 > & lieAlgebra
) 
```





**Parameters:**


* `lieAlgebra` Lie Algebra [theta Vt; 0 0] 



**Returns:**

[**Vector**](classtranslotator_1_1Vector.md) [3x1], [theta, x, y] 





        

<hr>



### function LieAlgebra2Vector [2/2]

_Convert SE(3) Lie Algebra to_ [_**Vector**_](classtranslotator_1_1Vector.md) _._
```C++
static inline VectorType < 3 > translotator::lie::LieOperator< ObjectType::SE_GROUP, Type >::LieAlgebra2Vector (
    const LieAlgebraType < 3 > & lieAlgebra
) 
```





**Parameters:**


* `lieAlgebra` Lie Algebra [theta Vt; 0 0] 



**Returns:**

[**Vector**](classtranslotator_1_1Vector.md) [6x1], [theta\_x, theta\_y, theta\_z, x, y, z] 





        

<hr>



### function Log [1/2]

_Logarithm map._ 
```C++
static inline VectorType < 2 > translotator::lie::LieOperator< ObjectType::SE_GROUP, Type >::Log (
    const LieGroupType < 2 > & lieGroup
) 
```





**Parameters:**


* `lieGroup` Lie Group SE(2) 



**Returns:**

[**Vector**](classtranslotator_1_1Vector.md) [3x1], [theta, x, y] 





        

<hr>



### function Log [2/2]

_Logarithm map._ 
```C++
static inline VectorType < 3 > translotator::lie::LieOperator< ObjectType::SE_GROUP, Type >::Log (
    const LieGroupType < 3 > & lieGroup
) 
```





**Parameters:**


* `lieGroup` Lie Group SE(3) 



**Returns:**

[**Vector**](classtranslotator_1_1Vector.md) [6x1], [theta\_x, theta\_y, theta\_z, x, y, z] 





        

<hr>



### function Vector2LieAlgebra [1/2]

_Convert_ [_**Vector**_](classtranslotator_1_1Vector.md) _to SE(2) Lie Algebra._
```C++
static inline LieAlgebraType < 2 > translotator::lie::LieOperator< ObjectType::SE_GROUP, Type >::Vector2LieAlgebra (
    const VectorType < 2 > & isomorphicVec
) 
```





**Parameters:**


* `isomorphicVec` [**Vector**](classtranslotator_1_1Vector.md) [3x1], [theta, x, y] 



**Returns:**

Lie Algebra [3x3] [theta Vt; 0 0] 





        

<hr>



### function Vector2LieAlgebra [2/2]

_Convert_ [_**Vector**_](classtranslotator_1_1Vector.md) _to SE(3) Lie Algebra._
```C++
static inline LieAlgebraType < 3 > translotator::lie::LieOperator< ObjectType::SE_GROUP, Type >::Vector2LieAlgebra (
    const VectorType < 3 > & isomorphicVec
) 
```





**Parameters:**


* `isomorphicVec` [**Vector**](classtranslotator_1_1Vector.md) [6x1], [theta\_x, theta\_y, theta\_z, x, y, z] 



**Returns:**

Lie Algebra [4x4] [theta Vt; 0 0] 





        

<hr>



### function exp [1/2]

_Exponential map._ 
```C++
static inline LieGroupType < 2 > translotator::lie::LieOperator< ObjectType::SE_GROUP, Type >::exp (
    const LieAlgebraType < 2 > & lieAlgebra
) 
```





**Parameters:**


* `lieAlgebra` Lie Algebra [3x3] [theta Vt; 0 0] 



**Returns:**

Lie Group SE(2) 





        

<hr>



### function exp [2/2]

_Exponential map._ 
```C++
static inline LieGroupType < 3 > translotator::lie::LieOperator< ObjectType::SE_GROUP, Type >::exp (
    const LieAlgebraType < 3 > & lieAlgebra
) 
```





**Parameters:**


* `lieAlgebra` Lie Algebra [4x4] [theta Vt; 0 0] 



**Returns:**

Lie Group SE(3) 





        

<hr>



### function log [1/2]

_Logarithm map._ 
```C++
static inline LieAlgebraType < 2 > translotator::lie::LieOperator< ObjectType::SE_GROUP, Type >::log (
    const LieGroupType < 2 > & lieGroup
) 
```





**Parameters:**


* `lieGroup` Lie Group SE(2) 



**Returns:**

Lie Algebra [3x3] [theta Vt; 0 0] 





        

<hr>



### function log [2/2]

_Logarithm map._ 
```C++
static inline LieAlgebraType < 3 > translotator::lie::LieOperator< ObjectType::SE_GROUP, Type >::log (
    const LieGroupType < 3 > & lieGroup
) 
```





**Parameters:**


* `lieGroup` Lie Group SE(3) 



**Returns:**

Lie Algebra [4x4] [theta Vt; 0 0] 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/lie/SE.hpp`

