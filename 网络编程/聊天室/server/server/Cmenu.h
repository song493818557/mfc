#pragma once
#include "Cbase64.h" 

#include <vector>
using std::vector;
class Cmenu {
public: 
	Cmenu();
	void main_menu(int a);   //���˵�
	void main_draw();	//������Ŀ��
	void show_menu(int now, int max, int select);//ѭ����ʾ�˵�
	void move_a(bool trrue);	//�򵥵�ѡ����
	void menu_choose();//�˵��ϵļ��̲���
	void menu_Pnumb(int &name, int numb);//��Ϸ��������Ľ�����ת���ַ��� ���������
	vector<char*> charaa;
	int m_menu_state;
	int m_menu_y;
	int m_menu_x;
	int m_max_y;
	int m_min_y;
	bool m_select;
private:
	//WORD wArr = F_H_CYAN | F_H_CYAN;
	
};