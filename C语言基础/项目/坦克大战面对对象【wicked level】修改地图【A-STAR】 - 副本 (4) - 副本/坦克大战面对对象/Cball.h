#pragma once 
#include "stdafx.h"
#include "Cbuff.h"

class Cball : public Cmap {
public:
	void Firstball(int typea, int b_tank, int position, int b_x, int b_y, char ball_style[3]);
	void tank_ball();
	friend void FindTank(int y, int x, int b_tank, int b_type);
	friend void MoveTank(Calltank &tank);

	friend class Cmap;
	bool isBullet = 0;
	int b_type;//�����ӵ�
	int b_tank;//��������ӵ���̹�˱�ʶ
	int b_position;//�����ӵ��ķ���
	int b_x;//��Ҳ�����̹���ƶ�x����
	int b_y;//��Ҳ�����̹���ƶ�y����
	int ball_lengh = 0;
	char t_ball[3];//�ӵ��� 
	static int ball_number;//��ǰ�����ӵ���������
	WORD wArr; //�Ҿ��ӵ� ��ɫ��ʽ
	//WORD wArra; //�о��ӵ� ��ɫ��ʽ

};