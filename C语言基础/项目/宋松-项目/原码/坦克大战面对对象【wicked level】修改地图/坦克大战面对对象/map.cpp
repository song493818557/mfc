#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "stdafx.h"
#include "map.h"
#include <wtypes.h>
//机器人坦克
static CenemyTank reboottank[5];
//我方坦克
static Cmytank mytanka[2];
//所有子弹
Cball all_ball[256];
//地图
int Cmap::now_map[40][40] = { 0 };
//坦克模型
int Calltank::t_demo[4][3][3] = {
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
};

/*
功能：检测右侧 暂停 或者游戏成功失败后的去向 
*/
void Cmap::check_help(){

	while (check_helpa == 0)
	{
		if (!_kbhit()) continue;
		unsigned	char cha = _getch();
		switch (cha)
		{
		case 'x':case 'X':
		{
			//成功退出			
				in_map = 9;
				check_helpa = 1;
				mytanka[1].myhelp(1);
			//游戏失败
			//游戏中途退出
		}break;
		case 'c':case 'C':{
			check_helpa = 2;
			mytanka[1].myhelp(1);
		}break;
		}
	}
	if (check_helpa == 2){
		
		check_helpa == 0;
	}
}
/*
功能：判断输赢
a = 1 赢  = 2 输
*/
void Cmap::Printf_lost_win(int a = 0){
	switch (a)
	{
	case 1:	printf("66666666666666666666666666666成功成功成功成功成功成功成功成功成功"); 
		Sleep(2000);
		in_map++;
		break;
	case 2:	printf("99999999999999999999999999999失败失败失败失败失败失败失败失败失败"); 
		in_map = 9;
		Sleep(2000);
		break;	
	}
	
}
//画当前In_map 的地图
void Cmap::DrawMap(){
	if (Goto == 88){
	system("cls");
	system("color 0f");
	}
	for (int i = 0; i < 40; i++){
		for (int j = 0; j < 40; j++)
		{
			if (now_map[i][j] == 2){

				WriteChar(i, j, WALL1_A, WALL1_AC);
			}
			else if (now_map[i][j] == 3){
				WriteChar(i, j, WALL1_A, WALL1_AC);
			}
			else if (now_map[i][j] == 4){
				WriteChar(i, j, WALL1_B, WALL1_BC);
			}
			else if (now_map[i][j] == 5){
				WriteChar(i, j, WALL1_C, WALL1_CC);
			}
			else if (now_map[i][j] == 6){
				WriteChar(i, j, WALL1_D, WALL1_DC);
			}
			else if (now_map[i][j] == 7){
				WriteChar(i, j, WALL1_E, WALL1_EC);
			}
			else if (now_map[i][j] == 8){
				WriteChar(i, j, WALL1_F, WALL1_FC);
			} else{
				now_map[i][j] = 1;
				WriteChar(i, j, "  ", 0);
			}
		}

	}
	

}
//输出右侧显示
void Cmap::myhelp(int swnumb){
	for (int i = 0; i < 40; i++){
		for (int j = 40; j < 56; j++)
		{
			if (j == 40 || j == 55 || i == 0|| i == 39){

				WriteChar(i, j, WALL1_D, WALL1_DC);
			}
			else
			{
				WriteChar(i, j, "  ", 0);
			}
			
		}

	}
	switch (swnumb)
	{
	case 1:{

		char gg[] = "  1P生命值：         ";
		char gg1[] = "  2P生命值：         ";
		char gg2[] = "  剩余敌军:          ";//0x32 41 4  49
		WriteChar(3, 43, gg, B_H_WHITE | 0);
		WriteChar(5, 43, gg1, B_H_WHITE | 0);
		WriteChar(7, 43, gg2, B_H_WHITE | 0);
	}break;
	case 2:{

		char gg[] = "  你已按下暂停键      ";
		char gg1[] = "  X 退出             ";
		char gg2[] = "  C 继续             ";//0x32 41 4  49
		WriteChar(3, 43, gg, B_H_WHITE | 0);
		WriteChar(5, 43, gg1, B_H_WHITE | 0);
		WriteChar(7, 43, gg2, B_H_WHITE | 0);
	
	} break;
	}
	
}
//清除当前40*40的地图
void Cmap::ClearMap(){

	for (int i = 0; i < 40; i++){
		for (int j = 0; j < 40; j++)
		{
			WriteChar(i, j, "  ", 0);

		}
	}


}
/* 
功能：检测坦克碰撞
position：方向
Y  X 坐标
tsize：物体所占大小 //打算A*用的
*/
bool Cmap::cheak_bump(int position, int y, int x, int tsize){
	//now_map 之前用的
	//现在需要添加
	/*
	#define WALL_E    0x7  // ≡   丛林 （隐身）
	#define WALL_F    0x8  // ※  高速路（加速）
	
	int  a;
	int  b;
	int  c;*/
	switch (position)
	{
	case 0:
	{
		y = y - 2;
		if (now_map[y][x + 1] > 1 && now_map[y][x + 1] < 7 ||
			now_map[y][x] > 1 && now_map[y][x] < 7 ||
			now_map[y][x - 1] > 1 && now_map[y][x - 1] < 7){
			return false;
		}
		if (now_map[y][x + 1] >= 10 ||
			now_map[y][x] >= 10 ||
			now_map[y][x - 1] >= 10){
			return false;
		}
		/* a = cheak_Tank_bump(position, y - 2, x + 1, 9);
		 b = cheak_Tank_bump(position, y - 2, x - 1, 9);
		 c = cheak_Tank_bump(position, y - 2, x, 9);*/
	}break;
	case 1:
	{
		y = y + 2;
		if (now_map[y][x + 1] > 1 && now_map[y][x + 1] < 7 ||
			now_map[y][x] > 1     && now_map[y][x] < 7 ||
			now_map[y][x - 1] > 1 && now_map[y][x - 1] < 7){
			return false;

		}
		if (now_map[y][x + 1] >= 10 ||
			now_map[y][x] >= 10 ||
			now_map[y][x - 1] >= 10){
			return false;
		}

	}break;
	case 2:
	{
		x = x - 2;
		if (now_map[y - 1][x] > 1 && now_map[y - 1][x] < 7 ||
			now_map[y    ][x] > 1 && now_map[y    ][x] < 7 ||
			now_map[y + 1][x] > 1 && now_map[y + 1][x] < 7){
			return false;

		}
		if (now_map[y + 1][x] >= 10 ||
			now_map[y][x] >= 10 ||
			now_map[y - 1][x] >= 10){
			return false;
		}
		/*a = cheak_Tank_bump(position, y + 1, x + 2, 9);
		b = cheak_Tank_bump(position, y - 1, x + 2, 9);
		c = cheak_Tank_bump(position, y,     x + 2, 9);*/


	}break;
	case 3:
	{
		x = x + 2;
		if (now_map[y - 1][x] > 1 && now_map[y - 1][x] < 7 ||
			now_map[y][x] > 1 && now_map[y][x] < 7 ||
			now_map[y + 1][x] > 1 && now_map[y + 1][x] < 7){
			return false;

		}
		if (now_map[y + 1][x] >= 10 ||
			now_map[y][x] >= 10 ||
			now_map[y - 1][x] >= 10){
			return false;
		}
		/*
		a = cheak_Tank_bump(position, y + 1, x - 2, 9);
		b = cheak_Tank_bump(position, y - 1, x - 2, 9);
		c = cheak_Tank_bump(position, y,     x - 2, 9);*/

	}break;

	default:
		break;
	}
	//if ((a + b + c) <3)
	//{

	//	return FALSE;
	//	
	//}
	return true;

}
/*
功能： 检测坦克碰撞  【暂时没用】 
position：方向
Y  X 坐标
tsize：物体所占大小 //打算A*用的
*/
bool Cmap::cheak_Tank_bump(int position, int y, int x, int tsize){
	if (now_map[y][x] > 1 && now_map[y][x] < 7)
	{

		return FALSE;
	}
	return true;

}
/*
功能：画坦克
singbo：自定义图形 //但是好像会输出烫烫
color：自定义打印颜色
*/
void Calltank::DrawTank(char singbo[3] = "■", int color = F_WHITE){
	for (int i = 0, lie = m_y - 1; i < 3; lie++, i++){
		for (int j = 0, hang = m_x - 1; j < 3; hang++, j++){
				
			int temp = 0;
			if (t_type == 1 ){
				temp = 10;
			}
			else if (t_type == 2 ){
				temp = 11;
			}
			if (now_map[lie][hang] == 7 ||//坦克第一次进草地
				now_map[lie][hang] > 16//坦克在草地中移动 元素   10 11   17 18都是 
				){
				temp += 7;
				now_map[lie][hang] = temp;//设置草地中  坦克的值
				WriteChar(lie, hang, "∑", 0 | B_H_YELB_PURPLELOW);
				
			}
			else
			{
				if (t_demo[t_position][i][j] == 1){
					now_map[lie][hang] = temp;//设置空白地图 坦克的值
					WriteChar(lie, hang, "■", color);

				}
			}
			
			
			//printf("%d", tankfire.t_demo[tposition][i][j]);
		}
		//printf("\n");
	}
}

