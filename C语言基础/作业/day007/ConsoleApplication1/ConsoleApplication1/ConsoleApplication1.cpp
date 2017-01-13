// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <wininet.h>
//#include <WinHTTP.h>
#include <vector>
#include <string.h>
#include <iostream>
#define MAXSIZE 20000
#pragma comment(lib, "Wininet.lib")
using namespace std;
vector<string> Astring;
void urlopen(_TCHAR*);

int _tmain(int argc, _TCHAR* argv[])
{
	
	urlopen(_T("http://club.jd.com/allreview/1-2.html"));
	return 0;
}
void urlopen(_TCHAR* url)
{
	HINTERNET hSession = InternetOpen(_T("UrlTest"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (hSession != NULL)
	{
		HINTERNET hHttp = InternetOpenUrl(hSession, url, NULL, 0, INTERNET_FLAG_DONT_CACHE, 0);
		if (hHttp != NULL)
		{
			wprintf_s(_T("%s\n"), url);
			char Temp[MAXSIZE]; 
			ULONG Number = 1;
			int i = 0;
			while (Number > 0)
			{
				InternetReadFile(hHttp, Temp, MAXSIZE - 1, &Number);
			//	string tem = Temp;				
				Astring.push_back(Temp);
				/*cout << Astring[i]<< endl;
					i++;*/
				//Temp[Number] = '\0';
				printf("%s", Temp);
			}
			InternetCloseHandle(hHttp);
			hHttp = NULL;
		}
		InternetCloseHandle(hSession);
		hSession = NULL;
	}
	int a = 0;
}
