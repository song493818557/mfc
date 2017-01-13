#pragma once
#include "stdafx.h"
#include "tank.h"
#include <conio.h>

int menu_x = 18;
int menu_y = 5;
int menu_i = 0;//菜单选项

void Firstball(){
	for (int i = 0; i < 256; i++)
	{
	#pragma region 
		//如果当前数组子弹还在运行 就不遍历下一个
		if (myball[i].isBullet != 0)
		{
			continue;
		}
		else
		{
			switch (tankfire.t_position)
			{
			case 0:
			{

				myball[i].b_x = tankfire.m_x;
				myball[i].b_y = tankfire.m_y - 2;

			}break;
			case 1:
			{
				myball[i].b_x = tankfire.m_x;
				myball[i].b_y = tankfire.m_y + 2;

			}break;
			case 2:
			{
				myball[i].b_x = tankfire.m_x - 2;
				myball[i].b_y = tankfire.m_y;

			}break;
			case 3:
			{

				myball[i].b_x = tankfire.m_x + 2;
				myball[i].b_y = tankfire.m_y;

			}break;

			default:
				break;
			}
			myball[i].b_type = 1;
			myball[i].isBullet = true;
			myball[i].b_position = tankfire.t_position;

			//myball[i].t_ball[i] = '*';
			WriteChar(myball[i].b_y, myball[i].b_x, "⊙", 0 | F_H_GREEN);
			//my_fast_ball();
			break;
		}
#pragma endregion
	}

}
//bool cheak_bump();
void my_fast_ball()
{
	for (int i = 0; i < 256; i++)
	{
		//myball[i]
		if (myball[i].isBullet == 0)
		{
			continue;
		}
		else
		{
			int a = 0;

			switch (myball[i].b_position)
			{
			case 0:
			{
				/*
				超强版 以后再弄
				WALL* objWall = (WALL*) &sysMap00[myball[i].b_y + 1][myball[i].b_x];
				switch (objWall->nType)
				{
				case 1:
				objWall->nXue;
				break;
				}*/

				if (sysMap00[myball[i].b_y - 1][myball[i].b_x] == 6)
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
					//WriteChar(myball[i].b_y, myball[i].b_x + 1, "  ", 0 | 0);

					myball[i].isBullet = 0;
					continue;
				}
				//河流 丛林 高速路 箱子 子弹经过不会清除 选择不打印子弹 坐标增加
				else if ((sysMap00[myball[i].b_y][myball[i].b_x] == 5) || (sysMap00[myball[i].b_y][myball[i].b_x] == 7) || (sysMap00[myball[i].b_y][myball[i].b_x] == 8) || (sysMap00[myball[i].b_y][myball[i].b_x] == 9))
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
					WriteChar(myball[i].b_y, myball[i].b_x, "≈", B_H_WHITE);
				}
				//
				else if (sysMap00[myball[i].b_y - 1][myball[i].b_x] > 1 && sysMap00[myball[i].b_y - 1][myball[i].b_x] < 5)
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | 0);
					WriteChar(myball[i].b_y - 1, myball[i].b_x, "  ", 0 | 0);
					myball[i].isBullet = 0;
					//尝试子弹计算墙体厚度;
					if (sysMap00[myball[i].b_y][myball[i].b_x] == 2){
						WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | 0);
					}
					sysMap00[myball[i].b_y - 1][myball[i].b_x]--;
					continue;
				}
				else
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0);
				}
				myball[i].b_y--;


			}break;
			case 1:
			{
				if (sysMap00[myball[i].b_y + 1][myball[i].b_x] == 6)
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
					//WriteChar(myball[i].b_y, myball[i].b_x + 1, "  ", 0 | 0);

					myball[i].isBullet = 0;
					continue;
				}
				//河流 丛林 高速路 箱子 子弹经过不会清除 选择不打印子弹 坐标增加
				else if ((sysMap00[myball[i].b_y][myball[i].b_x] == 5) || (sysMap00[myball[i].b_y][myball[i].b_x] == 7) || (sysMap00[myball[i].b_y][myball[i].b_x] == 8) || (sysMap00[myball[i].b_y][myball[i].b_x] == 9))
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
					WriteChar(myball[i].b_y, myball[i].b_x, "≈", B_H_WHITE);
				}
				else if (sysMap00[myball[i].b_y + 1][myball[i].b_x] > 1 && sysMap00[myball[i].b_y + 1][myball[i].b_x] < 5)
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | 0);
					WriteChar(myball[i].b_y + 1, myball[i].b_x, "  ", 0 | 0);
					myball[i].isBullet = 0;
					//尝试子弹计算墙体厚度;
					if (sysMap00[myball[i].b_y + 1][myball[i].b_x] == 2){
						WriteChar(myball[i].b_y + 1, myball[i].b_x, "  ", 0 | 0);
					}
					sysMap00[myball[i].b_y + 1][myball[i].b_x]--;
					continue;
				}
				else
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0);
				}
				myball[i].b_y++;
			}break;
			case 2:
			{
				if (sysMap00[myball[i].b_y][myball[i].b_x - 1] == 6)
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
					//WriteChar(myball[i].b_y, myball[i].b_x + 1, "  ", 0 | 0);

					myball[i].isBullet = 0;
					continue;
				}
				//河流 丛林 高速路 箱子 子弹经过不会清除 选择不打印子弹 坐标增加
				else if ((sysMap00[myball[i].b_y][myball[i].b_x] == 5) || (sysMap00[myball[i].b_y][myball[i].b_x] == 7) || (sysMap00[myball[i].b_y][myball[i].b_x] == 8) || (sysMap00[myball[i].b_y][myball[i].b_x] == 9))
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
					WriteChar(myball[i].b_y, myball[i].b_x, "≈", B_H_WHITE);
				}
				else if (sysMap00[myball[i].b_y][myball[i].b_x - 1] > 1 && sysMap00[myball[i].b_y][myball[i].b_x - 1] < 5)
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | 0);
					WriteChar(myball[i].b_y, myball[i].b_x - 1, "  ", 0 | 0);
					myball[i].isBullet = 0;
					//尝试子弹计算墙体厚度;
					if (sysMap00[myball[i].b_y][myball[i].b_x - 1] == 2){
						WriteChar(myball[i].b_y, myball[i].b_x - 1, "  ", 0 | 0);
					}
					sysMap00[myball[i].b_y][myball[i].b_x - 1]--;
					continue;
				}
				else
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0);
				}
				myball[i].b_x--;

			}break;
			case 3:
			{
				if (sysMap00[myball[i].b_y][myball[i].b_x + 1] == 6)
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0);
					//WriteChar(myball[i].b_y, myball[i].b_x + 1, "  ", 0 | 0);

					myball[i].isBullet = 0;
					continue;
				}
				//河流 丛林 高速路 箱子 子弹经过不会清除 选择不打印子弹 坐标增加
				else if ((sysMap00[myball[i].b_y][myball[i].b_x] == 5) || (sysMap00[myball[i].b_y][myball[i].b_x + 1] == 7) || (sysMap00[myball[i].b_y][myball[i].b_x + 1] == 8) || (sysMap00[myball[i].b_y][myball[i].b_x + 1] == 9))
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
					WriteChar(myball[i].b_y, myball[i].b_x, "≈", B_H_WHITE);
					///WriteChar(myball[i].b_y, myball[i].b_x + 1, "≈", 0 | 0);
				}
				else if (sysMap00[myball[i].b_y][myball[i].b_x + 1] > 1 && sysMap00[myball[i].b_y][myball[i].b_x + 1] < 5)
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | 0);
					WriteChar(myball[i].b_y, myball[i].b_x - 1, "  ", 0 | 0);
					myball[i].isBullet = 0;
					//WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0 | F_H_GREEN);
					//尝试子弹计算墙体厚度;
					if (sysMap00[myball[i].b_y][myball[i].b_x + 1] == 2){
						WriteChar(myball[i].b_y, myball[i].b_x + 1, "  ", 0 | 0);
					}
					//
					sysMap00[myball[i].b_y][myball[i].b_x + 1]--;
					continue;
				}
				else
				{
					WriteChar(myball[i].b_y, myball[i].b_x, "  ", 0);
				}

				myball[i].b_x++;

			}break;
			default:
				break;
			}



			WriteChar(myball[i].b_y, myball[i].b_x, "⊙", 0 | F_H_GREEN);
		}

	}
}

