#include "Data.h"

#include <process.h>
#include <windows.h>

void DrawTank();
void ClerarTank();
void DrawrobotTank();
void ClearrobotTank();
/***
����ͼ
***/
void DrawMap();

//��ӡ��Ļ
void box(int array[40][40], int x, int y);
//���Ʋ˵�
void game_menu(char amenu[11][70]);
/***
����һ�����X��
���������߶�Y��
����������ӡ���ַ�
�����ģ���ӡ�ַ�������
***/
void WriteChar(int y, int x, char *pszChar, WORD wArr);
/***
�������� �����ô�����Ϣ
����һ�����X��
���������߶�Y��
����������ӡ���ַ�
�����ģ���ӡ�ַ�������
***/
bool SetWindowSize(CHAR* pszWindowTitle, int nX, int nY);
