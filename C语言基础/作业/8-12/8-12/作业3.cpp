// 8-12.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using std::endl;
using std::wcout;
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

	float m = 8.8;
	float g = 10;
	cout << g << endl << m;
	jisuan(m,g);
	return 0;
}

