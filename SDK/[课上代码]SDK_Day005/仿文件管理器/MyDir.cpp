#include "MyDir.h"


MyDir::MyDir()
{
}


MyDir::~MyDir()
{
}



bool MyDir::ListDir(const TCHAR* pszDir , int nDeep/*=5*/)
{
	if(pszDir == NULL )
		return false;

	if(nDeep-1 < 0)
		return true;

	MyFile myFile;

	_stprintf_s(myFile.m_szFileName ,MAX_PATH ,_T("%s\\*") ,pszDir);

	WIN32_FIND_DATA findData;
	HANDLE hFind = FindFirstFile(myFile.m_szFileName , &findData);
	if(hFind == INVALID_HANDLE_VALUE)
		return false;

	do 
	{
		if(_tcscmp(findData.cFileName , _T(".")) == 0 || _tcscmp(findData.cFileName , _T("..")) == 0)
			continue;

		_stprintf_s(myFile.m_szFileName , MAX_PATH , _T("%s\\%s") , pszDir , findData.cFileName);

		if(findData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY && nDeep>1)
		{
			ListDir(myFile.m_szFileName , nDeep - 1);
		}

		myFile.GetFileInfo(findData);
		m_Filelist.push_back(myFile);

	} while(FindNextFile(hFind , &findData));

	return true;
}
