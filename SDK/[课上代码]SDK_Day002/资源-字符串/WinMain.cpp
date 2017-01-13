#include <windows.h>
#include <tchar.h>
#include "Resource.h"


LRESULT CALLBACK WndProc(HWND , UINT , WPARAM , LPARAM);

HINSTANCE g_ins ;
int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	g_ins = hInstance;

	WNDCLASS wndClass = { 0 };
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hInstance = GetModuleHandle(NULL);

	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wndClass.lpszClassName = _T("MyWndClass");

	//1. 使用资源:在窗口类中设置
	// wndClass.hIcon = LoadIcon(hInstance ,
	// 						  MAKEINTRESOURCE(IDI_ICON2));


	RegisterClass(&wndClass);


	HWND hWnd = CreateWindow(_T("MyWndClass") ,
							 _T("资源的使用-图标") ,
							 WS_OVERLAPPEDWINDOW ,
							 0 , 0 ,
							 720 , 480 ,
							 NULL , NULL ,
							 hInstance ,
							 0
							 );



	UpdateWindow(hWnd);
	ShowWindow(hWnd , SW_SHOW);


	MSG	msg;
	while(GetMessage(&msg , hWnd , 0 , 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.lParam;

}



LRESULT CALLBACK WndProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lPram)
{
	if(uMsg == WM_CREATE)
	{

		TCHAR ButtonName[ 50 ];
		LoadString(g_ins ,
				   IDS_STRING103 ,
				   ButtonName ,
				   50);

		CreateWindow(L"Button" ,
					 ButtonName ,
					 WS_CHILD | WS_VISIBLE ,
					 0 , 0 ,
					 120 , 30 ,
					 hWnd ,
					 (HMENU)0x1000 ,
					 0 , 0
					 );
	}
	else if(uMsg == WM_COMMAND)
	{
		if(LOWORD(wParam) == 0x1000)
		{
			LANGID langid = MAKELANGID(LANG_ENGLISH , SUBLANG_ENGLISH_US);
			SetThreadUILanguage(langid);


			TCHAR ButtonName[ 50 ];
			LoadString(g_ins ,
					   IDS_STRING103 ,
					   ButtonName ,
					   50);

			SetWindowText(GetDlgItem(hWnd , 0x1000) , ButtonName);
		}
	}
	return DefWindowProc(hWnd , uMsg , wParam , lPram);
}