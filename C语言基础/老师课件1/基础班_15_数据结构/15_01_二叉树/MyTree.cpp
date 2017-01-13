#include "stdafx.h"
#include "MyTree.h"

CMyTree::CMyTree()
{
	m_nCurrNum = 0;         //��ǰԪ�ظ���
	m_pRoot = nullptr;      //���ڵ�ָ��
}


CMyTree::~CMyTree()
{
	ClearBiTree(m_pRoot);
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
		m_pRoot = new NODE(); //����()ʱ,��ʼֵȫ��cdcdcd,��Ӻ�ȫ��0
		m_pRoot->Data = e;

		m_nCurrNum++;
		if (pNode)
		{
			*pNode = *m_pRoot;
		}
		return RESULT_TRUE;
	}
	//2.����Ƿ�������ȷ����				
	//  2.1 ��������Ƿ��Ѿ����ڴ�ֵ(�������˳�)
	PNODE pReNode;
	Status checkIsHave = LocateElem(m_pRoot, e, pReNode);
	if (checkIsHave == RESULT_TRUE)
	{
		return RESULT_ERR_PARAMTER;
	}
	//3.�����в����½ڵ�,����ֵ��Ϊe,Ԫ�ظ�����1
	//  3.1 �ҵ������λ��(ͨ��2.1�Ѿ��ҵ������ĸ��ڵ�)
	//  3.2 ��Ԫ������,������
	PNODE pNewNode = new NODE();
	pNewNode->Data = e;
	pNewNode->pFather = pReNode;

	if (e<pReNode->Data)
	{
		pReNode->pLChild = pNewNode;
	}
	else if (e>pReNode->Data) {
		pReNode->pRChild = pNewNode;
	}
	//  3.3 ����tree��Ԫ�ظ���
	m_nCurrNum++;
	//4.���÷���ֵ
	if (pNode)
	{
		*pNode = *pNewNode;
	}

	return RESULT_TRUE;
}


/************************************
* Access:    public
* ��������:  ��ֵΪe�Ľڵ�������ɾ��,Ԫ�ظ�����1
*
* �����б�:
*   ElemType e:   [in] ɾ����Ԫ��ֵ
*   PNODE pNode:  [out] ����ɾ���Ľڵ�����(ֻ�и��ڵ�ָ����Ч)
*
* ����ֵ:    Status
*
*************************************/
Status CMyTree::Delete(ElemType e, PNODE pNode /* = nullptr */)
{
	//1.����Ƿ������ʼ����
	if (m_pRoot == nullptr)
	{
		return RESULT_FALSE;
	}
	//2.����Ƿ�������ȷ����				
	//  2.1 ��������Ƿ��Ѿ����ڴ�ֵ(���������˳�)
	PNODE pReNode;
	Status checkIsHave = LocateElem(m_pRoot, e, pReNode);
	if (checkIsHave == RESULT_FALSE)
	{
		return RESULT_ERR_PARAMTER;
	}
	//3.��ֵΪe�Ľڵ�������ɾ��,Ԫ�ظ�����1
	//  3.1 �ж��Ƿ���Ҷ�ӽڵ�(Ҷ�ӽڵ�ֱ��ɾ��)
	//  3.2 �ж���������,�ڸ�����ѡ��Ҫ�����Ľڵ�
	//      (��������ѡ���ֵ,��������ѡ��С)
	//  3.3 ��3.2��ѡ���Ľڵ�,�ظ� 3.1-3.2,
	//      ֱ���ҵ�һ��Ҷ�ӽڵ�
	while (true)
	{
		//3.1 �ж��Ƿ���Ҷ�ӽڵ�(Ҷ�ӽڵ�ֱ��ɾ��)
		if (pReNode->pLChild == nullptr &&
			pReNode->pRChild == nullptr)
		{
			//3.1.1 ������ڵ��������¼
			if (pReNode->pFather->pLChild == pReNode) {
				pReNode->pFather->pLChild = nullptr;
			}
			else {
				pReNode->pFather->pRChild = nullptr;
			}
			//3.1.2 ����Լ�
			if (pNode)
			{
				//��ƽ��ʱʹ��
				//pNode->pFather = pReNode->pFather;
				*pNode = *pReNode;
			}
			delete pReNode;

			break;
		}
		//  3.2 �ж���������,�ڸ�����ѡ��Ҫ�����Ľڵ�
		//      (��������ѡ���ֵ,��������ѡ��С)
		int LChildDepth, RChildDepth;
		BiTreeDepth(pReNode->pLChild, LChildDepth);
		BiTreeDepth(pReNode->pRChild, RChildDepth);

		PNODE pExchangeNode;
		if (LChildDepth > RChildDepth)
		{
			//ȥ������ȡ���ֵ
			GetMax(pReNode->pLChild, pExchangeNode);
		}
		else {
			//ȥ������ȡ��Сֵ
			GetMin(pReNode->pRChild, pExchangeNode);
		}
		pReNode->Data = pExchangeNode->Data;

		//  3.3 ��3.2��ѡ���Ľڵ�,�ظ� 3.1-3.2,
		//      ֱ���ҵ�һ��Ҷ�ӽڵ�
		pReNode = pExchangeNode;
	}

	//3.4 ����tree��Ԫ�ظ���
	m_nCurrNum--;

	return RESULT_TRUE;
}

