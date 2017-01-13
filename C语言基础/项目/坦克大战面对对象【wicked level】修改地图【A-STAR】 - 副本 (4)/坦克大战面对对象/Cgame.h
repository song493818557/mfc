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
using namespace std;
 
static int   check_helpa = 0;
static int   Max_play = 0;//当前游戏最大玩家数
static int   Goto = 88;//去地图编辑还是去坦克大战
static int   Tank_life = 5;//我方坦克生命值
static int   Max_Rebottank = 3;//机器人坦克
static int   max_kill = 3;//最大击杀数
static int   now_max_kill = 0;//最大击杀数
static int   in_map = 2;//当前地图
static int   check_Rebottank = 0;//初始化当前活着的我方坦克数量
static int   check_play = 0;//初始化当前活着的我方坦克数量  
static int  now_map[40][40] = { 0 };
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

};
