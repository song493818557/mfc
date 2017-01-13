#pragma once
#include "stdafx.h"
#include <string>
using namespace std;
class CStudent
{
	 string name;
public:
	//CStudent( string& n = "noname") :name(n){}
	~CStudent();
};
class CTeacher
{
	string name;
public:
	//CTeacher(string& n = "noname") :name(n){}
	~CTeacher();
};
class Cmyclass{
	int number;
public:	
	Cmyclass();
	Cmyclass(int);
	~Cmyclass();
	void Display();
};