void Firstballa(){
	for (int i = 0; i < 256; i++)
	{
		//如果当前数组子弹还在运行 就不遍历下一个
		if (myball[i].isBullet != 0)
		{
			continue;
		}
		else
		{
			switch (tankRobot.t_position)
			{
			case 0:
			{
				if ((tankRobot.m_y - 2) > 1 && tankRobot.m_x < 39){

					myball[i].b_x = tankRobot.m_x;
					myball[i].b_y = tankRobot.m_y - 2;
				}


			}break;
			case 1:
			{
				if ((tankRobot.m_y + 2) < 38 && tankRobot.m_x < 39){
					myball[i].b_x = tankRobot.m_x;
					myball[i].b_y = tankRobot.m_y + 2;

				}
			}break;
			case 2:
			{
				if ((tankRobot.m_x - 2) < 38 && tankRobot.m_y < 39)
				{
					myball[i].b_x = tankRobot.m_x - 2;
					myball[i].b_y = tankRobot.m_y;
				}
			}break;
			case 3:
			{
				if ((tankRobot.m_x + 2) < 38 && tankRobot.m_y < 39){
					myball[i].b_x = tankRobot.m_x + 2;
					myball[i].b_y = tankRobot.m_y;
				}
			}break;

			default:
				break;
			}
			myball[i].b_type = 1;
			myball[i].isBullet = true;
			myball[i].b_position = tankRobot.t_position;

			//myball[i].t_ball[i] = '*';
			WriteChar(myball[i].b_y, myball[i].b_x, "⊙", 0 | F_H_GREEN);
			//my_fast_ball();
			break;
		}

	}

}
//坦克的检测碰撞
bool cheak_bump(){

	int x = tankfire.m_x;
	int y = tankfire.m_y;
	switch (tankfire.t_position)
	{
	case 0:
	{
		if (sysMap00[y - 2][x + 1] > 1 && sysMap00[y - 2][x + 1] < 7 ||
			sysMap00[y - 2][x] > 1 && sysMap00[y - 2][x] < 7 ||
			sysMap00[y - 2][x - 1] > 1 && sysMap00[y - 2][x - 1] < 7)
		{

			return FALSE;
			break;
		}


	}break;
	case 1:
	{
		if (sysMap00[y + 2][x + 1] > 1 && sysMap00[y + 2][x + 1] < 7 ||
			sysMap00[y + 2][x] > 1 && sysMap00[y + 2][x] < 7 ||
			sysMap00[y + 2][x - 1] > 1 && sysMap00[y + 2][x - 1] < 7)
		{

			return FALSE;
			break;
		}

	}break;
	case 2:
	{
		if (sysMap00[y + 1][x - 2] > 1 && sysMap00[y + 1][x - 2] < 7 ||
			sysMap00[y][x - 2] > 1 && sysMap00[y][x - 2] < 7 ||
			sysMap00[y - 1][x - 2] > 1 && sysMap00[y - 1][x - 2] < 7)
		{

			return FALSE;
			break;
		}

	}break;
	case 3:
	{
		if (sysMap00[y + 1][x + 2] > 1 && sysMap00[y + 1][x + 2] < 7 ||
			sysMap00[y][x + 2] > 1 && sysMap00[y][x + 2] < 7 ||
			sysMap00[y - 1][x + 2] > 1 && sysMap00[y - 1][x + 2] < 7)
		{

			return FALSE;
			break;
		}

	}break;

	default:
		break;
	}
	return true;

}


