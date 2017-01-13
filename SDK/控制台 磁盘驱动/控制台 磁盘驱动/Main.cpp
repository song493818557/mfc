#include <windows.h>
#include <stdio.h>
#include <tchar.h>


int _tmain(_In_ int _Argc, _TCHAR * argv[]){

	TCHAR buff[MAX_PATH];
	GetLogicalDriveStringsW(MAX_PATH,buff);

	wprintf(L"%s", buff);
	
	return 0;
}