#include "stdafx.h"
#include "Cganme.h"



void WriteChar(int y, int x, char *pszChar, WORD wArr){
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	COORD loc;
	loc.X = x * 2;
	loc.Y = y;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	printf(pszChar);
}

bool SetWindowSize(CHAR* pszWindowTitle, int nX, int nY)
{
	//���ÿ���̨����
	SetConsoleTitleA(pszWindowTitle);
	HANDLE  hStdln, hStdOut;
	hStdln = GetStdHandle(STD_INPUT_HANDLE);
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//��ȡ������̨�Ĵ�С
	COORD pos = GetLargestConsoleWindowSize(hStdOut);
	COORD buffersize = { pos.X + 1, pos.Y + 1 };
	//���ÿ���̨��������С
	if (!SetConsoleScreenBufferSize(hStdOut, buffersize)){
		printf("buffer err{%d %d}%d\n", buffersize.X, buffersize.Y, GetLastError());
	}
	SMALL_RECT srctWindow = { 0, 0, nX, nY };
	if (!SetConsoleWindowInfo(hStdOut, true, &srctWindow)){
		//���ÿ���̨��С
		printf("size err %d\n", GetLastError());
		return false;
	}
	COORD Buffer = { nX + 1, nY + 1 };
	//���ÿ���̨��������С
	if (!SetConsoleScreenBufferSize(hStdOut, Buffer)){
		//���ÿ���̨���ڻ�����ʧ��
		printf("buffer err{%d %d}%d\n", buffersize.X, buffersize.Y, GetLastError());

	}
	return true;
}

int Cganme::check_helpa = 0;
int Cganme::Max_play = 2;
int Cganme::Goto = 0;
int  Cganme::gamelife = 5;
int Cganme::in_map = 1;
int Cganme::now_map[40][40] = { 0 };
/*
���ܣ�����Ҳ� ��ͣ ������Ϸ�ɹ�ʧ�ܺ��ȥ��
*/
void Cganme::check_help(){

	while (check_helpa == 0)
	{
		if (!_kbhit()) continue;
		unsigned	char cha = _getch();
		switch (cha)
		{
		case 'x':case 'X':
		{
			//�ɹ��˳�			
			in_map = 9;
			check_helpa = 1;
			 myhelp(1);
			//��Ϸʧ��
			//��Ϸ��;�˳�
		}break;
		case 'c':case 'C':{
			check_helpa = 2;
			 myhelp(1);
		}break;
		}
	}
	if (check_helpa == 2){

		check_helpa = 0;
	}
}

/*
���ܣ��ж���Ӯ
a = 1 Ӯ  = 2 ��
*/
void Cganme::Printf_lost_win(int a = 0){
	switch (a)
	{
	case 1:	printf("66666666666666666666666666666�ɹ��ɹ��ɹ��ɹ��ɹ��ɹ��ɹ��ɹ��ɹ�");
		Sleep(2000);
		in_map++;
		break;
	case 2:	printf("99999999999999999999999999999ʧ��ʧ��ʧ��ʧ��ʧ��ʧ��ʧ��ʧ��ʧ��");
		in_map = 9;
		Sleep(2000);
		break;
	}

}
//����ǰIn_map �ĵ�ͼ
void Cganme::DrawMap(){
	if (Goto == 88){
		system("cls");
		system("color 0f");
	} 
	for (int i = 0; i < 40; i++){
		for (int j = 0; j < 40; j++)
		{			
			if (j == 0 || j == 39 || i == 0 || i == 39){
				WriteChar(i, j, WALL1_D, WALL1_DC);
				now_map[i][j] = 1;
			}
			else
			{
				WriteChar(i, j, "  ", H_H_H);
				now_map[i][j] = 0;
			} 
		}

	}


}
//����Ҳ���ʾ
void Cganme::myhelp(int swnumb){
	for (int i = 0; i < 40; i++){
		for (int j = 40; j < 56; j++)
		{
			if (j == 40 || j == 55 || i == 0 || i == 39){

				WriteChar(i, j, WALL1_D, WALL1_DC);
			}
			else
			{
				WriteChar(i, j, "  ", 0);
			}

		}

	}
	switch (swnumb)
	{
	case 1:{

		char gg[] = "  1P����ֵ��         ";
		char gg1[] = "  2P����ֵ��         ";
		char gg2[] = "  ʣ��о�:          ";//0x32 41 4  49
		WriteChar(3, 43, gg, B_H_WHITE | 0);
		WriteChar(5, 43, gg1, B_H_WHITE | 0);
		WriteChar(7, 43, gg2, B_H_WHITE | 0);
	}break;
	case 2:{

		char gg[] = "  ���Ѱ�����ͣ��      ";
		char gg1[] = "  X �˳�             ";
		char gg2[] = "  C ����             ";//0x32 41 4  49
		WriteChar(3, 43, gg, B_H_WHITE | 0);
		WriteChar(5, 43, gg1, B_H_WHITE | 0);
		WriteChar(7, 43, gg2, B_H_WHITE | 0);

	} break;
	}

}
//�����ǰ40*40�ĵ�ͼ
void Cganme::ClearMap(){

	for (int i = 0; i < 40; i++){
		for (int j = 0; j < 40; j++)
		{
			WriteChar(i, j, "  ", 0);

		}
	}


}

 