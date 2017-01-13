// 02_条件编译.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define  DIQIU


#ifdef DIQIU
void Heshui()
{
	//拿杯子喝

}
#else
void Heshui()
{
	//用水袋挤水

}
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

