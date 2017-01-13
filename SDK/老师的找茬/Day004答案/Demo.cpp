#include <windows.h>
#include "resource.h"
#include <vector>
#include <tchar.h>
#include <Strsafe.h>
using std::vector;

vector<POINT> g_vecPoint = {};

// 回话框回调函数
INT_PTR CALLBACK DialogProc(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);

// 显示图片
INT_PTR CALLBACK ShowPic(HWND   hwndDlg);

// 找不同
INT_PTR CALLBACK FinDiff(HWND   hwndDlg);

// 去重
bool FindNearPoint(POINT &pt);

// 显示不同
void ShowDiff(HWND   hwndDlg);


// 省事版
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
		// 显示图片
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

// 显示图片
INT_PTR CALLBACK ShowPic(HWND hwndDlg)
{
	//HINSTANCE hInstance = GetModuleHandle(0);
	// 1.加载两个图片
	HBITMAP hBmpSrc = (HBITMAP)LoadImage(NULL, L"图1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	HBITMAP hBmpDes = (HBITMAP)LoadImage(NULL, L"图2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// 2.显示在对话框上
	// 2.1获取客户区DC
	HDC hDc = GetDC(hwndDlg);
	// 2.2内存DC
	HDC hMem = CreateCompatibleDC(hDc);
	// 2.3把第1个图选入内存DC
	SelectObject(hMem, hBmpSrc);
	// 2.4第1个图贴到对话框上
	// 2.4.1获取图片大小
	BITMAP btInfo = {};
	GetObject(hBmpSrc, sizeof(BITMAP), &btInfo);
	// 2.4.2贴到对话框上
	BitBlt(hDc, 0, 0, btInfo.bmWidth, btInfo.bmHeight, hMem, 0, 0, SRCCOPY);
	// 把第2个贴到对话框上
	SelectObject(hMem, hBmpDes);
	BitBlt(hDc, btInfo.bmWidth + 10, 0, btInfo.bmWidth, btInfo.bmHeight, hMem, 0, 0, SRCCOPY);
	// 释放资源
	ReleaseDC(hwndDlg, hDc);
	DeleteObject(hBmpDes);
	DeleteObject(hBmpSrc);
	return true;
}

// 找不同
INT_PTR CALLBACK FinDiff(HWND   hwndDlg)
{
	// 1.加载图片用于获取图片尺寸
	HBITMAP hBmpSrc = (HBITMAP)LoadImage(NULL, L"图1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// 2.获取客户区DC
	HDC hDc = GetDC(hwndDlg);
	// 3.获取像素点比较，这里都在对话框上取点比较，也可以一个在对话框DC上取点，一个在内存DC上取点
	// 3.1比较的范围是图片大小
	BITMAP btInfo = {};
	GetObject(hBmpSrc, sizeof(BITMAP), &btInfo);
	// 3.2开始取点比较
	for (int row = 0; row <= btInfo.bmHeight; row += 5)//每次移动5个像素点
	{
		for (int col = 0; col <= btInfo.bmWidth; col += 5)
		{
			COLORREF src = GetPixel(hDc, col, row);//图1
			COLORREF des = GetPixel(hDc, col + btInfo.bmWidth + 10, row);//图2 水平坐标比图1偏右 图片宽度+10个像素
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
	// 释放资源
	DeleteObject(hBmpSrc);
	return true;
}

// 显示不同的点
void ShowDiff(HWND   hwndDlg)
{
	// 获取DC
	HDC hDc = GetDC(hwndDlg);
	// 透明画刷
	HBRUSH hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	SelectObject(hDc, hBrush);
	// 红色画笔
	HPEN hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	SelectObject(hDc, hPen);
	for (POINT &pt : g_vecPoint)
	{
		Ellipse(hDc, pt.x-10, pt.y-10, pt.x + 10, pt.y + 10);
	}
	// 释放DC
	ReleaseDC(hwndDlg, hDc);
}


// 去重
bool FindNearPoint(POINT &pt)
{
	for (POINT &each : g_vecPoint)
	{
		//两点比较近的话，看成是一个点
		if ((abs(each.x - pt.x) + abs(each.y - pt.y)) < 100)
		{
			return true;
		}
	}
	return false;
}


// 省事版
void DoSimple(HWND   hwndDlg)
{
	// 1.加载两个图片
	HBITMAP hBmpSrc = (HBITMAP)LoadImage(NULL, L"图1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	HBITMAP hBmpDes = (HBITMAP)LoadImage(NULL, L"图2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// 2.显示在对话框上
	// 2.1获取客户区DC
	HDC hDc = GetDC(hwndDlg);
	// 2.2内存DC
	HDC hMem = CreateCompatibleDC(hDc);
	// 2.3把第1个图选入内存DC
	SelectObject(hMem, hBmpSrc);
	// 2.4第1个图贴到对话框上
	// 2.4.1获取图片大小
	BITMAP btInfo = {};
	GetObject(hBmpSrc, sizeof(BITMAP), &btInfo);
	// 2.4.2贴到对话框上
	BitBlt(hDc, 0, 0, btInfo.bmWidth, btInfo.bmHeight, hMem, 0, 0, SRCCOPY);
	// 把第2个贴到对话框上
	SelectObject(hMem, hBmpDes);
	BitBlt(hDc, btInfo.bmWidth + 10, 0, btInfo.bmWidth, btInfo.bmHeight, hMem, 0, 0, SRCCOPY);
	// 3. 重点来了★★★★★★★★
	// 3.1 把第2张图片选入内存DC
	SelectObject(hMem, hBmpDes);
	// 3.2 和对话框的图1比较
	BitBlt(hDc, 0, 0, btInfo.bmWidth, btInfo.bmHeight, hMem, 0, 0, SRCINVERT);
	// 释放资源
	ReleaseDC(hwndDlg, hDc);
	DeleteObject(hBmpDes);
	DeleteObject(hBmpSrc);
	return;
}