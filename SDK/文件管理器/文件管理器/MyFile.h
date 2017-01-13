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
	// �����ļ���
	// �����ļ���С
	// �ļ�����ʱ��
	// �ļ�����޸ĵ�ʱ��
	TCHAR		m_szFileName[MAX_PATH]; // �ļ���(�������ļ�·��)

	TCHAR		m_szFiletype[MAX_PATH]; // �ļ���׺
	LONG64		m_qwSize; // �ļ���С
	DWORD		m_dwFileAttributes;// �ļ�����
	SYSTEMTIME  m_CreationTime;// �ļ�����ʱ��
	SYSTEMTIME  m_LastAccessTime;//�ļ�������ʱ��
	SYSTEMTIME  m_LastWriteTime;//�ļ�����޸�ʱ��
	  
	FILETIME  mm_CreationTime;// �ļ�����ʱ���
	FILETIME  mm_LastAccessTime;//�ļ�������ʱ���
	FILETIME  mm_LastWriteTime;//�ļ�����޸�ʱ���

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