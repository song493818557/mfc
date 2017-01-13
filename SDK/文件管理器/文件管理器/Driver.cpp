
#include "Driver.h"
#include <tchar.h>


const TCHAR* Driver::Type(const TCHAR * pszDiskName)
{
	DWORD dwType = GetDriveType(pszDiskName);
	switch (dwType)
	{
	case DRIVE_UNKNOWN:
		return  _T("未知");
	case DRIVE_NO_ROOT_DIR:
		return  _T("驱动器的根路径无效");
	case DRIVE_REMOVABLE:
		return  _T("可移动介质类驱动器");
	case DRIVE_FIXED:
		return  _T("不可移除的驱动器");
	case DRIVE_REMOTE:
		return  _T("网络驱动器");
	case DRIVE_CDROM:
	{
		if (!GetVolumeInformation(pszDiskName, NULL, NULL, NULL, NULL, NULL, NULL, NULL))
			return  _T("CD-ROM驱动器(有光盘)");
		else
			return  _T("CD-ROM驱动器(无光盘)");
	}
	case DRIVE_RAMDISK:
		return  _T("RAM驱动器");
	default:
		return  _T("驱动器类型错误");
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

	// 保存驱动器名
	_tcscpy_s(m_szDriverName, 4, pszDiskName);

	// 获取驱动器类型
	_tcscpy_s(m_szDriverType, 20, Type(pszDiskName));

	// 获取驱动器的总空间大小
	GetDiskFreeSpace(pszDiskName,
		&m_dwSectorsPerCluster,	 // 每簇的扇区数量
		&m_dwBytesPerSector,		 // 每个扇区的字节数
		&m_dwNumberOfFreeClusters, // 空闲簇的总数
		&m_dwTotalNumberOfClusters	 // 全部簇的总数
		);

	// 获取驱动器所在的卷的信息
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
	// 驱动器名 | 卷名 | 文件系统类型 | 总空间 | 剩余空间 

}

void DriverList::GetAllDriverInfo()
{
	// 获取系统所有的驱动器
	TCHAR buff[MAX_PATH];
	GetLogicalDriveStrings(MAX_PATH, buff);

	// 获取每一个驱动器的详细信息
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


