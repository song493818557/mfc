#pragma once
#include "stdafx.h"
struct _tankfire{
	int t_life;//生命值
	int t_demo[4][3][3];//坦克模型九方格  四个模型
	int t_position;//定义坦克方向
	int m_x;//玩家操作的坦克移动x坐标
	int m_y;//玩家操作的坦克移动y坐标
	int t_ball;//子弹
	//int t_move[100][100];//移动坐标

	//int t_npc_stank;//小坦克
	//int t_npc_jtank;//精英坦克
	//int t_npc_btank;//BOSS坦克

}; _tankfire tankfire = { 10, {
	{ { 0, 1, 0 },
	{ 1, 0, 1 },
	{ 1, 0, 1 } },
	{ { 1, 0, 1 },
	{ 1, 0, 1 },
	{ 0, 1, 0 } },
	{ { 0, 1, 1 },
	{ 1, 0, 0 },
	{ 0, 1, 1 } },
	{ { 1, 1, 0 },
	{ 0, 0, 1 },
	{ 1, 1, 0 } }
}, 0, 25, 37, MISSILETYPE_1 };
_tankfire tankRobot = { 5, {
	{ { 0, 1, 0 },
	{ 1, 0, 1 },
	{ 1, 0, 1 } },
	{ { 1, 0, 1 },
	{ 1, 0, 1 },
	{ 0, 1, 0 } },
	{ { 0, 1, 1 },
	{ 1, 0, 0 },
	{ 0, 1, 1 } },
	{ { 1, 1, 0 },
	{ 0, 0, 1 },
	{ 1, 1, 0 } }
}, 0, 34, 5, MISSILETYPE_1 };
