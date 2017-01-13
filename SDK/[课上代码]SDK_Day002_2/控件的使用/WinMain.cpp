#include <windows.h>
#include <tchar.h>
#include "resource.h"
#include <windowsx.h>
#include <commctrl.h>


// 主对话框回调函数
INT_PTR CALLBACK MainDlg(HWND hWnd , UINT uMsg , WPARAM wPraram , LPARAM lParam);

// 
INT_PTR CALLBACK DlgProc2(HWND hWnd , UINT uMsg , WPARAM wPraram , LPARAM lParam);

// 主对话框的WM_COMMAND消息响应函数
BOOL	OnCommand(HWND hWnd , DWORD dwID);

// 主对话框处理函数
BOOL	OnInitDialog1(HWND hWnd);



HINSTANCE g_hIns;
DWORD	  g_dwSection = 0; // 0 :北京1区, 1: 北京二区 ......
DWORD	  g_dwNet = 0; // 0 : 电信, 1 : 联通
 int WINAPI WinMain(_In_ HINSTANCE hInstance ,
				   _In_opt_ HINSTANCE hPrevInstance , 
				   _In_ LPSTR lpCmdLine , 
				   _In_ int nShowCmd)
{
	g_hIns = hInstance;
	DialogBox(hInstance ,
			  MAKEINTRESOURCE(IDD_DIALOG1) , /*对话框的资源ID*/
			  NULL , 
			  MainDlg);
}


// 主对话框回调函数
INT_PTR CALLBACK MainDlg(HWND hWnd , UINT uMsg , WPARAM wPraram , LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_INITDIALOG: // 对话框被初始化的消息,有且只有一次
			return OnInitDialog1(hWnd);

		case WM_CLOSE:
			EndDialog(hWnd , 0);
			break;

		case WM_COMMAND:
			return OnCommand(hWnd , LOWORD(wPraram));


		default:
			return FALSE;
			break;
	}
	return TRUE;
}


INT_PTR CALLBACK DlgProc2(HWND hWnd , UINT uMsg , WPARAM wPraram , LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_INITDIALOG:
		{
			// 获取资源ID对应的控件窗口句柄
			HWND hRaido1 = GetDlgItem(hWnd , IDC_RADIO1);
			HWND hRaido7 = GetDlgItem(hWnd , IDC_RADIO7);

			// 设置单选框的选中状态
			SendMessage(hRaido1 , 
						BM_SETCHECK , /*按钮类选中状态的消息*/
						BST_CHECKED,
						0);

			// 设置单选框的选中状态
			SendMessage(hRaido7 , 
						BM_SETCHECK , /*按钮类选中状态的消息*/
						BST_CHECKED , 
						0);
		}
		break;

		case  WM_COMMAND:
		{
			if(LOWORD(wPraram) == IDCANCEL)
			{
				g_dwSection = -1;
				g_dwNet = -1;
			}
			else if(LOWORD(wPraram) == IDOK)
			{
				if(SendMessage(GetDlgItem(hWnd , IDC_RADIO1) , BM_GETCHECK , 0 , 0) == BST_CHECKED)
				{
					// 设置父窗口的窗口标题
					// GetParent(hWnd) : 获取一个窗口句柄的父窗口句柄
					SetWindowText(GetParent(hWnd) , _T("北京一区"));
					g_dwSection = 0;
				}
				else if(SendMessage(GetDlgItem(hWnd , IDC_RADIO2) , BM_GETCHECK , 0 , 0) == BST_CHECKED)
				{
					// GetParent(hWnd) : 获取一个窗口句柄的父窗口句柄
					SetWindowText(GetParent(hWnd) , _T("北京二区"));
					g_dwSection = 1;
				}
				else if(SendMessage(GetDlgItem(hWnd , IDC_RADIO3) , BM_GETCHECK , 0 , 0) == BST_CHECKED)
				{
					SetWindowText(GetParent(hWnd) , _T("上海一区"));
					g_dwSection = 2;
				}


				if(SendMessage(GetDlgItem(hWnd , IDC_RADIO7) , BM_GETCHECK , 0 , 0) == BST_CHECKED)
				{
					g_dwNet = 0;
				}
				else if(SendMessage(GetDlgItem(hWnd , IDC_RADIO8) , BM_GETCHECK , 0 , 0) == BST_CHECKED)
				{
					g_dwNet = 1;
				}

				// 销毁自身窗口
				DestroyWindow(hWnd);
			}
		}
		break;


		case WM_CLOSE:
			// 销毁窗口
			DestroyWindow(hWnd);

		default:
			return FALSE;
			break;
	}
	return TRUE;
}

