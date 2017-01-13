// 6_00_简单复习.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>

#include <stdlib.h>

int main()
{
	/*
	1.指针
	2.结构体
	3.联合体
	4.枚举以及typedef
	5.堆空间
	*/
	//1.指针
	//含义 : 一个变量,用来存储地址
	//定义 : 类型 * 变量名;
	int * ptr = nullptr;
	//赋值 : 
	int num = 999;
	ptr = &num;
	//使用场景: 函数传参,操作内存,操作数组
	*ptr = 777;
	printf("%d %d ", num, *ptr);

	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	ptr = arr;
	//arr[5]    <->  ptr[5];	
	//*(arr + 5)<-> *(ptr + 5);
	
	//2.结构体
	struct CLASSROOM
	{
		char * TeacherName2;
		char ClassName[100];
		char TeacherName[100];
		int  StudentCount;
	};
	CLASSROOM classRoom1 ;
	CLASSROOM classRoom2 = {0};
	CLASSROOM classRoom3 = { "基础班01","杨老师",19 };

	strcpy_s(classRoom1.ClassName,100,"13期");
	strcpy_s(classRoom1.TeacherName, 100, "赵老师");
	classRoom1.StudentCount = 35;

	classRoom2 = classRoom3; //注意,堆空间的拷贝,只是地址的拷贝(悬空指针问题,浅拷贝)

	//3.联合体
	union NAME
	{
		char ChineseName[20];
		char EnglishName[100];
	};
	NAME yangName1;
	NAME yangName2 = {0};
	strcpy_s(yangName1.ChineseName, 20, "杨海军");
	strcpy_s(yangName1.EnglishName, 100, "haijunyang_SDFGHRTYUFERTYUXCVNDFGHJGHJFGHJFGHJFGHJ");
	printf("%s \n", yangName1.ChineseName);
	printf("%s \n", yangName1.EnglishName);


	//4.枚举以及typedef
	enum DIRECTION
	{
		UP  = 0,
		DOWN,
		LEFT,
		RIGHT
	};
	//枚举变量,可以限制此变量中存储的值,从而减少程序出错的概率
	DIRECTION direction = LEFT;
	switch (direction)
	{
	case UP:
		printf("向上移动 \n");
		break;
	case DOWN:
		printf("向下移动 \n");
		break;
	case LEFT:
		printf("向左移动 \n");
		break;
	case RIGHT:
		printf("向右移动 \n");
		break;
	default:
		break;
	}

	//5.堆空间
	int * pArr = (int *)malloc(sizeof(int)*10);
	if (pArr==nullptr)
	{
		printf("申请内存失败 \n");
		return 0;
	}
	memset(pArr, 0, sizeof(int) * 10);
	memcpy(pArr, arr, sizeof(int) * 10);
	for (int i = 0;i<10;i++)
	{
		printf("%d ", pArr[i]);
	}
	free(pArr);

    return 0;
}

