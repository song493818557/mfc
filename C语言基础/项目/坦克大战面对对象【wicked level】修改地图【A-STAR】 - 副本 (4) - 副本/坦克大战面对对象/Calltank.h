#pragma once 
#include "Cball.h"
//������̹��
static CenemyTank reboottank[5];
static  Cmytank mytanka[2];
class Calltank : public Cbuff, public Cball, public Castar
{
public:
	Calltank(){};
	~Calltank(){};
	//̹��ģ�;ŷ���  �ĸ�ģ��
	static int t_demo[4][3][3];
	void inInit_mytank();
	static void DrawTank(Calltank &tank);
	static void ClerarTank(int ty, int tx);
	void FindTank(int y, int x, int b_tank, int b_type, int i);
	//void MoveTank(int y,int x,int type);//̹���ƶ�
	//void MoveTank(Calltank &tank);
	void MoveTank();
	void check_buff(int nBuff);
	bool check_point(int b_type, int &y, int &x);//��⸴��λ���Ƿ�ռ��
	static	bool cheak_bump(Calltank &tank, int position, int uy, int ux);//���̹����ײ ����UY UX ����������ֵ
	bool gettankbuff(Calltank &tank, int type);//��⵱ǰ̹����ӵ�е�BUFF״̬
	int t_life;//����ֵ ˽��ֵ
	int t_type;
	int t_kill;//̹�˻���
	int t_position;//����̹�˷��� ˽��ֵ
	int m_x;//��Ҳ�����̹���ƶ�x���� ˽��ֵ
	int m_y;//��Ҳ�����̹���ƶ�y���� ˽��ֵ
	int t_online = 0;//�ж��Ƿ��Ѿ�����
	int t_speed;//����̹�˵��ٶ�
	int t_hp;//HPѪֵ
	int t_ball_speed;//HPѪֵ
	clock_t start;//��ǰ̹�˼�ʱ��ʼ

	bool  t_canmove;//�ж��Ƿ����ƶ�
	WORD t_bg;//̹�˱�����ɫ ˽��ֵ
private:
	int i = 10;
};

class Cmytank : public Calltank {
public:
	// ��ʼ������̹�� 10,0, 25, 37, MISSILETYPE_1,0x000
	Cmytank(){
		t_life = 2;
		t_online = 0;
		t_type = 1;
		t_speed = 30;
		t_position = 0;
		char t_ball[3] = "��";//�ӵ���ʽ ˽��ֵ
		t_bg = 0x000;
		//check_play++;
	};
	//void inInit();//��ʼ��

	void MyKill();//ɱ�м�һ
	void production_mytank();//����̹��+�ж�����û
	~Cmytank(){};
private:

};
//���̹��
class CenemyTank : public Calltank{
public:
	// ��ʼ������̹�� 10,0, 25, 37, MISSILETYPE_1,F_H_CYAN
	CenemyTank(int y = 30, int x = 32, WORD t_bg = F_H_CYAN){

		t_type = 2;
		t_position = 2;
		m_x = x;
		m_y = y;
		t_speed = 50;
		char t_ball[3] = "��";//�ӵ���ʽ ˽��ֵ
		t_bg = F_H_CYAN;
		t_canmove = true;
		start = clock();
		Wayfind = false;
		realfind = true;
	};
	bool move_enemy(CenemyTank &tank, int aa);//�Զ���������̹�� �����ƶ� �����ӵ�
	void production_enemy();//����ˢ����̹��  
	void Wayfind_enemy(CenemyTank &aa, int tankid);//̹��1�Զ�Ѱ· 
	~CenemyTank(){};
	bool Wayfind;//�Ƿ�����Ѱ·
	bool realfind;//�Ƿ�ȷ�� ������ο���
private:
	//int t_speed; ̹���ٶ�
};


