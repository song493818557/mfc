// �޸Ľ�����ں���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

// �޸���ں���
// '/entry: ' : ���������Ĳ���,��ʾҪ�޸���ں���
// `\"NewEntry\"` : �µ���ں���������
//#pragma comment(linker, "/entry:\"NewEntry\"")

int NewEntry2()
{
	MessageBox(0 , _T("NewEntry2") , _T("��ʾ") , 0);

	return 0;
}

int NewEntry()
{
	MessageBox(0 , _T("NewEntry") , _T("��ʾ") , 0);
	
	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
	MessageBox(0 , _T("_tmain") , _T("��ʾ") , 0);
	return 0;
}

