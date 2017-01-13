#include <windows.h>
#include "stdafx.h"
#include "resource.h"
#include <winuser.h>
#include <windowsx.h>
#include <windef.h>
INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wPraram, LPARAM lParam);
HWND hDes = FindWindow(NULL, _T("计算器")); 

HWND hCombox;

static int numb = 1;
HINSTANCE g_ins;
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	// 通过DialogBox函数创建模态对话框
	// 模态对话框不需要消息循环
	//窗口创建时 进行遍历需要计算机的控件
	g_ins = hInstance;
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);

	return 0;
}
BOOL CALLBACK WndEnumWindow(HWND hWnd, LPARAM lParam)
{
	 
	if (numb == 3){
		hCombox = hWnd;
		
		return false;
	}
	numb++;
	return TRUE;
}
//************************************
// Method:    OpCalc
// FullName:  OpCalc
// Access:    public 
// 返回值:   INT_PTR CALLBACK
// Qualifier:
// Parameter: HWND hWnd
// Parameter: WPARAM wPraram  高十六位通知码 (菜单0 快捷键1) 低十六位控件ID
// Parameter: LPARAM lParam  句柄
//************************************
INT_PTR CALLBACK OpCalc(HWND hWnd, WPARAM wPraram, LPARAM lParam){
	HWND thwnd;
	WPARAM TEMP;
	switch (LOWORD(wPraram))
	{ 
	case 82:SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X82), (LPARAM)0); break; //0
	case 83:SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X83), (LPARAM)0); break; //1
	case 84:SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X84), (LPARAM)0); break; //2
	case 85:SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X85), (LPARAM)0); break; //3
	case 86:SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X86), (LPARAM)0); break; //4
	case 87:SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X87), (LPARAM)0); break; //5
	case 88:SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X88), (LPARAM)0); break; //6
	case 89:SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X89), (LPARAM)0); break; //7
	case 90:SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0x8a), (LPARAM)0); break; //8
	case A8:SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0x8a), (LPARAM)0); break; //9
	case A9:SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0x8b), (LPARAM)0); break; //0
	case 54:// .
		SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X54), (LPARAM)0); break; //0
	case A5:	// /
		SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X5B), (LPARAM)0); break; //0
	case A6:	//*
		SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X5C), (LPARAM)0); break; //0
	case A7: //-
		SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X5E), (LPARAM)0); break; //0
	case a1:  // +
		SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X5D), (LPARAM)0); break; //+
	case 51: // C
		SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X51), (LPARAM)0); break; //0
	case 53: // ←
		SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X53), (LPARAM)0); break; //0
	case 55: // =
		SendMessage(hDes, WM_COMMAND, (WPARAM)MAKEINTRESOURCE(0X79), (LPARAM)0);  
		//hCombox = GetDlgItem(hDes, 0x00000096);
		//hCombox = (HWND)0X004207FE;
		//hDes = FindWindow(_T("#32770 (对话框)"),NULL );
		//hCombox = GetWindow(hDes, GW_CHILD); 
		//hCombox = (HWND)0X001E09F6; 
		//RECT clientRt;
		//GetWindowRect(hDes, &clientRt);
		//POINT pt1 = { 0 };
		//pt1.x = clientRt.left-100;// -155;
		//pt1.y = clientRt.top - 100;// -122;
		//hCombox = ChildWindowFromPoint(hDes, pt1);
		/*LPRECT pt = {0}; 
		bool aa = GetWindowRect(hDes, pt); 
		//LEFT 155X TOP 122
		//POINT
		hCombox = ChildWindowFromPoint(hDes, pt1);*/
		 
		TCHAR passwd[20];
		GetWindowText(hCombox, passwd, 20); 
		HWND temp = GetDlgItem(hWnd, input);
	
		SetWindowText(temp, passwd);
		break; //0 
	}
	return true;
}


INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wPraram, LPARAM lParam)
{ 
	HICON hIcon;
	switch (uMsg)
	{ 
	case WM_INITDIALOG:
		//1. 找到文本框的句柄
		EnumChildWindows(hDes, WndEnumWindow, (LPARAM)hCombox); 
		hCombox = GetDlgItem(hCombox, 0X96);
		//2 在创建窗口后, 这是图标资源
		hIcon = LoadIcon(g_ins, MAKEINTRESOURCE(IDI_ICON3));
		SetClassLong(hWnd, GCL_HICON, (LONG)hIcon);
		return false;
		break;
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		break;
	case WM_COMMAND:
		OpCalc(hWnd, wPraram, lParam);
		break;
		// 对话框只能返回TRUE和FALSE,TRUE代码已经对消息进行处理, FALSE代表没有对消息处理
	default:
		return FALSE;
	}
	// 对话框只能返回TRUE和FALSE,TRUE代码已经对消息进行处理, FALSE代表没有对消息处理
	return TRUE;
} 