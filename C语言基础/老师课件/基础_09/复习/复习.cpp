// 复习.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class CTest{
public:
	CTest() //构造函数，与类名相同，在对象创建时自动调用
		    //1 函数外定义全局对象
			//2 函数内定义的局部对象
			//3 用new运算符申请在堆上的对象时，会自动调用
	{

	}
	~CTest() //析构函数，类名前加上~符号，在对象销毁的时候自动调用
		     //1 在程序退出之前，销毁全局对象
			 //2 在函数退出之前，销毁局部对象
			 //3 使用delete释放资源的时候，会销毁堆上的对象
	{

	}
	CTest(CTest& Other)//拷贝构造函数，当一个对象初始化另外一个对象的时候，
		               //会被调用
					   //1  CTest  ObjB(ObjA);
					   //2  当函数传参，参数是类对象的时候
					   //3  当函数的返回值是类对象的时候，返回前，会调用
	{
	}
	static int fun()//类似于一个归属类的全局普通函数
		            //调用它是不会传递this指针。
					//所以在函数内，不能直接使用非静态的数据成员
	{
		//有很多代码
		//m_b = 100;错误的，静态函数内不能使用非静态数据成员。
	}
	friend void fun();
private:
	static int a;// 1静态成员为类所有，被所有对象所共享。
	             //类似于作用域在类内的全局变量。
	int m_b;
};
int CTest::a;    //静态数据成员的初始化时在类外的。

void fun()
{

	//m_b = 100;//访问私有成员，是访问某一个对象的私有成员。
	CTest obj;
	obj.m_b = 100;//正确的
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

