#include "stdafx.h"
#include "MyArray.h"
using namespace CMyArray_Space;

CMyArray::CMyArray()
{
	m_nCurrNum = 0;	      //当前数据元素个数
	m_nCurrSize = 0;      //当前数据结构的容量
	m_pArrHead = nullptr; //数据结构中的第一个数据元素的地址
}


CMyArray::~CMyArray()
{
	ClearArray();
}

/************************************
* Access:    public 
* 函数功能:  构造一个线性表
* 
* 参数列表:
*   int size:  [in] 线性表的初始大小
*   
* 返回值:    Status
* 
*************************************/
Status CMyArray::InitArray(int size /*= 10*/)
{
	//1.检查是否满足初始条件
	if (m_pArrHead != nullptr)
	{
		return RESULT_FALSE;
	}
				
	//2.检查是否传入了正确参数				
	if (size<=0)
	{
		return RESULT_ERR_PARAMER;  
	}
	
	//3.实现本函数的功能
	//  构造一个空的线性表
	m_pArrHead = new ElementType[size];
	m_nCurrNum = 0;
	m_nCurrSize = size;

	return RESULT_TRUE;
}

/************************************
* Access:    public 
* 函数功能:  在线性表中第i个元素位置之前插入新的数据元素e
* 
* 参数列表:
*   ElementType e:   [in] 被插入的新值
*   int i:           [in] 插入的位置(在此位置之前插入)
*   
* 返回值:    Status
* 
*************************************/
Status CMyArray::InsertArray(ElementType e,int i)
{
	//1.检查是否满足初始条件
	Status checkInit = InitArray();
	if (checkInit !=RESULT_TRUE && 
		checkInit !=RESULT_FALSE)
	{
		return checkInit; //数组没有被正常初始化
	}
	//2.检查是否传入了正确参数				
	//  2.1 处理参数的特殊值
	if (i==-1)
	{
		i = m_nCurrNum; //最后一个位置
	}
	//  2.1 检查参数是否有效
	if (i<0||i>m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}

	//3.实现本函数的功能
	//  在线性表中第i个元素位置之前插入新的数据元素e
	//3.1   查看容量是否已满
	if (m_nCurrNum == m_nCurrSize)
	{
	//3.1.1 扩容(开辟新的空间)
		Status checkExpand = ExpandSpace();
	//3.1.2 扩容的结果检查,是否成功
		if (checkExpand !=RESULT_TRUE)
		{
			return checkExpand;
		}
	}

	//3.2   插入元素
	//3.2.1 把i位置以及其后面的元素都往后面移动一下
	for (int j = m_nCurrNum - 1; j>=i ;j--)
	{
		m_pArrHead[j + 1] = m_pArrHead[j];
	}
	//3.2.2 把新元素插在i位置上
	m_pArrHead[i] = e;

	m_nCurrNum++;
	return RESULT_TRUE;
}

/************************************
* Access:    public 
* 函数功能:  删除L的第i个数据元素，并用e返回其值，L的长度减1
* 
* 参数列表:
*   int i:            [in] 删除元素的位置
*   ElementType & e:  [out]被删除元素的值
*   
* 返回值:    Status
* 
*************************************/
Status CMyArray::DeleteArray(ElementType &e,int i)
{
	//1.检查是否满足初始条件
	if (m_pArrHead == nullptr)
	{
		return RESULT_FALSE;
	}			
	//2.检查是否传入了正确参数	
	//  2.1 处理参数的特殊值
	if (i==-1)
	{
		i = m_nCurrNum - 1;
	}
	//  2.1 检查参数是否有效
	if (i<0 || i>= m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}
	//3.实现本函数的功能
	//删除L的第i个数据元素，并用e返回其值，L的长度减1
	//3.1 获取返回值
	e = m_pArrHead[i];
	//3.2 把第i个元素后面的所有元素都往前面移动一下
	for (int j = i; j < m_nCurrNum-1; j++)
	{
		m_pArrHead[j] = m_pArrHead[j + 1];
	}
	//3.3 更新数据成员
	m_nCurrNum--;

	return RESULT_TRUE;
}

