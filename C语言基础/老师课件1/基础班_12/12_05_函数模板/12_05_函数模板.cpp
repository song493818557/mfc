// 12_05_����ģ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <stdlib.h>
#include <iostream>
using std::cout;  using std::endl;

template <typename T1, typename T2>
T2 my_add(T1 NumA, T2 NumB)
{
	return NumA + NumB;
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout << my_add(1, 3.4) << endl;
	cout << my_add(1.2, 'A') << endl;
	cout << my_add(2, 'A') << endl;
	system("pause");
	return 0;
}
