#include "stdafx.h"
#include "Cball.h"
/*
功能：第一次射出的子弹
int typea,   子弹敌我区分
int b_tank ,  坦克ID
int position, 方向
int b_x   b_y, 子弹XY 坐标
char *ball_style  子弹风格
*/
void Cball::Firstball(int typea, int b_tank, int position, int b_x, int b_y, char ball_style[3]){
	for (int i = 0; i < 256; i++)
	{
		int check_a = 0;//当前的子弹是否40X40的越界
		//int check_b = 0;//考虑子弹的下个显示的地方是否是空地
		//if (now_map[b_y][b_x] > 1){ check_b = 2; }
		// all_ball[i].isBullet 可用之前 判断子弹是否越界
		//如果当前数组子弹还在运行 就不遍历下一个
		if (all_ball[i].isBullet != 0){ continue; }
		else
		{
			all_ball[i].isBullet = 1;
			all_ball[i].b_x = b_x;
			all_ball[i].b_y = b_y;
			switch (position)
			{
			case 0: all_ball[i].b_y -= 2; break;
			case 1: all_ball[i].b_y += 2; break;
			case 2:all_ball[i].b_x -= 2; break;
			case 3:all_ball[i].b_x += 2; break;
			}
			/*if (all_ball[i].b_x < 39 || all_ball[i].b_x > 0 ||
			all_ball[i].b_y < 39 || all_ball[i].b_y > 0 )
			{ */
			if (cheak_ball_bump(all_ball[i].b_type, position, all_ball[i].b_y, all_ball[i].b_x, 1, i))
			{
				//DrawBall(all_ball[i].b_y, all_ball[i].b_x, 1, 0 | F_H_GREEN);
				all_ball[i].b_position = position;//朝向
				all_ball[i].b_type = typea;//坦克子弹敌我
				all_ball[i].b_tank = b_tank;//那个坦克发的子弹
				(all_ball[i].b_type == 1) ? all_ball[i].wArr = 0 | F_H_GREEN : all_ball[i].wArr = 0 | F_H_GREEN; //坦克子弹样式赋值
			}
			else{ all_ball[i].isBullet = 0; }
			return;
		}
	}
}
/*
功能：循环子弹
*/
void Cball::tank_ball()
{
	for (int i = 0; i < 50; i++)
	{
		int ay = all_ball[i].b_y;
		int ax = all_ball[i].b_x;
		if (all_ball[i].isBullet == 0 || now_map[ay][ax] == 6)
		{
			all_ball[i].isBullet = 0;
			continue;
		}
		switch (all_ball[i].b_position)
		{
		case 0: --ay; break;
		case 1: ++ay;  break;
		case 2: --ax; break;
		case 3: ++ax;  break;
		}

		if (cheak_ball_bump(all_ball[i].b_type, all_ball[i].b_position, ay, ax, 1, i))
		{
			all_ball[i].b_y = ay;
			all_ball[i].b_x = ax;
			continue;
		}


	}
}

/*
功能：画子弹
int balltype 判断是清除还是画子弹
WORD wArr = 0  字体背景颜色
*/
void Cmap::DrawBall(int y, int x, int balltype, WORD wArr = 0){

	if (balltype == 1){

		switch (now_map[y][x])
		{
		case 5: WriteChar(y, x, WALL1_C, WALL1_GC); return;//河流 true
		case 7: WriteChar(y, x, WALL1_E, WALL1_GC); return;//草地 true
		case 9: WriteChar(y, x, WALL1_G, WALL1_GC); return;//BUFF true 
		case 20:WriteChar(y, x, BUFF_SPEED_GRAPHICS, WALL1_GC); return;
		case 21:WriteChar(y, x, BUFF_GOD_GRAPHICS, WALL1_GC); return;
		case 22:WriteChar(y, x, BUFF_SHIELD_GRAPHICS, WALL1_GC); return;
		}
		now_map[y][x] = 13;
		WriteChar(y, x, "◎", MAPBG | wArr);
	}
	else
	{

		switch (now_map[y][x])
		{
		case 5: WriteChar(y, x, WALL1_C, WALL1_CC); return;//河流 true
		case 7: WriteChar(y, x, WALL1_E, WALL1_EC); return;//草地 true
		case 9: WriteChar(y, x, WALL1_G, WALL1_GC); return;//BUFF true 
		case 20:WriteChar(y, x, BUFF_SPEED_GRAPHICS, BUFF_BG); return;
		case 21:WriteChar(y, x, BUFF_GOD_GRAPHICS, BUFF_BG); return;
		case 22:WriteChar(y, x, BUFF_SHIELD_GRAPHICS, BUFF_BG); return;
		}
		now_map[y][x] = 1;
		WriteChar(y, x, "  ", MAPBG);
	}
}
