#include <windows.h>
#include "resource.h"
#include <tchar.h>
INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK ButtonProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
DLGPROC  g_Old;
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd){
	//ģ̬�Ի���
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
			MessageBox(hWnd, _T("ģ̬�Ի��򱻴���"), 0,0);
			HWND hButton = GetDlgItem(hWnd, IDC_BUTTON);
			//�滻��Ϣ����
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
		//if (LOWORD(wParam) == IDC_BUTTON)  ��ΪWM_LBUTTONDOWN��WPARAM�Ǻ�WM_CONMAND��WPARAM��һ���� 
			MessageBox(hWnd, _T("�ٳֶԻ��򱻴���"), 0, 0);
			return true;
		 
	}break;
	}
	return g_Old(hWnd, uMsg, wParam, lParam);
}
