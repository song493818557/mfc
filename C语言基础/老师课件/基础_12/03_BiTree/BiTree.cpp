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
	//1 如果树是空树
	if (m_Root == NULL)
	{
		m_Root = new NODE;
		m_Root->Data = Data;
		m_Root->Left = m_Root->Right = NULL;
		return 0;
	}
	int* p = new int;


	//2 如果树不为空
	NODE* pTemp = 	m_Root;
	while (true)
	{
		//1 如果你的数据大于这个点，就应该往右边找，
		if (Data > pTemp->Data)
		{
			//找到的是空，就直接插入即可
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
		//2 如果你的数据小于这个点，就应该往左边找
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