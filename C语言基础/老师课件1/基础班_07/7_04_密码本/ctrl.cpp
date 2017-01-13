#include "stdafx.h"
#include "ctrl.h"
#include <stdlib.h>

void searchAllInfo(PASSWORD pwd[], int nCount)
{
	printf("==����: %3d ����¼===================\n", nCount);
	for (size_t i = 0; i < nCount; i++)
	{
		printf("--ID: %3d----------------------\n", i);
		printf("Ŀ  ��: %s \n", pwd[i].website);
		printf("�û���: %s \n", pwd[i].userName);
		printf("��  ��: %s \n", pwd[i].passWord);
		printf("��  ע: %s \n", pwd[i].note);
	}

	printf("\n");
	system("pause");
	system("cls");
}
void insertInfo(PASSWORD pwd[], int * pnCount)
{
	int i = *pnCount;
	if (i < 0 || i >= NUM)
	{
		printf("����λ���쳣:%d \n", i);
		return;
	}
	printf("������<Ŀ��վ��>\n");
	scanf_s("%s", pwd[i].website, 100);
	printf("������< �û��� >\n");
	scanf_s("%s", pwd[i].userName, 100);
	printf("������<  ����  >\n");
	scanf_s("%s", pwd[i].passWord, 100);
	printf("������<��ע��Ϣ>\n");
	scanf_s("%s", pwd[i].note, 100);

	(*pnCount)++;

	printf("\n");
	system("pause");
	system("cls");
}
void deleteInfo(PASSWORD pwd[], int * pnCount)
{
	int i = -1;
	printf("�������ɾ����<����ID>\n");
	scanf_s("%d", &i);
	if (i < 0 || i >= NUM)
	{
		printf("ɾ��λ���쳣:%d \n", i);
		return;
	}

	for (size_t j = i; j < *pnCount - 1; j++)
	{
		pwd[j] = pwd[j + 1];
	}

	(*pnCount)--;

	printf("\n");
	system("pause");
	system("cls");
}
void alterInfo(PASSWORD pwd[], int  nCount)
{
	int i = -1;
	printf("��������޸���<����ID>\n");
	scanf_s("%d", &i);
	if (i < 0 || i >= NUM)
	{
		printf("�޸�λ���쳣:%d \n", i);
		return;
	}

	printf("--ID: %3d----------------------\n", i);
	printf("Ŀ  ��: %s \n", pwd[i].website);
	printf("�û���: %s \n", pwd[i].userName);
	printf("��  ��: %s \n", pwd[i].passWord);
	printf("��  ע: %s \n", pwd[i].note);
	printf("~�޸�~\n");
	printf("������<Ŀ��վ��>\n");
	scanf_s("%s", pwd[i].website, 100);
	printf("������< �û��� >\n");
	scanf_s("%s", pwd[i].userName, 100);
	printf("������<  ����  >\n");
	scanf_s("%s", pwd[i].passWord, 100);
	printf("������<��ע��Ϣ>\n");
	scanf_s("%s", pwd[i].note, 100);

	printf("\n");
	system("pause");
	system("cls");
}
void searchInfo(PASSWORD pwd[], int  nCount)
{
	char key[100] = { 0 };
	printf("�������������Ĺؼ���:\n");
	scanf_s("%s", key, 100);

	//�ҳ�����ƥ����
	int findPwd[100] = { 0 };
	int nfindCount = 0;
	for (size_t i = 0; i < nCount; i++)
	{
		if (strstr(pwd[i].website, key))
		{
			findPwd[nfindCount++] = i;
			continue;
		};
		if (strstr(pwd[i].userName, key))
		{
			findPwd[nfindCount++] = i;
			continue;
		};
		if (strstr(pwd[i].passWord, key))
		{
			findPwd[nfindCount++] = i;
			continue;
		};
		if (strstr(pwd[i].note, key))
		{
			findPwd[nfindCount++] = i;
			continue;
		};
	}

	//��ӡ����ƥ����
	printf("==����ƥ��: %3d ����¼===================\n", nfindCount);
	for (size_t i = 0; i < nfindCount; i++)
	{
		int pos = findPwd[i];
		printf("--ID: %3d----------------------\n", pos);
		printf("Ŀ  ��: %s \n", pwd[pos].website);
		printf("�û���: %s \n", pwd[pos].userName);
		printf("��  ��: %s \n", pwd[pos].passWord);
		printf("��  ע: %s \n", pwd[pos].note);
	}

	printf("\n");
	system("pause");
	system("cls");
}

