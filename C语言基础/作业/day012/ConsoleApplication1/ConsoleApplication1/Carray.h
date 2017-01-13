﻿#pragma once
 
#define EType int;

//定义一个枚举,表示函数运行的错误码
enum Status
{
	RESULT_FALSE = 0,//失败
	RESULT_TRUE, //成功
	RESULT_ERR_OVER,//错误  数组越界
	RESULT_ERR_PARAMER,//错误  参数错误
	RESULT_ERR_OVERSIZE,//错误  超过最大容量
	RESULT_ERR_onknow,//错误  未知错误
	RESULT_ERR_memory//错误  内存申请失败
};
class Carray
{
public:
	Carray();
	~Carray();
private:
	int m_CurrNum;//当前数据元素的个数
	int m_nCurrSize;//当前数据结构的容量
	Status InitList(/** 构造一个空的线性表*/
		int size  //[IN] 线性表的初始化大小
		);
	Status InsertList(/** 在线性表中第I个元素未知之前插入新的数据*/
		int numb,  //[in]被插入的位置  在此位置之前插入
		int i //[IN] 被插入的新值
		);
	Status DeleteList(/** 删除L的第i个数据元素，并用e返回其值，L的长度减1*/
		int i,  //[in]被删除的元素位置  在此位置之后删除
		int &e //[out] 被删除元素的值
		);
	Status ClearList(/** 初始条件：线性表L已存在         操作结果：将L重置为空表*/
		 );
	Status ListEmpty(/** 若L为空表，则返回true，否则返回false*/ 
		int &e //[out] 被删除元素的值
		);
	//扩容2倍
	Status StaStuExpandSpace();
	int* m_pArrHead;//数据结构中的第一个数据元素的地址
};
/*ADT 线性表(List)Data数据对象：线性表的数据对象集合为{𝑎_1, 𝑎_2, ...𝑎_𝑛}，每个元素类型均为DataType。数据关系：除第一个元素𝑎_1外，每一个元素有且只有一个直接前驱元素，除了最后一个元素𝑎_𝑛外，每个元素有且只有一个直接后继元素，数据元素之间的关系是一对一的关系。OperationInitList(&L):操作结果：构造一个空的线性表LInsertList(&L,i,e):初始条件：线性表L已存在，0<=i<=ListLength(L)操作结果：在L中第i个元素位置之前插入新的数据元素e，L的长度加1DeleteList(&L,i,&e):初始条件：线性表L已存在且非空，0<=i<ListLength(L)操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1ClearList(&L):初始条件：线性表L已存在         操作结果：将L重置为空表ListEmpty(L):初始条件：线性表L已存在操作结果：若L为空表，则返回true，否则返回falseListLength(L):初始条件：线性表L已存在         操作结果：返回L中元素个数GetElem(L,i,&e):初始条件：线性表L已存在，0<= i <ListLength(L)操作结果：用e返回L中第i个数据元素的值LocateElem(L,e):初始条件：线性表L已存在。操作结果：返回在线性表中第1个与e相等的数据元素的位序。不存在则返回-1SetElem(L,i,e):初始条件：线性表L已存在，0<= i <ListLength(L)操作结果：用e替换L中第i个数据元素的值……endADT*/
