#pragma once
#include <Windows.h>
#define MAP_X 40
#define MAP_Y 40
#include <vector>
using std::vector;
enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
typedef struct _POSITION
{
	int nX;  //����X
	int nY;
}POSITION, *LPPOSITION;

typedef struct _NODE
{
	POSITION stcPos; //����
	int nH;          //����Ŀ��������
	int nG;          //�ƶ������
	int nF;          //G+H������ѡ�����ŵ�
	POSITION stcFatherPos;//���ڵ������
}NODE, *PNODE;

class CAStar
{
public:
	CAStar();
	~CAStar();
public:

	void SetInfo(POSITION stcBegin, POSITION stcEnd)
	{
		m_stcBegin = stcBegin;
		m_stcEnd = stcEnd;
	}
	void SetInfo(int nBegin_x, int nBegin_y, int End_x, int End_y)
	{
		m_stcBegin.nX = nBegin_x;
		m_stcBegin.nY = nBegin_y;
		m_stcEnd.nX = End_x;
		m_stcEnd.nY = End_y;
		m_Map[m_stcBegin.nY][m_stcBegin.nX] = 2;
		m_Map[m_stcEnd.nY][m_stcEnd.nX] = 3;
	}
	void SetMap(int Map[][40] = NULL)//int (*p)[40]
	{
		if (Map == NULL)
		{
			for (int x = 0; x < MAP_X; x++)
				for (int y = 0; y < MAP_Y; y++)
				{
					if (x == 0 || x == 39 || y == 0 || y == 39)
					{
						m_Map[y][x] = 1;
					}
				}
			for (size_t y = 5; y < 35; y++)
			{
				m_Map[y][10] = 1;
			}
		}
		else
		{
			//�����ͼ�ķ�ʽ���ɴ���Լ�ʵ����
		}
	}
	void PrintMap()
	{
		for (int x = 0; x < MAP_X; x++)
			for (int y = 0; y < MAP_Y; y++)
			{
				if (m_Map[y][x] == 1)
				{
					WriteChar(x, y, "��");
				}
				else if (m_Map[y][x] == 2)
				{
					WriteChar(x, y, "��");
				}
				else if (m_Map[y][x] == 3)
				{
					WriteChar(x, y, "��");
				}
			}
	}

