// 13_01_顺序线性表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyArray.h"
#include <iostream>
#include "MyArray_T.h"
using std::cout;
using std::endl;
using namespace CMyArray_T_Space;
using namespace CMyArray_Space;

int main()
{
	//----------------系统自带数组-------------
// 	int arr[10] = {0};
// 	int param;
// 	for ()
// 	{
// 
// 	}
	//----------------自定义数组类-------------
#pragma region 自定义数组类


	CMyArray my_arr;
	//插入数据
	my_arr.InsertArray(1);
	my_arr.InsertArray(2);
	my_arr.InsertArray(3);
	my_arr.InsertArray(4);

	my_arr.InsertArray(99, 2);

	for (int i = 0;i<100;i++)
	{
		my_arr.InsertArray(i * 10);
	}
	//删除数据
	int nRe = 0;
	my_arr.DeleteArray(nRe);
	my_arr.DeleteArray(nRe, 3);

	cout << my_arr[2];

#pragma endregion
	//----------------自定义数组类模板-------------
#pragma region 自定义数组类模板

	CMyArray_T<double> my_arr_t;
	//插入数据
	my_arr_t.InsertArray(1.6);
	my_arr_t.InsertArray(2.6);
	my_arr_t.InsertArray(3.6);
	my_arr_t.InsertArray(4.6);

	my_arr_t.InsertArray(99.89, 2);

	for (int i = 0; i < 100; i++)
	{
		my_arr_t.InsertArray(i * 0.1);
	}
	//删除数据
	double dRe;
	my_arr_t.DeleteArray(dRe);
	my_arr_t.DeleteArray(dRe, 3);

	cout << my_arr_t[2];

#pragma endregion
    return 0;
}

