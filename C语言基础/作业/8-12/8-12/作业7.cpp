// 8-12.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "sources.h"
using std::endl;
using std::cin;
using std::cout;
int _tmain(int argc, _TCHAR* argv[])
{

	_man *aa  = new _man[10];
	for (int i = 0; i < 4;i++)
	{
		cin >> aa[i].name >> aa[i].age >> aa[i].height >> aa[i].weight;
	}
	for (int i = 0; i < 4; i++)
	{
		aa[i].get_Health();
		cout << "����" << aa[i].name << "����" << aa[i].age << "���" << aa[i].height << "����" << aa[i].weight << "����ָ��" << std::dec<< aa[i].Health << endl;
	}
	//int &n = aa.chang;
	
	//���ûʲô����
	return 0;
}

