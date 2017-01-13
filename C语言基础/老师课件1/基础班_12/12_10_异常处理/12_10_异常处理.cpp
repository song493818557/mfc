// 12_10_异常处理.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <exception>
#include <iostream>
//using namespace std;
using std::cout;
using std::endl;

int divide(int nNuma, int nNumb)
{
	if (nNumb==0)
	{
		//__LINE__ 行号
		//__FILE__ 文件名

		//抛出异常
		//throw 'a';    //不能做隐式转换,不能被catch(int)捕获
		//throw 999;
		//throw "除数为零";
	}
	return nNuma / nNumb; //系统与错也会throw
}

int main()
{
	try
	{
		//可能会出错的代码,放在try块里面
		int a = divide(199, 0);
	}
	//匹配的时候,不作类型转换
	catch (const std::exception& e)
	{
		//捕获类类型,最好使用引用
		cout << e.what();
	}
	catch (int e)     
	{
		cout << e << endl;
	}
	catch (const char * e)
	{
		cout << e << endl;
		//1.释放一些资源

		//2.写错误日志
		
	}
	catch (...)//不定参数(不定个数,不定类型)
	{ 
		cout << "未定异常"<<endl;
	}

    return 0;
}

