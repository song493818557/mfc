
#pragma once
#include "stdafx.h"
#include "map.h"
#include <wtypes.h>
//机器人坦克
static CenemyTank reboottank[5];
static  Cmytank mytanka[2];
//我方坦克

//所有子弹
//vector<Cball> all_ball[256]; 
Cball all_ball[256];
//地图
int Cmap::now_map[40][40] = { 0 };
//坦克模型
int Calltank::t_demo[4][3][3] = {
	{ { 2, 1, 2 },
	{ 1, 4, 1 },
	{ 1, 3, 1 } },
	{ { 1, 3, 1 },
	{ 1, 4, 1 },
	{ 2, 1, 2 } },
	{ { 2, 1, 1 },
	{ 1, 4, 3 },
	{ 2, 1, 1 } },
	{ { 1, 1, 2 },
	{ 3, 4, 1 },
	{ 1, 1, 2 } }
};


bool Cmap::get_char(char& nChar){
	if (!_kbhit()) return false;
	char tchar = _getch();
	if (tchar == 0xe0)
	{
		char ch1 = _getch();
		nChar = ch1;
		return true;
	}
	else
	{
		nChar = tchar;
	}
	return true;
}
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
		
		check_helpa = 0;
	}
}
/*
功能：判断输赢
a = 1 赢  = 2 输
*/
void Cmap::Printf_lost_win(){
	if (now_max_kill == 0){
		printf("66666666666666666666666666666成功成功成功成功成功成功成功成功成功");//闯关成功  
			in_map++;	
			Sleep(2000);
	}
	if (check_play == 0){
		//没有生命值和我方坦克了 判定输了
		printf("99999999999999999999999999999失败失败失败失败失败失败失败失败失败");
		in_map = 9;
		Sleep(2000);
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
				WriteChar(i, j, "  ", MAPBG);
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
			WriteChar(i, j, "  ", MAPBG);
			now_map[i][j] = 1;
		}
	} 
}

/*
功能：根据子弹来查询碰撞物是否是可以被销毁的
int y, int x
int b_tank   坦克ID
int typea    子弹敌我
int i  子弹数组的值
*/
bool Cmap::cheak_Tank_bump(int position, int y, int x, int tsize){
	if (now_map[y][x] > 1 && now_map[y][x] < 7)
	{
		return FALSE;
	}
	return true;

}

bool Cmap::Canmove(clock_t& t_start, int t_speed){
	if (((clock() - t_start) / 5) >= t_speed)//判断允许是否移动
	{
		t_start = clock(); //移动后 重新进行计数 
		return true;
	}
	return false;
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
	int ty = all_ball[i].b_y;
	int tx = all_ball[i].b_x;
	switch (now_map[ty][tx])
	{
	case 6: all_ball[i].isBullet = 0;  return false;//铁墙 返回FALSE 不需要清除
	case 4: now_map[ty][ty]--;//有生命值的墙  返回FALSE 不需要清除
	case 3: all_ball[i].isBullet = 0; DrawBall(ty, tx, 0, 0 | F_H_GREEN); return false; //无生命值的墙 返回FALSE 不需要清除 
	}

	DrawBall(ty, tx, 0, F_H_GREEN);
	switch (now_map[y][x])
	{
	case 6: all_ball[i].isBullet = 0;  return false;//铁墙 返回FALSE 不需要清除
	case 4: now_map[y][x]--;//有生命值的墙  返回FALSE 不需要清除
	case 3: all_ball[i].isBullet = 0; DrawBall(y, x, 0, 0 | F_H_GREEN); return false; //无生命值的墙 返回FALSE 不需要清除 
	case 1:case 5:case 7:case 9:case 20:case 21:case 22: DrawBall(y, x, 1, 0 | F_H_GREEN); return true;//河流 true 
	}
	//t_type子弹类型 1 是我方子弹 2是敌方子弹   敌方坦克 11 我方坦克10  坦克 的ID号是 b_tank
	if (now_map[y][x] > 9) {
		reboottank[i].FindTank(y, x, all_ball[i].b_tank, typea, i);
		all_ball[i].isBullet = 0;
		DrawBall(ty, tx, 0, F_H_GREEN);
		return false;
	}
	//子弹对buff处理
	return false;

}


 