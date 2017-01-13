// 逆向入门-函数调用方式.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// C调用方式

int _cdecl CDCall(int n1, char* p2,int n3)
{
	return n1;
}


// 标准调用方式
int _stdcall StdCall(int n1 , char* p2 , int n3)
{
	return n1;
}

// 快速调用方式
int _fastcall FastCall(int n1 , char* p2 , int n3)
{
	
	return n3;
}

class MyClass
{
public:
	// C++ 类对象成员函数的调用方式
	int ThisCall(int n1 , char* p2 , int n3)
	{
		return  n1 ;
	}
};




// 裸函数
// 定义裸函数的关键字 ：  __declspec(naked)
// 函数的调用方式 ： _stdcall  
// 在裸函数中，必须自己写汇编代码来开辟栈空间
int __declspec(naked) nakedFunction(int n , char* p2 , int n3)
{
	_asm
	{
	push ebp;
	mov ebp,esp
	}

	_asm
	{
		mov eax , n3;
		mov esp , ebp;
		pop ebp;
		_asm ret 3 * 4
	}
}




int _tmain(int argc, _TCHAR* argv[])
{
	int nRet = 0;
	
	// 注意形参传递的顺序
	// 注意平衡堆栈的方式

	// C调用方式
	nRet = CDCall(1 , "123" , 2);


	// 标准调用
	nRet = StdCall(1 , "123" , 2);

	// 快速调用
	nRet = FastCall(1 , "123" , 2);

	MyClass obj;
	// this call
	obj.ThisCall(1 , "123" , 2);


	//nRet = nakedFunction(1 , "123" , 2);
	return 0;
}