/************************************
* Access:    public
* ��������:  ����������Ϊ����
*
* �����б�:
*
* ����ֵ:    Status
*
*************************************/
Status CMyTree::ClearBiTree()
{
	return ClearBiTree(m_pRoot);
}

Status CMyTree::ClearBiTree(PNODE & pChildTree)
{
	if (pChildTree == nullptr)
	{
		return RESULT_FALSE;
	}
	ClearBiTree(pChildTree->pLChild);
	ClearBiTree(pChildTree->pRChild);
	//�ͷű��ڵ�
	delete pChildTree;
	pChildTree = nullptr;

	return RESULT_TRUE;
}

/************************************
* Access:    public
* ��������:  ����Ϊ��,����true,���򷵻�false
*
* �����б�:
*   bool & isEmpty:
*
* ����ֵ:    Status
*
*************************************/
Status CMyTree::BiTreeEmpty(bool & isEmpty)
{
	//1.����Ƿ������ʼ����
	if (m_pRoot == nullptr)
	{
		isEmpty = true;
		return RESULT_FALSE;
	}
	//2.����Ϊ��,����true,���򷵻�false
	//  ���Ԫ�ظ���
	if (m_nCurrNum == 0)
	{
		isEmpty = true;
	}
	else {
		isEmpty = false;
	}
	return RESULT_TRUE;
}

/************************************
* Access:    public
* ��������:  �����������
*
* �����б�:
*   PNODE pChildTree:  [in] ��Ҫ����ȵ�����
*   int & nTreeDepth:  [out]�������
*
* ����ֵ:    Status
*
*************************************/
Status CMyTree::BiTreeDepth(PNODE pChildTree, int & nTreeDepth)
{
	//1.����Ƿ������ʼ����
	if (pChildTree == nullptr)
	{
		nTreeDepth = 0;
		return RESULT_FALSE;
	}

	//2.�����������
	int LChildDepth, RChildDepth;
	BiTreeDepth(pChildTree->pLChild, LChildDepth);
	BiTreeDepth(pChildTree->pRChild, RChildDepth);
	if (LChildDepth > RChildDepth)
	{
		nTreeDepth = LChildDepth + 1;
	}
	else {
		nTreeDepth = RChildDepth + 1;
	}

	return RESULT_TRUE;
}

/************************************
* Access:    public
* ��������:  ǰ�����������
*
* �����б�:
*   PNODE pChildTree: [in]��Ҫ����������
*   Visit:            [in]��ÿ���ڵ�,�����ô˺���
*
* ����ֵ:    Status
*
*************************************/
Status CMyTree::PreOrderTraverse(PNODE pChildTree, Status(*Visit)(ElemType &e))
{
	//1.����Ƿ������ʼ����
	//2.����Ƿ�������ȷ����				
	if (pChildTree == nullptr)
	{
		return RESULT_FALSE;
	}

	//3.ǰ�����������
	//  3.1 ������ڵ�
	Visit(pChildTree->Data);
	//  3.2 �������ݹ�
	PreOrderTraverse(pChildTree->pLChild, Visit);
	//  3.3 �������ݹ�
	PreOrderTraverse(pChildTree->pRChild, Visit);

	return RESULT_TRUE;
}

/************************************
* Access:    public
* ��������:  �������������
*
* �����б�:
*   PNODE pChildTree:  [in]��Ҫ����������
*   Visit:             [in]��ÿ���ڵ�,�����ô˺���
*
* ����ֵ:    Status
*
*************************************/
Status CMyTree::InOrderTraverse(PNODE pChildTree, Status(*Visit)(ElemType &e))
{
	//1.����Ƿ������ʼ����
	//2.����Ƿ�������ȷ����	
	if (pChildTree == nullptr)
	{
		return RESULT_FALSE;
	}

	//3.�������������
	//  3.1 �������ݹ�
	InOrderTraverse(pChildTree->pLChild, Visit);
	//  3.2 ������ڵ�
	Visit(pChildTree->Data);
	//  3.3 �������ݹ�
	InOrderTraverse(pChildTree->pRChild, Visit);

	return RESULT_TRUE;
}

