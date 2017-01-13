#include <windows.h>
#include "resource.h"
#include <vector>
#include <tchar.h>
#include <Strsafe.h>
using std::vector;

vector<POINT> g_vecPoint = {};

// �ػ���ص�����
INT_PTR CALLBACK DialogProc(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);

// ��ʾͼƬ
INT_PTR CALLBACK ShowPic(HWND   hwndDlg);

// �Ҳ�ͬ
INT_PTR CALLBACK FinDiff(HWND   hwndDlg);

// ȥ��
bool FindNearPoint(POINT &pt);

// ��ʾ��ͬ
void ShowDiff(HWND   hwndDlg);


// ʡ�°�
void DoSimple(HWND   hwndDlg);


int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
	return 0;
}


INT_PTR CALLBACK DialogProc(
	HWND   hwndDlg, UINT   uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		// ��ʾͼƬ
		ShowPic(hwndDlg);
		break;
	case WM_PAINT:
		ShowPic(hwndDlg);
		return 0;
	case WM_CLOSE:
		EndDialog(hwndDlg, 0);
		break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDM_SHOWPIC:
			ShowPic(hwndDlg);
			break;
		case IDM_FINDDIF:
			FinDiff(hwndDlg);
			ShowDiff(hwndDlg);
			break;
		case IDM_SIMPLE:
			DoSimple(hwndDlg);
			break;
		default:
			break;
		}
	}break;
	default:
		return 0;
	}
	return true;
}

