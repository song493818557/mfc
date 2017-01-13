#include "stdafx.h"
#include "Cbuff.h"


clock_t Cbuff::m_Fstart = 0;//�ڵ�ǰ��ͼ���ʱ���ʱ��ʼ
int Cbuff::m_stay = 1000;//�ڵ�ǰ��ͼ������ʱ��
int Cbuff::m_pfood = 0;
int Cbuff::max_food = 10;
vector<POSTION> Cbuff::m_food;//buff������ �������� �ͷ���
char MAP_BUFF[][3] = { "55", BUFF_GOD_GRAPHICS, BUFF_SPEED_GRAPHICS, BUFF_SHIELD_GRAPHICS };
void Cbuff::creat_buff(){ 
	
	m_Fstart = clock();
	int i = 0;
	while (i < max_food)//�Ż��� ��ˢ���ϰ�������   38 ֵ�õ��ǵ�ͼ��С
	{
		int ty = (double)rand() / (RAND_MAX + 1) * (38 - 1) + 1;
		int tx = (double)rand() / (RAND_MAX + 1) * (38 - 1) + 1;
		if ((now_map[ty][tx]) == 1)
		{
			i++;
			m_food.push_back({ ty, tx, 0 });
		}
	}
}
void Cbuff::push_buff(){
	if (!Canmove(m_Fstart, m_stay)){
		return;
	}
	draw_buff((double)rand() / (RAND_MAX + 1) * (4 - 1) + 1);//���ˢ1-3״̬��BUFF
	//draw_buff(1); 
}
void Cbuff::draw_buff(int type){
	char * wall;
//	WORD  thead;
	wall = MAP_BUFF[type]; 
	WriteChar(27, 26, wall, BUFF_BG);
	now_map[27][26] = 20 + type;
	m_food.clear();
	m_food.push_back({ 27, 26 ,0 });
	m_food.push_back({ 23, 26, 0 });
	clearbuff();
	/*m_pfood = rand() % (max_food - 1);*/
	m_pfood = rand() % 2;
	WriteChar(m_food[m_pfood].nY, m_food[m_pfood].nX, wall, BUFF_BG);
	now_map[m_food[m_pfood].nY][m_food[m_pfood].nX] = 20 + type;
}
void Cbuff::clearbuff(){ 
	WriteChar(m_food[m_pfood].nY, m_food[m_pfood].nX, "  ", MAPBG);
	now_map[m_food[m_pfood].nY][m_food[m_pfood].nX] = 1;
}
//��ӵ��BUFF��̹��
//************************************
// Method:    gettankbuff
// FullName:  Calltank::gettankbuff
// Access:    public 
// ����ֵ:   bool
// Qualifier:
// Parameter: Calltank & tank
// Parameter: int type  type 
//�ٶ���     ��Ϸ����
//̹�˹�����   
//�޵�
//����
//����
//��HP
//������ֵ 
//�ӵ���    
// ��  ���׵�  һ������
// �� ���ٵ�
// ��  ̹��ɱ����ĸ��
//
//��Ұ��� BUFF   �޵� ���� ����  ���ٵ�  ���׵� 
//************************************
bool Calltank::gettankbuff(Calltank &tank, int type){
	if (tank.buff_type[1] == 21) { return true; }//�޵�ģʽ
	else if (tank.buff_type[3] > BUFF_SHIELD_LIEF){ tank.buff_type[3]--; return true; }//����ģʽ
	else { return false; }//����false �����޿��õ�BUFF

//	for (int i = 0; i < 4; i++)
//	{
//		switch (buff_type[i])
//		{
//		case 20: break;
//		case 21:{//����ģʽ 
//			if (!Canmove(buff_Start[i], buff_time[i]))  continue;
//			WriteChar(m_y - 1, m_x - 1, "|", BUFF_BG);
//			WriteChar(m_y - 1, m_x + 1, "|", BUFF_BG);
////			WriteChar(m_y + 1, m_x, TANK_BUFF[0], BUFF_BG);
//		}break;
//		case 22:{//�޵�ģʽ
//			//if (!Canmove(buff_Start[2], buff_time[2]))  continue;
//			WriteChar(m_y - 1, m_x - 1, "��", BUFF_BG);
//			WriteChar(m_y - 1, m_x + 1, "��", BUFF_BG);
//			//WriteChar(m_y + 1, m_x, TANK_BUFF[0], BUFF_BG);
//		}break;
//		case 23:{//����ģʽ
//		//	if (!Canmove(buff_Start[2], buff_time[2]))  continue;
//			WriteChar(m_y - 1, m_x - 1, "��", BUFF_BG);
//			WriteChar(m_y - 1, m_x + 1, "��", BUFF_BG);
//			//WriteChar(m_y + 1, m_x, TANK_BUFF[0], BUFF_BG);
//		}
//		}
//	}
}