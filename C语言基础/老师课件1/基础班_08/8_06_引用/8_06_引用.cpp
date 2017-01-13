// 8_06_引用.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//值传递
void swap(int nNuma, int nNumb)
{
	int temp = nNumb;
	nNumb = nNuma;
	nNuma = temp;
}

//指针传递
void swap(int * nNuma, int * nNumb)
{
	//交换指针,没有用,仍然不能改变实参
// 	int * temp = nNumb;
// 	nNumb = nNuma;
// 	nNuma = temp;
	int temp = *nNumb;
	*nNumb = *nNuma;
	*nNuma = temp;
}

//引用传递
void swap1(int &nNuma, int &nNumb)
{
	int temp = nNumb;
	nNumb = nNuma;
	nNuma = temp;
}
int main()
{
	//普通引用
	char ch = 'a';
	int nNumA = 100;
	int & nNum1 = nNumA;  //类型一致
	nNum1--;
	nNum1 = 987;

	//const + 引用
	const int & nNum2 = nNumA;  //const类型的引用能够指向普通类型
	const float & nNum3 = nNumA;  //const类型的引用能够指向普通类型
	const int nNumB = 678;
	//int & nNum3 = nNumB;      //普通类型的引用不能够指向cosnt类型
	//nNum2++;                  //const类型的引用不能修改变量(保护变量)
	
	nNumA++;
	printf("%f , %d , %d ", nNum3, nNum2, nNumA);


	//引用传参
	int a = 100;
	int b = 1;
	swap(a, b);    //值传递
	swap(&a, &b);  //指针传递
	swap1(a, b);   //引用传递
	return 0;
}