	void GetPath()
	{
		NODE Firstnode = { m_stcBegin ,CalcH(m_stcBegin,m_stcEnd)};
		Firstnode.nF = Firstnode.nH;
		m_vecOpen.push_back(Firstnode);
		//1 �������뵽Open����
		//2 ��ʼѭ��Ѱ·
		while (m_vecOpen.size() > 0)
		{ 
			int loc = 0;
			int Minf = m_vecOpen[0].nF;		      
			//3 ��Open�����ҳ�F��С�ĵ�
			for (int i = 0; i < m_vecOpen.size(); i++)
			{
				if (Minf >m_vecOpen[i].nF){
					Minf = m_vecOpen[i].nF;
					loc = i;//���浱ǰFORѭ����λ��
				}

			}
			NODE nArray[4] = {
				m_vecOpen[loc],
				m_vecOpen[loc],
				m_vecOpen[loc],
				m_vecOpen[loc]
			};
			//4 ����С�ĵ㣬��������ɢ��4����
			nArray[0].stcPos.nX = m_vecOpen[loc].stcPos.nX - 1;
			nArray[1].stcPos.nX = m_vecOpen[loc].stcPos.nX + 1;
			nArray[2].stcPos.nY = m_vecOpen[loc].stcPos.nY + 1;
			nArray[3].stcPos.nY = m_vecOpen[loc].stcPos.nY - 1;
			//������ǵ�ǰOPEN����������� �� ����ɢ���ĸ���
			m_vecClose.push_back(m_vecOpen[loc]);
			
			//5 ���ĸ����У��������������Ч��
			for (int i = 0; i < 4; i++)
			{
			//  5.1�����Ǳ߽�
				bool nSucess = true;
				if (nArray[i].stcPos.nY == 0 ||
					nArray[i].stcPos.nY == 39 ||
					nArray[i].stcPos.nX == 39 ||
					nArray[i].stcPos.nX == 0 
					){
					nSucess = false;
				}
			//  5.2�������ϰ���
				if (m_Map[nArray[i].stcPos.nY][nArray[i].stcPos.nX] == 3){
					nSucess = false;
				}
			//  5.3�����Ѿ�̽�������Close����
				for (int j = 0; j <m_vecClose.size(); j++)
				{
					if (nArray[i].stcPos.nX == m_vecClose[j].stcPos.nX &&
						nArray[i].stcPos.nY == m_vecClose[j].stcPos.nY
						)
					{
						nSucess = false;
						break;
					}
				}
			//  5.4�����Ѿ���OPEN���� ��̽����
				for (int j = 0; j <m_vecOpen.size(); j++)
				{
					if (nArray[i].stcPos.nX == m_vecOpen[j].stcPos.nX &&
						nArray[i].stcPos.nY == m_vecOpen[j].stcPos.nY
						)
					{
						nSucess = false;
						break;
					}
				}
			//  5.5�ҵ��յ�
				if (m_Map[nArray[i].stcPos.nY][nArray[i].stcPos.nX] == 3){
					POSITION Father = m_vecOpen[loc].stcFatherPos;//����ǰ��ѭ���ĸ��ڵ㱣������
					m_Path.push_back(Father);//���浽�ɹ���·����		
					 //������CLOSE���е��Ǹ�FATHER �ڵ�	
					while (true)
					{ 
					for (int j = 0; j < m_vecClose.size()-1 ; j++)
					{
						if (Father.nY == m_vecClose[j].stcPos.nY &&
							Father.nX == m_vecClose[j].stcPos.nX){
							m_Path.push_back(m_vecClose[j].stcPos); // �ҵ��󱣴�����
							//���Ǹ��ڵ� ������һ��
							Father = m_vecClose[j].stcFatherPos;
							break; 
						}
					}
						//����Ѿ�������� ������ѭ��
						if (Father.nY == m_stcBegin.nY &&
							Father.nX == m_stcBegin.nX){
							return;
						}
					}					
				}
					//6 ����������Ч��ļ���Open����	
				if (nSucess == true)//���û��֮ǰ����Щ����״̬ 
				{ 
					nArray[i].stcFatherPos = m_vecOpen[loc].stcPos;
					nArray[i].nH = CalcH(nArray[i].stcPos,m_stcEnd);//��ȡ��ǰ H path   ��Ŀ�ĵصľ���
					nArray[i].nG = m_vecOpen[loc].nG + 1;//��ȡ��ǰ��G path �ƶ������nG
					nArray[i].nF = nArray[i].nG + nArray[i].nH;
					// x y֮ǰ���Ѿ���ֵ�� ���Բ���Ҫ�ı� ֱ�ӽ������鱣�浽COLSE������
					m_vecOpen.push_back(nArray[i]);
				}
				
			}
			//7 ��ѡ������С���Open�޳���[����Close��]��������
			//7 ��ѡ���ĵ����ɾ�� ��Ϊ�Ѿ��������
			m_vecOpen.erase(m_vecOpen.begin()+loc);
		}
			
}
	void PrintPath()
	{
		for (int i = 0; i < m_Path.size(); i++)
		{
			WriteChar(m_Path[i].nX, m_Path[i].nY, "��");
		}
	}
private:
	void WriteChar(int x, int y, char* szString)
	{
		COORD pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		printf(szString);
	}
	int CalcH(POSITION pos_1, POSITION pos_2)
	{
		return abs(pos_1.nX - pos_2.nX) + abs(pos_1.nY - pos_2.nY);
	}
private:

	vector<NODE> m_vecOpen;    //���ڴ洢��̽��ĵ�
	vector<NODE> m_vecClose;   //���ڴ洢��̽��ĵ�
	int m_Map[MAP_Y][MAP_X];//��ͼ
	POSITION m_stcBegin;
	POSITION m_stcEnd;
	vector<POSITION> m_Path;
};

