

# Struct translotator::MatrixBaseInternal::operator\_mul\_typemapper&lt; Derived, OtherDerived, enable\_if\_t&lt; Derived::ROWS==OtherDerived::COLS &&OtherDerived::COLS !=1, void &gt; &gt;

**template &lt;typename Derived, typename OtherDerived&gt;**



[**ClassList**](annotated.md) **>** [**translotator**](namespacetranslotator.md) **>** [**MatrixBaseInternal**](namespacetranslotator_1_1MatrixBaseInternal.md) **>** [**operator\_mul\_typemapper&lt; Derived, OtherDerived, enable\_if\_t&lt; Derived::ROWS==OtherDerived::COLS &&OtherDerived::COLS !=1, void &gt; &gt;**](structtranslotator_1_1MatrixBaseInternal_1_1operator__mul__typemapper_3_01Derived_00_01OtherDeri416034dcdebb2206f870a9ec06949246.md)






















## Public Types

| Type | Name |
| ---: | :--- |
| typedef [**SquareMatrix**](classtranslotator_1_1SquareMatrix.md)&lt; Derived::ROWS, typename Derived::DATATYPE &gt; | [**type**](#typedef-type)  <br> |
















































## Public Types Documentation




### typedef type 

```C++
using translotator::MatrixBaseInternal::operator_mul_typemapper< Derived, OtherDerived, enable_if_t< Derived::ROWS==OtherDerived::COLS &&OtherDerived::COLS !=1, void > >::type =  SquareMatrix<Derived::ROWS, typename Derived::DATATYPE>;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/MatrixBaseInternal.hpp`
