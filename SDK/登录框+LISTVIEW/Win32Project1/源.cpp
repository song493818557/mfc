#include <windows.h>
#include "resource.h"
#include <tchar.h>


HINSTANCE g_hIns;
INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HDC hdc, hdc1, hdc2;
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	g_hIns = hInstance;
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc);
}

INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDOK:{
			HDC	 hClientDC = GetDC(hWnd);
			// 1. ����λͼ,�õ�λͼ���
			HBITMAP hBitmap = LoadBitmap(g_hIns, MAKEINTRESOURCE(IDB_BITMAP1));
			// ��ȡλͼ�Ŀ�͸�
			BITMAP  bitmapInfo = { 0 };
			GetObject(hBitmap, sizeof(BITMAP), &bitmapInfo);

			//2. �����ڴ����DC
			HDC hMemDC = CreateCompatibleDC(hClientDC);
			SelectObject(hMemDC, hBitmap);
			// ���ڴ�DC�����ݿ���������DC��
			//��ȡ�ͻ����Ĵ�С
			RECT rt;
			GetClientRect(hWnd, &rt);
			BitBlt(hClientDC,/*Ŀ��DC*/
				0, 0, /*��ʼ����*/
				rt.right, rt.bottom,/*�ߺͿ�*/
				hMemDC,  /*ԴDC*/
				0, 0,/*ԴDC�������Ŀ�ʼ����*/
				SRCCOPY/*ֻ�����ı�־*/
				);

		}break;


		}

	}break;
	case WM_CLOSE:{
		ReleaseDC(hWnd, hdc);
		EndDialog(hWnd, 0);
	}break;
	case WM_PAINT:
	{
		HDC	 hClientDC = GetDC(hWnd);
		// 1. ����λͼ,�õ�λͼ���
		HBITMAP hBitmap = LoadBitmap(g_hIns, MAKEINTRESOURCE(IDB_BITMAP1));
		// ��ȡλͼ�Ŀ�͸�
		BITMAP  bitmapInfo = { 0 };
		GetObject(hBitmap, sizeof(BITMAP), &bitmapInfo);

		//2. �����ڴ����DC
		HDC hMemDC = CreateCompatibleDC(hClientDC);
		SelectObject(hMemDC, hBitmap);
		// ���ڴ�DC�����ݿ���������DC��
		//��ȡ�ͻ����Ĵ�С
		RECT rt;
		GetClientRect(hWnd, &rt);
		BitBlt(hClientDC,/*Ŀ��DC*/
			0, 0, /*��ʼ����*/
			rt.right, rt.bottom,/*�ߺͿ�*/
			hMemDC,  /*ԴDC*/
			0, 0,/*ԴDC�������Ŀ�ʼ����*/
			SRCCOPY/*ֻ�����ı�־*/
			);
	}
	default:
		return FALSE;
		break;
	}
	return TRUE;
}