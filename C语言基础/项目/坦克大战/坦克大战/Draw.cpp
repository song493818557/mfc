#pragma once
#include "stdafx.h"
#include "Draw.h"

void DrawTank(){
	int tposition = tankfire.t_position;


	for (int i = 0, lie = tankfire.m_y - 1; i < 3; lie++, i++){
		for (int j = 0, hang = tankfire.m_x - 1; j < 3; hang++, j++){
			//WriteChar(tankfire.m_y, tankfire.m_x, "■", ' ');
			if (tankfire.t_demo[tposition][i][j] == 1){

				WriteChar(lie, hang, "■", F_WHITE);
			}
			//printf("%d", tankfire.t_demo[tposition][i][j]);
		}
		printf("\n");
	}
}
void ClerarTank(){
	int tposition = tankfire.t_position;


	for (int i = 0, lie = tankfire.m_y - 1; i < 3; lie++, i++){
		for (int j = 0, hang = tankfire.m_x - 1; j < 3; hang++, j++){
			//WriteChar(tankfire.m_y, tankfire.m_x, "■", ' ');
			WriteChar(lie, hang, "  ", F_WHITE);
			//printf("%d", tankfire.t_demo[tposition][i][j]);
		}
		printf("\n");
	}
}
void DrawrobotTank(){
	int tposition = tankRobot.t_position;


	for (int i = 0, lie = tankRobot.m_y - 1; i < 3; lie++, i++){
		for (int j = 0, hang = tankRobot.m_x - 1; j < 3; hang++, j++){
			//WriteChar(tankfire.m_y, tankfire.m_x, "■", ' ');
			if (tankRobot.t_demo[tposition][i][j] == 1){

				WriteChar(lie, hang, "■", B_H_CYAN);
			}
			//printf("%d", tankfire.t_demo[tposition][i][j]);
		}
		printf("\n");
	}
}
void ClearrobotTank(){
	int tposition = tankRobot.t_position;


	for (int i = 0, lie = tankRobot.m_y - 1; i < 3; lie++, i++){
		for (int j = 0, hang = tankRobot.m_x - 1; j < 3; hang++, j++){
			//WriteChar(tankfire.m_y, tankfire.m_x, "■", ' ');
			if (tankRobot.t_demo[tposition][i][j] == 1){
				//WriteChar(lie, hang, "  ", 0);
				WriteChar(lie, hang, "  ", B_RED);
			}
			//printf("%d", tankfire.t_demo[tposition][i][j]);
		}
		printf("\n");
	}
}
/***
画地图
***/
void DrawMap(){
	//WALL wall; 超强版地图参数 暂时不用
	for (int i = 0; i < 40; i++){
		for (int j = 0; j < 40; j++)
		{
			if (sysMap00[i][j] == 1){
				WriteChar(i, j, "  ", 0);
			}
			else if (sysMap00[i][j] == 2){

				WriteChar(i, j, "▓", F_YELLOW);
			}
			else if (sysMap00[i][j] == 3){
				WriteChar(i, j, "卍", F_YELLOW);
			}
			else if (sysMap00[i][j] == 4){
				WriteChar(i, j, "〓", F_YELLOW);
			}
			else if (sysMap00[i][j] == 5){
				WriteChar(i, j, "≈", F_YELLOW);
			}
			else if (sysMap00[i][j] == 6){
				WriteChar(i, j, "■", B_H_WHITE);
			}
			else if (sysMap00[i][j] == 7){
				WriteChar(i, j, "≡", F_YELLOW);
			}
			else if (sysMap00[i][j] == 8){
				WriteChar(i, j, "※", F_YELLOW);
			} //else{}
		}

	}
}

//打印屏幕
void box(int array[40][40], int x, int y){
	system("cls");
	for (int i = 0; i <= 40; i++){

		for (int j = 0; j <= 40; j++){
			if (i == 0 || i == 40 || j == 0 || j == 40){
				array[i][j] = 1;
			}
			if (array[i][j] == 1){
				printf("■");
			}
			else{
				printf("  ");
			}

			/*
			array[i] = array[i] + array[n - i];
			array[n - i] = array[i] - array[n - i];
			array[i] = array[i] - array[n - i];*/
		}
		printf("\n");
	}
	int aac = 0;
	return;
}
//绘制菜单
void game_menu(char amenu[11][70])
{

	for (int i = 0; i < 11; i++){
		//for (int j = 0; j <= i; j++){
		//}
		printf("%s", amenu[i]);

		printf("\n");
	}



	// 
}
/***
参数一：宽度X行
参数二：高度Y行
参数三：打印的字符
参数四：打印字符的属性
***/
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
/***
函数功能 ：设置窗口信息
参数一：宽度X行
参数二：高度Y行
参数三：打印的字符
参数四：打印字符的属性
***/
bool SetWindowSize(CHAR* pszWindowTitle, int nX, int nY){
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