// ��ʾͼƬ
INT_PTR CALLBACK ShowPic(HWND hwndDlg)
{
	//HINSTANCE hInstance = GetModuleHandle(0);
	// 1.��������ͼƬ
	HBITMAP hBmpSrc = (HBITMAP)LoadImage(NULL, L"ͼ1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	HBITMAP hBmpDes = (HBITMAP)LoadImage(NULL, L"ͼ2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// 2.��ʾ�ڶԻ�����
	// 2.1��ȡ�ͻ���DC
	HDC hDc = GetDC(hwndDlg);
	// 2.2�ڴ�DC
	HDC hMem = CreateCompatibleDC(hDc);
	// 2.3�ѵ�1��ͼѡ���ڴ�DC
	SelectObject(hMem, hBmpSrc);
	// 2.4��1��ͼ�����Ի�����
	// 2.4.1��ȡͼƬ��С
	BITMAP btInfo = {};
	GetObject(hBmpSrc, sizeof(BITMAP), &btInfo);
	// 2.4.2�����Ի�����
	BitBlt(hDc, 0, 0, btInfo.bmWidth, btInfo.bmHeight, hMem, 0, 0, SRCCOPY);
	// �ѵ�2�������Ի�����
	SelectObject(hMem, hBmpDes);
	BitBlt(hDc, btInfo.bmWidth + 10, 0, btInfo.bmWidth, btInfo.bmHeight, hMem, 0, 0, SRCCOPY);
	// �ͷ���Դ
	ReleaseDC(hwndDlg, hDc);
	DeleteObject(hBmpDes);
	DeleteObject(hBmpSrc);
	return true;
}

// �Ҳ�ͬ
INT_PTR CALLBACK FinDiff(HWND   hwndDlg)
{
	// 1.����ͼƬ���ڻ�ȡͼƬ�ߴ�
	HBITMAP hBmpSrc = (HBITMAP)LoadImage(NULL, L"ͼ1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// 2.��ȡ�ͻ���DC
	HDC hDc = GetDC(hwndDlg);
	// 3.��ȡ���ص�Ƚϣ����ﶼ�ڶԻ�����ȡ��Ƚϣ�Ҳ����һ���ڶԻ���DC��ȡ�㣬һ�����ڴ�DC��ȡ��
	// 3.1�Ƚϵķ�Χ��ͼƬ��С
	BITMAP btInfo = {};
	GetObject(hBmpSrc, sizeof(BITMAP), &btInfo);
	// 3.2��ʼȡ��Ƚ�
	for (int row = 0; row <= btInfo.bmHeight; row += 5)//ÿ���ƶ�5�����ص�
	{
		for (int col = 0; col <= btInfo.bmWidth; col += 5)
		{
			COLORREF src = GetPixel(hDc, col, row);//ͼ1
			COLORREF des = GetPixel(hDc, col + btInfo.bmWidth + 10, row);//ͼ2 ˮƽ�����ͼ1ƫ�� ͼƬ���+10������
			//
			//SetPixel(hDc, col + btInfo.bmWidth + 10, row, RGB(0, 255, 0));
			if (src != des)
			{
				SetPixel(hDc, col, row, RGB(255, 0, 0));
				SetPixel(hDc, col + btInfo.bmWidth + 10, row, RGB(0, 255, 0));
			}
			/*if (!FindNearPoint(POINT{ col, row }))
			{
				g_vecPoint.push_back({ col ,row });
			}*/
			
			//Rectangle(hDc, col, row, col + 5, row + 5);

		}
	}
	// �ͷ���Դ
	DeleteObject(hBmpSrc);
	return true;
}

// ��ʾ��ͬ�ĵ�
void ShowDiff(HWND   hwndDlg)
{
	// ��ȡDC
	HDC hDc = GetDC(hwndDlg);
	// ͸����ˢ
	HBRUSH hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	SelectObject(hDc, hBrush);
	// ��ɫ����
	HPEN hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	SelectObject(hDc, hPen);
	for (POINT &pt : g_vecPoint)
	{
		Ellipse(hDc, pt.x-10, pt.y-10, pt.x + 10, pt.y + 10);
	}
	// �ͷ�DC
	ReleaseDC(hwndDlg, hDc);
}


// ȥ��
bool FindNearPoint(POINT &pt)
{
	for (POINT &each : g_vecPoint)
	{
		//����ȽϽ��Ļ���������һ����
		if ((abs(each.x - pt.x) + abs(each.y - pt.y)) < 100)
		{
			return true;
		}
	}
	return false;
}


// ʡ�°�
void DoSimple(HWND   hwndDlg)
{
	// 1.��������ͼƬ
	HBITMAP hBmpSrc = (HBITMAP)LoadImage(NULL, L"ͼ1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	HBITMAP hBmpDes = (HBITMAP)LoadImage(NULL, L"ͼ2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// 2.��ʾ�ڶԻ�����
	// 2.1��ȡ�ͻ���DC
	HDC hDc = GetDC(hwndDlg);
	// 2.2�ڴ�DC
	HDC hMem = CreateCompatibleDC(hDc);
	// 2.3�ѵ�1��ͼѡ���ڴ�DC
	SelectObject(hMem, hBmpSrc);
	// 2.4��1��ͼ�����Ի�����
	// 2.4.1��ȡͼƬ��С
	BITMAP btInfo = {};
	GetObject(hBmpSrc, sizeof(BITMAP), &btInfo);
	// 2.4.2�����Ի�����
	BitBlt(hDc, 0, 0, btInfo.bmWidth, btInfo.bmHeight, hMem, 0, 0, SRCCOPY);
	// �ѵ�2�������Ի�����
	SelectObject(hMem, hBmpDes);
	BitBlt(hDc, btInfo.bmWidth + 10, 0, btInfo.bmWidth, btInfo.bmHeight, hMem, 0, 0, SRCCOPY);
	// 3. �ص����ˡ��������
	// 3.1 �ѵ�2��ͼƬѡ���ڴ�DC
	SelectObject(hMem, hBmpDes);
	// 3.2 �ͶԻ����ͼ1�Ƚ�
	BitBlt(hDc, 0, 0, btInfo.bmWidth, btInfo.bmHeight, hMem, 0, 0, SRCINVERT);
	// �ͷ���Դ
	ReleaseDC(hwndDlg, hDc);
	DeleteObject(hBmpDes);
	DeleteObject(hBmpSrc);
	return;
}