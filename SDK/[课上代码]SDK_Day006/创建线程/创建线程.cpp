// �����߳�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Windows.h"

typedef struct THREADPARAM
{
	int n1 ;
	int n2;
	RECT rt;
}THREADPARAM , *PTHREADPARAM;

// �̻߳ص�����
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
	hThread = CreateThread(0 ,// �̰߳�ȫ����
						   0 , // ջ�Ĵ�С
						   ThreadProc ,// �̻߳ص�����
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

