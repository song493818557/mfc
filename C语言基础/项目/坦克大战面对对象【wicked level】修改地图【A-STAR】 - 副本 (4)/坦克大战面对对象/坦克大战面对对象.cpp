// ̹�˴�ս��Զ���.cpp : �������̨Ӧ�ó������ڵ㡣
// 
#include "stdafx.h"
#include <stdlib.h>
#include "Ceditmap.h"
int _tmain(int argc, _TCHAR* argv[])
{ 
	Cmenu cc;
	Wellcome();//Ƭͷ 
	while (true)//��ѭ�� ���������еĵط��Խ�����
	{	
	cc.main_menu(1);//����˵�  //���˻���ͼ ��  ̹�˴�ս���� ���ڲ˵�������
	switch (Goto)
	{
	case 88:{
		Cmap gmap;   
		gmap.get_max();
		while (in_map < 5) //ѭ�����еĹؿ�
		{		
		 gmap.ClearMap();
		 gmap.read_map(in_map);//���뵱ǰ�ؿ���ͼ 
		gmap.DrawMap();//����ǰ�ؿ���ͼ
		gmap.myhelp(1);//���Ҳ���Ϣ�� 
		 check_Rebottank = 0;//��ʼ����ǰ���ŵ��ҷ�̹������
	   	 check_play = 0;//��ʼ����ǰ���ŵ��ҷ�̹������
		 now_max_kill = max_kill;
		 //��Ҫ��ʼ������˫��̹�˵����� ����  ��ʼ���ӵ�
		 
		
		int now_level =  in_map; 
		while ( in_map == now_level) //ѭ����ǰ�ؿ�
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

