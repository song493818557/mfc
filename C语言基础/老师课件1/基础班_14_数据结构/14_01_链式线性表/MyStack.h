#pragma once
#include "MyList.h"

class CMyStack:protected CMyList
{
public:
	CMyStack();
	~CMyStack();

	//     Status InitStack( /**����һ����ջ*/
	//         );
	Status Push(      /**�����µ�����Ԫ��eΪ��ջ��,S�ĳ��ȼ�1*/
		ElementType e     //[in] �����Ԫ��
		);
	Status Pop(       /**ɾ��S��ջ��Ԫ��,����e������ֵ,S�ĳ��ȼ�1*/
		ElementType & e   //[out] ɾ����ջ��Ԫ��ֵ
		);
	Status ClearStack(/**��S����Ϊ��ջ*/
		);
	Status GetTop(    /**��e����S��ջ��Ԫ�ص�ֵ*/
		ElementType & e   //[out]�鿴��ջ��Ԫ��ֵ
		);
	Status StackEmpty(/**��SΪ��ջ,�򷵻�true,���򷵻�false*/
		bool & isEmpty //[out]�Ƿ�Ϊ��
		);
	Status StackLength(/**����S��Ԫ�صĸ���*/
		int & length    //[out]Ԫ�ظ���
		);
};


