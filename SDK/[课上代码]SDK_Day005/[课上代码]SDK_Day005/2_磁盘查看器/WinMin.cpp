#include <windows.h>
#include <tchar.h>
#include "resource.h"

// ����ͨ�ÿؼ���ͷ�ļ�
#include <commctrl.h>
// ����ͨ�ÿؼ��ľ�̬��
#pragma comment(lib,"Comctl32.lib")

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);

int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	// ������Դ�еĶԻ���
	DialogBox(hInstance ,
			  MAKEINTRESOURCE(IDD_DIALOG1) ,
			  NULL ,
			  DlgProc
			  );
}

const TCHAR* MyGetDriveType(const TCHAR* pDriveBuff)
{
	UINT uType = GetDriveType(pDriveBuff);
	const TCHAR* pType = NULL;
	switch(uType)
	{
		case DRIVE_NO_ROOT_DIR:pType = _T("��Ч�ĸ�·��"); break;
		case DRIVE_REMOVABLE:pType = _T("���ƶ����� "); break;
		case DRIVE_FIXED:pType = _T("Ӳ�� "); break;
		case DRIVE_REMOTE:pType = _T("�������"); break;
		case DRIVE_CDROM:
		{
			pType = _T(" ���������� ");
			GetVolumeInformation(pDriveBuff , 0 , 0 , 0 , 0 , 0 , 0 , 0);
			if(21 == GetLastError()) // ��ȡ���Ĵ�����Ϣ
			{
				pType = _T("����������(�޹���)");
			}
			else
				pType = _T("����������(�й���)");
			//printf("(%s����)" , 21==GetLastError()?"��":"��");
		}
		break;
		case DRIVE_RAMDISK:pType = _T("RAM����"); break;
		case DRIVE_UNKNOWN:pType = _T("δ֪������"); break;
	}

	return pType;
}


INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_INITDIALOG: // ��Ӧ�Ի����ʼ����Ϣ
		{
			// ��ʼ��ͨ�ÿؼ�
			InitCommonControls();

			// ��ʼ��ListView�ؼ�
		    // �̷� | ��ı��� | �ļ�ϵͳ | ʣ��ռ� | �ܿռ� | ����������

			// ��ȡListView�ؼ��Ĵ��ھ��
			HWND hListView = GetDlgItem(hWnd , IDC_LIST1);

			// ������չ���
			ListView_SetExtendedListViewStyle(hListView , LVS_EX_FULLROWSELECT);
			
			LV_COLUMN column = { 0 };

			// ˵���ṹ���е��ĸ��ֶ�����Ч��
			column.mask = LVCF_TEXT|LVCF_WIDTH|LVCF_FMT;
			column.fmt = LVCFMT_LEFT; // ���������
			column.cx = 40; // ���
			column.pszText = _T("�̷�");
			ListView_InsertColumn(hListView , 0 , &column);

			column.cx = 80; // ���
			column.pszText = _T("��ı���");
			ListView_InsertColumn(hListView ,1 , &column);

			column.cx = 60; // ���
			column.pszText = _T("�ļ�ϵͳ");
			ListView_InsertColumn(hListView , 2 , &column);

			column.cx = 100; // ���
			column.pszText = _T("ʣ��ռ�");
			ListView_InsertColumn(hListView , 3 , &column);

			column.cx = 100; // ���
			column.pszText = _T("�ܿռ�");
			ListView_InsertColumn(hListView , 4 , &column);

			column.cx = 100; // ���
			column.pszText = _T("����������");
			ListView_InsertColumn(hListView , 5 , &column);


			// ��ȡ����������
			TCHAR driveBuff[ MAX_PATH ];
			GetLogicalDriveStrings(MAX_PATH , driveBuff);

			TCHAR *pDriveBuff = driveBuff;
			LV_ITEM item = { 0 };
			item.mask = LVIF_TEXT;

			TCHAR volumeName[ MAX_PATH ];
			TCHAR fileSystemName[ 50 ];

			do 
			{
				*pDriveBuff;
				// �����̷�
				item.pszText = pDriveBuff; // ���̷��������׵�ַ��ֵ
				ListView_InsertItem(hListView , &item);

				GetVolumeInformation(pDriveBuff ,
									 volumeName , MAX_PATH ,
									 0 , 0 , 0 ,
									 fileSystemName , 50);
				
				// ����ı���,�;���ļ�ϵͳ���õ���ǰ�еĽڵ���
				ListView_SetItemText(hListView , item.iItem , 1 , volumeName);
				ListView_SetItemText(hListView , item.iItem , 2 , fileSystemName);

				// �������ռ���Ϣ
				// �ܿռ���Ϣ, ʣ��Ŀռ���Ϣ
				DWORD dwSectorsPerCluster ;
				DWORD dwBytesPerSector;
				DWORD dwNumberOfFreeClusters ;
				DWORD dwTotalNumberOfClusters;
				GetDiskFreeSpace(pDriveBuff ,
								 &dwSectorsPerCluster ,// ÿ��������
								 &dwBytesPerSector , // ÿ���������ֽ���
								 &dwNumberOfFreeClusters ,// ʣ��ռ�Ĵصĸ���
								 &dwTotalNumberOfClusters// �ܿռ�Ĵصĸ���
								 );

				// �����ʣ��ռ���ֽ���
				UINT64 freeByte = 1;
				freeByte = dwNumberOfFreeClusters;
				freeByte *= dwSectorsPerCluster;
				freeByte *= dwBytesPerSector;
				// ������ܿռ���ֽ���
				UINT64 totalByte = 1;
				totalByte = dwTotalNumberOfClusters;
				totalByte *= dwSectorsPerCluster;
				totalByte *= dwBytesPerSector;

				TCHAR buff[ 50 ];
				// �����ε�ֵת�����ַ���
				_stprintf_s(buff , 50 , _T("%I64d") , freeByte);
				// ��ʣ��ռ��ֽ������뵽listview
				ListView_SetItemText(hListView , item.iItem , 3 , buff);

				// �����ε�ֵת�����ַ���
				_stprintf_s(buff , 50 , _T("%I64d") , totalByte);
				// ��ʣ��ռ��ֽ������뵽listview
				ListView_SetItemText(hListView , item.iItem , 4 , buff);

				// ��ȡ����������
				const TCHAR* pType = MyGetDriveType(pDriveBuff);
				ListView_SetItemText(hListView , item.iItem , 5 , (TCHAR*)pType);


				pDriveBuff += 4;
				item.iItem++; // �����Բ��뵽�ڶ���;
			} while(*pDriveBuff);
		}
		break;

		case WM_CLOSE:
			EndDialog(hWnd , 0);

		default: return FALSE;
			break;
	}
	return TRUE;
}

