#include <windows.h>
#include "resource.h"
#include <tchar.h>


HINSTANCE g_hIns;
INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);


int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	g_hIns = hInstance;
	DialogBox(hInstance , MAKEINTRESOURCE(IDD_DIALOG1) , 0 , DlgProc);
}

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			BeginPaint(hWnd , &ps);

			// 1. TextOut
			HDC	 hDC = GetDC(hWnd);
			TCHAR szStr[] = { _T("hello") };

			// …Ë÷√Œƒ◊÷—’…´
			SetTextColor(hDC , RGB(255,0,0));
			SetBkColor(hDC , RGB(24 , 24 , 24 , ));
			TextOut(hDC , 0 , 0 , szStr , _tcslen(szStr));

			RECT	rt = { 0 , 20 , 300 , 100 };
			GetClientRect(hWnd , &rt);
			DrawText(hDC , szStr , -1 , &rt , DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			EndPaint(hWnd , &ps);
		}
		break;

		case WM_CLOSE:
			EndDialog(hWnd , 0);
		default:return FALSE;
	}
	return TRUE;
}
