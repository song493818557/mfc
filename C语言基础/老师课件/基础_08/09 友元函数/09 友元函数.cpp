// 09 ��Ԫ����.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int Score;//����
	char Name[20]; //����
};

void printStudentInfo1(CStudent obj)
{
	printf("����%d������%d", obj.GetScore(), obj.Getname());
}

void printStudentInfo2(CStudent obj)
{
	printf("����%d������%s", obj.Score, obj.Name);
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

