#pragma once
#include "Father.h"
class CChild_C:protected CFather
	                //��������,���Ž��ɵļ̳и��׵�����
	                //(�����̳�,��Щ����(public)��Ϊ������,��Щ���Բ���)
{
public:
	CChild_C();
	~CChild_C();

	void fun();
};

