// 8-12.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "sources.h"
using std::endl;
using std::cin;
using std::cout;
int _tmain(int argc, _TCHAR* argv[])
{

	_man *aa  = new _man[10];
	for (int i = 0; i < 4;i++)
	{
		cin >> aa[i].name >> aa[i].age >> aa[i].height >> aa[i].weight;
	}
	for (int i = 0; i < 4; i++)
	{
		aa[i].get_Health();
		cout << "姓名" << aa[i].name << "年龄" << aa[i].age << "身高" << aa[i].height << "体重" << aa[i].weight << "健康指数" << std::dec<< aa[i].Health << endl;
	}
	//int &n = aa.chang;
	
	//结果没什么区别
	return 0;
}

