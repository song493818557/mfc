// ʹ��DLL.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

//extern"C" ��ֹC++�����Ʒ������
extern"C" int fun(); // ��������
typedef int(*fnFun)(); // ���庯��ָ������


int _tmain(int argc, _TCHAR* argv[])
{
	// 1. ��ʽ����
	//1.1 ����DLL
	// hDll : DLL�ļ��ػ�ַ
	HMODULE hDll = LoadLibrary(L"����DLL.dll");

	fnFun pfnFun = nullptr ; // ����ָ�����͵ı���
	// 1.2 ��ȡDLL�еĺ����ĵ�ַ
	pfnFun = (fnFun)GetProcAddress(hDll , "fun");
	// 1.3 ���ú���
	pfnFun();

	//1.4 �ͷ�DLL
	FreeLibrary(hDll);

	return 0;
}

