#include "MyFile.h"



MyFile::MyFile()
	:m_CreationTime() ,
	m_dwFileAttributes() ,
	m_LastAccessTime() ,
	m_LastWriteTime() ,
	m_qwSize()
{
	m_szFileName[ 0 ] = 0;
}


MyFile::~MyFile()
{
}

bool MyFile::GetFileInfo(WIN32_FIND_DATA& findData)
{
	_tcscpy_s(m_szFileName , MAX_PATH , findData.cFileName);


	m_dwFileAttributes = findData.dwFileAttributes;
	if(findData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
		m_bIsDir = TRUE;
	else
		m_bIsDir = FALSE;

	//文件时间转本地(本时区)时间

	// 分别转换文件创建时间,文件最后访问时间,文件最后修改时间
	FileTimeToLocalFileTime(&findData.ftCreationTime , &findData.ftCreationTime);
	FileTimeToLocalFileTime(&findData.ftLastAccessTime , &findData.ftLastAccessTime);
	FileTimeToLocalFileTime(&findData.ftLastWriteTime , &findData.ftLastWriteTime);

	// 文件时间转系统时间(即包括年月日时分秒的时间)
	// 分别转换文件创建时间,文件最后访问时间,文件最后修改时间
	FileTimeToSystemTime(&findData.ftCreationTime , &m_CreationTime);
	FileTimeToSystemTime(&findData.ftLastAccessTime , &m_LastAccessTime);
	FileTimeToSystemTime(&findData.ftLastWriteTime , &m_LastWriteTime);

	// 保存文件大小
	m_qwSize = (((UINT64)findData.nFileSizeHigh) << 32) | findData.nFileSizeLow;
	
	return true;
}

bool MyFile::GetFileInfo(const TCHAR* pFilePath)
{
	WIN32_FIND_DATA findData;

	if(FindFirstFile(pFilePath , &findData) != INVALID_HANDLE_VALUE)
		return GetFileInfo(findData);
	return false;
}
