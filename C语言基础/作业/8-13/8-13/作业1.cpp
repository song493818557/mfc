// 04_����ĳ�ʼ���б�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class Czfx
{
public:
	Czfx(int a = 0, int b = 0){  this->a = a*b; }
	void print(){ printf("����ǣ�%d", a); }
	 

private:
	int a;
	int b;
};
 
int _tmain(int argc, _TCHAR* argv[])
{
	Czfx a(8,8);
	a.print();
	return 0;
}

