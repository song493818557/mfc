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

		case WM_NOTIFY:
		{
			NMHDR* pNMHDR = (NMHDR*)lParam;
			switch(pNMHDR->code)
			{
				case NM_RCLICK: // ��Ӧ�Ҽ�������Ϣ
				{
					switch(pNMHDR->idFrom)// ɸѡ��Ӧ�Ҽ�������Ϣ��x`�ؼ�ID
					{
						case IDC_TREE1:
						{
							// ��ȡ������ڵ���ı�
							TV_ITEM item = { 0 };
							// ��ȡ��ǰ�����ͣ�Ľڵ�
							// typedef struct tagTVHITTESTINFO
							// {
							// 	  POINT       pt; // �������(���ؼ��ͻ�������)
							// 	  UINT        flags;// ��־
							// 	  HTREEITEM   hItem; // �������س��Ľڵ���
							// } TVHITTESTINFO , *LPTVHITTESTINFO;
							TVHITTESTINFO hitTestInfo = { 0 };
							// ��ȡ��ǰ�������(��Ļ����)
							GetCursorPos(&hitTestInfo.pt);
							// ����Ļ����ת�������ؼ��Ŀͻ�������
							ScreenToClient(pNMHDR->hwndFrom , &hitTestInfo.pt);
							hitTestInfo.flags = TVHT_ONITEM ; // ��־

							TreeView_HitTest(pNMHDR->hwndFrom , &hitTestInfo);

							// ����Ҫ��ȡ�ڵ����Ϣ
							item.mask = TVIF_TEXT;
							item.hItem = hitTestInfo.hItem ; // ����Ҫ��ȡ�ڵ��ı��Ľڵ���
							TCHAR buff[ 50 ] = { 0 };
							item.pszText = buff; // ���滺�����׵�ַ(���ڽ��սڵ��ı�)
							item.cchTextMax = 50; // ������������ַ�����
							TreeView_GetItem(pNMHDR->hwndFrom , &item);

							MessageBox(hWnd , buff , _T("�ڵ��ı�") , 0);
						}
						break;
					}
				}
				break;
			}
		}
		break;

		case  WM_CLOSE:
			EndDialog(hWnd , 0);
		default:
			return FALSE;
			break;
	}
	return TRUE;
}


void OnInitDialog(HWND hWnd)
{
	//3. ��ʼ��ͨ�ÿؼ�
	InitCommonControls();

	//4 ����ڵ㵽���ؼ�

	//4.1
	HWND hTreeView = GetDlgItem(hWnd , IDC_TREE1);
	// 4.2 ��ʼ������ṹ��
	//	4.3 ��ʼ������ڵ��λ����Ϣ
	TV_INSERTSTRUCT insStruct;
	insStruct.hParent = NULL ; // ���ø��ڵ�,�����ڵ���NULLʱ,����Ľڵ��Ϊ���ڵ�
	insStruct.hInsertAfter = TVI_LAST; // ���ֵܽڵ���λ��(���뵽���)

	// 4.4 ��ʼ������ڵ㱾����Ϣ
	insStruct.item.mask = TVIF_TEXT;// ����ʹ�ýṹ���е��ı��ֶ�
	insStruct.item.pszText = _T("��15��");

	// 5 ��������Ϣ�ṹ�崫�뺯��,���в���,�����ز���ڵ�Ľڵ���
	HTREEITEM hItem15�� = TreeView_InsertItem(hTreeView , &insStruct);

	// 5.1 ����һ���½ڵ㵽���нڵ�֮��
	insStruct.hParent = hItem15��; // ���ø��ڵ���
	insStruct.item.pszText = _T("����ʦ"); // ���ýڵ����ʾ�ı�
	// ����ڵ�,�������½ڵ�Ľڵ���
	HTREEITEM hItem����ʦ = TreeView_InsertItem(hTreeView , &insStruct);

	insStruct.hParent = hItem����ʦ;// ���ø��ڵ���
	insStruct.item.pszText = _T("����ʦ����");// ���ýڵ����ʾ�ı�
	// ����ڵ�
	TreeView_InsertItem(hTreeView , &insStruct);


	insStruct.hParent = NULL; // ���ýڵ�ĸ��ڵ���
	insStruct.item.pszText = _T("��14��");
	TreeView_InsertItem(hTreeView , &insStruct);
}