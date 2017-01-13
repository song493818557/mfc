#include "stdafx.h"
#include "Ctree.h"


Ctree::Ctree() :m_pRoot(NULL){}
/***************************************
������: PreOrderTraverse
����:ǰ�����
����0:��ʼλ��  
˵��:
/***************************************/
void Ctree::PreOrderTraverse(PNODE& pNode){
	if (pNode == NULL) return;
	printf("%d\n", pNode->nData);
	PreOrderTraverse(pNode->pLeft);
	PreOrderTraverse(pNode->pRight);
}

 /***************************************
������: Insert
����:�����в���һ������
����0:��Ҫ��ӵ�����
����1:���ڵõ�һ��������
����ֵ �����жϴ˺����Ƿ�ִ�гɹ�
˵��:
/***************************************/
bool Ctree::Insert(
	int nEle,//����0 Ҫ���������
	int & nError //����1 ������
	)
{
	return InsertNode(nEle, m_pRoot, nError);
}
/***************************************
������: GetHeight
����:�����в���һ������
PNODE pTree //Ҫ��ȡ���ߵ�����
����ֵ �����жϴ˺����Ƿ�ִ�гɹ�
˵��:
/***************************************/
int Ctree::GetHeight(
	PNODE pTree //Ҫ��ȡ���ߵ�����
	)
{
	if (pTree == NULL)
	{
		return 0;
	}
	int nLeftHeight = GetHeight(pTree->pLeft);
	int nRightHeight = GetHeight(pTree->pRight);
	return (nLeftHeight > nRightHeight ? nLeftHeight : nRightHeight) + 1;
}

/***************************************
������: GetMax
����:��ȡ���ֵ��ֵ
����0:Ҫ��ȡ���ֵ������
����1:���ڵõ�һ�����ֵ
����ֵ �����жϴ˺����Ƿ�ִ�гɹ�
˵��:
/***************************************/
bool Ctree::GetMax(
	PNODE pTree,//Ҫ��ȡ���ֵ������
	int & nMax//���ڵõ�����ֵ
	)
{
	if (pTree == nullptr)
	{
		return false;
	}
	while (pTree)
	{
		nMax = pTree->nData;
		pTree = pTree->pRight;
	}
	return true;
}

/***************************************
������: GetMax
����:��ȡ��Сֵ��ֵ
����0:Ҫ��ȡ��Сֵ������
����1:���ڵõ�һ����Сֵ
����ֵ �����жϴ˺����Ƿ�ִ�гɹ�
˵��:
/***************************************/
bool Ctree::GetMin(
	PNODE pTree,//Ҫ��ȡ���ֵ������
	int & nMin//���ڵõ�����ֵ
	)
{
	if (pTree == nullptr)
	{
		return false;
	}
	while (pTree)
	{
		nMin = pTree->nData;
		pTree = pTree->pLeft;
	}
	return true;
}

/***************************************
������: SingleL
����:�˽ڵ�ΪԲ������
����0:Ҫ��ת�Ľڵ� 
����ֵ �����жϴ˺����Ƿ�ִ�гɹ�
˵��:
/***************************************/
bool Ctree::SingleL(  /*�˽ڵ�ΪԲ������ */
	PNODE& pNode//Ҫ��ת�Ľڵ�
	)
{
	//      K2					K1
	//        \				   /  \
	//          K1			  K2   N
	//           \
	//             N
	PNODE K2 = pNode;
	PNODE K1 = pNode->pRight;
	K2->pRight = K1->pLeft;
	K1->pLeft = K2;
	pNode = K1;
	return true;
}


/***************************************
������: SingleR
����:�˽ڵ�ΪԲ������
����0:Ҫ��ת�Ľڵ�
����ֵ �����жϴ˺����Ƿ�ִ�гɹ�
˵��:
/***************************************/
bool Ctree::SingleR(  /*�˽ڵ�ΪԲ������ */
	PNODE& pNode//Ҫ��ת�Ľڵ�
	)
{
	//        K2			K1
	//       /  		   /  \
    //      K1			  N   K2
	//     /    
	//    N
	PNODE K2 = pNode;
	PNODE K1 = pNode->pLeft;
	K2->pLeft = K1->pRight;
	K1->pRight = K2;
	pNode = K1;
	return true;
}


