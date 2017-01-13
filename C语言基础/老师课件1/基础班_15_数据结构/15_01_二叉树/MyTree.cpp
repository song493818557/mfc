#include "stdafx.h"
#include "MyTree.h"

CMyTree::CMyTree()
{
	m_nCurrNum = 0;         //当前元素个数
	m_pRoot = nullptr;      //根节点指针
}


CMyTree::~CMyTree()
{
	ClearBiTree(m_pRoot);
}

/************************************
* Access:    public
* 函数功能:  在树中插入新节点,并将值设为e,元素个数加1
*
* 参数列表:
*   ElemType e:   [in]  插入的新值
*   PNODE pNode:  [out] 返回插入的节点内容
*
* 返回值:    Status
*
*************************************/
Status CMyTree::Insert(ElemType e, PNODE pNode /* = nullptr */)
{

	//1.检查是否满足初始条件
	if (m_pRoot == nullptr)
	{
		//说明此树还没有根节点,元素只能插在根位置
		m_pRoot = new NODE(); //不加()时,初始值全是cdcdcd,添加后全是0
		m_pRoot->Data = e;

		m_nCurrNum++;
		if (pNode)
		{
			*pNode = *m_pRoot;
		}
		return RESULT_TRUE;
	}
	//2.检查是否传入了正确参数				
	//  2.1 检查树中是否已经存在此值(存在则退出)
	PNODE pReNode;
	Status checkIsHave = LocateElem(m_pRoot, e, pReNode);
	if (checkIsHave == RESULT_TRUE)
	{
		return RESULT_ERR_PARAMTER;
	}
	//3.在树中插入新节点,并将值设为e,元素个数加1
	//  3.1 找到插入的位置(通过2.1已经找到插入点的父节点)
	//  3.2 新元素生成,并插入
	PNODE pNewNode = new NODE();
	pNewNode->Data = e;
	pNewNode->pFather = pReNode;

	if (e<pReNode->Data)
	{
		pReNode->pLChild = pNewNode;
	}
	else if (e>pReNode->Data) {
		pReNode->pRChild = pNewNode;
	}
	//  3.3 更新tree的元素个数
	m_nCurrNum++;
	//4.设置返回值
	if (pNode)
	{
		*pNode = *pNewNode;
	}

	return RESULT_TRUE;
}


/************************************
* Access:    public
* 函数功能:  将值为e的节点在树中删除,元素个数减1
*
* 参数列表:
*   ElemType e:   [in] 删除的元素值
*   PNODE pNode:  [out] 返回删除的节点内容(只有父节点指针有效)
*
* 返回值:    Status
*
*************************************/
Status CMyTree::Delete(ElemType e, PNODE pNode /* = nullptr */)
{
	//1.检查是否满足初始条件
	if (m_pRoot == nullptr)
	{
		return RESULT_FALSE;
	}
	//2.检查是否传入了正确参数				
	//  2.1 检查树中是否已经存在此值(不存在则退出)
	PNODE pReNode;
	Status checkIsHave = LocateElem(m_pRoot, e, pReNode);
	if (checkIsHave == RESULT_FALSE)
	{
		return RESULT_ERR_PARAMTER;
	}
	//3.将值为e的节点在树中删除,元素个数减1
	//  3.1 判断是否是叶子节点(叶子节点直接删除)
	//  3.2 判断两边树高,在高树中选择要交换的节点
	//      (左子树中选最大值,右子树中选最小)
	//  3.3 以3.2中选出的节点,重复 3.1-3.2,
	//      直到找到一个叶子节点
	while (true)
	{
		//3.1 判断是否是叶子节点(叶子节点直接删除)
		if (pReNode->pLChild == nullptr &&
			pReNode->pRChild == nullptr)
		{
			//3.1.1 清掉父节点的子树记录
			if (pReNode->pFather->pLChild == pReNode) {
				pReNode->pFather->pLChild = nullptr;
			}
			else {
				pReNode->pFather->pRChild = nullptr;
			}
			//3.1.2 清掉自己
			if (pNode)
			{
				//做平衡时使用
				//pNode->pFather = pReNode->pFather;
				*pNode = *pReNode;
			}
			delete pReNode;

			break;
		}
		//  3.2 判断两边树高,在高树中选择要交换的节点
		//      (左子树中选最大值,右子树中选最小)
		int LChildDepth, RChildDepth;
		BiTreeDepth(pReNode->pLChild, LChildDepth);
		BiTreeDepth(pReNode->pRChild, RChildDepth);

		PNODE pExchangeNode;
		if (LChildDepth > RChildDepth)
		{
			//去左树中取最大值
			GetMax(pReNode->pLChild, pExchangeNode);
		}
		else {
			//去右树中取最小值
			GetMin(pReNode->pRChild, pExchangeNode);
		}
		pReNode->Data = pExchangeNode->Data;

		//  3.3 以3.2中选出的节点,重复 3.1-3.2,
		//      直到找到一个叶子节点
		pReNode = pExchangeNode;
	}

	//3.4 更新tree的元素个数
	m_nCurrNum--;

	return RESULT_TRUE;
}

