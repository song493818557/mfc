#pragma once
#include <tchar.h>
#include <list>
using std::list;

#include "MyFile.h"


class MyDir
{

public:
	list<MyFile> m_Filelist;
	 
public:
	MyDir();
	~MyDir();

	bool ListDir(const TCHAR* pszDir, int nDeep = 1); 
	bool CompareRules(MyFile a, MyFile b){
		if (_tcslen(a.m_szFileName) > _tcslen(b.m_szFileName)) // big to small  
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

