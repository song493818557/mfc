// 电话本.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#define 查看所有 1
#define 新增     2
#define 删除     3
#define 修改     4
#define 查找     5
int g_count = 0;
//这两个参数，都是代表数组指针。
void AddInfo(char 姓名表[200][16], char(*电话号码表)[12])  //添加联系人

{

	char buf[50] = {0};
	printf("请输入姓名");
	scanf_s("%s", buf, 50);
	strcpy_s(姓名表[g_count], 16, buf);
	printf("请输入电话号码");
	scanf_s("%s", buf, 50);
	strcpy_s(电话号码表[g_count], 12, buf);
	g_count++;
}

void DeleteInfo(
	char 姓名表[200][16], 
	char(*电话号码表)[12]
	)//删除联系人
{
	char 待删除名字[50] = { 0 };
	printf("请输入要删除的姓名");
	scanf_s("%s", 待删除名字, 50);
	for (size_t i = 0; i < g_count; i++)
	{
		if (strcmp(姓名表[i], 待删除名字) == 0)
		{
			for (int 位置 = i; 位置 < g_count-1; 位置++)
			{
				strcpy_s(姓名表[位置],16, 姓名表[位置 + 1]);
				strcpy_s(电话号码表[位置], 12, 电话号码表[位置 + 1]);
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

void SearchAll(char 姓名表[200][16], char(*电话号码表)[12])
{
	for (int i = 0; i < g_count; i++)
	{
		printf("%s %s\n", 姓名表[i], 电话号码表[i]);
	}
	system("pause");

}



int _tmain(int argc, _TCHAR* argv[])
{
	int  选择 = 0;
	char 电话号码[200][12];
	char 姓名[200][16];
	while (true)
	{
		printf("请输入你的选择:\n");
		printf("1 查看所有联系人\n");
		printf("2 新增联系人\n");
		printf("3 删除联系人\n");
		printf("4 修改联系人\n");
		printf("5 查找联系人\n");

		scanf_s("%d", &选择);
		system("cls");
		switch (选择)
		{
		case 查看所有:
		{
			SearchAll(姓名, 电话号码);
			break;
		}
		case 新增:
		{
			AddInfo(姓名, 电话号码);
			break;
		}
		case 删除:
		{
			DeleteInfo(姓名, 电话号码);
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
		default:
			break;
		}
		system("cls");
	}
	

	return 0;
}