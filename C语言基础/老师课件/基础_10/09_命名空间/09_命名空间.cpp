// 09_命名空间.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Test.h"
#include "Hehe.h"
#include <iostream>
using std::cout;//使用命名空间中的某一个名称
using Test::Inner::fun;

using namespace Hehe;
//使用了Hehe命名空间内的所有名称，就和没用命名空间差不多
int _tmain(int argc, _TCHAR* argv[])
{
	//cout << 1;
	printf("%d", g_num);
	printf("%d", Hehe::g_num);//在使用的时候加上命名空间的名字
	fun();
	return 0;
}

