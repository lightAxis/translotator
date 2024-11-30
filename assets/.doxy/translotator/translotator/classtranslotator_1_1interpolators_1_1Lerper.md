

# Class translotator::interpolators::Lerper

**template &lt;typename Container&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**interpolators**](namespacetranslotator_1_1interpolators.md) **>** [**Lerper**](classtranslotator_1_1interpolators_1_1Lerper.md)



_Linear interpolation class._ [More...](#detailed-description)

* `#include <Lerp.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Lerper**](#function-lerper-12) () = default<br> |
|   | [**Lerper**](#function-lerper-22) (const Container & start, const Container & end) <br> |
|  const Container & | [**getDiff**](#function-getdiff) () const<br> |
|  const Container & | [**getEnd**](#function-getend) () const<br> |
|  const Container & | [**getStart**](#function-getstart) () const<br>_Update difference between start and end._  |
|  Container | [**interpolate**](#function-interpolate) (ScalarType t) const<br>_Lerp operation for_ [_**Lerper**_](classtranslotator_1_1interpolators_1_1Lerper.md) _._ |
|  Container | [**operator()**](#function-operator()) (ScalarType t) const<br>_Lerp operation for_ [_**Lerper**_](classtranslotator_1_1interpolators_1_1Lerper.md) _._ |
|  void | [**setDiff**](#function-setdiff) (const Container & diff) <br> |
|  void | [**setEnd**](#function-setend) (const Container & end) <br> |
|  void | [**setStart**](#function-setstart) (const Container & start) <br> |
|  void | [**updateDiff**](#function-updatediff) () <br> |
|   | [**~Lerper**](#function-lerper) () = default<br> |




























# Detailed Description




**Template parameters:**


* `Container` [**Matrix**](classtranslotator_1_1Matrix.md) base type 




    
## Public Functions Documentation




### function Lerper [1/2]


```C++
translotator::interpolators::Lerper::Lerper () = default
```



constructor 


        

<hr>



### function Lerper [2/2]

```C++
inline translotator::interpolators::Lerper::Lerper (
    const Container & start,
    const Container & end
) 
```




<hr>



### function getDiff 

```C++
inline const Container & translotator::interpolators::Lerper::getDiff () const
```




<hr>



### function getEnd 

```C++
inline const Container & translotator::interpolators::Lerper::getEnd () const
```




<hr>



### function getStart 

_Update difference between start and end._ 
```C++
inline const Container & translotator::interpolators::Lerper::getStart () const
```



getter & setter 


        

<hr>



### function interpolate 

```C++
inline Container translotator::interpolators::Lerper::interpolate (
    ScalarType t
) const
```




<hr>



### function operator() 

```C++
inline Container translotator::interpolators::Lerper::operator() (
    ScalarType t
) const
```




<hr>



### function setDiff 

```C++
inline void translotator::interpolators::Lerper::setDiff (
    const Container & diff
) 
```




<hr>



### function setEnd 

```C++
inline void translotator::interpolators::Lerper::setEnd (
    const Container & end
) 
```




<hr>



### function setStart 

```C++
inline void translotator::interpolators::Lerper::setStart (
    const Container & start
) 
```




<hr>



### function updateDiff 

```C++
inline void translotator::interpolators::Lerper::updateDiff () 
```




<hr>



### function ~Lerper 

```C++
translotator::interpolators::Lerper::~Lerper () = default
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/interpolators/Lerp.hpp`