/************************************
* Access:    public
* ��������:  �������������
*
* �����б�:
*   PNODE pChildTree:  [in]��Ҫ����������
*   Visit:             [in]��ÿ���ڵ�,�����ô˺���
*
* ����ֵ:    Status
*
*************************************/
Status CMyTree::PostOrderTraverse(PNODE pChildTree, Status(*Visit)(ElemType &e))
{

	//1.����Ƿ������ʼ����
	//2.����Ƿ�������ȷ����
	if (pChildTree == nullptr)
	{
		return RESULT_FALSE;
	}

	//3.ʵ�ֱ������Ĺ���
	//  3.1 �������ݹ�
	PostOrderTraverse(pChildTree->pLChild, Visit);
	//  3.2 �������ݹ�
	PostOrderTraverse(pChildTree->pRChild, Visit);
	//  3.3 ������ڵ�
	Visit(pChildTree->Data);

	return RESULT_TRUE;
}

/************************************
* Access:    public
* ��������:  �������������
*
* �����б�:
*   PNODE pChildTree:  [in]��Ҫ����������
*   * Visit:           [in]��ÿ���ڵ�,�����ô˺���
*
* ����ֵ:    Status
*
*************************************/
Status CMyTree::LevelOrderTraverse(PNODE pChildTree, Status(*Visit)(ElemType &e))
{
	//1.����Ƿ������ʼ����
	//2.����Ƿ�������ȷ����				
	if (pChildTree == nullptr)
	{
		return RESULT_FALSE;
	}

	//3.�������������(��1��,��2�� ...... )
	//  3.1 ����һ������,׼��������Ԫ�����������(��������ʾ�˶��еĹ���)
	PNODE * queue = new PNODE[m_nCurrNum * 3];
	queue[0] = pChildTree;
	int front = 0; //����ͷ�±�
	int rear = 1;  //����β�±�

	while (front < rear)
	{
		// �ѽڵ�,���ղ� ��������,������ ��˳�����β�����е�β��.
		if (queue[front])
		{
			Visit(queue[front]->Data);
			queue[rear++] = queue[front]->pLChild;
			queue[rear++] = queue[front]->pRChild;

		}
		front++;
	}

	delete[]queue;
	return RESULT_TRUE;
}

void CMyTree::show()
{
	printf("\n");
	printTree(m_pRoot, 0);
}

void CMyTree::printTree(PNODE & pChildNode, int nLayer)
{
	if (pChildNode == nullptr)
	{
		return;
	}
	printTree(pChildNode->pRChild, nLayer + 1);
	//��ͬ�Ĳ��,�ÿո����ָ�
	for (int i = 0; i < nLayer; i++)
	{
		printf("        ");
	}
	//���ݴ˽ڵ�ʱ��,���ҽڵ�
	// ��ӡ��ͬ��������(�J)
	//                  �K
	if (pChildNode->pFather == nullptr)
	{
		printf("%6d\n", pChildNode->Data);
	}
	else if (pChildNode->Data < pChildNode->pFather->Data)
	{
		//������
		printf("�K%6d\n", pChildNode->Data);
	}
	else if (pChildNode->Data > pChildNode->pFather->Data)
	{
		//������
		printf("�J%6d\n", pChildNode->Data);
	}
	printTree(pChildNode->pLChild, nLayer + 1);
}

Status CMyTree::LocateElem(PNODE pChildTree, ElemType e, PNODE & pTree)
{
	PNODE pFindNode = nullptr;//����Ҫ���صĽ��ָ��
	//bool isFind = false;
	//1. ����ѭ��,ֱ���ҵ�,����pFindNodeΪnullptr
	while (pChildTree)
	{
		pFindNode = pChildTree;
		//   1.1 Ҫ�ҵ�ֵ�ȵ�ǰ�ڵ��ֵС,��ȥ������������
		//   1.2 Ҫ�ҵ�ֵ�ȵ�ǰ�ڵ��ֵ��,��ȥ������������
		//   1.3 Ҫ�ҵ�ֵ����ǰ�ڵ��ֵ���,�����ѭ��
		if (e<pChildTree->Data)
		{
			pChildTree = pChildTree->pLChild;
		}
		else if (e>pChildTree->Data)
		{
			pChildTree = pChildTree->pRChild;
		}
		else {
			//�ҵ���
			pTree = pFindNode;
			return RESULT_TRUE;
		}
	}
	//û���ҵ�,��pFindNode������ǲ���λ�õĸ��ڵ�ָ��
	pTree = pFindNode;
	return RESULT_FALSE;
}

Status CMyTree::GetMax(PNODE pChildTree, PNODE & pNode)
{
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

Status CMyTree::GetMin(PNODE pChildTree, PNODE & pNode)
{
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
