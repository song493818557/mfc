// 1_��ȡ����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Windows.h>

int _tmain(int argc , _TCHAR* argv[])
{
	// ��ȡ����������
	WCHAR buff[ MAX_PATH ];
	GetLogicalDriveStrings(MAX_PATH , buff);
	WCHAR* pTemp = buff;

	TCHAR	volumeName[ MAX_PATH ];
	TCHAR	fileSystemName[ 50 ];
	do{
		wprintf(L"%s" , pTemp);
		// ��ȡ�����ϸ��Ϣ
		GetVolumeInformation(pTemp ,
							 volumeName , MAX_PATH ,/*��ı�����*/
							 0 , 0 , 0 ,
							 fileSystemName , 50/*����ļ�ϵͳ��*/
							 );

		wprintf(L" %s %s " , volumeName , fileSystemName);

		// ��ȡ����������
		UINT uType = GetDriveType(pTemp);
		switch(uType)
		{
			case DRIVE_NO_ROOT_DIR:printf(" ��Ч�ĸ�·�� "); break;
			case DRIVE_REMOVABLE:printf(" ���ƶ����� "); break;
			case DRIVE_FIXED:printf(" Ӳ�� "); break;
			case DRIVE_REMOTE:printf(" ������� "); break;
			case DRIVE_CDROM:
			{
				printf(" ���������� ");
				GetVolumeInformation(pTemp , 0 , 0 , 0 , 0 , 0 , 0 , 0);
				if(21 == GetLastError()) // ��ȡ���Ĵ�����Ϣ
				{
					printf("(�޹���)");
				}
				else
					printf("(�й���)");
				//printf("(%s����)" , 21==GetLastError()?"��":"��");
			}
			break;
			case DRIVE_RAMDISK:printf(" RAM����"); break;
			case DRIVE_UNKNOWN:printf(" δ֪������ "); break;
		}

		// �������ռ���Ϣ
		// �ܿռ���Ϣ, ʣ��Ŀռ���Ϣ
		DWORD dwSectorsPerCluster ;
		DWORD dwBytesPerSector;
		DWORD dwNumberOfFreeClusters ;
		DWORD dwTotalNumberOfClusters;
		GetDiskFreeSpace(pTemp ,
						 &dwSectorsPerCluster ,// ÿ��������
						 &dwBytesPerSector , // ÿ���������ֽ���
						 &dwNumberOfFreeClusters ,// ʣ��ռ�Ĵصĸ���
						 &dwTotalNumberOfClusters// �ܿռ�Ĵصĸ���
						 );

		// �����ʣ��ռ���ֽ���
		UINT64 freeByte = 1;
		freeByte = dwNumberOfFreeClusters;
		freeByte *= dwSectorsPerCluster;
		freeByte *= dwBytesPerSector;
		// ������ܿռ���ֽ���
		UINT64 totalByte = 1;
		totalByte = dwTotalNumberOfClusters;
		totalByte *= dwSectorsPerCluster;
		totalByte *= dwBytesPerSector;

		printf("ʣ��: %I64d , ��:%I64d" ,
			   freeByte ,
			   totalByte);

		printf("\n");
		pTemp += 4; //�ַ����Ľṹ: C:\0D:\0E:\00
	} while(*pTemp != 0);

	system("pause");
	return 0;
}

