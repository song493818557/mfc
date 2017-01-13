#include "stdafx.h"
#include "avltree.h"
#include <process.h>

bool Cavltree::inserttree(PNODE& Pnode, int nData){

	bool nSucess = true;
	//1�ж��Ƿ���Ҫ����Ľڵ�
	if (Pnode == NULL)
	{
		Pnode = new NODE;
		Pnode->Data = nData;
		Pnode->Pleft = NULL;
		Pnode->Pright = NULL; 
		return true;
	}
	//2 �ж�Ҫ��������ݺ͵�ǰ�ĸ��ڵ�Ƚϴ�С
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
	//// 2.1�ж�boolֵ�Ƿ�Ϊ��  ����RETURN
	//if (nSucess == false)
	//{
	//	return false;
	//}
	//3 �ж�һ�¾�����ɾ��֮��  ���ڵ��Ƿ�ƽ��
	int left_height = get_treeheight(Pnode->Pleft);
	int right_height = get_treeheight(Pnode->Pright);
	int presult = left_height - right_height;
	//�����߸�
	if (presult == 2)
	{
	   
		//�Ƚϵ�ǰ�ڵ����������
		int left_height = get_treeheight(Pnode->Pleft->Pleft);
		int right_height = get_treeheight(Pnode->Pleft->Pright);
		if (left_height >= right_height)
		{//��Ҫ����
			
			singR(Pnode);
		}
		else//��Ҫ������
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
		{//��Ҫ����

			singRL(Pnode);
		}
		else//��Ҫ������
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
	//1�ж��Ƿ���Ҫ����Ľڵ�
	if (Pnode == NULL)
	{
		return false;
	}

	//2 �ж�Ҫ��������ݺ͵�ǰ�ĸ��ڵ�Ƚϴ�С
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
		//2.1 ����ǵ�ǰ�ڵ� 
		//�����Ҷ�ӽڵ� ֱ��ɾ��
		if (Pnode->Pleft == NULL && Pnode->Pright == NULL)
		{
			Pnode->Data = NULL; 
		//	delete Pnode;  ɾ�����ڻ�ȡ���ߵ�ʱ��������� �пտ���
			return false;
		}
		else
		{
			//���������(ɾ�����ɵ�˼·���ǰ����ɽڵ���ӽڵ�� ֵ(�����С ������ʱ���෴)��ֵ����ǰ�����ɽڵ� Ȼ��ɾ����������Ǹ�Ҷ�ӽڵ�) ��ȡ��ǰ�ڵ����������
			int left_height = get_treeheight(Pnode->Pleft);
			int right_height = get_treeheight(Pnode->Pright);
			//int presult = left_height - right_height;
			//�ж�˭�� 
			//�����������
			if (left_height> right_height)
			{
				int  max = getmax(Pnode->Pleft);
				Pnode->Data = max;
				deletree(Pnode->Pleft, max);
				//��ȡ�����������ֵ ֮��ֵ ������������ɾ�����ֵ
			}
			else
			{
				//�����������
				//��ȡ����������Сֵ ֮��ֵ ������������ɾ����Сֵ		
				int min = getmin(Pnode->Pright);
				Pnode->Data = min;
				deletree(Pnode->Pright, min);
			} 
		}		
	} 
	// 2.5�ж�boolֵ�Ƿ�Ϊ��  ����RETURN
	if (nSucess == false)
	{
		return false;
	}
	//3 �ж�һ�¾�����ɾ��֮��  ���ڵ��Ƿ�ƽ��
	int left_height = get_treeheight(Pnode->Pleft);
	int right_height = get_treeheight(Pnode->Pright);
	int presult = left_height - right_height;
	//�����߸�
	if (presult == 2)
	{ 
		//�Ƚϵ�ǰ�ڵ����������
		int left_height = get_treeheight(Pnode->Pleft->Pleft);
		int right_height = get_treeheight(Pnode->Pleft->Pright);
		if (left_height >= right_height)
		{//��Ҫ����
			singR(Pnode);
		}
		else//��Ҫ������
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
		{//��Ҫ����

			singRL(Pnode);
		}
		else//��Ҫ������
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
int Cavltree::getmax(PNODE Pnode){//��ȡ���ֵ
	int temp=0;
	while (Pnode != NULL)
	 {
		 temp = Pnode->Data;
		 Pnode =  Pnode->Pright;
	 }
	return temp;}
int Cavltree::getmin(PNODE Pnode){//��ȡ��Сֵ
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
