#pragma once
class CAvlTree
{
public:
	typedef struct _NODE
	{
		int Data;
		_NODE* Left;
		_NODE* Right;
	}NODE, *PNODE;
public://
	CAvlTree();
	~CAvlTree();
public://这些是对外接口
	bool InsertEle(int Data);
	bool InsertEleDiGui1(int Data);
	void PreOrder();
	void DeleteEle(int nEle);
private://这几个函数是内部函数
	int GetMin(NODE* pNode);
	int GetMax(NODE* pNode);
	int GetTreeHeight(NODE* pNode);
	bool DeleteEleInTree(int nEle, NODE* &pNode);
	bool InsertEleDiGui2(int Data, NODE* &pNode);
	void PreList(NODE* pNode);

	NODE* SigleRight(NODE* k1,NODE * k2)
	{
		k2->Left = k1->Right;
		k1->Right = k2;
		return k1;
	}

	NODE* SigleLeft(NODE* k1, NODE * k2)
	{
		k2->Right = k1->Left;
		k1->Left = k2;
		return k1;
	}
	NODE* DoubleRight(NODE* &k1, NODE * &k2)
	{
		SigleLeft(k1->Right,k1);
		SigleRight(k1, k2);
		return k1;
	}
	NODE*  DoubleLeft(NODE* &k1, NODE * &k2)
	{
		SigleRight(k1->Left,k1);
		SigleLeft(k1, k2);
		return k1;
	}
private:
	NODE* m_Root;
};