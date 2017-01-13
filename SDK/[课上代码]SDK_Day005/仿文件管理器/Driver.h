#pragma once
#include <windows.h>
#include <vector>
using std::vector;




class Driver
{

public:
	TCHAR m_szDriverName[ 4 ];  // 盘符
	TCHAR m_szDriverType[ 20 ]; // 驱动器的类型

	// 驱动器信息
	DWORD m_dwSectorsPerCluster ;	  // 每簇的扇区数量
	DWORD m_dwBytesPerSector ;		  // 每个扇区的字节数
	DWORD m_dwNumberOfFreeClusters ;  // 空闲簇的总数
	DWORD m_dwTotalNumberOfClusters;  // 全部簇的总数

	// 卷信息
	TCHAR  m_szVolumeName[ MAX_PATH ] ; // 卷的名字
	DWORD  m_dwVolumeSerialNumber ;     // 卷的序列号
	DWORD  m_dwMaximumComponentLength;
	DWORD  m_dwFileSystemFlags ;		// 文件系统标志
	TCHAR  m_szFileSystemNameBuffer[ MAX_PATH ]; // 文件系统名称

public:
	Driver(const TCHAR * pszDiskName = NULL);

	const TCHAR* Type(const TCHAR * pszDiskName);
	bool GetDriverInfo(const TCHAR * pszDiskName);	

	void show();
};




class DriverList
{
protected:
	vector<Driver> m_vecDriverList;

public:
	void GetAllDriverInfo();

	int size();
	const Driver& operator[](int nIndex);

	const vector<Driver>& GetDriverList()const;
};
