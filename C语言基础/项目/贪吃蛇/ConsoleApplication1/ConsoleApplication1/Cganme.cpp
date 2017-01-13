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
	//设置控制台标题
	SetConsoleTitleA(pszWindowTitle);
	HANDLE  hStdln, hStdOut;
	hStdln = GetStdHandle(STD_INPUT_HANDLE);
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//获取最大控制台的大小
	COORD pos = GetLargestConsoleWindowSize(hStdOut);
	COORD buffersize = { pos.X + 1, pos.Y + 1 };
	//设置控制台缓冲区大小
	if (!SetConsoleScreenBufferSize(hStdOut, buffersize)){
		printf("buffer err{%d %d}%d\n", buffersize.X, buffersize.Y, GetLastError());
	}
	SMALL_RECT srctWindow = { 0, 0, nX, nY };
	if (!SetConsoleWindowInfo(hStdOut, true, &srctWindow)){
		//设置控制台大小
		printf("size err %d\n", GetLastError());
		return false;
	}
	COORD Buffer = { nX + 1, nY + 1 };
	//设置控制台缓冲区大小
	if (!SetConsoleScreenBufferSize(hStdOut, Buffer)){
		//设置控制台窗口缓冲区失败
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
功能：检测右侧 暂停 或者游戏成功失败后的去向
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
			//成功退出			
			in_map = 9;
			check_helpa = 1;
			 myhelp(1);
			//游戏失败
			//游戏中途退出
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
功能：判断输赢
a = 1 赢  = 2 输
*/
void Cganme::Printf_lost_win(int a = 0){
	switch (a)
	{
	case 1:	printf("66666666666666666666666666666成功成功成功成功成功成功成功成功成功");
		Sleep(2000);
		in_map++;
		break;
	case 2:	printf("99999999999999999999999999999失败失败失败失败失败失败失败失败失败");
		in_map = 9;
		Sleep(2000);
		break;
	}

}
//画当前In_map 的地图
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
//输出右侧显示
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

		char gg[] = "  1P生命值：         ";
		char gg1[] = "  2P生命值：         ";
		char gg2[] = "  剩余敌军:          ";//0x32 41 4  49
		WriteChar(3, 43, gg, B_H_WHITE | 0);
		WriteChar(5, 43, gg1, B_H_WHITE | 0);
		WriteChar(7, 43, gg2, B_H_WHITE | 0);
	}break;
	case 2:{

		char gg[] = "  你已按下暂停键      ";
		char gg1[] = "  X 退出             ";
		char gg2[] = "  C 继续             ";//0x32 41 4  49
		WriteChar(3, 43, gg, B_H_WHITE | 0);
		WriteChar(5, 43, gg1, B_H_WHITE | 0);
		WriteChar(7, 43, gg2, B_H_WHITE | 0);

	} break;
	}

}
//清除当前40*40的地图
void Cganme::ClearMap(){

	for (int i = 0; i < 40; i++){
		for (int j = 0; j < 40; j++)
		{
			WriteChar(i, j, "  ", 0);

		}
	}


}

 