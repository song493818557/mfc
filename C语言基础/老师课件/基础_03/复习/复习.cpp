// 复习.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//1 数组
	//1.1数组的定义 
	//类型（int short char double ...） 数组名[数组长度]
	//注意：数组长度必须是常量
	//1.2数组的初始化
	int Array[5] = {2,1,5};
	/*printf("%d\n", Array[0]);
	printf("%d\n", Array[1]);
	printf("%d\n", Array[2]);
	printf("%d\n", Array[3]);
	printf("%d\n", Array[4]);*/
	//1.3 数组元素的使用
	//注意：下标即可是常量也可以是变量
	//
	int a = 2;
	printf("%d", Array[a]);
	//2 选择结构
	if ()//括号里的内容为真的话，就执行语句序列1，否则执行语句序列2
	{
		//语句序列1
	}
	else
	{
		//语句序列2
	}
	switch (switch_on)//会计算括号里的内容，和每一个case做比较，符合哪一个，就执行
		              //哪一个后面的语句。
	{
	case 1: //假如符合这一个case，就执行其后面的语句，若没有遇到break就执行下一个
		    //case
	case 2:

	default:
		break;
	}

	return 0;
}

