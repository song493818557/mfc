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

	//�ļ�ʱ��ת����(��ʱ��)ʱ��

	// �ֱ�ת���ļ�����ʱ��,�ļ�������ʱ��,�ļ�����޸�ʱ��
	FileTimeToLocalFileTime(&findData.ftCreationTime , &findData.ftCreationTime);
	FileTimeToLocalFileTime(&findData.ftLastAccessTime , &findData.ftLastAccessTime);
	FileTimeToLocalFileTime(&findData.ftLastWriteTime , &findData.ftLastWriteTime);

	// �ļ�ʱ��תϵͳʱ��(������������ʱ�����ʱ��)
	// �ֱ�ת���ļ�����ʱ��,�ļ�������ʱ��,�ļ�����޸�ʱ��
	FileTimeToSystemTime(&findData.ftCreationTime , &m_CreationTime);
	FileTimeToSystemTime(&findData.ftLastAccessTime , &m_LastAccessTime);
	FileTimeToSystemTime(&findData.ftLastWriteTime , &m_LastWriteTime);

	// �����ļ���С
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
