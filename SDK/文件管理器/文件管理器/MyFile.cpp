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
	if (strlocal == -1) //�ļ�������
	{
		_tcscpy_s(m_szFileName, MAX_PATH, findData.cFileName);
		_tcscpy_s(m_szFiletype, MAX_PATH, _T("�ļ���"));
	}
	else
	{
		_tcscpy_s(m_szFileName, MAX_PATH, aa.Left(strlocal));
		_tcscpy_s(m_szFiletype, MAX_PATH, aa.Right(_tcslen(aa) -strlocal));
	}

	//�ж��Ƿ����ļ���
	//m_dwFileAttributes = findData.dwFileAttributes;
	//if (findData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
	//	m_bIsDir = TRUE;
	//else
	//	m_bIsDir = FALSE;

	//�ļ�ʱ��ת����(��ʱ��)ʱ��

	// �ֱ�ת���ļ�����ʱ��,�ļ�������ʱ��,�ļ�����޸�ʱ��
	FileTimeToLocalFileTime(&findData.ftCreationTime, &findData.ftCreationTime);
	FileTimeToLocalFileTime(&findData.ftLastAccessTime, &findData.ftLastAccessTime);
	FileTimeToLocalFileTime(&findData.ftLastWriteTime, &findData.ftLastWriteTime);
	mm_CreationTime = findData.ftCreationTime;
	mm_LastAccessTime = findData.ftLastAccessTime;
	mm_LastWriteTime = findData.ftLastWriteTime;
	// �ļ�ʱ��תϵͳʱ��(������������ʱ�����ʱ��)
	// �ֱ�ת���ļ�����ʱ��,�ļ�������ʱ��,�ļ�����޸�ʱ��
	FileTimeToSystemTime(&findData.ftCreationTime, &m_CreationTime);
	FileTimeToSystemTime(&findData.ftLastAccessTime, &m_LastAccessTime);
	FileTimeToSystemTime(&findData.ftLastWriteTime, &m_LastWriteTime);
	//WIN32_FIND_DATA findDataaa;
	//SystemTimeToFileTime(&m_LastWriteTime, &findDataaa.ftCreationTime);
	// �����ļ���С
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
//��������
bool operator >(const MyFile& obj1, const MyFile& obj2)
{
	if (obj1.m_qwSize < obj2.m_qwSize)
	{
		return true;
	}
	return false;
}

//��������
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