void SaveInfoA(PASSWORD pwd[], int nCount)
{
	/*
	��д�ļ��Ĺ̶���·
	1. ���ļ�
	2. ��д�ļ�
	3. �ر��ļ�
	*/

	//1. ���ļ�
	FILE * pFile;
	errno_t err = fopen_s(&pFile, "data.txt", "w");
	if (err != 0)
	{
		return;
	}
	//2. ��д�ļ�(�ַ�putc/getc,�ַ���puts/gets,��ʽ���ַ���fprintf/fscanf_s)
	fprintf(pFile,"==����: %3d ����¼===================\n", nCount);
	for (size_t i = 0; i < nCount; i++)
	{
		fprintf(pFile, "--ID: %3d----------------------\n", i);
		fprintf(pFile, "Ŀ  ��: %s \n", pwd[i].website);
		fprintf(pFile, "�û���: %s \n", pwd[i].userName);
		fprintf(pFile, "��  ��: %s \n", pwd[i].passWord);
		fprintf(pFile, "��  ע: %s \n", pwd[i].note);
	}

	//3. �ر��ļ�
	fclose(pFile);

	printf("����������ļ��ɹ� \n");
	system("pause");
	system("cls");
}
void SaveInfoB(PASSWORD pwd[], int nCount)
{
	/*
	��д�ļ��Ĺ̶���·
	1. ���ļ�
	2. ��д�ļ�
	3. �ر��ļ�
	*/

	//1. ���ļ�
	FILE * pFile;
	errno_t err = fopen_s(&pFile, "data.i", "wb");
	if (err != 0)
	{
		return;
	}
	//2. ��д�ļ�(fwrite/fread)
	fwrite(&nCount,sizeof(nCount),1, pFile);  //��ǰ�������
	fwrite(&g_size,sizeof(g_size), 1, pFile); //��ǰ���뱾����(����)
	//�ȼ���,�ٴ洢
	int byteSize = sizeof(PASSWORD)*g_size;
	char * buf = (char *)pwd;
	for (size_t i = 0; i < byteSize; i++)
	{
		buf[i] ^= (i+ nCount + g_size);
	}
	size_t rlen = fwrite(pwd, sizeof(PASSWORD), g_size, pFile); //��������
	if (rlen != g_size)
	{
		printf("д�������ļ����� \n");
		fclose(pFile);
		return;
	}

	//3. �ر��ļ�
	fclose(pFile);

	printf("����������ļ��ɹ� \n");
	system("pause");
	system("cls");
}
void readInfo(PPASSWORD * ppPwd, int * pnCount)
{
	/*
	 ��д�ļ��Ĺ̶���·
	 1. ���ļ�
	 2. ��д�ļ�
	 3. �ر��ļ�
	*/

	//1. ���ļ�
	FILE * pFile;
	errno_t err = fopen_s(&pFile,"data.i","rb"); 
	if (err!=0)
	{
		*ppPwd = (PPASSWORD)malloc(sizeof(PASSWORD)*NUM);
		g_size = NUM;
		return;
	}
	//2. ��д�ļ�
	//�ȶ�ȡ,�ٽ���
	fread(pnCount, sizeof(int), 1, pFile);    //��ǰ�������
	fread(&g_size, sizeof(g_size), 1, pFile); //��ǰ���뱾����(����)

	*ppPwd = (PPASSWORD)malloc(sizeof(PASSWORD)*g_size);
	size_t rlen = fread(*ppPwd, sizeof(PASSWORD), g_size, pFile); //��������
	if (rlen != g_size)
	{
		printf("��ȡ�����ļ����� \n");
		fclose(pFile);
		return;
	}
	int byteSize = sizeof(PASSWORD)*g_size;
	char * buf = (char *)*ppPwd;
	for (size_t i = 0; i < byteSize; i++)
	{
		buf[i] ^= (i + *pnCount + g_size);
	}
	//3. �ر��ļ�
	fclose(pFile);
}
