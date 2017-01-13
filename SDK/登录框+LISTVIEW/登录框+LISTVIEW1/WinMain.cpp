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
TCHAR g_region[][10] = { _T("��ŷ����"), _T("ŵ����˹"), _T("Ƥ�����ط�"), _T("�þ�ʥ��"), _T("��ɫõ��") };
HWND hDlg2;
int g_selself = 0; //��ʼ����ǰ
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
		case WM_INITDIALOG: //�Ի��򱻳�ʼ������Ϣ  ����ֻ��һ��
		{
			//SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)GetStockObject(BLACK_BRUSH));
			//PAINTSTRUCT ps;
			//BeginPaint(hWnd, &ps); 
			//HDC	hdc = GetDC(hWnd); 
			//// ѡ��͸����ˢ
			//SelectObject(hdc, GetStockObject(BLACK_BRUSH
			//	));
			//MoveToEx(hdc, 0, 25, NULL);
			//LineTo(hdc, width, 25); 
			//// ���رհ�ť���Ƴ���
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
	//������������ַ���
	HWND hCombox = GetDlgItem(hWnd, IDC_COMBO1);
	//ComboBox_InsertString(hWnd, 0, _T("��ѡ�����"));
	
	//����ַ�����������
	for (int i = 0; i < _countof(g_region);i++)
	{
		SendMessage(hCombox, CB_INSERTSTRING, -1, (LPARAM)g_region[i]);
	} 
	HICON hIcon = LoadIcon(g_ins, MAKEINTRESOURCE(IDI_ICON1));
	SetClassLong(hWnd, GCL_HICON, (LONG)hIcon); 
	//���õ�ǰ��ѡ��
	SendMessage(hCombox, CB_SETCURSEL, 0, 1); 
	ComboBox_SetMinVisible(hCombox, 120);
	hCombox = GetDlgItem(hWnd, IDC_RADIO2);
	SendMessage(hCombox, BM_SETCHECK, 1, 0);
	
	//��ʼ���ý�����
	HWND hProgress = GetDlgItem(hWnd, IDC_PROGRESS1);
	//���ý�������Χ
	SendMessage(hProgress, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
	return true;
}

bool OnCommand(HWND hWnd, DWORD dwID)
{
	switch (dwID)
	{
	case IDOK: //��¼
	{  
		if (ComboBox_GetCurSel(GetDlgItem(hWnd, IDC_COMBO1)) < 0)
		{
			MessageBox(hWnd, L"��ѡ�����", L"����", 0);
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
		_stprintf_s(g_title[3], _T("��ӭ����%s,%s"), g_title[1], g_title[0]); 
		//��¼�ɹ��Ĵ���
		if (!wcscmp(UNAME, L"admin") && !wcscmp(UPWD, L"admin"))
		{ 
			HWND hProgress = GetDlgItem(hWnd, IDC_PROGRESS1);
			for (int i = 0; i <= 100; i += 10)
			{
				SendMessage(hProgress, PBM_SETPOS, i, 0);
				Sleep(100);
			}
			SetWindowText(hWnd, _T("��¼�ɹ�!"));
			MessageBox(hWnd, L"��¼�ɹ�", L"�ɹ�", 0);
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
			MessageBox(hWnd, L"�˺Ż��������", L"����", 0);
		}  
	}break;
	case IDC_RADIO1:_stprintf_s(g_title[0], _T("%s"), L"������"); break; 
	case IDC_RADIO2:_stprintf_s(g_title[0], _T("%s"), L"��ͨ��"); break;
	case IDC_RADIO3:_stprintf_s(g_title[0], _T("%s"), L"�ƶ���"); break;
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
			//��ȡ�б���
			HWND temp = GetDlgItem(hWnd, IDC_LIST1); 
			for (int i = 0; i < 6; i++)
			{
				TCHAR buff[50];
				//lpnmitem->iSubItem
				//ListView_GetItemText(pNMHDR->hwndFrom, lpnmitem->iItem, 1 + i, buff, 50);
				//��ȡ�ı���Ϣ
				HWND TEMPTEXT = GetDlgItem(hWnd, IDC_EDIT5 + i);
				GetWindowText(TEMPTEXT, buff,50);
				//�����ı���Ϣ���б�
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
		case NM_CLICK://����ͨ�ÿؼ�����굥����Ϣ
		{
			switch (pNMHDR->idFrom)//ɸѡ���ĸ�ͨ�ÿؼ�������������������Ϣ
			{
				case IDC_LIST1://LIST�ؼ�
				{
					//��WM_NOTIFY��Ϣ����LISTVIEW�ؼ�����ʱ lparam��һ��LPNMITEMACTIVATE�ṹ��ָ��
					//������ṹ���б����ű�����Ľڵ���к� ���к� �Լ��������
					LPNMITEMACTIVATE lpnmitem = (LPNMITEMACTIVATE)lParam;
					//��ȡ������Ľڵ���ı� 
					//1011-1015
					//���� ����  ��ַ  ѧ��  ��ѧʱ��   ��ע 
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
					SendMessage(TEMPTEXT, STM_SETIMAGE,//Ҫ���õ�λͼ��Ϣ
						IMAGE_BITMAP, //Ҫ���õ�ͼƬ��ʽ
						(LPARAM)hBitmap);
				}
			}
		}break;
		default:
			break;
		} 

	}break;
	case WM_CLOSE:
		// ���ٴ���
		DestroyWindow(hWnd);

	default:
		return FALSE;
		break;
	}
	return TRUE;
}

bool OnInitDialog2(HWND hWnd){
	InitCommonControls();
	//��ʼ��ʼ��LISTVIEW�ؼ�
	HWND hListView = GetDlgItem(hWnd, IDC_LIST1);
	//����listview ����չ���  ����ѡ��
	ListView_SetExtendedListViewStyle(hListView, LVS_EX_FULLROWSELECT);
	//��������Ϣ�ṹ��
	LV_COLUMN column;
	column.mask = LVCF_WIDTH | LVCF_TEXT | LVCF_FMT;//������Ҫʹ�õ��ֶ�
	//4.3 ���뵽listview�ؼ� 
	column.pszText = _T("22");
	column.cx = 50;
	column.fmt = LVCFMT_CENTER;//�ı����ж��� (��0��column������)
	ListView_InsertColumn(hListView, 0, &column);
	////���� ����  ��ַ  ѧ��  ��ѧʱ��   ��ע
	column.pszText = _T("����");
	column.fmt = LVCFMT_CENTER; //�ı����ж���
	column.cx = 60;
	ListView_InsertColumn(hListView, 1, &column);

	column.pszText = _T("����");
	column.fmt = LVCFMT_CENTER; //�ı����ж���
	column.cx = 60;
	ListView_InsertColumn(hListView, 2, &column);

	column.pszText = _T("��ַ");
	column.fmt = LVCFMT_CENTER; //�ı����ж���
	column.cx = 80;
	ListView_InsertColumn(hListView, 3, &column);

	column.pszText = _T("ѧ��");
	column.fmt = LVCFMT_CENTER; //�ı����ж���
	column.cx = 40;
	ListView_InsertColumn(hListView, 4, &column);

	column.pszText = _T("��ѧʱ��");
	column.fmt = LVCFMT_CENTER; //�ı����ж���
	column.cx = 80;
	ListView_InsertColumn(hListView, 5, &column);

	column.pszText = _T("��ע");
	column.fmt = LVCFMT_CENTER; //�ı����ж���
	column.cx = 140;
	ListView_InsertColumn(hListView, 6, &column);
	// 5 �����е���Ϣ�ṹ��
	LV_ITEM  item = { 0 };
	item.mask = LVIF_TEXT;
	item.iItem = 0;
	item.pszText = NULL;
	//5.2 ���ṹ����뵽listview�ؼ�
	int nIdex = ListView_InsertItem(hListView,&item);

	////���� ����  ��ַ  ѧ��  ��ְʱ��   ��ע

	//5.3 ����ָ���� ָ���е��ı�
	ListView_SetItemText(hListView,item.iItem,1,_T("���»�")); 
	ListView_SetItemText(hListView,item.iItem,2,_T("����"));
	ListView_SetItemText(hListView, item.iItem, 3, _T("�ױ�·22��"));
	ListView_SetItemText(hListView, item.iItem, 4, _T("����"));
	ListView_SetItemText(hListView, item.iItem, 5, _T("2012-1-2"));
	ListView_SetItemText(hListView, item.iItem, 6, _T("����Ŭ��"));
	++item.iItem;//�����к�
	nIdex = ListView_InsertItem(hListView, &item);
	ListView_SetItemText(hListView, item.iItem, 1, _T("��ѧ��"));
	ListView_SetItemText(hListView, item.iItem, 2, _T("̨��"));
	ListView_SetItemText(hListView, item.iItem, 3, _T("�ױ�·21��"));
	ListView_SetItemText(hListView, item.iItem, 4, _T("��ѧ"));
	ListView_SetItemText(hListView, item.iItem, 5, _T("2014-1-2"));
	ListView_SetItemText(hListView, item.iItem, 6, _T("�����ϰ�������"));

	++item.iItem;//�����к�
	nIdex = ListView_InsertItem(hListView, &item);
	ListView_SetItemText(hListView, item.iItem, 1, _T("������"));
	ListView_SetItemText(hListView, item.iItem, 2, _T("�ϲ�"));
	ListView_SetItemText(hListView, item.iItem, 3, _T("�˴��ͬ21��"));
	ListView_SetItemText(hListView, item.iItem, 4, _T("��ʿ"));
	ListView_SetItemText(hListView, item.iItem, 5, _T("2014-1-2"));
	ListView_SetItemText(hListView, item.iItem, 6, _T("������QQ"));
	return true;
}