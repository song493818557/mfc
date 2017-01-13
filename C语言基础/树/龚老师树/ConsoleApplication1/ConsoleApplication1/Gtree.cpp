#include "stdafx.h"
#include "Gtree.h" 
CMyTree::CMyTree()
{
	m_nCurrNum = 0;         //��ǰԪ�ظ���
	m_pRoot = nullptr;      //���ڵ�ָ��
}
 
CMyTree::~CMyTree()
{
	//ClearBiTree(m_pRoot);
}

/************************************
* Access:    public
* ��������:  �����в����½ڵ�,����ֵ��Ϊe,Ԫ�ظ�����1
*
* �����б�:
*   ElemType e:   [in]  �������ֵ
*   PNODE pNode:  [out] ���ز���Ľڵ�����
*
* ����ֵ:    Status
*
*************************************/
Status CMyTree::Insert(ElemType e, PNODE pNode /* = nullptr */)
{
	//1.����Ƿ������ʼ����
	if (m_pRoot == nullptr)
	{
		//˵��������û�и��ڵ�,Ԫ��ֻ�ܲ��ڸ�λ��
		pNode = new NODE();
		pNode->Data = e;
		m_pRoot = pNode;
		m_nCurrNum++;
		return RESULT_TRUE;
	} 
	//2.����Ƿ�������ȷ����				
		//  2.1 ��������Ƿ��Ѿ����ڴ�ֵ(�������˳�)
	PNODE Prenode; 
	Status checkIsHava = LocateElem(m_pRoot, e, Prenode);
	if (checkIsHava == RESULT_TRUE)
	{
		return RESULT_ERR_PARAMTER;//�ҵĵ� ���ز�������
	}
	//3.�����в����½ڵ�,����ֵ��Ϊe,Ԫ�ظ�����1
	//  3.1 �ҵ������λ��(ͨ��2.1�Ѿ��ҵ������ĸ��ڵ�)
	PNODE Pnewnode = new  NODE();
	Pnewnode->Data = e;
	Pnewnode->pFather = Prenode;//�����ڵ�ĵ�ַ�ȸ�ֵ��
	// 3.2�ж���ֵӦ�÷��ı�	���ڸ�ֵ�ұ�			С�ڸ�ֵ���	
	(e>Prenode->Data)?Prenode->pRChild = Pnewnode:Prenode->pLChild = Pnewnode;
	//3.3 treeԪ�ظ�����һ
	m_nCurrNum++;
	if (pNode)
	{
		*pNode = *Pnewnode;
	}
	return RESULT_TRUE;
}

Status CMyTree::LocateElem(PNODE pChildTree, ElemType e, PNODE & pTree){
	
	PNODE pFindNode = nullptr;//����Ҫ���صĽ��ָ��
	while (pChildTree)
	{
		pFindNode = pChildTree;
		//   1.1 Ҫ�ҵ�ֵ�ȵ�ǰ�ڵ��ֵС,��ȥ������������
		//   1.2 Ҫ�ҵ�ֵ�ȵ�ǰ�ڵ��ֵ��,��ȥ������������
		//   1.3 Ҫ�ҵ�ֵ����ǰ�ڵ��ֵ���,�����ѭ��
		if (e<pFindNode->Data)
		{
			pChildTree = pChildTree->pLChild;
		} 
		else if (e>pFindNode->Data)
		{
			pChildTree = pChildTree->pRChild;
		}
		else 
		{
			pTree = pFindNode;
			return RESULT_TRUE;
		} 
	} 
	//û���ҵ�,��pFindNode�ı�����ǲ���λ�õĸ��ڵ�
	pTree = pFindNode;
	return RESULT_FALSE;
}

Status CMyTree::Delete( ElemType e, PNODE pNode  ){
	//�ж��Ƿ��ж�������ɾ��
	if (m_pRoot == NULL)
	{
		RESULT_FALSE;
	}
	PNODE Prenode;
	Status CheckIsHava = LocateElem(m_pRoot, e, Prenode);
	if (CheckIsHava == RESULT_FALSE) //�ҵ��� Ӧ�ÿ���Ҫ��
	{
		return RESULT_ERR_PARAMTER;
	}
	while (1)
	{
		//3.1 �ж��Ƿ���Ҷ�ӽڵ�(Ҷ�ӽڵ�ֱ��ɾ��)
		if (Prenode->pLChild == nullptr && Prenode->pRChild == nullptr)
		{
			//3.1.1 ������ڵ��������¼
			if (Prenode->pFather->pLChild == Prenode)
			{
				Prenode->pFather->pLChild == nullptr;
			}
			else
			{
				Prenode->pFather->pRChild == nullptr;
			} 
			if (pNode)
			{
				//��ƽ��ʱʹ�ñ��游�ڵ�  //pNode->pFather = pReNode->pFather;
				*pNode = *Prenode;
			}
			//3.1.2 ����Լ�
			//delete Prenode;
			Prenode = nullptr;  
			return RESULT_TRUE;
		} 
			//  3.2 �ж���������,�ڸ�����ѡ��Ҫ�����Ľڵ�
			int TLheight, TRheight;
			BiTreeDepth(Prenode->pLChild, TLheight);
			BiTreeDepth(Prenode->pRChild, TRheight);
			PNODE Temp;
			if (TLheight>=TRheight)
			{
				//      (��������ѡ���ֵ,��������ѡ��С)
				//ȥ������ȡ���ֵ
				GetMax(Prenode->pLChild, Temp);  
			}
			else
			{//ȥ������ȡ��Сֵ
				GetMin(Prenode->pRChild, Temp); 
			}   
			Prenode->Data = Temp->Data;
			Prenode = Temp; 
	  }
		//3.4 ����tree��Ԫ�ظ���
		m_nCurrNum--; 
		return RESULT_TRUE;
}
/**ȡ�����е����ֵ*/
Status CMyTree::GetMax(PNODE pChildTree, PNODE & pNode){
	if (pChildTree == nullptr)
	{
		return RESULT_FALSE;
	}
	while (pChildTree)
	{
		pNode = pChildTree;
		pChildTree = pChildTree->pRChild;
	}
	return RESULT_TRUE;
}
/**ȡ�����е���Сֵ*/
Status CMyTree::GetMin(PNODE pChildTree, PNODE & pNode){
	if (pChildTree == nullptr)
	{
		return RESULT_FALSE;
	}
	while (pChildTree)
	{
		pNode = pChildTree;
		pChildTree = pChildTree->pLChild;
	}
	return RESULT_TRUE;
}
Status CMyTree::BiTreeDepth( /**�����������*/
	PNODE pChildTree,//[in] ��Ҫ����ȵ�����
	int & nTreeDepth //[out]�������
	){
	if (pChildTree == nullptr)
	{
		nTreeDepth = 0;
		return RESULT_FALSE;
	}
	int Tleft =  BiTreeDepth(pChildTree->pLChild, Tleft);
	int Tright = BiTreeDepth(pChildTree->pLChild, Tright); 
	nTreeDepth =  (Tleft > Tright ? Tleft : Tright)+1;
	return RESULT_TRUE;
}