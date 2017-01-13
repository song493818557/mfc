// 创建线程.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Windows.h"

typedef struct THREADPARAM
{
	int n1 ;
	int n2;
	RECT rt;
}THREADPARAM , *PTHREADPARAM;

// 线程回调函数
DWORD WINAPI ThreadProc(LPVOID lpThreadParameter)
{
	PTHREADPARAM pRt = (PTHREADPARAM)lpThreadParameter;

	COORD pos = { 10, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
		pos
		);

	int n = 0;
	while(true)
	{  
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) ,pos);
		printf("%d" , n);
		++n;
		Sleep(200);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	RECT rt = { 110 , 120 , 119 , 999 };

	DWORD dwTID= 0;
	HANDLE hThread = 0;
	THREADPARAM stc={ 0xAAAA , 0xBBBB , { 110 , 120 , 119 , 999 } };
	hThread = CreateThread(0 ,// 线程安全属性
						   0 , // 栈的大小
						   ThreadProc ,// 线程回调函数
						   &stc ,
						   NULL ,
						   &dwTID
						   );

	// WaitForSingleObject(hThread , -1);
	COORD pos = { 0 , 0 };
	int n = 0;
	while(true)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , pos);
		printf("%d" , n);
		++n;
		Sleep(50);
	}

	return 0;
}

