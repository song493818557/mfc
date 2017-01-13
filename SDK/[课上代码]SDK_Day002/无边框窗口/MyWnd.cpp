#include "MyWnd.h"

LONG	WND_BORDER = 414 ;  // 窗口边框的宽度
LONG   WND_CAPTION_HEIHGT = 25; // 窗口标题栏的高度

//************************************
// 函数名: RegisterWndClass
// 功  能: 注册窗口
// 返回值: void
// 参  数: const TCHAR * pszClassName
// 参  数: WNDPROC WndProc
//************************************
void MyWnd::RegisterWndClass(const TCHAR* pszClassName , WNDPROC WndProc)
{
	WNDCLASS wndClass = { 0 };
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hInstance = GetModuleHandle(NULL);

	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wndClass.lpszClassName = pszClassName;

	_tcscpy_s(m_szClassName , MAX_CALSSNAME , pszClassName);
	RegisterClass(&wndClass);
}



//************************************
// 函数名: MyWnd
// 功  能: 构造函数
// 返回值: 
// 参  数: HINSTANCE hInstance
//************************************
MyWnd::MyWnd(HINSTANCE hInstance)
{
	if(hInstance == 0)
		hInstance = GetModuleHandle(NULL);

	m_hInstance = hInstance;

	m_hPen = CreatePen(0 , 1 , RGB(255 , 255 , 255));
}


MyWnd::~MyWnd()
{
}



//************************************
// 函数名: Create
// 功  能: 创建窗口
// 返回值: HWND
// 参  数: int x
// 参  数: int y
// 参  数: int width
// 参  数: int height
// 参  数: const TCHAR * pszTitle
//************************************
HWND MyWnd::Create(int x , int y , int width , int height , const TCHAR* pszTitle)
{
	m_hWnd = CreateWindow(m_szClassName ,
						pszTitle ,
						WS_POPUP | WS_VISIBLE ,/*只选对话框风格会使窗口没有边框*/
						x , y ,
						width , height ,
						NULL , NULL ,
						m_hInstance ,
						0
						);

	UpdateWindow(m_hWnd);
	ShowWindow(m_hWnd , SW_SHOW);
	return m_hWnd;
}

