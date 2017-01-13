// 10 友元类.cpp : 定义控制台应用程序的入口点。
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
	int SetScore(int n)
	{
		 Score = n;
	}
	char* Getname()
	{
		return Name;
	}
	friend class Teacher;
private:
	int Score;//分数
	char Name[20]; //姓名
};

class Teacher
{
public:
	void GiveScore(int nNum)
	{
		//m_Student.SetScore(nNum);
		m_Student.Score = nNum;
	}
private:
	CStudent m_Student;
};


int _tmain(int argc, _TCHAR* argv[])
{
	Teacher yanglaoshi;
	yanglaoshi.GiveScore(80);
	return 0;
}

