#pragma once
#include <windows.h>
#include <vector>
using std::vector;




class Driver
{

public:
	TCHAR m_szDriverName[ 4 ];  // �̷�
	TCHAR m_szDriverType[ 20 ]; // ������������

	// ��������Ϣ
	DWORD m_dwSectorsPerCluster ;	  // ÿ�ص���������
	DWORD m_dwBytesPerSector ;		  // ÿ���������ֽ���
	DWORD m_dwNumberOfFreeClusters ;  // ���дص�����
	DWORD m_dwTotalNumberOfClusters;  // ȫ���ص�����

	// ����Ϣ
	TCHAR  m_szVolumeName[ MAX_PATH ] ; // �������
	DWORD  m_dwVolumeSerialNumber ;     // ������к�
	DWORD  m_dwMaximumComponentLength;
	DWORD  m_dwFileSystemFlags ;		// �ļ�ϵͳ��־
	TCHAR  m_szFileSystemNameBuffer[ MAX_PATH ]; // �ļ�ϵͳ����

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
