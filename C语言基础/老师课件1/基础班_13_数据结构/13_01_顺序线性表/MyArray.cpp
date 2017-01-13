#include "stdafx.h"
#include "MyArray.h"
using namespace CMyArray_Space;

CMyArray::CMyArray()
{
	m_nCurrNum = 0;	      //��ǰ����Ԫ�ظ���
	m_nCurrSize = 0;      //��ǰ���ݽṹ������
	m_pArrHead = nullptr; //���ݽṹ�еĵ�һ������Ԫ�صĵ�ַ
}


CMyArray::~CMyArray()
{
	ClearArray();
}

/************************************
* Access:    public 
* ��������:  ����һ�����Ա�
* 
* �����б�:
*   int size:  [in] ���Ա�ĳ�ʼ��С
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyArray::InitArray(int size /*= 10*/)
{
	//1.����Ƿ������ʼ����
	if (m_pArrHead != nullptr)
	{
		return RESULT_FALSE;
	}
				
	//2.����Ƿ�������ȷ����				
	if (size<=0)
	{
		return RESULT_ERR_PARAMER;  
	}
	
	//3.ʵ�ֱ������Ĺ���
	//  ����һ���յ����Ա�
	m_pArrHead = new ElementType[size];
	m_nCurrNum = 0;
	m_nCurrSize = size;

	return RESULT_TRUE;
}

