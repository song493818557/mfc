// �绰��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#define �鿴���� 1
#define ����     2
#define ɾ��     3
#define �޸�     4
#define ����     5
int g_count = 0;
//���������������Ǵ�������ָ�롣
void AddInfo(char ������[200][16], char(*�绰�����)[12])  //�����ϵ��

{

	char buf[50] = {0};
	printf("����������");
	scanf_s("%s", buf, 50);
	strcpy_s(������[g_count], 16, buf);
	printf("������绰����");
	scanf_s("%s", buf, 50);
	strcpy_s(�绰�����[g_count], 12, buf);
	g_count++;
}

void DeleteInfo(
	char ������[200][16], 
	char(*�绰�����)[12]
	)//ɾ����ϵ��
{
	char ��ɾ������[50] = { 0 };
	printf("������Ҫɾ��������");
	scanf_s("%s", ��ɾ������, 50);
	for (size_t i = 0; i < g_count; i++)
	{
		if (strcmp(������[i], ��ɾ������) == 0)
		{
			for (int λ�� = i; λ�� < g_count-1; λ��++)
			{
				strcpy_s(������[λ��],16, ������[λ�� + 1]);
				strcpy_s(�绰�����[λ��], 12, �绰�����[λ�� + 1]);
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

void SearchAll(char ������[200][16], char(*�绰�����)[12])
{
	for (int i = 0; i < g_count; i++)
	{
		printf("%s %s\n", ������[i], �绰�����[i]);
	}
	system("pause");

}



int _tmain(int argc, _TCHAR* argv[])
{
	int  ѡ�� = 0;
	char �绰����[200][12];
	char ����[200][16];
	while (true)
	{
		printf("���������ѡ��:\n");
		printf("1 �鿴������ϵ��\n");
		printf("2 ������ϵ��\n");
		printf("3 ɾ����ϵ��\n");
		printf("4 �޸���ϵ��\n");
		printf("5 ������ϵ��\n");

		scanf_s("%d", &ѡ��);
		system("cls");
		switch (ѡ��)
		{
		case �鿴����:
		{
			SearchAll(����, �绰����);
			break;
		}
		case ����:
		{
			AddInfo(����, �绰����);
			break;
		}
		case ɾ��:
		{
			DeleteInfo(����, �绰����);
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
		default:
			break;
		}
		system("cls");
	}
	

	return 0;
}