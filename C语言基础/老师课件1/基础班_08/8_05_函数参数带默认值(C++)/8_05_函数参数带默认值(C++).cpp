// 8_05_函数参数带默认值(C++).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int Add(int nNumA)
{
	return nNumA ;
}
int Add(int nNumA, int nNumB = 1)
{
	return nNumA + nNumB;
}
//按从右到左的顺序给默认参数
// int Add(int nNumA = 1, int nNumB , int nNumC = 1)
// {
// 	return nNumA + nNumB;
// }
int main()
{
	//Add(1);   //二义性问题,编译器不知道调用哪一个函数
	Add(1,2);
	return 0;
}

