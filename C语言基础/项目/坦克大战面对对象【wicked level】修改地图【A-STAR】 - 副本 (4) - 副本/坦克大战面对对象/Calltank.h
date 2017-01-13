#pragma once 
#include "Cball.h"
//机器人坦克
static CenemyTank reboottank[5];
static  Cmytank mytanka[2];
class Calltank : public Cbuff, public Cball, public Castar
{
public:
	Calltank(){};
	~Calltank(){};
	//坦克模型九方格  四个模型
	static int t_demo[4][3][3];
	void inInit_mytank();
	static void DrawTank(Calltank &tank);
	static void ClerarTank(int ty, int tx);
	void FindTank(int y, int x, int b_tank, int b_type, int i);
	//void MoveTank(int y,int x,int type);//坦克移动
	//void MoveTank(Calltank &tank);
	void MoveTank();
	void check_buff(int nBuff);
	bool check_point(int b_type, int &y, int &x);//检测复活位置是否被占用
	static	bool cheak_bump(Calltank &tank, int position, int uy, int ux);//检测坦克碰撞 传的UY UX 满足条件后赋值
	bool gettankbuff(Calltank &tank, int type);//检测当前坦克所拥有的BUFF状态
	int t_life;//生命值 私有值
	int t_type;
	int t_kill;//坦克积分
	int t_position;//定义坦克方向 私有值
	int m_x;//玩家操作的坦克移动x坐标 私有值
	int m_y;//玩家操作的坦克移动y坐标 私有值
	int t_online = 0;//判定是否已经在线
	int t_speed;//机器坦克的速度
	int t_hp;//HP血值
	int t_ball_speed;//HP血值
	clock_t start;//当前坦克计时开始

	bool  t_canmove;//判断是否能移动
	WORD t_bg;//坦克背景颜色 私有值
private:
	int i = 10;
};

class Cmytank : public Calltank {
public:
	// 初始化己方坦克 10,0, 25, 37, MISSILETYPE_1,0x000
	Cmytank(){
		t_life = 2;
		t_online = 0;
		t_type = 1;
		t_speed = 30;
		t_position = 0;
		char t_ball[3] = "⊙";//子弹样式 私有值
		t_bg = 0x000;
		//check_play++;
	};
	//void inInit();//初始化

	void MyKill();//杀敌加一
	void production_mytank();//复活坦克+判断输了没
	~Cmytank(){};
private:

};
//玩家坦克
class CenemyTank : public Calltank{
public:
	// 初始化己方坦克 10,0, 25, 37, MISSILETYPE_1,F_H_CYAN
	CenemyTank(int y = 30, int x = 32, WORD t_bg = F_H_CYAN){

		t_type = 2;
		t_position = 2;
		m_x = x;
		m_y = y;
		t_speed = 50;
		char t_ball[3] = "⊙";//子弹样式 私有值
		t_bg = F_H_CYAN;
		t_canmove = true;
		start = clock();
		Wayfind = false;
		realfind = true;
	};
	bool move_enemy(CenemyTank &tank, int aa);//自动操作机器坦克 包括移动 发射子弹
	void production_enemy();//批量刷机器坦克  
	void Wayfind_enemy(CenemyTank &aa, int tankid);//坦克1自动寻路 
	~CenemyTank(){};
	bool Wayfind;//是否正在寻路
	bool realfind;//是否确认 方便二次控制
private:
	//int t_speed; 坦克速度
};


