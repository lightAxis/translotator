

# Class translotator::interpolators::SlerpLerper

**template &lt;typename Container&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**interpolators**](namespacetranslotator_1_1interpolators.md) **>** [**SlerpLerper**](classtranslotator_1_1interpolators_1_1SlerpLerper.md)



_Slerp for rotation component, lerp for translation component class._ [More...](#detailed-description)

* `#include <Slerp_Lerp.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**SlerpLerper**](#function-slerplerper-12) () = default<br> |
|   | [**SlerpLerper**](#function-slerplerper-22) (const Container & start, const Container & end) <br> |
|  const Container & | [**getDiff**](#function-getdiff) () const<br> |
|  const Container & | [**getEnd**](#function-getend) () const<br> |
|  const Container & | [**getStart**](#function-getstart) () const<br>_Update difference between start and end._  |
|  Container | [**interpolate**](#function-interpolate) (Type t) const<br>_SlerpLerp operation for_ [_**SlerpLerper**_](classtranslotator_1_1interpolators_1_1SlerpLerper.md) _._ |
|  Container | [**operator()**](#function-operator()) (Type t) const<br>_SlerpLerp operation for_ [_**SlerpLerper**_](classtranslotator_1_1interpolators_1_1SlerpLerper.md) _._ |
|  void | [**setDiff**](#function-setdiff) (const Container & diff) <br> |
|  void | [**setEnd**](#function-setend) (const Container & end) <br> |
|  void | [**setStart**](#function-setstart) (const Container & start) <br> |
|  void | [**updateDiff**](#function-updatediff) () <br> |
|   | [**~SlerpLerper**](#function-slerplerper) () = default<br> |




























# Detailed Description




**Template parameters:**


* `Container` [**Matrix**](classtranslotator_1_1Matrix.md) base type 




    
## Public Functions Documentation




### function SlerpLerper [1/2]


```C++
translotator::interpolators::SlerpLerper::SlerpLerper () = default
```



constructor 


        

<hr>



### function SlerpLerper [2/2]

```C++
inline translotator::interpolators::SlerpLerper::SlerpLerper (
    const Container & start,
    const Container & end
) 
```




<hr>



### function getDiff 

```C++
inline const Container & translotator::interpolators::SlerpLerper::getDiff () const
```




<hr>



### function getEnd 

```C++
inline const Container & translotator::interpolators::SlerpLerper::getEnd () const
```




<hr>



### function getStart 

_Update difference between start and end._ 
```C++
inline const Container & translotator::interpolators::SlerpLerper::getStart () const
```



getter & setter 


        

<hr>



### function interpolate 

```C++
inline Container translotator::interpolators::SlerpLerper::interpolate (
    Type t
) const
```




<hr>



### function operator() 

```C++
inline Container translotator::interpolators::SlerpLerper::operator() (
    Type t
) const
```




<hr>



### function setDiff 

```C++
inline void translotator::interpolators::SlerpLerper::setDiff (
    const Container & diff
) 
```




<hr>



### function setEnd 

```C++
inline void translotator::interpolators::SlerpLerper::setEnd (
    const Container & end
) 
```




<hr>



### function setStart 

```C++
inline void translotator::interpolators::SlerpLerper::setStart (
    const Container & start
) 
```




<hr>



### function updateDiff 

```C++
inline void translotator::interpolators::SlerpLerper::updateDiff () 
```




<hr>



### function ~SlerpLerper 

```C++
translotator::interpolators::SlerpLerper::~SlerpLerper () = default
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/interpolators/Slerp_Lerp.hpp`

