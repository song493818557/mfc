// 12_03_�ļ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	//�ļ����
	ofstream cfout("c:\\context.txt");    //����·��,c����Ҫ����ԱȨ��//����,����,�嵥�ļ�
	//ofstream cfout("context.txt",ios::app); //���·��

	cfout << "������������ \n"
		<< 123434 << endl;


	//�ļ�����
	ifstream cfin("c:\\context.txt");
	while (!cfin.eof())
	{
		char str[1024] = { 0 };
		cfin >> str;
		cout << str << endl;
	}
	

    return 0;
}

