// ̹�˴�ս��Զ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include "map.h"



int _tmain(int argc, _TCHAR* argv[])
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;//�Ƿ���ʾ���
	SetConsoleTitle(L"̹�˴�ս");
	WORD wArr = FOREGROUND_INTENSITY;
	Cmap gmap;
	Cmytank mytank;
	Cball Allball;
	gmap.DrawMap();
	CenemyTank Reboottank;
	mytank.DrawTank("��", F_H_CYAN);
	
	//WriteChar(5, 18, "aaaa", 0x0040);
	//SetWindowSize("̹�˴�ս", 800, 600);
		int i = 0;
	while (1)
	{
		if (i % 7000 == 0)
		{
			Reboottank.production_enemy();
			i = 0;
		}
		if (i % 3000 == 0)
		{
			Allball.tank_ball();
		}
		mytank.MoveTank();
		i++;
	}
	//reboottank[0].move_enemy(&reboottank[0]);

	int a = 0;
	return 0;
}

