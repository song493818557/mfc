#pragma once
#include "MyList.h"
class CMyQueue :	protected CMyList
{
public:
	CMyQueue();
	~CMyQueue();

//	Status InitQueue(   /**����һ���յĶ���Q*/
//		);
	Status EnQueue(     /**�����µ�����Ԫ��eΪ�¶�β,Q�ĳ��ȼ�1*/
		ElementType e       //[in] �²���Ԫ�ص�ֵ
		);
	Status DeQueue(     /**ɾ��Q�Ķ�ͷԪ��,����e������ֵ,Q�ĳ��ȼ�1*/
		ElementType & e     //[out]��ɾ��Ԫ�ص�ֵ
		);
	Status ClearQueue(  /**��Q����Ϊ�ն���*/
		);
	Status GetHead(     /**��e����Q�ж�ͷԪ�ص�ֵ*/
		ElementType & e     //[out] ��ͷԪ�ص�ֵ
		);
	Status QueueLength( /**����Q��Ԫ�ظ���*/
		int & length     //[out] Ԫ�ظ���
		);
	Status QueueEmpty(  /**��QΪ�ն���,�򷵻�true,���򷵻�false*/
		bool & isEmpty   //[out] �Ƿ�Ϊ��
		);
};

