// 01_堆空间.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <malloc.h>

int g_Array[4];

void Fun()
{

	int * p = (int*)malloc(100 *1024);

	//free(p);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int Array[4];//数组长度只能是常量
	int * p = 0;
	int Size = 4;
	//申请
	p = (int*)malloc(sizeof(int) * Size);
	//使用
	p[0] = 'f';
	p[1] = 'g';
	p[2];
	p[3];
	p[4] = 20;
	printf("%d\n", p[0]);
	printf("%c\n", p[0]);
	printf("%c\n", p[1]);
	printf("%d\n", p[1]);
	printf("%d\n", p[4]);
	printf("%s\n", p);
	//使用堆的时候，一定要小心越界问题，很难
	//排错
	//for (int i = 0; i < 200; i++)
	//{
	//	p[i] = 10;
	//}
	//成千上万行代码就在这里....

	//堆的回收问题
	/*while (true)
	{
	Fun();
	}
	free(p);*/

	//成千上万行代码


	return 0;
}

