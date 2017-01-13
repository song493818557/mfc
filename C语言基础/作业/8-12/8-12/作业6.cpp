// 8-12.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "sources.h"
using std::endl;
using std::cin;
using std::cout;
void jisuan(float &m , float &g ){
	float temp = 0;
	temp = m;
	m = g;
	g = temp;
	//cout << g + m<<endl;
}
int _tmain(int argc, _TCHAR* argv[])
{

	_lifangtia aa;
	int &n = aa.chang;
	cout << &n<<endl;
	aa.shuchu();
	//结果没什么区别
	return 0;
}

