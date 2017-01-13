#pragma once
#include "MyList.h"

class CMyStack:protected CMyList
{
public:
	CMyStack();
	~CMyStack();

	//     Status InitStack( /**构造一个空栈*/
	//         );
	Status Push(      /**插入新的数据元素e为新栈顶,S的长度加1*/
		ElementType e     //[in] 插入的元素
		);
	Status Pop(       /**删除S的栈顶元素,并用e返回其值,S的长度减1*/
		ElementType & e   //[out] 删除的栈顶元素值
		);
	Status ClearStack(/**将S重置为空栈*/
		);
	Status GetTop(    /**用e返回S中栈顶元素的值*/
		ElementType & e   //[out]查看的栈顶元素值
		);
	Status StackEmpty(/**若S为空栈,则返回true,否则返回false*/
		bool & isEmpty //[out]是否为空
		);
	Status StackLength(/**返回S中元素的个数*/
		int & length    //[out]元素个数
		);
};


