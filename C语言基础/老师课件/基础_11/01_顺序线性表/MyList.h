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
class CMyList
{
public:
	CMyList();
	~CMyList();
public:

	bool InsertEle(  /******插入数据*******/
		int nData,  /*1 要插入到线性表中的数据*/
		int nLoc    /*2 要插入的位置*/
		);

	bool DeleteEle(/********删除元素*******/
		int nLoc,   /*1 要删除的位置*/
		int& Ele    /*2 将被删除的数据传递出来*/
		);


	void PrintAll()
	{
		for (int i = 0; i <m_Lenth; i++)
		{
			cout << m_Data[i];
		}
	}
private:
	int m_Data[MAX_LENTH];
	int m_Lenth;
};



