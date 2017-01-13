#include <windows.h>
#include <tchar.h>
#include "resource.h"
#include <windowsx.h>
#include <commctrl.h>


// ���Ի���ص�����
INT_PTR CALLBACK MainDlg(HWND hWnd , UINT uMsg , WPARAM wPraram , LPARAM lParam);

// 
INT_PTR CALLBACK DlgProc2(HWND hWnd , UINT uMsg , WPARAM wPraram , LPARAM lParam);

// ���Ի����WM_COMMAND��Ϣ��Ӧ����
BOOL	OnCommand(HWND hWnd , DWORD dwID);

// ���Ի�������
BOOL	OnInitDialog1(HWND hWnd);



HINSTANCE g_hIns;
DWORD	  g_dwSection = 0; // 0 :����1��, 1: �������� ......
DWORD	  g_dwNet = 0; // 0 : ����, 1 : ��ͨ
 int WINAPI WinMain(_In_ HINSTANCE hInstance ,
				   _In_opt_ HINSTANCE hPrevInstance , 
				   _In_ LPSTR lpCmdLine , 
				   _In_ int nShowCmd)
{
	g_hIns = hInstance;
	DialogBox(hInstance ,
			  MAKEINTRESOURCE(IDD_DIALOG1) , /*�Ի������ԴID*/
			  NULL , 
			  MainDlg);
}


// ���Ի���ص�����
INT_PTR CALLBACK MainDlg(HWND hWnd , UINT uMsg , WPARAM wPraram , LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_INITDIALOG: // �Ի��򱻳�ʼ������Ϣ,����ֻ��һ��
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
			// ��ȡ��ԴID��Ӧ�Ŀؼ����ھ��
			HWND hRaido1 = GetDlgItem(hWnd , IDC_RADIO1);
			HWND hRaido7 = GetDlgItem(hWnd , IDC_RADIO7);

			// ���õ�ѡ���ѡ��״̬
			SendMessage(hRaido1 , 
						BM_SETCHECK , /*��ť��ѡ��״̬����Ϣ*/
						BST_CHECKED,
						0);

			// ���õ�ѡ���ѡ��״̬
			SendMessage(hRaido7 , 
						BM_SETCHECK , /*��ť��ѡ��״̬����Ϣ*/
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
					// ���ø����ڵĴ��ڱ���
					// GetParent(hWnd) : ��ȡһ�����ھ���ĸ����ھ��
					SetWindowText(GetParent(hWnd) , _T("����һ��"));
					g_dwSection = 0;
				}
				else if(SendMessage(GetDlgItem(hWnd , IDC_RADIO2) , BM_GETCHECK , 0 , 0) == BST_CHECKED)
				{
					// GetParent(hWnd) : ��ȡһ�����ھ���ĸ����ھ��
					SetWindowText(GetParent(hWnd) , _T("��������"));
					g_dwSection = 1;
				}
				else if(SendMessage(GetDlgItem(hWnd , IDC_RADIO3) , BM_GETCHECK , 0 , 0) == BST_CHECKED)
				{
					SetWindowText(GetParent(hWnd) , _T("�Ϻ�һ��"));
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

				// ����������
				DestroyWindow(hWnd);
			}
		}
		break;


		case WM_CLOSE:
			// ���ٴ���
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
		case IDC_LOGIN: // ��ť����¼�
		{
			TCHAR username[20];
			TCHAR passwd[ 20 ];
			HWND hCombox = GetDlgItem(hWnd , IDC_COMBO1);
			HWND hEdit = GetDlgItem(hWnd , IDC_EDIT2);

			// ��ȡ�˺���
			ComboBox_GetText(hCombox , username , 20);
			// ��ȡ����
			GetWindowText(hEdit , passwd , 20);


			HWND hProgress = GetDlgItem(hWnd , IDC_PROGRESS1);
			for(int i = 0; i < 100;++i)
			{
				SendMessage(hProgress , PBM_SETPOS , i , 0);
				Sleep(10);
			}

			MessageBox(hWnd , passwd , username , 0);


			HWND hStatic = GetDlgItem(hWnd , IDC_PIC);
			// ������Դ�е�λͼ
			HBITMAP hBitmap = LoadBitmap(g_hIns , MAKEINTRESOURCE(IDB_BITMAP2));

			// ��λͼ���õ�ͼƬ��
			SendMessage(hStatic , 
						STM_SETIMAGE , /*����λͼ����Ϣ*/
						IMAGE_BITMAP , /*Ҫ���õ�ͼƬ�ĸ�ʽ*/
						(LPARAM)hBitmap);
		}
		break;

		case IDC_BUTTON1: // ��ť����¼�
		{
			// ������ģ̬�Ի���
			HWND hDlg2 = CreateDialog(g_hIns ,
									  MAKEINTRESOURCE(IDD_DIALOG2) ,/*��ԴID*/
									  hWnd , 
									  DlgProc2);

			ShowWindow(hDlg2,SW_SHOW);
			UpdateWindow(hDlg2);
		}
		break;

		case IDC_CHECK2: // ��ѡ��ĵ���¼�
		{
			HWND hCheck2 = GetDlgItem(hWnd , IDC_CHECK2);
			HWND hCheck1 = GetDlgItem(hWnd , IDC_CHECK1);

			// ��ȡ��ѡ���ѡ��״̬
			DWORD dwStatus = SendMessage(hCheck2 , BM_GETCHECK , 0 , 0);
			// ���ø�ѡ���ѡ��״̬
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
	// ������������ַ���
	HWND hCombox = GetDlgItem(hWnd , IDC_COMBO1);
	//ComboBox_InsertString(hCombox , 0 , _T("chibupaobutuputaopi@qq.com"));
	// ����ַ�����������
	SendMessage(hCombox , 
				CB_INSERTSTRING ,/*�����ַ�������Ϣ*/
				-1 , /*�����-1��������*/
				(LPARAM)_T("chibupaobutuputaopi@qq.com"));

	SendMessage(hCombox , CB_INSERTSTRING , -1 , (LPARAM)_T("�˰ٱ��������@qq.com"));

	// ���õ�ǰ��ѡ��
	SendMessage(hCombox , CB_SETCURSEL ,0, 0);

	HWND hProgress = GetDlgItem(hWnd , IDC_PROGRESS1);


	// ���ý������ķ�Χ
	SendMessage(hProgress , 
				PBM_SETRANGE , /*���ý�������Χ����Ϣ*/
				0 , 
				MAKELPARAM(0 , 100)/*���÷�Χ0~100*/
				);

	return TRUE;
}
