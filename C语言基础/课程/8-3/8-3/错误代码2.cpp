// 8-3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <process.h>
#include <string.h>
#include "stdio.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//1 �����������ʼ��
	int na = 0;
	int nb = 0;
	int nTemp = 0;
	//2 ��a��b�и�ֵ
	printf("������a��");
	scanf_s("%d", &na);
	printf("������b��");
	scanf_s("%d", &nb);
	//3 ���a��b����ô����������
	if (na > nb){
		nTemp = na;
		na = nb;
		nb = nTemp;
		printf("a����%d��b����%d", na, nb);
	}
	system("pause");
	return 0;

}
