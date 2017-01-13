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
public://这些是对外接口
	bool InsertEle(int Data);


	bool InsertEleDiGui1(int Data)
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
	
	void Pre()
	{
		PreList(m_Root);
	}
private://这两个函数是内部函数
	//前序遍历
	void PreList(NODE* pNode)
	{
		if (pNode==NULL)
		{
			return;
		}

		PreList(pNode->Left);
		printf("%d  ", pNode->Data);
		PreList(pNode->Right);

	}
	//第二参数应该传递指针的引用，为了向当前节点插入数据
	bool InsertEleDiGui2(int Data, NODE* &pNode)
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
			return InsertEleDiGui2(Data, pNode->Right);
		}
		//如果插入的数据比当前节点小，就往左子树插
		else if (Data < pNode->Data)
		{
			return InsertEleDiGui2(Data, pNode->Left);
		}
		else
		{
			return false;
		}
	}
private:
	NODE* m_Root;
};

