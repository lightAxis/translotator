

# Class translotator::interpolators::ScLerper

**template &lt;typename Container&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**interpolators**](namespacetranslotator_1_1interpolators.md) **>** [**ScLerper**](classtranslotator_1_1interpolators_1_1ScLerper.md)



_Screw linear interpolation class._ [More...](#detailed-description)

* `#include <ScLerp.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**ScLerper**](#function-sclerper-12) () = default<br> |
|   | [**ScLerper**](#function-sclerper-22) (const Container & start, const Container & end) <br> |
|  Container | [**getDiff**](#function-getdiff) () const<br> |
|  Container | [**getEnd**](#function-getend) () const<br> |
|  Container | [**getStart**](#function-getstart) () const<br>_Update difference between start and end._  |
|  Container | [**interpolate**](#function-interpolate) (Type t) <br>_ScLerp operation for_ [_**ScLerper**_](classtranslotator_1_1interpolators_1_1ScLerper.md) _._ |
|  Container | [**operator()**](#function-operator()) (Type t) const<br>_ScLerp operation for_ [_**ScLerper**_](classtranslotator_1_1interpolators_1_1ScLerper.md) _._ |
|  void | [**setDiff**](#function-setdiff) (const Container & diff) <br> |
|  void | [**setEnd**](#function-setend) (const Container & end) <br> |
|  void | [**setStart**](#function-setstart) (const Container & start) <br> |
|  void | [**updateDiff**](#function-updatediff) () <br> |
|   | [**~ScLerper**](#function-sclerper) () = default<br> |




























# Detailed Description




**Template parameters:**


* `Container` [**Matrix**](classtranslotator_1_1Matrix.md) base type 




    
## Public Functions Documentation




### function ScLerper [1/2]


```C++
translotator::interpolators::ScLerper::ScLerper () = default
```



constructor 


        

<hr>



### function ScLerper [2/2]

```C++
inline translotator::interpolators::ScLerper::ScLerper (
    const Container & start,
    const Container & end
) 
```




<hr>



### function getDiff 

```C++
inline Container translotator::interpolators::ScLerper::getDiff () const
```




<hr>



### function getEnd 

```C++
inline Container translotator::interpolators::ScLerper::getEnd () const
```




<hr>



### function getStart 

_Update difference between start and end._ 
```C++
inline Container translotator::interpolators::ScLerper::getStart () const
```



getter and setter 


        

<hr>



### function interpolate 

```C++
inline Container translotator::interpolators::ScLerper::interpolate (
    Type t
) 
```




<hr>



### function operator() 

```C++
inline Container translotator::interpolators::ScLerper::operator() (
    Type t
) const
```




<hr>



### function setDiff 

```C++
inline void translotator::interpolators::ScLerper::setDiff (
    const Container & diff
) 
```




<hr>



### function setEnd 

```C++
inline void translotator::interpolators::ScLerper::setEnd (
    const Container & end
) 
```




<hr>



### function setStart 

```C++
inline void translotator::interpolators::ScLerper::setStart (
    const Container & start
) 
```




<hr>



### function updateDiff 

```C++
inline void translotator::interpolators::ScLerper::updateDiff () 
```




<hr>



### function ~ScLerper 

```C++
translotator::interpolators::ScLerper::~ScLerper () = default
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/interpolators/ScLerp.hpp`

