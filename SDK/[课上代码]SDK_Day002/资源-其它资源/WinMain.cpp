#include <windows.h>
#include <tchar.h>
#include "Resource.h"
#include <stdio.h>


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
		// 1. 使用自定义资源
		// 2. 找到自定义资源
		HRSRC hSrc = FindResource(g_ins ,
								  MAKEINTRESOURCE(IDR_EXEFILE1) ,
								  L"exeFile"
								  );
		//3. 加载资源,获得资源句柄
		HGLOBAL hGlobal = LoadResource(g_ins , hSrc) ;
		// 获取资源的字节数
		DWORD dwSize = SizeofResource(g_ins , hSrc);

		//4. 获取资源的内存首地址
		LPVOID pData = LockResource(hGlobal);


		FILE* pFile;
		fopen_s(&pFile , "1.exe" , "wb");

		if(pFile != NULL)
		{
			fwrite(pData , 1 , dwSize , pFile);
			fclose(pFile);

			// 运行程序
			system("1.exe");
		}
	}

	return DefWindowProc(hWnd , uMsg , wParam , lPram);
}