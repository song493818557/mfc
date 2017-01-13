#include "stdafx.h"
#include "Clink.h"

 
//************************************
// Method:    Insertlink
// FullName:  Clink::Insertlink 
// ����ֵ:   void 
// Parameter: TEAMINT data
// Parameter: int loca
//************************************
void Clink::Insertlink(TEAMINT data, int loca ){
	//1.����Ƿ������ʼ����
	if (m_phead == NULL)//�����������г�ʼ���� Ӧ�ò������
		{
			 m_phead = new NODE();
			m_phead->nNext = m_phead;
			m_phead->nPrev = m_phead;
			m_phead->nData = data;
			m_length = 1;// ͷ�ǿյ� ��ô���ĳ���Ӧ������Ϊ1 
			return;
		} 
	//2.����Ƿ�������ȷ����				
		//  2.1 �������������ֵ
		if (loca ==-1)
		{
			loca = m_length;
		}
		//  2.1 �������Ƿ���Ч 
		if (loca< 0 || loca>m_length)
		{
			return; //��������
		}
	//3.ʵ�ֱ������Ĺ���
		NODE * TEMPNODE = m_phead;
		for (int i = 0; i < loca - 1; i++)
		{
			TEMPNODE = TEMPNODE->nNext;
		}
		NODE * NEWNODE = new NODE;
		NEWNODE->nData = data;

		NEWNODE->nNext = TEMPNODE->nNext;//TEMPNODE���¸��ڵ㸳ֵ���¶���
		TEMPNODE->nNext->nPrev = NEWNODE;//��TEMPNODE�¸������ϸ����ĳ��¶���
		
		TEMPNODE->nNext = NEWNODE;
		NEWNODE->nPrev = TEMPNODE;
		m_length++;
		return;
}
void Clink::Deletelink(TEAMINT &data, int loca){
	//1.����Ƿ������ʼ����
	//ͷ���Ϊ�ջ��߳���Ϊ0��ʱ�� �����Ѿ�û��������
	  if (m_phead == NULL ||m_length == 0)
	  {
		  return;
	  } 
	  //  2.1 �������������ֵ
	  if (loca == -1)
	  {
		  loca = m_length;
	  }
	  //  2.1 �������Ƿ���Ч 
	  if (loca< 0 || loca>m_length)
	  {
		  return; //��������
	  } 
	//3.ʵ�ֱ������Ĺ���
	  NODE * TEMPNODE = new NODE;
	  NODE * TEMPNODEA = new NODE;
	  TEMPNODE = m_phead;
	  for (int i = 0; i < loca - 1; i++)
	  {
		  TEMPNODE = TEMPNODE->nNext;
	  } 
	  //ɾ����TEMPNODE����һ��ָ��
	  data = TEMPNODE->nNext->nData;
	  TEMPNODEA = TEMPNODE->nNext;
	  TEMPNODE->nNext = TEMPNODE->nNext->nNext;//��ָ���ֵָ�����¸�Ԫ��
	  TEMPNODE->nNext->nPrev = TEMPNODE;//��ָ���ֵָ�����ϸ�Ԫ��
	  
	  delete[] TEMPNODEA;
	  TEMPNODEA = NULL;
	  m_length--;
	//  return data;
}
void Clink::Clearlink(){ ; }