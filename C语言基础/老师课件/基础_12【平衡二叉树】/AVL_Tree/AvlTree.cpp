#include "stdafx.h"
#include "AvlTree.h"

CAvlTree::CAvlTree() :m_Root(NULL)
{
}


CAvlTree::~CAvlTree()
{
}
bool CAvlTree::InsertEleDiGui1(int Data)
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
		//如果根不为0的话，就像当前节点插数据
		InsertEleDiGui2(Data, m_Root);
	}
}

bool CAvlTree::InsertEle(int Data)
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
	NODE* pTemp = m_Root;
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
				pTemp->Right->Left =
					pTemp->Right->Right = NULL;
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
//前序遍历
void CAvlTree::PreList(NODE* pNode)
{
	if (pNode == NULL)
	{
		return;
	}
	printf("%d  ", pNode->Data);
	PreList(pNode->Left);
	PreList(pNode->Right);

}
//第二参数应该传递指针的引用，为了向当前节点插入数据
bool CAvlTree::InsertEleDiGui2(int Data, NODE* &pNode)
{
	//如果当前节点为空，直接挂上这个数据
	if (pNode == NULL)
	{
		pNode = new NODE;
		pNode->Data = Data;
		pNode->Left = pNode->Right = NULL;
		return true;
	}
	//如果插入的数据比当前节点大，就往右子树插
	if (Data > pNode->Data)
	{
		InsertEleDiGui2(Data, pNode->Right);

	}
	//如果插入的数据比当前节点小，就往左子树插
	else if (Data < pNode->Data)
	{
		InsertEleDiGui2(Data, pNode->Left);
	}
	else
	{
		return false;
	}
	//处理不平衡
	//获得左右子树高度差
	int nDifference = 
		GetTreeHeight(pNode->Left) - GetTreeHeight(pNode->Right);
	if (nDifference == 2 || nDifference==-2)
	{
		//说明左边比右边高，
		if (nDifference == 2)
		{
			//需要右单旋
			if (
				GetTreeHeight(pNode->Left->Right)
				<
				GetTreeHeight(pNode->Left->Left))
			{
				pNode = SigleRight(pNode->Left, pNode);
			}
			//需要双旋
			else
			{
				pNode = DoubleRight(pNode->Left, pNode);
			}

		}
		//说明右边比左边高
		else
		{
			if (
				GetTreeHeight(pNode->Right->Right)
				>
				GetTreeHeight(pNode->Right->Left)
				)
			{
				//需要左单旋
				pNode = SigleLeft(pNode->Right, pNode);
			}
			else
			{
				//需要左双旋
				pNode = DoubleLeft(pNode->Right, pNode);
			}


		}
	}

	return true;
}
bool CAvlTree::DeleteEleInTree(int nEle, NODE* &pNode)
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
	//如果大于当前点，就去右边寻找
	if (nEle>pNode->Data)
	{
		DeleteEleInTree(nEle, pNode->Right);
	}
	//如果小于当前点，就去左边寻找
	else if (nEle<pNode->Data)
	{
		DeleteEleInTree(nEle, pNode->Left);
	}
	//如果等于当前点，就说明找到了
	else
	{
		//先求出左子树高度和右子树高度
		int nRightHeight = GetTreeHeight(pNode->Right);
		int nLeftHeight = GetTreeHeight(pNode->Left);
		//如果左边高度大于右边高度，我们就去获取左边的最大值
		if (nLeftHeight>nRightHeight)
		{
			//找到了最大值
			int nMax = GetMax(pNode->Left);
			//直接进行替换
			pNode->Data = nMax;
			DeleteEleInTree(nMax, pNode->Left);
		}
		else
		{
			//找到了最大值
			int nMin = GetMin(pNode->Right);
			//直接进行替换
			pNode->Data = nMin;
			DeleteEleInTree(nMin, pNode->Right);
		}
	}
	//处理不平衡
	//获得左右子树高度差
	int nDifference =
		GetTreeHeight(pNode->Left) - GetTreeHeight(pNode->Right);
	if (nDifference == 2 || nDifference == -2)
	{
		//说明左边比右边高，
		if (nDifference == 2)
		{
			//需要右单旋
			if (
				GetTreeHeight(pNode->Left->Right)
				<
				GetTreeHeight(pNode->Left->Left))
			{
				pNode = SigleRight(pNode->Left, pNode);
			}
			//需要双旋
			else
			{
				pNode = DoubleRight(pNode->Left, pNode);
			}

		}
		//说明右边比左边高
		else
		{
			if (
				GetTreeHeight(pNode->Right->Right)
				>
				GetTreeHeight(pNode->Right->Left)
				)
			{
				//需要左单旋
				pNode = SigleLeft(pNode->Right, pNode);
			}
			else
			{
				//需要左双旋
				pNode = DoubleLeft(pNode->Right, pNode);
			}
		}
	}
	return true;
}

int CAvlTree::GetTreeHeight(NODE* pNode)
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
int CAvlTree::GetMax(NODE* pNode)
{
	//不断往右遍历，就能找到最大值
	int Max = 0;
	while (pNode != NULL)
	{
		Max = pNode->Data;
		pNode = pNode->Right;
	}
	return Max;
}
int CAvlTree::GetMin(NODE* pNode)
{
	//不断往左遍历，就能找到最小值
	int Min = 0;
	while (pNode != NULL)
	{
		Min = pNode->Data;
		pNode = pNode->Left;
	}
	return Min;
}
void CAvlTree::DeleteEle(int nEle)
{
	DeleteEleInTree(nEle, m_Root);
}
void CAvlTree::PreOrder()
{
	PreList(m_Root);
}