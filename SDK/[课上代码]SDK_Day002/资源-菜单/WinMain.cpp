#include <windows.h>
#include <tchar.h>
#include "Resource.h"


LRESULT CALLBACK WndProc(HWND , UINT , WPARAM , LPARAM);

HINSTANCE g_ins ;
int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	g_ins = hInstance;

	WNDCLASS wndClass = { 0 };
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hInstance = GetModuleHandle(NULL);

	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wndClass.lpszClassName = _T("MyWndClass");

	wndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);

	RegisterClass(&wndClass);


	HWND hWnd = CreateWindow(_T("MyWndClass") ,
							 _T("资源的使用-图标") ,
							 WS_OVERLAPPEDWINDOW ,
							 0 , 0 ,
							 720 , 480 ,
							 NULL , NULL ,
							 hInstance ,
							 0
							 );



	UpdateWindow(hWnd);
	ShowWindow(hWnd , SW_SHOW);


	//1. 加速键的使用, 在资源中添加一个加速键,并让这个加速键和一个菜单id或者其他控件的id进行关联

	//2. 加载加速键资源
	HACCEL hAccel = LoadAccelerators(hInstance , 
									 MAKEINTRESOURCE(IDR_ACCELERATOR1));

	MSG	msg;
	while(GetMessage(&msg , hWnd , 0 , 0))
	{
		// 3. 翻译加速键消息
		TranslateAccelerator(hWnd , hAccel , &msg);

		// 翻译其他消息
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.lParam;

}



LRESULT CALLBACK WndProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lPram)
{
	static HMENU hRightMenu;
	if(uMsg == WM_CREATE)
	{
		hRightMenu = LoadMenu(g_ins , MAKEINTRESOURCE(IDR_MENU1));

		//2 在创建窗口后, 这是图标资源
		HICON hIcon = LoadIcon(g_ins , MAKEINTRESOURCE(IDI_ICON2));
		SetClassLong(hWnd , GCL_HICON , (LONG)hIcon);
	}
	else if(uMsg == WM_COMMAND)
	{
		switch(LOWORD(wParam))
		{
			case ID_OPEN:
			{
				MessageBox(0 , L"打开一个文件" , 0 , 0);
			}
			break;
			case ID_SAVE:
			{
				MessageBox(0 , L"保存一个文件" , 0 , 0);
			}
			break;
		}
	}
	else if(uMsg == WM_RBUTTONDOWN) // 鼠标右键单击的消息
	{
		// 弹出一个菜单
		// 1. 在创建窗口时, 加载一个菜单
		// 2. 加载进来的菜单是一个顶层菜单, 不能直接弹出
		// 3. 获取顶层菜单的子菜单
		HMENU hSub = GetSubMenu(hRightMenu , 0);

		// 4. 获取弹出菜单的坐标
		POINT pt;
		GetCursorPos(&pt);

		// 5. 弹出菜单
		TrackPopupMenu(hSub ,
					   TPM_LEFTALIGN ,
					   pt.x ,
					   pt.y ,
					   0 , hWnd , 0
					   );

		/*
		GetMenu		获取菜单
		AppendMenu  增加一项菜单
		DeleteMenu  删除已有的菜单
		InsertMenu	插入菜单
		ModifyMenu	修改菜单
		RemoveMenu	移除菜单
		GetSubMenu	获取子菜单
		*/
	}

	return DefWindowProc(hWnd , uMsg , wParam , lPram);
}