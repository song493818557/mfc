// 7_04_密码本.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ctrl.h"
/*
版本更新
1.多文件管理 
2.动态内存
3.文件存储
4.加密处理
*/
int main()
{
	//PASSWORD  pwd[NUM] = { 0 }; //密码数组
	PPASSWORD pPwd = nullptr;
	int nCount = 0;               //当前密码个数
	g_size = 0;                   //当前密码本容量

	readInfo(&pPwd,&nCount);

	while (true)
	{
		printf("请输出你的选择:\n");
		printf("1 查看所有密码:\n");
		printf("2 新增密码:\n");
		printf("3 删除密码:\n");
		printf("4 修改密码:\n");
		printf("5 查询密码:\n");
		printf("6 保存密码(文本):\n");
		printf("7 保存密码(二进制):\n");

		OPTION op;
		scanf_s("%d", &op);

		switch (op)
		{
		case 查看所有:
			searchAllInfo(pPwd, nCount);
			break;
		case 新增:
			insertInfo(pPwd, &nCount);
			break;
		case 删除:
			deleteInfo(pPwd, &nCount);
			break;
		case 修改:
			alterInfo(pPwd, nCount);
			break;
		case 查询:
			searchInfo(pPwd, nCount);
			break;
		case 保存文本:
			SaveInfoA(pPwd, nCount);
			break;
		case 保存二进制:
			SaveInfoB(pPwd, nCount);
			break;
		default:
			break;
		}
	}
    return 0;
}

