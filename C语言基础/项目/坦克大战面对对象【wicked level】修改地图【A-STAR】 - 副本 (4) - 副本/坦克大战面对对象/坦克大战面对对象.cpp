// 坦克大战面对对象.cpp : 定义控制台应用程序的入口点。
// 
#include "stdafx.h"
#include <stdlib.h>
#include "Ceditmap.h"
int _tmain(int argc, _TCHAR* argv[])
{ 
	Cmenu cc;
	Wellcome();//片头 
	while (true)//大循环 可以让所有的地方对接起来
	{	
	cc.main_menu(1);//输出菜单  //除了画地图 和  坦克大战闯关 都在菜单类里面
	switch (Goto)
	{
	case 88:{
		Cmap gmap;   
		gmap.get_max();
		while (in_map < 5) //循环所有的关卡
		{		
		 gmap.ClearMap();
		 gmap.read_map(in_map);//载入当前关卡地图 
		gmap.DrawMap();//画当前关卡地图
		gmap.myhelp(1);//画右侧信息栏 
		 check_Rebottank = 0;//初始化当前活着的我方坦克数量
	   	 check_play = 0;//初始化当前活着的我方坦克数量
		 now_max_kill = max_kill;
		 //需要初始化敌我双方坦克的生命 坐标  初始化子弹
		 
		
		int now_level =  in_map; 
		while ( in_map == now_level) //循环当前关卡
			{ 

			}

		}break;
	}
	case 77:
	{ 
		Cmap gmapa;
		gmapa.read_map( in_map);
		gmapa.DrawMap();
		Ceditmap Editmap;
		//Editmap.Ceditmapa();
		Editmap.Directions();
		Editmap.get_Message(); 
	} 
	}
}
 
	int a = 0;
	return 0;
}

