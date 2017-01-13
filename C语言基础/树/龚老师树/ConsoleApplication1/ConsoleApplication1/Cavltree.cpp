#include "stdafx.h"
#include "Cavltree.h"


Cavltree::Cavltree()
{
}
 
Cavltree::~Cavltree()
{
}
Status Cavltree::Insert( ElemType e,   PNODE pNode )
{
	//1. ��������,���ز���ڵ㸱��
	NODE insNode;
	Status result = CMyTree::Insert(e, &insNode); 
	if (result != RESULT_TRUE)
	{
		return RESULT_FALSE;
	}
	PNODE pFather = insNode.pFather; 
	BalanceTree(pFather);
	//3.���÷���ֵ
	if (pNode)
	{
		*pNode = insNode;
	}
	return RESULT_TRUE;
}

Status Cavltree::Delete(ElemType e, PNODE pNode)
{
	//1. ��������,���ز���ڵ㸱��
	NODE delNode;
	Status result = CMyTree::Insert(e, &delNode);
	if (result != RESULT_TRUE)
	{
		return RESULT_FALSE;
	}
	PNODE pFather = delNode.pFather;
	BalanceTree(pFather);
	//3.���÷���ֵ
	if (pNode)
	{
		*pNode = delNode;
	}
	return RESULT_TRUE;
}
Status Cavltree::BalanceTree(PNODE & pNode){
	while (pNode!=nullptr)
	{
		//1.�����������ʼ��ת
		int Pleft, Pright;
		BiTreeDepth(pNode->pLChild, Pleft);
		BiTreeDepth(pNode->pRChild, Pright);
		//1.1 - 1.2
		if ((Pleft - Pright) == 2)
		{ 
			BiTreeDepth(pNode->pLChild->pLChild, Pleft);
			BiTreeDepth(pNode->pLChild->pRChild, Pright);
				//  1.1 �������� - �������� > 1 ; ��.�������� >= ��.��������
				//  1.2 �������� - �������� > 1 ; ��.��������  < ��.��������
				//      �ҵ���		  //      ������
				//      K2			 //      K2
				//     /			 //     /
				//    K1			 //    K1
				//   / 				 //     \
				//  N   			 //      N
			(Pleft >= Pright) ? SingleR(pNode) : DoubleLR(pNode); 
		}
		else if ((Pleft - Pright) == -2)
		{
			BiTreeDepth(pNode->pRChild->pLChild, Pleft);
			BiTreeDepth(pNode->pRChild->pRChild, Pright);
			//1.3 - 1.4
			//  1.3 �������� - �������� > 1 ; ��.�������� >= ��.��������
			//  1.4 �������� - �������� > 1 ; ��.��������  < ��.��������
			//      ����			    ������
			//      K2				   K2
			//       \				    \
			//        K1			     K1
			//         \			    /
			//          N			   N
			(Pleft >= Pright) ? SingleL(pNode) : DoubleRL(pNode);
		} 
		//2. �������ϵ���
		pNode = pNode->pFather;
		
	}
	return RESULT_TRUE;
}

/**�ҵ���*/
Status Cavltree::SingleR(PNODE & pNode){
	//�������� - �������� > 1 ; ��.�������� >= ��.��������
	//      �ҵ���
	//      K2              K1
	//     /               / \
	//    K1       ->     N   K2
	//   / \                 /
	//  N   T               T
	// ����:
	//   1. ��K1�����������浽K2����������
	//   2. ��K1����������ΪK2
	// 
	//1. ��ȷ�� K2,K1
	PNODE K2 = pNode;
	PNODE K1 = pNode->pLChild;
	PNODE T = K1->pRChild;
	K2->pLChild = K1->pRChild;
	K1->pRChild = K2;
	K2->pFather = K1;//�����ڵ��K1
	if (K1->pFather == nullptr)
	{
		//5.1 ����ƽ��ĵ�(pNode)�Ǹ��ڵ�, ֻ��ı� m_pRoot
		m_pRoot = K1;
	}
	else if (K2->pFather->pLChild == K2)//���K2���ڵ������������K2 
	{
		K2->pFather->pLChild = K1;
		K1->pFather = K2->pFather->pLChild; 
	}
	else
	{
		K2->pFather->pRChild = K1;
		K1->pFather = K2->pFather->pRChild;
	} 
	//����K1
//	pNode = K1;
	return RESULT_TRUE; }
/**����*/
Status Cavltree::SingleL(PNODE & pNode){
	PNODE K2 = pNode;
	PNODE K1 = K2->pRChild;
	PNODE T = K1->pLChild;

	//2. ��K1�����������浽K2����������
	K2->pRChild = T;

	//3. ��K1����������ΪK2
	K1->pLChild = K2;

	//4. ���ýڵ��еĸ��ڵ�ָ����Ϣ
	K1->pFather = K2->pFather;
	K2->pFather = K1;
	if (T)
	{
		T->pFather = K2;
	}

	//5. ���ⲿ����������(�޸��ⲿָ��,ָ���µľֲ����ڵ�)
	//    5.1 ����ƽ��ĵ�(pNode)�Ǹ��ڵ�, ֻ��ı� m_pRoot
	if (K1->pFather == nullptr)
	{
		m_pRoot = K1;
	}
	else if (K1->Data < K1->pFather->Data)
	{
		//    5.2 ����ƽ��ĵ�(pNode)���丸�ڵ�����ӽڵ�
		K1->pFather->pLChild = K1;
	}
	else {
		//    5.3 ����ƽ��ĵ�(pNode)���丸�ڵ�����ӽڵ�
		K1->pFather->pRChild = K1;
	}

	return RESULT_TRUE;
}
/**����˫��*/
Status Cavltree::DoubleLR(PNODE & pNode){
	SingleL(pNode->pLChild);
	SingleR(pNode);

	return RESULT_TRUE;
}
/**����˫��*/
Status Cavltree::DoubleRL(PNODE & pNode){
	SingleR(pNode->pRChild);
	SingleL(pNode);

	return RESULT_TRUE;
}