bool cheak_rebotbump(){

	int x = tankRobot.m_x;
	int y = tankRobot.m_y;
	switch (tankRobot.t_position)
	{
	case UP:
	{
		if (sysMap00[y - 3][x + 1] >1 || sysMap00[y - 3][x] >1 || sysMap00[y - 3][x - 1] >1)
		{

			return FALSE;
			break;
		}


	}break;
	case DOWN:
	{
		if (sysMap00[y + 3][x + 1] > 1 ||
			sysMap00[y + 3][x] > 1 ||
			sysMap00[y + 3][x - 1] > 1)
		{

			return FALSE;
			break;
		}

	}break;
	case LEFT:
	{		//距离
		if (sysMap00[y + 1][x - 3] > 1 ||
			sysMap00[y][x - 3] > 1 ||
			sysMap00[y - 1][x - 3] > 1)
		{

			return FALSE;
			break;
		}

	}break;
	case RIGHT:
	{
		if (sysMap00[y + 1][x + 3] > 1 ||
			sysMap00[y][x + 3] > 1 ||
			sysMap00[y - 1][x + 3] > 1)
		{

			return FALSE;
			break;
		}

	}break;

	default:
		break;
	}
	return true;

}

void Robot_tank(){
	//DrawrobotTank();
	int aa = rand() % 6;
	switch (aa)
	{
	case 1:
	{
		//尝试修复 不能解决因为距离 坦克打印屏蔽地图元素的问题 以后有时间再处理 
		/*for (int i = 0; i < 3; i++)
		{
		ClearrobotTank();
		tankRobot.t_position = i;
		DrawrobotTank();
		//检测通过
		if (cheak_rebotbump() ){
		//方向正确 坐标减一
		if (tankRobot.t_position == UP){
		ClearrobotTank();
		tankRobot.m_y = tankRobot.m_y - 1;
		DrawrobotTank();
		}
		else
		{
		ClearrobotTank();
		DrawrobotTank();

		}
		break;
		}
		}*/
		/*else{
		tankRobot.m_y = tankRobot.m_y - 1;



		}*/
		bool cheak_bumpa = cheak_rebotbump();
		if (cheak_bumpa)
		{
			//WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
			ClearrobotTank();
			tankRobot.m_y = tankRobot.m_y - 1;
			tankRobot.t_position = 0;
			DrawrobotTank();
		}
		else{
			ClearrobotTank();

			tankRobot.t_position = 1;
			DrawrobotTank();
			// tankRobot.m_y = tankRobot.m_y + 1;
			// tankRobot.m_y = tankRobot.m_y + 1;
		}
	}break;
	case 2:
	{

		bool cheak_bumpa = cheak_rebotbump();
		if (cheak_bumpa)
		{
			//WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
			ClearrobotTank();
			tankRobot.m_y = tankRobot.m_y + 1;
			tankRobot.t_position = 1;
			DrawrobotTank();
		}
		else{
			ClearrobotTank();

			tankRobot.t_position = 0;
			DrawrobotTank();
			// tankRobot.m_y = tankRobot.m_y - 1;
			// tankRobot.m_y = tankRobot.m_y + 1;
		}

		//WriteChar(menu_y, menu_x, menu_char, wArr);

		// 操作坦克
	}break;

	case 3:
	{

		bool cheak_bumpa = cheak_rebotbump();
		if (cheak_bumpa)
		{//WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
			ClearrobotTank();
			tankRobot.m_x = tankRobot.m_x - 1;
			tankRobot.t_position = 2;
			DrawrobotTank();
		}
		else
		{

			//方向判断不对 就进行清楚 打印反方向坦克 
			ClearrobotTank();
			//
			tankRobot.t_position = 3;
			DrawrobotTank();

			// tankRobot.m_x = tankRobot.m_x - 1;
		}
		//WriteChar(menu_y, menu_x, menu_char, wArr);

		// 操作坦克
	}break;

	case 4:
	{

		bool cheak_bumpa = cheak_rebotbump();
		if (cheak_bumpa)
		{//WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
			ClearrobotTank();
			tankRobot.m_x = tankRobot.m_x + 1;
			tankRobot.t_position = 3;
			DrawrobotTank();
		}
		else
		{
			ClearrobotTank();

			tankRobot.t_position = 2;
			DrawrobotTank();
			// tankRobot.m_x = tankRobot.m_x - 1;
			//tankRobot.m_x = tankRobot.m_x + 1;
		}
		//WriteChar(menu_y, menu_x, menu_char, wArr);

		// 操作坦克
	} case 5:
	{
		// Firstballa();
		// 发射子弹  没做子弹判断敌我
	}break;
	default:
		break;
	}

	//}

	//DrawrobotTank();
}
void MoveTank(){
	int i = 0;
	while (1)
	{
		if (i % 3000 == 0)
		{
			//Robot_tank();//自动操作坦克
			my_fast_ball();
			i = 0;
		}

		i++;
		if (_kbhit()){
			unsigned	char ch = _getch();

			if (ch == 0xe0)
			{
				char ch1 = _getch();
				ch = ch1;
			}

			switch (ch)
			{

			case 'w':case 'W':case 'H':
			{


				tankfire.t_position = 0;
				bool cheak_bumpa = cheak_bump();
				if (cheak_bumpa)
				{//WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
					ClerarTank();
					tankfire.m_y = tankfire.m_y - 1;

					DrawTank();
				}
				//WriteChar(menu_y, menu_x, menu_char, wArr);

				// 操作坦克
			}break;
			case 's':case 'S':case 'P':
			{
				tankfire.t_position = 1;
				bool cheak_bumpa = cheak_bump();


				if (cheak_bumpa){
					ClerarTank();
					tankfire.m_y = tankfire.m_y + 1;

					DrawTank();

				}
				// 操作坦克
			}break;
			//确定选择 开始进入判断做什么功能的操作 传Y坐标

			case 'a':case 'A':case 'K':
			{


				tankfire.t_position = 2;
				bool cheak_bumpa = cheak_bump();
				if (cheak_bumpa){
					ClerarTank();
					tankfire.m_x = tankfire.m_x - 1;

					DrawTank();
				}
				// 操作坦克
			}break;
			case 'd':case 'D':case 'M':
			{



				tankfire.t_position = 3;
				bool cheak_bumpa = cheak_bump();
				if (cheak_bumpa){
					ClerarTank();
					tankfire.m_x = tankfire.m_x + 1;

					DrawTank();
				}
				// 操作坦克
			}break;
			// 游戏退出
			case 'j':case 'J':
			{
				Firstball();
				// 游戏退出
			}break;
			case 'q':case 'Q':
			{

			}break;
			case '\r':
			{
				if (menu_i == 0){
					system("cls");
					menu_i++;
					game_menu(start_menu);
				}
				if (menu_i == 2){
					system("cls");
					menu_i++;
					//strcpy(g_nMap, sysMap00 );
					DrawMap();
				}
				// 游戏退出
			}break;
			default:
				break;
			}

		}
	}
}
