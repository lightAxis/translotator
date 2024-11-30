

# Namespace translotator::EULER\_CONSTEXPR



[**Namespace List**](namespaces.md) **>** [**translotator**](namespacetranslotator.md) **>** [**EULER\_CONSTEXPR**](namespacetranslotator_1_1EULER__CONSTEXPR.md)



_Namespace for Euler Order constexpr functions._ 






































## Public Functions

| Type | Name |
| ---: | :--- |
|  constexpr AXIS | [**AXIS\_AT**](#function-axis_at) () noexcept<br>_Get the axis at Nth index in the euler order._  |
|  constexpr size\_t | [**AXIS\_IDX\_AT**](#function-axis_idx_at) () noexcept<br>_Get the index of the axis at Nth index in the euler order._  |
|  constexpr size\_t | [**AXIS\_TO\_IDX**](#function-axis_to_idx) () noexcept<br>_Get the index of the axis in the euler order._  |




























## Public Functions Documentation




### function AXIS\_AT 

_Get the axis at Nth index in the euler order._ 
```C++
template<size_t N, EULER_ORDER Order>
constexpr AXIS translotator::EULER_CONSTEXPR::AXIS_AT () noexcept
```





**Template parameters:**


* `N` Nth index 
* `Order` Euler order 



**Returns:**

Axis at Nth index 





        

<hr>



### function AXIS\_IDX\_AT 

_Get the index of the axis at Nth index in the euler order._ 
```C++
template<size_t N, EULER_ORDER Order>
constexpr size_t translotator::EULER_CONSTEXPR::AXIS_IDX_AT () noexcept
```





**Template parameters:**


* `N` Nth index 
* `Order` Euler order 



**Returns:**

Index of the axis 





        

<hr>



### function AXIS\_TO\_IDX 

_Get the index of the axis in the euler order._ 
```C++
template<AXIS Axis>
constexpr size_t translotator::EULER_CONSTEXPR::AXIS_TO_IDX () noexcept
```





**Template parameters:**


* `Axis` Axis 
* `Order` Euler order 



**Returns:**

Index of the axis 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/objectdefs.hpp`

