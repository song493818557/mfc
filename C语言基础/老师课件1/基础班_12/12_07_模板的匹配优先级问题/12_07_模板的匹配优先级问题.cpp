// 12_07_ģ���ƥ�����ȼ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <stdlib.h>
#include <iostream>
using std::cout;  using std::endl;

template <typename T1, typename T2>
T2  my_add(T1 NumA, T2 NumB) { return NumA + NumB; }
int my_add(int nNumA, int nNumB) { return nNumA + nNumB; }

int _tmain(int argc, _TCHAR* argv[]) {

	/*
	1.���Ҳ�����ȫƥ��ĺ�����
	2.���Һ���ģ�壬ʵ��������һ��ƥ���ģ�庯����
	3.ͨ������ת���ɲ�������ƥ��ĺ�����
	*/
	cout << my_add(1, 3.4) << endl;
	cout << my_add(1, 'A') << endl;
	cout << my_add(15, 87) << endl;
	system("pause");
	return 0;
}
