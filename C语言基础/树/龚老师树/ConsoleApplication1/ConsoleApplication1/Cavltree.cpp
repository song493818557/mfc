#include "stdafx.h"
#include "Cavltree.h"


Cavltree::Cavltree()
{
}
 
Cavltree::~Cavltree()
{
}
Status Cavltree::Insert( ElemType e,   PNODE pNode )
{
	//1. 插入数据,返回插入节点副本
	NODE insNode;
	Status result = CMyTree::Insert(e, &insNode); 
	if (result != RESULT_TRUE)
	{
		return RESULT_FALSE;
	}
	PNODE pFather = insNode.pFather; 
	BalanceTree(pFather);
	//3.设置返回值
	if (pNode)
	{
		*pNode = insNode;
	}
	return RESULT_TRUE;
}

Status Cavltree::Delete(ElemType e, PNODE pNode)
{
	//1. 插入数据,返回插入节点副本
	NODE delNode;
	Status result = CMyTree::Insert(e, &delNode);
	if (result != RESULT_TRUE)
	{
		return RESULT_FALSE;
	}
	PNODE pFather = delNode.pFather;
	BalanceTree(pFather);
	//3.设置返回值
	if (pNode)
	{
		*pNode = delNode;
	}
	return RESULT_TRUE;
}
Status Cavltree::BalanceTree(PNODE & pNode){
	while (pNode!=nullptr)
	{
		//1.分四种情况开始旋转
		int Pleft, Pright;
		BiTreeDepth(pNode->pLChild, Pleft);
		BiTreeDepth(pNode->pRChild, Pright);
		//1.1 - 1.2
		if ((Pleft - Pright) == 2)
		{ 
			BiTreeDepth(pNode->pLChild->pLChild, Pleft);
			BiTreeDepth(pNode->pLChild->pRChild, Pright);
				//  1.1 左子树高 - 右子树高 > 1 ; 左.左子树高 >= 左.右子树高
				//  1.2 左子树高 - 右子树高 > 1 ; 左.左子树高  < 左.右子树高
				//      右单旋		  //      左右旋
				//      K2			 //      K2
				//     /			 //     /
				//    K1			 //    K1
				//   / 				 //     \
				//  N   			 //      N
			(Pleft >= Pright) ? SingleR(pNode) : DoubleLR(pNode); 
		}
		else if ((Pleft - Pright) == -2)
		{
			BiTreeDepth(pNode->pRChild->pLChild, Pleft);
			BiTreeDepth(pNode->pRChild->pRChild, Pright);
			//1.3 - 1.4
			//  1.3 右子树高 - 左子树高 > 1 ; 右.右子树高 >= 右.左子树高
			//  1.4 右子树高 - 左子树高 > 1 ; 右.右子树高  < 右.左子树高
			//      左单旋			    右左旋
			//      K2				   K2
			//       \				    \
			//        K1			     K1
			//         \			    /
			//          N			   N
			(Pleft >= Pright) ? SingleL(pNode) : DoubleRL(pNode);
		} 
		//2. 继续向上迭代
		pNode = pNode->pFather;
		
	}
	return RESULT_TRUE;
}

/**右单旋*/
Status Cavltree::SingleR(PNODE & pNode){
	//左子树高 - 右子树高 > 1 ; 左.左子树高 >= 左.右子树高
	//      右单旋
	//      K2              K1
	//     /               / \
	//    K1       ->     N   K2
	//   / \                 /
	//  N   T               T
	// 步骤:
	//   1. 将K1的右子树保存到K2的左子树中
	//   2. 将K1的右子树置为K2
	// 
	//1. 先确定 K2,K1
	PNODE K2 = pNode;
	PNODE K1 = pNode->pLChild;
	PNODE T = K1->pRChild;
	K2->pLChild = K1->pRChild;
	K1->pRChild = K2;
	K2->pFather = K1;//将父节点给K1
	if (K1->pFather == nullptr)
	{
		//5.1 若不平衡的点(pNode)是根节点, 只需改变 m_pRoot
		m_pRoot = K1;
	}
	else if (K2->pFather->pLChild == K2)//如果K2父节点的左子树等于K2 
	{
		K2->pFather->pLChild = K1;
		K1->pFather = K2->pFather->pLChild; 
	}
	else
	{
		K2->pFather->pRChild = K1;
		K1->pFather = K2->pFather->pRChild;
	} 
	//返回K1
//	pNode = K1;
	return RESULT_TRUE; }
/**左单旋*/
Status Cavltree::SingleL(PNODE & pNode){
	PNODE K2 = pNode;
	PNODE K1 = K2->pRChild;
	PNODE T = K1->pLChild;

	//2. 将K1的左子树保存到K2的右子树中
	K2->pRChild = T;

	//3. 将K1的左子树置为K2
	K1->pLChild = K2;

	//4. 重置节点中的父节点指针信息
	K1->pFather = K2->pFather;
	K2->pFather = K1;
	if (T)
	{
		T->pFather = K2;
	}

	//5. 与外部重新连起来(修改外部指针,指向新的局部根节点)
	//    5.1 若不平衡的点(pNode)是根节点, 只需改变 m_pRoot
	if (K1->pFather == nullptr)
	{
		m_pRoot = K1;
	}
	else if (K1->Data < K1->pFather->Data)
	{
		//    5.2 若不平衡的点(pNode)是其父节点的左子节点
		K1->pFather->pLChild = K1;
	}
	else {
		//    5.3 若不平衡的点(pNode)是其父节点的右子节点
		K1->pFather->pRChild = K1;
	}

	return RESULT_TRUE;
}
/**左右双旋*/
Status Cavltree::DoubleLR(PNODE & pNode){
	SingleL(pNode->pLChild);
	SingleR(pNode);

	return RESULT_TRUE;
}
/**右左双旋*/
Status Cavltree::DoubleRL(PNODE & pNode){
	SingleR(pNode->pRChild);
	SingleL(pNode);

	return RESULT_TRUE;
}