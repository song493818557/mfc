// 12_06_ģ���ػ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <stdlib.h>
#include <iostream>
using std::cout;  using std::endl;

template <typename T>
T MyMax(const T NumA, const T NumB) {
	return NumA < NumB ? NumB : NumA;
}

template <>
const char* MyMax<const char*>(const char* pStrA, const char* pStrB) {
	return (strcmp(pStrA, pStrB) < 0) ? pStrB : pStrA;
}
int _tmain(int argc, _TCHAR* argv[]) {
	cout << MyMax("15PB", "A1Pass") << endl;
	system("pause");
	return 0;
}


