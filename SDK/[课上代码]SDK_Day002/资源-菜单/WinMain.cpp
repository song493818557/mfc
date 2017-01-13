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
							 _T("��Դ��ʹ��-ͼ��") ,
							 WS_OVERLAPPEDWINDOW ,
							 0 , 0 ,
							 720 , 480 ,
							 NULL , NULL ,
							 hInstance ,
							 0
							 );



	UpdateWindow(hWnd);
	ShowWindow(hWnd , SW_SHOW);


	//1. ���ټ���ʹ��, ����Դ�����һ�����ټ�,����������ټ���һ���˵�id���������ؼ���id���й���

	//2. ���ؼ��ټ���Դ
	HACCEL hAccel = LoadAccelerators(hInstance , 
									 MAKEINTRESOURCE(IDR_ACCELERATOR1));

	MSG	msg;
	while(GetMessage(&msg , hWnd , 0 , 0))
	{
		// 3. ������ټ���Ϣ
		TranslateAccelerator(hWnd , hAccel , &msg);

		// ����������Ϣ
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

		//2 �ڴ������ں�, ����ͼ����Դ
		HICON hIcon = LoadIcon(g_ins , MAKEINTRESOURCE(IDI_ICON2));
		SetClassLong(hWnd , GCL_HICON , (LONG)hIcon);
	}
	else if(uMsg == WM_COMMAND)
	{
		switch(LOWORD(wParam))
		{
			case ID_OPEN:
			{
				MessageBox(0 , L"��һ���ļ�" , 0 , 0);
			}
			break;
			case ID_SAVE:
			{
				MessageBox(0 , L"����һ���ļ�" , 0 , 0);
			}
			break;
		}
	}
	else if(uMsg == WM_RBUTTONDOWN) // ����Ҽ���������Ϣ
	{
		// ����һ���˵�
		// 1. �ڴ�������ʱ, ����һ���˵�
		// 2. ���ؽ����Ĳ˵���һ������˵�, ����ֱ�ӵ���
		// 3. ��ȡ����˵����Ӳ˵�
		HMENU hSub = GetSubMenu(hRightMenu , 0);

		// 4. ��ȡ�����˵�������
		POINT pt;
		GetCursorPos(&pt);

		// 5. �����˵�
		TrackPopupMenu(hSub ,
					   TPM_LEFTALIGN ,
					   pt.x ,
					   pt.y ,
					   0 , hWnd , 0
					   );

		/*
		GetMenu		��ȡ�˵�
		AppendMenu  ����һ��˵�
		DeleteMenu  ɾ�����еĲ˵�
		InsertMenu	����˵�
		ModifyMenu	�޸Ĳ˵�
		RemoveMenu	�Ƴ��˵�
		GetSubMenu	��ȡ�Ӳ˵�
		*/
	}

	return DefWindowProc(hWnd , uMsg , wParam , lPram);
}