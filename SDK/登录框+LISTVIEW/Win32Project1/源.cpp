#include <windows.h>
#include "resource.h"
#include <tchar.h>


HINSTANCE g_hIns;
INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HDC hdc, hdc1, hdc2;
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	g_hIns = hInstance;
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc);
}

INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDOK:{
			HDC	 hClientDC = GetDC(hWnd);
			// 1. 加载位图,得到位图句柄
			HBITMAP hBitmap = LoadBitmap(g_hIns, MAKEINTRESOURCE(IDB_BITMAP1));
			// 获取位图的宽和高
			BITMAP  bitmapInfo = { 0 };
			GetObject(hBitmap, sizeof(BITMAP), &bitmapInfo);

			//2. 创建内存兼容DC
			HDC hMemDC = CreateCompatibleDC(hClientDC);
			SelectObject(hMemDC, hBitmap);
			// 将内存DC的内容拷贝到窗口DC中
			//获取客户区的大小
			RECT rt;
			GetClientRect(hWnd, &rt);
			BitBlt(hClientDC,/*目标DC*/
				0, 0, /*开始坐标*/
				rt.right, rt.bottom,/*高和宽*/
				hMemDC,  /*源DC*/
				0, 0,/*源DC被拷贝的开始坐标*/
				SRCCOPY/*只拷贝的标志*/
				);

		}break;


		}

	}break;
	case WM_CLOSE:{
		ReleaseDC(hWnd, hdc);
		EndDialog(hWnd, 0);
	}break;
	case WM_PAINT:
	{
		HDC	 hClientDC = GetDC(hWnd);
		// 1. 加载位图,得到位图句柄
		HBITMAP hBitmap = LoadBitmap(g_hIns, MAKEINTRESOURCE(IDB_BITMAP1));
		// 获取位图的宽和高
		BITMAP  bitmapInfo = { 0 };
		GetObject(hBitmap, sizeof(BITMAP), &bitmapInfo);

		//2. 创建内存兼容DC
		HDC hMemDC = CreateCompatibleDC(hClientDC);
		SelectObject(hMemDC, hBitmap);
		// 将内存DC的内容拷贝到窗口DC中
		//获取客户区的大小
		RECT rt;
		GetClientRect(hWnd, &rt);
		BitBlt(hClientDC,/*目标DC*/
			0, 0, /*开始坐标*/
			rt.right, rt.bottom,/*高和宽*/
			hMemDC,  /*源DC*/
			0, 0,/*源DC被拷贝的开始坐标*/
			SRCCOPY/*只拷贝的标志*/
			);
	}
	default:
		return FALSE;
		break;
	}
	return TRUE;
}