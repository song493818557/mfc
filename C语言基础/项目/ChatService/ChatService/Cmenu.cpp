#include "stdafx.h"
#include "Cmenu.h"

int   in_map = 0;//当前游戏最大玩家数						   static
int   Goto = 88;//去地图编辑还是去坦克大战						static

Cmenu::Cmenu()
{
	m_menu_x = 17;
	charaa.push_back("※");//0
	charaa.push_back(">> ");//1
	charaa.push_back("管理员,欢迎回来");//2
	charaa.push_back("①  注册账号");//3
	charaa.push_back("②  登录账号");//4
	charaa.push_back("③  实时群聊");//5
	charaa.push_back("④  好友列表");//6
	charaa.push_back("⑤  退出");//7
	charaa.push_back("①  Player");//8
	charaa.push_back("②  Player");//9
	charaa.push_back("击毁坦克过关数");//10
	charaa.push_back("生    命    值");//11
	charaa.push_back("机器坦克在线数");//12	
	charaa.push_back("上下选择,左右加减值");//13	
	charaa.push_back("ESC 保存退出");//14	
	charaa.push_back("坦克大战关卡一");//15	
	charaa.push_back("坦克大战关卡二");//16	
	charaa.push_back("坦克大战关卡三");//17	
	m_menu_y = 7;
}



/*
功能：菜单控制中心
int a =m_menu_state  不同状态不同处理方式
*/
DWORD WINAPI Cmenu::main_menu(_In_ LPVOID lpParameter){
	//Goto = 77; in_map = 1;  Max_play = 1;  return;
	system("cls");
	system("color 0f");
	m_menu_state = (int)lpParameter;
	switch (m_menu_state)
	{
	case 88:  Goto = 88; in_map = 2;  return 0;//坦克大战 默认第一关卡地图
	case 77: Goto = 77;  return 0;//画图 用in_map 这个判断是那个地图
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
		show_menu(8, 10, 0);
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

						//						switch (m_menu_y)
						//						{
						//						case 11://当前页面第一行   开始游戏  坦克大战
						////menu_Pnumb(max_kill, -1); break;
						//						case 13:
						//							//menu_Pnumb(Tank_life, -1); break;
						//						case 15:
						//						//	menu_Pnumb(Max_Rebottank, -1); break;
						//							 
						//						}
					}
				}break;
				case 'd':case 'D':case 'M':
				{
					if (m_menu_state == 3){

						//switch (m_menu_y)
						//{
						//case 11:// 
						////	menu_Pnumb(max_kill, 1); break;
						//case 13:
						////	menu_Pnumb(Tank_life, 1); break;
						//case 15:
						////	menu_Pnumb(Max_Rebottank, 1); break;

						//}
					}
				}break;
				case 0x71:case  0x51:  case '\x1b': main_menu((LPVOID)1); break;
					//确定选择 开始进入判断做什么功能的操作 传Y坐标
				case '\r':
				{
					if (m_menu_state == 1){
						m_select = 1;
						switch (m_menu_y)
						{
						case 11://当前页面第一行   开始游戏  坦克大战
							main_menu((LPVOID)2); break;
						case 13:
							main_menu((LPVOID)3); break;//游戏设置
						case 15:
							main_menu((LPVOID)4); break;//绘制地图77
						case 17:
							main_menu((LPVOID)5); break;//游戏帮助
						case 19:
							main_menu((LPVOID)6); break;//退出游戏						
						}

					}
					if (m_menu_state == 2){
						m_select = 1;
						//switch (m_menu_y)
						//{
						//case 11://玩家一   
						//	//Max_play = 1;  break;
						//case 13:////玩家二
						//	//Max_play = 2; break;//游戏设置
						//}
						main_menu((LPVOID)88);//进入坦克大战
					}
					if (m_menu_state == 3){
						main_menu((LPVOID)1);
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
						main_menu((LPVOID)77);//进入对应的地图画图
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
	WriteChar(m_menu_y, m_menu_x + 8, ch, F_H_CYAN | F_H_CYAN);
}
/*
功能： 光标输出
*/
void Cmenu::move_a(bool trrue){
	if (trrue) {
		m_menu_y -= 2;
		if (m_menu_y <= m_max_y && m_menu_y >= m_min_y){
			WriteChar(m_menu_y + 2, m_menu_x - 2, "   ", F_H_CYAN | F_H_CYAN);
		}
		else
		{
			m_menu_y += 2;
			return;
		}
	}
	else {
		m_menu_y += 2;
		if (m_menu_y <= m_max_y && m_menu_y >= m_min_y){
			WriteChar(m_menu_y - 2, m_menu_x - 2, "   ", F_H_CYAN | F_H_CYAN);
		}
		else
		{
			m_menu_y -= 2;
			return;
		}
	}
	WriteChar(m_menu_y, m_menu_x - 2, charaa[1], F_H_CYAN | F_H_CYAN);
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
void Cmenu::show_menu(int now, int max, int select){
	m_select = select;
	int temp = m_menu_y + 2;
	for (int i = now; i < max; i++)
	{
		m_menu_y += 2;
		if (i == now) { move_a(false); }
		WriteChar(m_menu_y, m_menu_x, charaa[i], F_H_CYAN | F_H_CYAN);
	}
}
