// 11 ��̳еĶ���������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class CBase
{
public:
	int m_height;
};

class CMiddle1:virtual public CBase //��̳�,ֻҪ��������̳У�
	                                //����ͽ������
{
public:
	
};
class CMiddle2 :virtual public CBase
{
public:

};
class CTest :public CMiddle1, public CMiddle2
{

};

int _tmain(int argc, _TCHAR* argv[])
{
	CTest obj;
	//obj.m_height = 100;
	printf("%d",sizeof(CTest));
	return 0;
}

