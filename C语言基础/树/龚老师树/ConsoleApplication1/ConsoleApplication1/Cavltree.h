#pragma once
#include "Gtree.h" 
class Cavltree:public CMyTree
{
public:
	Cavltree();
	~Cavltree();
	virtual Status Insert(  /**在树中插入新节点,并将值设为e,元素个数加1*/
		ElemType e,            //[in] 插入的新值
		PNODE pNode = nullptr  //[out] 返回插入的位置
		);

	virtual Status Delete(  /**将值为e的节点在树中删除,元素个数减1*/
		ElemType e,            //[in] 删除的元素值
		PNODE pNode = nullptr  //[out] 返回删除的位置
		);

	/**旋转(平衡)*/
	Status BalanceTree(PNODE & pNode);

	/**右单旋*/
	Status SingleR(PNODE & pNode);
	/**左单旋*/
	Status SingleL(PNODE & pNode);
	/**左右双旋*/
	Status DoubleLR(PNODE & pNode);
	/**右左双旋*/
	Status DoubleRL(PNODE & pNode);
};

