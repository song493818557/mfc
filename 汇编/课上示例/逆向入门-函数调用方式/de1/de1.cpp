// de1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct point{
	long Address;
	int type;
};
int gi;
int *pi;
short *ps;
char *pc;
typedef;
int _tmain(int argc, _TCHAR* argv[])
{
	pi = &gi;
	ps = (short*)pi;
	pc = (char*)ps;
	*pi = 0x12345678;
	*ps = 0x5678;
	*pc = 0x99;
	return 0;
}