/*
功能：清除坦克 
*/
void Calltank::ClerarTank(){

	for (int i = 0, lie = m_y - 1; i < 3; lie++, i++){
		for (int j = 0, hang = m_x - 1; j < 3; hang++, j++){
			//WriteChar(tankfire.m_y, tankfire.m_x, "■", ' ');
			
			
			if (now_map[lie][hang] == 7 ||//坦克第一次进草地
				now_map[lie][hang] > 16//坦克在草地中移动 元素   10 11   17 18都是 
				){
				now_map[lie][hang] = 7;//设置坦克离开草地的值
				WriteChar(lie, hang, "∑", 0 | B_H_GREEN);

			}
			else
			{			
				/*if (now_map[i][j] == 6){ 
					WriteChar(lie, hang, "■", F_WHITE); 
					now_map[lie][hang] = 6;
				}
				else{}*/
				now_map[lie][hang] = 1;//设置坦克离开空白地的值
				WriteChar(lie, hang, "  ", F_WHITE);
				
			}			
		}
		//printf("\n");
	}
}
/*
功能：控制我方坦克移动  和玩家的键盘监控   
*/
void Cmytank::MoveTank(){

	 
	if (!_kbhit() ) return; 
	unsigned	char ch = _getch();
	if (ch == 0xe0)
	{
		char ch1 = _getch();
		ch = ch1;
	}
	switch (ch)
	{
	case 'w':case 'W':
	{
		if (mytanka[0].t_online == 0){ break; }
		mytanka[0].t_position = 0;
		mytanka[0].ClerarTank();
		mytanka[0].DrawTank("■", mytanka[0].t_bg);
		bool cheak_bumpa = cheak_bump(mytanka[0].t_position, mytanka[0].m_y, mytanka[0].m_x, 9);
		if (cheak_bumpa)
		{ 
			mytanka[0].ClerarTank();
			mytanka[0].m_y--;
			mytanka[0].DrawTank("■", mytanka[0].t_bg);
		}
		 
	}break;
	case 's':case 'S':
	{
		if (mytanka[0].t_online == 0){ break; }
		mytanka[0].t_position = 1;
		mytanka[0].ClerarTank();
		mytanka[0].DrawTank("■", mytanka[0].t_bg);
		bool cheak_bumpa = cheak_bump(mytanka[0].t_position, mytanka[0].m_y, mytanka[0].m_x, 9);
		if (cheak_bumpa){
			mytanka[0].ClerarTank();
			mytanka[0].m_y++;
			mytanka[0].DrawTank("■", mytanka[0].t_bg);
		} 
	}break; 
	case 'a':case 'A':
	{
		if (mytanka[0].t_online == 0){ break; }
		mytanka[0].t_position = 2;
		mytanka[0].ClerarTank();
		mytanka[0].DrawTank("■", mytanka[0].t_bg);
		bool cheak_bumpa = cheak_bump(mytanka[0].t_position, mytanka[0].m_y, mytanka[0].m_x, 9);
		if (cheak_bumpa){
			mytanka[0].ClerarTank();
			mytanka[0].m_x--;
			mytanka[0].DrawTank("■", mytanka[0].t_bg);

		}
	}break;
	case 'd':case 'D':
	{
		if (mytanka[0].t_online == 0){ break; }
		mytanka[0].t_position = 3;
		mytanka[0].ClerarTank();
		mytanka[0].DrawTank("■", mytanka[0].t_bg);
		bool cheak_bumpa = cheak_bump(mytanka[0].t_position, mytanka[0].m_y, mytanka[0].m_x, 9);
		if (cheak_bumpa){
			mytanka[0].ClerarTank();
			mytanka[0].m_x++;
			mytanka[0].DrawTank("■", mytanka[0].t_bg);
		} 
	}break;
	// 存子弹
	case 'j':case 'J':
	{
		if (mytanka[0].t_online == 0){ break; }
		Firstball(mytanka[0].t_type, mytanka[0].b_tank, mytanka[0].t_position, mytanka[0].m_x, mytanka[0].m_y, mytanka[0].t_ball);

	}break;
	case 'H':
	{
		if (mytanka[1].t_online == 0){ break; }
		mytanka[1].t_position = 0;
		mytanka[1].ClerarTank();
		mytanka[1].DrawTank("■", mytanka[1].t_bg);
		bool cheak_bumpa = cheak_bump(mytanka[1].t_position, mytanka[1].m_y, mytanka[1].m_x, 9);
		if (cheak_bumpa)
		{
			mytanka[1].ClerarTank();
			mytanka[1].m_y--;
			mytanka[1].DrawTank("■", mytanka[1].t_bg);
		}

	}break;
	case 'P':
	{
		if (mytanka[1].t_online == 0){ break; }
		mytanka[1].t_position = 1;
		mytanka[1].ClerarTank();
		mytanka[1].DrawTank("■", mytanka[1].t_bg);
		bool cheak_bumpa = cheak_bump(mytanka[1].t_position, mytanka[1].m_y, mytanka[1].m_x, 9);
		if (cheak_bumpa){
			mytanka[1].ClerarTank();
			mytanka[1].m_y++;
			mytanka[1].DrawTank("■", mytanka[1].t_bg);
		}
		// 操作坦克
	}break;
	//确定选择 开始进入判断做什么功能的操作 传Y坐标
	case 'K':
	{
		if (mytanka[1].t_online == 0){ break; }
		mytanka[1].t_position = 2;
		mytanka[1].ClerarTank();
		mytanka[1].DrawTank("■", mytanka[1].t_bg);
		bool cheak_bumpa = cheak_bump(mytanka[1].t_position, mytanka[1].m_y, mytanka[1].m_x, 9);
		if (cheak_bumpa){
			mytanka[1].ClerarTank();
			mytanka[1].m_x--;
			mytanka[1].DrawTank("■", mytanka[1].t_bg);

		}
		// 操作坦克
	}break;
	case 'M':
	{
		if (mytanka[1].t_online == 0){ break; }
		mytanka[1].t_position = 3;
		mytanka[1].ClerarTank();
		mytanka[1].DrawTank("■", mytanka[1].t_bg);
		bool cheak_bumpa = cheak_bump(mytanka[1].t_position, mytanka[1].m_y, mytanka[1].m_x, 9);
		if (cheak_bumpa){
			mytanka[1].ClerarTank();
			mytanka[1].m_x++;
			mytanka[1].DrawTank("■", mytanka[1].t_bg);
		}
		// 操作坦克
	}break;
	// 存子弹
	case 'l':case 'L':
	{
		if (mytanka[1].t_online == 0){ break; }
		Firstball(mytanka[1].t_type, mytanka[1].b_tank, mytanka[1].t_position, mytanka[1].m_x, mytanka[1].m_y, mytanka[1].t_ball);
	}break;
	// 游戏退出
	case 'q':case 'Q':
	{
		int check_help = 0;
		mytanka[1].myhelp(2);
		mytanka[1].check_help();
		

	}break;
	case '\r':
	{
		//if (menu_i == 0){
		//	system("cls");
		//	menu_i++;
		//	game_menu(start_menu);
		//}
		//if (menu_i == 2){
		//	system("cls");
		//	menu_i++;
		//	//strcpy(g_nMap, sysMap00 );
		//	DrawMap();
		//}
		// 游戏退出
	}break;
	default:
		break;
	}
}
/*
功能：第一次射出的子弹
int typea,   子弹敌我区分
int b_tank ,  坦克ID
int position, 方向
int b_x   b_y, 子弹XY 坐标
char *ball_style  子弹风格
*/
void Cball::Firstball(int typea, int b_tank ,int position, int b_x, int b_y, char *ball_style){
	for (int i = 0; i < 256; i++)
	{
		int check_a = 0;//当前的子弹是否40X40的越界
		int check_b = 0;//考虑子弹的下个显示的地方是否是空地
		
		//if (now_map[b_y][b_x] > 1){ check_b = 2; }
		// all_ball[i].isBullet 可用之前 判断子弹是否越界
		//如果当前数组子弹还在运行 就不遍历下一个
		if (all_ball[i].isBullet != 0)
		{
			continue;
		}
		else
		{
			switch (position)
			{
			case 0:
			{

				all_ball[i].b_x = b_x;
				all_ball[i].b_y = b_y - 2;
				if (now_map[b_y - 2][b_x] > 1){ check_b = 2; }
				if (all_ball[i].b_y >= 1){ check_a = 1; }
			}break;
			case 1:
			{
				
				all_ball[i].b_x = b_x;
				all_ball[i].b_y = b_y + 2;
				if (now_map[b_y + 2][b_x] > 1){ check_b = 2; }
				if (all_ball[i].b_y < 39){ check_a = 1; }
				//if (now_map[b_y + 2][b_x]  < 2){ check_b = 0; }
				//else if (now_map[all_ball[i].b_x][all_ball[i].b_x] < 10){ check_b = 2; }
				//else{ check_b = 3; }
			}break;
			case 2:
			{
				
				all_ball[i].b_x = b_x - 2;
				all_ball[i].b_y = b_y;
			//	if (all_ball[i].b_x > 1){ check_a = 1; }
				//if (now_map[b_y][b_x - 2] < 2){ check_b = 0; }
				if (all_ball[i].b_x >= 1){ check_a = 1; }
				if (now_map[b_y][b_x - 2] > 1){ check_b = 2; }
				//else if (now_map[all_ball[i].b_x][all_ball[i].b_x] < 10){ check_b = 2; }
				//else{ check_b = 3; }

			}break;
			case 3:
			{
				
				all_ball[i].b_x = b_x + 2;
				all_ball[i].b_y = b_y;
				if (all_ball[i].b_x <= 38){ check_a = 1; }
				if (now_map[b_y][b_x + 2] > 1){ check_b = 2; }
				//else if (now_map[all_ball[i].b_x][all_ball[i].b_x] < 10){ check_b = 2; }
				//else{ check_b = 3; }
			}break;
			}
			if (check_a == 1)
			{
				all_ball[i].isBullet = 1;
				all_ball[i].b_position = position;//朝向
				all_ball[i].b_type = typea;//坦克子弹敌我
				all_ball[i].b_tank = b_tank;//那个坦克发的子弹
				if (all_ball[i].b_type == 10){
					all_ball[i].wArr = 0 | F_H_GREEN;
					if (check_b == 0){
						DrawBall(all_ball[i].b_y, all_ball[i].b_x, 1, all_ball[i].wArr);
					}
				}
				else{
					//char t_ball[3] = "⊙";
					//敌军
					all_ball[i].wArr = 0 | F_H_GREEN;
					if (check_b == 0){
						DrawBall(all_ball[i].b_y, all_ball[i].b_x, 1, all_ball[i].wArr);
					}
				}


			}
			break;


		}

	}

}
/*
功能：循环子弹  
*/
void Cball::tank_ball()
{
	for (int i = 0; i < 256; i++)
	{
		//all_ball[i]
		int ay = all_ball[i].b_y;
		int ax = all_ball[i].b_x;
		if (all_ball[i].isBullet == 0)		{	 continue; }
		else
		{
			int a = 0;//判断是否隐藏子弹 1隐藏 0 不隐藏
			if ((now_map[ay][ax] == 5) ||
				(now_map[ay][ax] == 7) ||
				(now_map[ay][ax] == 8) ||
				(now_map[ay][ax] == 9))
			{
				a = 1;
			}//隐藏 a
			else
			{ 
				if ((now_map[ay][ax] == 6)){
					
					all_ball[i].isBullet = 0;
					break;
				} 
				DrawBall(all_ball[i].b_y, all_ball[i].b_x, 0, F_H_GREEN);
				
			}
			switch (all_ball[i].b_position)
			{
			case 0:
			{
				//子弹类型（敌我） 朝向 Y坐标 X坐标 子弹体积 当前数组 
				if (cheak_ball_bump(all_ball[i].b_type, all_ball[i].b_position, ay - 1, ax, 1, i))
				{
					if (a = 1 && (all_ball[i].b_y > 0)) {
						all_ball[i].b_y--;
						continue;
					}
				}
				else
				{
					all_ball[i].isBullet = 0;
					continue;
				}
			}break;
			case 1:
			{
				//子弹类型（敌我） 朝向 Y坐标 X坐标 子弹体积 当前数组 
				if (cheak_ball_bump(all_ball[i].b_type, all_ball[i].b_position, ay + 1, ax, 1, i))
				{
					if (a = 1 && (all_ball[i].b_y < 40)) {
						all_ball[i].b_y++;
						continue;
					}
				}
				else
				{
					all_ball[i].isBullet = 0;
					continue;
				}
			}break;
			case 2:
			{
				//子弹类型（敌我） 朝向 Y坐标 X坐标 子弹体积 当前数组 
				if (cheak_ball_bump(all_ball[i].b_type, all_ball[i].b_position, ay, ax - 1, 1, i))
				{
					if (a = 1 && (ax > 0)) {
						all_ball[i].b_x--;
						continue;
					}
				}
				else
				{
					all_ball[i].isBullet = 0;
					continue;
				}
			}break;
			case 3:
			{
				//子弹类型（敌我） 朝向 Y坐标 X坐标 子弹体积 当前数组 
				if (cheak_ball_bump(all_ball[i].b_type, all_ball[i].b_position, ay, ax + 1, 1, i))
				{
					if (a = 1 && all_ball[i].b_x < 39) {
						all_ball[i].b_x++;
						continue;
					}
				}
				else
				{
					all_ball[i].isBullet = 0;
					continue;
				}
			}break;
			}

		}
	}
}
/*
功能：画子弹 
int balltype 判断是清除还是画子弹
WORD wArr = 0  字体背景颜色
*/
void Cmap::DrawBall(int y, int x, int balltype, WORD wArr = 0){
	
	if (balltype == 1 ){
		WriteChar(y, x, "◎", wArr);
		now_map[y][x] = 13;
	}
	else
	{
		WriteChar(y, x, "  ", wArr);
		now_map[y][x] = 1;
	}
}

