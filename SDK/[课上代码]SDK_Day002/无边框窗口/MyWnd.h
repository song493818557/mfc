#pragma once

#include <windows.h>
#include <tchar.h>

#define MAX_CALSSNAME		20  // 窗口类名的最大长度


extern LONG   WND_BORDER;			// 窗口边框的宽度
extern LONG   WND_CAPTION_HEIHGT ; // 窗口标题栏的高度


typedef	struct WNDSIZE
{
	LONG width;
	LONG height;
}WNDSIZE , *PWNDSIZE;


class MyWnd
{
	HINSTANCE m_hInstance;
	HWND	  m_hWnd;
	TCHAR	  m_szClassName[ MAX_CALSSNAME ];

	WNDSIZE	  m_WndSize;

private:
	HPEN	  m_hPen;
private:
	

public:
	MyWnd(HINSTANCE hInstance=0) ;
	~MyWnd();


public:

	// 提供对HWND隐式转换的函数
	operator HWND();

public:
	// 注册窗口
	void RegisterWndClass(const TCHAR* pszClassName, WNDPROC WndProc);

	// 创建窗口
	HWND Create(int x , int y , int width , int height , const TCHAR* pszTitle );

	DWORD Exec();

public:
	DWORD OnCreate(); // 创建窗口时被调用
	DWORD OnClose();  // 关闭窗口时被调用
	DWORD OnDestory();// 销毁窗口时被调用

	// 控件产生消息时被调用
	DWORD OnCommand(WPARAM wParam , LPARAM lParam);

	// 鼠标移动时被调用
	DWORD OnMousemove(LPARAM lParam);
	// 按键按下时被调用
	DWORD OnKeyDown(WPARAM wParam);


	// 无边框窗口想要实现窗口的移动,窗口拖拽改变大小,则必须响应WM_NCHITTEST消息
	DWORD OnNCHitTest();

	// 窗口重绘时被调用
	DWORD OnPaint();
	// 窗口大小被改变时被移动
	DWORD OnSize(WPARAM wParam, LPARAM lParam);

};

