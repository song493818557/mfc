// 07_�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int Array[10][10] = { 0 };
	//1 ��Ҫ������ߵ�һ�ж���ֵΪ1��б�ŵ�һ�и�ֵΪ1
	for (int i = 0; i < 10; i++)
	{
		Array[i][0] = 1;
	}
	for (int i = 0; i < 10; i++)
	{
		Array[i][i] = 1;
	}
	//2 ���ÿһ��Ԫ�ص�ֵ
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			Array[i][j] = Array[i - 1][j - 1] + Array[i - 1][j];
		}
	}
	//3 �������
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%5d", Array[i][j]);
		}
		printf("\n");
	}
	return 0;
}

