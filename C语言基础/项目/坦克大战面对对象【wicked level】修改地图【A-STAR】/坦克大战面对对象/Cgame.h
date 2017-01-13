#pragma once
#include "Data.h"
#include <string>
#include <vector> 
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <wtypes.h>
#include <time.h>
#include "Cball.h"
using namespace std;

bool SetWindowSize(CHAR* pszWindowTitle, int nX, int nY);
void WriteChar(int y, int x, char *pszChar, WORD wArr, int mapid = 0);
void Wellcome();
class Cgame
{
public:
	Cgame();
	~Cgame();
	/*
	功能：循环监听鼠标键盘事件
	*/
	static int max_map;//最大地图数量
	void get_Message(int& nChar);
	void read_map(int in_map);
	void save_map(int in_map);
	void get_max();
	static  int check_Rebottank;
	static  int check_play;
	static  int Tank_life;
	static  int Max_Rebottank;
	static  int Max_play;
	static  int Goto;
	static  int now_max_kill;
	static  int check_helpa;
	static  int max_kill;//击杀最大值 大于等于就过关
	static  int in_map;//当前地图 
	static  int now_level;
	static int now_map[40][40];
};
int  Cgame::check_helpa = 0;
int  Cgame::Max_play = 0;//当前游戏最大玩家数
int  Cgame::Goto = 0;//去地图编辑还是去坦克大战
int  Cgame::Tank_life = 5;//我方坦克生命值
int  Cgame::Max_Rebottank = 3;//机器人坦克
int  Cgame::max_kill = 3;//最大击杀数
int  Cgame::now_max_kill = 0;//最大击杀数
int  Cgame::in_map = 2;//当前地图
int  Cgame::check_Rebottank = 0;//初始化当前活着的我方坦克数量
int  Cgame::check_play = 0;//初始化当前活着的我方坦克数量
Cball all_ball[256];
//坦克模型
int Calltank::t_demo[4][3][3] = {
	{ { 2, 1, 2 },
	{ 1, 4, 1 },
	{ 1, 3, 1 } },
	{ { 1, 3, 1 },
	{ 1, 4, 1 },
	{ 2, 1, 2 } },
	{ { 2, 1, 1 },
	{ 1, 4, 3 },
	{ 2, 1, 1 } },
	{ { 1, 1, 2 },
	{ 3, 4, 1 },
	{ 1, 1, 2 } }
};