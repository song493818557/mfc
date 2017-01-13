// 8_07_类型转换.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	//1.const_cast:去掉常量属性(只能用于指针和引用)
	const int nNumA = 100; //强制从内存中取值volatile
	int * nNumB = const_cast<int *>(&nNumA);
	int & nNumC = const_cast<int &>(nNumA);
	//nNumA = 123;
	*nNumB = 777;
	nNumC = 567;

	printf("%d %d %d", nNumA, *nNumB, nNumC);
	
	//2.static_cast:静态类型转换(自动转换,默认转换)
	//  提示两边类型不同
	int nNumD = 999;
	char ch = 'w';
	nNumD = ch;			 //默认转换
	nNumD = static_cast<int> (ch);

	//3.reinterpret_cast:强制转换(不能自动转换时)
	int nNumE = 233;
	int * pNumF = nullptr;
	//nNumE = pNumF;
	nNumE = (int)pNumF;
	nNumE = reinterpret_cast<int>(pNumF);
	pNumF = reinterpret_cast<int *>(nNumE);

    return 0;
}

