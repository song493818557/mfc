// 10 ��Ԫ��.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int Score;//����
	char Name[20]; //����
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

