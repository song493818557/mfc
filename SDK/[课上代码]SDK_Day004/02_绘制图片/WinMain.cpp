#include <windows.h>
#include "resource.h"
#include <tchar.h>


HINSTANCE g_hIns;
INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);


int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	g_hIns = hInstance;
	DialogBox(hInstance , MAKEINTRESOURCE(IDD_DIALOG1) , 0 , DlgProc);
}

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_CLOSE:
			EndDialog(hWnd , 0);

		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			BeginPaint(hWnd , &ps);

			HDC	 hClientDC = GetDC(hWnd);

			// 1. 加载位图,得到位图句柄
			HBITMAP hBitmap = LoadBitmap(g_hIns , MAKEINTRESOURCE(IDB_BITMAP1));

			// 获取位图的宽和高
			BITMAP  bitmapInfo = { 0 };
			GetObject(hBitmap ,sizeof(BITMAP),&bitmapInfo);


			//2. 创建内存兼容DC
			HDC hMemDC = CreateCompatibleDC(hClientDC);
			SelectObject(hMemDC , hBitmap);

			RECT rt;
			GetClientRect(hWnd , &rt);
//			等比拷贝
// 			BitBlt(hClientDC , 0 , 0 , rt.right , rt.bottom,
// 				   hMemDC , 0 , 0 ,
// 				   SRCCOPY
// 				   );

//			拉伸拷贝
// 			StretchBlt(hClientDC , 0 , 0 , rt.right , rt.bottom ,/*目标dc的开始坐标和高宽*/
// 					   hMemDC , 0 , 0 , bitmapInfo.bmWidth , bitmapInfo.bmHeight ,
// 					   SRCCOPY
// 					   );


			// 二. 用位图画刷来绘制图片

			// 从文件中加载位图
			HBITMAP	hbitmap2 = (HBITMAP)LoadImage(g_hIns ,
										 _T("2.bmp") ,/*图片的路径*/
										 IMAGE_BITMAP ,/*图片的类型*/
										 0 , 0 ,/*图片的宽和高*/
										 LR_DEFAULTSIZE | LR_LOADFROMFILE/*使用文件路径,并且使用图片默认大小*/
										 );

			// 创建位图画刷
			HBRUSH	hBrushBitmap = CreatePatternBrush(hbitmap2);

			// 选入一个透明画笔
			SelectObject(hClientDC , GetStockObject(NULL_PEN));

			// 将画刷选入到DC中
			SelectObject(hClientDC , hBrushBitmap);

			// 画矩形(使用位图画刷来填充矩形内部)
			Rectangle(hClientDC , 20 , 20 , 250 , 250);

			EndPaint(hWnd , &ps);
		}
		break;

		default:
			return FALSE;
			break;
	}
	return TRUE;
}