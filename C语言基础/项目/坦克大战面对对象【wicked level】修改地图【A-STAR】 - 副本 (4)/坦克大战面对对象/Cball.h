#pragma once 
#include "stdafx.h"
#include "Cbuff.h"

class Cball : public Cmap {
public:
	void Firstball(int typea, int b_tank, int position, int b_x, int b_y, char ball_style[3]);
	void tank_ball();
	friend void FindTank(int y, int x, int b_tank, int b_type);
	friend void MoveTank(Calltank &tank);

	friend class Cmap;
	bool isBullet = 0;
	int b_type;//敌我子弹
	int b_tank;//发射敌我子弹的坦克标识
	int b_position;//定义子弹的方向
	int b_x;//玩家操作的坦克移动x坐标
	int b_y;//玩家操作的坦克移动y坐标
	int ball_lengh = 0;
	char t_ball[3];//子弹☉ 
	static int ball_number;//当前所有子弹的总数量
	WORD wArr; //我军子弹 颜色样式
	//WORD wArra; //敌军子弹 颜色样式

};