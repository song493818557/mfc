#pragma once
#include "Father.h"

class CChild_A:public CFather  //��ͨ����,ȫ��ԭ���ļ̳и��׵�����
	                           // (���м̳�,�̳�����������,����ԭ����)
	                   
{
public:
	CChild_A();
	~CChild_A();

	void fun();
};

