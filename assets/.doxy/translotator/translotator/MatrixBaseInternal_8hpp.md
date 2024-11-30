

# File MatrixBaseInternal.hpp



[**FileList**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**translotator**](dir_ffa3503b73a46a1fbf73d754da62ba14.md) **>** [**objects**](dir_d5306d4012edd8106bd4452d9b4e4e98.md) **>** [**MatrixBaseInternal.hpp**](MatrixBaseInternal_8hpp.md)

[Go to the source code of this file](MatrixBaseInternal_8hpp_source.md)
















## Namespaces

| Type | Name |
| ---: | :--- |
| namespace | [**translotator**](namespacetranslotator.md) <br> |
| namespace | [**MatrixBaseInternal**](namespacetranslotator_1_1MatrixBaseInternal.md) <br>_Internal namespace for_ [_**MatrixBase**_](classtranslotator_1_1MatrixBase.md) _implementation._ |


## Classes

| Type | Name |
| ---: | :--- |
| struct | [**operator\_cast\_typemapper**](structtranslotator_1_1MatrixBaseInternal_1_1operator__cast__typemapper.md) &lt;typename Derived, typename NewType&gt;<br> |
| struct | [**operator\_cast\_typemapper&lt; Matrix&lt; N, M, Type &gt;, NewType &gt;**](structtranslotator_1_1MatrixBaseInternal_1_1operator__cast__typemapper_3_01Matrix_3_01N_00_01M_00_01Type_01_4_00_01NewType_01_4.md) &lt;typename NewType, N, M, typename Type&gt;<br> |
| struct | [**operator\_cast\_typemapper&lt; Vector&lt; N, Type &gt;, NewType &gt;**](structtranslotator_1_1MatrixBaseInternal_1_1operator__cast__typemapper_3_01Vector_3_01N_00_01Type_01_4_00_01NewType_01_4.md) &lt;typename NewType, N, typename Type&gt;<br> |
| struct | [**operator\_mul\_typemapper**](structtranslotator_1_1MatrixBaseInternal_1_1operator__mul__typemapper.md) &lt;typename Derived, typename OtherDerived, typename Enable&gt;<br> |
| struct | [**operator\_mul\_typemapper&lt; Derived, OtherDerived, enable\_if\_t&lt; Derived::ROWS !=1 &&OtherDerived::COLS==1, void &gt; &gt;**](structtranslotator_1_1MatrixBaseInternal_1_1operator__mul__typemapper_3_01Derived_00_01OtherDeri1b96ed4aed79df1e494374b57efb0a1d.md) &lt;typename Derived, typename OtherDerived&gt;<br> |
| struct | [**operator\_mul\_typemapper&lt; Derived, OtherDerived, enable\_if\_t&lt; Derived::ROWS !=OtherDerived::COLS &&OtherDerived::COLS !=1, void &gt; &gt;**](structtranslotator_1_1MatrixBaseInternal_1_1operator__mul__typemapper_3_01Derived_00_01OtherDeri2a96eb5bfa413dff0cddca3d951d6a71.md) &lt;typename Derived, typename OtherDerived&gt;<br> |
| struct | [**operator\_mul\_typemapper&lt; Derived, OtherDerived, enable\_if\_t&lt; Derived::ROWS==1 &&OtherDerived::COLS==1, void &gt; &gt;**](structtranslotator_1_1MatrixBaseInternal_1_1operator__mul__typemapper_3_01Derived_00_01OtherDeri96d299f5dadca2759194ea845be7ed5c.md) &lt;typename Derived, typename OtherDerived&gt;<br> |
| struct | [**operator\_mul\_typemapper&lt; Derived, OtherDerived, enable\_if\_t&lt; Derived::ROWS==OtherDerived::COLS &&OtherDerived::COLS !=1, void &gt; &gt;**](structtranslotator_1_1MatrixBaseInternal_1_1operator__mul__typemapper_3_01Derived_00_01OtherDeri416034dcdebb2206f870a9ec06949246.md) &lt;typename Derived, typename OtherDerived&gt;<br> |



















































------------------------------
The documentation for this class was generated from the following file `include/translotator/objects/MatrixBaseInternal.hpp`

