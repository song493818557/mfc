#pragma once
#include "Father.h"
class CChild_B :private CFather //2B����,һ�ɷ񶨵ļ̳и��׵�����
{                               //(˽�м̳�,�̳�����������ȫ����Ϊ˽�е�,���ٸ�������̳�)
public:
	CChild_B();
	~CChild_B();

	void fun();
};

