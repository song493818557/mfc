#pragma once
#include <Windows.h>
#define MAPBG B_H_WHITE|F_H_RED //ȫ�ֵ�ͼ������ɫ����
#define DRAWBG   B_H_WHITE|F_H_RED // ��ͼ�����	
#define MAPPATH   "c:\\a\\c\\"  //��ͼ�����·��
#define MAPNAME   ".txt"
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
#define H_H_H   0|0
/****************************************************/
/*	����ͼ�η��Ŷ���								*/
/****************************************************/
#define WALL_NO   0x0  // δ��������,����ӡ,�޵в��ɴ�Խ
#define WALL_NULL 0x1  // �յ�00000001
#define WALL_A1   0x3  // ��   ��ǽ �����ƻ��� 00000022
#define WALL_A2   0x3  // �d  ��ǽ �����ƻ�,�ƻ���̬��
#define WALL_B    0x4  // ��  ��ǽ �����ƻ���
#define WALL_C    0x5  // ��   ���� �����ɴ�Խ���ӵ��ɹ���
#define WALL_D    "��" ///0x6  // ��   ·��
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
#define WALL1_G    "��"  // ��   ���� �������BUff��
#define WALL1_GC    B_H_YELB_PURPLELOW  //    ���� ������ɫ