#include <windows.h>
#include "resource.h"

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wPraram , LPARAM lParam);

int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	// ʹ��CreateDialog��������ģ̬�Ի���
	HWND hWnd = CreateDialog(hInstance , 
							 MAKEINTRESOURCE(IDD_DIALOG1) , 
							 NULL , 
							 DlgProc);

	// ��ģ̬�Ի�����Ҫ�ֶ����´���,��ʾ����
	UpdateWindow(hWnd);
	ShowWindow(hWnd , SW_SHOW);


	// ��ģ̬�Ի�����Ҫ�ֶ��ı�д��Ϣѭ��
	MSG msg;
	while(GetMessage(&msg,hWnd,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wPraram , LPARAM lParam)
{
	switch(uMsg)
	{


		// ��ģ̬�Ի������ֶ�����DestroyWindow���ٴ���
		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;	

	
		case WM_DESTROY:
			ExitProcess(0);
			break;

		// �Ի���ֻ�ܷ���TRUE��FALSE,TRUE�����Ѿ�����Ϣ���д���, FALSE����û�ж���Ϣ����
		default:
			return FALSE;
	}

	// �Ի���ֻ�ܷ���TRUE��FALSE,TRUE�����Ѿ�����Ϣ���д���, FALSE����û�ж���Ϣ����
	return TRUE;
}