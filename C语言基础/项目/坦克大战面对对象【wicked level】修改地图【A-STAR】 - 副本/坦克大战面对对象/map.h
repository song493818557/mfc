#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "stdafx.h"
#include "menu.h"
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <vector>
using std::vector;

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


//int m_temp_map[40][40];
//static int  m_temp_map[40][40];//绘制地图副本【临时】
//移动碰撞 都在这里处理
class Cmap{
public: 
	//地图初始化
	void inInit(){
		FILE * pFile = NULL;
		if (in_map == 2){//关卡一

			fopen_s(&pFile, "c:\\a\\2.txt", "rb+");
		}
		else if (in_map == 3)//关卡二
		{
			fopen_s(&pFile, "c:\\a\\3.txt", "rb+");
		}
		else if (in_map == 4)//关卡三
		{
			fopen_s(&pFile, "c:\\a\\4.txt", "rb+");
		}
		fread(
			sysMap00, //写的起始地址 buf2
			4, //一块的大小
			20 * 20 * sizeof(int), //写入多少块
			pFile);
		fclose(pFile);
		
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				now_map[i][j] = sysMap00[i][j];
			}
		}
		//每次初始化 重置需要杀的坦克  以后可以优化 动态的击杀数
		
		
	}
	void DrawMap();//画地图
	void ClearMap();//清除地图
	static void myhelp(int swnumb);//右侧输出
	static void check_help();//监控右侧的键盘输出
	static void Printf_lost_win(int a);//输出输了还是赢了
	static	int now_map[40][40];
	//void DrawGraphics(int y, int x, int mapid, WORD wArr);
	//检测碰撞 在全局地图里面检测
	
	static	bool cheak_bump(int position, int y, int x, int tsize);//检测坦克碰撞

	static	bool cheak_ball_bump(int typea, int position, int y, int x, int tsize,int i);
	static	bool  cheak_Tank_bump(int position, int y, int x, int tsize);
	static	void DrawBall(int y, int x, int balltype, WORD wArr);
	
	
private:

};
//A star
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

class Calltank : public Cmap 
{
public:
	Calltank(){};
	~Calltank(){};
	//坦克模型九方格  四个模型
	static int t_demo[4][3][3];
	void inInit_mytank();
	void DrawTank(char singbo[3], int color);
	void ClerarTank();
	void FindTank(int y, int x, int b_tank, int b_type, int i);
	bool Canmove();
	int t_life;//生命值 私有值
	int t_type;
	int t_kill;//坦克积分
	int t_position;//定义坦克方向 私有值
	int m_x;//玩家操作的坦克移动x坐标 私有值
	int m_y;//玩家操作的坦克移动y坐标 私有值
	int t_online = 0;//判定是否已经在线
	int t_speed;//机器坦克的速度
	int t_hp;//HP血值
	clock_t start;//当前坦克计时开始
	clock_t finish;//当前坦克计时结束
	bool  t_canmove;//判断是否能移动
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
		t_life = 2;
		t_online = 0;
		t_type = 1;
		t_position = 0;
		b_tank = 6;
		char t_ball[3] = "⊙";//子弹样式 私有值
		 t_bg = 0x000;
		 //check_play++;
	};
	//void inInit();//初始化
	void MoveTank();//坦克移动
	void MyKill();//杀敌加一
	void production_mytank();//复活坦克+判断输了没
	~Cmytank(){};
private:

};
//玩家坦克
class CenemyTank : public Calltank, public Cball, public Castar{
public:
	// 初始化己方坦克 10,0, 25, 37, MISSILETYPE_1,F_H_CYAN
	CenemyTank(int y = 30, int x = 32, WORD t_bg = F_H_CYAN){
		t_life = 1;
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
 


#endif