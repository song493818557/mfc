#include <windows.h>
#include "resource.h"
#include <tchar.h>
INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK ButtonProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
DLGPROC  g_Old;
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd){
	//模态对话框
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{ 
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == IDC_BUTTON)
		{
			MessageBox(hWnd, _T("模态对话框被触发"), 0,0);
			HWND hButton = GetDlgItem(hWnd, IDC_BUTTON);
			//替换消息函数
			g_Old = (DLGPROC)SetWindowLong(hButton, GWL_WNDPROC, (LONG)ButtonProc);
		}
	} 
	break;
	default:
		return false;
	}
	return true;
}

INT_PTR CALLBACK ButtonProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_LBUTTONDOWN:{ 
		//if (LOWORD(wParam) == IDC_BUTTON)  因为WM_LBUTTONDOWN的WPARAM是和WM_CONMAND的WPARAM不一样的 
			MessageBox(hWnd, _T("劫持对话框被触发"), 0, 0);
			return true;
		 
	}break;
	}
	return g_Old(hWnd, uMsg, wParam, lParam);
}
