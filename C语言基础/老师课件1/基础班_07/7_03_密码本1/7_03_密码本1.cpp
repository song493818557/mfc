// 7_03_密码本1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

#define NUM 100
// #define 查看所有 1
// #define 新增     2
// #define 删除     3
// #define 修改     4
// #define 查询     5

enum OPTION
{
	查看所有 = 1,
	新增,
	删除,
	修改,
	查询,
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
密码太多~~记不住哇~~~
给自己写个小工具,从此变身密码达人(*@ο@*) 哇～
*/
int main()
{
	PASSWORD  pwd[NUM] = {0}; //密码数组 
	int nCount = 0;           //当前密码个数

	while (true)
	{
		printf("请输出你的选择:\n");
		printf("1 查看所有密码:\n");
		printf("2 新增密码:\n");
		printf("3 删除密码:\n");
		printf("4 修改密码:\n");
		printf("5 查询密码:\n");
		
		OPTION op;
		scanf_s("%d", &op);

		switch (op)
		{
		case 查看所有:
			searchAllInfo(pwd, nCount);
			break;
		case 新增:
			insertInfo(pwd, &nCount);
			break;
		case 删除:
			deleteInfo(pwd, &nCount);
			break;
		case 修改:
			alterInfo(pwd, nCount);
			break;
		case 查询:
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
	printf("==共计: %3d 条记录===================\n", nCount);
	for (size_t i = 0; i < nCount; i++)
	{
		printf("--ID: %3d----------------------\n", i);
		printf("目  标: %s \n", pwd[i].website);
		printf("用户名: %s \n", pwd[i].userName);
		printf("密  码: %s \n", pwd[i].passWord);
		printf("备  注: %s \n", pwd[i].note);
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
		printf("插入位置异常:%d \n", i);
		return;
	}
	printf("请输入<目标站点>\n");
	scanf_s("%s", pwd[i].website,100);
	printf("请输入< 用户名 >\n");
	scanf_s("%s", pwd[i].userName,100);
	printf("请输入<  密码  >\n");
	scanf_s("%s", pwd[i].passWord,100);
	printf("请输入<备注信息>\n");
	scanf_s("%s", pwd[i].note,100);

	(*pnCount)++;

	printf("\n");
	system("pause");
	system("cls");
}
void deleteInfo(PASSWORD pwd[], int * pnCount) 
{
	int i = -1;
	printf("请输入待删除项<密码ID>\n");
	scanf_s("%d", &i);
	if (i < 0 || i >= NUM)
	{
		printf("删除位置异常:%d \n", i);
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
	printf("请输入待修改项<密码ID>\n");
	scanf_s("%d", &i);
	if (i < 0 || i >= NUM)
	{
		printf("修改位置异常:%d \n", i);
		return;
	}

	printf("--ID: %3d----------------------\n", i);
	printf("目  标: %s \n", pwd[i].website);
	printf("用户名: %s \n", pwd[i].userName);
	printf("密  码: %s \n", pwd[i].passWord);
	printf("备  注: %s \n", pwd[i].note);
	printf("~修改~\n");
	printf("请输入<目标站点>\n");
	scanf_s("%s", pwd[i].website,100);
	printf("请输入< 用户名 >\n");
	scanf_s("%s", pwd[i].userName, 100);
	printf("请输入<  密码  >\n");
	scanf_s("%s", pwd[i].passWord, 100);
	printf("请输入<备注信息>\n");
	scanf_s("%s", pwd[i].note, 100);

	printf("\n");
	system("pause");
	system("cls");
}
void searchInfo(PASSWORD pwd[], int  nCount)
{
	char key[100] = { 0 };
	printf("请输入查找密码的关键字:\n");
	scanf_s("%s", key, 100);

	//找出所有匹配项
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

	//打印所有匹配项
	printf("==共计匹配: %3d 条记录===================\n", nfindCount);
	for (size_t i = 0; i < nfindCount; i++)
	{
		int pos = findPwd[i];
		printf("--ID: %3d----------------------\n", pos);
		printf("目  标: %s \n", pwd[pos].website);
		printf("用户名: %s \n", pwd[pos].userName);
		printf("密  码: %s \n", pwd[pos].passWord);
		printf("备  注: %s \n", pwd[pos].note);
	}

	printf("\n");
	system("pause");
	system("cls");
}