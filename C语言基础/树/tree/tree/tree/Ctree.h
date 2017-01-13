#pragma once
class Ctree
{ 
public:
	Ctree();

public:
	typedef struct _NODE{
		int nData;
		_NODE *pLeft;
		_NODE *pRight;
	}NODE, *PNODE;
public:
	bool Insert(
		int nEle,//����0 Ҫ���������
		int & nError //����1 ������
		);
	bool Delete(
		int nEle,//����0 Ҫ���������
		int & nError //����1 ������
		);
	//ǰ�����
	void PreOrder(){
		PreOrderTraverse(m_pRoot);
	}
		void InOrder();//�������
		void PostOrder();//�������
private:
	bool InsertNode(
		int nEle,//����0:Ҫ��ӵ�����
		PNODE &pNode,//����1:��Ҫ���������
		int &nError//����2:���ڵõ�һ��������
		);
	bool DeleteNode(
		int nEle,//����0:Ҫ��ӵ�����
		PNODE &pTree,//����1:Ҫɾ���ڵ������
		int &nError//����2:���ڵõ�һ��������
		);
	int GetHeight(// ��ȡ����
		PNODE pTree //Ҫ��ȡ���ߵ�����
		);
	bool GetMax(
		PNODE pTree,//Ҫ��ȡ���ֵ������
		int & nMax//���ڵõ�����ֵ
		);
	bool GetMin(
		PNODE pTree,//Ҫ��ȡ���ֵ������
		int & nMin//���ڵõ�����ֵ
		);
	bool SingleL(  /*�˽ڵ�ΪԲ������ */
		PNODE& pNode//Ҫ��ת�Ľڵ�
		);
	bool SingleR(  /*�˽ڵ�ΪԲ������ */
		PNODE& pNode//Ҫ��ת�Ľڵ�
		);
	bool SingleLR(  /*�˽ڵ�ΪԲ�������� */
		PNODE& pNode//Ҫ��ת�Ľڵ�
		);
	bool SingleRL(  /*�˽ڵ�ΪԲ�������� */
		PNODE& pNode//Ҫ��ת�Ľڵ�
		);
	void PreOrderTraverse(PNODE& pNode);
	void InOrderTraverse(PNODE& pNode);
	void PostOrderTraverse(PNODE& pNode);
private:
	PNODE m_pRoot;
};

