// 6_01_ָ�����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

/*
1.	ֻ�ܽ��мӷ��ͼ������㣺+  -  ++  --  +=  -=
2.	������ʽ��ָ�������  ����  ָ�� - ָ��
3.	ָ��������ֵ�Ӽ��Ľ����ָ�룬��ʾʹ��ָ���ƶ� 
( ����ֵ*�洢��Ԫ�Ĵ�С) ֮����ڴ��ַ��
�洢��Ԫ�Ĵ�С���Ǹ�ָ����ָ�����������������ڴ��С��
4.	ָ����ָ��ļ�����Ҫ�����������ָ������ͬһ���ͣ�
��������������ʾ����ָ��֮������ݵĸ���������������ַ�Ĳ�ֵ��

*/
int main()
{
	int nNumA = 0x11111111;
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int * p = arr;
	for (int i = 0; i < 10;i++)
	{
		printf("%d", *p);
		p++;
	}
	int nNumB = 0x22222222;

	int * pNumA = &arr[4];
	int * pNumB = &arr[9];

	int nResult = 0;
	//pNumA + pNumB;  //error
	nResult = pNumA - pNumB;
	//pNumA * pNumB;  //error
	//pNumA / pNumB;  //error

	pNumA = pNumA + 5;
	pNumA = pNumA - 5;

	pNumA = &nNumA;
	pNumB = &nNumB;
	nResult = pNumA - pNumB;

	char ch = 'h';
	char * pCh = &ch;
	//nResult = pNumA - pCh;   //error: ����ָ�����������ͬ

    return 0;
}

