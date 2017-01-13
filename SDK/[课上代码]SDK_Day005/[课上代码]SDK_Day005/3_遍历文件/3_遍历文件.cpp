// 3_遍历文件.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <locale.h>
#include <wchar.h>
#include <psapi.h>

// BOOL GetFileAttribute(LPWSTR lpPath , FILE_INFO &stcFileInfo) {
// 	// 1. 文件路径
// 	wcscpy(stcFileInfo.szFilePath , lpPath);
// 	
// 	// 2. 获取时间信息
// 	WIN32_FILE_ATTRIBUTE_DATA wfad;
// 	GetFileAttributesEx(lpPath , GetFileExInfoStandard , &wfad);
// 	// 2.1 获取创建时间
// 	FILETIME ftLocal;
// 	FileTimeToLocalFileTime(&wfad.ftCreationTime , &ftLocal);   // 调整为系统所在时区的时间
// 	FileTimeToSystemTime(&ftLocal , &stcFileInfo.stcCreatTime); // 转换为SYSTEMTIME格式
// 
// 	// 2.2 获取最后访问时间
// 	FileTimeToLocalFileTime(&wfad.ftLastAccessTime , &ftLocal); // 调整为系统所在时区的时间
// 	FileTimeToSystemTime(&ftLocal , &stcFileInfo.stcCreatTime); // 转换为SYSTEMTIME格式
// 	// 2.3 获取最后修改时间
// 	FileTimeToLocalFileTime(&wfad.ftLastWriteTime , &ftLocal);  // 调整为系统所在时区的时间
// 	FileTimeToSystemTime(&ftLocal , &stcFileInfo.stcCreatTime); // 转换为SYSTEMTIME格式
// 	// 3. 获取文件大小
// 	stcFileInfo.qwFileSize = wfad.nFileSizeHigh;
// 	stcFileInfo.qwFileSize <<= sizeof(DWORD) * 8;
// 	stcFileInfo.qwFileSize += wfad.nFileSizeLow;
// 
// 
// 	// 4. 文件属性
// 	stcFileInfo.dwAttribute = wfad.dwFileAttributes;
// 	if(stcFileInfo.dwAttribute&FILE_ATTRIBUTE_ARCHIVE)
// 		wcscpy(stcFileInfo.szAttributeDescription , L"<ARCHIVE> ");
// 	if(stcFileInfo.dwAttribute&FILE_ATTRIBUTE_COMPRESSED)
// 		wcscpy(stcFileInfo.szAttributeDescription , L"<压缩> ");
// 	// ......
// 	if(stcFileInfo.dwAttribute&FILE_ATTRIBUTE_TEMPORARY)
// 		wcscpy(stcFileInfo.szAttributeDescription , L"<临时文件> ");
// 	if(stcFileInfo.dwAttribute&FILE_ATTRIBUTE_DIRECTORY)
// 		wcscpy(stcFileInfo.szAttributeDescription , L"<目录> ");
// 
// 	return TRUE;
// }


void Travel(const TCHAR* pszPath , int nDeep )
{
	if(nDeep == 0)
		return;

	HANDLE hFind = NULL;
	TCHAR buff[ MAX_PATH ];

	// 合成一个用于查找的字符串
	_stprintf_s(buff , MAX_PATH , _T("%s\\*") , pszPath);

	WIN32_FIND_DATA findData = { 0 };
	// 查找指定目录下的第一个文件, 并且把文件信息保存到结构体中,
	// 并返回一个查找句柄
	hFind = FindFirstFile(buff , &findData);
	if(hFind == INVALID_HANDLE_VALUE)
		return ;
	

	do 
	{
		wprintf(L"%s\n" , findData.cFileName);

		// 
		// 过滤掉当前目录和上层目录
		if(_tcscmp(findData.cFileName , _T(".")) == 0 //判断是否是当前目录
		   || _tcscmp(findData.cFileName , _T("..")) == 0)// 判断是否是上层目录
		{
			continue;
		}


		// 判断当前文件是否是一个目录
		if(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			// 将当前文件夹路径和目录名合成一个新的文件夹路径
			_stprintf_s(buff , MAX_PATH , _T("%s\\%s") , pszPath , findData.cFileName);
			Travel(buff , nDeep-1);
		}
		

	} while(FindNextFile(hFind , &findData));// 查找下一个文件,并且把文件信息保存到结构体中


}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL , "chs");
	Travel(L"C:",2);


	WIN32_FILE_ATTRIBUTE_DATA wfad;
	GetFileAttributesEx(L"4_文件操作函数.cpp" , GetFileExInfoStandard , &wfad);

	// 获取进程目录
	TCHAR modulePath[MAX_PATH];
	GetModuleFileName(GetModuleHandle(NULL) ,// 模块句柄,
					  modulePath ,  // 保存路径的缓冲区
					  MAX_PATH // 缓冲区的大小
					  );

	return 0;
}

