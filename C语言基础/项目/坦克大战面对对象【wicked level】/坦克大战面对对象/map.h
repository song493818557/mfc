#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "stdafx.h"
#include "menu.h"
#include <conio.h>

static  int check_Rebottank = 0;
static  int check_play = 0;
static  int Max_Rebottank = 5;
static  int Max_play = 2;

//移动碰撞 都在这里处理
class Cmap{
public: 
	Cmap(){
		
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				now_map[i][j] = sysMap00[i][j];
			}
		}
		int c = sizeof(sysMap00);
	}
	void DrawMap();
	//检测碰撞 在全局地图里面检测
	static	bool cheak_bump(int position, int y, int x, int tsize);
	static	bool cheak_ball_bump(int typea, int position, int y, int x, int tsize,int i);
	static	bool  cheak_Tank_bump(int position, int y, int x, int tsize);
	static	void DrawBall(int y, int x, int balltype, WORD wArr);
	static	int now_map[40][40];
	
private:
};


class Calltank : public Cmap 
{
public:
	Calltank(){
	
	};
	~Calltank(){};
	//坦克模型九方格  四个模型
	static int t_demo[4][3][3];
	void DrawTank(char singbo[3], int color);
	void ClerarTank();
	
	void FindTank(int y, int x, int b_tank, int b_type, int i);
	int t_life;//生命值 私有值
	int t_type;
	int t_position;//定义坦克方向 私有值
	int m_x;//玩家操作的坦克移动x坐标 私有值
	int m_y;//玩家操作的坦克移动y坐标 私有值
	int t_online = 0;//判定是否已经在线
	WORD t_bg;//坦克背景颜色 私有值
private:
	int i = 10;
};


class Cball : public Cmap {
public:
	void Firstball(int typea, int b_tank, int position, int b_x, int b_y, char *ball_style);
	void tank_ball();
	friend void FindTank(int y, int x, int b_tank, int b_type);
	friend class Cmap;
	bool isBullet = 0;
	int b_type;//敌我子弹
	int b_tank;//发射敌我子弹的坦克标识
	int b_position;//定义子弹的方向
	int b_x;//玩家操作的坦克移动x坐标
	int b_y;//玩家操作的坦克移动y坐标

	char t_ball[3];//子弹☉ 
	WORD wArr; //我军子弹 颜色样式
	//WORD wArra; //敌军子弹 颜色样式

};
class Cmytank : public Calltank ,public Cball {
public:
	// 初始化己方坦克 10,0, 25, 37, MISSILETYPE_1,0x000
	Cmytank(){
		t_life = 10;
		t_type = 1;
		t_position = 0;
		t_online = 1;
		m_x = 25;
		m_y = 25;
		b_tank = 6;
		char t_ball[3] = "⊙";//子弹样式 私有值
		 t_bg = 0x000;
		 check_play++;
	};
	void MoveTank();
	
	~Cmytank(){};
private:

};
class CenemyTank : public Calltank, public Cball{
public:
	// 初始化己方坦克 10,0, 25, 37, MISSILETYPE_1,F_H_CYAN
	CenemyTank(int y = 30, int x = 32, WORD t_bg = F_H_CYAN){
		t_life = 0;
		t_type = 2;
		t_position = 2;
		m_x = x;
		m_y = y;
		//check_Rebottank++;
		char t_ball[3] = "⊙";//子弹样式 私有值
		t_bg = F_H_CYAN;
	};
	void move_enemy();
	void production_enemy();//批量刷机器坦克 
	~CenemyTank(){};
private:

};




#endif
