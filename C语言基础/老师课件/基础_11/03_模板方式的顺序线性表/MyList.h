#pragma once
#include <iostream>
using std::cout;
#define MAX_LENTH  200
//ADT 顺序线性表(List)
//Data
//数据对象：线性表的数据对象集合为{ 𝑎_1, 𝑎_2, ...𝑎_𝑛 }，
//每个元素类型均为DataType。
//数据关系：除第一个元素𝑎_1外，每一个元素有且只有一个直接前驱元素，
//除了最后一个元素𝑎_𝑛外，每个元素有且只有一个直接后继元素，数据元素之间的关系是一对一的关系。
//线性表中每一个元素在物理是连续的。
//Operation
//InitList(&L) :
//操作结果：构造一个空的线性表L
//InsertList(&L, i, e) :
//初始条件：线性表L已存在，0 <= i <= ListLength(L)
//操作结果：在L中第i个元素位置之前插入新的数据元素e，L的长度加1
//DeleteList(&L, i, &e) :
//初始条件：线性表L已存在且非空，0 <= i<ListLength(L)
//操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
//ClearList(&L) :
//初始条件：线性表L已存在         操作结果：将L重置为空表
//ListEmpty(L) :
//初始条件：线性表L已存在
//操作结果：若L为空表，则返回true，否则返回false
//ListLength(L) : 
//初始条件：线性表L已存在         操作结果：返回L中元素个数
//GetElem(L, i, &e) :
//初始条件：线性表L已存在，0 <= i <ListLength(L)
//操作结果：用e返回L中第i个数据元素的值
//LocateElem(L, e) :
//初始条件：线性表L已存在。
//操作结果：返回在线性表中第1个与e相等的数据元素的位序。不存在则返回 - 1
//SetElem(L, i, e) :
//初始条件：线性表L已存在，0 <= i <ListLength(L)
//操作结果：用e替换L中第i个数据元素的值
//……
//endADT

template <typename T>
class CMyList
{
public:
	CMyList();
	~CMyList();
public:
	bool Init(        /******初始化线性表*******/
		int nMaxLenth /*1 长度**************/
		);
	bool InsertEle(  /******插入数据*******/
		T nData,  /*1 要插入到线性表中的数据*/
		int nLoc    /*2 要插入的位置*/
		);

	bool DeleteEle(/********删除元素*******/
		int nLoc,   /*1 要删除的位置*/
		T& Ele    /*2 将被删除的数据传递出来*/
		);


	void PrintAll()
	{
		for (int i = 0; i <m_Lenth; i++)
		{
			//1 使用cout优于printf的地方
			//就是cout可以支持所有的类型
			//对于类对象来说，只要你在类中
			//重载了流运算符，就能够得到
			//cout的支持
			cout << m_Data[i];
		}
	}
private:

	T *m_Data;
	int m_Lenth;
	int m_MaxLenth;
};
template<typename T>
CMyList<T>::CMyList() :m_Lenth(0), m_MaxLenth(0), m_Data(NULL)
{
}

template<typename T>
CMyList<T>::~CMyList()
{
}
template<typename T>
bool CMyList<T>::Init(
	int nMaxLenth
	)
{
	m_MaxLenth = nMaxLenth;
	m_Data = new T[nMaxLenth];
	return true;
}
template<typename T>
bool CMyList<T>::InsertEle(
	T nData,
	int nLoc
	)
{
	// 1 检测插入的位置，是否超出当前长度
	if (nLoc>m_Lenth)
	{
		return false;
	}
	// 2 检测当前线性表是否已经满了
	if (m_Lenth == m_MaxLenth)
	{
		//2.1 申请出原来的2倍的空间
		T * pTemp = new T[m_MaxLenth * 2];
		//2.2 将老数据存储到新的空间中
		for (int i = 0; i < m_MaxLenth; i++)
		{
			pTemp[i] = m_Data[i];
		}
		//2.3 释放掉原来的空间
		delete[]m_Data;
		//2.4 将指针指向新的空间
		m_Data = pTemp;
		m_MaxLenth = m_MaxLenth * 2;
	}
	// 3 开始插入数据
	// 3.1插入的位置是不是末尾
	if (nLoc == m_Lenth)
	{
		m_Data[nLoc] = nData;
	}
	else
	{
		for (int i = m_Lenth - 1; i >= nLoc; i--)
		{
			m_Data[i + 1] = m_Data[i];
		}
		m_Data[nLoc] = nData;
	}
	m_Lenth++;
	return true;
}

template<typename T>
bool CMyList<T>::DeleteEle(
	int nLoc,
	T& Ele
	)
{
	//1 位置不正确
	if (nLoc >= m_Lenth)
	{
		return false;
	}
	//2 保存要被删除的数据
	Ele = m_Data[nLoc];
	//3 开始删除
	for (int i = nLoc; i < m_Lenth - 1; i++)
	{
		m_Data[i] = m_Data[i + 1];
	}
	m_Lenth--;
	return true;
}