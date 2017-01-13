#pragma once
#include <tchar.h>
#include <windows.h>



enum sortEnum
{
	SNAME = 0,
	STYPE,
	SSIZE,
	SUTIME,
	SCTIME 
};

class MyFile
{

public:
	// 保存文件名
	// 保存文件大小
	// 文件创建时间
	// 文件最后被修改的时间
	TCHAR		m_szFileName[MAX_PATH]; // 文件名(不包括文件路径)

	TCHAR		m_szFiletype[MAX_PATH]; // 文件后缀
	LONG64		m_qwSize; // 文件大小
	DWORD		m_dwFileAttributes;// 文件属性
	SYSTEMTIME  m_CreationTime;// 文件创建时间
	SYSTEMTIME  m_LastAccessTime;//文件最后访问时间
	SYSTEMTIME  m_LastWriteTime;//文件最后修改时间
	  
	FILETIME  mm_CreationTime;// 文件创建时间戳
	FILETIME  mm_LastAccessTime;//文件最后访问时间戳
	FILETIME  mm_LastWriteTime;//文件最后修改时间戳

	BOOL		m_bIsDir;
	static sortEnum Enumsort;
public:
	MyFile();
	~MyFile(); 
	friend bool operator >(const MyFile& obj1,const MyFile& obj2);
	bool GetFileInfo(const TCHAR* pFilePath);
	bool GetFileInfo(WIN32_FIND_DATA& findData);
	//bool CompareRules(const MyFile& obj1, const MyFile& obj2);
};

bool CompareRules(const MyFile& obj1, const MyFile& obj2);