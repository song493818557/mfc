// �������.cpp : �������̨Ӧ�ó������ڵ㡣
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
				case  DRIVE_UNKNOWN:printf("δ֪����"); break;
				case  DRIVE_NO_ROOT_DIR:printf("��Ч�Ĵ�������"); break;
				case  DRIVE_REMOVABLE:printf("���ƶ�����"); break;
				case  DRIVE_FIXED:printf("Ӳ��"); break;
				case  DRIVE_REMOTE:printf("�������"); break;
				case  DRIVE_CDROM:printf("CD-ROM"); break;
				case  DRIVE_RAMDISK:printf("RAM ����"); break;
				default: break;
		}
		printf("\n");
		pTemp += 4;
	} while (*pTemp !=0);
	//getch();
	system("PAUSE");
	return 0;
}

