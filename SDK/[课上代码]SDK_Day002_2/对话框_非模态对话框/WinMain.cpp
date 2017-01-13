#include <windows.h>
#include "resource.h"

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wPraram , LPARAM lParam);

int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	// 使用CreateDialog来创建非模态对话框
	HWND hWnd = CreateDialog(hInstance , 
							 MAKEINTRESOURCE(IDD_DIALOG1) , 
							 NULL , 
							 DlgProc);

	// 非模态对话框需要手动更新窗口,显示窗口
	UpdateWindow(hWnd);
	ShowWindow(hWnd , SW_SHOW);


	// 非模态对话框需要手动的编写消息循环
	MSG msg;
	while(GetMessage(&msg,hWnd,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wPraram , LPARAM lParam)
{
	switch(uMsg)
	{


		// 非模态对话框不能手动调用DestroyWindow销毁窗口
		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;	

	
		case WM_DESTROY:
			ExitProcess(0);
			break;

		// 对话框只能返回TRUE和FALSE,TRUE代码已经对消息进行处理, FALSE代表没有对消息处理
		default:
			return FALSE;
	}

	// 对话框只能返回TRUE和FALSE,TRUE代码已经对消息进行处理, FALSE代表没有对消息处理
	return TRUE;
}