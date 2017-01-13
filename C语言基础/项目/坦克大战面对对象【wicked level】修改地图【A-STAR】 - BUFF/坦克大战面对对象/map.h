#pragma once
#include "stdafx.h"
//#include "Cgame.h"
#include "menu.h"
#include "Cbuff.h" 
#include <string>
#include <vector> 
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <wtypes.h>
#include <time.h> 
using  std::vector; 
using namespace std;
class Cmap;
enum{
	AUP,
	ADOWN,
	ALEFT,
	ARIGHT
};
typedef struct _position
{
	int nY;
	int nX;
	int nP;//新增 保存方向
}POSTION;
typedef struct _strstar
{
	POSTION stcpos;//坐标
	int nH;  //移动的损耗  即从 起点开始每移一步加一
	int nG;  //离目的地的距离
	int nF;  //G+H的和  F最小点可以认为是该选的点
	POSTION Fatherpos;//父节点坐标

}STRSTAR;

class Cgame
{
public: 
	/*
	功能：循环监听鼠标键盘事件
	*/
	static int max_map;//最大地图数量
	void get_Message(int& nChar);
	void read_map(int in_map);
	void save_map(int in_map);
	void get_max();

};
//移动碰撞 都在这里处理
class Cmap:public Cgame{
public: 
	//地图初始化 
	void DrawMap();//画地图
	void ClearMap();//清除地图
	static void myhelp(int swnumb);//右侧输出
	static void check_help();//监控右侧的键盘输出
	static void Printf_lost_win();//输出输了还是赢了
	static	int now_map[40][40];
	//void DrawGraphics(int y, int x, int mapid, WORD wArr);
	//检测碰撞 在全局地图里面检测 

	static	bool cheak_ball_bump(int typea, int position, int y, int x, int tsize,int i);
	static	bool  cheak_Tank_bump(int position, int y, int x, int tsize);
	static	void DrawBall(int y, int x, int balltype, WORD wArr);
	static bool Canmove(clock_t& t_start, int t_speed);
	static bool get_char(char& t_start);
	clock_t ball_speed = 30;
	clock_t ball_start = 0;
	clock_t production_star = 0;
	clock_t production_speed = 500;
	clock_t buff_star = 0;
	clock_t buff_speed = 500;
	//static  int check_Rebottank;
	//static  int check_play;
	//static  int Tank_life;
	//static  int Max_Rebottank;
	//static  int Max_play;
	//static  int Goto;
	//static  int now_max_kill;
	//static  int check_helpa;
	//static  int max_kill;//击杀最大值 大于等于就过关
	//static  int in_map;//当前地图 
	//static  int now_level;
private:

};



/* ** 坦克属性开始** */
class Calltank;
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

class Cbuff : public Cmap {
	/*
	BUFF系统	显示  逻辑判断
	无敌
	加速
	护盾(抵挡一棵子弹) 圈
	*/
public:
	Cbuff(){ 	}
	bool buff_state = false;//buff的状态
	vector<int> buff_type; //将当前坦克获取到的BUFF可以依次保存到数组 达到BUFF的效果可以叠加 同一BUFF的时间是覆盖的 
	vector<clock_t> buff_Start;//当前坦克的BUFF计时开始容器 
	vector<int> buff_time; //当前坦克的BUFF停留时间容器  
	static void clearbuff();
	static void creat_buff();
	static void push_buff();
private:
	static clock_t m_Fstart;//在当前地图存活时间计时开始
	static int m_stay;//在当前地图存活的总时间
	static int m_pfood;
	static int max_food;
	static vector<POSTION> m_food;//buff的数组 包括坐标 和方向 
	static void draw_buff(int type);

};

class Castar :public  Cmap{
public:
	//设置地图  起点 终点
	void Setmap();
	void Drawmap();
	void Getpath(int now_map[40][40]);
	void PrintPath();
	void reset();
	POSTION sTart;
	POSTION eNd;
	vector<POSTION> m_Path; //最终结果
private:
	vector<STRSTAR> m_Openlist; //待探测
	vector<STRSTAR> m_Closelist;//已经探测
	int m_map[40][40];
	//计算当前位置到终点的绝对值 x
	int CalcH(POSTION pos_1, POSTION pos_2);
	void WriteChara(int x, int y, char* szString);
};
/* ** 坦克属性结束** */

//玩家坦克
class Calltank : public Cbuff, public Cball
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
	void check_buff( int nBuff);
	bool check_point(int b_type,int &y,int &x);//检测复活位置是否被占用
	static	bool cheak_bump(Calltank &tank, int position, int uy, int ux);//检测坦克碰撞 传的UY UX 满足条件后赋值
	bool gettankbuff(Calltank &tank,int type);//检测当前坦克所拥有的BUFF状态
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

class Cmytank : public Calltank  {
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

class CenemyTank : public Calltank, public Castar{
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
	bool move_enemy(CenemyTank &tank,int aa);//自动操作机器坦克 包括移动 发射子弹
	void production_enemy();//批量刷机器坦克  
	void Wayfind_enemy(CenemyTank &aa,int tankid);//坦克1自动寻路 
	~CenemyTank(){}; 
	bool Wayfind;//是否正在寻路
	bool realfind;//是否确认 方便二次控制
private:
	//int t_speed; 坦克速度
};
 


