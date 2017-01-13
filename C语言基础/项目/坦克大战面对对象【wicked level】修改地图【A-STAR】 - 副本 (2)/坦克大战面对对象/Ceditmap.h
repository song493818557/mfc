#pragma once
#include "map.h"
 
class Ceditmap :public Cmap, public Cmenu
{
	
public:
	Ceditmap(){
		gga.push_back("  ------------------   ");
		gga.push_back("��       2���հ�     ��");//0x32 41 4  49
		gga.push_back("��       3����ǽ     ��");//0x33 41 6
		gga.push_back("��       4����ǽ     ��");//0x34 41 8
		gga.push_back("��       5������     ��");//0x35 41 10 
		gga.push_back("��       6���ϰ�     ��");//0x36 41 12 		
		gga.push_back("��       7���ݵ�     ��");//0x37 41 14 	  
		gga.push_back("��       �������ͼ  ��");
		gga.push_back("��       �Ҽ����    ��");
		gga.push_back("��       ���棨S��   ��");//0X73 0X53  41 27
		gga.push_back("��       ��ȡ��L��   ��");//0X4C 0X6C  41 29
		gga.push_back("��      Ĭ�ϣ�D��    ��");//0X64 0X44  41 31
		gga.push_back("��      �˳� (Q)     ��");//0X71 0X51  41 33
	
	};//������Ҫ�õ���һЩ������Ϣ
	void Directions();//�������
	void outputPos(int nX, int nY);//�������
	void keyevent(KEY_EVENT_RECORD ker);//���ռ��̵ĺ���
	void mouseEvent(MOUSE_EVENT_RECORD mer);//�������ĺ���
	int get_Message();//��ȡ�¼�����
	void small_menu(int number, int map_id); //�˵���ѡ��
	void Savemap();//����༭�ĵ�ͼ
	void Readmap(int numb);//��ȡ����༭�ĵ�ͼ
	//void Printinfo(int mapid);//��ӡͼ�ε�����  
private:
	int ison=0;
	int m_key_now;//���ռ��̵�ֵ
	int m_key_Previous;//���ռ��̵�ֵ
	int m_bool =0;//�������ڵ�����ֵ
	int m_mouse_Previous;//������һ��ʷ����ֵ
	int m_x;//X����
	int m_y;//Y����
	int m_mapid;//��ǰ��ѡ��ID
	vector<char *> gga;
};

