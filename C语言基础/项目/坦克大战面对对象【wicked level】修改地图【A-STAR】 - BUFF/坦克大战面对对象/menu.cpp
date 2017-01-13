#pragma once
#include "stdafx.h"  
#include "menu.h" 
#include <conio.h>


//int  Cmap::check_helpa = 0;
//int  Cmap::Max_play = 0;//当前游戏最大玩家数
//int  Cmap::Goto = 0;//去地图编辑还是去坦克大战
//int  Cmap::Tank_life = 5;//我方坦克生命值
//int  Cmap::Max_Rebottank = 3;//机器人坦克
//int  Cmap::max_kill = 3;//最大击杀数
//int  Cmap::now_max_kill = 0;//最大击杀数
//int  Cmap::in_map = 2;//当前地图
//int  Cmap::check_Rebottank = 0;//初始化当前活着的我方坦克数量
//int  Cmap::check_play = 0;//初始化当前活着的我方坦克数量

int   check_helpa = 0;										//static	static
int   Max_play = 0;//当前游戏最大玩家数						   static
int   Goto = 88;//去地图编辑还是去坦克大战						static
int   Tank_life = 5;//我方坦克生命值							 static
int   Max_Rebottank = 3;//机器人坦克							   static
int   max_kill = 3;//最大击杀数								   static
int   now_max_kill = 0;//最大击杀数							   static
int   in_map = 2;//当前地图										static
int   check_Rebottank = 0;//初始化当前活着的我方坦克数量		  static
int   check_play = 0;//初始化当前活着的我方坦克数量  			  static
int  now_map[40][40] = { 0 };


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
void WriteChar(int y, int x, char *pszChar, WORD wArr, int mapid ){	
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	COORD loc;
	loc.X = x * 2;
	loc.Y = y;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
		if (mapid == 0)
		{
			printf(pszChar);
		}
		else
		{
			switch (mapid)
			{
// WALL1_A   "▓"  // 卍  土墙 （可破坏,破坏形态）0x3
// WALL1_B    "〓" // 〓  铁墙 （可破坏）0x4
// WALL1_C    "≈"  // ≈   河流 （不可穿越，子弹可过）0x5
// WALL1_D   "■"   // ∷   路障  （不可穿越，子弹不可过）   0x6
// WALL1_E    "^^"  // ≡ ^^  丛林 （隐身）0x7
			case 3:printf(WALL1_A); break;
			case 4:printf(WALL1_B); break;
			case 5:printf(WALL1_C); break;
			case 6:printf(WALL1_D); break;
			case 7:printf(WALL1_E); break;
			
			}
		}{


		}

}
//"                          |       ";
//"                   __\--__|_      "
//"   II=======OOOOO[/ ★02 ___|      "
//"             _____\______|/-----. "
//"           /____________________| "
//"            \◎◎◎◎◎◎◎◎⊙/          "
//"              ~~~~~~~~~~~~~~~~    "
/*
功能：片头 
*/
void Wellcome(){ 
	
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;//是否显示光标
	SetConsoleTitle(L"坦克大战");
	SetWindowSize("宋松 坦克大战", 40, 100);
	vector<char*> gggg;
	//移动坦克 
	gggg.push_back("                        |       ");
	gggg.push_back("                 __\\--__|_      ");
	gggg.push_back(" II=======OOOOO[/ ★02 ___|      ");
	gggg.push_back("          _____\\______|/-----.  ");
	gggg.push_back("         /____________________|  ");
	gggg.push_back("          \\◎◎◎◎◎◎◎◎⊙/   ");
	gggg.push_back("            ~~~~~~~~~~~~~~~~     ");
	vector<char*> chara;
	chara.push_back("@@@@@@@@  @@@                         @@@@@@@@@@                      @@@         ");
	chara.push_back("@@@@@@@@  @@@                         @@@@@@@@@@                      @@@         ");
	chara.push_back("@@@             @@ @@   @@@@@            @@@@      @@@@@@   @@@@@@@   @@@   @@@   ");
	chara.push_back("@@@       @@@  @@@@@@  @@@@@@@@          @@@@     @@@@@@@@  @@@@@@@@  @@@  @@@    ");
	chara.push_back("@@@@@@@@  @@@  @@@    @@     @@          @@@@     @@   @@@  @@@@@@@@  @@@@@@      ");
	chara.push_back("@@@@@@@@  @@@  @@@@   @@     @@          @@@@        @@@@@  @@@  @@@@ @@@@@       ");
	chara.push_back("@@@@      @@@  @@@    @@@@@@@@@          @@@@     @@@@@@@@  @@@  @@@@ @@@@@@@     ");
	chara.push_back("@@@       @@@  @@@    @@@                @@@@    @@@   @@@  @@@  @@@@ @@@@@@@@    ");
	chara.push_back("@@@       @@@  @@@     @@    @@          @@@@    @@@@@@@@@  @@@  @@@@ @@@@   @@@   ");
	chara.push_back("@@@       @@@  @@@     @@@@@@@           @@@@     @@@@@@@@  @@@  @@@@ @@@@   @@@   ");
	chara.push_back("@@@       @@@   @@       @@@             @@@@            @@     @@    @@     @@@@");
	int kk = 0;
	for (int j = 0; j < 10; j++)
	{
		kk = j;
	
	for (int i = 0 ; i < 7; i++)
	{
		WriteChar(20 + i, 35-kk, gggg[i], 0 | F_H_WHITE);

	}
	Sleep(100);
		if (j != 9){
			for (int i = 0; i < 7; i++)
			{
				WriteChar(20 + i, 35 - kk, "                                  ", 0 | F_H_WHITE); 
			}
		}
	}
	Sleep(100);

	for (int j = 0; j < 8; j++)
	{
		kk = j;
		for (int i = 0; i < 11; i++)
		{
			WriteChar(5 + i, 0 + kk, chara[i], 0 | F_H_WHITE);
		}
		Sleep(200);
		if (j < 5)
		{
			for (int i = 0; i < 11; i++)
			{
				WriteChar(5 + i, 0 + kk, "                                       ", 0 | F_H_WHITE);
			}
		}		
	}
	 int i = 0;
	 while (i == 0)
	 {
		 if (_kbhit()){
			 unsigned	char ch = _getch();
			 if (ch == 0xe0)
			 {  char ch1 = _getch();
				 ch = ch1;  }
			 if (ch == '\r') { 
				 //进菜单动画
				 WriteChar(22, 25, "                                  ", 0 | F_H_WHITE);
				 for (int i = 0; i < 7; i++)
				 {
					 WriteChar(22, 25 + i, gggg[2], 0 | F_H_WHITE);
					 Sleep(50);
					 WriteChar(22, 25 + i, "                                  ", 0 | F_H_WHITE);
					 Sleep(50);
				 }
				 Sleep(10);
				 for (int i = 0; i < 7; i++)
				 {
					 WriteChar(22, (25 + 7 - i), gggg[2], 0 | F_H_WHITE);
					 Sleep(10);
					 WriteChar(22, 25 + 7 - i, "                                  ", 0 | F_H_WHITE);
					 Sleep(10);
				 }
				 WriteChar(22, 25, gggg[2], 0 | F_H_WHITE);
				 Sleep(1000); 
			     continue; 
			 }
			 else
			 {  
				 WriteChar(22, 10, "                       ", 0 | F_H_WHITE);
				 Sleep(1000);
				 WriteChar(22, 10, "请按回车键进入游戏 *…*", 0 | F_H_WHITE);
			 }
		  }
		 else
		 {
			 WriteChar(22, 10, "请按回车键进入游戏 *…*", 0 | F_H_WHITE);
		 } 
	 }
	}

