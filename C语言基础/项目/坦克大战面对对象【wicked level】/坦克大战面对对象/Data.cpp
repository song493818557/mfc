#include "stdafx.h"
#include "Data.h"

/***
����һ�����X��
���������߶�Y��
����������ӡ���ַ�
�����ģ���ӡ�ַ�������
***/
//ȫ�ֵ�ͼ
int sysMap00[40][40] = {
	WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, WALL_B, WALL_B, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_B, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, WALL_A2, WALL_A2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, WALL_A2, WALL_A2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, 1, 1, 1, WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_F, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_F, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_F, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_F, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_F, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, WALL_E, WALL_E, WALL_E, WALL_E, 1, 1, 1, WALL_D, WALL_D, WALL_D, WALL_D, 1, 1, 1, 1, 1, 1, 1, WALL_F, WALL_F, WALL_F, WALL_F, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_F, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, WALL_E, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_F, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, WALL_E, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_E, WALL_E, WALL_E, WALL_E, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, WALL_D, WALL_D, WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, 1, 1, WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, 1, 1, WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D

};
