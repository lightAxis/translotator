

# Struct translotator::initializer\_list

**template &lt;size\_t N, typename Type&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**initializer\_list**](structtranslotator_1_1initializer__list.md)



[_**initializer\_list**_](structtranslotator_1_1initializer__list.md) _struct_[More...](#detailed-description)

* `#include <initializer_list.hpp>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  Type | [**data**](#variable-data)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**initializer\_list**](#function-initializer_list) (Args... args) <br> |




























# Detailed Description




**Template parameters:**


* `N` size of the list 
* `Type` type of the list

This struct is used to initialize the list with the same type and size. Usaully used for matrix-based object's initialization. 


    
## Public Attributes Documentation




### variable data 

```C++
Type translotator::initializer_list< N, Type >::data[N];
```




<hr>
## Public Functions Documentation




### function initializer\_list 

```C++
template<typename... Args>
inline translotator::initializer_list::initializer_list (
    Args... args
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/initializer_list.hpp`

