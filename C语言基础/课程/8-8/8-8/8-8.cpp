// 8-8.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <crtdbg.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
typedef void(* signal(int signum, void(*handler)(int)))(int);
signal;
int _tmain(int argc, _TCHAR* argv[])
{
	char *str1 = "hello 15pb";
	//int temp = ;
	char *str2 = (char*)malloc(strlen(str1));
//	strcpy(str2,str1);//ͨ���ַ������� ֵ������ ��Ҫʹ�� �ڴ濽��
	memset(
		str2,//�����ڴ����ʼ��ַ
		*str1, //���õ�ֵ
		sizeof(short) * 10//��С
		);
	memcpy(
		str1,//������Ŀ���ַ
		str2, //������Դ��ַ 
		sizeof(short) * 10
		);
	printf("%d\n", str2);
	return 0;
}

