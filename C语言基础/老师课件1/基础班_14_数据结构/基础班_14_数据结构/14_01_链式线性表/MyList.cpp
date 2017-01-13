#include "stdafx.h"
#include "MyList.h"


CMyList::CMyList()
{
	m_nCurrNum = 0;       //当前元素个数
	m_pListHead= nullptr; //指定第一个节点的位置
}


CMyList::~CMyList()
{
	ClearList();
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
	if (i==-1)				//插入到链表的尾节点之后
	{
		i = m_nCurrNum;
	}
	bool isNewHead = false;
	if (i==0)				//插入到链表的头节点之前
	{
		i = m_nCurrNum;     //循环链表中 头节点的前一个节点为尾节点
		isNewHead = true;   //需要更换头节点指针
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
	pNewNode->pNext->pPrev = pNewNode;//改变插入位置后一个元素的指针域 (前驱指针 pPrev )

	//3.4 更新数据成员
	m_nCurrNum++;
	if (isNewHead)
	{
		m_pListHead = pNewNode;
	}
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
	if (i == -1)			                //删除链表的尾节点
	{
		i = m_nCurrNum - 1;
	}
	if (i == 0)								//删除链表的头节点
	{
		//2.1.1 获取返回值
		PNODE pPos    = m_pListHead->pPrev; //要删除位置的前一个元素
		PNODE delNode = m_pListHead;        //将要被删除的元素
		e = delNode->data;                  //将要被删除的元素的数据域作为返回值

		//2.1.2 删除元素
		pPos->pNext = delNode->pNext;       //前一个元素的后继指针,指向待删除元素的后一个元素
											//(这样正向查找的时候就找不到我了)
		delNode->pNext->pPrev = pPos;       //后一个元素的前驱指针,指向待删除元素的前一个元素
											//(这样反向查找的时候就找不到我了)

		delete delNode;

		//2.1.3 更新数据成员
		m_pListHead = pPos->pNext;          //循环链表中 头节点的前一个节点为尾节点
		m_nCurrNum--;   
		return RESULT_TRUE;
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

/************************************
* Access:    public 
* 函数功能:  将List重置为空表
* 
* 参数列表:
*   
* 返回值:    Status
* 
*************************************/
Status CMyList::ClearList( )
{
	//1.检查是否满足初始条件
	if (m_pListHead == nullptr)
	{
		return RESULT_FALSE;
	}
	//2.检查是否传入了正确参数				
	//  2.1 处理参数的特殊值
	//  2.2 检查参数是否有效

	//3.实现本函数的功能
	//  将List重置为空表
	PNODE TempNode = m_pListHead;
	for (int i = 0; i < m_nCurrNum; i++)
	{
		PNODE DelNode = TempNode ;
		TempNode = TempNode->pNext;
		delete DelNode;
	}

	//4. 更新数据成员
	m_nCurrNum = 0;
	m_pListHead = nullptr;

	return RESULT_TRUE;
}

/************************************
* Access:    public 
* 函数功能:  线性表是否为空
* 
* 参数列表:
*   bool & isEmpty: [out] 是否为空
*   
* 返回值:    Status
* 
*************************************/
Status CMyList::ListEmpty( bool & isEmpty )
{
	//1.检查是否满足初始条件
	if (m_pListHead == nullptr)
	{
		isEmpty = true;
		return RESULT_FALSE;
	}
	//2.线性表是否为空
	if (m_nCurrNum == 0)
	{
		isEmpty = true;
	}
	else {
		isEmpty = false;
	}
	return RESULT_TRUE;
}

/************************************
* Access:    public 
* 函数功能:  线性表中元素的个数
* 
* 参数列表:
*   int & length:  [out] 长度
*   
* 返回值:    Status
* 
*************************************/
Status CMyList::ListLength(int & length )
{
	//1.检查是否满足初始条件
	if (m_pListHead == nullptr)
	{
		length = 0;
		return RESULT_FALSE;
	}
	//2.检查是否传入了正确参数				
	//  2.1 处理参数的特殊值
	//  2.2 检查参数是否有效

	//3.实现本函数的功能
	//  线性表中元素的个数
	length = m_nCurrNum;
	return RESULT_TRUE;
}

/************************************
* Access:    public 
* 函数功能:  获取线性表中指定位置上的元素
* 
* 参数列表:
*   int i:            [in] 获取哪个位置上的元素
*   ElementType & e:  [out]获取的元素值
*   
* 返回值:    Status
* 
*************************************/
Status CMyList::GetElem( int i,  ElementType & e )
{
	//1.检查是否满足初始条件
	if (m_pListHead == nullptr)
	{
		return RESULT_FALSE;
	}
	//2.检查是否传入了正确参数				
	//  2.1 处理参数的特殊值
	//  2.2 检查参数是否有效
	if (i < 0 || i >= m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}
	//3.实现本函数的功能
	PNODE pFindNode = m_pListHead;
	for (int j = 0; j < i; j++)
	{
		pFindNode = pFindNode->pNext;
	}
	//4.设置返回值
	e = pFindNode->data;

	return RESULT_TRUE;
}

/************************************
* Access:    public 
* 函数功能:  返回线性表中从指定位置开始,找到的第一个与e相等的元素下标(没找到返回-1)
* 
* 参数列表:
*   int i:          [in] 从哪个位置开始找
*   ElementType e:  [in] 找哪个值 
*   int & pos:      [out]该值所在位置
*   
* 返回值:    Status
* 
*************************************/
Status CMyList::LocateElem( int i, ElementType e, int & pos )
{
	//1.检查是否满足初始条件
	if (m_pListHead == nullptr)
	{
		return RESULT_FALSE;
	}
	//2.检查是否传入了正确参数				
	//  2.1 index是否越界
	if (i < 0 || i >= m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}

	//3.返回线性表中从指定位置开始,
	//      找到的第一个与e相等的元素下标
	//      (没找到返回 - 1)
	pos = -1;
	PNODE pFindNode = m_pListHead;
	for (int j = 0; j < m_nCurrNum; j++)
	{
		if (pFindNode->data == e && j <= i)
		{
			pos = i;
			break;
		}
		pFindNode = pFindNode->pNext;
	}

	return RESULT_TRUE;
}

/************************************
* Access:    public 
* 函数功能:  替换(设置)线性表中第i个元素的值
* 
* 参数列表:
*   int i:           [in] 替换哪个位置
*   ElementType e:   [in] 替换成什么值
*   
* 返回值:    Status
* 
*************************************/
Status CMyList::SetElem( int i, ElementType e)
{
	//1.检查是否满足初始条件
	if (m_pListHead == nullptr)
	{
		return RESULT_FALSE;
	}
	//2.检查是否传入了正确参数				
	//  2.1 index是否越界
	if (i < 0 || i >= m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}
	//3.替换(设置)线性表中第i个元素的值
	PNODE pFindNode = m_pListHead;
	for (int j = 0; j < i;j++)
	{
		pFindNode = pFindNode->pNext;
	}
	pFindNode->data = e;//如果保存的不是基本类型,需要重载"="号

	return RESULT_TRUE;
}