/************************************
* Access:    public
* 函数功能:  将二叉树清为空树
*
* 参数列表:
*
* 返回值:    Status
*
*************************************/
Status CMyTree::ClearBiTree()
{
	return ClearBiTree(m_pRoot);
}

Status CMyTree::ClearBiTree(PNODE & pChildTree)
{
	if (pChildTree == nullptr)
	{
		return RESULT_FALSE;
	}
	ClearBiTree(pChildTree->pLChild);
	ClearBiTree(pChildTree->pRChild);
	//释放本节点
	delete pChildTree;
	pChildTree = nullptr;

	return RESULT_TRUE;
}

/************************************
* Access:    public
* 函数功能:  若树为空,返回true,否则返回false
*
* 参数列表:
*   bool & isEmpty:
*
* 返回值:    Status
*
*************************************/
Status CMyTree::BiTreeEmpty(bool & isEmpty)
{
	//1.检查是否满足初始条件
	if (m_pRoot == nullptr)
	{
		isEmpty = true;
		return RESULT_FALSE;
	}
	//2.若树为空,返回true,否则返回false
	//  检查元素个数
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
* 函数功能:  返回树的深度
*
* 参数列表:
*   PNODE pChildTree:  [in] 需要求深度的子树
*   int & nTreeDepth:  [out]树的深度
*
* 返回值:    Status
*
*************************************/
Status CMyTree::BiTreeDepth(PNODE pChildTree, int & nTreeDepth)
{
	//1.检查是否满足初始条件
	if (pChildTree == nullptr)
	{
		nTreeDepth = 0;
		return RESULT_FALSE;
	}

	//2.返回树的深度
	int LChildDepth, RChildDepth;
	BiTreeDepth(pChildTree->pLChild, LChildDepth);
	BiTreeDepth(pChildTree->pRChild, RChildDepth);
	if (LChildDepth > RChildDepth)
	{
		nTreeDepth = LChildDepth + 1;
	}
	else {
		nTreeDepth = RChildDepth + 1;
	}

	return RESULT_TRUE;
}

/************************************
* Access:    public
* 函数功能:  前序遍历整棵树
*
* 参数列表:
*   PNODE pChildTree: [in]需要遍历的子树
*   Visit:            [in]对每个节点,都调用此函数
*
* 返回值:    Status
*
*************************************/
Status CMyTree::PreOrderTraverse(PNODE pChildTree, Status(*Visit)(ElemType &e))
{
	//1.检查是否满足初始条件
	//2.检查是否传入了正确参数				
	if (pChildTree == nullptr)
	{
		return RESULT_FALSE;
	}

	//3.前序遍历整棵树
	//  3.1 处理根节点
	Visit(pChildTree->Data);
	//  3.2 左子树递归
	PreOrderTraverse(pChildTree->pLChild, Visit);
	//  3.3 右子树递归
	PreOrderTraverse(pChildTree->pRChild, Visit);

	return RESULT_TRUE;
}

/************************************
* Access:    public
* 函数功能:  中序遍历整棵树
*
* 参数列表:
*   PNODE pChildTree:  [in]需要遍历的子树
*   Visit:             [in]对每个节点,都调用此函数
*
* 返回值:    Status
*
*************************************/
Status CMyTree::InOrderTraverse(PNODE pChildTree, Status(*Visit)(ElemType &e))
{
	//1.检查是否满足初始条件
	//2.检查是否传入了正确参数	
	if (pChildTree == nullptr)
	{
		return RESULT_FALSE;
	}

	//3.中序遍历整棵树
	//  3.1 左子树递归
	InOrderTraverse(pChildTree->pLChild, Visit);
	//  3.2 处理根节点
	Visit(pChildTree->Data);
	//  3.3 右子树递归
	InOrderTraverse(pChildTree->pRChild, Visit);

	return RESULT_TRUE;
}

/************************************
* Access:    public
* 函数功能:  后序遍历整棵树
*
* 参数列表:
*   PNODE pChildTree:  [in]需要遍历的子树
*   Visit:             [in]对每个节点,都调用此函数
*
* 返回值:    Status
*
*************************************/
Status CMyTree::PostOrderTraverse(PNODE pChildTree, Status(*Visit)(ElemType &e))
{

	//1.检查是否满足初始条件
	//2.检查是否传入了正确参数
	if (pChildTree == nullptr)
	{
		return RESULT_FALSE;
	}

	//3.实现本函数的功能
	//  3.1 左子树递归
	PostOrderTraverse(pChildTree->pLChild, Visit);
	//  3.2 右子树递归
	PostOrderTraverse(pChildTree->pRChild, Visit);
	//  3.3 处理根节点
	Visit(pChildTree->Data);

	return RESULT_TRUE;
}

/************************************
* Access:    public
* 函数功能:  层序遍历整棵树
*
* 参数列表:
*   PNODE pChildTree:  [in]需要遍历的子树
*   * Visit:           [in]对每个节点,都调用此函数
*
* 返回值:    Status
*
*************************************/
Status CMyTree::LevelOrderTraverse(PNODE pChildTree, Status(*Visit)(ElemType &e))
{
	//1.检查是否满足初始条件
	//2.检查是否传入了正确参数				
	if (pChildTree == nullptr)
	{
		return RESULT_FALSE;
	}

	//3.层序遍历整棵树(第1层,第2层 ...... )
	//  3.1 构建一个数组,准备把所有元素往里面插入(用数组演示了队列的功能)
	PNODE * queue = new PNODE[m_nCurrNum * 3];
	queue[0] = pChildTree;
	int front = 0; //队列头下标
	int rear = 1;  //队列尾下标

	while (front < rear)
	{
		// 把节点,按照层 由上至下,由左到右 的顺序依次插入队列的尾部.
		if (queue[front])
		{
			Visit(queue[front]->Data);
			queue[rear++] = queue[front]->pLChild;
			queue[rear++] = queue[front]->pRChild;

		}
		front++;
	}

	delete[]queue;
	return RESULT_TRUE;
}

void CMyTree::show()
{
	printf("\n");
	printTree(m_pRoot, 0);
}

void CMyTree::printTree(PNODE & pChildNode, int nLayer)
{
	if (pChildNode == nullptr)
	{
		return;
	}
	printTree(pChildNode->pRChild, nLayer + 1);
	//不同的层次,用空格来分割
	for (int i = 0; i < nLayer; i++)
	{
		printf("        ");
	}
	//根据此节点时是,左右节点
	// 打印不同的数据线(↗)
	//                  ↘
	if (pChildNode->pFather == nullptr)
	{
		printf("%6d\n", pChildNode->Data);
	}
	else if (pChildNode->Data < pChildNode->pFather->Data)
	{
		//左子树
		printf("↘%6d\n", pChildNode->Data);
	}
	else if (pChildNode->Data > pChildNode->pFather->Data)
	{
		//右子树
		printf("↗%6d\n", pChildNode->Data);
	}
	printTree(pChildNode->pLChild, nLayer + 1);
}

Status CMyTree::LocateElem(PNODE pChildTree, ElemType e, PNODE & pTree)
{
	PNODE pFindNode = nullptr;//保存要返回的结果指针
	//bool isFind = false;
	//1. 不断循环,直到找到,或者pFindNode为nullptr
	while (pChildTree)
	{
		pFindNode = pChildTree;
		//   1.1 要找的值比当前节点的值小,则去左子树继续找
		//   1.2 要找的值比当前节点的值大,则去右子树继续找
		//   1.3 要找的值跟当前节点的值相等,则结束循环
		if (e<pChildTree->Data)
		{
			pChildTree = pChildTree->pLChild;
		}
		else if (e>pChildTree->Data)
		{
			pChildTree = pChildTree->pRChild;
		}
		else {
			//找到了
			pTree = pFindNode;
			return RESULT_TRUE;
		}
	}
	//没有找到,则pFindNode保存的是插入位置的父节点指针
	pTree = pFindNode;
	return RESULT_FALSE;
}

Status CMyTree::GetMax(PNODE pChildTree, PNODE & pNode)
{
	if (pChildTree == nullptr)
	{
		return RESULT_FALSE;
	}
	while (pChildTree)
	{
		pNode = pChildTree;
		pChildTree = pChildTree->pRChild;
	}
	return RESULT_TRUE;
}

Status CMyTree::GetMin(PNODE pChildTree, PNODE & pNode)
{
	if (pChildTree == nullptr)
	{
		return RESULT_FALSE;
	}
	while (pChildTree)
	{
		pNode = pChildTree;
		pChildTree = pChildTree->pLChild;
	}
	return RESULT_TRUE;
}
