#pragma once
#include "stdafx.h" 
#include "Cgame.h"
#include <string>
#include <vector>
using std::string;
using std::vector;
/***
函数功能 ：设置窗口信息
参数一：宽度X行
参数二：高度Y行
参数三：打印的字符
参数四：打印字符的属性
***/

bool SetWindowSize(CHAR* pszWindowTitle, int nX, int nY);
void WriteChar(int y, int x, char *pszChar, WORD wArr,int mapid=0);
void Wellcome();
struct position
{
	int y;
	int x;
};
class Cmenu :public Cgame{
public:
	Cmenu(){ 
		m_menu_x = 17;
		charaa.push_back("※");//0
		charaa.push_back(">> ");//1
		charaa.push_back("坦克大战 Max ^_^");//2
		charaa.push_back("①  开始游戏");//3
		charaa.push_back("②  游戏设置");//4
		charaa.push_back("③  绘制地图");//5
		charaa.push_back("④  游戏帮助");//6
		charaa.push_back("⑤  退出游戏");//7
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
	void main_menu(int a);   //主菜单
	void main_draw();	//画界面的框架
	void show_menu(int now, int max, int select);//循环显示菜单
	void move_a(bool trrue);	//简单的选择光标
	void menu_choose();//菜单上的键盘操作
	void menu_Pnumb(int &name, int numb);//游戏设置里面的将数字转成字符串 输出到界面
private:
	vector<char*> charaa;
	WORD wArr = F_H_CYAN | F_H_CYAN;
	int m_menu_state;
	int m_menu_y;
	int m_menu_x;
	int m_max_y;
	int m_min_y;
	bool m_select; 
};