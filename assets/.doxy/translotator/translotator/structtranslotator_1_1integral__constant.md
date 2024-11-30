

# Struct translotator::integral\_constant

**template &lt;typename T, T v&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**integral\_constant**](structtranslotator_1_1integral__constant.md)










Inherited by the following classes: [translotator::is\_float](structtranslotator_1_1is__float.md),  [translotator::is\_float&lt; double &gt;](structtranslotator_1_1is__float_3_01double_01_4.md),  [translotator::is\_float&lt; float &gt;](structtranslotator_1_1is__float_3_01float_01_4.md),  [translotator::is\_float&lt; long double &gt;](structtranslotator_1_1is__float_3_01long_01double_01_4.md),  [translotator::is\_matrix\_base](structtranslotator_1_1is__matrix__base.md),  [translotator::is\_matrix\_base&lt; T, typename enable\_if&lt; T::MATRIX\_BASE &gt;::type &gt;](structtranslotator_1_1is__matrix__base_3_01T_00_01typename_01enable__if_3_01T_1_1MATRIX__BASE_01_4_1_1type_01_4.md),  [translotator::is\_same](structtranslotator_1_1is__same.md),  [translotator::is\_same&lt; T, T &gt;](structtranslotator_1_1is__same_3_01T_00_01T_01_4.md)












## Public Types

| Type | Name |
| ---: | :--- |
| typedef [**integral\_constant**](structtranslotator_1_1integral__constant.md) | [**type**](#typedef-type)  <br> |
| typedef T | [**value\_type**](#typedef-value_type)  <br> |






## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr T | [**value**](#variable-value)   = = v<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  constexpr | [**operator value\_type**](#function-operator-value_type) () noexcept const<br> |
|  constexpr value\_type | [**operator()**](#function-operator()) () noexcept const<br> |




























## Public Types Documentation




### typedef type 

```C++
using translotator::integral_constant< T, v >::type =  integral_constant;
```




<hr>



### typedef value\_type 

```C++
using translotator::integral_constant< T, v >::value_type =  T;
```




<hr>
## Public Static Attributes Documentation




### variable value 

```C++
constexpr T translotator::integral_constant< T, v >::value;
```




<hr>
## Public Functions Documentation




### function operator value\_type 

```C++
inline constexpr translotator::integral_constant::operator value_type () noexcept const
```




<hr>



### function operator() 

```C++
inline constexpr value_type translotator::integral_constant::operator() () noexcept const
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/utils/micro_type_traits.hpp`

