

# Class translotator::interpolators::SlerperFast

**template &lt;typename Container&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**interpolators**](namespacetranslotator_1_1interpolators.md) **>** [**SlerperFast**](classtranslotator_1_1interpolators_1_1SlerperFast.md)



_Slerp for rotation component interpolation class. Faster than_ [_**Slerper**_](classtranslotator_1_1interpolators_1_1Slerper.md) _for S1, S3 group._[More...](#detailed-description)

* `#include <Slerp.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**SlerperFast**](#function-slerperfast-12) () = default<br> |
|   | [**SlerperFast**](#function-slerperfast-22) (const Container & start, const Container & end) <br> |
|  const Container & | [**getEnd**](#function-getend) () const<br> |
|  const Container & | [**getStart**](#function-getstart) () const<br> |
|  Container | [**interpolate**](#function-interpolate) (Type t) const<br>_Slerp operation for_ [_**SlerperFast**_](classtranslotator_1_1interpolators_1_1SlerperFast.md) _._ |
|  Container | [**operator()**](#function-operator()) (Type t) const<br>_Slerp operation for_ [_**SlerperFast**_](classtranslotator_1_1interpolators_1_1SlerperFast.md) _._ |
|  void | [**setEnd**](#function-setend) (const Container & end) <br> |
|  void | [**setStart**](#function-setstart) (const Container & start) <br> |
|  void | [**update\_theta**](#function-update_theta) () <br>_Update theta and shortest\_path._  |
|   | [**~SlerperFast**](#function-slerperfast) () = default<br> |




























# Detailed Description




**Template parameters:**


* `Container` [**Matrix**](classtranslotator_1_1Matrix.md) base type 



**Note:**

Implemented using Exp & Log Lie Group opearation 





    
## Public Functions Documentation




### function SlerperFast [1/2]


```C++
translotator::interpolators::SlerperFast::SlerperFast () = default
```



constructor 


        

<hr>



### function SlerperFast [2/2]

```C++
inline translotator::interpolators::SlerperFast::SlerperFast (
    const Container & start,
    const Container & end
) 
```




<hr>



### function getEnd 

```C++
inline const Container & translotator::interpolators::SlerperFast::getEnd () const
```




<hr>



### function getStart 

```C++
inline const Container & translotator::interpolators::SlerperFast::getStart () const
```




<hr>



### function interpolate 

```C++
inline Container translotator::interpolators::SlerperFast::interpolate (
    Type t
) const
```




<hr>



### function operator() 

```C++
inline Container translotator::interpolators::SlerperFast::operator() (
    Type t
) const
```




<hr>



### function setEnd 

```C++
inline void translotator::interpolators::SlerperFast::setEnd (
    const Container & end
) 
```




<hr>



### function setStart 

```C++
inline void translotator::interpolators::SlerperFast::setStart (
    const Container & start
) 
```




<hr>



### function update\_theta 

_Update theta and shortest\_path._ 
```C++
inline void translotator::interpolators::SlerperFast::update_theta () 
```





**Note:**

Call this function after changing start or end 





        

<hr>



### function ~SlerperFast 

```C++
translotator::interpolators::SlerperFast::~SlerperFast () = default
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/interpolators/Slerp.hpp`

