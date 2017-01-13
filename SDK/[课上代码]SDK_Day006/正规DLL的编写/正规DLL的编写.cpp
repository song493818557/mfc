// 正规DLL的编写.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "正规DLL的编写.h"


// 这是导出变量的一个示例
DLL_API int n正规DLL的编写=0;

// 这是导出函数的一个示例。
DLL_API int fn正规DLL的编写(void)
{
	return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 正规DLL的编写.h
C正规DLL的编写::C正规DLL的编写()
{
	return;
}
