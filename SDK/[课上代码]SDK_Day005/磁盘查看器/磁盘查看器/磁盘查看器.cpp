// ���̲鿴��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Driver.h"

int _tmain(int argc, _TCHAR* argv[])
{

	TCHAR buff[ MAX_PATH ] = { 0 };
	TCHAR buff2[ MAX_PATH ] = { 0 };
	HANDLE hFile = FindFirstVolume(buff , MAX_PATH);

	FindFirstVolumeMountPoint(buff , buff2 , MAX_PATH);


	
	do 
	{
		wprintf(L"%s\n" , buff);
	} while(FindNextVolume(hFile , buff , MAX_PATH));

	DriverList driverlist;
	driverlist.GetAllDriverInfo();

	for(size_t i = 0; i < driverlist.size(); i++)
	{
		driverlist[ i ].m_dwBytesPerSector;
	}
	
	return 0;
}

