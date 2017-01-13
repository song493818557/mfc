#pragma once

#define ElementType int

//定义一个枚举,表示函数运行的错误码
enum Status
{
	RESULT_FALSE = 0,   //失败
	RESULT_TRUE,        //成功
	RESULT_ERR_OVER,    //错误_数组越界
	RESULT_ERR_PARAMER, //错误_参数错误
	RESULT_ERR_OVERSIZE,//错误_超过最大容量
	RESULT_ERR_ONKNOW,  //错误_未知错误
};


class CMyList
{
	//定义链表节点
	typedef struct _NODE
	{
		//数据域
		ElementType data;
		//指针域
		_NODE * pNext;  //后一个元素
		_NODE * pPrev;  //前一个元素
	}NODE,* PNODE;
public:
	CMyList();
	virtual ~CMyList();

	Status InsertList(  /**在L中第i个元素位置之前插入新的数据元素e，L的长度加1*/
		ElementType e,   //[in] 插入的新元素
		int i = -1       //[in] 插入的位置
		);

	Status DeleteList(  /** 删除L的第i个数据元素，并用e返回其值，L的长度减1*/
		ElementType & e, //[out]被删除的元素
		int i=-1         //[in] 删除的位置
		);
	//======new==============
	Status ClearList(   /**将List重置为空表*/
		);

	Status ListEmpty(   /**线性表是否为空*/
		bool & isEmpty   //[out] 是否为空
		);

	Status ListLength(  /**线性表中元素的个数*/
		int & length     //[out] 长度
		);

	Status GetElem(    /**获取线性表中指定位置上的元素*/
		int i,          //[in] 获取哪个位置上的元素
		ElementType & e //[out]获取的元素值
		);
	//链式存储一般不提供下标运算符  []

	Status LocateElem(  /**返回线性表中从指定位置开始,找到的第一个与e相等的元素下标(没找到返回-1)*/
		int i,           //[in] 从哪个位置开始找
		ElementType e,   //[in] 找哪个值
		int & pos        //[out]该值所在位置
		);

	Status SetElem(     /**替换(设置)线性表中第i个元素的值*/
		int i,       //[in] 替换哪个位置
		ElementType e       //[in] 替换成什么值
		);


private:
	int m_nCurrNum;    //当前元素个数
	PNODE m_pListHead; //指定第一个节点的位置
};

/*
ADT 线性表(List)
Data
    数据对象：线性表的数据对象集合为{𝑎_1, 𝑎_2, ...𝑎_𝑛}，每个元素类型均为DataType。
    数据关系：除第一个元素𝑎_1外，每一个元素有且只有一个直接前驱元素，
                  除了最后一个元素𝑎_𝑛外，每个元素有且只有一个直接后继元素，数据元素之间的关系是一对一的关系。
Operation
    InitList(&L):
        操作结果：构造一个空的线性表L
    InsertList(&L,i,e):
        初始条件：线性表L已存在，0<=i<=ListLength(L)
        操作结果：在L中第i个元素位置之前插入新的数据元素e，L的长度加1
    DeleteList(&L,i,&e):
        初始条件：线性表L已存在且非空，0<=i<ListLength(L)
        操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
    ClearList(&L):
        初始条件：线性表L已存在         操作结果：将L重置为空表   
    ListEmpty(L):
        初始条件：线性表L已存在
        操作结果：若L为空表，则返回true，否则返回false 
    ListLength(L):
        初始条件：线性表L已存在         操作结果：返回L中元素个数
    GetElem(L,i,&e):
        初始条件：线性表L已存在，0<= i <ListLength(L)
        操作结果：用e返回L中第i个数据元素的值
    LocateElem(L,e):
        初始条件：线性表L已存在。
        操作结果：返回在线性表中第1个与e相等的数据元素的位序。不存在则返回-1
    SetElem(L,i,e):
        初始条件：线性表L已存在，0<= i <ListLength(L)
        操作结果：用e替换L中第i个数据元素的值
……
endADT

*/