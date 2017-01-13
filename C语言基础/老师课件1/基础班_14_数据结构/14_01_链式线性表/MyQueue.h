#pragma once
#include "MyList.h"
class CMyQueue :	protected CMyList
{
public:
	CMyQueue();
	~CMyQueue();

//	Status InitQueue(   /**构造一个空的队列Q*/
//		);
	Status EnQueue(     /**插入新的数据元素e为新队尾,Q的长度加1*/
		ElementType e       //[in] 新插入元素的值
		);
	Status DeQueue(     /**删除Q的队头元素,并用e返回其值,Q的长度减1*/
		ElementType & e     //[out]被删除元素的值
		);
	Status ClearQueue(  /**将Q重置为空队列*/
		);
	Status GetHead(     /**用e返回Q中队头元素的值*/
		ElementType & e     //[out] 队头元素的值
		);
	Status QueueLength( /**返回Q中元素个数*/
		int & length     //[out] 元素个数
		);
	Status QueueEmpty(  /**若Q为空队列,则返回true,否则返回false*/
		bool & isEmpty   //[out] 是否为空
		);
};

