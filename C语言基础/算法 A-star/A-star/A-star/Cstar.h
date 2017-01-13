#pragma once
#include <Windows.h>
#include <vector>
using std::vector;
enum{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
typedef struct _position
{
	int nY;
	int nX;
}position;
typedef struct _strstar
{
	position stcpos;//����
	int nH;  //�ƶ������  ���� ��㿪ʼÿ��һ����һ
	int nG;  //��Ŀ�ĵصľ���
	int nF;  //G+H�ĺ�  F��С�������Ϊ�Ǹ�ѡ�ĵ�
	position Fatherpos;//���ڵ�����

}strstar;
class Cstar
{
public:
	Cstar(int sY, int sX, int eY, int eX){
		start.nX = sX;
		start.nY = sY;
		end.nX = eX;
		end.nY=eY;
	};
	~Cstar(){};
public:
	//���õ�ͼ  ��� �յ�
	void Setmap(){
		for (int  y = 0; y < 40; y++)
		{
			for (int x = 0; x < 40;x++){
				if (x == 0 || y == 38 || x == 38 || y == 0  ){
				m_map[y][x] = 1;
				}
				else if (y == start.nY && x == start.nX){
					m_map[y][x] = 2;
				}
				else if (y == end.nY && x == end.nX){
					m_map[y][x] = 3;
				}
				else if (y == 10 && x < 25){
					m_map[y][x] = 1;
				}
				else if (y == 20 && x  > 15){
					m_map[y][x] = 1;
				}
				else{
					m_map[y][x] = 0;
				}
			}

		}

	}
	void Drawmap(){
		for (int y = 0; y < 39; y++)
		{
			for (int x = 0; x < 39; x++){
				if (m_map[y][x] == 1 ){
					WriteChar(y,x,"��");
				}
				else if (m_map[y][x] == 2){
					WriteChar(y, x, "��");
				}
				else if (m_map[y][x] == 3){
					WriteChar(y, x, "��");
				}
				else{
					WriteChar(y, x, "��");
				}
			}

		}

	}
	void Getpath();
	void PrintPath();
private:
	vector<strstar> m_Openlist; //��̽��
	vector<strstar> m_Closelist;//�Ѿ�̽��
	position start;
	position end;
	int m_map[40][40];
	vector<position> m_Path;
	//���㵱ǰλ�õ��յ�ľ���ֵ x
	int CalcH(position pos_1, position pos_2)
	{
		return abs(pos_1.nX - pos_2.nX) + abs(pos_1.nY - pos_2.nY);
	}
	void WriteChar(int x, int y, char* szString)
	{
		COORD pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		printf(szString);
	}
};

