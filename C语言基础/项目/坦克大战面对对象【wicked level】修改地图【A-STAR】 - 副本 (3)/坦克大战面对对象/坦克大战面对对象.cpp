// ̹�˴�ս��Զ���.cpp : �������̨Ӧ�ó������ڵ㡣
// 
#include "stdafx.h"
#include <stdlib.h>
#include "Cgame.h"  
int _tmain(int argc, _TCHAR* argv[])
{ 
	Cmenu cc;
	Wellcome();//Ƭͷ
	int &in_map = Cgame::in_map;
	int &Goto = Cgame::Goto;
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
		 gmap.ClearMap();
		 gmap.read_map(in_map);//���뵱ǰ�ؿ���ͼ 
		gmap.DrawMap();//����ǰ�ؿ���ͼ
		gmap.myhelp(1);//���Ҳ���Ϣ�� 
		 cc.check_Rebottank = 0;//��ʼ����ǰ���ŵ��ҷ�̹������
		cc.check_play = 0;//��ʼ����ǰ���ŵ��ҷ�̹������
		 cc.now_max_kill = cc.max_kill;
		 //��Ҫ��ʼ������˫��̹�˵����� ����  ��ʼ���ӵ�
		
		mytank.inInit_mytank();		 
		mytank.production_mytank();
		
		int now_level = in_map;
		Cbuff::creat_buff();
		while (in_map == now_level) //ѭ����ǰ�ؿ�
			{ 
				if (gmap.Canmove(gmap.ball_start, gmap.ball_speed)) { Allball.tank_ball(); }//���100
				if (gmap.Canmove(gmap.production_star, gmap.production_speed)) {
					Cmap::Printf_lost_win();
					Cbuff::push_buff();
				}//BUFFˢ�� ���3000
				Reboottank.production_enemy();
				mytank.production_mytank();
				mytank.MoveTank();
			}

		}break;
	}
	case 77:
	{ 
		Cmap gmapa;
		gmapa.read_map(in_map);
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

