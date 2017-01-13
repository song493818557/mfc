// 11_09_使用纯虚函数，面向接口编程.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Animal.h"
#include "Tiger.h"
#include "Monkey.h"


int main()
{
	//面向接口编程(逻辑关系都是基于接口)
	CAnimal * animal[10];


	for (int i = 0; i < 5; i++)
	{
		animal[i] = new CTiger; //替换掉这个类，主体代码不需要修改
	}
	for (int i = 5; i < 10; i++)
	{
		animal[i] = new CMonkey; //增加这个类，主体代码不需要修改
	}


	//主体代码都是基于接口关联起来的
	for (int i = 0; i < 10; i++)
	{
		animal[i]->eat();   //通过父类指针来使用子类对象
							//通过接口来调用具体的函数实现
	}
	return 0;
}