/*
功能：检测子弹碰撞
int typea    子弹敌我
int position  方向
int y, int x
int tsize,  子弹占用位置
int i  子弹数组的值
*/
bool Cmap::cheak_ball_bump(int typea, int position, int y, int x, int tsize, int i){
	// || now_map[y + 1][x] == 6 || now_map[y - 1][x] == 6 || now_map[y][x - 1] == 6 || now_map[y][x + 1] == 6
	if (now_map[y][x] == 6)
	{
		all_ball[i].isBullet = 0;
		return true;
	}
	//河流 丛林 高速路 箱子 子弹经过不会清除 选择不打印子弹 坐标增加
	else if ((now_map[y][x] == 5) || (now_map[y][x] == 7) || (now_map[y][x] == 8) || (now_map[y][x] == 9))
	{
		switch (now_map[y][x])
		{
		case 5:
		{
			WriteChar(y, x, WALL1_C, WALL1_CC);
		}break;
		case 7:
		{
			WriteChar(y, x, WALL1_E, WALL1_EC);
		}break;
		case 9://buff
		{
			WriteChar(y, x, WALL1_F, WALL1_FC);
		}break;
		}
	}
	else if (now_map[y][x] > 1 && now_map[y][x] < 5)
	{
		all_ball[i].isBullet = 0;
		//尝试子弹计算墙体厚度;
		if (now_map[y][x] < 4){
			now_map[y][x] = 1;
		//	WriteChar(y, x, "  ", F_H_GREEN | 0);
			DrawBall(y, x, 0, 0 | F_H_GREEN);
		}
		else
		{
			now_map[y][x]--;
		}
		return false;
	}
	else if (now_map[y][x] > 9)
	{ 
		//t_type子弹类型 1 是我方子弹 2是敌方子弹   敌方坦克 11 我方坦克10  坦克 的ID号是 b_tank
		//我方子弹打敌方坦克   b_tank 好像暂时无效
			reboottank[i].FindTank(y, x, all_ball[i].b_tank, typea,i);
			
		return false;
	}
	else if (now_map[y][x] == 1)
	{

		DrawBall(y, x, 1, 0 | F_H_GREEN);

		return true;
	}

}
/*
功能：根据子弹来查询碰撞物是否是可以被销毁的
int y, int x
int b_tank   坦克ID
int typea    子弹敌我 
int i  子弹数组的值
*/
void Calltank::FindTank(int y, int x, int b_tank, int b_type,int i ){
	int kk = 0;             //  在空白地图          在草地里
	if (now_map[y][x] == 10 || now_map[y][x] == 17 || now_map[y][x] == 11 || now_map[y][x] == 18){ //子弹打敌方坦克
		if (b_type == 1){//我方子弹打坦克
			for (int k = 0; k < check_Rebottank; k++)
			{
				//如果中心点差值大于2 应该就没有机会碰到坦克
				if (abs(reboottank[k].m_y - y) > 2 && abs(reboottank[k].m_x - x) > 2)
				{
					continue;
				}
				for (int i = 0, lie = reboottank[k].m_y - 1; i < 3; lie++, i++){
					for (int j = 0, hang = reboottank[k].m_x - 1; j < 3; hang++, j++){
						if (lie == y && hang == x){
							reboottank[k].ClerarTank();
							reboottank[k].b_tank = 0;
							reboottank[k].t_online = 0;
							check_Rebottank--;
							kk = k;
							now_max_kill = now_max_kill - 1;//击杀数加1
							char ch[10] = {};
//							sprintf_s(ch, 10, "%s", now_max_kill);
							_itoa_s(now_max_kill, ch, 10);
							if (now_max_kill == 0){
								Printf_lost_win(1);//闯关成功  
							}
							WriteChar(7, 51, "  ", B_H_WHITE | B_H_WHITE);
							WriteChar(7, 51, ch, B_H_WHITE | B_H_WHITE);
							return;
						}
					}
				}
			}
		}
		else //敌方子弹打我方坦克
		{
			 
			for (int k = 0; k < Max_play; k++)
			{
				//如果中心点差值大于2 应该就没有机会碰到坦克
				if (abs(mytanka[k].m_y - y) > 2 && abs(mytanka[k].m_x - x) > 2 && mytanka[k].t_online == 0)
				{
					continue;
				}
				for (int i = 0, lie = mytanka[k].m_y - 1; i < 3; lie++, i++){
					for (int j = 0, hang = mytanka[k].m_x - 1; j < 3; hang++, j++){
						if (lie == y && hang == x){
							mytanka[k].ClerarTank();
							mytanka[k].t_online = 0;
							
							check_play = check_play-1;//当前在线玩家
							
							return;
						}
					}
				}
			}
		}
	
	}
	//敌方子弹 和我方子弹对碰  或者我方子弹与敌方子弹对碰
	else if ( now_map[y][x] == 13){
		//int i = 0;
		for (int k = 0; k < 255; k++)
		{
			if (all_ball[k].b_x == x && all_ball[k].b_y == y  && all_ball[k].b_type != b_type){
				//清除当前位置的子弹 
				DrawBall(y, x, 0, 0 | F_H_GREEN);
				all_ball[k].isBullet = 0;//被碰撞的子弹
				all_ball[i].isBullet = 0;//发射的子弹
				return;
			}
		}

		//FindTank(reboottank[i].b_tank, reboottank[i].b_type);

	}
}


