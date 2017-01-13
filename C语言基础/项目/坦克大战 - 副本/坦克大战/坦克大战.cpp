// 8-6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
#include <conio.h>
#include "Data.h"
#include "tank.h"
#include<time.h>
//#include "Data.cpp"
#include <windows.h>
//#include <locale.h>
//enum MyEnum
//{
//
//};
int menu_x = 18;
int menu_y = 5;
int menu_i = 0;//菜单选项

void DrawMap();//绘制地图

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
/*** 
画地图
***/
void DrawMap(){
	//WALL wall; 超强版地图参数 暂时不用



	for (int i = 0; i < 40; i++){
		for (int j = 0; j < 40; j++)
		{
			if (sysMap00[i][j] == 1){
				WriteChar(i, j, "  ",  0 );
			}
			else if (sysMap00[i][j] == 2){

				WriteChar(i, j, "▓", F_YELLOW);
			}
			else if (sysMap00[i][j] == 3){
				WriteChar(i, j, "卍", F_YELLOW);
			}
			else if (sysMap00[i][j] == 4){
				WriteChar(i, j, "〓",  F_YELLOW);
			}
			else if (sysMap00[i][j] == 5){
				WriteChar(i, j, "≈", F_YELLOW);
			}
			else if (sysMap00[i][j] == 6){
				WriteChar(i, j, "■", B_H_WHITE );
			}
			else if (sysMap00[i][j] == 7){
				WriteChar(i, j, "≡", F_YELLOW);
			} //else{}
		}

	}
}
WCHAR GetKeyInput(){
	if (_kbhit()) { return _getwch(); }//多字节版本为_getch()
	return 0;
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

void DrawrobotTank(){
	int tposition = tankRobot.t_position;


	for (int i = 0, lie =  tankRobot.m_y - 1; i < 3; lie++, i++){
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

void Firstball(){
	for (int i = 0; i < 256;i++)
	{
		//如果当前数组子弹还在运行 就不遍历下一个
		if (myball[i].isBullet != 0)
		{
			continue;
		}
		else
		{
			switch (tankfire.t_position)
			{
			case 0:
			{

				myball[i].b_x = tankfire.m_x;
				myball[i].b_y = tankfire.m_y - 2;

			}break;
			case 1:
			{
				myball[i].b_x = tankfire.m_x;
				myball[i].b_y = tankfire.m_y + 2;

			}break;
			case 2:
			{
				myball[i].b_x = tankfire.m_x - 2;
				myball[i].b_y = tankfire.m_y;

			}break;
			case 3:
			{
			
				myball[i].b_x = tankfire.m_x+2;
				myball[i].b_y = tankfire.m_y;

			}break;

			default:
				break;
			}
			myball[i].b_type     = 1;
			myball[i].isBullet   = true;
			myball[i].b_position = tankfire.t_position;
			
			//myball[i].t_ball[i] = '*';
			WriteChar(myball[i].b_y, myball[i].b_x, "⊙", 0 | F_H_GREEN);
			//my_fast_ball();
			break;
		}

	}

}
bool cheak_bump();
void my_fast_ball()
{
	for (int i = 0; i < 256;i++)
	{
		//myball[i]
		if (myball[i].isBullet == 0)
		{
			continue;
		} else
		{
			int a = 0;
			
 			switch (myball[i].b_position)
 			{
 			case 0:
 			{
 				/*
		超强版 以后再弄
		WALL* objWall = (WALL*) &sysMap00[myball[i].b_y + 1][myball[i].b_x];
			switch (objWall->nType)
			{
			case 1:
				objWall->nXue;
				break;
			}*/
				
				if (sysMap00[myball[i].b_y-1][myball[i].b_x] == 6)
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
					//WriteChar(myball[i].b_y, myball[i].b_x + 1, "  ", 0 | 0);

					myball[i].isBullet = 0;
					continue;
				}
				//河流 丛林 高速路 箱子 子弹经过不会清除 选择不打印子弹 坐标增加
				else if ((sysMap00[myball[i].b_y][myball[i].b_x] == 5) || (sysMap00[myball[i].b_y][myball[i].b_x] == 7) || (sysMap00[myball[i].b_y][myball[i].b_x] == 8) || (sysMap00[myball[i].b_y][myball[i].b_x] == 9))
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
					WriteChar(myball[i].b_y, myball[i].b_x, "≈", B_H_WHITE);
				}
				//
				else if (sysMap00[myball[i].b_y - 1][myball[i].b_x] > 1 && sysMap00[myball[i].b_y - 1][myball[i].b_x] < 5)
 				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | 0);
					WriteChar(myball[i].b_y - 1, myball[i].b_x, "  ", 0 | 0);
					myball[i].isBullet = 0;
 					//尝试子弹计算墙体厚度;
					if (sysMap00[myball[i].b_y][myball[i].b_x] == 2){ 					 
						WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | 0);
 					}
					sysMap00[myball[i].b_y - 1][myball[i].b_x]--;
 					continue; 
				}
				else
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0);
				}
				myball[i].b_y--;


			}break;
			case 1:
			{
				if (sysMap00[myball[i].b_y + 1][myball[i].b_x] == 6)
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
				//WriteChar(myball[i].b_y, myball[i].b_x + 1, "  ", 0 | 0);

				myball[i].isBullet = 0;
				continue;
			}
			//河流 丛林 高速路 箱子 子弹经过不会清除 选择不打印子弹 坐标增加
				else if ((sysMap00[myball[i].b_y][myball[i].b_x] == 5) || (sysMap00[myball[i].b_y][myball[i].b_x] == 7) || (sysMap00[myball[i].b_y][myball[i].b_x] == 8) || (sysMap00[myball[i].b_y][myball[i].b_x] == 9))
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
					WriteChar(myball[i].b_y, myball[i].b_x, "≈", B_H_WHITE);
				}
				else if (sysMap00[myball[i].b_y + 1][myball[i].b_x] > 1 && sysMap00[myball[i].b_y + 1][myball[i].b_x] < 5)
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | 0);
					WriteChar(myball[i].b_y + 1, myball[i].b_x, "  ", 0 | 0);
					myball[i].isBullet = 0;
					//尝试子弹计算墙体厚度;
					if (sysMap00[myball[i].b_y + 1][myball[i].b_x] == 2){
						WriteChar(myball[i].b_y + 1, myball[i].b_x, "  ", 0 | 0);
					}
					sysMap00[myball[i].b_y + 1][myball[i].b_x]--;
					continue;
				}
				else
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0);
				}
				myball[i].b_y++;
			}break;
			case 2:
			{
				if (sysMap00[myball[i].b_y][myball[i].b_x-1] == 6)
				{
				WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
				//WriteChar(myball[i].b_y, myball[i].b_x + 1, "  ", 0 | 0);

				myball[i].isBullet = 0;
				continue;
			}
			//河流 丛林 高速路 箱子 子弹经过不会清除 选择不打印子弹 坐标增加
				else if ((sysMap00[myball[i].b_y][myball[i].b_x] == 5) || (sysMap00[myball[i].b_y][myball[i].b_x] == 7) || (sysMap00[myball[i].b_y][myball[i].b_x] == 8) || (sysMap00[myball[i].b_y][myball[i].b_x] == 9))
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
					WriteChar(myball[i].b_y, myball[i].b_x, "≈", B_H_WHITE);
				}
				else if (sysMap00[myball[i].b_y][myball[i].b_x - 1] > 1 && sysMap00[myball[i].b_y][myball[i].b_x - 1] < 5)
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | 0);
					WriteChar(myball[i].b_y, myball[i].b_x - 1, "  ", 0 | 0);
					myball[i].isBullet = 0;
					//尝试子弹计算墙体厚度;
					if (sysMap00[myball[i].b_y][myball[i].b_x - 1] == 2){
						WriteChar(myball[i].b_y, myball[i].b_x - 1, "  ", 0 | 0);
					}
					sysMap00[myball[i].b_y][myball[i].b_x - 1]--;
					continue;
				}
				else
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0);
				}
				myball[i].b_x--;

			}break;
			case 3:
			{
				if (sysMap00[myball[i].b_y][myball[i].b_x+1] == 6)
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0);
					//WriteChar(myball[i].b_y, myball[i].b_x + 1, "  ", 0 | 0);
					
					myball[i].isBullet = 0;
					continue;
				}
				//河流 丛林 高速路 箱子 子弹经过不会清除 选择不打印子弹 坐标增加
				else if ((sysMap00[myball[i].b_y][myball[i].b_x] == 5) || (sysMap00[myball[i].b_y][myball[i].b_x + 1] == 7 )||(sysMap00[myball[i].b_y][myball[i].b_x + 1] == 8) || (sysMap00[myball[i].b_y][myball[i].b_x + 1] == 9))
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
					WriteChar(myball[i].b_y, myball[i].b_x, "≈", B_H_WHITE);
					///WriteChar(myball[i].b_y, myball[i].b_x + 1, "≈", 0 | 0);
				}
				else if (sysMap00[myball[i].b_y][myball[i].b_x + 1] > 1 && sysMap00[myball[i].b_y][myball[i].b_x + 1] < 5)
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | 0);
					WriteChar(myball[i].b_y, myball[i].b_x - 1, "  ", 0 | 0);
					myball[i].isBullet = 0;
					//WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
					//尝试子弹计算墙体厚度;
					if (sysMap00[myball[i].b_y][myball[i].b_x + 1] == 2){
						WriteChar(myball[i].b_y, myball[i].b_x + 1, "  ", 0 | 0);
					}
					//
					sysMap00[myball[i].b_y][myball[i].b_x + 1]--;
					continue;
				}
				else
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0);
				}
				
				myball[i].b_x++;

			}break;
			default:
				break;
			}
			 
		
			 
			WriteChar(myball[i].b_y, myball[i].b_x, "⊙", 0 | F_H_GREEN);
			}
	
	}
}

