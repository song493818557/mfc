/* 思考题二测试*/
int sizof(char arrc[]){

printf("%d\n", sizeof(arrc));
printf("%d\n", strnlen_s(arrc,100));
//printf("%d", _countof(arrc));
return 0;
}
#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
void * xxcc(){ return 0; }

int _tmain(int argc, _TCHAR* argv[])
{


	/*思考题二测试
	char brrc[] = {1,2,3,4,5,5,6,7,33,2,1,2,3,3,1,23};
	char *p = brrc;
	sizof(p);
	printf("%d\n", sizeof(p));
	printf("%d\n", strnlen_s(brrc, 100));
	printf("%d", _countof(brrc));*/

	//变量跟踪 p1 没有分配内存空间  p2 分配了内存 但是值是错的
	/*
	char p2[] = "hello15pb";
	printf("%s\n", p2);
	printf("%d\n", p2);
	int b = sizeof(p2);
	char *p1 =  "hello15pb";
	printf("%s\n", &p1);
	printf("%d\n", &p1);
	int a=sizeof(p1);
	*/
}