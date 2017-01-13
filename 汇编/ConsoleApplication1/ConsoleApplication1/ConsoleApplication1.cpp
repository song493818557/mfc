// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int data[6] = { 1, 2, 3, 4, 5, 6 };
	int temp = 0;
	_asm{
		/*	push [data];
			push [data+20];
			pop [data];
			pop[data+20];

			push[data +4];
			push[data + 16];
			pop[data+4];
			pop[data + 16];

			push[data + 8];
			push[data + 12];
			pop[data + 8];
			pop[data + 12];*/
		//	mov ax, 10;
		//xchg ax, word Ptr[data];
		//xchg word Ptr[data+20], ax;
		//xchg ax, word Ptr [data];
		// 
		//xchg ax, word Ptr [data + 4];
		//xchg word Ptr [data + 16], ax;
		//xchg ax, word Ptr [data + 4];

		//xchg ax, word Ptr [data + 8];
		//xchg word Ptr [data + 12], ax;
		//xchg ax, word Ptr [data + 8];
		lea eax, [data];
		xchg ebx, [eax];
		xchg[eax + 20], ebx;
		xchg ebx, [eax];

		
	}

	_asm{
			mov eax, [data + 4]
			xor eax, [data + 16]
			xor[data + 4], eax
			xor[data+16],eax 
	}
	return 0;
}

