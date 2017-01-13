// 8-8.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <memory.h>



int allchange(int a, int b, int (*xall)(int a, int b)){

	return(xall(a, b));
}
int jia(int a, int b){
	return a + b;

}
int jian(int a, int b){
	return a - b;

}
int cheng(int a, int b){
	return a * b;

}
int _tmain(int argc, _TCHAR* argv[])
{
	int a = 6;
	int b = 5;
	printf("%d + %d = %d\n", a,b,allchange(a,b,jia));
	printf("%d - %d = %d\n", a, b, allchange(a, b, jian));
	printf("%d * %d = %d\n", a, b, allchange(a, b, cheng));
	return 0;
}

