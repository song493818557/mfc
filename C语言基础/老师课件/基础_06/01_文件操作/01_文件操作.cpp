// 01_�ļ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//FILE* pfile = fopen("D:\\1.txt", "r");//����Ƿǰ�ȫ���
	//���ļ�
	FILE * pFile = NULL;
	fopen_s(&pFile, "D:\\1.txt", "w");
	//�ļ���ز���
	fputc('1', pFile);
	fputc('5', pFile);
	fputc('p', pFile);
	fputc('b', pFile);
	//�ر��ļ�
	fclose(pFile);

	//���ļ�
	pFile = NULL;
	fopen_s(&pFile, "D:\\1.txt", "r");

	//�ļ���ز���
	while (true)
	{
		char cCh = fgetc( pFile);
		if (feof(pFile))//�����Ƿ�0��û������0
		{
			break;
		}
		printf("%c", cCh);
	}
	//�ر��ļ�
	fclose(pFile);



	return 0;
}

