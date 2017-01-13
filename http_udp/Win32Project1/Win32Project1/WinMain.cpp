#include <windows.h>
#include <tchar.h>
#include <mmsystem.h>
#pragma comment(lib,"WINMM.LIB")

#define MAX_LOADSTRING 100
//ȫ�ֱ���
HINSTANCE hInst; //��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];//�������ı�
TCHAR szWindowsclass[MAX_LOADSTRING];//����������
//�˴���ģ���а����ĺ�����ǰ������
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd){

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	//TODO �ڴ˷��ô���
	MSG msg;
	HACCEL hAccelTable;
	//��ʼ��ȫ���ַ���
	LoadString(hInstance,IDS_APP_TITLE,szTitle,MAX_LOADSTRING);
	LoadString(hInstance, IDC_SDK_DAY001_03_, szWindowsclass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
	//ִ��Ӧ�ó����ʼ��
	if (!InitInstance(hInstance,nShowCmd))
	{
		return FALSE;
	}
	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SDK_DAY001_03_));
	//����Ϣѭ��
	while (GetMessage(&msg,NULL,0,0))
	{
		if (!TranslateAccelerator(msg.hwnd,hAccelTable,&msg))
		{
			TranslateMessage(&msg);//�����¼�����
			DispatchMessage(&msg);
		}
		
	}
	return (int)msg.wParam;
}
//
//  ����:  MyRegisterClass()
//
//  Ŀ��:  ע�ᴰ���ࡣ
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
//   ����:  InitInstance(HINSTANCE, int)
//
//   Ŀ��:  ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance;//��ʵ������洢ȫ�ֱ�����
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
//  ����:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
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
		//�����뱣����wParam
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
// �����ڡ������Ϣ�������
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
