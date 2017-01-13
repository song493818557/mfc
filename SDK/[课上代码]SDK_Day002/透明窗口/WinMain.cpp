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


	HWND hWnd = CreateWindowEx(WS_EX_LAYERED ,/*在创建时, 添加分层扩展风格,这样才能实现透明窗口*/
							   _T("MyWndClass") ,
							   _T("透明窗口") ,
							   WS_OVERLAPPEDWINDOW ,
							   0 , 0 ,
							   200 , 80,
							   NULL , NULL ,
							   hInstance ,
							   0
							   );

	// 将窗口设置为半透明
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
						 _T("变变变") ,
						 WS_CHILD | WS_VISIBLE ,
						 0 , 0 ,
						 rt.right , rt.bottom,
						 hWnd ,
						 (HMENU)0x1000 ,  /*按钮的ID*/
						 0 , 0);
				
			// 设置窗口位置
			SetWindowPos(hWnd , 
						 HWND_TOPMOST , /*置顶*/
						 (desktopRt.right - rt.right) / 2 , /*屏幕居中*/
						 (desktopRt.bottom - rt.bottom) / 2 , /*屏幕居中*/
						 0 , 0 , 
						 SWP_NOSIZE);
		}
		break;

		// 响应控件消息
		case WM_COMMAND:
		{
			switch(LOWORD(wParam)) /*判断控件的ID*/
			{
				case 0x1000: // 按钮控件的ID
				{
					// 获取资源管理器的窗口句柄
					HWND hExplorer = FindWindow(_T("  ") , NULL);
					if(hExplorer)
					{
						// 将资源管理器改成透明状态
						// 如果在创建时没有添加这个风格,则使用SetWindowLong()函数来设置

						// 获取原来的扩展风格
						LONG nStyle = ::GetWindowLong(hExplorer , GWL_EXSTYLE);
						// 在原有的扩展风格基础上增加新的扩展风格
						nStyle = nStyle | WS_EX_LAYERED;
						// 将新的扩展风格设置上
						SetWindowLong(hExplorer , GWL_EXSTYLE , nStyle);
						// 设置透明度
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