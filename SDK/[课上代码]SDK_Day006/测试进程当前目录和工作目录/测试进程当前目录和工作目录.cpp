// ���Խ��̵�ǰĿ¼�͹���Ŀ¼.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	WCHAR currDirectory[ MAX_PATH ];
	SetCurrentDirectory(L"C:\\");
	// ��ȡ���̵ĵ�ǰĿ¼
	GetCurrentDirectory(MAX_PATH , currDirectory);

	MessageBox(NULL , currDirectory , L"���̵�ǰĿ¼" , 0);

	// ���õ�ǰ����Ŀ¼��API:
	
	return 0;
}

