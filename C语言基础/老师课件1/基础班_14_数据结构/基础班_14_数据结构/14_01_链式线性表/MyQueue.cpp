#include "stdafx.h"
#include "MyQueue.h"


CMyQueue::CMyQueue()
{
}


CMyQueue::~CMyQueue()
{
}

/************************************
* Access:    public 
* 函数功能:  插入新的数据元素e为新队尾,Q的长度加1
* 
* 参数列表:
*   ElementType e: [in] 新插入元素的值
*   
* 返回值:    Status
* 
*************************************/
Status CMyQueue::EnQueue( ElementType e )
{
	return InsertList(e);
}

/************************************
* Access:    public 
* 函数功能:  删除Q的队头元素,并用e返回其值,Q的长度减1
* 
* 参数列表:
*   ElementType & e:  [out]被删除元素的值
*   
* 返回值:    Status
* 
*************************************/
Status CMyQueue::DeQueue( ElementType & e )
{
	return DeleteList(e,0);
}

/************************************
* Access:    public 
* 函数功能:  将Q重置为空队列
* 
* 参数列表:
*   
* 返回值:    Status
* 
*************************************/
Status CMyQueue::ClearQueue()
{
	return ClearList();
}

/************************************
* Access:    public 
* 函数功能:  用e返回Q中队头元素的值
* 
* 参数列表:
*   ElementType & e:   [out] 队头元素的值
*   
* 返回值:    Status
* 
*************************************/
Status CMyQueue::GetHead( ElementType & e )
{
	return GetElem(0, e);
}

/************************************
* Access:    public 
* 函数功能:  返回Q中元素个数
* 
* 参数列表:
*   int & length:  [out] 元素个数
*   
* 返回值:    Status
* 
*************************************/
Status CMyQueue::QueueLength( int & length )
{
	ListLength(length);
}

/************************************
* Access:    public 
* 函数功能:  若Q为空队列,则返回true,否则返回false
* 
* 参数列表:
*   bool & isEmpty:  [out] 是否为空
*   
* 返回值:    Status
* 
*************************************/
Status CMyQueue::QueueEmpty( bool & isEmpty )
{
	ListEmpty(isEmpty);
}
