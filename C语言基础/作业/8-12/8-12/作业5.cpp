// 8-12.cpp : �������̨Ӧ�ó������ڵ㡣
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

	_lifangti a;
	a.shezhi();
	a.shuchu();
	return 0;
}

