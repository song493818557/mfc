#pragma once
#include "stdafx.h"
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
#define WALL_A1   0x2  // ��   ��ǽ �����ƻ��� 00000022
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
extern int sysMap00[40][40];	//�û��Զ���߼ʵ�ͼʱ,�ṩ��һ��ģ��
//
//extern int sysMap01[40][40] = {
//	WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, WALL_B, WALL_B, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, 1, 1, WALL_B, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, WALL_A2, WALL_A2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, WALL_A2, WALL_A2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, WALL_A1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, WALL_D, 1, 1, 1, WALL_D, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, WALL_A1, WALL_A1, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_A1, WALL_A1, WALL_A1, 1, 1, WALL_A1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D
//
//};
//
int sysMap00[40][40] = {
	WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, WALL_B, WALL_B, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, 1, 1, WALL_B, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, WALL_A2, WALL_A2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, WALL_A2, WALL_A2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, WALL_A1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, WALL_D, 1, 1, 1, WALL_D, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, WALL_A1, WALL_A1, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_A1, WALL_A1, WALL_A1, 1, 1, WALL_A1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, WALL_D, WALL_D, WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, 1, 1, WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, 1, 1, WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D

};
struct _tankball{
	bool isBullet;
	int b_type;//�����ӵ�
	//int t_demo[4][3][3];//̹��ģ�;ŷ���  �ĸ�ģ��
	int b_position;//�����ӵ��ķ���
	int b_x;//��Ҳ�����̹���ƶ�x����
	int b_y;//��Ҳ�����̹���ƶ�y����
	char t_ball[2];//�ӵ���
	//int t_move[100][100];//�ƶ�����

	//int t_npc_stank;//С̹��
	//int t_npc_jtank;//��Ӣ̹��
	//int t_npc_btank;//BOSS̹��

}; _tankball myball[256] = { 0 };

typedef struct _WALL
{
	int nType : 4;
	int nXue  : 4;

	int nBaoliu : 24;
}WALL;

int g_nMap[40][40] = { 0 };//ȫ�������ʼ��

char g_game_menu[11][70] = {
	"			��������������������������������������������������",
	"			��                                              ��",
	"			��                                              ��",
	"			��              ̹�˴�ս Max ^_^                ��",
	"			��              ��  ��ʼ��Ϸ	                ��",
	"			��              ��  ��Ϸ����	                ��",
	"			��              ��  ���Ƶ�ͼ	                ��",
	"			��              ��  ��Ϸ����	                ��",
	"			��                                              ��",
	"			��                                              ��",
	"			��������������������������������������������������" };
char start_menu[11][70] = {
	"			��������������������������������������������������",
	"			��                                              ��",
	"			��                                              ��",
	"			��              ̹�˴�ս Max ^_^                ��",
	"			��              ��  Player  	                ��",
	"			��              ��  Player  	                ��",
	"			��                                              ��",
	"			��                                              ��",
	"			��                                              ��",
	"			��                                              ��",
	"			��������������������������������������������������" };