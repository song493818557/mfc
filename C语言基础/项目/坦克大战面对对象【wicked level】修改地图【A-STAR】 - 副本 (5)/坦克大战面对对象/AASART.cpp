#include "stdafx.h"
#include "AASART.h"
 
void Castar::Getpath(int now_map[40][40]){
	//1���������뵽open����  �ṹ���ʼ��  ����ʼ������������յ��λ�ø�ֵ
	STRSTAR First = { sTart, CalcH(sTart, eNd) };
	First.nF = First.nG + First.nH;
	m_Openlist.push_back(First);//��OPEN��װ�����úõĵ�һ����ʼ������ 
	//2����ʼѭ��Ѱ·  ���������յ�ľ���
	while (m_Openlist.size() != 0) //ѭ����û�пɵ���ķ���Ϊֹ
	{
		//3����OPEN�����ҳ�F��С�ĵ�
		int opensieze = m_Openlist.size();//��ȡ��ǰ�����������ж��ٸ�Ԫ��
		int MinF = m_Openlist[0].nF;//��ȡ��һ�δ������С�� F  path
		int MinPos = 0;//X Y�������0
		for (int i = 0; i < opensieze; i++)
		{
			if (MinF> m_Openlist[i].nF){//�����ǰ�����MinF ���ڵ�ǰ��������F PATH  �͸���
				MinF = m_Openlist[i].nF;//���Դﵽ�ҵ���ѵ��Ǹ������
				MinPos = i;	 //���浱ǰԪ�ص����ꣿ��ȷ��				
			}
		}
		//4������С�ĵ���������ɢ���ĸ���
		//4.1 ����ǰ���ǵ�MinPos��ֵ�����ĸ����� ����
		STRSTAR minArray[4] = {
			m_Openlist[MinPos],
			m_Openlist[MinPos],
			m_Openlist[MinPos],
			m_Openlist[MinPos]
		};		//��������4����������ָ�ֵ �ֱ��������������  
	
		minArray[AUP].stcpos.nY = m_Openlist[MinPos].stcpos.nY - 1;
		minArray[AUP].stcpos.nP = 1;
		minArray[ADOWN].stcpos.nY = m_Openlist[MinPos].stcpos.nY + 1;
		minArray[ADOWN].stcpos.nP = 2;
		minArray[ALEFT].stcpos.nX = m_Openlist[MinPos].stcpos.nX - 1;
		minArray[ALEFT].stcpos.nP = 3;
		minArray[ARIGHT].stcpos.nX = m_Openlist[MinPos].stcpos.nX + 1;
		minArray[ARIGHT].stcpos.nP = 4;
		//����ֵ�õ����ݱ��浽CLOSE��  ��Ϊ����Ҫ���м��
		m_Closelist.push_back(m_Openlist[MinPos]);
		//4.2 ��ʼ����
		for (int i = 0; i < 4; i++)
		{
			bool checkstate = true;
			if (minArray[i].stcpos.nX == 0 ||
				minArray[i].stcpos.nX == 39 ||
				minArray[i].stcpos.nY == 0 ||
				minArray[i].stcpos.nY == 39
				)
			{
				checkstate = false;
			}

			 if (m_map[minArray[i].stcpos.nY][minArray[i].stcpos.nX] == 1)
			{ 
				checkstate = false;
			}  

			//5.3  �����Ѿ���COLSE����
			for (int j = 0; j < (m_Closelist.size()); j++)
			{
				if (m_Closelist[j].stcpos.nY == minArray[i].stcpos.nY &&
					m_Closelist[j].stcpos.nX == minArray[i].stcpos.nX){
					checkstate = false;
					break;
				}
			}
			//5.4  �Ѿ���OPEN���� ��̽����
			for (int j = 0; j < m_Openlist.size(); j++)
			{
				if (m_Openlist[j].stcpos.nY == minArray[i].stcpos.nY &&
					m_Openlist[j].stcpos.nX == minArray[i].stcpos.nX){
					checkstate = false;
					break;
				}
			}
			//WriteChar(minArray[i].stcpos.nY, minArray[i].stcpos.nX, "��", 0 | F_H_WHITE);
			//5.5 �ҵ��յ�
			//minArray[i].stcpos.nY == eNd.nY  && minArray[i].stcpos.nX == eNd.nX
			if (abs(minArray[i].stcpos.nY - eNd.nY) < 2 && abs(minArray[i].stcpos.nX - eNd.nX) < 2){

				POSTION Father = m_Openlist[MinPos].Fatherpos;//���浱ǰ�ĸ��ڵ�
				m_Path.push_back(Father);//����ǰ�ĸ��ڵ����걣�浽�ɹ��ı�����ȥ
				while (true)
				{
					for (int i = (m_Closelist.size()) - 1; i >= 0; i--)
					{
						if (Father.nX == m_Closelist[i].stcpos.nX &&
							Father.nY == m_Closelist[i].stcpos.nY)
						{
							m_Path.push_back(Father);//�ҵ��˶�Ӧ������ ���浽�ɹ��ı�����ȥ
							Father = m_Closelist[i].Fatherpos;
							break;
						}

					}
					if (Father.nX == sTart.nX && Father.nY == sTart.nY){
						return;
					}
				}
			}
			if (checkstate == true){
				//6 ����������Ч��ļ���OPEN����
				minArray[i].Fatherpos = m_Openlist[MinPos].stcpos;
				minArray[i].nG = m_Openlist[MinPos].nG + 1;
				minArray[i].nH = CalcH(minArray[i].stcpos, eNd);
				minArray[i].nF = minArray[i].nH + minArray[i].nG;
				m_Openlist.push_back(minArray[i]);
			}
		}
		//7 ��ѡ������С���OPEN�����޳� ���Ҽ���CLOSE ��
		m_Openlist.erase(m_Openlist.begin() + MinPos);

	}

}
void Castar::PrintPath()
{
	
	for (int i = 0; i < (m_Closelist.size()); i++)
	{
		//WriteChar(m_Closelist[i].stcpos.nY, m_Closelist[i].stcpos.nX, "�d", 0 | F_H_RED);
	}
	for (int i = 0; i < m_Path.size(); i++)
	{
		WriteChar(m_Path[i].nY, m_Path[i].nX, "��", MAPBG);
	}
}

