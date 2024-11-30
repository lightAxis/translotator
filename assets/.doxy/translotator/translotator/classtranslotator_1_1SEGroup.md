

# Class translotator::SEGroup

**template &lt;size\_t N, typename Type&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**SEGroup**](classtranslotator_1_1SEGroup.md)



_Special Euclidean Group._ [More...](#detailed-description)

* `#include <SEGroup.hpp>`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef Type | [**DATATYPE**](#typedef-datatype)  <br> |






## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr static ObjectType | [**OBJECT\_TYPE**](#variable-object_type)   = = ObjectType::SE\_GROUP<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**SEGroup**](#function-segroup-13) () = default<br> |
|   | [**SEGroup**](#function-segroup-23) (const [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; & rotation, const [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; & translation) <br> |
|   | [**SEGroup**](#function-segroup-33) (const [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; N+1, Type &gt; & matrix) <br> |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; | [**actOnVector**](#function-actonvector) (const [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; & vec) const<br>_act on vector_  |
|  [**SEGroup**](classtranslotator_1_1SEGroup.md)&lt; N, Type &gt; | [**inversed**](#function-inversed) () const<br>_inverse_  |
|  [**SEGroup**](classtranslotator_1_1SEGroup.md)&lt; N, Type &gt; | [**operator\***](#function-operator) (const [**SEGroup**](classtranslotator_1_1SEGroup.md)&lt; N, Type &gt; & other) const<br>[_**SEGroup**_](classtranslotator_1_1SEGroup.md) _\*_[_**SEGroup**_](classtranslotator_1_1SEGroup.md) _._ |
|  [**SEGroup**](classtranslotator_1_1SEGroup.md)&lt; N, Type &gt; | [**operator/**](#function-operator_1) (const [**SEGroup**](classtranslotator_1_1SEGroup.md)&lt; N, Type &gt; & other) const<br>[_**SEGroup**_](classtranslotator_1_1SEGroup.md) _/_[_**SEGroup**_](classtranslotator_1_1SEGroup.md) _._ |
|  [**SEGroup**](classtranslotator_1_1SEGroup.md)&lt; N, Type &gt; | [**pow**](#function-pow) (const Type & t) const<br>_power_  |
|  void | [**print**](#function-print) () const<br>_print_  |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; | [**rotation**](#function-rotation-12) () const<br> |
|  [**SOGroup**](classtranslotator_1_1SOGroup.md)&lt; N, Type &gt; & | [**rotation**](#function-rotation-22) () <br> |
|  [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; N+1, Type &gt; | [**toSquareMatrix**](#function-tosquarematrix) () const<br>_to square matrix_  |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; | [**translation**](#function-translation-12) () const<br> |
|  [**Vector**](classtranslotator_1_1Vector.md)&lt; N, Type &gt; & | [**translation**](#function-translation-22) () <br> |
|   | [**~SEGroup**](#function-segroup) () = default<br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  [**SEGroup**](classtranslotator_1_1SEGroup.md)&lt; N, Type &gt; | [**identity**](#function-identity) () <br>_identity_  |


























# Detailed Description




**Template parameters:**


* `N` dimension 
* `Type` data type

Special Euclidean Group is a group of rigid body transformation in N dimension. It is a combination of rotation and translation. Subgroup of [**SEGroup**](classtranslotator_1_1SEGroup.md) is [**SOGroup**](classtranslotator_1_1SOGroup.md) and Translation. Also [**SEGroup**](classtranslotator_1_1SEGroup.md) is a Lie Group, which means it has a group structure and a smooth manifold structure. Exponential and Logarithm map can be defined. 

**Note:**

Not a [**Matrix**](classtranslotator_1_1Matrix.md) based implementation. Just a composition of [**SOGroup**](classtranslotator_1_1SOGroup.md) and Translation each. 





    
## Public Types Documentation




### typedef DATATYPE 

```C++
using translotator::SEGroup< N, Type >::DATATYPE =  Type;
```




<hr>
## Public Static Attributes Documentation




### variable OBJECT\_TYPE 

```C++
constexpr static ObjectType translotator::SEGroup< N, Type >::OBJECT_TYPE;
```




<hr>
## Public Functions Documentation




### function SEGroup [1/3]


```C++
translotator::SEGroup::SEGroup () = default
```



constructor 


        

<hr>



### function SEGroup [2/3]

```C++
inline translotator::SEGroup::SEGroup (
    const SOGroup < N, Type > & rotation,
    const Vector < N, Type > & translation
) 
```




<hr>



### function SEGroup [3/3]

```C++
inline translotator::SEGroup::SEGroup (
    const SquareMatrix < N+1, Type > & matrix
) 
```




<hr>



### function actOnVector 

```C++
inline Vector < N, Type > translotator::SEGroup::actOnVector (
    const Vector < N, Type > & vec
) const
```




<hr>



### function inversed 

_inverse_ 
```C++
inline SEGroup < N, Type > translotator::SEGroup::inversed () const
```



utils 


        

<hr>



### function operator\* 

[_**SEGroup**_](classtranslotator_1_1SEGroup.md) _\*_[_**SEGroup**_](classtranslotator_1_1SEGroup.md) _._
```C++
inline SEGroup < N, Type > translotator::SEGroup::operator* (
    const SEGroup < N, Type > & other
) const
```



operator 


        

<hr>



### function operator/ 

```C++
inline SEGroup < N, Type > translotator::SEGroup::operator/ (
    const SEGroup < N, Type > & other
) const
```




<hr>



### function pow 

```C++
inline SEGroup < N, Type > translotator::SEGroup::pow (
    const Type & t
) const
```




<hr>



### function print 

```C++
inline void translotator::SEGroup::print () const
```




<hr>



### function rotation [1/2]


```C++
inline SOGroup < N, Type > translotator::SEGroup::rotation () const
```



accessors 


        

<hr>



### function rotation [2/2]

```C++
inline SOGroup < N, Type > & translotator::SEGroup::rotation () 
```




<hr>



### function toSquareMatrix 

_to square matrix_ 
```C++
inline SquareMatrix < N+1, Type > translotator::SEGroup::toSquareMatrix () const
```



casting 


        

<hr>



### function translation [1/2]

```C++
inline Vector < N, Type > translotator::SEGroup::translation () const
```




<hr>



### function translation [2/2]

```C++
inline Vector < N, Type > & translotator::SEGroup::translation () 
```




<hr>



### function ~SEGroup 

```C++
translotator::SEGroup::~SEGroup () = default
```




<hr>
## Public Static Functions Documentation




### function identity 

_identity_ 
```C++
static inline SEGroup < N, Type > translotator::SEGroup::identity () 
```



static functions 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/SEGroup.hpp`

