// 03_指针.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//1 定义一个指针,并使用
	int * p = 0;//初识化为0
	int Num1 = 100;
	p = &Num1;
	printf("%d\n", *p);
	*p = 200;
	printf("%d\n", Num1);
	//2 指针的验证
	printf("p中存储的数据%d\n", p);
	printf("对p解引用的数据%d\n", *p);
	printf("Num1变量的地址%d\n", &Num1);
	printf("Num1变量的值%d\n", Num1);
	printf("p这个变量的地址%d", &p);
	//3 指针的运算
	printf("p中存储的数据%d\n", p);
	printf("p+1得到的数据%d\n", *p+1);


	char b;
	//p = &b;不能直接赋值，变量取地址之后是有类型的

	char buf[10] = "hello";
	char * p2 = buf;
	printf("数组名的值%d", buf);//输出数组的首地址
	printf("数组名的值%s", buf);//输出BUF数组的字符串
	scanf_s("%s", buf, 10);//这佐证了数组名是一个地址
	                       //值，数组的首地址

//	buf = p2;

	//char  p3; 'A'
	return 0;
}

