#pragma once
#include "map.h"
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

