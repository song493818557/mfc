// 11 多继承的二义性问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CBase
{
public:
	int m_height;
};

class CMiddle1:virtual public CBase //虚继承,只要子类是虚继承，
	                                //父类就叫虚基类
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

