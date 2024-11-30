

# Class translotator::interpolators::Slerper

**template &lt;typename Container&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**interpolators**](namespacetranslotator_1_1interpolators.md) **>** [**Slerper**](classtranslotator_1_1interpolators_1_1Slerper.md)



_Slerp for rotation component interpolation class._ [More...](#detailed-description)

* `#include <Slerp.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Slerper**](#function-slerper-12) () = default<br> |
|   | [**Slerper**](#function-slerper-22) (const Container & start, const Container & end) <br> |
|  const Container & | [**getDiff**](#function-getdiff) () const<br> |
|  const Container & | [**getEnd**](#function-getend) () const<br> |
|  const Container & | [**getStart**](#function-getstart) () const<br>_Update difference between start and end._  |
|  Container | [**interpolate**](#function-interpolate) (Type t) const<br>_Slerp operation for_ [_**Slerper**_](classtranslotator_1_1interpolators_1_1Slerper.md) _._ |
|  Container | [**operator()**](#function-operator()) (Type t) const<br>_Slerp operation for_ [_**Slerper**_](classtranslotator_1_1interpolators_1_1Slerper.md) _._ |
|  void | [**setDiff**](#function-setdiff) (const Container & diff) <br> |
|  void | [**setEnd**](#function-setend) (const Container & end) <br> |
|  void | [**setStart**](#function-setstart) (const Container & start) <br> |
|  void | [**updateDiff**](#function-updatediff) () <br> |
|   | [**~Slerper**](#function-slerper) () = default<br> |




























# Detailed Description




**Template parameters:**


* `Container` [**Matrix**](classtranslotator_1_1Matrix.md) base type 



**Note:**

Implemented using Exp & Log Lie Group opearation 





    
## Public Functions Documentation




### function Slerper [1/2]


```C++
translotator::interpolators::Slerper::Slerper () = default
```



constructor 


        

<hr>



### function Slerper [2/2]

```C++
inline translotator::interpolators::Slerper::Slerper (
    const Container & start,
    const Container & end
) 
```




<hr>



### function getDiff 

```C++
inline const Container & translotator::interpolators::Slerper::getDiff () const
```




<hr>



### function getEnd 

```C++
inline const Container & translotator::interpolators::Slerper::getEnd () const
```




<hr>



### function getStart 

_Update difference between start and end._ 
```C++
inline const Container & translotator::interpolators::Slerper::getStart () const
```



getter & setter 


        

<hr>



### function interpolate 

```C++
inline Container translotator::interpolators::Slerper::interpolate (
    Type t
) const
```




<hr>



### function operator() 

```C++
inline Container translotator::interpolators::Slerper::operator() (
    Type t
) const
```




<hr>



### function setDiff 

```C++
inline void translotator::interpolators::Slerper::setDiff (
    const Container & diff
) 
```




<hr>



### function setEnd 

```C++
inline void translotator::interpolators::Slerper::setEnd (
    const Container & end
) 
```




<hr>



### function setStart 

```C++
inline void translotator::interpolators::Slerper::setStart (
    const Container & start
) 
```




<hr>



### function updateDiff 

```C++
inline void translotator::interpolators::Slerper::updateDiff () 
```




<hr>



### function ~Slerper 

```C++
translotator::interpolators::Slerper::~Slerper () = default
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/interpolators/Slerp.hpp`

