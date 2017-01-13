#include "stdafx.h"
#include "Ctree.h"

bool Ctree::Insertnode(PNODE &Pnode, int data){
	//����һ���ݹ����������
	bool nSucess = true;
	//1.����Ƿ������ʼ����
	//���ýڵ��Ƿ�Ϊ�� �ǵĻ���ֱ�Ӳ���
	if (Pnode == nullptr)
	{
		Pnode = new NODE(); //�ṹ���ʼ�������� ���Խ�һЩû�г�ʼ����ָ��ֵ��Ϊ0
		Pnode->ndata = data;
		/*
		Pnode->pLeft = nullptr;
		Pnode->pRight = nullptr;*/
		return true;
	}
	//2.�ж�DATA��ֵӦ�����Ǳ߲��� ��С�ִ�
	if (data < Pnode->ndata) { nSucess = Insertnode(Pnode->pLeft, data); }//��߲���
	else if (data > Pnode->ndata) { nSucess = Insertnode(Pnode->pRight, data); }//�ұ߲���  
	//3. �ҵ��� ֵ֮�� 
	if (nSucess == false)   return false; 
	//4.�ж����Ƿ�ƽ��
	int Leftheight = Getheight(Pnode->pLeft);
	int Righttheight = Getheight(Pnode->pRight);
	//��߱��ұ߸�2��
	if (Leftheight - Righttheight == 2)
	{
		Leftheight = Getheight(Pnode->pLeft->pLeft);
		Righttheight = Getheight(Pnode->pLeft->pRight);
		(Leftheight >= Righttheight) ? floatRight(Pnode) : DoubleLR(Pnode);
		/* ��Ҫ�ҵ���					��Ҫ������
		  K2		 	     k1				 K2			  K2	     N
		 /			 	    / \			    /			 /		    / \
		K1                N   K2		   K1           N          k1  K2
	   /		     					    \		   /
	  N 		   						     N		  K1
		*/
	}
	else if (Leftheight - Righttheight == -2)
	{
		/* ��Ҫ����				��Ҫ������
	  K2			 k1			   K2			  K2	     N
		\		    / \			    \			 /		    / \
	     K1 	   K2  	N	        K1          N          k1  K2
	      \						    /		   /
	    	N					   N		  K1
		*/
		Leftheight = Getheight(Pnode->pRight->pLeft);
		Righttheight = Getheight(Pnode->pRight->pRight);
		(Leftheight >= Righttheight) ? DoubleRL(Pnode) : floatLeft(Pnode);
	} 
}

int Ctree::Getheight(PNODE Pnode){

	if (Pnode == NULL)//�����Ϊ�յĻ��ͷ���
	{
		return 0;
	}
	int a, b;
	a = Getheight(Pnode->pLeft);
	b = Getheight(Pnode->pRight);
	return  (a > b ? a : b) + 1;

}
void Ctree::show(int numb){
	switch (numb)
	{
	case 0: {//�����
		preshow(m_root->pLeft);
		std::cout << m_root->ndata << std::endl;
		preshow(m_root->pRight);
		break;
	}
	case 1: {//������
		std::cout << m_root->ndata << std::endl;
		preshow(m_root->pLeft);
		preshow(m_root->pRight);
		break;
	}
	case 2: {//���Ҹ�
		preshow(m_root->pLeft);
		preshow(m_root->pRight);
		std::cout << m_root->ndata << std::endl;
		break;
	}
	}
}

