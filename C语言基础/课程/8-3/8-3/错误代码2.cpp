// 8-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>
#include <string.h>
#include "stdio.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//1 定义变量并初始化
	int na = 0;
	int nb = 0;
	int nTemp = 0;
	//2 像a，b中赋值
	printf("请输入a：");
	scanf_s("%d", &na);
	printf("请输入b：");
	scanf_s("%d", &nb);
	//3 如果a比b大，那么交换两个数
	if (na > nb){
		nTemp = na;
		na = nb;
		nb = nTemp;
		printf("a等于%d，b等于%d", na, nb);
	}
	system("pause");
	return 0;

}