void Firstballa(){
	for (int i = 0; i < 256; i++)
	{
		//如果当前数组子弹还在运行 就不遍历下一个
		if (myball[i].isBullet != 0)
		{
			continue;
		}
		else
		{
			switch (tankRobot.t_position)
			{
			case 0:
			{
				if ((tankRobot.m_y - 2) > 1 && tankRobot.m_x < 39 ){

					myball[i].b_x = tankRobot.m_x;
					myball[i].b_y = tankRobot.m_y - 2;
				}
				

			}break;
			case 1:
			{
				if ((tankRobot.m_y + 2) < 38 && tankRobot.m_x < 39){
					myball[i].b_x = tankRobot.m_x;
					myball[i].b_y = tankRobot.m_y + 2;

				}
			}break;
			case 2:
			{
				if ((tankRobot.m_x - 2) < 38 && tankRobot.m_y < 39)
				{
				myball[i].b_x = tankRobot.m_x - 2;
				myball[i].b_y = tankRobot.m_y;
				}
			}break;
			case 3:
			{
				if ((tankRobot.m_x + 2) < 38 && tankRobot.m_y < 39){
					myball[i].b_x = tankRobot.m_x + 2;
					myball[i].b_y = tankRobot.m_y;
				}
			}break;

			default:
				break;
			}
			myball[i].b_type = 1;
			myball[i].isBullet = true;
			myball[i].b_position = tankRobot.t_position;

			//myball[i].t_ball[i] = '*';
			WriteChar(myball[i].b_y, myball[i].b_x, "⊙", 0 | F_H_GREEN);
			//my_fast_ball();
			break;
		}

	}

}
//坦克的检测碰撞
bool cheak_bump(){
	
	int x = tankfire.m_x;
	int y = tankfire.m_y;
		switch (tankfire.t_position)
		{
		case 0:
		{
			if (sysMap00[y - 2][x + 1] > 1 && sysMap00[y - 2][x + 1] < 7 ||
				sysMap00[y - 2][x] > 1 && sysMap00[y - 2][x] < 7 ||
				sysMap00[y - 2][x - 1] > 1 && sysMap00[y - 2][x - 1] < 7)
			{
				
				return FALSE;
				break;
			}
			 

		}break;
		case 1:
		{
			if (sysMap00[y + 2][x + 1] > 1 && sysMap00[y + 2][x + 1] < 7 ||
				sysMap00[y + 2][x] > 1 && sysMap00[y + 2][x] < 7 ||
				sysMap00[y + 2][x - 1] > 1 && sysMap00[y + 2][x - 1] < 7)
			{

				return FALSE;
				break;
			}

		}break;
		case 2:
		{
			if (sysMap00[y + 1][x - 2] > 1 && sysMap00[y+1][x - 2] < 7 ||
				sysMap00[y][x - 2] > 1 && sysMap00[y][x - 2] < 7 ||
				sysMap00[y-1][x - 2] > 1 && sysMap00[y - 1][x - 2] < 7)
			{

				return FALSE;
				break;
			}

		}break;
		case 3:
		{
			if (sysMap00[y + 1][x + 2] > 1 && sysMap00[y + 1][x + 2] < 7 ||
				sysMap00[y][x + 2] > 1 && sysMap00[y][x + 2] < 7 ||
				sysMap00[y - 1][x + 2] > 1 && sysMap00[y - 1][x + 2] < 7)
			{

				return FALSE;
				break;
			}

		}break;

		default:
			break;
		}
		return true;
	
}