BOOL OnCommand(HWND hWnd , DWORD dwID)
{
	switch(dwID)
	{
		case IDC_LOGIN: // 按钮点击事件
		{
			TCHAR username[20];
			TCHAR passwd[ 20 ];
			HWND hCombox = GetDlgItem(hWnd , IDC_COMBO1);
			HWND hEdit = GetDlgItem(hWnd , IDC_EDIT2);

			// 获取账号名
			ComboBox_GetText(hCombox , username , 20);
			// 获取密码
			GetWindowText(hEdit , passwd , 20);


			HWND hProgress = GetDlgItem(hWnd , IDC_PROGRESS1);
			for(int i = 0; i < 100;++i)
			{
				SendMessage(hProgress , PBM_SETPOS , i , 0);
				Sleep(10);
			}

			MessageBox(hWnd , passwd , username , 0);


			HWND hStatic = GetDlgItem(hWnd , IDC_PIC);
			// 加载资源中的位图
			HBITMAP hBitmap = LoadBitmap(g_hIns , MAKEINTRESOURCE(IDB_BITMAP2));

			// 将位图设置到图片上
			SendMessage(hStatic , 
						STM_SETIMAGE , /*设置位图的消息*/
						IMAGE_BITMAP , /*要设置的图片的格式*/
						(LPARAM)hBitmap);
		}
		break;

		case IDC_BUTTON1: // 按钮点击事件
		{
			// 创建非模态对话框
			HWND hDlg2 = CreateDialog(g_hIns ,
									  MAKEINTRESOURCE(IDD_DIALOG2) ,/*资源ID*/
									  hWnd , 
									  DlgProc2);

			ShowWindow(hDlg2,SW_SHOW);
			UpdateWindow(hDlg2);
		}
		break;

		case IDC_CHECK2: // 复选框的点击事件
		{
			HWND hCheck2 = GetDlgItem(hWnd , IDC_CHECK2);
			HWND hCheck1 = GetDlgItem(hWnd , IDC_CHECK1);

			// 获取复选框的选中状态
			DWORD dwStatus = SendMessage(hCheck2 , BM_GETCHECK , 0 , 0);
			// 设置复选框的选中状态
			SendMessage(hCheck1 , BM_SETCHECK , dwStatus , 0);
		}
		break;

		default:
			break;
	}

	return TRUE;
}

BOOL OnInitDialog1(HWND hWnd)
{
	// 给下拉框添加字符串
	HWND hCombox = GetDlgItem(hWnd , IDC_COMBO1);
	//ComboBox_InsertString(hCombox , 0 , _T("chibupaobutuputaopi@qq.com"));
	// 添加字符串到下拉框
	SendMessage(hCombox , 
				CB_INSERTSTRING ,/*插入字符串的消息*/
				-1 , /*如果是-1则插在最后*/
				(LPARAM)_T("chibupaobutuputaopi@qq.com"));

	SendMessage(hCombox , CB_INSERTSTRING , -1 , (LPARAM)_T("八百标兵奔北坡@qq.com"));

	// 设置当前被选中
	SendMessage(hCombox , CB_SETCURSEL ,0, 0);

	HWND hProgress = GetDlgItem(hWnd , IDC_PROGRESS1);


	// 设置进度条的范围
	SendMessage(hProgress , 
				PBM_SETRANGE , /*设置进度条范围的消息*/
				0 , 
				MAKELPARAM(0 , 100)/*设置范围0~100*/
				);

	return TRUE;
}
