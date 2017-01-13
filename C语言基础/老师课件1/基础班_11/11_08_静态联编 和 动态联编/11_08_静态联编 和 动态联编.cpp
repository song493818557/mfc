// 11_08_静态联编 和 动态联编.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CClassA {
public:
	CClassA() {};
	CClassA(int a) {}
	virtual ~CClassA() {}
	virtual void fun_a() { cout << "fun_a:CClassA" << endl; }
};
class CClassB : public CClassA {
public:
	virtual ~CClassB() {}
	virtual void fun_a() { cout << "fun_a:CClassB" << endl; }
};

int _tmain(int argc, _TCHAR* argv[]) {
	CClassA objA, *pobjA;
	CClassB objB;

	CClassA objC(4); //重载是通过静态联编完成的.
					 //静态联编,函数的调用地址,已经在二进制文件里面写死了.
					 //无参构造函数:E8 CD BF FF FF       call        CClassA::CClassA (0B113EDh) 
					 //有参构造函数:E8 9A BF FF FF       call        CClassA::CClassA (0B113E8h)

	pobjA = &objA;
	pobjA->fun_a();   //动态联编,函数的调用地址,是运行的时候才确定(virtual虚函数) 
	                  //FF D0                call        eax 
	pobjA = &objB;   
	pobjA->fun_a();   //动态联编,函数的调用地址,是运行的时候才确定(virtual虚函数)
					  
	
	pobjA = new CClassB; // 只有父类析构函数定义为虚函数时，
	delete pobjA;		 // 释放父类指针，才能够调用到子类的析构函数，
					     // 从而正常释放子类中的资源，
					     // 并且子类析构调用完会调用父类析构，达到正常释放
					     
					     //如果父类析构函数不定义为虚函数
					     // 则释放父类指针时，直接调用父类析构函数就结束了
					     // 从而子类中的资源得不到释放
	return 0;
}


