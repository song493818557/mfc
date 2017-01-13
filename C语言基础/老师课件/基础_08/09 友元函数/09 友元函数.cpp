// 09 友元函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
class CStudent
{
public:
	CStudent()
	{
		Score = 100;
		strcpy_s(Name, 20, "xiaoming");
	}
	int GetScore()
	{
		return Score;
	}
	char* Getname()
	{
		return Name;
	}
	friend void printStudentInfo2(CStudent obj);
private:
	int Score;//分数
	char Name[20]; //姓名
};

void printStudentInfo1(CStudent obj)
{
	printf("分数%d，姓名%d", obj.GetScore(), obj.Getname());
}

void printStudentInfo2(CStudent obj)
{
	printf("分数%d，姓名%s", obj.Score, obj.Name);
}


int _tmain(int argc, _TCHAR* argv[])
{
	CStudent obj;
	while (true)
	{
		printStudentInfo2(obj);
	}
	return 0;
}