/************************************
* Access:    public 
* 函数功能:  将线性表重置为空表
* 
* 参数列表:
*   
* 返回值:    Status
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
* 函数功能:  线性表是否为空
* 
* 参数列表:
*   bool & isEmpty:  [out]是否为空
*   
* 返回值:    Status
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
* 函数功能:  返回L中元素个数
* 
* 参数列表:
*   int & length:   [out]长度
*   
* 返回值:    Status
* 
*************************************/
Status CMyArray::ArrayLength(int & length )
{
	//1.检查是否满足初始条件
		if (m_pArrHead == nullptr)
		{
			length = -1;
			return RESULT_FALSE;
		}
			
	//2.检查是否传入了正确参数				
	//  2.1 处理参数的特殊值
	//  2.1 检查参数是否有效

	//3.实现本函数的功能
	//  返回L中元素个数
	length = m_nCurrNum;
	return RESULT_TRUE;
}

/************************************
* Access:    public 
* 函数功能:  用e返回L中第i个数据元素的值
* 
* 参数列表:
*   int i:           [in]获取元素的位置
*   ElementType e:   [out]被获取的元素
*   
* 返回值:    Status
* 
*************************************/
Status CMyArray::GetElem(int i, ElementType& e )
{
	//1.检查是否满足初始条件
	if (m_pArrHead == nullptr)
	{
		return RESULT_FALSE;
	}
			
	//2.检查是否传入了正确参数	
	//  2.1 处理参数的特殊值
	//  2.2 检查参数是否有效
	if (i<0 || i>=m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}
	//3.实现本函数的功能
	//  用e返回L中第i个数据元素的值
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
* 函数功能:  返回在线性表中第1个与e相等的数据元素的位序。不存在则返回-1
* 
* 参数列表:
*   int startPos:  [in]从第几个位置开始查找
*   ElementType:   [in]查找哪个元素
*   int & pos:     [out]元素所在位置
*   
* 返回值:    Status
* 
*************************************/
Status CMyArray::LocateElem( int startPos,  ElementType e,  int & pos )
{
	//1.检查是否满足初始条件
	if (m_pArrHead == nullptr)
	{
		pos = -1;
		return RESULT_FALSE;
	}
			
	//2.检查是否传入了正确参数				
	//  2.1 处理参数的特殊值
	//  2.2 检查参数是否有效
	if (startPos<0 || startPos>=m_nCurrNum)
	{
		return RESULT_ERR_PARAMER;
	}

	//3.实现本函数的功能
	//  返回在线性表中第1个与e相等的数据元素的位序。不存在则返回-1
	//3.1 通过for循环寻找指定元素
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
* 函数功能:  用e替换L中第i个数据元素的值
* 
* 参数列表:
*   int i:          [in]被设置元素的下标
*   ElementType e:  [in]设置成新值
*   
* 返回值:    Status
* 
*************************************/
Status CMyArray::SetElem( int i, ElementType e)
{
	//1.检查是否满足初始条件
	if (m_pArrHead == nullptr)
	{
		return RESULT_FALSE;
	}
			
	//2.检查是否传入了正确参数				
	//  2.1 处理参数的特殊值
	//  2.2 检查参数是否有效
	if (i<0||i>=m_nCurrNum)
	{
		return RESULT_ERR_OVER;
	}
	
	//3.实现本函数的功能
	//  用e替换L中第i个数据元素的值
	m_pArrHead[i] = e;

	return RESULT_TRUE;
}

//扩大数组的容量
Status CMyArray::ExpandSpace()
{
	//扩大容量的规则(每次扩大到原来的2倍)
	//1. 开辟新空间
	ElementType * temp = nullptr;
	try
	{
		temp = new ElementType[2 * m_nCurrSize];
	}catch (...)
	{
		return RESULT_FALSE;
	}
	//2. 原来的赋值到新空间
	memcpy_s(temp, m_nCurrSize*sizeof(ElementType),
		m_pArrHead, m_nCurrSize*sizeof(ElementType));
	//3. 释放原来的控件
	delete[]m_pArrHead;
	//4. 更新数据成员
	m_pArrHead = temp;
	m_nCurrSize = 2 * m_nCurrSize;

	return RESULT_TRUE;
}
