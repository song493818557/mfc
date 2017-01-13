// 8-12.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "sources.h"
using std::endl;
using std::cin;
using std::cout;
int _tmain(int argc, _TCHAR* argv[])
{

	//_man *aa  = new _man[10];
	_count_Machine surpercount;
	//输出当前结果
	
	for (int temp = 1; 1;)
	{
		system("cls");
		//printf("请输入表达式可以是+ - * / %\n");
		printf("1 = 使用当前表达式计算 2= 删除表达式 3 = 修改表达式1-5 \n");
		surpercount.outputresult();
		temp = surpercount.user_input();
		switch (temp)
		{
		case 1:
			//等待用户输入
			printf("请输入例如:44 55可以得出当前表达式的结果 %\n");
			surpercount.input_number(); break;
			
		case 2:
			//删除表达式
			//printf("请输入表达式可以是+ - * / %\n");
			surpercount.delete_expression(); break;
		case 3:
			//修改表达式
			printf("请输入表达式可以是+ - * / % \n");
			surpercount.expression(); break;
		default:
			break;
		}
		//输入表达式运算符
		
		


	}
	
	
	//surpercount.call();
	//int &n = aa.chang;
	
	//结果没什么区别
	return 0;
}

