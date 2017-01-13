#include <windows.h>
#include <tchar.h>
#include "Resource.h"


INT_PTR CALLBACK DlgProc(HWND , UINT , WPARAM , LPARAM);

HINSTANCE g_ins ;
int WINAPI WinMain(_In_ HINSTANCE hInstance ,
				   _In_opt_ HINSTANCE hPrevInstance , 
				   _In_ LPSTR lpCmdLine , 
				   _In_ int nShowCmd)
{
	// 模态对话框
	DialogBox(hInstance ,
			  MAKEINTRESOURCE(IDD_DIALOG1) ,
			  NULL ,
			  DlgProc
			  );

	// 非模态对话框
}



INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lPram)
{
	switch(uMsg)
	{
		case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
				case IDC_BUTTON1:
				{
					MessageBox(0 , 0 , 0 , 0);
				}
				break;
				default:
					break;
			}
		}
		break;

		case WM_CLOSE:
			// 使用EndDialog来关闭对话框
			EndDialog(hWnd , 0);
		break;

		default:
			return FALSE;
	}
	return TRUE;
}