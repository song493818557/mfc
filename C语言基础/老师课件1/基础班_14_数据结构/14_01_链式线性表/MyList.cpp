#include "stdafx.h"
#include "MyList.h"


CMyList::CMyList()
{
	m_nCurrNum = 0;       //��ǰԪ�ظ���
	m_pListHead= nullptr; //ָ����һ���ڵ��λ��
}


CMyList::~CMyList()
{
	//ClearList();
}

/************************************
* Access:    public 
* ��������:  ��L�е�i��Ԫ��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
* 
* �����б�:
*   ElementType e:   [in] �������Ԫ��
*   int i:           [in] �����λ��
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyList::InsertList(ElementType e, int i /*= -1 */)
{
	//1.����Ƿ������ʼ����
	if (m_pListHead == nullptr)
	{
		m_pListHead = new NODE;
		m_pListHead->data = e;
		m_pListHead->pNext = m_pListHead;
		m_pListHead->pPrev = m_pListHead;

		m_nCurrNum++;
		return RESULT_TRUE;
	}
			
	//2.����Ƿ�������ȷ����				
	//  2.1 �������������ֵ
	if (i==-1)
	{
		i = m_nCurrNum;
	}
	//  2.2 �������Ƿ���Ч
	if (i<0||i>m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}
	//3.ʵ�ֱ������Ĺ���
	//  ��L�е�i��Ԫ��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
	//3.1 �ҵ�Ҫ�����λ��
	/*
	    44,55,**,66,77,88
	       ��(pPos)
		2
	         
	*/
	//  nPosΪҪ����λ�õ�ǰһ��Ԫ��
	PNODE pPos = m_pListHead;
	for (int pos = 0;pos<i-1;pos++)
	{
		pPos = pPos->pNext;
	}
	//3.2 ����һ���½ڵ�
	PNODE pNewNode = new NODE;        //�����½ڵ� **
	pNewNode->data = e;               //���������
	pNewNode->pPrev = pPos;           //���ָ����pPrev( ��һ���ڵ��� 66 )
	pNewNode->pNext = pPos->pNext;    //���ָ����pNext( ��һ���ڵ��� 77 )
	//3.3 ������λ��
	pPos->pNext = pNewNode;           //�ı����λ��ǰһ��Ԫ�ص�ָ���� (���ָ�� pNext )
	pPos->pNext->pPrev = pNewNode;    //�ı����λ�ú�һ��Ԫ�ص�ָ���� (ǰ��ָ�� pPrev )

	//3.4 �������ݳ�Ա
	m_nCurrNum++;

	return RESULT_TRUE;
}

/************************************
* Access:    public 
* ��������:  ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
* 
* �����б�:
*   ElementType & e:  [out]��ɾ����Ԫ��
*   int i:            [in] ɾ����λ��
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyList::DeleteList( ElementType & e, int i/*=-1 */)
{
	//1.����Ƿ������ʼ����
	if (m_pListHead == nullptr)
	{
		return RESULT_FALSE;
	}
			
	//2.����Ƿ�������ȷ����				
	//  2.1 �������������ֵ
	if (i==-1)
	{
		i = m_nCurrNum - 1;
	}
	//  2.2 �������Ƿ���Ч
	if (i<0||i>=m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}
	//3.ʵ�ֱ������Ĺ���
	//  ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
	/*
	    44,55,X66X,77,88
	       ��(pPos)
		2
	         
	*/
	//  nPosΪҪɾ��λ�õ�ǰһ��Ԫ��

	//3.1 �ҵ�ɾ��λ�õ�ǰһ��Ԫ��
	PNODE pPos = m_pListHead;
	for (int pos = 0;pos<i-1;pos++)
	{
		pPos = pPos->pNext;
	}
	//3.2 ��ȡ����ֵ
	PNODE delNode = pPos->pNext;        //��Ҫ��ɾ����Ԫ��
	e = delNode->data;                  //��Ҫ��ɾ����Ԫ�ص���������Ϊ����ֵ

	//3.3 ɾ��Ԫ��
	pPos->pNext = delNode->pNext;       //ǰһ��Ԫ�صĺ��ָ��,ָ���ɾ��Ԫ�صĺ�һ��Ԫ��
	                                    //(����������ҵ�ʱ����Ҳ�������)
	delNode->pNext->pPrev = pPos;       //��һ��Ԫ�ص�ǰ��ָ��,ָ���ɾ��Ԫ�ص�ǰһ��Ԫ��
										//(����������ҵ�ʱ����Ҳ�������)

	delete delNode;

	//4. �������ݳ�Ա
	m_nCurrNum--;
	if (m_nCurrNum==0)
	{
		m_pListHead = nullptr;
	}

	return RESULT_TRUE;
}
