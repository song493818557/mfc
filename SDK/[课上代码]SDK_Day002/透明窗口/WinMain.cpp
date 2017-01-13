#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);

int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{

	WNDCLASS wndClass = { 0 };
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hInstance = GetModuleHandle(NULL);

	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_PEN);
	wndClass.lpszClassName = _T("MyWndClass");

	RegisterClass(&wndClass);


	HWND hWnd = CreateWindowEx(WS_EX_LAYERED ,/*�ڴ���ʱ, ��ӷֲ���չ���,��������ʵ��͸������*/
							   _T("MyWndClass") ,
							   _T("͸������") ,
							   WS_OVERLAPPEDWINDOW ,
							   0 , 0 ,
							   200 , 80,
							   NULL , NULL ,
							   hInstance ,
							   0
							   );

	// ����������Ϊ��͸��
	SetLayeredWindowAttributes(hWnd , 0 , 123 , LWA_ALPHA);


	UpdateWindow(hWnd);
	ShowWindow(hWnd , SW_SHOW);

	
	MSG	msg;
	while(GetMessage(&msg , hWnd , 0 , 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.lParam;

}

LRESULT CALLBACK WndProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_CREATE:
		{
			RECT rt;
			GetClientRect(hWnd , &rt);
			RECT desktopRt;
			GetWindowRect(GetDesktopWindow() , &desktopRt);

			CreateWindow(_T("Button") ,
						 _T("����") ,
						 WS_CHILD | WS_VISIBLE ,
						 0 , 0 ,
						 rt.right , rt.bottom,
						 hWnd ,
						 (HMENU)0x1000 ,  /*��ť��ID*/
						 0 , 0);
				
			// ���ô���λ��
			SetWindowPos(hWnd , 
						 HWND_TOPMOST , /*�ö�*/
						 (desktopRt.right - rt.right) / 2 , /*��Ļ����*/
						 (desktopRt.bottom - rt.bottom) / 2 , /*��Ļ����*/
						 0 , 0 , 
						 SWP_NOSIZE);
		}
		break;

		// ��Ӧ�ؼ���Ϣ
		case WM_COMMAND:
		{
			switch(LOWORD(wParam)) /*�жϿؼ���ID*/
			{
				case 0x1000: // ��ť�ؼ���ID
				{
					// ��ȡ��Դ�������Ĵ��ھ��
					HWND hExplorer = FindWindow(_T("  ") , NULL);
					if(hExplorer)
					{
						// ����Դ�������ĳ�͸��״̬
						// ����ڴ���ʱû�����������,��ʹ��SetWindowLong()����������

						// ��ȡԭ������չ���
						LONG nStyle = ::GetWindowLong(hExplorer , GWL_EXSTYLE);
						// ��ԭ�е���չ�������������µ���չ���
						nStyle = nStyle | WS_EX_LAYERED;
						// ���µ���չ���������
						SetWindowLong(hExplorer , GWL_EXSTYLE , nStyle);
						// ����͸����
						SetLayeredWindowAttributes(hExplorer , 0 , 90 , LWA_ALPHA);
					}
				}
				break;
			}
		}
		break;

		default:
			break;
	}
	if(uMsg == WM_DESTROY)
		ExitProcess(0);

	return DefWindowProc(hWnd , uMsg , wParam , lParam);
}