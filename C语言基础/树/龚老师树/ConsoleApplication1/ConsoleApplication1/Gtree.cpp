#include "stdafx.h"
#include "Gtree.h" 
CMyTree::CMyTree()
{
	m_nCurrNum = 0;         //当前元素个数
	m_pRoot = nullptr;      //根节点指针
}
 
CMyTree::~CMyTree()
{
	//ClearBiTree(m_pRoot);
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
		pNode = new NODE();
		pNode->Data = e;
		m_pRoot = pNode;
		m_nCurrNum++;
		return RESULT_TRUE;
	} 
	//2.检查是否传入了正确参数				
		//  2.1 检查树中是否已经存在此值(存在则退出)
	PNODE Prenode; 
	Status checkIsHava = LocateElem(m_pRoot, e, Prenode);
	if (checkIsHava == RESULT_TRUE)
	{
		return RESULT_ERR_PARAMTER;//找的到 返回参数错误
	}
	//3.在树中插入新节点,并将值设为e,元素个数加1
	//  3.1 找到插入的位置(通过2.1已经找到插入点的父节点)
	PNODE Pnewnode = new  NODE();
	Pnewnode->Data = e;
	Pnewnode->pFather = Prenode;//将父节点的地址先赋值上
	// 3.2判断下值应该放哪边	大于赋值右边			小于赋值左边	
	(e>Prenode->Data)?Prenode->pRChild = Pnewnode:Prenode->pLChild = Pnewnode;
	//3.3 tree元素个数加一
	m_nCurrNum++;
	if (pNode)
	{
		*pNode = *Pnewnode;
	}
	return RESULT_TRUE;
}

Status CMyTree::LocateElem(PNODE pChildTree, ElemType e, PNODE & pTree){
	
	PNODE pFindNode = nullptr;//保存要返回的结果指针
	while (pChildTree)
	{
		pFindNode = pChildTree;
		//   1.1 要找的值比当前节点的值小,则去左子树继续找
		//   1.2 要找的值比当前节点的值大,则去右子树继续找
		//   1.3 要找的值跟当前节点的值相等,则结束循环
		if (e<pFindNode->Data)
		{
			pChildTree = pChildTree->pLChild;
		} 
		else if (e>pFindNode->Data)
		{
			pChildTree = pChildTree->pRChild;
		}
		else 
		{
			pTree = pFindNode;
			return RESULT_TRUE;
		} 
	} 
	//没有找到,则pFindNode的保存的是插入位置的父节点
	pTree = pFindNode;
	return RESULT_FALSE;
}

Status CMyTree::Delete( ElemType e, PNODE pNode  ){
	//判断是否还有东西可以删除
	if (m_pRoot == NULL)
	{
		RESULT_FALSE;
	}
	PNODE Prenode;
	Status CheckIsHava = LocateElem(m_pRoot, e, Prenode);
	if (CheckIsHava == RESULT_FALSE) //找到了 应该可以要的
	{
		return RESULT_ERR_PARAMTER;
	}
	while (1)
	{
		//3.1 判断是否是叶子节点(叶子节点直接删除)
		if (Prenode->pLChild == nullptr && Prenode->pRChild == nullptr)
		{
			//3.1.1 清掉父节点的子树记录
			if (Prenode->pFather->pLChild == Prenode)
			{
				Prenode->pFather->pLChild == nullptr;
			}
			else
			{
				Prenode->pFather->pRChild == nullptr;
			} 
			if (pNode)
			{
				//做平衡时使用保存父节点  //pNode->pFather = pReNode->pFather;
				*pNode = *Prenode;
			}
			//3.1.2 清掉自己
			//delete Prenode;
			Prenode = nullptr;  
			return RESULT_TRUE;
		} 
			//  3.2 判断两边树高,在高树中选择要交换的节点
			int TLheight, TRheight;
			BiTreeDepth(Prenode->pLChild, TLheight);
			BiTreeDepth(Prenode->pRChild, TRheight);
			PNODE Temp;
			if (TLheight>=TRheight)
			{
				//      (左子树中选最大值,右子树中选最小)
				//去左树中取最大值
				GetMax(Prenode->pLChild, Temp);  
			}
			else
			{//去右树中取最小值
				GetMin(Prenode->pRChild, Temp); 
			}   
			Prenode->Data = Temp->Data;
			Prenode = Temp; 
	  }
		//3.4 更新tree的元素个数
		m_nCurrNum--; 
		return RESULT_TRUE;
}
/**取子树中的最大值*/
Status CMyTree::GetMax(PNODE pChildTree, PNODE & pNode){
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
/**取子树中的最小值*/
Status CMyTree::GetMin(PNODE pChildTree, PNODE & pNode){
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
Status CMyTree::BiTreeDepth( /**返回树的深度*/
	PNODE pChildTree,//[in] 需要求深度的子树
	int & nTreeDepth //[out]树的深度
	){
	if (pChildTree == nullptr)
	{
		nTreeDepth = 0;
		return RESULT_FALSE;
	}
	int Tleft =  BiTreeDepth(pChildTree->pLChild, Tleft);
	int Tright = BiTreeDepth(pChildTree->pLChild, Tright); 
	nTreeDepth =  (Tleft > Tright ? Tleft : Tright)+1;
	return RESULT_TRUE;
}