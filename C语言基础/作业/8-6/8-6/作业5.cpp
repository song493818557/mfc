// 8-6.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
struct _stuinfo{
	int num;
	char sname[20];
	int nscore;
}stuinfo, *pstuinfo;
int _tmain(int argc, _TCHAR* argv[])
{

	_stuinfo stuinfo[3] = { 0, "", 0 };
	stuinfo[0] = { 22, "huangwu", 66 };
	stuinfo[1] = { 25, "jerry", 77 };
	stuinfo[2] = { 28, "tom", 88 };
	for (int i = 0; i < 3; i++){

		printf("%d,%s,%d\n", stuinfo[i].num, stuinfo[i].sname, stuinfo[i].nscore);
	}
	pstuinfo = stuinfo;
	for (int i = 0; i < 3; i++){

		printf("%d,%s,%d\n", pstuinfo[i].num, pstuinfo[i].sname, pstuinfo[i].nscore);
	}
	
	return 0;
}