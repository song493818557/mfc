#pragma once

#include <windows.h>
#include <tchar.h>

#define MAX_CALSSNAME		20  // ������������󳤶�


extern LONG   WND_BORDER;			// ���ڱ߿�Ŀ��
extern LONG   WND_CAPTION_HEIHGT ; // ���ڱ������ĸ߶�


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

	// �ṩ��HWND��ʽת���ĺ���
	operator HWND();

public:
	// ע�ᴰ��
	void RegisterWndClass(const TCHAR* pszClassName, WNDPROC WndProc);

	// ��������
	HWND Create(int x , int y , int width , int height , const TCHAR* pszTitle );

	DWORD Exec();

public:
	DWORD OnCreate(); // ��������ʱ������
	DWORD OnClose();  // �رմ���ʱ������
	DWORD OnDestory();// ���ٴ���ʱ������

	// �ؼ�������Ϣʱ������
	DWORD OnCommand(WPARAM wParam , LPARAM lParam);

	// ����ƶ�ʱ������
	DWORD OnMousemove(LPARAM lParam);
	// ��������ʱ������
	DWORD OnKeyDown(WPARAM wParam);


	// �ޱ߿򴰿���Ҫʵ�ִ��ڵ��ƶ�,������ק�ı��С,�������ӦWM_NCHITTEST��Ϣ
	DWORD OnNCHitTest();

	// �����ػ�ʱ������
	DWORD OnPaint();
	// ���ڴ�С���ı�ʱ���ƶ�
	DWORD OnSize(WPARAM wParam, LPARAM lParam);

};