/***************************************
������: SingleLR
����:�˽ڵ�ΪԲ��������
����0:Ҫ��ת�Ľڵ�
����ֵ �����жϴ˺����Ƿ�ִ�гɹ�
˵��:
/***************************************/
bool Ctree::SingleLR(  /*�˽ڵ�ΪԲ�������� */
	PNODE& pNode//Ҫ��ת�Ľڵ�
	)
{						                         
	//        K2		     K2                   N
	//       /  		    /                    / \
    //       K1		->>	   N	     ->>        K1  K2
	//       \  		  /                   
	//        N			 K1                  
	SingleL(pNode->pLeft);
	SingleR(pNode);
	return true;
}


/***************************************
������: SingleRL
����:�˽ڵ�ΪԲ��������
����0:Ҫ��ת�Ľڵ�
����ֵ �����жϴ˺����Ƿ�ִ�гɹ�
˵��:
/***************************************/
bool Ctree::SingleRL(  /*�˽ڵ�ΪԲ�������� */
	PNODE& pNode//Ҫ��ת�Ľڵ�
	)
{
	//    K2    		 K2                       N
	//    \     		  \                      / \
  //       K1		->>	   N	     ->>        K2  K1
	//    /     		    \                 
	//   N      		     K1            
	SingleL(pNode->pRight);
	SingleR(pNode);
	return true;
}
/***************************************
������: InsertNode
����:�˽ڵ�ΪԲ��������
����0:Ҫ��ת�Ľڵ�
����ֵ �����жϴ˺����Ƿ�ִ�гɹ�
˵��:
/***************************************/
bool Ctree::InsertNode(
	int nEle,//����0:Ҫ��ӵ�����
	PNODE& pNode,//����1:��Ҫ���������
	int &nError//����2:���ڵõ�һ��������
	){
	bool nSucess = true;
//1�ж��Ƿ���Ҫ����Ľڵ�
	if (pNode == NULL)
	{
	    pNode = new NODE;
		pNode->nData = nEle;
		pNode->pRight =  pNode->pLeft = NULL;
		return true;
	}
//2 �ж�Ҫ��������ݺ͵�ǰ�ĸ��ڵ�Ƚϴ�С
	if (nEle > pNode->nData)
	{
		nSucess = InsertNode(nEle, pNode->pRight, nError);
	}
	else if (nEle < pNode->nData){

		nSucess = InsertNode(nEle, pNode->pLeft, nError);
	}
	// 2.1�ж�boolֵ�Ƿ�Ϊ��  ����RETURN
	if (nSucess == false)
	{
		return false;
	}
//3 �ж�һ�¾�����ɾ��֮��  ���ڵ��Ƿ�ƽ��
	int nLheight = GetHeight(pNode->pLeft);
	int nRheight = GetHeight(pNode->pRight);
	int nSub = nLheight - nRheight;// -2  2 �����ֵ����2  �Ų�ƽ��
	//�����߸�
	if (nSub == 2)
	{
		nLheight = GetHeight(pNode->pLeft->pLeft);
		nRheight = GetHeight(pNode->pLeft->pRight);
		//�Ƚϵ�ǰ�ڵ����������
		if (nLheight >= nRheight)
		{
			SingleR(pNode);//��Ҫ����
		}
		else
		{
			SingleLR(pNode);//��Ҫ������
		}		
	}
	//����ұ߸�
	else if (nSub == -2)
	{
		nLheight = GetHeight(pNode->pRight->pLeft);
		nRheight = GetHeight(pNode->pRight->pRight);
		//�Ƚϵ�ǰ�ڵ����������
		if (nLheight >= nRheight)
		{
			SingleL(pNode);//��Ҫ����
		}
		else
		{
			SingleRL(pNode);//��Ҫ������
		}
	}
	return true;
}

