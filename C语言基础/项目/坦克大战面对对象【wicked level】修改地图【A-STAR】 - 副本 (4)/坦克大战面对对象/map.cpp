
#pragma once
#include "stdafx.h"
#include "map.h"


//我方坦克

//所有子弹
//vector<Cball> all_ball[256]; 





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
				myhelp(1);
			//游戏失败
			//游戏中途退出
		}break;
		case 'c':case 'C':{
			check_helpa = 2;
			myhelp(1);
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
 