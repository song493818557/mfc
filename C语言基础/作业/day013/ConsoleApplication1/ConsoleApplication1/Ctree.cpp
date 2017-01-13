#include "stdafx.h"
#include "Ctree.h"

bool Ctree::Insertnode(PNODE &Pnode, int data){
	//创建一个递归结束的条件
	bool nSucess = true;
	//1.检查是否满足初始条件
	//检测该节点是否为空 是的话就直接插入
	if (Pnode == nullptr)
	{
		Pnode = new NODE(); //结构体初始化带括号 可以将一些没有初始化的指针值赋为0
		Pnode->ndata = data;
		/*
		Pnode->pLeft = nullptr;
		Pnode->pRight = nullptr;*/
		return true;
	}
	//2.判断DATA的值应该往那边插入 左小又大
	if (data < Pnode->ndata) { nSucess = Insertnode(Pnode->pLeft, data); }//左边插入
	else if (data > Pnode->ndata) { nSucess = Insertnode(Pnode->pRight, data); }//右边插入  
	//3. 找到了 值之后 
	if (nSucess == false)   return false; 
	//4.判断下是否平衡
	int Leftheight = Getheight(Pnode->pLeft);
	int Righttheight = Getheight(Pnode->pRight);
	//左边比右边高2层
	if (Leftheight - Righttheight == 2)
	{
		Leftheight = Getheight(Pnode->pLeft->pLeft);
		Righttheight = Getheight(Pnode->pLeft->pRight);
		(Leftheight >= Righttheight) ? floatRight(Pnode) : DoubleLR(Pnode);
		/* 需要右单旋					需要左右旋
		  K2		 	     k1				 K2			  K2	     N
		 /			 	    / \			    /			 /		    / \
		K1                N   K2		   K1           N          k1  K2
	   /		     					    \		   /
	  N 		   						     N		  K1
		*/
	}
	else if (Leftheight - Righttheight == -2)
	{
		/* 需要左单旋				需要右左旋
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

	if (Pnode == NULL)//如果树为空的话就返回
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
	case 0: {//左根右
		preshow(m_root->pLeft);
		std::cout << m_root->ndata << std::endl;
		preshow(m_root->pRight);
		break;
	}
	case 1: {//根左右
		std::cout << m_root->ndata << std::endl;
		preshow(m_root->pLeft);
		preshow(m_root->pRight);
		break;
	}
	case 2: {//左右跟
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
	//1.检查是否为空
	if (Pnode == NULL)
	{
		return false;
	}
	bool nSucess = true;
	//2 . 判断要删除的值该往哪边查找
	if (data < Pnode->ndata)  {
		nSucess = Deletetree(Pnode->pLeft,  data);
	}
	else if (data > Pnode->ndata)
	{
		nSucess = Deletetree(Pnode->pRight, data);
	}
	else{
		//3.1 如果要删除的值是叶子节点
		if (Pnode->pRight == NULL && Pnode->pLeft == NULL)
		{
			Pnode=NULL;//这样下次就有值到达这个位置 就可以直接插入进来了
			return false;//这个false 代表删除成功  不去下面继续删除了
		}
		//3.2根据树高判断找哪边的叶子节点来替换  根据左大 右小 来进行找叶子节点替换
		int Leftheight = Getheight(Pnode->pLeft);
		int Righttheight = Getheight(Pnode->pRight);
		int tnumb = 0;
		//3.1  如果左边高
		if (Leftheight>Righttheight)
		{ 
			getmax(Pnode->pLeft, tnumb);//获取当前节点左子树最大值
			Pnode->ndata = tnumb;//赋值
			Deletetree(Pnode->pLeft, tnumb); //删除左子树最大值的子节点
			return true;//先暂时返回假
		}
		else
		{
			getmin(Pnode->pRight, tnumb);
			Pnode->ndata = tnumb;
			Deletetree(Pnode->pRight, tnumb);
			return true;//先暂时返回假 
		}
	}
	//3. 找到了 值之后 
	if (nSucess == false)
	{
		return false;
	}
	//4.判断下是否平衡
	int Leftheight = Getheight(Pnode->pLeft);
	int Righttheight = Getheight(Pnode->pRight);
	//左边比右边高2层
	if (Leftheight - Righttheight == 2)
	{
		Leftheight = Getheight(Pnode->pLeft->pLeft);
		Righttheight = Getheight(Pnode->pLeft->pRight);
		(Leftheight >= Righttheight) ? DoubleLR(Pnode) : floatRight(Pnode);
		return false;
			/* 需要右单旋					需要左右旋
			   K2		 		 k1				 K2			  K2	     N
			  /			 	    / \			    /			 /		    / \
		     K1                N   K2		   K1           N          k1  K2
			/		     					    \		   /
		   N 		   						     N		  K1
			*/ 
	}
	else if (Leftheight - Righttheight == -2)
	{
		/* 需要左单旋				需要右左旋
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

	/* 需要右单选
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
//左右旋
void Ctree::DoubleLR(PNODE& Pnode){ 
	floatLeft(Pnode->pLeft); 
	floatRight(Pnode);
}
//右左旋
void Ctree::DoubleRL(PNODE& Pnode){ 
	floatRight(Pnode->pRight);
	floatLeft(Pnode);
}