// �绰��2.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#define �鿴���� 1
#define ����     2
#define ɾ��     3
#define �޸�     4
#define ����     5
#define ����     6
#define ��ȡ     7

int g_count = 0; //��ǰ�Ĵ洢��
int g_max = 0;   //��ǰ�����洢��

typedef struct _INFO
{
	char ����[20];
	char �ֻ���[20];
	char ������[20];
	int  �Ա�;
	int  ����;
	char סַ[20];
}INFO,*PINFO;
//PINFO��INFO * ��һ����

//���������������Ǵ�������ָ�롣
void AddInfo(INFO ** ��ϵ��)  //�����ϵ��

{
	if (g_count == g_max)//�Ѿ�Ҫ�治����
	{
		g_max = g_max * 2;
		INFO * p = (INFO*)malloc(sizeof(INFO)*g_max);
		memcpy(p, *��ϵ��, sizeof(INFO)* g_max / 2);
		free(*��ϵ��);
		*��ϵ�� = p;
	}

	char buf[50] = { 0 };
	printf("����������");
	scanf_s("%s", buf, 50);
	strcpy_s((*��ϵ��)[g_count].����, 16, buf);
	printf("������绰����");
	scanf_s("%s", buf, 50);
	strcpy_s((*��ϵ��)[g_count].�ֻ���, 12, buf);
	g_count++;
}

void DeleteInfo(
	INFO * ��ϵ��
	)//ɾ����ϵ��
{
	char ��ɾ������[50] = { 0 };
	printf("������Ҫɾ��������");
	scanf_s("%s", ��ɾ������, 50);
	//1 ɾ�����߼��������ҵ�������ڱ��е�λ��
	
	for (size_t i = 0; i < g_count; i++)
	{
		if (strcmp(��ϵ��[i].����, ��ɾ������) == 0)
		{
			//2 ���������ϵ�˸��ǵ�ǰ����
			for (int λ�� = i; λ�� < g_count - 1; λ��++)
			{
				/*strcpy_s(��ϵ��[λ��].����, 16, ��ϵ��[λ�� + 1].����);
				strcpy_s(��ϵ��[λ��].�ֻ���, 12, ��ϵ��[λ�� + 1].�ֻ���);*/
				memcpy(&��ϵ��[λ��], &��ϵ��[λ�� + 1], sizeof(INFO));
			}
			g_count--;
			break;
		}
	}
}

void AlterInfo()//�޸���ϵ��
{

}
void SearchInfo()//������ϵ��
{

}

void SearchAll(INFO * ��ϵ��)
{
	for (int i = 0; i < g_count; i++)
	{
		printf("%s %s\n", ��ϵ��[i].����, ��ϵ��[i].�ֻ���);
	}
	system("pause");

}



int _tmain(int argc, _TCHAR* argv[])
{
	int  ѡ�� = 0;
	g_max = 3;
	INFO* ��ϵ�� = (INFO*)malloc(sizeof(INFO) * g_max);

	while (true)
	{
		printf("���������ѡ��:\n");
		printf("1 �鿴������ϵ��\n");
		printf("2 ������ϵ��\n");
		printf("3 ɾ����ϵ��\n");
		printf("4 �޸���ϵ��\n");
		printf("5 ������ϵ��\n");
		printf("6 ����\n");
		printf("7 ��ȡ\n");
		scanf_s("%d", &ѡ��);
		system("cls");
		switch (ѡ��)
		{
		case �鿴����:
		{
			SearchAll(��ϵ��);
			break;
		}
		case ����:
		{
			AddInfo(&��ϵ��);
			break;
		}
		case ɾ��:
		{
			DeleteInfo(��ϵ��);
			break;
		}
		case �޸�:
		{
			break;
		}
		case ����:
		{
			break;
		}
		case ����:
		{
			FILE * pFile = NULL;
			fopen_s(&pFile, "D:\\�绰��.txt", "wb");
			fprintf(pFile, "%d", g_count);
			fwrite(
				��ϵ��, //д����ʼ��ַ
				sizeof(INFO) * g_count, //һ��Ĵ�С
				1,              //д����ٿ�
				pFile);
			fclose(pFile);
		}
		case ��ȡ:
		{
			FILE * pFile = NULL;
			fopen_s(&pFile, "D:\\�绰��.txt", "rb");
			fscanf_s(pFile, "%d", &g_count);
			fread(
				��ϵ��, //д����ʼ��ַ
				sizeof(INFO) * g_count, //һ��Ĵ�С
				1,                      //д����ٿ�
				pFile);
			fclose(pFile);
		}
		default:
			break;
		}
		system("cls");
	}
	return 0;
}

