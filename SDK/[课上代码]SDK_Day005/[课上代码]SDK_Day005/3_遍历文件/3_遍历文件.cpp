// 3_�����ļ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <locale.h>
#include <wchar.h>
#include <psapi.h>

// BOOL GetFileAttribute(LPWSTR lpPath , FILE_INFO &stcFileInfo) {
// 	// 1. �ļ�·��
// 	wcscpy(stcFileInfo.szFilePath , lpPath);
// 	
// 	// 2. ��ȡʱ����Ϣ
// 	WIN32_FILE_ATTRIBUTE_DATA wfad;
// 	GetFileAttributesEx(lpPath , GetFileExInfoStandard , &wfad);
// 	// 2.1 ��ȡ����ʱ��
// 	FILETIME ftLocal;
// 	FileTimeToLocalFileTime(&wfad.ftCreationTime , &ftLocal);   // ����Ϊϵͳ����ʱ����ʱ��
// 	FileTimeToSystemTime(&ftLocal , &stcFileInfo.stcCreatTime); // ת��ΪSYSTEMTIME��ʽ
// 
// 	// 2.2 ��ȡ������ʱ��
// 	FileTimeToLocalFileTime(&wfad.ftLastAccessTime , &ftLocal); // ����Ϊϵͳ����ʱ����ʱ��
// 	FileTimeToSystemTime(&ftLocal , &stcFileInfo.stcCreatTime); // ת��ΪSYSTEMTIME��ʽ
// 	// 2.3 ��ȡ����޸�ʱ��
// 	FileTimeToLocalFileTime(&wfad.ftLastWriteTime , &ftLocal);  // ����Ϊϵͳ����ʱ����ʱ��
// 	FileTimeToSystemTime(&ftLocal , &stcFileInfo.stcCreatTime); // ת��ΪSYSTEMTIME��ʽ
// 	// 3. ��ȡ�ļ���С
// 	stcFileInfo.qwFileSize = wfad.nFileSizeHigh;
// 	stcFileInfo.qwFileSize <<= sizeof(DWORD) * 8;
// 	stcFileInfo.qwFileSize += wfad.nFileSizeLow;
// 
// 
// 	// 4. �ļ�����
// 	stcFileInfo.dwAttribute = wfad.dwFileAttributes;
// 	if(stcFileInfo.dwAttribute&FILE_ATTRIBUTE_ARCHIVE)
// 		wcscpy(stcFileInfo.szAttributeDescription , L"<ARCHIVE> ");
// 	if(stcFileInfo.dwAttribute&FILE_ATTRIBUTE_COMPRESSED)
// 		wcscpy(stcFileInfo.szAttributeDescription , L"<ѹ��> ");
// 	// ......
// 	if(stcFileInfo.dwAttribute&FILE_ATTRIBUTE_TEMPORARY)
// 		wcscpy(stcFileInfo.szAttributeDescription , L"<��ʱ�ļ�> ");
// 	if(stcFileInfo.dwAttribute&FILE_ATTRIBUTE_DIRECTORY)
// 		wcscpy(stcFileInfo.szAttributeDescription , L"<Ŀ¼> ");
// 
// 	return TRUE;
// }


void Travel(const TCHAR* pszPath , int nDeep )
{
	if(nDeep == 0)
		return;

	HANDLE hFind = NULL;
	TCHAR buff[ MAX_PATH ];

	// �ϳ�һ�����ڲ��ҵ��ַ���
	_stprintf_s(buff , MAX_PATH , _T("%s\\*") , pszPath);

	WIN32_FIND_DATA findData = { 0 };
	// ����ָ��Ŀ¼�µĵ�һ���ļ�, ���Ұ��ļ���Ϣ���浽�ṹ����,
	// ������һ�����Ҿ��
	hFind = FindFirstFile(buff , &findData);
	if(hFind == INVALID_HANDLE_VALUE)
		return ;
	

	do 
	{
		wprintf(L"%s\n" , findData.cFileName);

		// 
		// ���˵���ǰĿ¼���ϲ�Ŀ¼
		if(_tcscmp(findData.cFileName , _T(".")) == 0 //�ж��Ƿ��ǵ�ǰĿ¼
		   || _tcscmp(findData.cFileName , _T("..")) == 0)// �ж��Ƿ����ϲ�Ŀ¼
		{
			continue;
		}


		// �жϵ�ǰ�ļ��Ƿ���һ��Ŀ¼
		if(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			// ����ǰ�ļ���·����Ŀ¼���ϳ�һ���µ��ļ���·��
			_stprintf_s(buff , MAX_PATH , _T("%s\\%s") , pszPath , findData.cFileName);
			Travel(buff , nDeep-1);
		}
		

	} while(FindNextFile(hFind , &findData));// ������һ���ļ�,���Ұ��ļ���Ϣ���浽�ṹ����


}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL , "chs");
	Travel(L"C:",2);


	WIN32_FILE_ATTRIBUTE_DATA wfad;
	GetFileAttributesEx(L"4_�ļ���������.cpp" , GetFileExInfoStandard , &wfad);

	// ��ȡ����Ŀ¼
	TCHAR modulePath[MAX_PATH];
	GetModuleFileName(GetModuleHandle(NULL) ,// ģ����,
					  modulePath ,  // ����·���Ļ�����
					  MAX_PATH // �������Ĵ�С
					  );

	return 0;
}

