// 8_02_�滻define.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//define��ʹ��
//1.�޲κ�
//#define WIDTH 10
//#define HITH  10
//#define WIDTH_HITH WIDTH+HITH
//const���滻
const int WIDTH = 10;
const int HITH = 10;
const int WIDTH_HITH = WIDTH + HITH;
//enum���滻
enum DIRECTION
{
	up = 0,
	down,
	left,
	right
};

//2.�вκ�
#define MAX(a,b) (a)>(b)?(a):(b); 
//inline(��������)
inline int max(int a,int b)//1.��Ŀ��������,"��Ŀ����"->"C++"->"����������չ"
{                          //2.��������,�ڲ��������
	                       //3.�Ƿ����Ƶ��
	return (a)>(b) ? (a) : (b);
}
int main()
{
	//�޲�����
	//���ܳ�
	int rect = 2 * WIDTH_HITH;

	DIRECTION dir = left;
	switch (dir)
	{
	case up:
		break;
	case down:
		break;
	case left:
		break;
	case right:
		break;
	default:
		break;
	}

	//�вκ�
	int nNum = MAX(48, 40+50);
	int nNumA = 15;
	int nNumB = 5;
	//int nResult1 = MAX(++nNumA, nNumB);   //��������,������Ԥ��
	//int nResult2 = MAX(++nNumA, nNumB+20);

	int nResult1 = max(++nNumA, nNumB);
	int nResult2 = max(++nNumA, nNumB + 20);

    return 0; 
}

