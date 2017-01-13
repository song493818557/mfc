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
// 返回值:   Status 
// Parameter: int size
//************************************
Status Carray::InitList(int size = 10)
{
	//1.检查是否满足初始条件
	if (m_pArrHead != nullptr)
	{
		return RESULT_FALSE;
	}
	//2.检查是否传入了正确参数	
	if (size<=0){
		return  RESULT_ERR_PARAMER;
	}
		//  2.1 处理参数的特殊值
		//  2.1 检查参数是否有效 
	//3.实现本函数的功能
	//构造一个空的线性表
	m_pArrHead = new int[size];
	m_CurrNum = 0;
	m_nCurrSize = size;
	return RESULT_TRUE;
}
//************************************
// Method:    InsertList
// FullName:  Carray::InsertList
// Access:    private 
// 返回值:   Status
// Qualifier:   在线性表中第I个元素未知之前插入新的数据
// Parameter: int i   [in]被插入的位置  在此位置之前插入
// Parameter: int numb   [IN] 被插入的新值
//************************************
Status Carray::InsertList(int numb , int i=-1 ){
	//1.检查是否满足初始条件
	Status checkInit = InitList();
	if (checkInit != RESULT_TRUE &&
		checkInit != RESULT_FALSE)
	{
		return checkInit;//数组没有被正常初始化
	}
	//2.检查是否传入了正确参数	
	//  2.1 处理参数的特殊值
	//  2.1 检查参数是否有效
	if (i == -1)
	{
		i = m_CurrNum;//最后一个位置
	}	
	if (i<0||i>m_CurrNum)
	{
		return RESULT_ERR_OVERSIZE;
	}
		
	//3.实现本函数的功能
	//3.1 查看容量是否已满 
	if (m_CurrNum==m_nCurrSize)
	{	
	//3.1.1 满了就需要扩容
		Status checkExpand = StaStuExpandSpace();
	//3.1.2 扩容的结果检查 是否成功
		if (checkExpand != RESULT_TRUE)
		{
			return checkExpand;
		}
	}
	//3.2   插入元素
	 
	for (int j = m_CurrNum - 1; j <= i;j--)
	{
		m_pArrHead[j + 1] = m_pArrHead[j];
	}
	m_pArrHead[i] = numb;
	m_CurrNum++;
	return RESULT_TRUE;
}
Status Carray::StaStuExpandSpace(){
	//扩大容量的规则 (每次扩大到原来的2倍)
	//1.开辟新空间
	int * temp = nullptr;
	try
	{
		temp = new int[2 * m_nCurrSize];

	}
	catch (...)
	{
		return RESULT_ERR_memory;
	} 
    

	 //2.原来的赋值到新空间
	memcpy_s(temp, m_nCurrSize*sizeof(int),
		m_pArrHead, m_nCurrSize*sizeof(int));
	delete[]m_pArrHead;
	return RESULT_TRUE;

}