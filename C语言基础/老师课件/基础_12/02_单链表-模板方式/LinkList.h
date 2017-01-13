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
*������:InsertEle(int nLoc, int nData)
*����:  �������в���һ������
*����1: �����λ��
*����2: �����Ԫ��
*����ֵ:Ϊfalse������ʧ�ܣ�Ϊtrue������ɹ�
******************************/
template <typename T>
bool CLinkList<T>::InsertEle(int nLoc, T nData)
{
	//1 nloc> m_Lenth,λ�ò���
	if (nLoc>m_Lenth)
	{
		return false;
	}
	//2 �����ǰ����Ϊ�� 
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
	//3 ��������0���λ�ò���
	//if (nLoc == 0)
	//{
	//	NODE *pNewNode = new NODE;
	//	pNewNode->Data = nData;
	//	pNewNode->pNext = m_pHead;
	//	m_pHead = pNewNode;
	//	m_Lenth++;
	//	return true;
	//}



	//4 ��ʼ�������в�������
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
*������:bool DeleteEle(int nLoc, int& nData)
*����:  �������и���λ��ɾ��һ������
*����1: Ҫɾ����λ��
*����2: ������ɾ��������
*����ֵ:Ϊfalse������ʧ�ܣ�Ϊtrue������ɹ�
******************************/
template <typename T>
bool CLinkList<T>::DeleteEle(int nLoc, T& nData)
{
	//1 nloc> m_Lenth,λ�ò���
	if (nLoc >= m_Lenth)
	{
		return false;
	}
	//2 ��ʼɾ��
	//2.1ɾ������ͷ�ڵ�
	if (nLoc == 0)
	{
		NODE *pTemp = m_pHead;
		m_pHead = m_pHead->pNext;
		nData = pTemp->Data;
		delete pTemp;
		m_Lenth--;
		return true;
	}
	//ɾ��������ͨ�ڵ�
	//2.2 ��ʼ��������ɾ�����ݣ������ұ�ɾ�����ǰһ����
	NODE *pTemp = m_pHead;
	for (int i = 0; i < nLoc - 1; i++)
	{
		pTemp = pTemp->pNext;
	}
	////���汻ɾ���ĵ�
	//NODE* pDeleteNode = pTemp->pNext;
	////�ñ�ɾ�����ǰһ���ָ��ָ��ɾ����ĺ�һ��
	//pTemp->pNext = pTemp->pNext->pNext;
	////�ͷſռ�
	//delete pDeleteNode;

	NODE* pDeleteNode = pTemp->pNext;
	pTemp->pNext = pDeleteNode->pNext;//���������������һ���ġ�
	nData = pDeleteNode->Data;
	delete pDeleteNode;
	m_Lenth--;
	return true;
}
