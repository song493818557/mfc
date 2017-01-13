#include <windows.h>
#include "resource.h"
#include <tchar.h>

#define DRAW_LINE	1  // 直线
#define DRAW_RECT	2  // 直线
#define DRAW_ELLI	3  // 椭圆

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);

DWORD	g_dwChoose;// 当前选择的几何图案, 1=>直线

POINT	g_begPos; // 开始坐标
POINT	g_endPos; // 结束坐标

HDC		g_hMemDC; // 内存兼容DC
HDC		g_hClientDC; // 窗口客户区DC


int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	DialogBox(hInstance , MAKEINTRESOURCE(IDD_DIALOG1) , 0 , DlgProc);
}

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
{
	static BOOL bIsLbuttonDowm = FALSE;

	switch(uMsg)
	{
		case WM_INITDIALOG:
		{
			g_hClientDC = GetDC(hWnd);
			g_hMemDC = CreateCompatibleDC(g_hClientDC);

			RECT rt;
			GetClientRect(hWnd , &rt);
			HBITMAP hBitmap = CreateCompatibleBitmap(g_hClientDC ,
													 rt.right ,
													 rt.bottom
													 );
			// 将内存兼容位图选入到内存兼容DC中,
			// 如果内存兼容DC上没有内存兼容位图,是无法直接在上面
			// 绘制图案的
			SelectObject(g_hMemDC , hBitmap);

			// 创建一个画刷
			// 把画刷选入到内存兼容DC中,
			HBRUSH hBrush = CreateSolidBrush(RGB(255,255,255));
			// 将画刷选入到内存兼容DC中
			SelectObject(g_hMemDC , hBrush);

			// 使用画矩形的函数,将内存兼容DC的背景刷一遍
			// 在画矩形的过程当中, 函数会使用内存兼容DC中已有的GDI对象
			// 来填充内存.
			Rectangle(g_hMemDC , 0 , 0 , rt.right , rt.bottom);

		}
		break;
		case WM_DESTROY:
		{
			// 释放DC
			DeleteDC(g_hMemDC);
			ReleaseDC(hWnd,g_hClientDC);
		}
		break;

		case WM_COMMAND:
		{
			switch(LOWORD(wParam)) // 判断发出WM_COMMAND的窗口ID
			{
				case IDC_RADIO1:g_dwChoose = DRAW_LINE; break;
				case IDC_RADIO2:g_dwChoose = DRAW_RECT; break;
				case IDC_RADIO3:g_dwChoose = DRAW_ELLI; break;
			}
		}
		break;

		case WM_LBUTTONDOWN:
		{
			bIsLbuttonDowm = TRUE;
			g_begPos.x = LOWORD(lParam);
			g_begPos.y = HIWORD(lParam);
		}
		break;

		case  WM_MOUSEMOVE:
		{
			if(bIsLbuttonDowm)
			{
				g_endPos.x = LOWORD(lParam);
				g_endPos.y = HIWORD(lParam);

				RECT rt;
				GetClientRect(hWnd , &rt);

				// 将内存DC的内容拷贝到窗口DC中
				BitBlt(g_hClientDC ,/*目标DC*/
					   0 , 0 , /*开始坐标*/
					   rt.right , rt.bottom ,/*高和宽*/
					   g_hMemDC ,  /*源DC*/
					   0 , 0 ,/*源DC被拷贝的开始坐标*/
					   SRCCOPY/*只拷贝的标志*/
					   );

				MoveToEx(g_hClientDC , g_begPos.x , g_begPos.y , 0);
				LineTo(g_hClientDC , g_endPos.x , g_endPos.y);
			}
			
		}
		break;

		case WM_LBUTTONUP:
		{
			bIsLbuttonDowm = FALSE;
			g_endPos.x = LOWORD(lParam);
			g_endPos.y = HIWORD(lParam);

			// 现在窗口DC上进行绘制
			switch(g_dwChoose)
			{
				case DRAW_LINE:
					// 先画出直线
					MoveToEx(g_hClientDC , g_begPos.x , g_begPos.y , 0);
					LineTo(g_hClientDC , g_endPos.x , g_endPos.y);
					break;
				case DRAW_RECT:
					Rectangle(g_hClientDC , g_begPos.x , g_begPos.y , g_endPos.x , g_endPos.y);
					break;

				case DRAW_ELLI:
				{
					HBRUSH	hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
					SelectObject(g_hClientDC , hBrush);
					Ellipse(g_hClientDC , g_begPos.x , g_begPos.y , g_endPos.x , g_endPos.y);
				}
				break;
			}


			RECT rt;
			GetClientRect(hWnd , &rt);

			// 将当前窗口DC的内容先保存下来
			// 保存到内存兼容DC中
			// 将DC等比拷贝到另一个DC
			BitBlt(g_hMemDC ,/*目标DC*/
				   0 , 0 , /*开始坐标*/
				   rt.right , rt.bottom ,/*高和宽*/
				   g_hClientDC ,  /*源DC*/
				   0 , 0 ,/*源DC被拷贝的开始坐标*/
				   SRCCOPY/*只拷贝的标志*/
				   );
	
			//使窗口变为无效,不擦除背景
			InvalidateRect(hWnd , NULL , FALSE);
		}
		break;

		case WM_PAINT:
		{
			PAINTSTRUCT ps = {0};
			// 获取无效区域
			BeginPaint(hWnd , &ps);

			RECT rt;
			// 获取客户区大小
			GetClientRect(hWnd , &rt);

			// 将内存DC的内容拷贝到窗口DC中
			BitBlt(g_hClientDC ,/*目标DC*/
				   0 , 0 , /*开始坐标*/
				   rt.right , rt.bottom ,/*高和宽*/
				   g_hMemDC ,  /*源DC*/
				   0 , 0 ,/*源DC被拷贝的开始坐标*/
				   SRCCOPY/*只拷贝的标志*/
				   ); 
			// 将无效区域全部变成有效
			EndPaint(hWnd , &ps);
		}
		break;

		case WM_CLOSE:
		{
			EndDialog(hWnd , 0);
		}
		default:return FALSE;
	}
	return TRUE;
}