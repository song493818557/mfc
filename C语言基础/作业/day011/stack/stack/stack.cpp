// stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "Cstack.h"//栈
#include "Cstring.h"//从键盘输入一个字符串 
using namespace mystring;
int _tmain(int argc, _TCHAR* argv[])
{
	//stack
	//Cstack stack;
	//stack.push(1);
	//stack.push(2);
	//stack.push(3);
	//stack.push(4);
	//stack.push(5);
	//stack.pop(5);
	//stack.push(5);
	//stack.push(6);
	//stack.push(7);
	//stack.pop(5);

	/*mystring::Cstring aa;
	aa.input();
	aa.copy("bb3.txt", "bb.txt");*/
	mystring::Castring numb;
	numb.insert(2);
	numb.insert(3);
	numb.insert(90);
	numb.insert(5);
	numb.insert(6);
	numb.insert(4);
	numb.insert(8); 
	numb.adelete(90);
	numb.ashort(2);
	numb.ashort(1);
	return 0;
}

