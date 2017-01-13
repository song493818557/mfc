#pragma once
#include "stdafx.h"
#include <windows.h>
#include <vector>
#include <time.h>
#include <conio.h>
//************************************ 
// Qualifier:
// Parameter: int y  ��ӡY����
// Parameter: int x  ��ӡX����
// Parameter: char * pszChar  ��ӡ����
// Parameter: WORD wArr  ����ɫ|����ɫ
//************************************
void WriteChar(int y, int x, char *pszChar, WORD wArr);
bool SetWindowSize(CHAR* pszWindowTitle, int nX, int nY);
struct _position{
	int p_direction;
	int p_y;
	int p_x;
	WORD color;
};
class Cganme
{
public:
	Cganme() { };
	//static void draw();//����ͼ Ӧ����ȫ�ֵ�
	/*void map_inInit(){
		FILE * pFile = NULL;
		if (in_map == 2){//�ؿ�һ

			fopen_s(&pFile, "c:\\a\\2.txt", "rb+");
		}
		else if (in_map == 3)//�ؿ���
		{
			fopen_s(&pFile, "c:\\a\\3.txt", "rb+");
		}
		else if (in_map == 4)//�ؿ���
		{
			fopen_s(&pFile, "c:\\a\\4.txt", "rb+");
		}
		fread(
			sysMap00, //д����ʼ��ַ buf2
			4, //һ��Ĵ�С
			20 * 20 * sizeof(int), //д����ٿ�
			pFile);
		fclose(pFile);

		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				now_map[i][j] = sysMap00[i][j];
			}
		}
		//ÿ�γ�ʼ�� ������Ҫɱ��̹��  �Ժ�����Ż� ��̬�Ļ�ɱ��


	}*/
	void DrawMap();//����ͼ
	void ClearMap();//�����ͼ
	static void myhelp(int swnumb);//�Ҳ����
	static void check_help();//����Ҳ�ļ������
	static void Printf_lost_win(int a);//������˻���Ӯ��
	static	int now_map[40][40];
	static bool Canmove(clock_t &nStart, int nSpeed);
	~Cganme(){};
	static int check_helpa;//�Ҳ���Ϣ����ļ��
	static int Max_play ;//��ǰ��Ϸ��������
	static int Goto ;//�ؿ�����ȥ̹�˴�ս
	static int gamelife;//��ǰ������ֵ  
	static int in_map;//��ǰ�ؿ�
};


/****************************************************/
/*	������ɫ����									*/
/****************************************************/

// ������ɫ
#define F_BLUE     FOREGROUND_BLUE      // ����
#define F_H_BLUE   0x0001|0x0008        // ����
#define F_GREEN    0x0002               // ����
#define F_H_GREEN  0x0002|0x0008        // ����
#define F_RED      0x0004               // ���
#define F_H_RED    0x0004|0x0008        // ����
#define F_YELLOW   0x0002|0x0004        // ���

#define F_H_YELLOW 0x0002|0x0004|0x0008 // ����
#define F_PURPLE   0x0001|0x0004        // ����
#define F_H_PURPLE 0x0001|0x0004|0x0008 // ����
#define F_CYAN     0x0002|0x0004        // ����
#define F_H_CYAN   0x0002|0x0004|0x0008 // ����
#define F_WHITE    0x0004|0x0002|0x0001
#define F_H_WHITE  0x0004|0x0002|0x0001|0x0008
#define H_H_H   0|0

// ������ɫ
#define B_BLUE     BACKGROUND_BLUE      // ����
#define B_H_BLUE   0x0010|0x0080        // ����
#define B_GREEN    0x0020               // ����
#define B_H_GREEN  0x0020|0x0080        // ����
#define B_RED      0x0040               // ���
#define B_H_RED    0x0040|0x0080        // ����
#define B_YELLOW   0x0020|0x0040        // ���
#define B_H_YELB_PURPLELOW 0x0020|0x0040|0x0080 // ����
#define B_PURPLE   0x0010|0x0040        // ����
#define B_H_PURPLE 0x0010|0x0040|0x0080 // ����
#define B_CYAN     0x0020|0x0040        // ����
#define B_H_CYAN   0x0020|0x0040|0x0080 // ����
#define B_WHITE    0x0010|0x0020|0x0040
#define B_H_WHITE  0x0010|0x0020|0x0040|0x0080

