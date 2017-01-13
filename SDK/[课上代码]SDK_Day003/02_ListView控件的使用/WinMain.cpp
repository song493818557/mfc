#include <windows.h>
#include "resource.h"
#include <tchar.h>

// 1. ����ͷ�ļ�
#include <commctrl.h>
// 2. ���뾲̬��
#pragma comment(lib,"comctl32.lib")

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);

void OnInitDialog(HWND hWnd);

HINSTANCE g_hIns ;
int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	g_hIns = hInstance;
	DialogBox(hInstance , MAKEINTRESOURCE(IDD_DIALOG1) , NULL , DlgProc);
}


INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_INITDIALOG:
			OnInitDialog(hWnd);
		break;

		case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
				case ID_MENU_OPEN:
				{
					HWND hListView = GetDlgItem(hWnd , IDC_LIST1);
					// ��ȡ��ѡ�е��е��к�(�����ǰû�б�ѡ�е���, ���ص���-1)
					int nLine = SendMessage(hListView , LVM_GETSELECTIONMARK , 0 , 0);
					if(nLine != -1)
					{
						TCHAR buff[ 20 ];
					
						ListView_GetItemText(hListView , nLine , 1 , buff , 20);
						MessageBox(hWnd , buff , _T("��") , 0);
					}
				}
				break;
			}
		}
		break;

		case WM_NOTIFY: // ��Ӧͨ�ÿؼ�����Ϣ
		{
			NMHDR* pNMHDR = (NMHDR*)lParam;
			switch(pNMHDR->code)
			{
				case NM_RCLICK:
				{
					switch(pNMHDR->idFrom)
					{
						case IDC_LIST1:
						{
							// ����һ���Ҽ��˵�
							// 1. ���ز˵�
							HMENU hMenu = LoadMenu(g_hIns , MAKEINTRESOURCE(IDR_MENU1));
							// ��ȡ����˵����Ӳ˵�(�����˵�)
							HMENU hPopup = GetSubMenu(hMenu,0);

							POINT pt;
							GetCursorPos(&pt);//��ȡ�������(��Ļ����)
							TrackPopupMenu(hPopup , TPM_LEFTALIGN , pt.x , pt.y , 0 , hWnd , 0);

							// ���ٲ˵�
							DestroyMenu(hMenu);
						}
						break;
					}
				}
				break;

				case NM_CLICK: // ����ͨ�ÿؼ���������������Ϣ
				{
					switch(pNMHDR->idFrom ) // ɸѡ���ĸ�ͨ�ÿؼ�������������������Ϣ
					{
						case IDC_LIST1:// ListView�ؼ�
						{
							// ��WM_NOTIFY��Ϣ����ListView�ؼ�����ʱ, lParam��һ��LPNMITEMACTIVATE�ṹ��ָ��
							// ������ṹ����, �����ű�����Ľڵ���кź��к�,�Լ��������
							LPNMITEMACTIVATE lpnmitem = (LPNMITEMACTIVATE)lParam;
							

							// ��ȡ������ڵ���ı�
							TCHAR buff[ 50 ];
							ListView_GetItemText(pNMHDR->hwndFrom ,
												 lpnmitem->iItem ,
												 lpnmitem->iSubItem ,
												 buff ,
												 50
												 );
							MessageBox(hWnd , buff , 0 , 0);
						}
						break;
					}

				}
			}
		}
		break;

		case WM_CLOSE:
			EndDialog(hWnd , 0);
		default:
			return FALSE;
	}
	return TRUE;
}

void OnInitDialog(HWND hWnd)
{
	// 3. ���ó�ʼ��ͨ�ÿؼ��ĺ���
	InitCommonControls();
	
	// 4. ��ʼ��ʼ��ListView�ؼ�
	// ����ListView����չ���
	//4.1 ����Column(�����߽���)
	HWND hListView = GetDlgItem(hWnd , IDC_LIST1);

	// ����ListView����չ���:����ѡ��
	ListView_SetExtendedListViewStyle(hListView , LVS_EX_FULLROWSELECT|LVS_EX_CHECKBOXES);

	//4.2 ��������Ϣ�ṹ��
	LV_COLUMN column;
	column.mask = LVCF_WIDTH |LVCF_TEXT|LVCF_FMT; // ����Ҫʹ�õ��ֶ�
	column.pszText= _T(""); // ������ʾ�ı�
	column.cx = 20; // ���Ŀ��
	column.fmt = LVCFMT_CENTER; // �ı����ж���(��0��Column������)

	// 4.3 ���뵽ListView�ؼ�
	ListView_InsertColumn(hListView , /*ListView�ؼ����*/
						  0 , /*���*/
						  &column/*������Ϣ�ṹ��*/
						  );

	column.pszText = _T("����"); // ������ʾ�ı�
	column.cx = 80; // ���Ŀ��
	ListView_InsertColumn(hListView , 1 , &column);

	column.pszText = _T("����"); // ������ʾ�ı�
	column.cx = 50; // ���Ŀ��
	ListView_InsertColumn(hListView , 2 , &column);

	column.pszText = _T("�Ա�"); // ������ʾ�ı�
	column.cx = 50; // ���Ŀ��
	ListView_InsertColumn(hListView , 3 , &column);

	//5 ��������Ϣ
	LV_ITEM item = { 0 };

	//5.1 ��������Ϣ�ṹ��
	item.mask = LVIF_TEXT;

	item.iItem = 0; // �к�
	item.pszText = NULL;
	//5.2 ���ṹ����뵽ListView�ؼ�
	int nIdex = ListView_InsertItem(hListView , &item);

	// 5.3 ����ָ����ָ���е��ı�
	ListView_SetItemText(hListView , /*ListView���ھ��*/
						 item.iItem , /*�к�*/
						 1 , /*�к�*/
						 _T("���»�")/*�е���ʾ�ı�*/
						 );
	ListView_SetItemText(hListView , item.iItem , 2 , _T("18"));
	ListView_SetItemText(hListView , item.iItem , 3 , _T("��"));

	++item.iItem; // �����к�
	nIdex = ListView_InsertItem(hListView , &item);
	ListView_SetItemText(hListView , item.iItem , 1 , _T("����"));
	ListView_SetItemText(hListView , item.iItem , 2 , _T("28"));
	ListView_SetItemText(hListView , item.iItem , 3 , _T("��"));
}
