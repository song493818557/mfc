// 01_�ѿռ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <malloc.h>

int g_Array[4];

void Fun()
{

	int * p = (int*)malloc(100 *1024);

	//free(p);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int Array[4];//���鳤��ֻ���ǳ���
	int * p = 0;
	int Size = 4;
	//����
	p = (int*)malloc(sizeof(int) * Size);
	//ʹ��
	p[0] = 'f';
	p[1] = 'g';
	p[2];
	p[3];
	p[4] = 20;
	printf("%d\n", p[0]);
	printf("%c\n", p[0]);
	printf("%c\n", p[1]);
	printf("%d\n", p[1]);
	printf("%d\n", p[4]);
	printf("%s\n", p);
	//ʹ�öѵ�ʱ��һ��ҪС��Խ�����⣬����
	//�Ŵ�
	//for (int i = 0; i < 200; i++)
	//{
	//	p[i] = 10;
	//}
	//��ǧ�����д����������....

	//�ѵĻ�������
	/*while (true)
	{
	Fun();
	}
	free(p);*/

	//��ǧ�����д���


	return 0;
}

