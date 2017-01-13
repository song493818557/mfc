#include <windows.h>
#include "MyWnd.h"

#define WND_TITLE  _T("无边框窗口")


LRESULT CALLBACK WndProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);

MyWnd	g_Wnd; 

int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	g_Wnd.RegisterWndClass(_T("MyWndClass") , WndProc);
	g_Wnd.Create(100 , 100 , 720 , 480 ,WND_TITLE);
	g_Wnd.Exec();
}


LRESULT CALLBACK WndProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_CREATE:
			g_Wnd.OnCreate();
			break;

		case WM_COMMAND:
			if(g_Wnd.OnCommand(wParam , lParam))
				return 1;
			break;

		case WM_SIZE:
			if(g_Wnd.OnSize(wParam , lParam))
				return 1;
			break;

		case WM_PAINT:
			if(g_Wnd.OnPaint())
				return 1;
			break;

		case WM_KEYDOWN:
			if(g_Wnd.OnKeyDown(wParam))
				return 1;
			break;


		case WM_MOUSEMOVE:
			if(g_Wnd.OnMousemove(lParam))
				return 1;
			break;

		case WM_NCHITTEST: // 模拟无边框窗口的移动,改变大小的消息
			return g_Wnd.OnNCHitTest();
			break;

		case WM_CLOSE:
			if(g_Wnd.OnClose())
				return 1;
			break;

		case WM_DESTROY:
			if(g_Wnd.OnDestory())
				return 1;
			break;
	}

	return DefWindowProc(hWnd , uMsg , wParam , lParam);
}