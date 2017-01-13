#include "stdafx.h"
#include "MyStack.h"


CMyStack::CMyStack() :MyList()
{
}


CMyStack::~CMyStack()
{
}

/************************************
* Access:    public
* 函数功能:  插入新的数据元素e为新栈顶,S的长度加1
*
* 参数列表:
*   ElemType e:  [in] 插入的元素
*
* 返回值:    Status
*
*************************************/
Status CMyStack::Push(ElementType e)
{
	return InsertList(e, 0);
}

/************************************
* Access:    public
* 函数功能:  删除S的栈顶元素,并用e返回其值,S的长度减1
*
* 参数列表:
*   ElemType & e:  [out] 删除的栈顶元素值
*
* 返回值:    Status
*
*************************************/
Status CMyStack::Pop(ElementType & e)
{
	return DeleteList( e,0);
}

/************************************
* Access:    public
* 函数功能:  将S重置为空栈
*
* 参数列表:
*
* 返回值:    Status
*
*************************************/
Status CMyStack::ClearStack()
{
	return ClearList();
}

/************************************
* Access:    public
* 函数功能:  用e返回S中栈顶元素的值
*
* 参数列表:
*   ElemType & e:  [out]查看的栈顶元素值
*
* 返回值:    Status
*
*************************************/
Status CMyStack::GetTop(ElementType & e)
{
	return GetElem(0, e);
}

/************************************
* Access:    public
* 函数功能:  若S为空栈,则返回true,否则返回false
*
* 参数列表:
*   bool & isEmpty:  [out]是否为空
*
* 返回值:    Status
*
*************************************/
Status CMyStack::StackEmpty(bool & isEmpty)
{
	return ListEmpty(isEmpty);
}

/************************************
* Access:    public
* 函数功能:  返回S中元素的个数
*
* 参数列表:
*   int & length:  [out]元素个数
*
* 返回值:    Status
*
*************************************/
Status CMyStack::StackLength(int & length)
{
	return ListLength(length);
}

