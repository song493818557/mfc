#include <windows.h>
#include "resource.h"

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wPraram , LPARAM lParam);

int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	// ͨ��DialogBox��������ģ̬�Ի���
	// ģ̬�Ի�����Ҫ��Ϣѭ��
	DialogBox(hInstance , MAKEINTRESOURCE(IDD_DIALOG1) , NULL , DlgProc);
}

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wPraram , LPARAM lParam)
 {

	 switch(uMsg)
	 {
		 case WM_CLOSE:
			 EndDialog(hWnd , 0);
			 break;


		 // �Ի���ֻ�ܷ���TRUE��FALSE,TRUE�����Ѿ�����Ϣ���д���, FALSE����û�ж���Ϣ����
		 default:
			 return FALSE;
	 }
	 // �Ի���ֻ�ܷ���TRUE��FALSE,TRUE�����Ѿ�����Ϣ���д���, FALSE����û�ж���Ϣ����
	 return TRUE;
}