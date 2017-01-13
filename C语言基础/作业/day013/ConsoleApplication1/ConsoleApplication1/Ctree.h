#pragma once
#include <iostream>
class Ctree
{ 

public:
	typedef struct _NODE{
		int ndata;
		_NODE* pLeft;
		_NODE* pRight; 
	}NODE,*PNODE;
	Ctree(){ m_root = nullptr; }
	~Ctree(){}
	
	void insert(int numb){  Insertnode(m_root, numb); }
	int Getheighta(){ return Getheight(m_root); }
	void show(int numb);
	void Delete(int numb);
private:
	NODE * m_root;
	//�������  
	bool Insertnode(PNODE &Pnode, int data);
	//��ȡ����
	int Getheight(PNODE Pnode);
	//ǰ�к������
	void preshow(PNODE Pnode);
	//ɾ��
	bool Deletetree(PNODE& Pnode, int data);
	void getmax(PNODE Pnode, int &temp);
	void getmin(PNODE Pnode, int &temp);
	//�ҵ���
	void floatLeft(PNODE& Pnode);
	//�ҵ���
	void floatRight(PNODE& Pnode);
	//������
	void DoubleLR(PNODE& Pnode);
	//������
	void DoubleRL(PNODE& Pnode);

};

