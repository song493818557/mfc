// 03 �ļ�����3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//д
	FILE * pFile = NULL;
	char buf[20] = { 0 };
	fopen_s(&pFile, "D:\\3.txt", "w");
	fprintf_s(pFile, "hello%dpb", 15);
	fclose(pFile);

	//��
	pFile = NULL;
	fopen_s(&pFile, "D:\\3.txt", "r");
	fscanf_s(pFile, "%s", buf, 20);
	fclose(pFile);

	return 0;
}

