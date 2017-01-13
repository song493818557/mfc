// 逆向入门-定位核心代码示例.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <windows.h>


int _tmain(int argc, _TCHAR* argv[])
{
	printf("请输入密码:");
	char buff[ 20 ];
	scanf_s("%s" , buff , 20);


	if(strcmp(buff , "hello15pb") == 0)
	{
		printf("密码正确\n");
	}
	else
	{
		MessageBoxW(0 , L"密码错误" , L"提示" , 0);
	}


	return 0;
}

