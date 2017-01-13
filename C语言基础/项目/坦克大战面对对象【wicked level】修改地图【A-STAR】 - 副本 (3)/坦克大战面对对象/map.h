#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "stdafx.h"
#include "Cgame.h"
//#include "Cbuff1.h"
#include <vector>
using  std::vector;

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

//移动碰撞 都在这里处理
class Cmap:public Cgame{
public: 
	//地图初始化
	void inInit(){
		//read_map(in_map);
		 
		//FILE * pFile = NULL;
		//if (in_map == 2){//关卡一

		//	fopen_s(&pFile, "c:\\a\\2.txt", "rb+");
		//}
		//else if (in_map == 3)//关卡二
		//{
		//	fopen_s(&pFile, "c:\\a\\3.txt", "rb+");
		//}
		//else if (in_map == 4)//关卡三
		//{
		//	fopen_s(&pFile, "c:\\a\\4.txt", "rb+");
		//}
		//fread(
		//	sysMap00, //写的起始地址 buf2
		//	4, //一块的大小
		//	20 * 20 * sizeof(int), //写入多少块
		//	pFile);
		//fclose(pFile);
		//
		//for (int i = 0; i < 40; i++)
		//{
		//	for (int j = 0; j < 40; j++)
		//	{
		//		now_map[i][j] = sysMap00[i][j];
		//	}
		//} 
	}
	void DrawMap();//画地图
	void ClearMap();//清除地图
	static void myhelp(int swnumb);//右侧输出
	static void check_help();//监控右侧的键盘输出
	static void Printf_lost_win();//输出输了还是赢了
	static	int now_map[40][40];  

	//检测碰撞 在全局地图里面检测 
	static	bool cheak_ball_bump(int typea, int position, int y, int x, int tsize,int i);
	static	bool cheak_Tank_bump(int position, int y, int x, int tsize);
	static	void DrawBall(int y, int x, int balltype, WORD wArr);
	static bool Canmove(clock_t& t_start, int t_speed);
	static bool get_char(char& t_start);
	clock_t ball_speed = 30;
	clock_t ball_start = 0;
	clock_t production_star = 0;
	clock_t production_speed = 500;
	clock_t buff_star = 0;
	clock_t buff_speed = 500;
private:

};

 





#endif