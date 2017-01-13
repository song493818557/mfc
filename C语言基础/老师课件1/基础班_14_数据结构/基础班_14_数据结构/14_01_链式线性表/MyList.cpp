#include "stdafx.h"
#include "MyList.h"


CMyList::CMyList()
{
	m_nCurrNum = 0;       //��ǰԪ�ظ���
	m_pListHead= nullptr; //ָ����һ���ڵ��λ��
}


CMyList::~CMyList()
{
	ClearList();
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
	if (i==-1)				//���뵽�����β�ڵ�֮��
	{
		i = m_nCurrNum;
	}
	bool isNewHead = false;
	if (i==0)				//���뵽�����ͷ�ڵ�֮ǰ
	{
		i = m_nCurrNum;     //ѭ�������� ͷ�ڵ��ǰһ���ڵ�Ϊβ�ڵ�
		isNewHead = true;   //��Ҫ����ͷ�ڵ�ָ��
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
	pNewNode->pNext->pPrev = pNewNode;//�ı����λ�ú�һ��Ԫ�ص�ָ���� (ǰ��ָ�� pPrev )

	//3.4 �������ݳ�Ա
	m_nCurrNum++;
	if (isNewHead)
	{
		m_pListHead = pNewNode;
	}
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
	if (i == -1)			                //ɾ�������β�ڵ�
	{
		i = m_nCurrNum - 1;
	}
	if (i == 0)								//ɾ�������ͷ�ڵ�
	{
		//2.1.1 ��ȡ����ֵ
		PNODE pPos    = m_pListHead->pPrev; //Ҫɾ��λ�õ�ǰһ��Ԫ��
		PNODE delNode = m_pListHead;        //��Ҫ��ɾ����Ԫ��
		e = delNode->data;                  //��Ҫ��ɾ����Ԫ�ص���������Ϊ����ֵ

		//2.1.2 ɾ��Ԫ��
		pPos->pNext = delNode->pNext;       //ǰһ��Ԫ�صĺ��ָ��,ָ���ɾ��Ԫ�صĺ�һ��Ԫ��
											//(����������ҵ�ʱ����Ҳ�������)
		delNode->pNext->pPrev = pPos;       //��һ��Ԫ�ص�ǰ��ָ��,ָ���ɾ��Ԫ�ص�ǰһ��Ԫ��
											//(����������ҵ�ʱ����Ҳ�������)

		delete delNode;

		//2.1.3 �������ݳ�Ա
		m_pListHead = pPos->pNext;          //ѭ�������� ͷ�ڵ��ǰһ���ڵ�Ϊβ�ڵ�
		m_nCurrNum--;   
		return RESULT_TRUE;
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

/************************************
* Access:    public 
* ��������:  ��List����Ϊ�ձ�
* 
* �����б�:
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyList::ClearList( )
{
	//1.����Ƿ������ʼ����
	if (m_pListHead == nullptr)
	{
		return RESULT_FALSE;
	}
	//2.����Ƿ�������ȷ����				
	//  2.1 �������������ֵ
	//  2.2 �������Ƿ���Ч

	//3.ʵ�ֱ������Ĺ���
	//  ��List����Ϊ�ձ�
	PNODE TempNode = m_pListHead;
	for (int i = 0; i < m_nCurrNum; i++)
	{
		PNODE DelNode = TempNode ;
		TempNode = TempNode->pNext;
		delete DelNode;
	}

	//4. �������ݳ�Ա
	m_nCurrNum = 0;
	m_pListHead = nullptr;

	return RESULT_TRUE;
}

/************************************
* Access:    public 
* ��������:  ���Ա��Ƿ�Ϊ��
* 
* �����б�:
*   bool & isEmpty: [out] �Ƿ�Ϊ��
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyList::ListEmpty( bool & isEmpty )
{
	//1.����Ƿ������ʼ����
	if (m_pListHead == nullptr)
	{
		isEmpty = true;
		return RESULT_FALSE;
	}
	//2.���Ա��Ƿ�Ϊ��
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
* ��������:  ���Ա���Ԫ�صĸ���
* 
* �����б�:
*   int & length:  [out] ����
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyList::ListLength(int & length )
{
	//1.����Ƿ������ʼ����
	if (m_pListHead == nullptr)
	{
		length = 0;
		return RESULT_FALSE;
	}
	//2.����Ƿ�������ȷ����				
	//  2.1 �������������ֵ
	//  2.2 �������Ƿ���Ч

	//3.ʵ�ֱ������Ĺ���
	//  ���Ա���Ԫ�صĸ���
	length = m_nCurrNum;
	return RESULT_TRUE;
}

/************************************
* Access:    public 
* ��������:  ��ȡ���Ա���ָ��λ���ϵ�Ԫ��
* 
* �����б�:
*   int i:            [in] ��ȡ�ĸ�λ���ϵ�Ԫ��
*   ElementType & e:  [out]��ȡ��Ԫ��ֵ
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyList::GetElem( int i,  ElementType & e )
{
	//1.����Ƿ������ʼ����
	if (m_pListHead == nullptr)
	{
		return RESULT_FALSE;
	}
	//2.����Ƿ�������ȷ����				
	//  2.1 �������������ֵ
	//  2.2 �������Ƿ���Ч
	if (i < 0 || i >= m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}
	//3.ʵ�ֱ������Ĺ���
	PNODE pFindNode = m_pListHead;
	for (int j = 0; j < i; j++)
	{
		pFindNode = pFindNode->pNext;
	}
	//4.���÷���ֵ
	e = pFindNode->data;

	return RESULT_TRUE;
}

/************************************
* Access:    public 
* ��������:  �������Ա��д�ָ��λ�ÿ�ʼ,�ҵ��ĵ�һ����e��ȵ�Ԫ���±�(û�ҵ�����-1)
* 
* �����б�:
*   int i:          [in] ���ĸ�λ�ÿ�ʼ��
*   ElementType e:  [in] ���ĸ�ֵ 
*   int & pos:      [out]��ֵ����λ��
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyList::LocateElem( int i, ElementType e, int & pos )
{
	//1.����Ƿ������ʼ����
	if (m_pListHead == nullptr)
	{
		return RESULT_FALSE;
	}
	//2.����Ƿ�������ȷ����				
	//  2.1 index�Ƿ�Խ��
	if (i < 0 || i >= m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}

	//3.�������Ա��д�ָ��λ�ÿ�ʼ,
	//      �ҵ��ĵ�һ����e��ȵ�Ԫ���±�
	//      (û�ҵ����� - 1)
	pos = -1;
	PNODE pFindNode = m_pListHead;
	for (int j = 0; j < m_nCurrNum; j++)
	{
		if (pFindNode->data == e && j <= i)
		{
			pos = i;
			break;
		}
		pFindNode = pFindNode->pNext;
	}

	return RESULT_TRUE;
}

/************************************
* Access:    public 
* ��������:  �滻(����)���Ա��е�i��Ԫ�ص�ֵ
* 
* �����б�:
*   int i:           [in] �滻�ĸ�λ��
*   ElementType e:   [in] �滻��ʲôֵ
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyList::SetElem( int i, ElementType e)
{
	//1.����Ƿ������ʼ����
	if (m_pListHead == nullptr)
	{
		return RESULT_FALSE;
	}
	//2.����Ƿ�������ȷ����				
	//  2.1 index�Ƿ�Խ��
	if (i < 0 || i >= m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}
	//3.�滻(����)���Ա��е�i��Ԫ�ص�ֵ
	PNODE pFindNode = m_pListHead;
	for (int j = 0; j < i;j++)
	{
		pFindNode = pFindNode->pNext;
	}
	pFindNode->data = e;//�������Ĳ��ǻ�������,��Ҫ����"="��

	return RESULT_TRUE;
}
