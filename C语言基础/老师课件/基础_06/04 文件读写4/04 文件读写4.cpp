// 04 �ļ���д4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FILE * pFile = NULL;
	int buf[20] = { 1,2,3,4,5,6,7,8,9,10 };
	fopen_s(&pFile, "D:\\4.txt", "wb");
	fwrite(
		buf, //д����ʼ��ַ
		sizeof(int) * 10, //һ��Ĵ�С
		1,              //д����ٿ�
		pFile);
	fclose(pFile);
	int buf2[20] = {};
	fopen_s(&pFile, "D:\\4.txt", "rb+");
	//�Ȼ�ȡ�ļ���С
	fseek(pFile, 0, SEEK_END); //�ƶ����ļ���β
	int nSize = ftell(pFile);  //��֪�ļ�λ��,��Ϊ�ļ�λ�ô��ڽ�β��
	                           //�ʶ��õ������ļ��Ĵ�С����Ϊ��ȡ���ٴ�
	                           //�ṩ��Ϣ
	int nCount = (nSize / (sizeof(int) * 10)) + 1;
	while (nCount)
	{
	fread(
		buf2, //д����ʼ��ַ
		sizeof(int) * 10, //һ��Ĵ�С
		1,              //д����ٿ�
		pFile);
	nCount--;
	}
	fclose(pFile);
	return 0;
}

