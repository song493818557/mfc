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
			//�������Ϊ0�Ļ�������ǰ�ڵ������
			InsertEleDiGui2(Data, m_Root);
		}
	}
	
	void Pre()
	{
		PreList(m_Root);
	}
private://�������������ڲ�����
	//ǰ�����
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
	//�ڶ�����Ӧ�ô���ָ������ã�Ϊ����ǰ�ڵ��������
	bool InsertEleDiGui2(int Data, NODE* &pNode)
	{
		//�����ǰ�ڵ�Ϊ�գ�ֱ�ӹ����������
		if (pNode == NULL)
		{
			pNode = new NODE;
			pNode->Data = Data;
			pNode->Left = pNode->Right = NULL;
			return true;
		}
		//�����������ݱȵ�ǰ�ڵ�󣬾�����������
		if (Data > pNode->Data)
		{
			return InsertEleDiGui2(Data, pNode->Right);
		}
		//�����������ݱȵ�ǰ�ڵ�С��������������
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

