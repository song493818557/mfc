#include "stdafx.h"
#include "Carray.h"


Carray::Carray() :m_nCurrSize(0), m_CurrNum(0), m_pArrHead(NULL){ }

Carray::~Carray()
{
	if (!m_pArrHead)
	{
		delete[] m_pArrHead; 
	}
}

//************************************
// FullName:  Carray::InitList
// Access:    private 
// ����ֵ:   Status 
// Parameter: int size
//************************************
Status Carray::InitList(int size = 10)
{
	//1.����Ƿ������ʼ����
	if (m_pArrHead != nullptr)
	{
		return RESULT_FALSE;
	}
	//2.����Ƿ�������ȷ����	
	if (size<=0){
		return  RESULT_ERR_PARAMER;
	}
		//  2.1 �������������ֵ
		//  2.1 �������Ƿ���Ч 
	//3.ʵ�ֱ������Ĺ���
	//����һ���յ����Ա�
	m_pArrHead = new int[size];
	m_CurrNum = 0;
	m_nCurrSize = size;
	return RESULT_TRUE;
}
//************************************
// Method:    InsertList
// FullName:  Carray::InsertList
// Access:    private 
// ����ֵ:   Status
// Qualifier:   �����Ա��е�I��Ԫ��δ֪֮ǰ�����µ�����
// Parameter: int i   [in]�������λ��  �ڴ�λ��֮ǰ����
// Parameter: int numb   [IN] ���������ֵ
//************************************
Status Carray::InsertList(int numb , int i=-1 ){
	//1.����Ƿ������ʼ����
	Status checkInit = InitList();
	if (checkInit != RESULT_TRUE &&
		checkInit != RESULT_FALSE)
	{
		return checkInit;//����û�б�������ʼ��
	}
	//2.����Ƿ�������ȷ����	
	//  2.1 �������������ֵ
	//  2.1 �������Ƿ���Ч
	if (i == -1)
	{
		i = m_CurrNum;//���һ��λ��
	}	
	if (i<0||i>m_CurrNum)
	{
		return RESULT_ERR_OVERSIZE;
	}
		
	//3.ʵ�ֱ������Ĺ���
	//3.1 �鿴�����Ƿ����� 
	if (m_CurrNum==m_nCurrSize)
	{	
	//3.1.1 ���˾���Ҫ����
		Status checkExpand = StaStuExpandSpace();
	//3.1.2 ���ݵĽ����� �Ƿ�ɹ�
		if (checkExpand != RESULT_TRUE)
		{
			return checkExpand;
		}
	}
	//3.2   ����Ԫ��
	 
	for (int j = m_CurrNum - 1; j <= i;j--)
	{
		m_pArrHead[j + 1] = m_pArrHead[j];
	}
	m_pArrHead[i] = numb;
	m_CurrNum++;
	return RESULT_TRUE;
}
Status Carray::StaStuExpandSpace(){
	//���������Ĺ��� (ÿ������ԭ����2��)
	//1.�����¿ռ�
	int * temp = nullptr;
	try
	{
		temp = new int[2 * m_nCurrSize];

	}
	catch (...)
	{
		return RESULT_ERR_memory;
	} 
    

	 //2.ԭ���ĸ�ֵ���¿ռ�
	memcpy_s(temp, m_nCurrSize*sizeof(int),
		m_pArrHead, m_nCurrSize*sizeof(int));
	delete[]m_pArrHead;
	return RESULT_TRUE;

}