// 8-3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <process.h>
#include <string.h>
#include "stdio.h"
#include <conio.h>
int _tmain(int argc, _TCHAR* argv[])
{
	//1 ����һ��char�ͱ������������հ�������
uup:
	int c = 0;
	printf("	*********************************************************\n");
	printf("	*			1   one player			*\n");
	printf("	*			2   two player			*\n");
	printf("	*			3   Edit map			*\n");
	printf("	*			4   Chose Level			*\n");
	printf("	*********************************************************\n");
	printf("	����    Please input your choice(1~4)	 ����\n");
	//2 ���հ�������
	printf("	");
	scanf_s("%d", &c);  //%c��ʾ����һ���ַ�����˼Ŷ������ô�����ʼ�ȥ��~~
	//3 ���ݰ�������������Ӧ
	
	switch (c)
	{
	case 1:
		printf("	������\n");
		break;
	case 2:
		printf("	������\n");
		break;
	case 3:
		printf("	������\n");
		break;
	case 4:
		printf("	������\n");
		break;
	default:
		printf("����    Please input your choice(1~4)	 ����\n");
		break;
		//��Ҫ��ȡʲô�����ټ������
	}
	goto uup;
	return 0;

}
