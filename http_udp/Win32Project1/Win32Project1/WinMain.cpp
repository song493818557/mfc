#include <windows.h>
#include <tchar.h>
#include <mmsystem.h>
#pragma comment(lib,"WINMM.LIB")

#define MAX_LOADSTRING 100
//全局变量
HINSTANCE hInst; //当前实例
TCHAR szTitle[MAX_LOADSTRING];//标题栏文本
TCHAR szWindowsclass[MAX_LOADSTRING];//主窗口类名
//此代码模块中包含的函数的前向申明
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd){

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	//TODO 在此放置代码
	MSG msg;
	HACCEL hAccelTable;
	//初始化全局字符串
	LoadString(hInstance,IDS_APP_TITLE,szTitle,MAX_LOADSTRING);
	LoadString(hInstance, IDC_SDK_DAY001_03_, szWindowsclass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
	//执行应用程序初始化
	if (!InitInstance(hInstance,nShowCmd))
	{
		return FALSE;
	}
	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SDK_DAY001_03_));
	//主消息循环
	while (GetMessage(&msg,NULL,0,0))
	{
		if (!TranslateAccelerator(msg.hwnd,hAccelTable,&msg))
		{
			TranslateMessage(&msg);//键盘事件解析
			DispatchMessage(&msg);
		}
		
	}
	return (int)msg.wParam;
}
//
//  函数:  MyRegisterClass()
//
//  目的:  注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SDK_DAY001_03_));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_SDK_DAY001_03_);
	wcex.lpszClassName = szWindowsclass;
	wcex.hIconSm = LoadIcon(wcex.hInstance,MAKEINTRESOURCE(IDI_SMALL));
	return RegisterClassEx(&wcex);
}
//
//   函数:  InitInstance(HINSTANCE, int)
//
//   目的:  保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance;//将实例句柄存储全局变量中
	hWnd = CreateWindow(
		szWindowsclass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0, NULL, NULL, hInstance, NULL );
	if (!hWnd)
	{
		return false;
	}
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}
//
//  函数:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmID, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	switch (message)
	{
	case WM_CHAR:
	{
		//按键码保存在wParam
		TCHAR szPath[50] = { _T("Sound\\Sound_A.wav") };
		szPath[12] = wParam;
		PlaySound(szPath, hInst, SND_ASYNC | SND_FILENAME);

	}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)true;
	break;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)true;
		}
		break; 
	}
	return (INT_PTR)TRUE;
}
