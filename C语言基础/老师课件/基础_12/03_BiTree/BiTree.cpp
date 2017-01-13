#include "stdafx.h"
#include "BiTree.h"


CBiTree::CBiTree() :m_Root(NULL)
{
}


CBiTree::~CBiTree()
{
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
				pTemp->Right->Left = pTemp->Right->Right = NULL;
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