#pragma once
#include "stdafx.h" 
#include "Cgame.h"
#include <string>
#include <vector>
using std::string;
using std::vector;
/***
�������� �����ô�����Ϣ
����һ�����X��
���������߶�Y��
����������ӡ���ַ�
�����ģ���ӡ�ַ�������
***/

bool SetWindowSize(CHAR* pszWindowTitle, int nX, int nY);
void WriteChar(int y, int x, char *pszChar, WORD wArr,int mapid=0);
void Wellcome();
struct position
{
	int y;
	int x;
};
class Cmenu :public Cgame{
public:
	Cmenu(){ 
		m_menu_x = 17;
		charaa.push_back("��");//0
		charaa.push_back(">> ");//1
		charaa.push_back("̹�˴�ս Max ^_^");//2
		charaa.push_back("��  ��ʼ��Ϸ");//3
		charaa.push_back("��  ��Ϸ����");//4
		charaa.push_back("��  ���Ƶ�ͼ");//5
		charaa.push_back("��  ��Ϸ����");//6
		charaa.push_back("��  �˳���Ϸ");//7
		charaa.push_back("��  Player");//8
		charaa.push_back("��  Player");//9
		charaa.push_back("����̹�˹�����");//10
		charaa.push_back("��    ��    ֵ");//11
		charaa.push_back("����̹��������");//12	
		charaa.push_back("����ѡ��,���ҼӼ�ֵ");//13	
		charaa.push_back("ESC �����˳�");//14	
		charaa.push_back("̹�˴�ս�ؿ�һ");//15	
		charaa.push_back("̹�˴�ս�ؿ���");//16	
		charaa.push_back("̹�˴�ս�ؿ���");//17	
		m_menu_y = 7; 
	}
	void main_menu(int a);   //���˵�
	void main_draw();	//������Ŀ��
	void show_menu(int now, int max, int select);//ѭ����ʾ�˵�
	void move_a(bool trrue);	//�򵥵�ѡ����
	void menu_choose();//�˵��ϵļ��̲���
	void menu_Pnumb(int &name, int numb);//��Ϸ��������Ľ�����ת���ַ��� ���������
private:
	vector<char*> charaa;
	WORD wArr = F_H_CYAN | F_H_CYAN;
	int m_menu_state;
	int m_menu_y;
	int m_menu_x;
	int m_max_y;
	int m_min_y;
	bool m_select; 
};