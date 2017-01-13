#include <windows.h>
#include "resource.h"
#include <tchar.h>  
#define  DRAW_LINE 1 //ֱ��
#define  DRAW_ELLI 2 //��Բ
#define  DRAW_RECT 3 //����

INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
DWORD  g_dwChoose;//��ǰѡ��ļ���ͼ�� 1=>ֱ��

POINT g_begPos; //��ʼ����
POINT g_endPos; //��������
HDC g_hMemDC; //�ڴ����DC
HDC g_hClientDC; //���ڿͻ���DC

INT_PTR CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd){

	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc); 
}
VOID CALLBACK OnInitDialog(HWND hWnd){
	
	HWND radio = GetDlgItem(hWnd, IDC_RADIO1);
	//���õ�ѡ��ť�����ϵ�Ч��
	SendMessage(radio, BM_SETCHECK, 1, 0);
	//���͵�ѡ��ťʱ����Ϣ
	SendMessage(hWnd, WM_COMMAND, MAKEWPARAM(IDC_RADIO1, 0), (LPARAM)radio);
	g_hClientDC = GetDC(hWnd);//���ڿͻ���DC
	g_hMemDC = CreateCompatibleDC(g_hClientDC); //�����ڿͻ�������һ�ݵ��ڴ�DC
	RECT rt;
	GetClientRect(hWnd, &rt);
	HBITMAP hBitmap = CreateCompatibleBitmap(g_hClientDC, rt.right, rt.bottom);
	//���ڴ����λͼѡ�뵽�ڴ����DC�� 
	//����ڴ����DC��û���ڴ����λͼ  ���޷�ֱ�����������ͼ����
	SelectObject(g_hMemDC, hBitmap);
	//����һ����ˢ
	//�ѻ�ˢѡ���ڴ����DC��
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	//����ˢѡ�뵽�ڴ����DC��
	SelectObject(g_hMemDC, hBrush);

	//ʹ�û����εĺ��� ���ڴ����DC�ı���ˢһ�� 
	//�ڻ����εĴ����ѹ��� ������ʹ���ڴ����DC�����е�GDI����
	//������ڴ�
	Rectangle(g_hMemDC, 10, 10, rt.right, rt.bottom);

}
INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	static bool bIsLbuttonDowm = false;
	switch (uMsg)
	{
		
			case WM_INITDIALOG:{
				OnInitDialog(hWnd);
			}break; 
			case  WM_COMMAND:{
				switch (LOWORD(wParam))  //�жϷ�����WM_COMMAND�Ĵ���ID
				{
				case IDC_RADIO1:g_dwChoose = DRAW_LINE; break; 
				case IDC_RADIO2:g_dwChoose = DRAW_ELLI; break;
				case IDC_RADIO3:g_dwChoose = DRAW_RECT; break;
				}
			}break;
			case WM_LBUTTONDOWN:{
				bIsLbuttonDowm = true;
				g_begPos.x = LOWORD(lParam);
				g_begPos.y = HIWORD(lParam);

			}break;
			case WM_MOUSEMOVE:{
				if (bIsLbuttonDowm)
				{
					g_endPos.x = LOWORD(lParam);
					g_endPos.y = HIWORD(lParam);
					//��ȡ�ͻ����Ĵ�С
					RECT rt;
					GetClientRect(hWnd, &rt);

					// ���ڴ�DC�����ݿ���������DC��
					BitBlt(g_hClientDC,/*Ŀ��DC*/
						0, 0, /*��ʼ����*/
						rt.right, rt.bottom,/*�ߺͿ�*/
						g_hMemDC,  /*ԴDC*/
						0, 0,/*ԴDC�������Ŀ�ʼ����*/
						SRCCOPY/*ֻ�����ı�־*/
						);
					MoveToEx(g_hClientDC, g_begPos.x, g_begPos.y, 0);
					LineTo(g_hClientDC, g_endPos.x, g_endPos.y);
				} 
			}break;
			case WM_LBUTTONUP:{
				bIsLbuttonDowm = FALSE;
				g_endPos.x = LOWORD(lParam);
				g_endPos.y = HIWORD(lParam);
				//���ڴ���DC�Ͻ��л���
				switch (g_dwChoose)
				{ 
				case DRAW_LINE:
					//�Ȼ���ֱ��
				{
					MoveToEx(g_hClientDC, g_begPos.x, g_begPos.y, 0);
					LineTo(g_hClientDC, g_endPos.x, g_endPos.y); }
					break;
				case DRAW_RECT: Rectangle(g_hClientDC, g_begPos.x, g_begPos.y, g_endPos.x, g_endPos.y); break;

				case DRAW_ELLI:{
					HBRUSH hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
					SelectObject(g_hClientDC, hBrush);
					Ellipse(g_hClientDC, g_begPos.x, g_begPos.y, g_endPos.x, g_endPos.y);
				} break;
				}
				RECT rt;
				GetClientRect(hWnd, &rt);
				// ���ڴ�DC�����ݿ���������DC��
				BitBlt(g_hMemDC,/*Ŀ��DC*/
					0, 0, /*��ʼ����*/
					rt.right, rt.bottom,/*�ߺͿ�*/
					g_hClientDC,  /*ԴDC*/
					0, 0,/*ԴDC�������Ŀ�ʼ����*/
					SRCCOPY/*ֻ�����ı�־*/
					);
				//����Ч����ȫ����Ϊ��Ч
				InvalidateRect(hWnd, NULL, FALSE);
			
			}break;
			case WM_PAINT:{
				PAINTSTRUCT ps = { 0 };
				//��ȡ��Ч����
				BeginPaint(hWnd,&ps);
				RECT rt;
				//��ȡ�ͻ�����С
				GetClientRect(hWnd, &rt);
				//���ڴ�DC�����ݿ���������DC��
				BitBlt(g_hClientDC,/*Ŀ��DC*/
					0, 0, /*��ʼ����*/
					rt.right, rt.bottom,/*�ߺͿ�*/
					g_hMemDC,  /*ԴDC*/
					0, 0,/*ԴDC�������Ŀ�ʼ����*/
					SRCCOPY/*ֻ�����ı�־*/
					);
				//����Ч����ȫ����Ϊ��Ч
				EndPaint(hWnd, &ps);

			}break;
			case  WM_DESTROY:{
				//�ͷ�DC
				DeleteDC(g_hMemDC); //�ڴ�DC
				ReleaseDC(hWnd, g_hMemDC);//�ͻ��˴���DC
			}break;
			case WM_CLOSE:{
				EndDialog(hWnd, 0);  
			}break;
			default: return FALSE;  
	}
	return true;
}