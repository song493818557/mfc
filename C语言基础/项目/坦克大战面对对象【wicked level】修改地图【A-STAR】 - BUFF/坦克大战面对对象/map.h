#pragma once
#include "stdafx.h"
//#include "Cgame.h"
#include "menu.h"
#include "Cbuff.h" 
#include <string>
#include <vector> 
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <wtypes.h>
#include <time.h> 
using  std::vector; 
using namespace std;
class Cmap;
enum{
	AUP,
	ADOWN,
	ALEFT,
	ARIGHT
};
typedef struct _position
{
	int nY;
	int nX;
	int nP;//���� ���淽��
}POSTION;
typedef struct _strstar
{
	POSTION stcpos;//����
	int nH;  //�ƶ������  ���� ��㿪ʼÿ��һ����һ
	int nG;  //��Ŀ�ĵصľ���
	int nF;  //G+H�ĺ�  F��С�������Ϊ�Ǹ�ѡ�ĵ�
	POSTION Fatherpos;//���ڵ�����

}STRSTAR;

class Cgame
{
public: 
	/*
	���ܣ�ѭ�������������¼�
	*/
	static int max_map;//����ͼ����
	void get_Message(int& nChar);
	void read_map(int in_map);
	void save_map(int in_map);
	void get_max();

};
//�ƶ���ײ �������ﴦ��
class Cmap:public Cgame{
public: 
	//��ͼ��ʼ�� 
	void DrawMap();//����ͼ
	void ClearMap();//�����ͼ
	static void myhelp(int swnumb);//�Ҳ����
	static void check_help();//����Ҳ�ļ������
	static void Printf_lost_win();//������˻���Ӯ��
	static	int now_map[40][40];
	//void DrawGraphics(int y, int x, int mapid, WORD wArr);
	//�����ײ ��ȫ�ֵ�ͼ������ 

	static	bool cheak_ball_bump(int typea, int position, int y, int x, int tsize,int i);
	static	bool  cheak_Tank_bump(int position, int y, int x, int tsize);
	static	void DrawBall(int y, int x, int balltype, WORD wArr);
	static bool Canmove(clock_t& t_start, int t_speed);
	static bool get_char(char& t_start);
	clock_t ball_speed = 30;
	clock_t ball_start = 0;
	clock_t production_star = 0;
	clock_t production_speed = 500;
	clock_t buff_star = 0;
	clock_t buff_speed = 500;
	//static  int check_Rebottank;
	//static  int check_play;
	//static  int Tank_life;
	//static  int Max_Rebottank;
	//static  int Max_play;
	//static  int Goto;
	//static  int now_max_kill;
	//static  int check_helpa;
	//static  int max_kill;//��ɱ���ֵ ���ڵ��ھ͹���
	//static  int in_map;//��ǰ��ͼ 
	//static  int now_level;
private:

};



/* ** ̹�����Կ�ʼ** */
class Calltank;
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

class Cbuff : public Cmap {
	/*
	BUFFϵͳ	��ʾ  �߼��ж�
	�޵�
	����
	����(�ֵ�һ���ӵ�) Ȧ
	*/
public:
	Cbuff(){ 	}
	bool buff_state = false;//buff��״̬
	vector<int> buff_type; //����ǰ̹�˻�ȡ����BUFF�������α��浽���� �ﵽBUFF��Ч�����Ե��� ͬһBUFF��ʱ���Ǹ��ǵ� 
	vector<clock_t> buff_Start;//��ǰ̹�˵�BUFF��ʱ��ʼ���� 
	vector<int> buff_time; //��ǰ̹�˵�BUFFͣ��ʱ������  
	static void clearbuff();
	static void creat_buff();
	static void push_buff();
private:
	static clock_t m_Fstart;//�ڵ�ǰ��ͼ���ʱ���ʱ��ʼ
	static int m_stay;//�ڵ�ǰ��ͼ������ʱ��
	static int m_pfood;
	static int max_food;
	static vector<POSTION> m_food;//buff������ �������� �ͷ��� 
	static void draw_buff(int type);

};

class Castar :public  Cmap{
public:
	//���õ�ͼ  ��� �յ�
	void Setmap();
	void Drawmap();
	void Getpath(int now_map[40][40]);
	void PrintPath();
	void reset();
	POSTION sTart;
	POSTION eNd;
	vector<POSTION> m_Path; //���ս��
private:
	vector<STRSTAR> m_Openlist; //��̽��
	vector<STRSTAR> m_Closelist;//�Ѿ�̽��
	int m_map[40][40];
	//���㵱ǰλ�õ��յ�ľ���ֵ x
	int CalcH(POSTION pos_1, POSTION pos_2);
	void WriteChara(int x, int y, char* szString);
};
/* ** ̹�����Խ���** */

//���̹��
class Calltank : public Cbuff, public Cball
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
	void check_buff( int nBuff);
	bool check_point(int b_type,int &y,int &x);//��⸴��λ���Ƿ�ռ��
	static	bool cheak_bump(Calltank &tank, int position, int uy, int ux);//���̹����ײ ����UY UX ����������ֵ
	bool gettankbuff(Calltank &tank,int type);//��⵱ǰ̹����ӵ�е�BUFF״̬
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

class Cmytank : public Calltank  {
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

class CenemyTank : public Calltank, public Castar{
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
	bool move_enemy(CenemyTank &tank,int aa);//�Զ���������̹�� �����ƶ� �����ӵ�
	void production_enemy();//����ˢ����̹��  
	void Wayfind_enemy(CenemyTank &aa,int tankid);//̹��1�Զ�Ѱ· 
	~CenemyTank(){}; 
	bool Wayfind;//�Ƿ�����Ѱ·
	bool realfind;//�Ƿ�ȷ�� ������ο���
private:
	//int t_speed; ̹���ٶ�
};
 


