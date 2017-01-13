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
	//插入操作  
	bool Insertnode(PNODE &Pnode, int data);
	//获取树高
	int Getheight(PNODE Pnode);
	//前中后序遍历
	void preshow(PNODE Pnode);
	//删除
	bool Deletetree(PNODE& Pnode, int data);
	void getmax(PNODE Pnode, int &temp);
	void getmin(PNODE Pnode, int &temp);
	//右单旋
	void floatLeft(PNODE& Pnode);
	//右单旋
	void floatRight(PNODE& Pnode);
	//左右旋
	void DoubleLR(PNODE& Pnode);
	//右左旋
	void DoubleRL(PNODE& Pnode);

};

