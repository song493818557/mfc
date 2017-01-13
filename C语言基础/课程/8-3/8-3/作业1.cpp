// 8-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>
#include <string.h>
#include "stdio.h"
#include <conio.h>
int _tmain(int argc, _TCHAR* argv[])
{
	//1 定义一个char型变量，用来接收按键操作
uup:
	int c = 0;
	printf("	*********************************************************\n");
	printf("	*			1   one player			*\n");
	printf("	*			2   two player			*\n");
	printf("	*			3   Edit map			*\n");
	printf("	*			4   Chose Level			*\n");
	printf("	*********************************************************\n");
	printf("	……    Please input your choice(1~4)	 ……\n");
	//2 接收按键操作
	printf("	");
	scanf_s("%d", &c);  //%c表示的是一个字符的意思哦，忘了么，看笔记去吧~~
	//3 根据按键操作做出反应
	
	switch (c)
	{
	case 1:
		printf("	向上走\n");
		break;
	case 2:
		printf("	向下走\n");
		break;
	case 3:
		printf("	向左走\n");
		break;
	case 4:
		printf("	向右走\n");
		break;
	default:
		printf("……    Please input your choice(1~4)	 ……\n");
		break;
		//想要获取什么按键再继续添加
	}
	goto uup;
	return 0;

}
