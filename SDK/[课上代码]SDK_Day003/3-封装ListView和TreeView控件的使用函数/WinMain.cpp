#include <windows.h>
#include "resource.h"
#include <tchar.h>
#include "MyListView.h"

// 1. 导入头文件
#include <commctrl.h>
// 2. 导入静态库
#pragma comment(lib,"comctl32.lib")

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);

void OnInitDialog(HWND hWnd);

HINSTANCE g_hIns ;
MyListView g_myListView;

int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	g_hIns = hInstance;
	DialogBox(hInstance , MAKEINTRESOURCE(IDD_DIALOG1) , NULL , DlgProc);
}


INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_INITDIALOG:
		{
			InitCommonControls();

			g_myListView.Create(IDC_LIST1,hWnd, 0, 0, 300, 200);
			g_myListView.InsertColumn(0 , _T("姓名") , 80);
			g_myListView.InsertColumn(1 , _T("年龄") , 80);

			g_myListView.InsertItem(0,0, _T("网大椎"));
			DWORD dwAge = 18;
			g_myListView.SetItemText(0 , 1 , dwAge);
		}
		break;

		case WM_CLOSE:
			EndDialog(hWnd , 0);
		default:
			return FALSE;
			break;
	}
	return TRUE;
}