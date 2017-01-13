#include <windows.h>
#include "resource.h"
#include <tchar.h>
#include <commctrl.h>
#include <windowsx.h>   
#include <CommCtrl.h>
#include <afxres.h>
#pragma comment(lib,"comctl32.lib")

HINSTANCE g_ins; 
TCHAR g_title[3][50] = {0};
TCHAR g_region[][10] = { _T("艾欧尼亚"), _T("诺克萨斯"), _T("皮尔沃特夫"), _T("裁决圣地"), _T("黑色玫瑰") };
HWND hDlg2;
int g_selself = 0; //初始化当前
INT_PTR CALLBACK MainDlg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK DlgProc2(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
bool OnInitDialog2(HWND hWnd);
bool OnInitDialog1(HWND hWnd);
bool OnCommand(HWND hWnd, DWORD dwID);
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd){
	g_ins = hInstance;
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1),NULL,MainDlg); 
}

INT_PTR CALLBACK MainDlg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{ 
		case WM_INITDIALOG: //对话框被初始化的消息  有且只有一次
		{
			//SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)GetStockObject(BLACK_BRUSH));
			//PAINTSTRUCT ps;
			//BeginPaint(hWnd, &ps); 
			//HDC	hdc = GetDC(hWnd); 
			//// 选择透明画刷
			//SelectObject(hdc, GetStockObject(BLACK_BRUSH
			//	));
			//MoveToEx(hdc, 0, 25, NULL);
			//LineTo(hdc, width, 25); 
			//// 将关闭按钮绘制出来
			//SelectObject(hdc, hWnd);
			//Rectangle(hdc, width - 30, 1, width - 1, 25);

			//MoveToEx(hdc, width - 30, 1, NULL);
			//LineTo(hdc,width - 1, 25);

			//MoveToEx(hdc, width - 30, 25, NULL);
			//LineTo(hdc, width - 1, 1); 
			//EndPaint(hWnd, &ps);

			return OnInitDialog1(hWnd);
		}
		break;
		case WM_COMMAND: return OnCommand(hWnd, LOWORD(wParam));
		 
		case WM_CLOSE:
			EndDialog(hWnd, 0);
			break;  
		default:
			return FALSE;
			break;
	}
	return 0;
}

