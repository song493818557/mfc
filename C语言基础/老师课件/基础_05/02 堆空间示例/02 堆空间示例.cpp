// 02 �ѿռ�ʾ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <stdlib.h>
int _tmain(int argc, _TCHAR* argv[])  {
	int *pResults, nNum;
	int a;
	scanf_s("%d", &nNum);
	if (!(pResults = (int*)malloc(nNum*sizeof(int))))
		return 0;
	for (int i = 0; i<nNum; i++)
		scanf_s("%d", pResults + i);
	    //scanf_s("%d", &pResults[i]);�����ַ�ʽ��һ���ġ�

	for (int i = 0; i<nNum; i++)
		printf("%5d", pResults[i]);
	free(pResults);//�����ǣ�����ͷ���
	system("pause");
	return 0;
}