bool cheak_rebotbump(){

	int x = tankRobot.m_x;
	int y = tankRobot.m_y;
	switch (tankRobot.t_position)
	{
	case UP:
	{								
		if (sysMap00[y - 3][x + 1] >1 || sysMap00[y - 3][x    ] >1 || sysMap00[y - 3][x - 1] >1 )
		{

			return FALSE;
			break;
		}


	}break;
	case DOWN:
	{															 
		if (sysMap00[y + 3][x + 1] > 1 ||
			sysMap00[y + 3][x    ] > 1 ||
			sysMap00[y + 3][x - 1] > 1)
		{

			return FALSE;
			break;
		}

	}break;
	case LEFT:
	{		//距离
		if (sysMap00[y + 1][x - 3] > 1  ||
			sysMap00[y    ][x - 3] > 1  ||
			sysMap00[y - 1][x - 3] > 1 )
		{

			return FALSE;
			break;
		}

	}break;
	case RIGHT:
	{
		if (sysMap00[y + 1][x + 3] > 1  ||
			sysMap00[y    ][x + 3] > 1  ||
			sysMap00[y - 1][x + 3] > 1 )
		{

			return FALSE;
			break;
		}

	}break;

	default:
		break;
	}
	return true;

}

void Robot_tank(){
	//DrawrobotTank();
		int aa = rand() % 6;
		switch (aa)
		 {
		 case 1:
		 {
			 //尝试修复 不能解决因为距离 坦克打印屏蔽地图元素的问题 以后有时间再处理 
			 /*for (int i = 0; i < 3; i++)
			 {
				 ClearrobotTank();
				 tankRobot.t_position = i;
				 DrawrobotTank();
				 //检测通过
				 if (cheak_rebotbump() ){
					 //方向正确 坐标减一
					 if (tankRobot.t_position == UP){
						 ClearrobotTank();
						 tankRobot.m_y = tankRobot.m_y - 1;
						 DrawrobotTank();
					 }
					 else
					 {
						 ClearrobotTank();
						 DrawrobotTank();
						 
					 }
					 break;
				 }
			 }*/
			 /*else{
				 tankRobot.m_y = tankRobot.m_y - 1;



				 }*/
			 bool cheak_bumpa = cheak_rebotbump();
			 if (cheak_bumpa)
			 {
				 //WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
				 ClearrobotTank();
				 tankRobot.m_y = tankRobot.m_y - 1;
				 tankRobot.t_position = 0;
				 DrawrobotTank();
			 }
			 else{
				 ClearrobotTank();

				 tankRobot.t_position = 1;
				 DrawrobotTank();
				// tankRobot.m_y = tankRobot.m_y + 1;
				 // tankRobot.m_y = tankRobot.m_y + 1;
			 }
		 }break;
		 case 2:
		 {

			 bool cheak_bumpa = cheak_rebotbump();
			 if (cheak_bumpa)
			 {
				 //WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
				 ClearrobotTank();
				 tankRobot.m_y = tankRobot.m_y + 1;
				 tankRobot.t_position = 1;
				 DrawrobotTank();
			 }
			 else{
				 ClearrobotTank();

				 tankRobot.t_position = 0;
				 DrawrobotTank();
				// tankRobot.m_y = tankRobot.m_y - 1;
				 // tankRobot.m_y = tankRobot.m_y + 1;
			 }

			 //WriteChar(menu_y, menu_x, menu_char, wArr);

			 // 操作坦克
		 }break;

		 case 3:
		 {

			 bool cheak_bumpa = cheak_rebotbump();
			 if (cheak_bumpa)
			 {//WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
				 ClearrobotTank();
				 tankRobot.m_x = tankRobot.m_x - 1;
				 tankRobot.t_position = 2;
				 DrawrobotTank();
			 }
			 else
			 {

				 //方向判断不对 就进行清楚 打印反方向坦克 
				 ClearrobotTank();
				 //
				 tankRobot.t_position = 3;
				 DrawrobotTank();
				 
				 // tankRobot.m_x = tankRobot.m_x - 1;
			 }
			 //WriteChar(menu_y, menu_x, menu_char, wArr);

			 // 操作坦克
		 }break;
		 
		 case 4:
		 {
			
			 bool cheak_bumpa = cheak_rebotbump();
			 if (cheak_bumpa)
			 {//WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
				 ClearrobotTank();
				 tankRobot.m_x = tankRobot.m_x + 1;
				 tankRobot.t_position = 3;
				 DrawrobotTank();
			 }
			 else
			 {
				 ClearrobotTank();
				
				 tankRobot.t_position = 2;
				 DrawrobotTank();
				// tankRobot.m_x = tankRobot.m_x - 1;
				 //tankRobot.m_x = tankRobot.m_x + 1;
			 }
			 //WriteChar(menu_y, menu_x, menu_char, wArr);

			 // 操作坦克
		 } case 5:
		 {
			// Firstballa();
			 // 发射子弹  没做子弹判断敌我
		 }break;
		 default:
			 break;
		 }
	
		//}
	
	//DrawrobotTank();
}
void MoveTank(){
	int i = 0;
	while (1)
	{
		if (i%3000==0)
		{
		//Robot_tank();//自动操作坦克
			my_fast_ball();
			i = 0;
		}
	
		i++;
		if (_kbhit()){
		  unsigned	char ch = _getch();
			
			if (ch==0xe0)
			{
				char ch1 = _getch();
				 ch = ch1;
			}
			
		switch (ch)
			{
				
		case 'w':case 'W':case 'H':
			{

				
					tankfire.t_position = 0;
					bool cheak_bumpa = cheak_bump();
					if (cheak_bumpa)
					{//WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
					ClerarTank();
					tankfire.m_y = tankfire.m_y - 1;
					
					DrawTank();
					}
					//WriteChar(menu_y, menu_x, menu_char, wArr);
				
				// 操作坦克
			}break;
		case 's':case 'S':case 'P':
			{
				tankfire.t_position = 1;
				bool cheak_bumpa = cheak_bump();
					
					
					if (cheak_bumpa){
						ClerarTank();
					tankfire.m_y = tankfire.m_y + 1;
				
					DrawTank();
					
				}
				// 操作坦克
			}break;
			//确定选择 开始进入判断做什么功能的操作 传Y坐标
		
			case 'a':case 'A':case 'K':
			{
				
					
					tankfire.t_position = 2;
					bool cheak_bumpa = cheak_bump();
					if (cheak_bumpa){
						ClerarTank();
						tankfire.m_x = tankfire.m_x - 1;

						DrawTank();
					}
				// 操作坦克
			}break;
			case 'd':case 'D':case 'M':
			{
				
					
					
					tankfire.t_position = 3;
					bool cheak_bumpa = cheak_bump();
					if (cheak_bumpa){
					ClerarTank();
					tankfire.m_x = tankfire.m_x + 1;
				
					DrawTank();
				}
				// 操作坦克
			}break;
			// 游戏退出
			case 'j':case 'J':
			{
				Firstball();
				// 游戏退出
			}break;
			case 'q':case 'Q':
			{
			
			}break;
			case '\r':
			{
				if (menu_i == 0){
					system("cls");
					menu_i++;
					game_menu(start_menu);
				}
				if (menu_i == 2){
					system("cls");
					menu_i++;
					//strcpy(g_nMap, sysMap00 );
					DrawMap();
				}
				// 游戏退出
			}break;
			default:
				break;
			}

		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	

	
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;//是否显示光标
	SetConsoleTitle(L"坦克大战");
	game_menu(g_game_menu);
	WORD wArr = FOREGROUND_INTENSITY;
	char menu_char[10] = ">>";
	char menu_char1[10] = "   "; 
	int menu_max_cy = 7;
	int menu_min_cy = 4;
	WriteChar(5, 18, menu_char, wArr);
	//getchar();

	//菜单判断
	
	while ( menu_i < 4)
	{
		if (menu_i == 1){ 
			menu_y = 4;
			menu_max_cy = 5;
			menu_min_cy = 4;
			menu_i = 2;
			//WriteChar(4, 18, menu_char, wArr);
		}
		if (_kbhit()){
		  unsigned	char ch = _getch();
			
			if (ch==0xe0)
			{
				char ch1 = _getch();
				 ch = ch1;
			}
		switch (ch)
			{
		case 'w':case 'W':case 'H':
			{
				if (menu_y > menu_min_cy)
				{
					WriteChar(menu_y, menu_x, menu_char1, wArr);
					menu_y = menu_y - 1;

					WriteChar(menu_y, menu_x, menu_char, wArr);
				}
				// 操作坦克
			}break;
		case 's':case 'S':case 'P':
			{
				if (menu_y < menu_max_cy)
				{ 
					WriteChar(menu_y, menu_x, menu_char1, wArr);
					menu_y = menu_y + 1;
					WriteChar(menu_y, menu_x, menu_char, wArr);
				}
				// 操作坦克
			}break;
			//确定选择 开始进入判断做什么功能的操作 传Y坐标
			case '\r':
			{
			if (menu_i == 0){
					system("cls");
				menu_i++;
				game_menu(start_menu);
				}
				if (menu_i == 2){
					system("cls");
					menu_i++;
					//strcpy(g_nMap, sysMap00 );
					DrawMap();
					DrawTank();
					MoveTank();
				}
				// 游戏退出
			}break;
			case 'a':case 'A':
			{
				// 操作坦克
			}break;
			case 'd':case 'D': 
			{
				
				// 操作坦克
			}break;
			case 'q':case 'Q':
			{
				// 游戏退出
			}break;
			default:
				break;
			}

		}
	}


	////坦克大战键盘判断
	//while (1)
	//{
	//	if (_kbhit()){
	//		char ch = _getch();
	//		switch (ch)
	//		{
	//		case 'w':case 'W':case 0xe048:
	//		{
	//		// 操作坦克
	//		}break;
	//		case 's':case 'S':
	//		{
	//			// 操作坦克
	//		}break;
	//		case 'a':case 'A':
	//		{
	//			// 操作坦克
	//		}break;
	//		case 'd':case 'D':
	//		{
	//			// 操作坦克
	//		}break;
	//		case 'q':case 'Q':
	//		{
	//			// 游戏退出
	//		}break;
	//		default:
	//			break;
	//		}

	//	}
	//}
	//showtan();
//	system("pause");
	return 0;
}