// 4_�ļ���������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	// CopyFile(L"stdafx.cpp" , L"123.cpp" , 0);

	// DeleteFile(L"G:\\work\\T\\SDK\\����ʾ��\\[���ϴ���]SDK_Day005\\4_�ļ���������\\123.cpp");
	// MoveFile(L"123.cpp" , L"../../459.cpp");
	HANDLE hFile = 0;
	hFile = CreateFile(L"456.txt" ,
					   GENERIC_READ|GENERIC_WRITE , // �ļ�����Ȩ��(���ԶԴ����������ļ�����ʲô����,����fopen"r","w")
					   FILE_SHARE_READ ,// �ļ�����Ȩ��
					   0 ,
					   OPEN_EXISTING , // �ļ��򿪱�־
					   FILE_ATTRIBUTE_NORMAL ,// �ļ�����(һ��ʹ���������ļ�)
					   NULL
					   );
	if(hFile == INVALID_HANDLE_VALUE)
	{
		printf("�����ļ�ʧ��\n");
		return 0;
	}

	DWORD dwFileSize = GetFileSize(hFile , NULL);

	LPBYTE pFileData = new BYTE[ dwFileSize ];
	DWORD  dwRead = 0;
	ReadFile(hFile , // �ļ����
			 pFileData , // �����ļ����ݵĻ�����
			 dwFileSize ,// Ҫ��ȡ���ֽ���
			 &dwRead , // ����ʵ�ʶ�ȡ�����ֽ���
			 NULL
			 );

	

	

	// ���ļ���дλ�ö�λ���ļ���ʼ�ĵ�10���ַ�
	SetFilePointer(hFile ,10,0,FILE_BEGIN); // ����fseek()


	DWORD dwWrite = 0;
	WriteFile(hFile ,  // �ļ����
			  "-----" , // д������
			  5 ,  // д�����ݵ��ֽ���
			  &dwWrite , // ����ʵ��д�뵽�ļ��е��ֽ���
			  0);
	if(dwWrite < 10)
	{
		printf("д��ʧ��\n");
	}

	// ���ļ���дλ�ö�λ���ļ�����ǰ�ĵ�10���ַ�
	SetFilePointer(hFile , 10 , 0 , FILE_END); // ����fseek()

	printf("%s" , pFileData);
	delete[] pFileData;
	CloseHandle(hFile); // �ر��ļ����

	return 0;
}

