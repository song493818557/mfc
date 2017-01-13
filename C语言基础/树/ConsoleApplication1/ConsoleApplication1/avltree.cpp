#include "stdafx.h"
#include "avltree.h"
#include <process.h>

bool Cavltree::inserttree(PNODE& Pnode, int nData){

	bool nSucess = true;
	//1判断是否是要插入的节点
	if (Pnode == NULL)
	{
		Pnode = new NODE;
		Pnode->Data = nData;
		Pnode->Pleft = NULL;
		Pnode->Pright = NULL; 
		return true;
	}
	//2 判断要插入的数据和当前的根节点比较大小
	if (nData < Pnode->Data)
	{
		nSucess = inserttree(Pnode->Pleft, nData);
	}
	else if (nData > Pnode->Data)
	{
		nSucess = inserttree(Pnode->Pright, nData);
	}
	else
	{
		return false;
	}
	//// 2.1判断bool值是否为真  否则RETURN
	//if (nSucess == false)
	//{
	//	return false;
	//}
	//3 判断一下经历了删除之后  本节点是否平衡
	int left_height = get_treeheight(Pnode->Pleft);
	int right_height = get_treeheight(Pnode->Pright);
	int presult = left_height - right_height;
	//如果左边高
	if (presult == 2)
	{
	   
		//比较当前节点的左右树高
		int left_height = get_treeheight(Pnode->Pleft->Pleft);
		int right_height = get_treeheight(Pnode->Pleft->Pright);
		if (left_height >= right_height)
		{//需要右旋
			
			singR(Pnode);
		}
		else//需要左右旋
		{
			singLR(Pnode);
		}
		/*system("cls");
		PreOrderTraverse(Pnode);*/
	}
	else if (presult == -2)
	{
		int left_height = get_treeheight(Pnode->Pright->Pleft);
		int right_height = get_treeheight(Pnode->Pright->Pright);
		//PreOrderTraverse(Pnode);
		if (left_height >= right_height)
		{//需要左旋

			singRL(Pnode);
		}
		else//需要右左旋
		{
			singL(Pnode);
		}
		/*system("cls");
		PreOrderTraverse(Pnode);*/
	}

	
	return true;
	 
	}

bool Cavltree::deletree(PNODE& Pnode, int nData){

	bool nSucess = true;
	//1判断是否是要插入的节点
	if (Pnode == NULL)
	{
		return false;
	}

	//2 判断要插入的数据和当前的根节点比较大小
	if (nData < Pnode->Data)
	{
		nSucess = deletree(Pnode->Pleft, nData);
	}
	else if (nData > Pnode->Data)
	{
		nSucess = deletree(Pnode->Pright, nData);
	}
	else
	{
		//2.1 如果是当前节点 
		//如果是叶子节点 直接删除
		if (Pnode->Pleft == NULL && Pnode->Pright == NULL)
		{
			Pnode->Data = NULL; 
		//	delete Pnode;  删除了在获取树高的时候出现问题 有空看看
			return false;
		}
		else
		{
			//如果是树干(删除树干的思路就是把树干节点的子节点的 值(左大右小 与插入的时候相反)赋值到当前的树干节点 然后删除的是最后那个叶子节点) 获取当前节点的左右树高
			int left_height = get_treeheight(Pnode->Pleft);
			int right_height = get_treeheight(Pnode->Pright);
			//int presult = left_height - right_height;
			//判断谁高 
			//如果左子树高
			if (left_height> right_height)
			{
				int  max = getmax(Pnode->Pleft);
				Pnode->Data = max;
				deletree(Pnode->Pleft, max);
				//获取左子树的最大值 之后赋值 并到左子树中删除最大值
			}
			else
			{
				//如果右子树高
				//获取右子树的最小值 之后赋值 并到右子树中删除最小值		
				int min = getmin(Pnode->Pright);
				Pnode->Data = min;
				deletree(Pnode->Pright, min);
			} 
		}		
	} 
	// 2.5判断bool值是否为真  否则RETURN
	if (nSucess == false)
	{
		return false;
	}
	//3 判断一下经历了删除之后  本节点是否平衡
	int left_height = get_treeheight(Pnode->Pleft);
	int right_height = get_treeheight(Pnode->Pright);
	int presult = left_height - right_height;
	//如果左边高
	if (presult == 2)
	{ 
		//比较当前节点的左右树高
		int left_height = get_treeheight(Pnode->Pleft->Pleft);
		int right_height = get_treeheight(Pnode->Pleft->Pright);
		if (left_height >= right_height)
		{//需要右旋
			singR(Pnode);
		}
		else//需要左右旋
		{
			singLR(Pnode);
		}
		/*system("cls");
		PreOrderTraverse(Pnode);*/
	}
	else if (presult == -2)
	{
		int left_height = get_treeheight(Pnode->Pright->Pleft);
		int right_height = get_treeheight(Pnode->Pright->Pright);
		//PreOrderTraverse(Pnode);
		if (left_height >= right_height)
		{//需要左旋

			singRL(Pnode);
		}
		else//需要右左旋
		{
			singL(Pnode);
		}
		/*system("cls");
		PreOrderTraverse(Pnode);*/
	}


	return true;

}
void Cavltree::PreOrderTraverse(PNODE& pNode){
	
	if (pNode == NULL) return;
	printf("%d\n", pNode->Data);
	printf("================================\n"   );
	PreOrderTraverse(pNode->Pleft);
	printf("================================\n");
	PreOrderTraverse(pNode->Pright);
}
int Cavltree::getmax(PNODE Pnode){//获取最大值
	int temp=0;
	while (Pnode != NULL)
	 {
		 temp = Pnode->Data;
		 Pnode =  Pnode->Pright;
	 }
	return temp;}
int Cavltree::getmin(PNODE Pnode){//获取最小值
	int temp = 0;
	while (Pnode != NULL)
	{
		temp = Pnode->Data;
		Pnode = Pnode->Pleft;
	}
	return temp;}
Cavltree::Cavltree()
{
}


Cavltree::~Cavltree()
{
}
