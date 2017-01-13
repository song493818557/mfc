// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <crtdbg.h>
#include <stdlib.h>
#include <string.h>

//指针遍历数组
void get_string(){
	char astring[4][10] = { "hello", "15pb", "Change", "Wolrd" };
	char(*p)[10] = astring;
	for (int i = 0; i < 4;i++)
	{
		for (int j = 0; j < 10;j++)
		{
			if (p[i][j] != '\0')
			{
				printf("%c ", p[i][j]);
			}
			
		}
		printf("\n");
	}
}
int max(int a, int b)
{
	return (a > b ? a : b);
}
int min(int a, int b)
{
	return (a < b ? a : b);
}
int sum(int a, int b)
{
	return a + b;
}
//指针遍历数组
int get_number(int a,int b,int (*p)(int a ,int b)){
	
	return (p(a,b));
}
//上级基础3
struct  BOOKINFO{
	char * author;
	char * book_name;
	double book_price;
};
//初始化函数
/*
1 定义一个函数可以初始化这个结构体指针 使其指向多本书  
2 初始化书的个数可以由调用者传入
3 书名,作者名 价格可以在初始化函数中输入得到


*/
bool initBook(BOOKINFO * pBook, unsigned int nCount){
	//BOOKINFO *  TBOOKINFO = pBook;
	char bname[100] ="bbb";
	char bauthor[100] ="aac";
	double  price = 55.0;
	for (int i = 0; i < 5;i++)
	{ 
		//pBook[i]->author = (char *)malloc(20);
		
	//	printf("请输入作者名--书名--价格\n");
	//	scanf_s("%s %s %f", bname, 10, bauthor, 30, &price, 4);
		//scanf_s("%s", pBook->book_name, 30);
		pBook->author = (char *)malloc(strlen(bauthor) + 1);
		strcpy_s(pBook->author, strlen(bauthor) + 1, bauthor);
		pBook->book_name = (char *)malloc(strlen(bname) + 1);
		strcpy_s(pBook->book_name, strlen(bname) + 1, bname);
		pBook->book_price = price+i;
		pBook++;
	}
	return true;
}
//释放资源函数
bool FreeAllRecource(BOOKINFO * pBook, unsigned int nCount){
	//BOOKINFO *  TBOOKINFO = pBook;
	for (int i = 0; i < 5; i++)
	{
		
		//pBook[i] = nullptr;
		free(pBook->author);
		free(pBook->book_name);
		pBook->author = nullptr;
		pBook->book_name = nullptr;
	}
	return true;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//get_string();
	/*printf("max=%d\n", get_number(1, 2, max));
	printf("min=%d\n", get_number(3, 4, min));
	printf("sum=%d\n", get_number(5, 6, sum));*/
	BOOKINFO * nBookinfo = (BOOKINFO *)malloc(sizeof(BOOKINFO) * 20);
	initBook(nBookinfo,10);
	//4 在主函数中将所有图书信息输出
	BOOKINFO * aBookinfo = nBookinfo;
	printf("%s", nBookinfo->book_name);
	for (int i = 0; i < 5; i++)
	{
		printf("作者名:%s--书名:%s--价格:%f\n", aBookinfo->author, aBookinfo->book_name, nBookinfo->book_price);
		aBookinfo++;
	}
	//5 释放掉所有资源
	FreeAllRecource(nBookinfo, 10);
	
	free(nBookinfo);
	nBookinfo = nullptr;
	return 0;
}