/*
功能：菜单控制中心
 int a =m_menu_state  不同状态不同处理方式
*/
void Cmenu::main_menu(int a){
	//Goto = 77; in_map = 1;  Max_play = 1;  return;
	system("cls");
	system("color 0f");
	m_menu_state = a; 
	switch (m_menu_state)
	{
	case 88:  Goto = 88; in_map = 2;  return;//坦克大战 默认第一关卡地图
	case 77: Goto = 77;  return;//画图 用in_map 这个判断是那个地图
	}
	m_menu_y = 7;
	main_draw();
	switch (m_menu_state)
	{		
		move_a(true);
		case 1:{
			//主菜单
			m_max_y = 19;
			show_menu(3, 8, 0);
		}break;
		case 2:{
			//几个玩家 选项  Max_play 关联	
			m_max_y = 13;
			show_menu(8,10,0);			
		}break;
		case 3:{
			//游戏设置
			m_max_y = 15;
			show_menu(10, 15, 0);
		}break;
		case 4:{
			//选择编辑的地图	
			m_max_y = 15;
			show_menu(15, 18, 0);
		}break;
	}
	m_menu_y = 11;//重置光标位置
	m_min_y = 11;
	menu_choose();

}
/*
功能：键盘控制中心    
*/
void Cmenu::menu_choose(){
	if (m_select == 0){
	while (m_select == 0)
	{ 
		if (_kbhit()) {
		unsigned	char ch = _getch();

		if (ch == 0xe0)
		{
			char ch1 = _getch();
			 ch = ch1;
		}
			switch (ch)
				{
					case 'w':case 'W':case 'H':
						{ 
							move_a(true);
				// 操作坦克
						}break;
				case 's':case 'S':case 'P':
					{ 
						move_a(false);
					}break;
				case 'a':case 'A':case 'K':
				{
					if (m_menu_state == 3){

						switch (m_menu_y)
						{
						case 11://当前页面第一行   开始游戏  坦克大战
							menu_Pnumb(max_kill, -1); break;
						case 13:
							menu_Pnumb(Tank_life, -1); break;
						case 15:
							menu_Pnumb(Max_Rebottank, -1); break;
						 				
						}
					} 
				}break;
				case 'd':case 'D':case 'M':
				{
					if (m_menu_state == 3){

						switch (m_menu_y)
						{
						case 11:// 
							menu_Pnumb(max_kill, 1); break;
						case 13:
							menu_Pnumb(Tank_life, 1); break;
						case 15:
							menu_Pnumb(Max_Rebottank, 1); break;

						}
					}
				}break;
				case 0x71:case  0x51:  case '\x1b': main_menu(1); break;
				//确定选择 开始进入判断做什么功能的操作 传Y坐标
				case '\r':
				{
					if (m_menu_state == 1){
						m_select = 1;						
						switch (m_menu_y)
						{
						case 11://当前页面第一行   开始游戏  坦克大战
							main_menu(2); break;
						case 13:
							main_menu(3); break;//游戏设置
						case 15:
							main_menu(4); break;//绘制地图77
						case 17:
							main_menu(5); break;//游戏帮助
						case 19:
							main_menu(6); break;//退出游戏						
						}
						
					}
					if (m_menu_state == 2){
						m_select = 1;
						switch (m_menu_y)
						{
						case 11://玩家一   
							Max_play = 1;  break;
						case 13:////玩家二
							Max_play = 2; break;//游戏设置
						}
						main_menu(88);//进入坦克大战
					}
					if (m_menu_state == 3){
						main_menu(1);
					}
					if (m_menu_state == 4){//选项
						m_select = 1;
						switch (m_menu_y)
						{
						case 11://地图一   
							in_map = 2; break;
						case 13:////地图二
							in_map = 3; break;
						case 15:////地图三
							in_map = 4;  break; 
						}
						main_menu(77);//进入对应的地图画图
					}
				// 游戏退出
				}break;
				system("cls");
			}

		}
	}
	}
}
/*
功能： 将数字转成字符串 输出到界面
*/
void Cmenu::menu_Pnumb(int &name, int numb){
	
	name = name + numb;
	char ch[10] = {};
	_itoa_s(name, ch, 10);
	WriteChar(m_menu_y, m_menu_x + 8, ch, wArr);
}
/*
功能： 光标输出 
*/
void Cmenu::move_a(bool trrue){
	if (trrue) {			
		m_menu_y -= 2;		
		if (m_menu_y  <= m_max_y && m_menu_y   >= m_min_y){
			WriteChar(m_menu_y+2, m_menu_x - 2, "   ", wArr);
		}
		else
		{
			m_menu_y += 2;
			return;
		}
	}else { 
		m_menu_y += 2;
		if (m_menu_y  <= m_max_y && m_menu_y   >= m_min_y){
			WriteChar(m_menu_y - 2, m_menu_x - 2, "   ", wArr);
		}
		else
		{
			m_menu_y -= 2;
			return;
		}
	}
		WriteChar(m_menu_y, m_menu_x - 2, charaa[1], wArr); 
}
/*
功能： 
画界面的框架  
*/
void Cmenu::main_draw(){
	for (int i = 5; i < 25; i++){// 行
		for (int j = 10; j < 30; j++)//列
		{
			if (j == 10 || j == 29 || i == 5 || i == 24){

				WriteChar(i, j, WALL1_D, WALL1_DC);
			}
			else
			{
				WriteChar(i, j, "  ", 0);
			} 
		} 
	}
	WriteChar(m_menu_y, m_menu_x, charaa[2], F_H_CYAN);
}
/*
功能：循环显示菜单 charaa    NOW 从哪里开始 MAX 从哪里结束
*/
void Cmenu::show_menu(int now, int max,int select){
	m_select = select;
	int temp = m_menu_y+2;
	for (int i = now; i < max; i++)
	{
		m_menu_y += 2;
		if (i == now) { move_a(false);  }
		WriteChar(m_menu_y, m_menu_x, charaa[i], wArr);
	} 
} 