// 8-8.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <memory.h>


int _tmain(int argc, _TCHAR* argv[])
{
	int *inumb = (int*)malloc(sizeof(int) * 10);
	memset(
		inumb,//�����ڴ����ʼ��ַ
		{ 0 },
		sizeof(int) * 10
		);
		int  a[10] = { 0, 13, 22, 31, 4, 25, 66, 7, 8, 9 };
		for (int i = 0; i < 10;i++){
			inumb[i] = a[i];
			//printf("%d", inumb[i]);
			//printf("%d\n", *(inumb + i));
			printf("%d\n", *&(inumb[i])); 
			
		}
		free(inumb);
		inumb = NULL;

		
	return 0;
}