//��ȡH��ֵ ������Ŀ�ĵصľ���
int Castar::CalcH(POSTION pos_1, POSTION pos_2)
{
	return abs(pos_1.nX - pos_2.nX) + abs(pos_1.nY - pos_2.nY);
}
void Castar::WriteChara(int x, int y, char* szString)
{
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf(szString);
}
void Castar::Setmap(){
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 40; x++){
			if (x == 0 || y == 39 || x == 39 || y == 0){
				m_map[y][x] = 1;
			}
			else if (now_map[y][x] == 1){

				m_map[y][x] = 0;
			}
			else if (now_map[y][x] > 1 && now_map[y][x] < 7){
				m_map[y][x] = 1;
				m_map[y][x-1] = 1;
				m_map[y][x+1] = 1;
				m_map[y+1][x] = 1;
				m_map[y-1][x] = 1;
			} 
		} 
	}	  
}
void Castar::Drawmap(){
	for (int y = 0; y < 39; y++)
	{
		for (int x = 0; x < 39; x++){
			if (m_map[y][x] == 1){
				WriteChar(y, x, WALL1_D, WALL1_DC);
			} 
			else{
				WriteChar(y, x, "��",MAPBG);
			}
		} 
	} 
}

void Castar::reset(){
	m_Openlist.clear();
	m_Closelist.clear();
	sTart.nX = 0;
	sTart.nY = 0; 
	eNd.nX = 0;
	eNd.nY = 0; 
	m_Path.clear();
}