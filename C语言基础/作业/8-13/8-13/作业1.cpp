// 04_构造的初始化列表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Czfx
{
public:
	Czfx(int a = 0, int b = 0){  this->a = a*b; }
	void print(){ printf("结果是：%d", a); }
	 

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

