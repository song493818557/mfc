#pragma once
typedef struct _NODE
{
	int Data;
	_NODE* pNext;
}NODE,*PNODE;
class CLinkList
{
public:
	CLinkList();
	~CLinkList();
	bool InsertEle(int nLoc, int nData);
	bool DeleteEle(int nLoc, int& nData);
	void printfAll()
	{
		if (m_pHead==NULL)
		{
			return;
		}
		NODE* pTemp = m_pHead;
		for (int i = 0; i < m_Lenth; i++)
		{
			printf("%d", pTemp->Data);
			pTemp = pTemp->pNext;
		}
	}
private:
	NODE * m_pHead;
	int m_Lenth;
};


