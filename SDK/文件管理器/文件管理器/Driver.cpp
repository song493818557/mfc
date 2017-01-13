
#include "Driver.h"
#include <tchar.h>


const TCHAR* Driver::Type(const TCHAR * pszDiskName)
{
	DWORD dwType = GetDriveType(pszDiskName);
	switch (dwType)
	{
	case DRIVE_UNKNOWN:
		return  _T("δ֪");
	case DRIVE_NO_ROOT_DIR:
		return  _T("�������ĸ�·����Ч");
	case DRIVE_REMOVABLE:
		return  _T("���ƶ�������������");
	case DRIVE_FIXED:
		return  _T("�����Ƴ���������");
	case DRIVE_REMOTE:
		return  _T("����������");
	case DRIVE_CDROM:
	{
		if (!GetVolumeInformation(pszDiskName, NULL, NULL, NULL, NULL, NULL, NULL, NULL))
			return  _T("CD-ROM������(�й���)");
		else
			return  _T("CD-ROM������(�޹���)");
	}
	case DRIVE_RAMDISK:
		return  _T("RAM������");
	default:
		return  _T("���������ʹ���");
	}

}



Driver::Driver(const TCHAR * pszDiskName /*= NULL*/)
{
	GetDriverInfo(pszDiskName);
}




bool Driver::GetDriverInfo(const TCHAR * pszDiskName)
{
	if (pszDiskName == NULL)
		return false;

	// ������������
	_tcscpy_s(m_szDriverName, 4, pszDiskName);

	// ��ȡ����������
	_tcscpy_s(m_szDriverType, 20, Type(pszDiskName));

	// ��ȡ���������ܿռ��С
	GetDiskFreeSpace(pszDiskName,
		&m_dwSectorsPerCluster,	 // ÿ�ص���������
		&m_dwBytesPerSector,		 // ÿ���������ֽ���
		&m_dwNumberOfFreeClusters, // ���дص�����
		&m_dwTotalNumberOfClusters	 // ȫ���ص�����
		);

	// ��ȡ���������ڵľ����Ϣ
	GetVolumeInformation(pszDiskName,
		m_szVolumeName, MAX_PATH,
		&m_dwVolumeSerialNumber,
		&m_dwMaximumComponentLength,
		&m_dwFileSystemFlags,
		m_szFileSystemNameBuffer,
		MAX_PATH
		);

	return true;
}

void Driver::show()
{
	// �������� | ���� | �ļ�ϵͳ���� | �ܿռ� | ʣ��ռ� 

}

void DriverList::GetAllDriverInfo()
{
	// ��ȡϵͳ���е�������
	TCHAR buff[MAX_PATH];
	GetLogicalDriveStrings(MAX_PATH, buff);

	// ��ȡÿһ������������ϸ��Ϣ
	TCHAR *pTemp = buff;
	do
	{
		m_vecDriverList.push_back(Driver(pTemp));
		pTemp += _tcslen(pTemp) + 1;
	} while (*pTemp);

}

int DriverList::size()
{
	return m_vecDriverList.size();
}

const Driver& DriverList::operator[](int nIndex)
{
	return m_vecDriverList[nIndex];
}

const vector<Driver>& DriverList::GetDriverList() const
{
	return m_vecDriverList;
}


