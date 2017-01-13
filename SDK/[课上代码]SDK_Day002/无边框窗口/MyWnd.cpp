#include "MyWnd.h"

LONG	WND_BORDER = 414 ;  // ���ڱ߿�Ŀ��
LONG   WND_CAPTION_HEIHGT = 25; // ���ڱ������ĸ߶�

//************************************
// ������: RegisterWndClass
// ��  ��: ע�ᴰ��
// ����ֵ: void
// ��  ��: const TCHAR * pszClassName
// ��  ��: WNDPROC WndProc
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
// ������: MyWnd
// ��  ��: ���캯��
// ����ֵ: 
// ��  ��: HINSTANCE hInstance
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
// ������: Create
// ��  ��: ��������
// ����ֵ: HWND
// ��  ��: int x
// ��  ��: int y
// ��  ��: int width
// ��  ��: int height
// ��  ��: const TCHAR * pszTitle
//************************************
HWND MyWnd::Create(int x , int y , int width , int height , const TCHAR* pszTitle)
{
	m_hWnd = CreateWindow(m_szClassName ,
						pszTitle ,
						WS_POPUP | WS_VISIBLE ,/*ֻѡ�Ի������ʹ����û�б߿�*/
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
// ������: Exec
// ��  ��: ������Ϣѭ��
// ����ֵ: DWORD
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
// ������: OnNCHitTest
// ��  ��: ��WM_NCHITTEST��Ϣ�е���,����ģ��ʵ�ִ��ڵ��ƶ�,��ק�ı��С
// ����ֵ: DWORD
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

	// ģ����ק���� ���ߺ͵ױ�
	// �ĸ���
	if(nMousX - StartPoint.x <= WND_BORDER && nMousY - StartPoint.y <= WND_BORDER) // ���Ͻ�x>=0y<=10
	{
		return HTTOPLEFT;
	}
	else if(nMousX - StartPoint.x >= rect.right - WND_BORDER && nMousY - StartPoint.y <= WND_BORDER)//���Ͻ�
	{
		return	HTTOPRIGHT;
	}
	else if(nMousX - StartPoint.x <= WND_BORDER && nMousY - StartPoint.y >= rect.bottom - WND_BORDER)// ���½�
	{
		return HTBOTTOMLEFT;
	}
	else if(nMousX - StartPoint.x >= rect.right - WND_BORDER && nMousY - StartPoint.y >= rect.bottom - WND_BORDER)
	{
		return	HTBOTTOMRIGHT;
	}
	else if(nMousY - StartPoint.y <= WND_BORDER)  // �����߿�
	{
		return	HTTOP;
	}
	else if(nMousX - StartPoint.x <= WND_BORDER)// ��߿�
	{
		return HTLEFT;
	}
	else if(nMousX - StartPoint.x >= rect.right - WND_BORDER) // �ұ߿�
	{
		return HTRIGHT;
	}
	else if(nMousY - StartPoint.y >= rect.bottom - WND_BORDER) // �ױ߿�
	{
		return HTBOTTOM;
	}


	//	������
	if(GetAsyncKeyState(MK_LBUTTON) < 0)
	{
		if(nMousX >= m_WndSize.width - 30 && nMousY <= 25)
			DestroyWindow(m_hWnd);

		// ���������������,���ж�����ڱ�������
		if(nMousY <= WND_CAPTION_HEIHGT)
			return	HTCAPTION;
	}

	return	25; // 25�������κζ���
}



//************************************
// ������: ��WM_CREATE�е���
// ��  ��: ���ڱ�����ʱ������
// ����ֵ: DWORD
//************************************
DWORD MyWnd::OnCreate()
{
	
	return 1;
}

//************************************
// ������: OnClose
// ��  ��: ��WM_CLOSE�е���
// ����ֵ: DWORD
//************************************
DWORD MyWnd::OnClose()
{
	DestroyWindow(m_hWnd);
	return 1;
}

//************************************
// ������: OnCommand
// ��  ��: ��WM_COMMAND�е���
// ����ֵ: DWORD
// ��  ��: WPARAM wParam
// ��  ��: LPARAM lParam
//************************************
DWORD MyWnd::OnCommand(WPARAM wParam , LPARAM lParam)
{

	return 1;
}

//************************************
// ������: OnMousemove
// ��  ��: ��WM_MOUSEMOVE�е���
// ����ֵ: DWORD
// ��  ��: LPARAM lParam
//************************************
DWORD MyWnd::OnMousemove(LPARAM lParam)
{
	
	return 1;
}



//************************************
// ������: OnPaint
// ��  ��: ��WM_PAINT�е���
// ����ֵ: DWORD
//************************************
DWORD MyWnd::OnPaint()
{
	PAINTSTRUCT ps;
	BeginPaint(m_hWnd , &ps);

	HDC	hdc = GetDC(m_hWnd);

	// ѡ��͸����ˢ
	SelectObject(hdc , GetStockObject(NULL_BRUSH));

	MoveToEx(hdc , 0, 25, NULL);
	LineTo(hdc , m_WndSize.width , 25);

	// ���رհ�ť���Ƴ���
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
// ������: OnKeyDown
// ��  ��: ��WM_KEYDOWN�е���
// ����ֵ: DWORD
// ��  ��: WPARAM wParam
//************************************
DWORD MyWnd::OnKeyDown(WPARAM wParam)
{
	if(wParam == VK_ESCAPE)
		return DestroyWindow(m_hWnd);

	return 0;
}

//************************************
// ������: OnDestory
// ��  ��: ��WM_DESTROY�е���
// ����ֵ: DWORD
//************************************
DWORD MyWnd::OnDestory()
{
	DeleteObject(m_hPen);
	ExitProcess(0);
	return 0;
}

//************************************
// ������: OnSize
// ��  ��: ��WM_SIZE�е���
// ����ֵ: DWORD
// ��  ��: WPARAM wParam
// ��  ��: LPARAM lParam
//************************************
DWORD MyWnd::OnSize(WPARAM wParam , LPARAM lParam)
{
	m_WndSize.height = HIWORD(lParam);
	m_WndSize.width  = LOWORD(lParam);
	return 0;
}




