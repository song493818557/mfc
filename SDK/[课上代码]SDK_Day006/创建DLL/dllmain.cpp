// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#include "stdafx.h"

// DLL����ں���


_declspec(dllexport)  int cppFun()
{
	return 0;
}

_declspec(dllexport)  int cppFun(int nNum)
{
	return nNum;
}

_declspec(dllexport)  int cppFun(int nNum ,char ch)
{
	return nNum;
}


int fun2()
{
	return 0;
}

extern"C"   // ��C���Եķ�ʽ����һ������
_declspec(dllexport)  // ��������һ�������ᱻ����
int fun()
{
	fun2();
	return MessageBox(0 , L"Hello" , 0 , 0);
}


// ģ���� , ģ����ػ�ַ 
BOOL APIENTRY DllMain( HMODULE hModule, // DLL�����ص����ڴ��ַ
                       DWORD  ul_reason_for_call,//DllMain�����õ�ԭ��
                       LPVOID lpReserved
					 )
{
	switch(ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH: // ���̴���ʱ������
			MessageBox(0 , L"���̴���ʱ������" , L"DllMain" , 0);
			break;
		case DLL_THREAD_ATTACH:  // �̴߳���ʱ������
			MessageBox(0 , L"�̴߳���ʱ������" , L"DllMain" , 0);
			break;
		case DLL_THREAD_DETACH:  // �߳��˳�ʱ������
			MessageBox(0 , L"�߳��˳�ʱ������" , L"DllMain" , 0);
			break;
		case DLL_PROCESS_DETACH: // �����˳�ʱ������
			MessageBox(0 , L"�����˳�ʱ������" , L"DllMain" , 0);
			break;
	}
	return TRUE;
}

