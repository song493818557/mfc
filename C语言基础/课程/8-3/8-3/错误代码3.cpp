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
	
	//char b;
uup:
	//1 ����һ��char�ͱ������������հ�������
	char c = 0;
	//2 ���հ�������
	scanf_s("%c", &c);  //%c��ʾ����һ���ַ�����˼Ŷ������ô�����ʼ�ȥ��~~
	//3 ���ݰ�������������Ӧ
	char * pOper1 = "";
	char * pOper2 = "";
	char * pOper3 = "";
	char * pOper4 = "";
	switch (c)
	{
	case 'w':
		pOper1 = "��";
		printf(pOper1);
		break;
	case 's':
		pOper2 = "��";
		printf(pOper2);
		break;
	case 'a':
		pOper3 = "��";
		printf(pOper3);
		break;
	case 'd':
		pOper4 = "��";
		printf(pOper4);
		break;
	default:
		break;//��Ҫ��ȡʲô�����ټ������
	}
	printf("\n");
	 goto uup;
	system("pause");
	return 0;

}
