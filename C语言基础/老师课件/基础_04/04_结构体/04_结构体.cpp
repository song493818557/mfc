// 04_�ṹ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
struct Test
{
	int hehe;
	char haha;
};
//��һ�ֶ���ṹ������ķ�ʽ
struct
{
	int nId;
	int nAge;
	char Name[20];
	Test nStc;
}g_Per1 = {10,20,"xiaoming"};
//�ڶ��ֶ���ṹ��ķ�ʽ
struct PERSON
{
	int nId;
	int nAge;
	char Name[20];
	
};

PERSON g_Per2 = {20,20,"xiaozhang"};

int _tmain(int argc, _TCHAR* argv[])
{
	

	//printf("ѧ�ţ�%d ������%s", 
	//	g_Per1.nId, g_Per1.Name);
	//printf("%d,%s", g_Per2.nId, g_Per2.Name);


	PERSON g_Per2[2] = {
		{ 20, 20, "xiaozhang" },
		{ 20, 20, "xiaobai" }
	};
	PERSON* pStc = g_Per2;
	//g_Per2[0]
	printf("%d %s\n", g_Per2[0].nAge, g_Per2[0].Name);
	printf("%d %s\n", pStc[0].nAge, pStc[0].Name);
	printf("%d %s\n", pStc->nAge, pStc->Name);
	pStc++;
	printf("%d %s\n", pStc->nAge, pStc->Name);
	return 0;
}

