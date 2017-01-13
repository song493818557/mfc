// 8_08_第一个面向对象的C++程序(cou,cin).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

void testCin()
{
	//正常输入
	int nNumA;
	char ch;
	float fNumB;
	char str[100] = {0};
	cin >> nNumA >>ch>>fNumB >> str;

	cin >> nNumA;
	while (cin.fail()) //检查cin.failbit 是否被设置 true;
	{
		//cin输入错误时,不再继续响应输入,需要特殊处理
		//处理方式一
		//cin.clear(); //	清除错误标记
		//cin.sync();  //   清除缓冲区中的数据
		//cin >> nNumA;

		//处理方式二
		cin.clear();
		char ch;
		cin >> ch;
		cin >> nNumA;
	}

	
	int nNum = 555;
	cin >> nNum;

}

void testCout()
{
	int nNumA = 987;
	char ch = 'w';
	float fNumB = 0.345;
	char str[100] = { "hello" };
	cout << "hello world" << endl;
	cout << nNumA << "\t"
		 << ch    << "  " 
		 << fNumB << "\n"
		 << str 
		 <<endl;

	cout.setf(ios::left);
	nNumA = 10;
	cout << hex << nNumA << "\n";
	cout << oct << nNumA << "\n";
	cout << dec << nNumA << "\n";
	cout << setw(10) << nNumA << endl;
	cout << setw(10) <<left<< nNumA << endl;
	cout << setw(10) <<right<< nNumA << endl;
	cout << setw(10) << setfill('0')<< right << nNumA << endl;

}

void testCout2()
{
	cout << endl;

	for (int i = 0;i<7;i++)
	{
		if (i<4)
		{
			//前四行       0,1,2,3
			//空格越来越少 4,3,2,1
			//星号越来越多 1,3,5,7
			cout << setfill(' ')<<setw(4 - i) << ' ';
			cout << setfill('*')<<setw(2 * i + 1) << '*';
		}
		else {
			//后三行       4,5,6
			//空格越来越少 2,3,4
			//星号越来越多 5,3,1
			/*
			4  5    7-4=3   5
			5  3    7-5=2   3
			6  1    7-6=1   1
			*/
			cout << setfill(' ') << setw(i-2) << ' ';
			cout << setfill('*') << setw( 2*(7-i)-1) << '*';
		}

		cout << endl;
	}

}
int main()
{
	
	//testCin();
	testCout();
	testCout2();
    return 0;
}

