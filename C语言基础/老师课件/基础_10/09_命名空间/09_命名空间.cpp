// 09_�����ռ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Test.h"
#include "Hehe.h"
#include <iostream>
using std::cout;//ʹ�������ռ��е�ĳһ������
using Test::Inner::fun;

using namespace Hehe;
//ʹ����Hehe�����ռ��ڵ��������ƣ��ͺ�û�������ռ���
int _tmain(int argc, _TCHAR* argv[])
{
	//cout << 1;
	printf("%d", g_num);
	printf("%d", Hehe::g_num);//��ʹ�õ�ʱ����������ռ������
	fun();
	return 0;
}