/*
功能：机器人坦克自动移动 发射子弹
*/
void CenemyTank::move_enemy()
{
	
	int aa = rand() % 5;
	switch (aa)
	{
	case 1:
	{
		t_position = 0;
		bool cheak_bumpa = cheak_bump(t_position, m_y, m_x, 9);

		if (cheak_bumpa)
		{
			ClerarTank();
			m_y--;
			DrawTank("■", t_bg);
		}

	}break;
	case 2:
	{
		t_position = 1;
		bool cheak_bumpa = cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa)
		{
			ClerarTank();
			m_y++;
			DrawTank("■", t_bg);
		}
	}break;

	case 3:
	{

		t_position = 2;
		bool cheak_bumpa = cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa)
		{
			ClerarTank();
			m_x--;

			DrawTank("■", t_bg);
		}
	}
	break;
	case 4:
	{
		t_position = 3;
		bool cheak_bumpa = cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa)
		{	//WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
			ClerarTank();
			m_x++;

			DrawTank("■", t_bg);
		}
	}
	case 5:
	{
		int bb = rand() % 100;
		if (bb < 20){
		Firstball(t_life, b_tank, t_position, m_x, m_y, t_ball);
		}
		// 发射子弹  没做子弹判断敌我
	}break;
	default:
		break;
	}
};
//功能：敌方坦克的自动刷新 自动生成 
void CenemyTank::production_enemy(){
	for (int i = 0; i < Max_Rebottank; i++)
	{
		//如果当前元素没有刷新 
		
		if (reboottank[i].t_online == 0)
		{
			//画坦克			
			reboottank[i].t_online = 1;
			
			reboottank[i].b_tank = i;
			reboottank[i].t_bg = i+1;
			int aa = rand() % 2;
			if (aa == 1){
				reboottank[i].m_x = 2;
				reboottank[i].m_y = 2;

			}
			else
			{
				reboottank[i].m_x = 37;
				reboottank[i].m_y = 2;
			}
			reboottank[i].DrawTank("■", t_bg);
			reboottank[i].move_enemy();
			check_Rebottank++;
			
			//Max_Rebottank--;
		}
		else
		{
			
			//如果在线就开始让他自己操作
			reboottank[i].move_enemy();
		}
	}
}
//功能：我方坦克的自动刷新 自动生成 
void Cmytank::production_mytank(){
	 
	for (int i = 0; i < Max_play; i++)
	{
	if (mytanka[i].t_online == 0 && mytanka[i].t_life > 0){
			//我方坦克复活	
		mytanka[i].t_life--;
			char ch[8] = {};
			//_itoa_s(mytanka[i].t_life, ch, 9);
			_itoa_s(mytanka[i].t_life, ch, 8);
			if (i == 0){ 		
				WriteChar(3, 51, "  ", B_H_WHITE | B_H_WHITE);
				WriteChar(3, 51, ch, B_H_WHITE | B_H_WHITE);
				///sprintf_s(ch,20,"%s",123);
				mytanka[i].m_x = 30;
				mytanka[i].m_y = 37;
				mytanka[i].t_bg = TANK_G;
			}
			if (i == 1){
				WriteChar(5, 51, "  ", B_H_WHITE | B_H_WHITE);
				WriteChar(5, 51, ch, B_H_WHITE | B_H_WHITE);
				mytanka[i].m_x = 10;
				mytanka[i].m_y = 37;
				mytanka[i].t_bg = TANK_G1;
			}
			mytanka[i].t_online = 1;
			mytanka[i].DrawTank("■", mytanka[i].t_bg);
			check_play = check_play+1;
			
		}	
	}
	if (check_play == 0){
		//没有生命值和我方坦克了 判定输了
		mytanka[0].Printf_lost_win(2); 
	}
	

	

}
/*
功能：所有坦克 和地图元素在新的游戏的初始化
*/
void Calltank::inInit_mytank(){
    //我方坦克初始化
	for (int i = 0; i < Max_play; i++)
	{
		mytanka[i].t_life = Tank_life;//生命值 私有值 
		mytanka[i].t_online = 0;//判定是否已经在线 私有值 
	}
	////敌方坦克初始化
	for (int i = 0; i < Max_Rebottank; i++)
	{
		reboottank[i].t_online = 0;//判定是否已经在线 私有值 
	}
	////子弹初始化
	for (int i = 0; i < 256; i++)
	{
		all_ball[i].isBullet = 0;//判定子弹是否可用 私有值 
	}
}
