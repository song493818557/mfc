// 8-3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <process.h>
#include <string.h>
#include "stdio.h"
#include <conio.h>
#include<stdlib.h>
int _tmain(int argc, _TCHAR* argv[])
{
	//˼·��ʹ�ö�������ȡ��λ��

	//int c = 1;
	short int a,b;
	//char b;
uup:
	printf("�����ⰴ����");
	 
	scanf_s("%d %d", &a ,&b);
	//a = a + b;
	//b = a - b;
	//a = a - b;

	//a = a * b;
	//b = a / b;
	//a = a / b;

	a ^=  b;
	printf("\n %d %d", a, b);
	b ^= a ;
	printf("\n %d %d", a, b);
	a ^= b;
	printf("\n %d %d", a,b);
	////��򷨿�����ɶ����ͱ����Ľ��������ڸ����ͱ������޷���ɽ������ڶ��෽������������һ��������Ϸ�����ַ����������ڴ�����Ƕ�������ķ�����������ʱ����������
	
	goto uup;
	
	return 0;

}
