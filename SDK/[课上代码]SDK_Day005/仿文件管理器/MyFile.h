#pragma once
#include <tchar.h>
#include <windows.h>

class MyFile
{

public:
	// �����ļ���
	// �����ļ���С
	// �ļ�����ʱ��
	// �ļ�����޸ĵ�ʱ��
	TCHAR		m_szFileName[ MAX_PATH ]; // �ļ���(�������ļ�·��)
	LONG64		m_qwSize; // �ļ���С
	DWORD		m_dwFileAttributes;// �ļ�����
	SYSTEMTIME  m_CreationTime;// �ļ�����ʱ��
	SYSTEMTIME  m_LastAccessTime;//�ļ�������ʱ��
	SYSTEMTIME  m_LastWriteTime;//�ļ�����޸�ʱ��
	BOOL		m_bIsDir;
public:
	MyFile();
	~MyFile();


	bool GetFileInfo(const TCHAR* pFilePath);
	bool GetFileInfo(WIN32_FIND_DATA& findData);
};

