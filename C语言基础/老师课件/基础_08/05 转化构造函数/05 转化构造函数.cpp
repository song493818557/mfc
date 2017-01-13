// 05 转化构造函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class CHEHE
{
public:

};
class CTest
{

	CTest()
	{}
	
};

int _tmain(int argc, _TCHAR* argv[])
{
	CHEHE objA;
	CTest obj;

	CTest obj2(objA);
	return 0;
}

