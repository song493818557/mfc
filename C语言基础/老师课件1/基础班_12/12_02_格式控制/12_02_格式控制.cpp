// 12_02_��ʽ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	ofstream cfout("context.txt");

	double d1 = 3456.34545;
	double d2 = 56.345;

	//һ����Ա����
	cfout.precision(4);
	cfout << d1 << endl;
	cfout.precision(10);
	cfout << d2 <<endl;

	//������ʽ���Ʒ���ֱ�ӷŵ�<<�Ȳ������ĺ���
	cfout << setprecision(4)<<endl;
	cfout << d2 << endl;
    return 0;
}

