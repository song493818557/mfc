// ̹�˴�ս��Զ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include "Ceditmap.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;//�Ƿ���ʾ���
	SetConsoleTitle(L"̹�˴�ս");	
	Cmenu cc;
	Wellcome();//Ƭͷ
	while (true)//��ѭ�� ���������еĵط��Խ�����
	{	
	cc.main_menu(1);//����˵�  //���˻���ͼ ��  ̹�˴�ս���� ���ڲ˵�������
	switch (Goto)
	{
	case 88:{
		Cmap gmap; 
		Cmytank mytank;
		Cball Allball;
		CenemyTank Reboottank; 		
		while (in_map < 5) //ѭ�����еĹؿ�
		{		
		gmap.inInit();//���뵱ǰ�ؿ���ͼ
		gmap.DrawMap();//����ǰ�ؿ���ͼ
		gmap.myhelp(1);//���Ҳ���Ϣ�� 
		 check_Rebottank = 0;//��ʼ����ǰ���ŵ��ҷ�̹������
		 check_play = 0;//��ʼ����ǰ���ŵ��ҷ�̹������
		 now_max_kill = max_kill;
		 //��Ҫ��ʼ������˫��̹�˵����� ����  ��ʼ���ӵ�
		 mytank.inInit_mytank();		 
		mytank.production_mytank();
		int i = 0;
		//
		int now_level = in_map;
			while (in_map == now_level) //ѭ����ǰ�ؿ�
			{
				if (i % 10000 == 0)
				{
					Reboottank.production_enemy();
					i = 0;
				}
				if (i % 3000 == 0)
				{
					Allball.tank_ball();
				}
				if (i % 50000 == 0){
					mytank.production_mytank();
				}
				
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

