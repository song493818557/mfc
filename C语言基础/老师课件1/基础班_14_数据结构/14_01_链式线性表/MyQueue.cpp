#include "stdafx.h"
#include "MyQueue.h"


CMyQueue::CMyQueue()
{
}


CMyQueue::~CMyQueue()
{
}

/************************************
* Access:    public 
* ��������:  �����µ�����Ԫ��eΪ�¶�β,Q�ĳ��ȼ�1
* 
* �����б�:
*   ElementType e: [in] �²���Ԫ�ص�ֵ
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyQueue::EnQueue( ElementType e )
{
	return InsertList(e);
}

/************************************
* Access:    public 
* ��������:  ɾ��Q�Ķ�ͷԪ��,����e������ֵ,Q�ĳ��ȼ�1
* 
* �����б�:
*   ElementType & e:  [out]��ɾ��Ԫ�ص�ֵ
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyQueue::DeQueue( ElementType & e )
{
	return DeleteList(e,0);
}

/************************************
* Access:    public 
* ��������:  ��Q����Ϊ�ն���
* 
* �����б�:
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyQueue::ClearQueue()
{
	return ClearList();
}

/************************************
* Access:    public 
* ��������:  ��e����Q�ж�ͷԪ�ص�ֵ
* 
* �����б�:
*   ElementType & e:   [out] ��ͷԪ�ص�ֵ
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyQueue::GetHead( ElementType & e )
{
	return GetElem(0, e);
}

/************************************
* Access:    public 
* ��������:  ����Q��Ԫ�ظ���
* 
* �����б�:
*   int & length:  [out] Ԫ�ظ���
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyQueue::QueueLength( int & length )
{
	ListLength(length);
}

/************************************
* Access:    public 
* ��������:  ��QΪ�ն���,�򷵻�true,���򷵻�false
* 
* �����б�:
*   bool & isEmpty:  [out] �Ƿ�Ϊ��
*   
* ����ֵ:    Status
* 
*************************************/
Status CMyQueue::QueueEmpty( bool & isEmpty )
{
	ListEmpty(isEmpty);
}
