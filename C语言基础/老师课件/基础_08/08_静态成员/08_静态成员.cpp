// 08_静态成员.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


class CTest
{
public:
	CTest()
	{
		Num++;
	}
	~CTest()
	{
		Num--;
	}
	void fun2()
	{

	}
	static void fun()  //不会传入this指针
	{
		printf("helloworld");
		//b = 10;//在静态函数内，无法访问非静态成员。
		Num = 20;
	}
public:
	static int Num ;
	int b;
};
int CTest::Num = 10;

int _tmain(int argc, _TCHAR* argv[])
{
	CTest objA;
	//CTest objB;
	//CTest objC;
	//CTest objD;
	//CTest objE;
	objA.fun2();    //正确的
	CTest::fun();   //正确的
	//CTest::fun2();//错误的 静态函数与静态成员，不用对象就可以调用，
	                //不依赖于对象，
	                //非静态的成员函数与成员变量，必须得通过对象来使用。
	printf("%d\n", CTest::Num);//我们既可以通过类来访问一个静态成员，
	//也可以通过对象来访问静态成员，但是一般情况，我们是通过类来访问的，
	//因为通过对象访问，容易和普通的成员变量弄混。
	//printf("D:%d\n", objD.Num);

	//printf("D:%d\n", objD.b);
	return 0;
}

