#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "stdafx.h"
#include "menu.h"
#include <conio.h>

static  int check_Rebottank = 0;
static  int check_play = 0;
static  int Max_Rebottank = 5;
static  int Max_play = 2;

//�ƶ���ײ �������ﴦ��
class Cmap{
public: 
	Cmap(){
		
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				now_map[i][j] = sysMap00[i][j];
			}
		}
		int c = sizeof(sysMap00);
	}
	void DrawMap();
	//�����ײ ��ȫ�ֵ�ͼ������
	static	bool cheak_bump(int position, int y, int x, int tsize);
	static	bool cheak_ball_bump(int typea, int position, int y, int x, int tsize,int i);
	static	bool  cheak_Tank_bump(int position, int y, int x, int tsize);
	static	void DrawBall(int y, int x, int balltype, WORD wArr);
	static	int now_map[40][40];
	
private:
};


class Calltank : public Cmap 
{
public:
	Calltank(){
	
	};
	~Calltank(){};
	//̹��ģ�;ŷ���  �ĸ�ģ��
	static int t_demo[4][3][3];
	void DrawTank(char singbo[3], int color);
	void ClerarTank();
	
	void FindTank(int y, int x, int b_tank, int b_type, int i);
	int t_life;//����ֵ ˽��ֵ
	int t_type;
	int t_position;//����̹�˷��� ˽��ֵ
	int m_x;//��Ҳ�����̹���ƶ�x���� ˽��ֵ
	int m_y;//��Ҳ�����̹���ƶ�y���� ˽��ֵ
	int t_online = 0;//�ж��Ƿ��Ѿ�����
	WORD t_bg;//̹�˱�����ɫ ˽��ֵ
private:
	int i = 10;
};


class Cball : public Cmap {
public:
	void Firstball(int typea, int b_tank, int position, int b_x, int b_y, char *ball_style);
	void tank_ball();
	friend void FindTank(int y, int x, int b_tank, int b_type);
	friend class Cmap;
	bool isBullet = 0;
	int b_type;//�����ӵ�
	int b_tank;//��������ӵ���̹�˱�ʶ
	int b_position;//�����ӵ��ķ���
	int b_x;//��Ҳ�����̹���ƶ�x����
	int b_y;//��Ҳ�����̹���ƶ�y����

	char t_ball[3];//�ӵ��� 
	WORD wArr; //�Ҿ��ӵ� ��ɫ��ʽ
	//WORD wArra; //�о��ӵ� ��ɫ��ʽ

};
class Cmytank : public Calltank ,public Cball {
public:
	// ��ʼ������̹�� 10,0, 25, 37, MISSILETYPE_1,0x000
	Cmytank(){
		t_life = 10;
		t_type = 1;
		t_position = 0;
		t_online = 1;
		m_x = 25;
		m_y = 25;
		b_tank = 6;
		char t_ball[3] = "��";//�ӵ���ʽ ˽��ֵ
		 t_bg = 0x000;
		 check_play++;
	};
	void MoveTank();
	
	~Cmytank(){};
private:

};
class CenemyTank : public Calltank, public Cball{
public:
	// ��ʼ������̹�� 10,0, 25, 37, MISSILETYPE_1,F_H_CYAN
	CenemyTank(int y = 30, int x = 32, WORD t_bg = F_H_CYAN){
		t_life = 0;
		t_type = 2;
		t_position = 2;
		m_x = x;
		m_y = y;
		//check_Rebottank++;
		char t_ball[3] = "��";//�ӵ���ʽ ˽��ֵ
		t_bg = F_H_CYAN;
	};
	void move_enemy();
	void production_enemy();//����ˢ����̹�� 
	~CenemyTank(){};
private:

};




#endif