void Ctree::preshow(PNODE Pnode){
	if (Pnode == NULL)  return; 
	std::cout << Pnode->ndata << std::endl;
	preshow(Pnode->pLeft);
	preshow(Pnode->pRight);
}
void Ctree::Delete(int numb){ 
	Deletetree(m_root,  numb);
}
bool Ctree::Deletetree(PNODE& Pnode,int data){
	//1.����Ƿ�Ϊ��
	if (Pnode == NULL)
	{
		return false;
	}
	bool nSucess = true;
	//2 . �ж�Ҫɾ����ֵ�����ı߲���
	if (data < Pnode->ndata)  {
		nSucess = Deletetree(Pnode->pLeft,  data);
	}
	else if (data > Pnode->ndata)
	{
		nSucess = Deletetree(Pnode->pRight, data);
	}
	else{
		//3.1 ���Ҫɾ����ֵ��Ҷ�ӽڵ�
		if (Pnode->pRight == NULL && Pnode->pLeft == NULL)
		{
			Pnode=NULL;//�����´ξ���ֵ�������λ�� �Ϳ���ֱ�Ӳ��������
			return false;//���false ����ɾ���ɹ�  ��ȥ�������ɾ����
		}
		//3.2���������ж����ıߵ�Ҷ�ӽڵ����滻  ������� ��С ��������Ҷ�ӽڵ��滻
		int Leftheight = Getheight(Pnode->pLeft);
		int Righttheight = Getheight(Pnode->pRight);
		int tnumb = 0;
		//3.1  �����߸�
		if (Leftheight>Righttheight)
		{ 
			getmax(Pnode->pLeft, tnumb);//��ȡ��ǰ�ڵ����������ֵ
			Pnode->ndata = tnumb;//��ֵ
			Deletetree(Pnode->pLeft, tnumb); //ɾ�����������ֵ���ӽڵ�
			return true;//����ʱ���ؼ�
		}
		else
		{
			getmin(Pnode->pRight, tnumb);
			Pnode->ndata = tnumb;
			Deletetree(Pnode->pRight, tnumb);
			return true;//����ʱ���ؼ� 
		}
	}
	//3. �ҵ��� ֵ֮�� 
	if (nSucess == false)
	{
		return false;
	}
	//4.�ж����Ƿ�ƽ��
	int Leftheight = Getheight(Pnode->pLeft);
	int Righttheight = Getheight(Pnode->pRight);
	//��߱��ұ߸�2��
	if (Leftheight - Righttheight == 2)
	{
		Leftheight = Getheight(Pnode->pLeft->pLeft);
		Righttheight = Getheight(Pnode->pLeft->pRight);
		(Leftheight >= Righttheight) ? DoubleLR(Pnode) : floatRight(Pnode);
		return false;
			/* ��Ҫ�ҵ���					��Ҫ������
			   K2		 		 k1				 K2			  K2	     N
			  /			 	    / \			    /			 /		    / \
		     K1                N   K2		   K1           N          k1  K2
			/		     					    \		   /
		   N 		   						     N		  K1
			*/ 
	}
	else if (Leftheight - Righttheight == -2)
	{
		/* ��Ҫ����				��Ҫ������
	  K2			 k1			   K2			  K2	     N
	   \		    / \			    \			 /		    / \
	    K1 	       K2  	N	        K1          N          k1  K2
	     \						    /		   /
	      N						   N		  K1
		*/
		Leftheight = Getheight(Pnode->pRight->pLeft);
		Righttheight = Getheight(Pnode->pRight->pRight);
		(Leftheight >= Righttheight) ? floatLeft(Pnode) : DoubleRL(Pnode);
		return false;
	}
	 
}
void Ctree::getmax(PNODE Pnode,int &temp){
	
	while (Pnode != NULL)
	{
		temp = Pnode->ndata;
		Pnode = Pnode->pRight; 
	}  
	
}
void Ctree::getmin(PNODE Pnode, int &temp){ 
	while (Pnode != NULL)
	{
		temp = Pnode->ndata;
		Pnode = Pnode->pLeft; 
	}
}
void Ctree::floatRight(PNODE& Pnode){

	/* ��Ҫ�ҵ�ѡ
		K2			     k1
		/			    / \
	  K1               N   K2
	  /
	 N
	*/
	PNODE k1, k2;
	k2 = Pnode; 
	k1 = Pnode->pLeft;
	k2->pLeft = k1->pRight;
	k1->pRight = k2;
	Pnode = k1;  
} 

void Ctree::floatLeft(PNODE& Pnode){
	PNODE k2 = Pnode;
	PNODE k1 = Pnode->pRight;
	k2->pRight = k1->pLeft;
	k1->pLeft = k2;
	Pnode = k1; 
}
//������
void Ctree::DoubleLR(PNODE& Pnode){ 
	floatLeft(Pnode->pLeft); 
	floatRight(Pnode);
}
//������
void Ctree::DoubleRL(PNODE& Pnode){ 
	floatRight(Pnode->pRight);
	floatLeft(Pnode);
}