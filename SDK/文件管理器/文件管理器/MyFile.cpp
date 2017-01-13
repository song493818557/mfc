#include "MyFile.h"
#include <atlstr.h>

sortEnum MyFile::Enumsort = SNAME;
MyFile::MyFile()
	:m_CreationTime(),
	m_dwFileAttributes(),
	m_LastAccessTime(),
	m_LastWriteTime(),
	m_qwSize()
{
	m_szFileName[0] = 0;
}


MyFile::~MyFile()
{
}

bool MyFile::GetFileInfo(WIN32_FIND_DATA& findData)
{ 
	CString aa(findData.cFileName);
	int strlocal = aa.FindOneOf(_T("."));
	if (strlocal == -1) //文件夹类型
	{
		_tcscpy_s(m_szFileName, MAX_PATH, findData.cFileName);
		_tcscpy_s(m_szFiletype, MAX_PATH, _T("文件夹"));
	}
	else
	{
		_tcscpy_s(m_szFileName, MAX_PATH, aa.Left(strlocal));
		_tcscpy_s(m_szFiletype, MAX_PATH, aa.Right(_tcslen(aa) -strlocal));
	}

	//判断是否是文件夹
	//m_dwFileAttributes = findData.dwFileAttributes;
	//if (findData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
	//	m_bIsDir = TRUE;
	//else
	//	m_bIsDir = FALSE;

	//文件时间转本地(本时区)时间

	// 分别转换文件创建时间,文件最后访问时间,文件最后修改时间
	FileTimeToLocalFileTime(&findData.ftCreationTime, &findData.ftCreationTime);
	FileTimeToLocalFileTime(&findData.ftLastAccessTime, &findData.ftLastAccessTime);
	FileTimeToLocalFileTime(&findData.ftLastWriteTime, &findData.ftLastWriteTime);
	mm_CreationTime = findData.ftCreationTime;
	mm_LastAccessTime = findData.ftLastAccessTime;
	mm_LastWriteTime = findData.ftLastWriteTime;
	// 文件时间转系统时间(即包括年月日时分秒的时间)
	// 分别转换文件创建时间,文件最后访问时间,文件最后修改时间
	FileTimeToSystemTime(&findData.ftCreationTime, &m_CreationTime);
	FileTimeToSystemTime(&findData.ftLastAccessTime, &m_LastAccessTime);
	FileTimeToSystemTime(&findData.ftLastWriteTime, &m_LastWriteTime);
	//WIN32_FIND_DATA findDataaa;
	//SystemTimeToFileTime(&m_LastWriteTime, &findDataaa.ftCreationTime);
	// 保存文件大小
	m_qwSize = (((UINT64)findData.nFileSizeHigh) << 32) | findData.nFileSizeLow;

	return true;
}

bool MyFile::GetFileInfo(const TCHAR* pFilePath)
{
	WIN32_FIND_DATA findData;

	if (FindFirstFile(pFilePath, &findData) != INVALID_HANDLE_VALUE)
		return GetFileInfo(findData);
	return false;
}
//重载排序
bool operator >(const MyFile& obj1, const MyFile& obj2)
{
	if (obj1.m_qwSize < obj2.m_qwSize)
	{
		return true;
	}
	return false;
}

//重载排序
bool CompareRules(const MyFile& obj1, const MyFile& obj2)
{
	 
	long aa = obj1.m_LastAccessTime.wYear + obj1.m_LastAccessTime.wMonth + obj1.m_LastAccessTime.wDay;
	long aab = obj2.m_LastAccessTime.wYear + obj2.m_LastAccessTime.wMonth + obj2.m_LastAccessTime.wDay;
	switch (MyFile::Enumsort)
	{
		  
	case SNAME: { if (_toupper(obj1.m_szFileName[0]) < _toupper(obj2.m_szFileName[0])) return true;  }break;
	case STYPE: { if (obj1.m_szFiletype[1] < obj2.m_szFiletype[1]) return true; }break;
	case SSIZE:  if (obj1.m_qwSize < obj2.m_qwSize) return true; break;
	case SUTIME: if (obj1.mm_LastAccessTime.dwHighDateTime < obj2.mm_LastAccessTime.dwHighDateTime) return true; break;
	case SCTIME:  if (obj1.mm_CreationTime.dwHighDateTime < obj2.mm_CreationTime.dwHighDateTime) return true; break;

	}
	   
	return false;
}