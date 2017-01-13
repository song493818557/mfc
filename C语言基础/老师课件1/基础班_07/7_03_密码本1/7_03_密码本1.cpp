// 7_03_���뱾1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

#define NUM 100
// #define �鿴���� 1
// #define ����     2
// #define ɾ��     3
// #define �޸�     4
// #define ��ѯ     5

enum OPTION
{
	�鿴���� = 1,
	����,
	ɾ��,
	�޸�,
	��ѯ,
};

typedef struct _PASSWORD
{
	char website[100];
	char userName[100];
	char passWord[100];
	char note[100];
}PASSWORD,*PPASSWORD;


void searchAllInfo(PASSWORD pwd[],int nCount); //PPASSWORD pPwd
void insertInfo(PASSWORD pwd[], int * pnCount);
void deleteInfo(PASSWORD pwd[], int * pnCount);
void alterInfo( PASSWORD pwd[], int  nCount);
void searchInfo(PASSWORD pwd[], int  nCount);

/*
����̫��~~�ǲ�ס��~~~
���Լ�д��С����,�Ӵ˱����������(*@��@*) �ۡ�
*/
int main()
{
	PASSWORD  pwd[NUM] = {0}; //�������� 
	int nCount = 0;           //��ǰ�������

	while (true)
	{
		printf("��������ѡ��:\n");
		printf("1 �鿴��������:\n");
		printf("2 ��������:\n");
		printf("3 ɾ������:\n");
		printf("4 �޸�����:\n");
		printf("5 ��ѯ����:\n");
		
		OPTION op;
		scanf_s("%d", &op);

		switch (op)
		{
		case �鿴����:
			searchAllInfo(pwd, nCount);
			break;
		case ����:
			insertInfo(pwd, &nCount);
			break;
		case ɾ��:
			deleteInfo(pwd, &nCount);
			break;
		case �޸�:
			alterInfo(pwd, nCount);
			break;
		case ��ѯ:
			searchInfo(pwd, nCount);
			break;
		default:
			break;
		}
	}
    return 0;
}



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
	if (i<0 || i>=NUM)
	{
		printf("����λ���쳣:%d \n", i);
		return;
	}
	printf("������<Ŀ��վ��>\n");
	scanf_s("%s", pwd[i].website,100);
	printf("������< �û��� >\n");
	scanf_s("%s", pwd[i].userName,100);
	printf("������<  ����  >\n");
	scanf_s("%s", pwd[i].passWord,100);
	printf("������<��ע��Ϣ>\n");
	scanf_s("%s", pwd[i].note,100);

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

	for (size_t j = i; j < *pnCount-1; j++)
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
	scanf_s("%s", pwd[i].website,100);
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
	int findPwd[100] = {0};
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