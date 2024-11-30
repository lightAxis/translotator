

# Struct translotator::lie::LieOperator&lt; ObjectType::SO\_GROUP, Type &gt;

**template &lt;typename Type&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**lie**](namespacetranslotator_1_1lie.md) **>** [**LieOperator&lt; ObjectType::SO\_GROUP, Type &gt;**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1SO__GROUP_00_01Type_01_4.md)



_Special Orthogonal Group._ [More...](#detailed-description)

* `#include <SO.hpp>`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; N, Type &gt; | [**LieAlgebraType**](#typedef-liealgebratype)  <br> |
| typedef [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; | [**LieGroupType**](#typedef-liegrouptype)  <br> |
| typedef [**Vector**](classtranslotator_1_1Vector.md)&lt; N==2 ? 1 :3, Type &gt; | [**VectorType**](#typedef-vectortype)  <br> |






















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  [**LieGroupType**](classtranslotator_1_1SOGroup.md)&lt; 2 &gt; | [**Exp**](#function-exp-12) (const [**VectorType**](classtranslotator_1_1Vector.md)&lt; 2 &gt; & isomorphicVec) <br>_Exponential map._  |
|  [**LieGroupType**](classtranslotator_1_1SOGroup.md)&lt; 3 &gt; | [**Exp**](#function-exp-22) (const [**VectorType**](classtranslotator_1_1Vector.md)&lt; 3 &gt; & isomorphicVec) <br>_Exponential map._  |
|  [**VectorType**](classtranslotator_1_1Vector.md)&lt; 2 &gt; | [**LieAlgebra2Vector**](#function-liealgebra2vector-12) (const [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 2 &gt; & lieAlgebra) <br>_Convert Lie Algebra to_ [_**Vector**_](classtranslotator_1_1Vector.md) _._ |
|  [**VectorType**](classtranslotator_1_1Vector.md)&lt; 3 &gt; | [**LieAlgebra2Vector**](#function-liealgebra2vector-22) (const [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 3 &gt; & lieAlgebra) <br>_Convert Lie Algebra to_ [_**Vector**_](classtranslotator_1_1Vector.md) _._ |
|  [**VectorType**](classtranslotator_1_1Vector.md)&lt; 2 &gt; | [**Log**](#function-log-12) (const [**LieGroupType**](classtranslotator_1_1SOGroup.md)&lt; 2 &gt; & lieGroup) <br>_Logarithm map._  |
|  [**VectorType**](classtranslotator_1_1Vector.md)&lt; 3 &gt; | [**Log**](#function-log-22) (const [**LieGroupType**](classtranslotator_1_1SOGroup.md)&lt; 3 &gt; & lieGroup) <br>_Logarithm map._  |
|  [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 2 &gt; | [**Vector2LieAlgebra**](#function-vector2liealgebra-12) (const [**VectorType**](classtranslotator_1_1Vector.md)&lt; 2 &gt; & isomorphicVec) <br>_Convert_ [_**Vector**_](classtranslotator_1_1Vector.md) _to Lie Algebra._ |
|  [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 3 &gt; | [**Vector2LieAlgebra**](#function-vector2liealgebra-22) (const [**VectorType**](classtranslotator_1_1Vector.md)&lt; 3 &gt; & isomorphicVec) <br>_Convert_ [_**Vector**_](classtranslotator_1_1Vector.md) _to Lie Algebra._ |
|  [**LieGroupType**](classtranslotator_1_1SOGroup.md)&lt; 2 &gt; | [**exp**](#function-exp-12) (const [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 2 &gt; & lieAlgebra) <br>_Exponential map._  |
|  [**LieGroupType**](classtranslotator_1_1SOGroup.md)&lt; 3 &gt; | [**exp**](#function-exp-22) (const [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 3 &gt; & lieAlgebra) <br>_Exponential map._  |
|  [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 2 &gt; | [**log**](#function-log-12) (const [**LieGroupType**](classtranslotator_1_1SOGroup.md)&lt; 2 &gt; & lieGroup) <br>_Logarithm map._  |
|  [**LieAlgebraType**](classtranslotator_1_1SquareMatrix.md)&lt; 3 &gt; | [**log**](#function-log-22) (const [**LieGroupType**](classtranslotator_1_1SOGroup.md)&lt; 3 &gt; & lieGroup) <br>_Logarithm map._  |


























# Detailed Description




**Template parameters:**


* `N` Dimension 
* `Type` Data type

SO is a Special Orthogonal Group 


    
## Public Types Documentation




### typedef LieAlgebraType 

```C++
using translotator::lie::LieOperator< ObjectType::SO_GROUP, Type >::LieAlgebraType =  SquareMatrix<N, Type>;
```




<hr>



### typedef LieGroupType 

```C++
using translotator::lie::LieOperator< ObjectType::SO_GROUP, Type >::LieGroupType =  SOGroup<N, Type>;
```




<hr>



### typedef VectorType 

```C++
using translotator::lie::LieOperator< ObjectType::SO_GROUP, Type >::VectorType =  Vector<N == 2 ? 1 : 3, Type>;
```




<hr>
## Public Static Functions Documentation




### function Exp [1/2]

_Exponential map._ 
```C++
static inline LieGroupType < 2 > translotator::lie::LieOperator< ObjectType::SO_GROUP, Type >::Exp (
    const VectorType < 2 > & isomorphicVec
) 
```





**Parameters:**


* `isomorphicVec` [**Vector**](classtranslotator_1_1Vector.md) [1x1], [theta] 



**Returns:**

Lie Group SO(2) 





        

<hr>



### function Exp [2/2]

_Exponential map._ 
```C++
static inline LieGroupType < 3 > translotator::lie::LieOperator< ObjectType::SO_GROUP, Type >::Exp (
    const VectorType < 3 > & isomorphicVec
) 
```





**Parameters:**


* `isomorphicVec` [**Vector**](classtranslotator_1_1Vector.md) [3x1], [x, y, z] 



**Returns:**

Lie Group SO(3) 





        

<hr>



### function LieAlgebra2Vector [1/2]

_Convert Lie Algebra to_ [_**Vector**_](classtranslotator_1_1Vector.md) _._
```C++
static inline VectorType < 2 > translotator::lie::LieOperator< ObjectType::SO_GROUP, Type >::LieAlgebra2Vector (
    const LieAlgebraType < 2 > & lieAlgebra
) 
```





**Parameters:**


* `lieAlgebra` Lie Algebra [2x2] [0 -theta; theta 0] 



**Returns:**

[**Vector**](classtranslotator_1_1Vector.md) [1x1], [theta] 





        

<hr>



### function LieAlgebra2Vector [2/2]

_Convert Lie Algebra to_ [_**Vector**_](classtranslotator_1_1Vector.md) _._
```C++
static inline VectorType < 3 > translotator::lie::LieOperator< ObjectType::SO_GROUP, Type >::LieAlgebra2Vector (
    const LieAlgebraType < 3 > & lieAlgebra
) 
```





**Parameters:**


* `lieAlgebra` Lie Algebra [3x3] [0 -z y; z 0 -x; -y x 0] 



**Returns:**

[**Vector**](classtranslotator_1_1Vector.md) [3x1], [x, y, z] 





        

<hr>



### function Log [1/2]

_Logarithm map._ 
```C++
static inline VectorType < 2 > translotator::lie::LieOperator< ObjectType::SO_GROUP, Type >::Log (
    const LieGroupType < 2 > & lieGroup
) 
```





**Parameters:**


* `lieGroup` Lie Group SO(2) 



**Returns:**

[**Vector**](classtranslotator_1_1Vector.md) [1x1], [theta] 





        

<hr>



### function Log [2/2]

_Logarithm map._ 
```C++
static inline VectorType < 3 > translotator::lie::LieOperator< ObjectType::SO_GROUP, Type >::Log (
    const LieGroupType < 3 > & lieGroup
) 
```





**Parameters:**


* `lieGroup` Lie Group SO(3) 



**Returns:**

[**Vector**](classtranslotator_1_1Vector.md) [3x1], [x, y, z] 





        

<hr>



### function Vector2LieAlgebra [1/2]

_Convert_ [_**Vector**_](classtranslotator_1_1Vector.md) _to Lie Algebra._
```C++
static inline LieAlgebraType < 2 > translotator::lie::LieOperator< ObjectType::SO_GROUP, Type >::Vector2LieAlgebra (
    const VectorType < 2 > & isomorphicVec
) 
```





**Parameters:**


* `isomorphicVec` [**Vector**](classtranslotator_1_1Vector.md) [1x1], [theta] 



**Returns:**

Lie Algebra [2x2] [0 -theta; theta 0] 





        

<hr>



### function Vector2LieAlgebra [2/2]

_Convert_ [_**Vector**_](classtranslotator_1_1Vector.md) _to Lie Algebra._
```C++
static inline LieAlgebraType < 3 > translotator::lie::LieOperator< ObjectType::SO_GROUP, Type >::Vector2LieAlgebra (
    const VectorType < 3 > & isomorphicVec
) 
```





**Parameters:**


* `isomorphicVec` [**Vector**](classtranslotator_1_1Vector.md) [3x1], [x, y, z] 



**Returns:**

Lie Algebra [3x3] [0 -z y; z 0 -x; -y x 0] 





        

<hr>



### function exp [1/2]

_Exponential map._ 
```C++
static inline LieGroupType < 2 > translotator::lie::LieOperator< ObjectType::SO_GROUP, Type >::exp (
    const LieAlgebraType < 2 > & lieAlgebra
) 
```





**Parameters:**


* `lieAlgebra` Lie Algebra [2x2] [0 -theta; theta 0] 



**Returns:**

Lie Group SO(2) 





        

<hr>



### function exp [2/2]

_Exponential map._ 
```C++
static inline LieGroupType < 3 > translotator::lie::LieOperator< ObjectType::SO_GROUP, Type >::exp (
    const LieAlgebraType < 3 > & lieAlgebra
) 
```





**Parameters:**


* `lieAlgebra` Lie Algebra [3x3] [0 -z y; z 0 -x; -y x 0] 



**Returns:**

Lie Group SO(3) 





        

<hr>



### function log [1/2]

_Logarithm map._ 
```C++
static inline LieAlgebraType < 2 > translotator::lie::LieOperator< ObjectType::SO_GROUP, Type >::log (
    const LieGroupType < 2 > & lieGroup
) 
```





**Parameters:**


* `lieGroup` Lie Group SO(2) 



**Returns:**

Lie Algebra [2x2] [0 -theta; theta 0] 





        

<hr>



### function log [2/2]

_Logarithm map._ 
```C++
static inline LieAlgebraType < 3 > translotator::lie::LieOperator< ObjectType::SO_GROUP, Type >::log (
    const LieGroupType < 3 > & lieGroup
) 
```





**Parameters:**


* `lieGroup` Lie Group SO(3) 



**Returns:**

Lie Algebra [3x3] [0 -z y; z 0 -x; -y x 0] 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/lie/SO.hpp`