bool OnInitDialog1(HWND hWnd)
{
	//给下拉框添加字符串
	HWND hCombox = GetDlgItem(hWnd, IDC_COMBO1);
	//ComboBox_InsertString(hWnd, 0, _T("请选择分区"));
	
	//添加字符串到下拉框
	for (int i = 0; i < _countof(g_region);i++)
	{
		SendMessage(hCombox, CB_INSERTSTRING, -1, (LPARAM)g_region[i]);
	} 
	HICON hIcon = LoadIcon(g_ins, MAKEINTRESOURCE(IDI_ICON1));
	SetClassLong(hWnd, GCL_HICON, (LONG)hIcon); 
	//设置当前被选中
	SendMessage(hCombox, CB_SETCURSEL, 0, 1); 
	ComboBox_SetMinVisible(hCombox, 120);
	hCombox = GetDlgItem(hWnd, IDC_RADIO2);
	SendMessage(hCombox, BM_SETCHECK, 1, 0);
	
	//开始设置进度条
	HWND hProgress = GetDlgItem(hWnd, IDC_PROGRESS1);
	//设置进度条范围
	SendMessage(hProgress, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
	return true;
}

bool OnCommand(HWND hWnd, DWORD dwID)
{
	switch (dwID)
	{
	case IDOK: //登录
	{  
		if (ComboBox_GetCurSel(GetDlgItem(hWnd, IDC_COMBO1)) < 0)
		{
			MessageBox(hWnd, L"请选择大区", L"错误", 0);
			return FALSE;
		}   
		TCHAR UNAME[20];
		TCHAR UPWD[20];
		HWND hUAME = GetDlgItem(hWnd, IDC_EDIT3);
		HWND hUPWD = GetDlgItem(hWnd, IDC_EDIT4);
		GetWindowText(hUAME, UNAME, 20);
		GetWindowText(hUPWD, UPWD, 20); 
		HWND hCombox1 = GetDlgItem(hWnd, IDC_COMBO1);
		GetWindowText(hCombox1, g_title[1], 20); 
		_stprintf_s(g_title[3], _T(""),"");
		_stprintf_s(g_title[3], _T("欢迎来到%s,%s"), g_title[1], g_title[0]); 
		//登录成功的处理
		if (!wcscmp(UNAME, L"admin") && !wcscmp(UPWD, L"admin"))
		{ 
			HWND hProgress = GetDlgItem(hWnd, IDC_PROGRESS1);
			for (int i = 0; i <= 100; i += 10)
			{
				SendMessage(hProgress, PBM_SETPOS, i, 0);
				Sleep(100);
			}
			SetWindowText(hWnd, _T("登录成功!"));
			MessageBox(hWnd, L"登录成功", L"成功", 0);
			 hDlg2 = CreateDialog(g_ins, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, DlgProc2);
			 ShowWindow(hDlg2, SW_SHOW);
			 UpdateWindow(hDlg2);
			 SetWindowText(hDlg2, g_title[3]);
			 //ShowWindow(hDlg2, SW_SHOW);

			 ShowWindow(hWnd, SW_HIDE);
			 //DestroyWindow(hWnd); 
		}
		else
		{
			MessageBox(hWnd, L"账号或密码错误", L"错误", 0);
		}  
	}break;
	case IDC_RADIO1:_stprintf_s(g_title[0], _T("%s"), L"电信区"); break; 
	case IDC_RADIO2:_stprintf_s(g_title[0], _T("%s"), L"联通区"); break;
	case IDC_RADIO3:_stprintf_s(g_title[0], _T("%s"), L"移动区"); break;
	default:
		return false;
		break;
	}
	return true;
}

INT_PTR CALLBACK DlgProc2(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	
	switch (uMsg)
	{
	case WM_INITDIALOG:{
		OnInitDialog2(hWnd);
	}break;
	case WM_COMMAND:{
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON1:
		{ 
			//获取列表句柄
			HWND temp = GetDlgItem(hWnd, IDC_LIST1); 
			for (int i = 0; i < 6; i++)
			{
				TCHAR buff[50];
				//lpnmitem->iSubItem
				//ListView_GetItemText(pNMHDR->hwndFrom, lpnmitem->iItem, 1 + i, buff, 50);
				//获取文本信息
				HWND TEMPTEXT = GetDlgItem(hWnd, IDC_EDIT5 + i);
				GetWindowText(TEMPTEXT, buff,50);
				//设置文本信息到列表
				ListView_SetItemText(temp, g_selself, i+1, buff);

			}
			
			return true;
		}break;
		}

	}break;
	case WM_NOTIFY:{
		NMHDR * pNMHDR = (NMHDR *)lParam;
		switch (pNMHDR->code)
		{
		case NM_CLICK://处理通用控件的鼠标单击消息
		{
			switch (pNMHDR->idFrom)//筛选是哪个通用控件发出的鼠标左键单击消息
			{
				case IDC_LIST1://LIST控件
				{
					//当WM_NOTIFY消息是由LISTVIEW控件产生时 lparam是一个LPNMITEMACTIVATE结构体指针
					//在这个结构体中保存着被点击的节点的行号 和列号 以及鼠标坐标
					LPNMITEMACTIVATE lpnmitem = (LPNMITEMACTIVATE)lParam;
					//获取被点击的节点的文本 
					//1011-1015
					//姓名 籍贯  地址  学历  入学时间   备注 
					g_selself = lpnmitem->iItem;
					HWND TEMPTEXT;
					for (int i = 0; i < 6; i++)
					{
						TCHAR buff[50];
						//lpnmitem->iSubItem
						ListView_GetItemText(pNMHDR->hwndFrom, lpnmitem->iItem, 1 + i, buff, 50);
						 TEMPTEXT = GetDlgItem(hWnd, IDC_EDIT5 + i);
						SetWindowText(TEMPTEXT, buff);
						
					}  
					TEMPTEXT = GetDlgItem(hWnd, IDC_STATIC);
					HBITMAP hBitmap = LoadBitmap(g_ins, MAKEINTRESOURCE(IDB_BITMAP3 + lpnmitem->iItem));
					SendMessage(TEMPTEXT, STM_SETIMAGE,//要设置的位图消息
						IMAGE_BITMAP, //要设置的图片格式
						(LPARAM)hBitmap);
				}
			}
		}break;
		default:
			break;
		} 

	}break;
	case WM_CLOSE:
		// 销毁窗口
		DestroyWindow(hWnd);

	default:
		return FALSE;
		break;
	}
	return TRUE;
}

