// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <winuser.h>
#include <stdio.h>
#include <fstream>
#include <iosfwd>
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	
	HWND hWnd; 
	hWnd = (HWND)0x00031320;
	/*
	月亮代表我的心
	LOQSONQS STUVTS QPOOO QPOOO PQPOMPQP
	LOQSONQS STUVTS QPOOO QPOOO PQPMNOPO
	QSQPOSN MNMNMLQ SQPOSN MNOOOPQP
	LOQSONQS STUVTS QPOOO QPOOO PQPMNOPO
	 */ 
	//查找窗口句柄
	
	HWND hDes = FindWindow(_T("WIN32PROJECT3") , _T("Win32Project3")); 
	//char buffer[256];  
		//从文件输入
		fstream fobjInFile;
		fobjInFile.open("C:\\a\\key.txt", ios::in); 
		if (!fobjInFile) { cout << "key.txt can't open.\n"; abort(); fobjInFile.rdbuf(); }
		char cChar;
		while (fobjInFile.get(cChar)){
			 
			if (cChar != ' ') SendMessage(hDes, WM_CHAR, cChar, 0);
			Sleep(900);
		}
			//wcout.put(cChar);
		 
		fobjInFile.close();
	
	 
	return 0;
}

