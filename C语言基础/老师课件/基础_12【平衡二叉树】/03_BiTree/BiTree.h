#pragma once
class CBiTree
{
public:
	typedef struct _NODE
	{
		int Data;
		_NODE* Left;
		_NODE* Right;
	}NODE, *PNODE;
public://
	CBiTree();
	~CBiTree();
public://��Щ�Ƕ���ӿ�
	bool InsertEle(int Data);
	bool InsertEleDiGui1(int Data);
	void PreOrder();
	void DeleteEle(int nEle);
private://�⼸���������ڲ�����
	int GetMin(NODE* pNode);
	int GetMax(NODE* pNode);
	int GetTreeHeight(NODE* pNode);
	bool DeleteEleInTree(int nEle, NODE* &pNode);
	bool InsertEleDiGui2(int Data, NODE* &pNode);
	void PreList(NODE* pNode);
private:
	NODE* m_Root;
};

