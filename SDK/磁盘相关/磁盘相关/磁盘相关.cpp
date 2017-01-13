// 磁盘相关.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	WCHAR buff[MAX_PATH];
	GetLogicalDriveStrings(MAX_PATH, buff);
	WCHAR *pTemp = buff;
	do 
	{
		wprintf(L"%s", pTemp);
		UINT uType = GetDriveType(pTemp);
		switch (uType)
		{
				case  DRIVE_UNKNOWN:printf("未知驱动"); break;
				case  DRIVE_NO_ROOT_DIR:printf("无效的磁盘驱动"); break;
				case  DRIVE_REMOVABLE:printf("可移动磁盘"); break;
				case  DRIVE_FIXED:printf("硬盘"); break;
				case  DRIVE_REMOTE:printf("网络磁盘"); break;
				case  DRIVE_CDROM:printf("CD-ROM"); break;
				case  DRIVE_RAMDISK:printf("RAM 磁盘"); break;
				default: break;
		}
		printf("\n");
		pTemp += 4;
	} while (*pTemp !=0);
	//getch();
	system("PAUSE");
	return 0;
}

