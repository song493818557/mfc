// 1_获取所有驱动器.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>

int _tmain(int argc , _TCHAR* argv[])
{
	// 获取所有驱动器
	WCHAR buff[ MAX_PATH ];
	GetLogicalDriveStrings(MAX_PATH , buff);
	WCHAR* pTemp = buff;

	TCHAR	volumeName[ MAX_PATH ];
	TCHAR	fileSystemName[ 50 ];
	do{
		wprintf(L"%s" , pTemp);
		// 获取卷的详细信息
		GetVolumeInformation(pTemp ,
							 volumeName , MAX_PATH ,/*卷的标题名*/
							 0 , 0 , 0 ,
							 fileSystemName , 50/*卷的文件系统名*/
							 );

		wprintf(L" %s %s " , volumeName , fileSystemName);

		// 获取驱动器类型
		UINT uType = GetDriveType(pTemp);
		switch(uType)
		{
			case DRIVE_NO_ROOT_DIR:printf(" 无效的根路径 "); break;
			case DRIVE_REMOVABLE:printf(" 可移动磁盘 "); break;
			case DRIVE_FIXED:printf(" 硬盘 "); break;
			case DRIVE_REMOTE:printf(" 网络磁盘 "); break;
			case DRIVE_CDROM:
			{
				printf(" 光盘驱动器 ");
				GetVolumeInformation(pTemp , 0 , 0 , 0 , 0 , 0 , 0 , 0);
				if(21 == GetLastError()) // 获取最后的错误信息
				{
					printf("(无光盘)");
				}
				else
					printf("(有光盘)");
				//printf("(%s光盘)" , 21==GetLastError()?"无":"有");
			}
			break;
			case DRIVE_RAMDISK:printf(" RAM磁盘"); break;
			case DRIVE_UNKNOWN:printf(" 未知驱动器 "); break;
		}

		// 驱动器空间信息
		// 总空间信息, 剩余的空间信息
		DWORD dwSectorsPerCluster ;
		DWORD dwBytesPerSector;
		DWORD dwNumberOfFreeClusters ;
		DWORD dwTotalNumberOfClusters;
		GetDiskFreeSpace(pTemp ,
						 &dwSectorsPerCluster ,// 每簇扇区数
						 &dwBytesPerSector , // 每个扇区的字节数
						 &dwNumberOfFreeClusters ,// 剩余空间的簇的个数
						 &dwTotalNumberOfClusters// 总空间的簇的个数
						 );

		// 计算出剩余空间的字节数
		UINT64 freeByte = 1;
		freeByte = dwNumberOfFreeClusters;
		freeByte *= dwSectorsPerCluster;
		freeByte *= dwBytesPerSector;
		// 计算出总空间的字节数
		UINT64 totalByte = 1;
		totalByte = dwTotalNumberOfClusters;
		totalByte *= dwSectorsPerCluster;
		totalByte *= dwBytesPerSector;

		printf("剩余: %I64d , 总:%I64d" ,
			   freeByte ,
			   totalByte);

		printf("\n");
		pTemp += 4; //字符串的结构: C:\0D:\0E:\00
	} while(*pTemp != 0);

	system("pause");
	return 0;
}

