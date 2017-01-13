#include <windows.h>
#include "resource.h"
#include <tchar.h>


HINSTANCE g_hIns;
INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);


int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	g_hIns = hInstance;
	DialogBox(hInstance , MAKEINTRESOURCE(IDD_DIALOG1) , 0 , DlgProc);
}

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_CLOSE:
			EndDialog(hWnd , 0);

		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			BeginPaint(hWnd , &ps);

			HDC	 hClientDC = GetDC(hWnd);

			// 1. ����λͼ,�õ�λͼ���
			HBITMAP hBitmap = LoadBitmap(g_hIns , MAKEINTRESOURCE(IDB_BITMAP1));

			// ��ȡλͼ�Ŀ�͸�
			BITMAP  bitmapInfo = { 0 };
			GetObject(hBitmap ,sizeof(BITMAP),&bitmapInfo);


			//2. �����ڴ����DC
			HDC hMemDC = CreateCompatibleDC(hClientDC);
			SelectObject(hMemDC , hBitmap);

			RECT rt;
			GetClientRect(hWnd , &rt);
//			�ȱȿ���
// 			BitBlt(hClientDC , 0 , 0 , rt.right , rt.bottom,
// 				   hMemDC , 0 , 0 ,
// 				   SRCCOPY
// 				   );

//			���쿽��
// 			StretchBlt(hClientDC , 0 , 0 , rt.right , rt.bottom ,/*Ŀ��dc�Ŀ�ʼ����͸߿�*/
// 					   hMemDC , 0 , 0 , bitmapInfo.bmWidth , bitmapInfo.bmHeight ,
// 					   SRCCOPY
// 					   );


			// ��. ��λͼ��ˢ������ͼƬ

			// ���ļ��м���λͼ
			HBITMAP	hbitmap2 = (HBITMAP)LoadImage(g_hIns ,
										 _T("2.bmp") ,/*ͼƬ��·��*/
										 IMAGE_BITMAP ,/*ͼƬ������*/
										 0 , 0 ,/*ͼƬ�Ŀ�͸�*/
										 LR_DEFAULTSIZE | LR_LOADFROMFILE/*ʹ���ļ�·��,����ʹ��ͼƬĬ�ϴ�С*/
										 );

			// ����λͼ��ˢ
			HBRUSH	hBrushBitmap = CreatePatternBrush(hbitmap2);

			// ѡ��һ��͸������
			SelectObject(hClientDC , GetStockObject(NULL_PEN));

			// ����ˢѡ�뵽DC��
			SelectObject(hClientDC , hBrushBitmap);

			// ������(ʹ��λͼ��ˢ���������ڲ�)
			Rectangle(hClientDC , 20 , 20 , 250 , 250);

			EndPaint(hWnd , &ps);
		}
		break;

		default:
			return FALSE;
			break;
	}
	return TRUE;
}