/************************************
* Access:    public 
* ��������:  �����Ա��е�i��Ԫ��λ��֮ǰ�����µ�����Ԫ��e
* 
* �����б�:
*   ElementType e:   [in] ���������ֵ
*   int i:           [in] �����λ��(�ڴ�λ��֮ǰ����)
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyArray::InsertArray(ElementType e,int i)
{
	//1.����Ƿ������ʼ����
	Status checkInit = InitArray();
	if (checkInit !=RESULT_TRUE && 
		checkInit !=RESULT_FALSE)
	{
		return checkInit; //����û�б�������ʼ��
	}
	//2.����Ƿ�������ȷ����				
	//  2.1 �������������ֵ
	if (i==-1)
	{
		i = m_nCurrNum; //���һ��λ��
	}
	//  2.1 �������Ƿ���Ч
	if (i<0||i>m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}

	//3.ʵ�ֱ������Ĺ���
	//  �����Ա��е�i��Ԫ��λ��֮ǰ�����µ�����Ԫ��e
	//3.1   �鿴�����Ƿ�����
	if (m_nCurrNum == m_nCurrSize)
	{
	//3.1.1 ����(�����µĿռ�)
		Status checkExpand = ExpandSpace();
	//3.1.2 ���ݵĽ�����,�Ƿ�ɹ�
		if (checkExpand !=RESULT_TRUE)
		{
			return checkExpand;
		}
	}

	//3.2   ����Ԫ��
	//3.2.1 ��iλ���Լ�������Ԫ�ض��������ƶ�һ��
	for (int j = m_nCurrNum - 1; j>=i ;j--)
	{
		m_pArrHead[j + 1] = m_pArrHead[j];
	}
	//3.2.2 ����Ԫ�ز���iλ����
	m_pArrHead[i] = e;

	m_nCurrNum++;
	return RESULT_TRUE;
}

/************************************
* Access:    public 
* ��������:  ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
* 
* �����б�:
*   int i:            [in] ɾ��Ԫ�ص�λ��
*   ElementType & e:  [out]��ɾ��Ԫ�ص�ֵ
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyArray::DeleteArray(ElementType &e,int i)
{
	//1.����Ƿ������ʼ����
	if (m_pArrHead == nullptr)
	{
		return RESULT_FALSE;
	}			
	//2.����Ƿ�������ȷ����	
	//  2.1 �������������ֵ
	if (i==-1)
	{
		i = m_nCurrNum - 1;
	}
	//  2.1 �������Ƿ���Ч
	if (i<0 || i>= m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}
	//3.ʵ�ֱ������Ĺ���
	//ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
	//3.1 ��ȡ����ֵ
	e = m_pArrHead[i];
	//3.2 �ѵ�i��Ԫ�غ��������Ԫ�ض���ǰ���ƶ�һ��
	for (int j = i; j < m_nCurrNum-1; j++)
	{
		m_pArrHead[j] = m_pArrHead[j + 1];
	}
	//3.3 �������ݳ�Ա
	m_nCurrNum--;

	return RESULT_TRUE;
}

/************************************
* Access:    public 
* ��������:  �����Ա�����Ϊ�ձ�
* 
* �����б�:
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyArray::ClearArray()
{
	if (!m_pArrHead)
	{
		delete[]m_pArrHead;
	}
	m_nCurrNum = 0;
	m_nCurrSize = 0;
	m_pArrHead = nullptr;

	return RESULT_TRUE;
}

/************************************
* Access:    public 
* ��������:  ���Ա��Ƿ�Ϊ��
* 
* �����б�:
*   bool & isEmpty:  [out]�Ƿ�Ϊ��
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyArray::ArrayEmpty( bool & isEmpty)
{
	if (m_nCurrNum == 0)
	{
		isEmpty = true;
	}
	else
	{
		isEmpty = false;
	}
	return RESULT_TRUE;
}

/************************************
* Access:    public 
* ��������:  ����L��Ԫ�ظ���
* 
* �����б�:
*   int & length:   [out]����
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyArray::ArrayLength(int & length )
{
	//1.����Ƿ������ʼ����
		if (m_pArrHead == nullptr)
		{
			length = -1;
			return RESULT_FALSE;
		}
			
	//2.����Ƿ�������ȷ����				
	//  2.1 �������������ֵ
	//  2.1 �������Ƿ���Ч

	//3.ʵ�ֱ������Ĺ���
	//  ����L��Ԫ�ظ���
	length = m_nCurrNum;
	return RESULT_TRUE;
}

/************************************
* Access:    public 
* ��������:  ��e����L�е�i������Ԫ�ص�ֵ
* 
* �����б�:
*   int i:           [in]��ȡԪ�ص�λ��
*   ElementType e:   [out]����ȡ��Ԫ��
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyArray::GetElem(int i, ElementType& e )
{
	//1.����Ƿ������ʼ����
	if (m_pArrHead == nullptr)
	{
		return RESULT_FALSE;
	}
			
	//2.����Ƿ�������ȷ����	
	//  2.1 �������������ֵ
	//  2.2 �������Ƿ���Ч
	if (i<0 || i>=m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}
	//3.ʵ�ֱ������Ĺ���
	//  ��e����L�е�i������Ԫ�ص�ֵ
	e = m_pArrHead[i];

	return RESULT_TRUE;
}

ElementType CMyArray::operator[](int i)
{
	ElementType e;
	GetElem(i, e);
	return e;
}

/************************************
* Access:    public 
* ��������:  ���������Ա��е�1����e��ȵ�����Ԫ�ص�λ�򡣲������򷵻�-1
* 
* �����б�:
*   int startPos:  [in]�ӵڼ���λ�ÿ�ʼ����
*   ElementType:   [in]�����ĸ�Ԫ��
*   int & pos:     [out]Ԫ������λ��
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyArray::LocateElem( int startPos,  ElementType e,  int & pos )
{
	//1.����Ƿ������ʼ����
	if (m_pArrHead == nullptr)
	{
		pos = -1;
		return RESULT_FALSE;
	}
			
	//2.����Ƿ�������ȷ����				
	//  2.1 �������������ֵ
	//  2.2 �������Ƿ���Ч
	if (startPos<0 || startPos>=m_nCurrNum)
	{
		return RESULT_ERR_PARAMER;
	}

	//3.ʵ�ֱ������Ĺ���
	//  ���������Ա��е�1����e��ȵ�����Ԫ�ص�λ�򡣲������򷵻�-1
	//3.1 ͨ��forѭ��Ѱ��ָ��Ԫ��
	pos = -1;
	for (size_t i = startPos; i < m_nCurrNum; i++)
	{
		if (m_pArrHead[i]==e)
		{
			pos = i;
			break;
		}
	}
	return RESULT_TRUE;
}

/************************************
* Access:    public 
* ��������:  ��e�滻L�е�i������Ԫ�ص�ֵ
* 
* �����б�:
*   int i:          [in]������Ԫ�ص��±�
*   ElementType e:  [in]���ó���ֵ
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyArray::SetElem( int i, ElementType e)
{
	//1.����Ƿ������ʼ����
	if (m_pArrHead == nullptr)
	{
		return RESULT_FALSE;
	}
			
	//2.����Ƿ�������ȷ����				
	//  2.1 �������������ֵ
	//  2.2 �������Ƿ���Ч
	if (i<0||i>=m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}
	
	//3.ʵ�ֱ������Ĺ���
	//  ��e�滻L�е�i������Ԫ�ص�ֵ
	m_pArrHead[i] = e;

	return RESULT_TRUE;
}

//�������������
Status CMyArray::ExpandSpace()
{
	//���������Ĺ���(ÿ������ԭ����2��)
	//1. �����¿ռ�
	ElementType * temp = nullptr;
	try
	{
		temp = new ElementType[2 * m_nCurrSize];
	}catch (...)
	{
		return RESULT_FALSE;
	}
	//2. ԭ���ĸ�ֵ���¿ռ�
	memcpy_s(temp, m_nCurrSize*sizeof(ElementType),
		m_pArrHead, m_nCurrSize*sizeof(ElementType));
	//3. �ͷ�ԭ���Ŀؼ�
	delete[]m_pArrHead;
	//4. �������ݳ�Ա
	m_pArrHead = temp;
	m_nCurrSize = 2 * m_nCurrSize;

	return RESULT_TRUE;
}
