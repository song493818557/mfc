// 8-6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
#include <conio.h>

struct _tankfire{
	int t_life;//生命值
	char t_demo;//坦克模型
	//int t_map[100][100];//生命值
	int x;//移动x坐标
	int y;//移动y坐标
	//int t_move[100][100];//移动坐标
	int t_ball;//子弹
	//int t_npc_stank;//小坦克
	//int t_npc_jtank;//精英坦克
	//int t_npc_btank;//BOSS坦克

};
_tankfire ttank{ 10, '■', 24, 25, 1 };
//打印屏幕
void box(int array[40][40],int x,int y){
	system("cls");
	for (int i = 0; i <= 40; i++){
		
		for (int j = 0; j <= 40; j++){
			if (i == 0 || i == 40 || j == 0 || j == 40){
				array[i][j] = 1;
			}
			if (array[i][j] == 1){
				printf("■");
			}
			else{
				//i == 24 || i == 25 || j == 24 || j == 25
				if (i == x && j == y || i == x+1 && j == y)
				{
					printf("■");
				} else{
				printf("  ");
				}
			}

			/*
			array[i] = array[i] + array[n - i];
			array[n - i] = array[i] - array[n - i];
			array[i] = array[i] - array[n - i];*/
		}
		printf("\n");
	}
	int aac = 0;
	return;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int arc[40][40] = { 0 }; 
	box(arc,ttank.x,ttank.y);
	for (;1;){
		//开始对坦克的移动进行流程控制	
		ssf:
			int c = _getch();

		switch (c)
		{
		case  'w':
			ttank.x -= 1;
			box(arc, ttank.x, ttank.y); goto ssf; //break;
		case  'a':
			ttank.y -= 1;
			box(arc, ttank.x, ttank.y); goto ssf;  //break;
		case  's':
			ttank.x += 1;
			box(arc, ttank.x, ttank.y); goto ssf; //break;
		case  'd':
			ttank.y += 1;
			box(arc, ttank.x, ttank.y); goto ssf; //break;
		default:
			goto ssf;
			break;
		} 
	}
	//showtan();
	system("pause");
	return 0;
}