// 8.9.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>


int _tmain(int argc, _TCHAR* argv[])
{
	//FILE* fope=fopen("c:\\File.txt","r");
	FILE * fope = NULL;
		int i = fopen_s(&fope, "c:\\a\\file.txt","w+");
		//�ļ���ز���
		fputc('xxx',fope);
		//�ر��ļ�
		fclose(fope);
	return 0;
}

