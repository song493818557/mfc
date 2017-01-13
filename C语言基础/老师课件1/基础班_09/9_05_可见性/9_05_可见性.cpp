// 9_05_可见性.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int MyClass1;


class MyClass1
{
public:
	int m_data;
	void print() {
		//2.类隐藏了别人
		printf("%d", ::MyClass1);  //全局变量被隐藏了,通过::来访问
								   //作用域符号::,会到本作用域外部去寻找符号
	}
};

//1.类被隐藏了
void fun(int MyClass1)
{
	MyClass1 = 10;
	class MyClass1 obj;  //类名被隐藏了,添加class 前缀来使用类
	obj.m_data = 10;
}


int main()
{
    return 0;
}

