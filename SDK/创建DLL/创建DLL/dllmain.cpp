// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#include "stdafx.h"
//DLL����ں��� ����_tMain _winMain
/*
��˽����
����ͷ�ļ�
����LIB�ļ�
ֱ�ӵ��ú���

�Ѱ������е�DLL ��Ԥ�������ڴ� �ٽ�������������

��ʽ����
��ʾ������Ҫ��������
1 LoadLibrary  ��DLL�ļ�������̿ռ� �����ؾ��
2 GetProcAddress ��ȡ�����ĵ�ַ  1���  ������ �õ�������ַ ͨ������ָ����ú���
3 FreeLibrary  �ͷ�DLL
*/
extern "C" //PE������ȫһ�� ���֧��C���ԵĻ� �ͱ������ extern "C"    ����extern C�� �� ����C++Ĭ�ϵĺ����������
_declspec(dllexport)
int fun(){ 
	MessageBox(0, L"AA", L"DLL", 0);
	return 1;
}
BOOL APIENTRY DllMain( HMODULE hModule, //DLL�����ص����ڴ��ַ   ģ���� ģ����ػ�ַ
                       DWORD  ul_reason_for_call,//DLLMAIN�����õ�ԭ��
                       LPVOID lpReserved  
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH: //���̴���ʱ������
		MessageBox(0, L"DLL_PROCESS_ATTACH", L"DLLMAIN", 0); break;
	case DLL_THREAD_ATTACH:	 //�̴߳���ʱ ������
		MessageBox(0, L"DLL_THREAD_ATTACH", L"DLLMAIN", 0); break;
	case DLL_THREAD_DETACH:	//�߳�����ʱ������
		MessageBox(0, L"DLL_THREAD_DETACH", L"DLLMAIN", 0); break;
	case DLL_PROCESS_DETACH:	//��������ʱ ������:
		MessageBox(0, L"DLL_PROCESS_DETACH", L"DLLMAIN", 0); break;
		break;
	}
	return TRUE;
}

