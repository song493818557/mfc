#pragma once

#define NUM 100
// #define �鿴���� 1
// #define ����     2
// #define ɾ��     3
// #define �޸�     4
// #define ��ѯ     5

enum OPTION
{
	�鿴���� = 1,
	����,
	ɾ��,
	�޸�,
	��ѯ,
	�����ı�,
	���������,
};

typedef struct _PASSWORD
{
	char website[100];
	char userName[100];
	char passWord[100];
	char note[100];
}PASSWORD, *PPASSWORD;

extern int g_size;