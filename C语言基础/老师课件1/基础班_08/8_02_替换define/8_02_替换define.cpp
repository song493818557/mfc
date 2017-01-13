// 8_02_替换define.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//define的使用
//1.无参宏
//#define WIDTH 10
//#define HITH  10
//#define WIDTH_HITH WIDTH+HITH
//const来替换
const int WIDTH = 10;
const int HITH = 10;
const int WIDTH_HITH = WIDTH + HITH;
//enum来替换
enum DIRECTION
{
	up = 0,
	down,
	left,
	right
};

//2.有参宏
#define MAX(a,b) (a)>(b)?(a):(b); 
//inline(内联函数)
inline int max(int a,int b)//1.项目属性设置,"项目属性"->"C++"->"内联函数扩展"
{                          //2.内联函数,内部语句必须简单
	                       //3.是否调用频繁
	return (a)>(b) ? (a) : (b);
}
int main()
{
	//无参数宏
	//求周长
	int rect = 2 * WIDTH_HITH;

	DIRECTION dir = left;
	switch (dir)
	{
	case up:
		break;
	case down:
		break;
	case left:
		break;
	case right:
		break;
	default:
		break;
	}

	//有参宏
	int nNum = MAX(48, 40+50);
	int nNumA = 15;
	int nNumB = 5;
	//int nResult1 = MAX(++nNumA, nNumB);   //被加两次,不符合预期
	//int nResult2 = MAX(++nNumA, nNumB+20);

	int nResult1 = max(++nNumA, nNumB);
	int nResult2 = max(++nNumA, nNumB + 20);

    return 0; 
}

