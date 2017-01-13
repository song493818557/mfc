#pragma once
#include <tchar.h>
#include <windows.h>

class MyFile
{

public:
	// 保存文件名
	// 保存文件大小
	// 文件创建时间
	// 文件最后被修改的时间
	TCHAR		m_szFileName[ MAX_PATH ]; // 文件名(不包括文件路径)
	LONG64		m_qwSize; // 文件大小
	DWORD		m_dwFileAttributes;// 文件属性
	SYSTEMTIME  m_CreationTime;// 文件创建时间
	SYSTEMTIME  m_LastAccessTime;//文件最后访问时间
	SYSTEMTIME  m_LastWriteTime;//文件最后修改时间
	BOOL		m_bIsDir;
public:
	MyFile();
	~MyFile();


	bool GetFileInfo(const TCHAR* pFilePath);
	bool GetFileInfo(WIN32_FIND_DATA& findData);
};

