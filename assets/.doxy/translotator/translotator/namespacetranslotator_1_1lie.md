

# Namespace translotator::lie



[**Namespace List**](namespaces.md) **>** [**translotator**](namespacetranslotator.md) **>** [**lie**](namespacetranslotator_1_1lie.md)



_Namespace for Lie Group and Algebra Operations._ 
















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**LieOperator**](structtranslotator_1_1lie_1_1LieOperator.md) &lt;oType, typename dataType&gt;<br>_Lie Operator for Lie Group and Lie Algebra._  |
| struct | [**LieOperator&lt; ObjectType::SE\_GROUP, Type &gt;**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1SE__GROUP_00_01Type_01_4.md) &lt;typename Type&gt;<br>_Lie Operator for SE._  |
| struct | [**LieOperator&lt; ObjectType::SO\_GROUP, Type &gt;**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1SO__GROUP_00_01Type_01_4.md) &lt;typename Type&gt;<br>_Special Orthogonal Group._  |
| struct | [**LieOperator&lt; ObjectType::UNIT\_COMPLEX\_NUM, Type &gt;**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1UNIT__COMPLEX__NUM_00_01Type_01_4.md) &lt;typename Type&gt;<br>_Lie Operator for S1._  |
| struct | [**LieOperator&lt; ObjectType::UNIT\_QUATERNION, Type &gt;**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1UNIT__QUATERNION_00_01Type_01_4.md) &lt;typename Type&gt;<br>_Lie Operator for S3._  |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef [**LieOperator**](structtranslotator_1_1lie_1_1LieOperator.md)&lt; ObjectType::UNIT\_COMPLEX\_NUM, Type &gt; | [**LieOperator\_S1**](#typedef-lieoperator_s1)  <br> |
| typedef [**LieOperator\_S1**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1UNIT__COMPLEX__NUM_00_01Type_01_4.md)&lt; double &gt; | [**LieOperator\_S1d**](#typedef-lieoperator_s1d)  <br> |
| typedef [**LieOperator\_S1**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1UNIT__COMPLEX__NUM_00_01Type_01_4.md)&lt; float &gt; | [**LieOperator\_S1f**](#typedef-lieoperator_s1f)  <br> |
| typedef [**LieOperator\_S1**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1UNIT__COMPLEX__NUM_00_01Type_01_4.md)&lt; long double &gt; | [**LieOperator\_S1ld**](#typedef-lieoperator_s1ld)  <br> |
| typedef [**LieOperator**](structtranslotator_1_1lie_1_1LieOperator.md)&lt; ObjectType::UNIT\_QUATERNION, Type &gt; | [**LieOperator\_S3**](#typedef-lieoperator_s3)  <br> |
| typedef [**LieOperator\_S3**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1UNIT__QUATERNION_00_01Type_01_4.md)&lt; double &gt; | [**LieOperator\_S3d**](#typedef-lieoperator_s3d)  <br> |
| typedef [**LieOperator\_S3**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1UNIT__QUATERNION_00_01Type_01_4.md)&lt; float &gt; | [**LieOperator\_S3f**](#typedef-lieoperator_s3f)  <br> |
| typedef [**LieOperator\_S3**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1UNIT__QUATERNION_00_01Type_01_4.md)&lt; long double &gt; | [**LieOperator\_S3ld**](#typedef-lieoperator_s3ld)  <br> |
| typedef [**LieOperator**](structtranslotator_1_1lie_1_1LieOperator.md)&lt; ObjectType::SE\_GROUP, Type &gt; | [**LieOperator\_SE**](#typedef-lieoperator_se)  <br> |
| typedef [**LieOperator\_SE**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1SE__GROUP_00_01Type_01_4.md)&lt; double &gt; | [**LieOperator\_SEd**](#typedef-lieoperator_sed)  <br> |
| typedef [**LieOperator\_SE**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1SE__GROUP_00_01Type_01_4.md)&lt; float &gt; | [**LieOperator\_SEf**](#typedef-lieoperator_sef)  <br> |
| typedef [**LieOperator\_SE**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1SE__GROUP_00_01Type_01_4.md)&lt; long double &gt; | [**LieOperator\_SEld**](#typedef-lieoperator_seld)  <br> |
| typedef [**LieOperator**](structtranslotator_1_1lie_1_1LieOperator.md)&lt; ObjectType::SO\_GROUP, Type &gt; | [**LieOperator\_SO**](#typedef-lieoperator_so)  <br> |
| typedef [**LieOperator\_SO**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1SO__GROUP_00_01Type_01_4.md)&lt; double &gt; | [**LieOperator\_SOd**](#typedef-lieoperator_sod)  <br> |
| typedef [**LieOperator\_SO**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1SO__GROUP_00_01Type_01_4.md)&lt; float &gt; | [**LieOperator\_SOf**](#typedef-lieoperator_sof)  <br> |
| typedef [**LieOperator\_SO**](structtranslotator_1_1lie_1_1LieOperator_3_01ObjectType_1_1SO__GROUP_00_01Type_01_4.md)&lt; long double &gt; | [**LieOperator\_SOld**](#typedef-lieoperator_sold)  <br> |
















































## Public Types Documentation




### typedef LieOperator\_S1 

```C++
using translotator::lie::LieOperator_S1 = typedef LieOperator<ObjectType::UNIT_COMPLEX_NUM, Type>;
```




<hr>



### typedef LieOperator\_S1d 

```C++
using translotator::lie::LieOperator_S1d = typedef LieOperator_S1<double>;
```




<hr>



### typedef LieOperator\_S1f 

```C++
using translotator::lie::LieOperator_S1f = typedef LieOperator_S1<float>;
```




<hr>



### typedef LieOperator\_S1ld 

```C++
using translotator::lie::LieOperator_S1ld = typedef LieOperator_S1<long double>;
```




<hr>



### typedef LieOperator\_S3 

```C++
using translotator::lie::LieOperator_S3 = typedef LieOperator<ObjectType::UNIT_QUATERNION, Type>;
```




<hr>



### typedef LieOperator\_S3d 

```C++
using translotator::lie::LieOperator_S3d = typedef LieOperator_S3<double>;
```




<hr>



### typedef LieOperator\_S3f 

```C++
using translotator::lie::LieOperator_S3f = typedef LieOperator_S3<float>;
```




<hr>



### typedef LieOperator\_S3ld 

```C++
using translotator::lie::LieOperator_S3ld = typedef LieOperator_S3<long double>;
```




<hr>



### typedef LieOperator\_SE 

```C++
using translotator::lie::LieOperator_SE = typedef LieOperator<ObjectType::SE_GROUP, Type>;
```




<hr>



### typedef LieOperator\_SEd 

```C++
using translotator::lie::LieOperator_SEd = typedef LieOperator_SE<double>;
```




<hr>



### typedef LieOperator\_SEf 

```C++
using translotator::lie::LieOperator_SEf = typedef LieOperator_SE<float>;
```




<hr>



### typedef LieOperator\_SEld 

```C++
using translotator::lie::LieOperator_SEld = typedef LieOperator_SE<long double>;
```




<hr>



### typedef LieOperator\_SO 

```C++
using translotator::lie::LieOperator_SO = typedef LieOperator<ObjectType::SO_GROUP, Type>;
```




<hr>



### typedef LieOperator\_SOd 

```C++
using translotator::lie::LieOperator_SOd = typedef LieOperator_SO<double>;
```




<hr>



### typedef LieOperator\_SOf 

```C++
using translotator::lie::LieOperator_SOf = typedef LieOperator_SO<float>;
```




<hr>



### typedef LieOperator\_SOld 

```C++
using translotator::lie::LieOperator_SOld = typedef LieOperator_SO<long double>;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/translotator/lie/LieOperator.hpp`

