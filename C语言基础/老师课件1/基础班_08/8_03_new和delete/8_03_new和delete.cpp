// 8_03_new��delete.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <malloc.h>
#include <iostream>
using namespace std;

int main()
{
	//����15��Ԫ�ص�int ����
	int * arr1 = (int *)malloc(sizeof(int) * 15);
	int * arr2 = new int[15];
	int * pNum = new int(777);

	cout << *pNum << endl;

	free(arr1);
	delete pNum;
	delete[] arr2;
	arr1 = nullptr;
	arr2 = nullptr;
	pNum = nullptr;

	return 0;
}

