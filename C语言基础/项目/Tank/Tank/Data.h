#pragma once

/****************************************************/
/*	������											*/
/****************************************************/
#define CHAR_TO_WCHAR(lpChar, lpW_Char)\
	MultiByteToWideChar(CP_ACP, NULL, lpChar, -1, lpW_Char, _countof(lpW_Char)); //char*ת��Ϊwchar_t*
#define KEY_DOWN(key) GetAsyncKeyState(key)&0x8000  ?1:0					     //���̼��



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

// ������ɫ
#define B_BLUE     BACKGROUND_BLUE      // ����
#define B_H_BLUE   0x0010|0x0080        // ����
#define B_GREEN    0x0020               // ����
#define B_H_GREEN  0x0020|0x0080        // ����
#define B_RED      0x0040               // ���
#define B_H_RED    0x0040|0x0080        // ����
#define B_YELLOW   0x0020|0x0040        // ���
#define B_H_YELLOW 0x0020|0x0040|0x0080 // ����
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
#define WALL_NULL 0x1  // �յ�
#define WALL_A1   0x2  // ��   ��ǽ �����ƻ���
#define WALL_A2   0x3  // �d  ��ǽ �����ƻ�,�ƻ���̬��
#define WALL_B    0x4  // ��  ��ǽ �����ƻ���
#define WALL_C    0x5  // ��   ���� �����ɴ�Խ���ӵ��ɹ���
#define WALL_D    0x6  // ��   ·��
#define WALL_E    0x7  // ��   ���� ������
#define WALL_F    0x8  // ��  ����·�����٣�
#define WALL_G    0x9  // ��   ���� �������BUff��

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

/****************************************************/
/*	ȫ�ֱ�������								    */
/****************************************************/
//extern int sysMap01[40][40];	//��Ϸ���õ�һ�ŵ�ͼ
//extern int sysMap00[40][40];	//�û��Զ���߼ʵ�ͼʱ,�ṩ��һ��ģ��