/***************************************
������: DeleteNode
����:�˽ڵ�ΪԲ��������
����0:Ҫ��ת�Ľڵ�
����ֵ �����жϴ˺����Ƿ�ִ�гɹ�
˵��:
/***************************************/
bool Ctree::DeleteNode(
	int nEle,//����0:Ҫ��ӵ����� 
	PNODE &pTree,//����1:Ҫɾ���ڵ������
	int &nError//����2:���ڵõ�һ��������
	){
	bool nSucess = true;
	//1�ж���Ϊ�սڵ�
	if (pTree == NULL)
	{
		return false;
	}
	//2 �ж�Ҫɾ�������ݺ͵�ǰ�ĸ��ڵ�Ƚϴ�С
	if (nEle > pTree->nData)//�ұ���
	{
		nSucess = DeleteNode(nEle, pTree->pRight, nError);
	}
	else if (nEle < pTree->nData){

		nSucess = DeleteNode(nEle, pTree->pLeft, nError);
	}
	else
	{
		//2.1 ����ǵ�ǰ�ڵ� 
		//�����Ҷ�ӽڵ� ֱ��ɾ��
		if (pTree->pLeft == NULL && pTree->pRight == NULL)
		{
			delete pTree;
			pTree = NULL;
			return true;
		}
		//���������(ɾ�����ɵ�˼·���ǰ����ɽڵ���ӽڵ�� ֵ(�����С ������ʱ���෴)��ֵ����ǰ�����ɽڵ� Ȼ��ɾ����������Ǹ�Ҷ�ӽڵ�) ��ȡ��ǰ�ڵ����������		
		int nLheight = GetHeight(pTree->pLeft);
		int nRheight = GetHeight(pTree->pRight);
		//�ж�˭�� 
		if (nLheight > nRheight)//�����������
		{
			//��ȡ�����������ֵ ֮��ֵ ������������ɾ�����ֵ
			int nMax = 0;
			GetMax(pTree->pLeft, nMax);
			pTree->nData = nMax;
			DeleteNode(nMax, pTree->pLeft, nError);
		}
		//�����������
		else
		{
			//��ȡ����������Сֵ ֮��ֵ ������������ɾ����Сֵ
			int nMin = 0;
			GetMax(pTree->pRight, nMin);
			pTree->nData = nMin;
			DeleteNode(nMin, pTree->pRight, nError);
		}		
	}	
	// 2.5�ж�boolֵ�Ƿ�Ϊ��  ����RETURN
	if (nSucess == false)
	{
		return false;
	} 
	//3 �ж�һ�¾�����ɾ��֮��  ���ڵ��Ƿ�ƽ��
	int nLheight = GetHeight(pTree->pLeft);
	int nRheight = GetHeight(pTree->pRight);
	int nSub = nLheight - nRheight;
	//�����߸�
	
	if (nSub == 2)
	{
		nLheight = GetHeight(pTree->pLeft->pLeft);
		nRheight = GetHeight(pTree->pLeft->pRight);
		// �Ƚϵ�ǰ�ڵ����������
		if (nLheight >= nRheight)
		{
			SingleR(pTree->pLeft);//��Ҫ����
		}
		else
		{
			SingleLR(pTree->pLeft);//��Ҫ������
		} 
	}
	//����ұ߸�
	else if (nSub == -2)
	{
		//�Ƚϵ�ǰ�ڵ����������
		nLheight = GetHeight(pTree->pRight->pLeft);
		nRheight = GetHeight(pTree->pRight->pRight);
		if (nLheight <= nRheight)
		{
			SingleR(pTree->pRight);//��Ҫ����
		}
		else
		{
			SingleLR(pTree->pRight);//��Ҫ������
		} 
	}
	return true;
}

bool Ctree::Delete(
	int nEle,//����0 Ҫ���������
	int & nError //����1 ������
	){
	return DeleteNode(nEle, m_pRoot, nError);
}