#include <windows.h>
#include "resource.h"

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wPraram , LPARAM lParam);

int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	// 通过DialogBox函数创建模态对话框
	// 模态对话框不需要消息循环
	DialogBox(hInstance , MAKEINTRESOURCE(IDD_DIALOG1) , NULL , DlgProc);
}

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wPraram , LPARAM lParam)
 {

	 switch(uMsg)
	 {
		 case WM_CLOSE:
			 EndDialog(hWnd , 0);
			 break;


		 // 对话框只能返回TRUE和FALSE,TRUE代码已经对消息进行处理, FALSE代表没有对消息处理
		 default:
			 return FALSE;
	 }
	 // 对话框只能返回TRUE和FALSE,TRUE代码已经对消息进行处理, FALSE代表没有对消息处理
	 return TRUE;
}