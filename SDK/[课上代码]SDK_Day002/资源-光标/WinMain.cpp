#include <windows.h>
#include <tchar.h>
#include "Resource.h"


LRESULT CALLBACK WndProc(HWND , UINT , WPARAM , LPARAM);

HINSTANCE g_ins ;
int height;
int width;
int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	g_ins = hInstance;
	WNDCLASS wndClass = { 0 };
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hInstance = GetModuleHandle(NULL);

	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wndClass.lpszClassName = _T("MyWndClass");

	wndClass.hCursor = LoadCursor(hInstance , 
								  MAKEINTRESOURCE(IDC_CURSOR1));

	//1. ʹ����Դ:�ڴ�����������
	 wndClass.hIcon = LoadIcon(hInstance ,
	 						  MAKEINTRESOURCE(IDI_ICON2));


	RegisterClass(&wndClass);


	HWND hWnd = CreateWindow(_T("MyWndClass") ,
							 _T("��Դ��ʹ��-ͼ��") ,
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
		// ͨ��SetClassLong���ı���
		HCURSOR hCursor = LoadCursor(g_ins , 
									 MAKEINTRESOURCE(IDC_CURSOR1));

		SetClassLong(hWnd , GCL_HCURSOR , (LONG)hCursor);
	}

	return DefWindowProc(hWnd , uMsg , wParam , lPram);
}