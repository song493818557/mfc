#pragma once
#include "Cbase64.h" 

#include <vector>
using std::vector;
class Cmenu {
public: 
	Cmenu();
	void main_menu(int a);   //主菜单
	void main_draw();	//画界面的框架
	void show_menu(int now, int max, int select);//循环显示菜单
	void move_a(bool trrue);	//简单的选择光标
	void menu_choose();//菜单上的键盘操作
	void menu_Pnumb(int &name, int numb);//游戏设置里面的将数字转成字符串 输出到界面
	vector<char*> charaa;
	int m_menu_state;
	int m_menu_y;
	int m_menu_x;
	int m_max_y;
	int m_min_y;
	bool m_select;
private:
	//WORD wArr = F_H_CYAN | F_H_CYAN;
	
};