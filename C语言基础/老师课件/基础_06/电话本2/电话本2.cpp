// 电话本2.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#define 查看所有 1
#define 新增     2
#define 删除     3
#define 修改     4
#define 查找     5
#define 保存     6
#define 读取     7

int g_count = 0; //当前的存储量
int g_max = 0;   //当前的最大存储量

typedef struct _INFO
{
	char 姓名[20];
	char 手机号[20];
	char 座机号[20];
	int  性别;
	int  年龄;
	char 住址[20];
}INFO,*PINFO;
//PINFO和INFO * 是一样的

//这两个参数，都是代表数组指针。
void AddInfo(INFO ** 联系人)  //添加联系人

{
	if (g_count == g_max)//已经要存不下了
	{
		g_max = g_max * 2;
		INFO * p = (INFO*)malloc(sizeof(INFO)*g_max);
		memcpy(p, *联系人, sizeof(INFO)* g_max / 2);
		free(*联系人);
		*联系人 = p;
	}

	char buf[50] = { 0 };
	printf("请输入姓名");
	scanf_s("%s", buf, 50);
	strcpy_s((*联系人)[g_count].姓名, 16, buf);
	printf("请输入电话号码");
	scanf_s("%s", buf, 50);
	strcpy_s((*联系人)[g_count].手机号, 12, buf);
	g_count++;
}

void DeleteInfo(
	INFO * 联系人
	)//删除联系人
{
	char 待删除名字[50] = { 0 };
	printf("请输入要删除的姓名");
	scanf_s("%s", 待删除名字, 50);
	//1 删除的逻辑，就是找到这个人在表中的位置
	
	for (size_t i = 0; i < g_count; i++)
	{
		if (strcmp(联系人[i].姓名, 待删除名字) == 0)
		{
			//2 将后面的联系人覆盖到前面来
			for (int 位置 = i; 位置 < g_count - 1; 位置++)
			{
				/*strcpy_s(联系人[位置].姓名, 16, 联系人[位置 + 1].姓名);
				strcpy_s(联系人[位置].手机号, 12, 联系人[位置 + 1].手机号);*/
				memcpy(&联系人[位置], &联系人[位置 + 1], sizeof(INFO));
			}
			g_count--;
			break;
		}
	}
}

void AlterInfo()//修改联系人
{

}
void SearchInfo()//查找联系人
{

}

void SearchAll(INFO * 联系人)
{
	for (int i = 0; i < g_count; i++)
	{
		printf("%s %s\n", 联系人[i].姓名, 联系人[i].手机号);
	}
	system("pause");

}



int _tmain(int argc, _TCHAR* argv[])
{
	int  选择 = 0;
	g_max = 3;
	INFO* 联系人 = (INFO*)malloc(sizeof(INFO) * g_max);

	while (true)
	{
		printf("请输入你的选择:\n");
		printf("1 查看所有联系人\n");
		printf("2 新增联系人\n");
		printf("3 删除联系人\n");
		printf("4 修改联系人\n");
		printf("5 查找联系人\n");
		printf("6 保存\n");
		printf("7 读取\n");
		scanf_s("%d", &选择);
		system("cls");
		switch (选择)
		{
		case 查看所有:
		{
			SearchAll(联系人);
			break;
		}
		case 新增:
		{
			AddInfo(&联系人);
			break;
		}
		case 删除:
		{
			DeleteInfo(联系人);
			break;
		}
		case 修改:
		{
			break;
		}
		case 查找:
		{
			break;
		}
		case 保存:
		{
			FILE * pFile = NULL;
			fopen_s(&pFile, "D:\\电话本.txt", "wb");
			fprintf(pFile, "%d", g_count);
			fwrite(
				联系人, //写的起始地址
				sizeof(INFO) * g_count, //一块的大小
				1,              //写入多少块
				pFile);
			fclose(pFile);
		}
		case 读取:
		{
			FILE * pFile = NULL;
			fopen_s(&pFile, "D:\\电话本.txt", "rb");
			fscanf_s(pFile, "%d", &g_count);
			fread(
				联系人, //写的起始地址
				sizeof(INFO) * g_count, //一块的大小
				1,                      //写入多少块
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

