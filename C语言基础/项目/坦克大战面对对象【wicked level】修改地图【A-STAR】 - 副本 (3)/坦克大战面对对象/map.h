#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "stdafx.h"
#include "Cgame.h"
//#include "Cbuff1.h"
#include <vector>
using  std::vector;

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

//�ƶ���ײ �������ﴦ��
class Cmap:public Cgame{
public: 
	//��ͼ��ʼ��
	void inInit(){
		//read_map(in_map);
		 
		//FILE * pFile = NULL;
		//if (in_map == 2){//�ؿ�һ

		//	fopen_s(&pFile, "c:\\a\\2.txt", "rb+");
		//}
		//else if (in_map == 3)//�ؿ���
		//{
		//	fopen_s(&pFile, "c:\\a\\3.txt", "rb+");
		//}
		//else if (in_map == 4)//�ؿ���
		//{
		//	fopen_s(&pFile, "c:\\a\\4.txt", "rb+");
		//}
		//fread(
		//	sysMap00, //д����ʼ��ַ buf2
		//	4, //һ��Ĵ�С
		//	20 * 20 * sizeof(int), //д����ٿ�
		//	pFile);
		//fclose(pFile);
		//
		//for (int i = 0; i < 40; i++)
		//{
		//	for (int j = 0; j < 40; j++)
		//	{
		//		now_map[i][j] = sysMap00[i][j];
		//	}
		//} 
	}
	void DrawMap();//����ͼ
	void ClearMap();//�����ͼ
	static void myhelp(int swnumb);//�Ҳ����
	static void check_help();//����Ҳ�ļ������
	static void Printf_lost_win();//������˻���Ӯ��
	static	int now_map[40][40];  

	//�����ײ ��ȫ�ֵ�ͼ������ 
	static	bool cheak_ball_bump(int typea, int position, int y, int x, int tsize,int i);
	static	bool cheak_Tank_bump(int position, int y, int x, int tsize);
	static	void DrawBall(int y, int x, int balltype, WORD wArr);
	static bool Canmove(clock_t& t_start, int t_speed);
	static bool get_char(char& t_start);
	clock_t ball_speed = 30;
	clock_t ball_start = 0;
	clock_t production_star = 0;
	clock_t production_speed = 500;
	clock_t buff_star = 0;
	clock_t buff_speed = 500;
private:

};

 





#endif