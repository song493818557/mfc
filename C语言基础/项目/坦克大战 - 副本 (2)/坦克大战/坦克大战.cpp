// 8-6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include "tank.h"
//#include <locale.h>
//enum MyEnum
//{
//
//};


WCHAR GetKeyInput(){
	if (_kbhit()) { return _getwch(); }//多字节版本为_getch()
	return 0;
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


	
	return 0;
}