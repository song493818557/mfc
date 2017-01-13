#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "stdafx.h"
#include "menu.h"
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <vector>
using std::vector;

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


//int m_temp_map[40][40];
//static int  m_temp_map[40][40];//���Ƶ�ͼ��������ʱ��
//�ƶ���ײ �������ﴦ��
class Cmap{
public: 
	//��ͼ��ʼ��
	void inInit(){
		FILE * pFile = NULL;
		if (in_map == 2){//�ؿ�һ

			fopen_s(&pFile, "c:\\a\\2.txt", "rb+");
		}
		else if (in_map == 3)//�ؿ���
		{
			fopen_s(&pFile, "c:\\a\\3.txt", "rb+");
		}
		else if (in_map == 4)//�ؿ���
		{
			fopen_s(&pFile, "c:\\a\\4.txt", "rb+");
		}
		fread(
			sysMap00, //д����ʼ��ַ buf2
			4, //һ��Ĵ�С
			20 * 20 * sizeof(int), //д����ٿ�
			pFile);
		fclose(pFile);
		
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				now_map[i][j] = sysMap00[i][j];
			}
		}
		//ÿ�γ�ʼ�� ������Ҫɱ��̹��  �Ժ�����Ż� ��̬�Ļ�ɱ��
		
		
	}
	void DrawMap();//����ͼ
	void ClearMap();//�����ͼ
	static void myhelp(int swnumb);//�Ҳ����
	static void check_help();//����Ҳ�ļ������
	static void Printf_lost_win(int a);//������˻���Ӯ��
	static	int now_map[40][40];
	//void DrawGraphics(int y, int x, int mapid, WORD wArr);
	//�����ײ ��ȫ�ֵ�ͼ������
	
	static	bool cheak_bump(int position, int y, int x, int tsize);//���̹����ײ

	static	bool cheak_ball_bump(int typea, int position, int y, int x, int tsize,int i);
	static	bool  cheak_Tank_bump(int position, int y, int x, int tsize);
	static	void DrawBall(int y, int x, int balltype, WORD wArr);
	
	
private:

};
//A star
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

class Calltank : public Cmap 
{
public:
	Calltank(){};
	~Calltank(){};
	//̹��ģ�;ŷ���  �ĸ�ģ��
	static int t_demo[4][3][3];
	void inInit_mytank();
	void DrawTank(char singbo[3], int color);
	void ClerarTank();
	void FindTank(int y, int x, int b_tank, int b_type, int i);
	bool Canmove();
	int t_life;//����ֵ ˽��ֵ
	int t_type;
	int t_kill;//̹�˻���
	int t_position;//����̹�˷��� ˽��ֵ
	int m_x;//��Ҳ�����̹���ƶ�x���� ˽��ֵ
	int m_y;//��Ҳ�����̹���ƶ�y���� ˽��ֵ
	int t_online = 0;//�ж��Ƿ��Ѿ�����
	int t_speed;//����̹�˵��ٶ�
	int t_hp;//HPѪֵ
	clock_t start;//��ǰ̹�˼�ʱ��ʼ
	clock_t finish;//��ǰ̹�˼�ʱ����
	bool  t_canmove;//�ж��Ƿ����ƶ�
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
		t_life = 2;
		t_online = 0;
		t_type = 1;
		t_position = 0;
		b_tank = 6;
		char t_ball[3] = "��";//�ӵ���ʽ ˽��ֵ
		 t_bg = 0x000;
		 //check_play++;
	};
	//void inInit();//��ʼ��
	void MoveTank();//̹���ƶ�
	void MyKill();//ɱ�м�һ
	void production_mytank();//����̹��+�ж�����û
	~Cmytank(){};
private:

};
//���̹��
class CenemyTank : public Calltank, public Cball, public Castar{
public:
	// ��ʼ������̹�� 10,0, 25, 37, MISSILETYPE_1,F_H_CYAN
	CenemyTank(int y = 30, int x = 32, WORD t_bg = F_H_CYAN){
		t_life = 1;
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
 


#endif