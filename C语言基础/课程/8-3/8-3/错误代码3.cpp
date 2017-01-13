// 8-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>
#include <string.h>
#include "stdio.h"
#include <conio.h>
#include<stdlib.h>
int _tmain(int argc, _TCHAR* argv[])
{
	
	//char b;
uup:
	//1 定义一个char型变量，用来接收按键操作
	char c = 0;
	//2 接收按键操作
	scanf_s("%c", &c);  //%c表示的是一个字符的意思哦，忘了么，看笔记去吧~~
	//3 根据按键操作做出反应
	char * pOper1 = "";
	char * pOper2 = "";
	char * pOper3 = "";
	char * pOper4 = "";
	switch (c)
	{
	case 'w':
		pOper1 = "↑";
		printf(pOper1);
		break;
	case 's':
		pOper2 = "↓";
		printf(pOper2);
		break;
	case 'a':
		pOper3 = "←";
		printf(pOper3);
		break;
	case 'd':
		pOper4 = "→";
		printf(pOper4);
		break;
	default:
		break;//想要获取什么按键再继续添加
	}
	printf("\n");
	 goto uup;
	system("pause");
	return 0;

}
