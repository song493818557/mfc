#pragma once
#include "AASART.h"

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
