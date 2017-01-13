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

	bool ListDir(const TCHAR* pszDir, int nDeep=1);

};

