#include "stdafx.h"
#include "MyStack.h"


CMyStack::CMyStack() :MyList()
{
}


CMyStack::~CMyStack()
{
}

/************************************
* Access:    public
* ��������:  �����µ�����Ԫ��eΪ��ջ��,S�ĳ��ȼ�1
*
* �����б�:
*   ElemType e:  [in] �����Ԫ��
*
* ����ֵ:    Status
*
*************************************/
Status CMyStack::Push(ElementType e)
{
	return InsertList(e, 0);
}

/************************************
* Access:    public
* ��������:  ɾ��S��ջ��Ԫ��,����e������ֵ,S�ĳ��ȼ�1
*
* �����б�:
*   ElemType & e:  [out] ɾ����ջ��Ԫ��ֵ
*
* ����ֵ:    Status
*
*************************************/
Status CMyStack::Pop(ElementType & e)
{
	return DeleteList( e,0);
}

/************************************
* Access:    public
* ��������:  ��S����Ϊ��ջ
*
* �����б�:
*
* ����ֵ:    Status
*
*************************************/
Status CMyStack::ClearStack()
{
	return ClearList();
}

/************************************
* Access:    public
* ��������:  ��e����S��ջ��Ԫ�ص�ֵ
*
* �����б�:
*   ElemType & e:  [out]�鿴��ջ��Ԫ��ֵ
*
* ����ֵ:    Status
*
*************************************/
Status CMyStack::GetTop(ElementType & e)
{
	return GetElem(0, e);
}

/************************************
* Access:    public
* ��������:  ��SΪ��ջ,�򷵻�true,���򷵻�false
*
* �����б�:
*   bool & isEmpty:  [out]�Ƿ�Ϊ��
*
* ����ֵ:    Status
*
*************************************/
Status CMyStack::StackEmpty(bool & isEmpty)
{
	return ListEmpty(isEmpty);
}

/************************************
* Access:    public
* ��������:  ����S��Ԫ�صĸ���
*
* �����б�:
*   int & length:  [out]Ԫ�ظ���
*
* ����ֵ:    Status
*
*************************************/
Status CMyStack::StackLength(int & length)
{
	return ListLength(length);
}

