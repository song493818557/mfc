#include "stdafx.h"
#include "Cmenu.h"

int   in_map = 0;//��ǰ��Ϸ��������						   static
int   Goto = 88;//ȥ��ͼ�༭����ȥ̹�˴�ս						static

Cmenu::Cmenu()
{
	m_menu_x = 17;
	charaa.push_back("��");//0
	charaa.push_back(">> ");//1
	charaa.push_back("����Ա,��ӭ����");//2
	charaa.push_back("��  ע���˺�");//3
	charaa.push_back("��  ��¼�˺�");//4
	charaa.push_back("��  ʵʱȺ��");//5
	charaa.push_back("��  �����б�");//6
	charaa.push_back("��  �˳�");//7
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



/*
���ܣ��˵���������
int a =m_menu_state  ��ͬ״̬��ͬ����ʽ
*/
DWORD WINAPI Cmenu::main_menu(_In_ LPVOID lpParameter){
	//Goto = 77; in_map = 1;  Max_play = 1;  return;
	system("cls");
	system("color 0f");
	m_menu_state = (int)lpParameter;
	switch (m_menu_state)
	{
	case 88:  Goto = 88; in_map = 2;  return 0;//̹�˴�ս Ĭ�ϵ�һ�ؿ���ͼ
	case 77: Goto = 77;  return 0;//��ͼ ��in_map ����ж����Ǹ���ͼ
	}
	m_menu_y = 7;
	main_draw();
	switch (m_menu_state)
	{
		move_a(true);
	case 1:{
		//���˵�
		m_max_y = 19;
		show_menu(3, 8, 0);
	}break;
	case 2:{
		//������� ѡ��  Max_play ����	
		m_max_y = 13;
		show_menu(8, 10, 0);
	}break;
	case 3:{
		//��Ϸ����
		m_max_y = 15;
		show_menu(10, 15, 0);
	}break;
	case 4:{
		//ѡ��༭�ĵ�ͼ	
		m_max_y = 15;
		show_menu(15, 18, 0);
	}break;
	}
	m_menu_y = 11;//���ù��λ��
	m_min_y = 11;
	menu_choose();

}
/*
���ܣ����̿�������
*/
void Cmenu::menu_choose(){
	if (m_select == 0){
		while (m_select == 0)
		{
			if (_kbhit()) {
				unsigned	char ch = _getch(); 
				if (ch == 0xe0)
				{
					char ch1 = _getch();
					ch = ch1;
				}
				switch (ch)
				{
				case 'w':case 'W':case 'H':
				{
					move_a(true);
					// ����̹��
				}break;
				case 's':case 'S':case 'P':
				{
					move_a(false);
				}break;
				case 'a':case 'A':case 'K':
				{
					if (m_menu_state == 3){

						//						switch (m_menu_y)
						//						{
						//						case 11://��ǰҳ���һ��   ��ʼ��Ϸ  ̹�˴�ս
						////menu_Pnumb(max_kill, -1); break;
						//						case 13:
						//							//menu_Pnumb(Tank_life, -1); break;
						//						case 15:
						//						//	menu_Pnumb(Max_Rebottank, -1); break;
						//							 
						//						}
					}
				}break;
				case 'd':case 'D':case 'M':
				{
					if (m_menu_state == 3){

						//switch (m_menu_y)
						//{
						//case 11:// 
						////	menu_Pnumb(max_kill, 1); break;
						//case 13:
						////	menu_Pnumb(Tank_life, 1); break;
						//case 15:
						////	menu_Pnumb(Max_Rebottank, 1); break;

						//}
					}
				}break;
				case 0x71:case  0x51:  case '\x1b': main_menu((LPVOID)1); break;
					//ȷ��ѡ�� ��ʼ�����ж���ʲô���ܵĲ��� ��Y����
				case '\r':
				{
					if (m_menu_state == 1){
						m_select = 1;
						switch (m_menu_y)
						{
						case 11://��ǰҳ���һ��   ��ʼ��Ϸ  ̹�˴�ս
							main_menu((LPVOID)2); break;
						case 13:
							main_menu((LPVOID)3); break;//��Ϸ����
						case 15:
							main_menu((LPVOID)4); break;//���Ƶ�ͼ77
						case 17:
							main_menu((LPVOID)5); break;//��Ϸ����
						case 19:
							main_menu((LPVOID)6); break;//�˳���Ϸ						
						}

					}
					if (m_menu_state == 2){
						m_select = 1;
						//switch (m_menu_y)
						//{
						//case 11://���һ   
						//	//Max_play = 1;  break;
						//case 13:////��Ҷ�
						//	//Max_play = 2; break;//��Ϸ����
						//}
						main_menu((LPVOID)88);//����̹�˴�ս
					}
					if (m_menu_state == 3){
						main_menu((LPVOID)1);
					}
					if (m_menu_state == 4){//ѡ��
						m_select = 1;
						switch (m_menu_y)
						{
						case 11://��ͼһ   
							in_map = 2; break;
						case 13:////��ͼ��
							in_map = 3; break;
						case 15:////��ͼ��
							in_map = 4;  break;
						}
						main_menu((LPVOID)77);//�����Ӧ�ĵ�ͼ��ͼ
					}
					// ��Ϸ�˳�
				}break;
				system("cls");
				}

			}
		}
	}
}
/*
���ܣ� ������ת���ַ��� ���������
*/
void Cmenu::menu_Pnumb(int &name, int numb){

	name = name + numb;
	char ch[10] = {};
	_itoa_s(name, ch, 10);
	WriteChar(m_menu_y, m_menu_x + 8, ch, F_H_CYAN | F_H_CYAN);
}
/*
���ܣ� ������
*/
void Cmenu::move_a(bool trrue){
	if (trrue) {
		m_menu_y -= 2;
		if (m_menu_y <= m_max_y && m_menu_y >= m_min_y){
			WriteChar(m_menu_y + 2, m_menu_x - 2, "   ", F_H_CYAN | F_H_CYAN);
		}
		else
		{
			m_menu_y += 2;
			return;
		}
	}
	else {
		m_menu_y += 2;
		if (m_menu_y <= m_max_y && m_menu_y >= m_min_y){
			WriteChar(m_menu_y - 2, m_menu_x - 2, "   ", F_H_CYAN | F_H_CYAN);
		}
		else
		{
			m_menu_y -= 2;
			return;
		}
	}
	WriteChar(m_menu_y, m_menu_x - 2, charaa[1], F_H_CYAN | F_H_CYAN);
}
/*
���ܣ�
������Ŀ��
*/
void Cmenu::main_draw(){
	for (int i = 5; i < 25; i++){// ��
		for (int j = 10; j < 30; j++)//��
		{
			if (j == 10 || j == 29 || i == 5 || i == 24){

				WriteChar(i, j, WALL1_D, WALL1_DC);
			}
			else
			{
				WriteChar(i, j, "  ", 0);
			}
		}
	}
	WriteChar(m_menu_y, m_menu_x, charaa[2], F_H_CYAN);
}
/*
���ܣ�ѭ����ʾ�˵� charaa    NOW �����￪ʼ MAX ���������
*/
void Cmenu::show_menu(int now, int max, int select){
	m_select = select;
	int temp = m_menu_y + 2;
	for (int i = now; i < max; i++)
	{
		m_menu_y += 2;
		if (i == now) { move_a(false); }
		WriteChar(m_menu_y, m_menu_x, charaa[i], F_H_CYAN | F_H_CYAN);
	}
}
