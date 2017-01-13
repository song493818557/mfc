#pragma once
#include <iostream>
using std::cout;
template <typename T>
class CLinkList
{
public:
	typedef struct _NODE
	{
		T Data;
		_NODE* pNext;
	}NODE, *PNODE;
public:
	CLinkList();
	~CLinkList();
	bool InsertEle(int nLoc, T nData);
	bool DeleteEle(int nLoc, T& nData);
	void printfAll()
	{
		if (m_pHead == NULL)
		{
			return;
		}
		NODE* pTemp = m_pHead;
		for (int i = 0; i < m_Lenth; i++)
		{
			cout << pTemp->Data;
			pTemp = pTemp->pNext;
		}
	}
private:
	NODE * m_pHead;
	int m_Lenth;
};
template <typename T>
CLinkList<T>::CLinkList() :m_pHead(NULL), m_Lenth(0)
{

}
template <typename T>
CLinkList<T>::~CLinkList()
{
}
/******************************
*函数名:InsertEle(int nLoc, int nData)
*作用:  在链表中插入一个数据
*参数1: 插入的位置
*参数2: 插入的元素
*返回值:为false，代表失败，为true，代表成功
******************************/
template <typename T>
bool CLinkList<T>::InsertEle(int nLoc, T nData)
{
	//1 nloc> m_Lenth,位置不对
	if (nLoc>m_Lenth)
	{
		return false;
	}
	//2 如果当前链表为空 
	if (m_Lenth == 0 || nLoc == 0)
	{
		/*m_pHead = new NODE;
		m_pHead->Data = nData;
		m_pHead->pNext = NULL;
		m_Lenth++;
		return true;*/
		NODE *pNewNode = new NODE;
		pNewNode->Data = nData;
		pNewNode->pNext = m_pHead;
		m_pHead = pNewNode;
		m_Lenth++;
		return true;
	}
	//3 假如是在0这个位置插入
	//if (nLoc == 0)
	//{
	//	NODE *pNewNode = new NODE;
	//	pNewNode->Data = nData;
	//	pNewNode->pNext = m_pHead;
	//	m_pHead = pNewNode;
	//	m_Lenth++;
	//	return true;
	//}



	//4 开始在链表中插入数据
	NODE *pTemp = m_pHead;
	for (int i = 0; i < nLoc - 1; i++)
	{
		pTemp = pTemp->pNext;
	}
	NODE *pNewNode = new NODE;
	pNewNode->Data = nData;
	pNewNode->pNext = pTemp->pNext;
	pTemp->pNext = pNewNode;
	m_Lenth++;
	return true;
}

/******************************
*函数名:bool DeleteEle(int nLoc, int& nData)
*作用:  在链表中根据位置删除一个数据
*参数1: 要删除的位置
*参数2: 传出被删除的数据
*返回值:为false，代表失败，为true，代表成功
******************************/
template <typename T>
bool CLinkList<T>::DeleteEle(int nLoc, T& nData)
{
	//1 nloc> m_Lenth,位置不对
	if (nLoc >= m_Lenth)
	{
		return false;
	}
	//2 开始删除
	//2.1删除的是头节点
	if (nLoc == 0)
	{
		NODE *pTemp = m_pHead;
		m_pHead = m_pHead->pNext;
		nData = pTemp->Data;
		delete pTemp;
		m_Lenth--;
		return true;
	}
	//删除的是普通节点
	//2.2 开始在链表中删除数据，首先找被删除点的前一个点
	NODE *pTemp = m_pHead;
	for (int i = 0; i < nLoc - 1; i++)
	{
		pTemp = pTemp->pNext;
	}
	////保存被删除的点
	//NODE* pDeleteNode = pTemp->pNext;
	////让被删除点的前一点的指针指向被删除点的后一点
	//pTemp->pNext = pTemp->pNext->pNext;
	////释放空间
	//delete pDeleteNode;

	NODE* pDeleteNode = pTemp->pNext;
	pTemp->pNext = pDeleteNode->pNext;//含义和上面的语句是一样的。
	nData = pDeleteNode->Data;
	delete pDeleteNode;
	m_Lenth--;
	return true;
}
