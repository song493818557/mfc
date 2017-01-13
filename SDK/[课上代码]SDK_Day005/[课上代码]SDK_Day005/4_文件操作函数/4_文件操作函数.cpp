// 4_文件操作函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	// CopyFile(L"stdafx.cpp" , L"123.cpp" , 0);

	// DeleteFile(L"G:\\work\\T\\SDK\\课上示例\\[课上代码]SDK_Day005\\4_文件操作函数\\123.cpp");
	// MoveFile(L"123.cpp" , L"../../459.cpp");
	HANDLE hFile = 0;
	hFile = CreateFile(L"456.txt" ,
					   GENERIC_READ|GENERIC_WRITE , // 文件操作权限(可以对创建出来的文件进行什么操作,类似fopen"r","w")
					   FILE_SHARE_READ ,// 文件共享权限
					   0 ,
					   OPEN_EXISTING , // 文件打开标志
					   FILE_ATTRIBUTE_NORMAL ,// 文件属性(一般使用正常的文件)
					   NULL
					   );
	if(hFile == INVALID_HANDLE_VALUE)
	{
		printf("创建文件失败\n");
		return 0;
	}

	DWORD dwFileSize = GetFileSize(hFile , NULL);

	LPBYTE pFileData = new BYTE[ dwFileSize ];
	DWORD  dwRead = 0;
	ReadFile(hFile , // 文件句柄
			 pFileData , // 保存文件内容的缓冲区
			 dwFileSize ,// 要读取的字节数
			 &dwRead , // 函数实际读取到的字节数
			 NULL
			 );

	

	

	// 将文件读写位置定位到文件开始的第10个字符
	SetFilePointer(hFile ,10,0,FILE_BEGIN); // 类似fseek()


	DWORD dwWrite = 0;
	WriteFile(hFile ,  // 文件句柄
			  "-----" , // 写入内容
			  5 ,  // 写入内容的字节数
			  &dwWrite , // 函数实际写入到文件中的字节数
			  0);
	if(dwWrite < 10)
	{
		printf("写入失败\n");
	}

	// 将文件读写位置定位到文件结束前的第10个字符
	SetFilePointer(hFile , 10 , 0 , FILE_END); // 类似fseek()

	printf("%s" , pFileData);
	delete[] pFileData;
	CloseHandle(hFile); // 关闭文件句柄

	return 0;
}

