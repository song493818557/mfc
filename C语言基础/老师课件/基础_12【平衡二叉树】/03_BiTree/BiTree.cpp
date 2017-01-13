#include "stdafx.h"
#include "BiTree.h"


CBiTree::CBiTree() :m_Root(NULL)
{
}


CBiTree::~CBiTree()
{
}
bool CBiTree::InsertEleDiGui1(int Data)
{
	if (m_Root == NULL)
	{
		m_Root = new NODE;
		m_Root->Data = Data;
		m_Root->Left = m_Root->Right = NULL;
		return 0;
	}
	else
	{
		//�������Ϊ0�Ļ�������ǰ�ڵ������
		InsertEleDiGui2(Data, m_Root);
	}
}

bool CBiTree::InsertEle(int Data)
{
	//1 ������ǿ���
	if (m_Root == NULL)
	{
		m_Root = new NODE;
		m_Root->Data = Data;
		m_Root->Left = m_Root->Right = NULL;
		return 0;
	}
	int* p = new int;


	//2 �������Ϊ��
	NODE* pTemp = 	m_Root;
	while (true)
	{
		//1 ���������ݴ�������㣬��Ӧ�����ұ��ң�
		if (Data > pTemp->Data)
		{
			//�ҵ����ǿգ���ֱ�Ӳ��뼴��
			if (pTemp->Right == NULL)
			{
				pTemp->Right = new NODE;
				pTemp->Right->Data = Data;
				pTemp->Right->Left =
					pTemp->Right->Right = NULL;
				return true;
			}
			else
			{
				pTemp = pTemp->Right;
			}
		}
		//2 ����������С������㣬��Ӧ���������
		else
		{
			if (pTemp->Left == NULL)
			{
				pTemp->Left = new NODE;
				pTemp->Left->Data = Data;
				pTemp->Left->Left =
					pTemp->Left->Right = NULL;
				return true;
			}
			else
			{
				pTemp = pTemp->Left;
			}
		}
		
	}

}
//ǰ�����
void CBiTree::PreList(NODE* pNode)
{
	if (pNode == NULL)
	{
		return;
	}

	PreList(pNode->Left);
	printf("%d  ", pNode->Data);
	PreList(pNode->Right);

}
//�ڶ�����Ӧ�ô���ָ������ã�Ϊ����ǰ�ڵ��������
bool CBiTree::InsertEleDiGui2(int Data, NODE* &pNode)
{
	//�����ǰ�ڵ�Ϊ�գ�ֱ�ӹ����������
	if (pNode == NULL)
	{
		pNode = new NODE;
		pNode->Data = Data;
		pNode->Left = pNode->Right = NULL;
		return true;
	}
	//�����������ݱȵ�ǰ�ڵ�󣬾�����������
	if (Data > pNode->Data)
	{
		return InsertEleDiGui2(Data, pNode->Right);
	}
	//�����������ݱȵ�ǰ�ڵ�С��������������
	else if (Data < pNode->Data)
	{
		return InsertEleDiGui2(Data, pNode->Left);
	}
	else
	{
		return false;
	}
}
bool CBiTree::DeleteEleInTree(int nEle, NODE* &pNode)
{
	if (pNode->Left == NULL&&pNode->Right == NULL)
	{
		if (nEle == pNode->Data)
		{
			delete pNode;
			pNode = NULL;
			return true;
		}
		else
		{
			return false;
		}
	}
	//������ڵ�ǰ�㣬��ȥ�ұ�Ѱ��
	if (nEle>pNode->Data)
	{
		return DeleteEleInTree(nEle, pNode->Right);
	}
	//���С�ڵ�ǰ�㣬��ȥ���Ѱ��
	else if (nEle<pNode->Data)
	{
		return DeleteEleInTree(nEle, pNode->Left);
	}
	//������ڵ�ǰ�㣬��˵���ҵ���
	else
	{
		//������������߶Ⱥ��������߶�
		int nRightHeight = GetTreeHeight(pNode->Right);
		int nLeftHeight = GetTreeHeight(pNode->Left);
		//�����߸߶ȴ����ұ߸߶ȣ����Ǿ�ȥ��ȡ��ߵ����ֵ
		if (nLeftHeight>nRightHeight)
		{
			//�ҵ������ֵ
			int nMax = GetMax(pNode->Left);
			//ֱ�ӽ����滻
			pNode->Data = nMax;
			return DeleteEleInTree(nMax, pNode->Left);
		}
		else
		{
			//�ҵ������ֵ
			int nMin = GetMin(pNode->Right);
			//ֱ�ӽ����滻
			pNode->Data = nMin;
			return DeleteEleInTree(nMin, pNode->Right);
		}
	}
}

int CBiTree::GetTreeHeight(NODE* pNode)
{

	if (pNode == NULL)
	{
		return 0;
	}
	int nLeftHeight = GetTreeHeight(pNode->Left);
	int nRightHeight = GetTreeHeight(pNode->Right);
	int nHeight = nLeftHeight > nRightHeight ? nLeftHeight : nRightHeight;
	nHeight++;
	return nHeight;
}
int CBiTree::GetMax(NODE* pNode)
{
	//�������ұ����������ҵ����ֵ
	int Max = 0;
	while (pNode != NULL)
	{
		Max = pNode->Data;
		pNode = pNode->Right;
	}
	return Max;
}
int CBiTree::GetMin(NODE* pNode)
{
	//������������������ҵ���Сֵ
	int Min = 0;
	while (pNode != NULL)
	{
		Min = pNode->Data;
		pNode = pNode->Left;
	}
	return Min;
}
void CBiTree::DeleteEle(int nEle)
{
	DeleteEleInTree(nEle, m_Root);
}
void CBiTree::PreOrder()
{
	PreList(m_Root);
}