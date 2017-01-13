// 12_09_命名空间.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "标头.h"

namespace Outer                //定义命名空间
{
	int nNumA = 10;             
	int fun_a() { nNumA++; }   //函数声明在内部,实现也在内部
	int fun_b();               //函数声明在内部,实现在外部
	class CLASS                //类
	{
	public:
		int fun_c();
		int fun_d() {}
	};      
	namespace Inner
	{
		int nNumA = 999;
		int fun_a() { nNumA++; } //函数声明在内部,实现也在内部
		int fun_aa();            //函数声明在内部,实现在外部
	}

}
int Outer::fun_b()
{

}
int Outer::CLASS::fun_c()
{

}
int Outer::Inner::fun_aa()
{}

using namespace std;//不推荐使用
using std::cout;    //推荐这样使用
using std::cin;
using std::endl;

int main()
{
	//一.不能直接访问
	//nNumA;

	//二.通过名字单独访问(不方便)
	Outer::nNumA;
	Outer::Inner::nNumA;

	//三.通过声明名字,来访问(推荐使用这种方式)
	using Outer::nNumA;
	using Outer::fun_a;
	nNumA;
	fun_a(); 

	//四.通过声明命名空间来访问
	namespace hehe = Outer;
	using namespace hehe;      //声明命名空间的别名
	//using namespace Outer;
	using namespace Inner;
	fun_b();
	fun_aa();
	fun111111();               //来之不同的文件,同一个命名空间

	
	

    return 0;
}

