// [���ϴ���]SDK_Day006.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <tchar.h>
#include <thread>

using   std::thread;
int _tmain(int argc, _TCHAR* argv[])
{
	__declspec (thread) class aa;
	aa.
	STARTUPINFOW startInfo = { 0 };//����������Ϣ�ṹ��
	startInfo.cb = sizeof(STARTUPINFOW);
	PROCESS_INFORMATION processInfo = { 0 }; // ��������Ľ�����Ϣ

	//HANDLE hTrhea; <== ������ӵ�еľ��

	CreateProcess(_T("C:\\Program Files (x86)\\Tencent\\QQ\\Bin\\QQScLauncher.exe") ,// �����ļ�·��
				  NULL , // �����в���
				  0 , // ���̰�ȫ����
				  0 , //�̰߳�ȫ����
				  FALSE ,//���������ӽ����Ƿ�̳и����̵ľ��
				  0 ,
				  0 ,// ����������
				  0 ,//���̵�ǰĿ¼
				  &startInfo ,
				  &processInfo
				  );

	
	return 0;
}

