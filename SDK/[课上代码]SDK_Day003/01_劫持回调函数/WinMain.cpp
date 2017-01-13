#include <windows.h>
#include "resource.h"
#include <tchar.h>

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);

INT_PTR CALLBACK ButtonProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);

DLGPROC g_OldButtonProc;

int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	DialogBox(hInstance , MAKEINTRESOURCE(IDD_DIALOG1) , NULL , DlgProc);
}

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
{

	switch(uMsg)
	{
		case WM_CLOSE:
			EndDialog(hWnd , 0);
		break;
		case WM_LBUTTONDOWN:
		{


		}
		case WM_COMMAND:
		{
			if(LOWORD(wParam) == IDOK)
			{
				MessageBox(hWnd , _T("按钮被点击") , _T("提示") , 0);
				
				HWND hButton = GetDlgItem(hWnd , IDOK);

				// 替换消息回调函数
				g_OldButtonProc = (DLGPROC)SetWindowLong(hButton ,
														 GWL_WNDPROC ,
														 (LONG)ButtonProc);
			}
		}
		break;

		default:
			return FALSE;
	}

	return TRUE;
}


INT_PTR CALLBACK ButtonProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_LBUTTONDOWN:
		{
			MessageBox(hWnd , _T("按钮回调函数") , 0 , 0);
			return	TRUE;
		}
		break;

		default:
			break;
	}

	return g_OldButtonProc(hWnd , uMsg , wParam , lParam);

	//return TRUE;
}