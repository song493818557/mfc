#include "stdafx.h"
#include "MyList.h"


CMyList::CMyList()
{
	m_nCurrNum = 0;       //当前元素个数
	m_pListHead= nullptr; //指定第一个节点的位置
}


CMyList::~CMyList()
{
	//ClearList();
}

/************************************
* Access:    public 
* 函数功能:  在L中第i个元素位置之前插入新的数据元素e，L的长度加1
* 
* 参数列表:
*   ElementType e:   [in] 插入的新元素
*   int i:           [in] 插入的位置
*   
* 返回值:    Status
* 
*************************************/
Status CMyList::InsertList(ElementType e, int i /*= -1 */)
{
	//1.检查是否满足初始条件
	if (m_pListHead == nullptr)
	{
		m_pListHead = new NODE;
		m_pListHead->data = e;
		m_pListHead->pNext = m_pListHead;
		m_pListHead->pPrev = m_pListHead;

		m_nCurrNum++;
		return RESULT_TRUE;
	}
			
	//2.检查是否传入了正确参数				
	//  2.1 处理参数的特殊值
	if (i==-1)
	{
		i = m_nCurrNum;
	}
	//  2.2 检查参数是否有效
	if (i<0||i>m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}
	//3.实现本函数的功能
	//  在L中第i个元素位置之前插入新的数据元素e，L的长度加1
	//3.1 找到要插入的位置
	/*
	    44,55,**,66,77,88
	       ↑(pPos)
		2
	         
	*/
	//  nPos为要插入位置的前一个元素
	PNODE pPos = m_pListHead;
	for (int pos = 0;pos<i-1;pos++)
	{
		pPos = pPos->pNext;
	}
	//3.2 创建一个新节点
	PNODE pNewNode = new NODE;        //创建新节点 **
	pNewNode->data = e;               //填充数据域
	pNewNode->pPrev = pPos;           //填充指针域pPrev( 上一个节点是 66 )
	pNewNode->pNext = pPos->pNext;    //填充指针域pNext( 下一个节点是 77 )
	//3.3 插入新位置
	pPos->pNext = pNewNode;           //改变插入位置前一个元素的指针域 (后继指针 pNext )
	pPos->pNext->pPrev = pNewNode;    //改变插入位置后一个元素的指针域 (前驱指针 pPrev )

	//3.4 更新数据成员
	m_nCurrNum++;

	return RESULT_TRUE;
}

/************************************
* Access:    public 
* 函数功能:  删除L的第i个数据元素，并用e返回其值，L的长度减1
* 
* 参数列表:
*   ElementType & e:  [out]被删除的元素
*   int i:            [in] 删除的位置
*   
* 返回值:    Status
* 
*************************************/
Status CMyList::DeleteList( ElementType & e, int i/*=-1 */)
{
	//1.检查是否满足初始条件
	if (m_pListHead == nullptr)
	{
		return RESULT_FALSE;
	}
			
	//2.检查是否传入了正确参数				
	//  2.1 处理参数的特殊值
	if (i==-1)
	{
		i = m_nCurrNum - 1;
	}
	//  2.2 检查参数是否有效
	if (i<0||i>=m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}
	//3.实现本函数的功能
	//  删除L的第i个数据元素，并用e返回其值，L的长度减1
	/*
	    44,55,X66X,77,88
	       ↑(pPos)
		2
	         
	*/
	//  nPos为要删除位置的前一个元素

	//3.1 找到删除位置的前一个元素
	PNODE pPos = m_pListHead;
	for (int pos = 0;pos<i-1;pos++)
	{
		pPos = pPos->pNext;
	}
	//3.2 获取返回值
	PNODE delNode = pPos->pNext;        //将要被删除的元素
	e = delNode->data;                  //将要被删除的元素的数据域作为返回值

	//3.3 删除元素
	pPos->pNext = delNode->pNext;       //前一个元素的后继指针,指向待删除元素的后一个元素
	                                    //(这样正向查找的时候就找不到我了)
	delNode->pNext->pPrev = pPos;       //后一个元素的前驱指针,指向待删除元素的前一个元素
										//(这样反向查找的时候就找不到我了)

	delete delNode;

	//4. 更新数据成员
	m_nCurrNum--;
	if (m_nCurrNum==0)
	{
		m_pListHead = nullptr;
	}

	return RESULT_TRUE;
}
