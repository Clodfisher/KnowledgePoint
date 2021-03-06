测试例子，用于说明，数组指针类型，与数组名之间的关系        
***
*说明*：    
在_BUF中，成员p为指针常量，它并不存在存储指针类型的存储空间，此时_BUF类型的存储空间的位宽为32位（仅仅是_I类型数据存储空间的宽度）。而在_BUF1中，成员p1为指针类型的数据存储空间。如果指针为32位宽，则一个_BUF1类型的存储空间的位宽为64位，其中p1这个指针类型的存储空间占用了32位。另一个_BUF2类型的存储空间的位宽也为64位，虽然p2这个指针常量本身并不存在存储空间，但其指向了拥有1个单元的无符号32位整型连续存储空间，这个连续存储空间属于_BUF2。

我们再次整理上述3种类型中p、p1、p2的异同。

相同点如下。

·p、p1、p2均是上述3种结构体类型的成员。

·p和p2均是指针常量，它们的数值并不存在于具体的空间中。这些数值通过所在结构体数据存储空间的地址获得。

·p1和p2对应在结构体内都存在具体的存储空间。

不同点如下。

·虽然p和p2一样都是指针常量，但由于结构体内不存在空间与它对应，因此它指向_BUF类型存储空间的后续地址。p2则指向_BUF2类型存储空间内部的某个地址。

·_BUF1的p1为数据，存在存储空间，它可指向任意位置。_BUF2的p2所指向的位置不可改变。    

**若读完笔记还是不太了解原因可参考下一连接**：        
[左耳朵耗子--C语言结构体里的成员数组和指针](http://coolshell.cn/articles/11377.html)    

  