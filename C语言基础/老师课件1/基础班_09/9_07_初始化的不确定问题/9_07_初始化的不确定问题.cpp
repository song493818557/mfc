// 9_07_��ʼ���Ĳ�ȷ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class CDesk  // ����һ���칫����
{ 
public: 
	int weight;  
	int high;  
	int width;  
	int length;
};
class CStool // ����һ��������
{ 
public: 
	int weight;  
	int high;  
	int width;  
	int length;
};

CDesk g_objDesk;  // ȫ�ֶ���

void fun() {
	static CStool objStool; // �ֲ���̬����
	CDesk objDesk;          // �ֲ�����
}
int _tmain(int argc, _TCHAR* argv[])
{
	CStool objS;             // �ֲ�����
	CDesk *pobj = new CDesk; // �Ѷ���
	CDesk  obj[50];          // �ֲ���������
	delete pobj;
	fun();
	return 0;
}


