#include "stdafx.h"
#include "Clink.h"

 
//************************************
// Method:    Insertlink
// FullName:  Clink::Insertlink 
// 返回值:   void 
// Parameter: TEAMINT data
// Parameter: int loca
//************************************
void Clink::Insertlink(TEAMINT data, int loca ){
	//1.检查是否满足初始条件
	if (m_phead == NULL)//在析构函数中初始化了 应该不会出现
		{
			 m_phead = new NODE();
			m_phead->nNext = m_phead;
			m_phead->nPrev = m_phead;
			m_phead->nData = data;
			m_length = 1;// 头是空的 那么它的长度应该重置为1 
			return;
		} 
	//2.检查是否传入了正确参数				
		//  2.1 处理参数的特殊值
		if (loca ==-1)
		{
			loca = m_length;
		}
		//  2.1 检查参数是否有效 
		if (loca< 0 || loca>m_length)
		{
			return; //参数错误
		}
	//3.实现本函数的功能
		NODE * TEMPNODE = m_phead;
		for (int i = 0; i < loca - 1; i++)
		{
			TEMPNODE = TEMPNODE->nNext;
		}
		NODE * NEWNODE = new NODE;
		NEWNODE->nData = data;

		NEWNODE->nNext = TEMPNODE->nNext;//TEMPNODE的下个节点赋值给新对象
		TEMPNODE->nNext->nPrev = NEWNODE;//将TEMPNODE下个结点的上个结点改成新对象
		
		TEMPNODE->nNext = NEWNODE;
		NEWNODE->nPrev = TEMPNODE;
		m_length++;
		return;
}
void Clink::Deletelink(TEAMINT &data, int loca){
	//1.检查是否满足初始条件
	//头结点为空或者长度为0的时候 代表已经没有数据了
	  if (m_phead == NULL ||m_length == 0)
	  {
		  return;
	  } 
	  //  2.1 处理参数的特殊值
	  if (loca == -1)
	  {
		  loca = m_length;
	  }
	  //  2.1 检查参数是否有效 
	  if (loca< 0 || loca>m_length)
	  {
		  return; //参数错误
	  } 
	//3.实现本函数的功能
	  NODE * TEMPNODE = new NODE;
	  NODE * TEMPNODEA = new NODE;
	  TEMPNODE = m_phead;
	  for (int i = 0; i < loca - 1; i++)
	  {
		  TEMPNODE = TEMPNODE->nNext;
	  } 
	  //删的是TEMPNODE的下一个指针
	  data = TEMPNODE->nNext->nData;
	  TEMPNODEA = TEMPNODE->nNext;
	  TEMPNODE->nNext = TEMPNODE->nNext->nNext;//将指针的值指向他下个元素
	  TEMPNODE->nNext->nPrev = TEMPNODE;//将指针的值指向他上个元素
	  
	  delete[] TEMPNODEA;
	  TEMPNODEA = NULL;
	  m_length--;
	//  return data;
}
void Clink::Clearlink(){ ; }