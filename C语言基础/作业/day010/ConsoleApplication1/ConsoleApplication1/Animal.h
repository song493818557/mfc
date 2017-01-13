#pragma once
#include <iostream>
using namespace  std;
class CAnimal
{
public:
	CAnimal();
	~CAnimal();
	virtual void miao(){ cout << "CAnimal...."; }
	int nNuma;
private:
	int nNumb;
};

class CCat :public CAnimal{
public:
	virtual void miao(){ cout << "Cat:miaomiaomiao...."; }
	int nNuma;
private:
	int nNumb;
};

class CLeopard :public CAnimal{
public:
	virtual void miao(){ cout << "CLeopard:aoaoaoao...."; }
	int nNuma;
private:
	int nNumb;
};