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

