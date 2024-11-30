

# Namespace translotator::interpolators



[**Namespace List**](namespaces.md) **>** [**translotator**](namespacetranslotator.md) **>** [**interpolators**](namespacetranslotator_1_1interpolators.md)




















## Classes

| Type | Name |
| ---: | :--- |
| class | [**Lerper**](classtranslotator_1_1interpolators_1_1Lerper.md) &lt;typename Container&gt;<br>_Linear interpolation class._  |
| class | [**ScLerper**](classtranslotator_1_1interpolators_1_1ScLerper.md) &lt;typename Container&gt;<br>_Screw linear interpolation class._  |
| class | [**SlerpLerper**](classtranslotator_1_1interpolators_1_1SlerpLerper.md) &lt;typename Container&gt;<br>_Slerp for rotation component, lerp for translation component class._  |
| class | [**Slerper**](classtranslotator_1_1interpolators_1_1Slerper.md) &lt;typename Container&gt;<br>_Slerp for rotation component interpolation class._  |
| class | [**SlerperFast**](classtranslotator_1_1interpolators_1_1SlerperFast.md) &lt;typename Container&gt;<br>_Slerp for rotation component interpolation class. Faster than_ [_**Slerper**_](classtranslotator_1_1interpolators_1_1Slerper.md) _for S1, S3 group._ |






















## Public Functions

| Type | Name |
| ---: | :--- |
|  Container | [**LerpDiff**](#function-lerpdiff) (const Container & start, const Container & end) <br>_Linear interpolation._  |
|  Container | [**Lerping**](#function-lerping) (const Container & start, const Container & end, typename Container::DATATYPE t) <br>_Linear interpolation._  |
|  auto | [**ScLerpDiff**](#function-sclerpdiff) (const Container & start, const Container & end) <br>_Screw linear interpolation._  |
|  auto | [**ScLerping**](#function-sclerping) (const Container & start, const Container & end, Type t) <br> |
|  auto | [**SlerpDiff**](#function-slerpdiff) (const Container & start, const Container & end) <br> |
|  auto | [**SlerpLerpDiff**](#function-slerplerpdiff) (const Container & start, const Container & end) <br>_Slerp for rotation component, lerp for translation component between start and end._  |
|  auto | [**SlerpLerping**](#function-slerplerping) (const Container & start, const Container & end, Type t) <br>_Slerp for rotation component, lerp for translation component interpolation._  |
|  auto | [**Slerping**](#function-slerping) (const Container & start, const Container & end, Type t) <br>_Slerp for rotation component interpolation._  |




























## Public Functions Documentation




### function LerpDiff 

_Linear interpolation._ 
```C++
template<typename Container>
Container translotator::interpolators::LerpDiff (
    const Container & start,
    const Container & end
) 
```





**Template parameters:**


* `Container` [**Matrix**](classtranslotator_1_1Matrix.md) base type 



**Returns:**

Linear difference between start and end 





        

<hr>



### function Lerping 

_Linear interpolation._ 
```C++
template<typename Container>
Container translotator::interpolators::Lerping (
    const Container & start,
    const Container & end,
    typename Container::DATATYPE t
) 
```





**Template parameters:**


* `Container` [**Matrix**](classtranslotator_1_1Matrix.md) base type 



**Returns:**

Linear interpolation between start and end 





        

<hr>



### function ScLerpDiff 

_Screw linear interpolation._ 
```C++
template<typename Container>
auto translotator::interpolators::ScLerpDiff (
    const Container & start,
    const Container & end
) 
```





**Template parameters:**


* `Container` [**Matrix**](classtranslotator_1_1Matrix.md) base type 



**Returns:**

Screw linear difference between start and end 





        

<hr>



### function ScLerping 

```C++
template<typename Container, typename Type>
auto translotator::interpolators::ScLerping (
    const Container & start,
    const Container & end,
    Type t
) 
```




<hr>



### function SlerpDiff 

```C++
template<typename Container>
auto translotator::interpolators::SlerpDiff (
    const Container & start,
    const Container & end
) 
```




<hr>



### function SlerpLerpDiff 

_Slerp for rotation component, lerp for translation component between start and end._ 
```C++
template<typename Container>
auto translotator::interpolators::SlerpLerpDiff (
    const Container & start,
    const Container & end
) 
```





**Template parameters:**


* `Container` [**Matrix**](classtranslotator_1_1Matrix.md) base type 



**Returns:**

difference between start and end 





        

<hr>



### function SlerpLerping 

_Slerp for rotation component, lerp for translation component interpolation._ 
```C++
template<typename Container, typename Type>
auto translotator::interpolators::SlerpLerping (
    const Container & start,
    const Container & end,
    Type t
) 
```





**Template parameters:**


* `Container` [**Matrix**](classtranslotator_1_1Matrix.md) base type 



**Returns:**

Slerp linear interpolation between start and end 





        

<hr>



### function Slerping 

_Slerp for rotation component interpolation._ 
```C++
template<typename Container, typename Type>
auto translotator::interpolators::Slerping (
    const Container & start,
    const Container & end,
    Type t
) 
```





**Template parameters:**


* `Container` [**Matrix**](classtranslotator_1_1Matrix.md) base type 



**Returns:**

Slerp linear interpolation between start and end 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/interpolators/Lerp.hpp`