//************************************
// 函数名: Exec
// 功  能: 运行消息循环
// 返回值: DWORD
//************************************
DWORD MyWnd::Exec()
{
	MSG	msg;
	while(GetMessage(&msg , m_hWnd , 0 , 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.lParam;
}


MyWnd::operator HWND()
{
	return m_hWnd;
}


//************************************
// 函数名: OnNCHitTest
// 功  能: 在WM_NCHITTEST消息中调用,用于模拟实现窗口的移动,拖拽改变大小
// 返回值: DWORD
//************************************
DWORD MyWnd::OnNCHitTest()
{
	POINT point ;
	GetCursorPos(&point);

	RECT rect = { 0 };
	::GetClientRect(m_hWnd , &rect);
	POINT StartPoint = { 0 };

	ScreenToClient(m_hWnd , &point);
	LONG nMousX = point.x;
	LONG nMousY = point.y;

	// 模拟拖拽窗口 两边和底边
	// 四个角
	if(nMousX - StartPoint.x <= WND_BORDER && nMousY - StartPoint.y <= WND_BORDER) // 左上角x>=0y<=10
	{
		return HTTOPLEFT;
	}
	else if(nMousX - StartPoint.x >= rect.right - WND_BORDER && nMousY - StartPoint.y <= WND_BORDER)//右上角
	{
		return	HTTOPRIGHT;
	}
	else if(nMousX - StartPoint.x <= WND_BORDER && nMousY - StartPoint.y >= rect.bottom - WND_BORDER)// 左下角
	{
		return HTBOTTOMLEFT;
	}
	else if(nMousX - StartPoint.x >= rect.right - WND_BORDER && nMousY - StartPoint.y >= rect.bottom - WND_BORDER)
	{
		return	HTBOTTOMRIGHT;
	}
	else if(nMousY - StartPoint.y <= WND_BORDER)  // 顶部边框
	{
		return	HTTOP;
	}
	else if(nMousX - StartPoint.x <= WND_BORDER)// 左边框
	{
		return HTLEFT;
	}
	else if(nMousX - StartPoint.x >= rect.right - WND_BORDER) // 右边框
	{
		return HTRIGHT;
	}
	else if(nMousY - StartPoint.y >= rect.bottom - WND_BORDER) // 底边框
	{
		return HTBOTTOM;
	}


	//	标题栏
	if(GetAsyncKeyState(MK_LBUTTON) < 0)
	{
		if(nMousX >= m_WndSize.width - 30 && nMousY <= 25)
			DestroyWindow(m_hWnd);

		// 如果鼠标在这个区间,则判定鼠标在标题栏中
		if(nMousY <= WND_CAPTION_HEIHGT)
			return	HTCAPTION;
	}

	return	25; // 25不代表任何东西
}



//************************************
// 函数名: 在WM_CREATE中调用
// 功  能: 窗口被创建时被调用
// 返回值: DWORD
//************************************
DWORD MyWnd::OnCreate()
{
	
	return 1;
}

//************************************
// 函数名: OnClose
// 功  能: 在WM_CLOSE中调用
// 返回值: DWORD
//************************************
DWORD MyWnd::OnClose()
{
	DestroyWindow(m_hWnd);
	return 1;
}

//************************************
// 函数名: OnCommand
// 功  能: 在WM_COMMAND中调用
// 返回值: DWORD
// 参  数: WPARAM wParam
// 参  数: LPARAM lParam
//************************************
DWORD MyWnd::OnCommand(WPARAM wParam , LPARAM lParam)
{

	return 1;
}

//************************************
// 函数名: OnMousemove
// 功  能: 在WM_MOUSEMOVE中调用
// 返回值: DWORD
// 参  数: LPARAM lParam
//************************************
DWORD MyWnd::OnMousemove(LPARAM lParam)
{
	
	return 1;
}



//************************************
// 函数名: OnPaint
// 功  能: 在WM_PAINT中调用
// 返回值: DWORD
//************************************
DWORD MyWnd::OnPaint()
{
	PAINTSTRUCT ps;
	BeginPaint(m_hWnd , &ps);

	HDC	hdc = GetDC(m_hWnd);

	// 选择透明画刷
	SelectObject(hdc , GetStockObject(NULL_BRUSH));

	MoveToEx(hdc , 0, 25, NULL);
	LineTo(hdc , m_WndSize.width , 25);

	// 将关闭按钮绘制出来
	SelectObject(hdc , m_hPen);
	Rectangle(hdc ,  m_WndSize.width - 30 ,1 ,m_WndSize.width - 1 ,25);

	MoveToEx(hdc , m_WndSize.width - 30 , 1 , NULL);
	LineTo(hdc , m_WndSize.width - 1 , 25);

	MoveToEx(hdc , m_WndSize.width - 30 , 25 , NULL);
	LineTo(hdc , m_WndSize.width - 1 , 1);


	EndPaint(m_hWnd , &ps);
	return 0;
}

//************************************
// 函数名: OnKeyDown
// 功  能: 在WM_KEYDOWN中调用
// 返回值: DWORD
// 参  数: WPARAM wParam
//************************************
DWORD MyWnd::OnKeyDown(WPARAM wParam)
{
	if(wParam == VK_ESCAPE)
		return DestroyWindow(m_hWnd);

	return 0;
}

//************************************
// 函数名: OnDestory
// 功  能: 在WM_DESTROY中调用
// 返回值: DWORD
//************************************
DWORD MyWnd::OnDestory()
{
	DeleteObject(m_hPen);
	ExitProcess(0);
	return 0;
}

//************************************
// 函数名: OnSize
// 功  能: 在WM_SIZE中调用
// 返回值: DWORD
// 参  数: WPARAM wParam
// 参  数: LPARAM lParam
//************************************
DWORD MyWnd::OnSize(WPARAM wParam , LPARAM lParam)
{
	m_WndSize.height = HIWORD(lParam);
	m_WndSize.width  = LOWORD(lParam);
	return 0;
}




