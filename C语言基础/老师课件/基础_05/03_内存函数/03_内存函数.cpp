// 03_�ڴ溯��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <memory.h>
int _tmain(int argc, _TCHAR* argv[])
{
	short *p =(short*) malloc(sizeof(short) * 10);//�����ڴ�ռ�
	memset(
		p,//�����ڴ����ʼ��ַ
		0, //���õ�ֵ
		sizeof(short) * 10//��С
		);
	short *p2 = (short*)malloc(sizeof(short) * 10);
	memcpy(
		p2,//������Ŀ���ַ
		p, //������Դ��ַ
		sizeof(short) * 10
		);



	return 0;
}

