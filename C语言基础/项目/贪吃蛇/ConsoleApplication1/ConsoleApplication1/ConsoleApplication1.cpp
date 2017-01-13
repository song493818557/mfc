// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Csnake.h"


int _tmain(int argc, _TCHAR* argv[])
{
	/*
	自动刷新食物
	自动移动
	只有3个移动方向
	判断输赢
	速度控制
	碰撞检测
	*/
	Csnake ssnake;
	Cfood sfood;
	sfood.creat_food();
	ssnake.map_inInit();
	int checkpoint = ssnake.in_map;
	while (ssnake.in_map == checkpoint)
	{
		 
		ssnake.snake_move();
		sfood.push_food();
	}
	return 0;
}