bool OnInitDialog2(HWND hWnd){
	InitCommonControls();
	//开始初始化LISTVIEW控件
	HWND hListView = GetDlgItem(hWnd, IDC_LIST1);
	//设置listview 的扩展风格  整行选中
	ListView_SetExtendedListViewStyle(hListView, LVS_EX_FULLROWSELECT);
	//配置栏信息结构体
	LV_COLUMN column;
	column.mask = LVCF_WIDTH | LVCF_TEXT | LVCF_FMT;//配置需要使用的字段
	//4.3 插入到listview控件 
	column.pszText = _T("22");
	column.cx = 50;
	column.fmt = LVCFMT_CENTER;//文本居中对齐 (第0个column不居中)
	ListView_InsertColumn(hListView, 0, &column);
	////姓名 籍贯  地址  学历  入学时间   备注
	column.pszText = _T("姓名");
	column.fmt = LVCFMT_CENTER; //文本居中对齐
	column.cx = 60;
	ListView_InsertColumn(hListView, 1, &column);

	column.pszText = _T("籍贯");
	column.fmt = LVCFMT_CENTER; //文本居中对齐
	column.cx = 60;
	ListView_InsertColumn(hListView, 2, &column);

	column.pszText = _T("地址");
	column.fmt = LVCFMT_CENTER; //文本居中对齐
	column.cx = 80;
	ListView_InsertColumn(hListView, 3, &column);

	column.pszText = _T("学历");
	column.fmt = LVCFMT_CENTER; //文本居中对齐
	column.cx = 40;
	ListView_InsertColumn(hListView, 4, &column);

	column.pszText = _T("入学时间");
	column.fmt = LVCFMT_CENTER; //文本居中对齐
	column.cx = 80;
	ListView_InsertColumn(hListView, 5, &column);

	column.pszText = _T("备注");
	column.fmt = LVCFMT_CENTER; //文本居中对齐
	column.cx = 140;
	ListView_InsertColumn(hListView, 6, &column);
	// 5 插入行的信息结构体
	LV_ITEM  item = { 0 };
	item.mask = LVIF_TEXT;
	item.iItem = 0;
	item.pszText = NULL;
	//5.2 将结构体插入到listview控件
	int nIdex = ListView_InsertItem(hListView,&item);

	////姓名 籍贯  地址  学历  入职时间   备注

	//5.3 设置指定行 指定列的文本
	ListView_SetItemText(hListView,item.iItem,1,_T("刘德华")); 
	ListView_SetItemText(hListView,item.iItem,2,_T("广州"));
	ListView_SetItemText(hListView, item.iItem, 3, _T("甲北路22号"));
	ListView_SetItemText(hListView, item.iItem, 4, _T("高中"));
	ListView_SetItemText(hListView, item.iItem, 5, _T("2012-1-2"));
	ListView_SetItemText(hListView, item.iItem, 6, _T("工作努力"));
	++item.iItem;//增加行号
	nIdex = ListView_InsertItem(hListView, &item);
	ListView_SetItemText(hListView, item.iItem, 1, _T("张学友"));
	ListView_SetItemText(hListView, item.iItem, 2, _T("台湾"));
	ListView_SetItemText(hListView, item.iItem, 3, _T("甲北路21号"));
	ListView_SetItemText(hListView, item.iItem, 4, _T("大学"));
	ListView_SetItemText(hListView, item.iItem, 5, _T("2014-1-2"));
	ListView_SetItemText(hListView, item.iItem, 6, _T("天天上班听音乐"));

	++item.iItem;//增加行号
	nIdex = ListView_InsertItem(hListView, &item);
	ListView_SetItemText(hListView, item.iItem, 1, _T("郭富城"));
	ListView_SetItemText(hListView, item.iItem, 2, _T("南昌"));
	ListView_SetItemText(hListView, item.iItem, 3, _T("八大胡同21号"));
	ListView_SetItemText(hListView, item.iItem, 4, _T("博士"));
	ListView_SetItemText(hListView, item.iItem, 5, _T("2014-1-2"));
	ListView_SetItemText(hListView, item.iItem, 6, _T("天天聊QQ"));
	return true;
}