/****************************************************/
/*	����ͼ�η��Ŷ���								*/
/****************************************************/
#define WALL_NO   0x0  // δ��������,����ӡ,�޵в��ɴ�Խ
#define WALL_NULL 0x1  // �յ�00000001
#define WALL_A1   0x3  // ��   ��ǽ �����ƻ��� 00000022
#define WALL_A2   0x3  // �d  ��ǽ �����ƻ�,�ƻ���̬��
#define WALL_B    0x4  // ��  ��ǽ �����ƻ���
#define WALL_C    0x5  // ��   ���� �����ɴ�Խ���ӵ��ɹ���
#define WALL_D    0x6  // ��   ·��
#define WALL_E    0x7  // �� ^^  ���� ������
#define WALL_F    0x7  // ��  08  ����·�����٣����ô��� 
#define WALL_G    0x9  // ��   ���� �������BUff��
/****************************************************/
/*	����ͼ�η��Ŷ���111111								*/
/****************************************************/
//#define WALL1_A   0x3  // ��   ��ǽ �����ƻ��� 00000022
#define WALL1_A   "��"  //   ��ǽ �����ƻ�,�ƻ���̬��0x3
#define WALL1_AC   F_H_WHITE | B_BLUE  //    ��ǽ������ɫ
#define WALL1_B    "��" // ��  ��ǽ �����ƻ���0x4
#define WALL1_BC   F_H_WHITE | B_BLUE // ��  ��ǽ������ɫ
#define WALL1_C    "��"  // ��   ���� �����ɴ�Խ���ӵ��ɹ���0x5
#define WALL1_CC    F_H_WHITE | B_BLUE // ��   ���� ������ɫ
#define WALL1_D   "��"   // ��   ·��     0x6
#define WALL1_DC   B_H_WHITE   // ��   ·�� ������ɫ
#define WALL1_E    "��"  //  �� ���� ������0x7
#define WALL1_EC    B_H_GREEN  //    ���� ������ɫ
#define WALL1_F    "��"  //  �� ����  0x8 ��ʱû�õ�
#define WALL1_FC    B_H_GREEN  //    ���� ������ɫ
#define FOOD "��"
#define FOOD_COLOR F_H_WHITE|B_H_GREEN
//���ӵ���̹���ƶ���Ľ�����ص�ͼԪ������ȥ
#define TANK_G    B_H_RED//0x10 0x11 0x17 0x18// ��   �ҷ�̹�� �з�̹�� �ҷ��ݵ�̹�� �з��ݵ�̹��    �ӵ������� ���ɴ�Խ 
#define TANK_G1   B_H_BLUE// 0x11   // ��   �ӵ�  �ӵ������� ���ɴ�Խ 



#define MISSILETYPE_1   0x01 // ��  �ڵ�
#define MISSILETYPE_2   0x02 // ��  ��
#define MISSILETYPE_3   0x03 // ��  ���׵�
#define MISSILETYPE_4   0x04 // �� ƶ�ᵯ
#define MISSILETYPE_5   0x05 // ��  ̹��ɱ����ĸ��

/****************************************************/
/*	�������Զ���								    */
/****************************************************/
#define UP    0x0	//����	orientation ����
#define DOWN  0x1	//����
#define LEFT  0x2	//����
#define RIGHT 0x3	//����



//scoreID(���id)
#define PALY_A    0x0  //  
#define PALY_B    0x1  // 
#define NPC       0x2  //  
