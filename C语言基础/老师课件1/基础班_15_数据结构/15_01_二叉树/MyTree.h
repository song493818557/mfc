#pragma once

//定义统一的错误码
enum Status
{
	RESULT_FALSE = 0,       //失败
	RESULT_TRUE,            //成功
	RESULT_ERR_OVERFLOW,    //错误_数组越界
	RESULT_ERR_PARAMTER,    //错误_参数错误
	RESULT_ERR_OVERMAXSIZE, //错误_超过最大容量
	RESULT_ERR_UNKOWN       //错误_未知错误
};

#define ElemType int

class CMyTree
{
public:
	//定义树节点
	typedef struct _NODE
	{
		ElemType Data;
		_NODE * pLChild;  //左子树
		_NODE * pRChild;  //右子树
		_NODE * pFather;  //父节点
	}NODE, *PNODE;
public:
	CMyTree();
	virtual ~CMyTree();


	virtual Status Insert(  /**在树中插入新节点,并将值设为e,元素个数加1*/
		ElemType e,            //[in] 插入的新值
		PNODE pNode = nullptr  //[out] 返回插入的节点内容
		);

	virtual Status Delete(  /**将值为e的节点在树中删除,元素个数减1*/
		ElemType e,            //[in] 删除的元素值
		PNODE pNode = nullptr  //[out]返回删除的节点内容(只有父节点指针有效)
		);

	Status ClearBiTree( /**将二叉树清为空树*/
		);

	Status BiTreeEmpty( /**若树为空,返回true,否则返回false*/
		bool & isEmpty   //[out]是否为空
		);

	Status BiTreeDepth( /**返回树的深度*/
		PNODE pChildTree,//[in] 需要求深度的子树
		int & nTreeDepth //[out]树的深度
		);

	Status PreOrderTraverse(        /**前序遍历整棵树*/
		PNODE pChildTree,            //[in]需要遍历的子树
		Status(*Visit)(ElemType &e)//[in]对每个节点,都调用此函数
		);

	Status InOrderTraverse(       /**中序遍历整棵树*/
		PNODE pChildTree,          //[in]需要遍历的子树
		Status(*Visit)(ElemType &e)//[in]对每个节点,都调用此函数
		);

	Status PostOrderTraverse(     /**后序遍历整棵树*/
		PNODE pChildTree,          //[in]需要遍历的子树
		Status(*Visit)(ElemType &e)//[in]对每个节点,都调用此函数
		);

	Status LevelOrderTraverse(    /**层序遍历整棵树*/
		PNODE pChildTree,          //[in]需要遍历的子树
		Status(*Visit)(ElemType &e)//[in]对每个节点,都调用此函数
		);

	/**仅用于演示,打印出整个二叉树的结构*/
	void show();
	void printTree(PNODE & pChildNode, int nLayer);

	PNODE m_pRoot;      //根节点指针

protected:
	int m_nCurrNum;     //当前元素个数

	/**返回从指定子树开始找,找到第一个值与e相等的元素;
	找到则返回该节点指针,
	没找到则返回插入位置的父节点指针*/
	Status LocateElem(PNODE pChildTree,
		ElemType e,
		PNODE & pTree);

	/**取子树中的最大值*/
	Status GetMax(PNODE pChildTree, PNODE & pNode);
	/**取子树中的最小值*/
	Status GetMin(PNODE pChildTree, PNODE & pNode);

	/**将子树清为空树*/
	Status ClearBiTree(PNODE & pChildTree);
};



