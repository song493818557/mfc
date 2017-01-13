// 9_11_拷贝构造.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CLocation {
public:
	CLocation(CLocation& obj) // 拷贝构造
		:m_X(obj.m_X), m_Y(obj.m_Y) {
		cout << "Copy initialization\n";
	}
	CLocation(int nX, int nY) // 普通带参构造
		:m_X(nX), m_Y(nY)
	{}
private:
	int m_X, m_Y;
};
CLocation  fun_A(CLocation  obj) { return obj; }
CLocation& fun_B(CLocation& obj) { return obj; }

int _tmain(int argc, _TCHAR* argv[]) {
	CLocation objA(3, 4);
	CLocation objB(objA);          //1.定义一个对象,并用另一个对象来初始化它
	fun_A(objB);                   //2.当一个函数的形参是类对象,实参也是类对象 时会调用拷贝够构造
								   //3.当一个函数的返回值是类对象,return后面给的也是类对象 时 ,会调用拷贝构造

	CLocation& objD = fun_B(objB);//注意：引用传参不调用拷贝构造，引用返回值也不调用拷贝构造

	CLocation objB = objA;  //用同类型的变量初始化对象,会调用拷贝够着
	CLocation objC(objA);   //同上

	objC = objB;            //赋值:调用 重载= 的函数

	return 0;
}


