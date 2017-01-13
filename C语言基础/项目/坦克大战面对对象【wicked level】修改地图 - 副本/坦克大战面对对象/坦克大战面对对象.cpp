// 坦克大战面对对象.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include "Ceditmap.h"


void sleep(clock_t wait);

// Pauses for a specified number of milliseconds.
void sleep(clock_t wait)
{
	clock_t goal;
	goal = wait + clock();
	while (goal > clock()){ ; }
}
int _tmain(int argc, _TCHAR* argv[])
{

	/*long    i = 6000000L;
	clock_t start, finish;
	double  duration;*/

	//// Delay for a specified time.
	//printf("Delay for three seconds\n");
	//sleep((clock_t)10 * CLOCKS_PER_SEC);
	//printf("Done!\n");

	// Measure the duration of an event.
	//printf("Time to do %ld empty loops is ", i);
	//start = clock();
	//while (i--){;}
	//finish = clock();
	//duration = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("%2.1f seconds\n", duration);



	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;//是否显示光标
	SetConsoleTitle(L"坦克大战");	
	Cmenu cc;
	Wellcome();//片头
	while (true)//大循环 可以让所有的地方对接起来
	{	
	cc.main_menu(1);//输出菜单  //除了画地图 和  坦克大战闯关 都在菜单类里面
	switch (Goto)
	{
	case 88:{
		Cmap gmap; 
		Cmytank mytank;
		Cball Allball;
		CenemyTank Reboottank; 		
		while (in_map < 5) //循环所有的关卡
		{		
		gmap.inInit();//载入当前关卡地图
		gmap.DrawMap();//画当前关卡地图
		gmap.myhelp(1);//画右侧信息栏 
		 check_Rebottank = 0;//初始化当前活着的我方坦克数量
		 check_play = 0;//初始化当前活着的我方坦克数量
		 now_max_kill = max_kill;
		 //需要初始化敌我双方坦克的生命 坐标  初始化子弹
		 mytank.inInit_mytank();		 
		mytank.production_mytank();
		int i = 0;
		//
		int now_level = in_map;
			while (in_map == now_level) //循环当前关卡
			{
				
				
				if (i % 3000 == 0)
				{
					Allball.tank_ball();
				}
				if (i % 10000 == 0){
					mytank.production_mytank();
					i = 0;
				}
				Reboottank.production_enemy();
				mytank.MoveTank(); 
				i++;
			}

		}break;
	}
	case 77:
	{
		
	
		Cmap gmapa;
		gmapa.inInit();
		gmapa.DrawMap();
		Ceditmap Editmap;
		//Editmap.Ceditmapa();
		Editmap.Directions();
		Editmap.get_Message();
		
	}

	}
}

	
	//reboottank[0].move_enemy(&reboottank[0]);

	

	int a = 0;
	return 0;
}

