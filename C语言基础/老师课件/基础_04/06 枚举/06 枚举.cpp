// 06 ö��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//             ��       ��      ��     ��
enum _SEASON{ spring, summer, autumn, winter };

#define PI 3.14

#define ���� 2
#define ���� 5
#define ���� 8
#define ���� 10


//�ŵ�1��ö�ٱ�����ֻ�ܴ洢��ö�����͵����ݣ�������Ч�Ľ��ͳ������
void ChuanYifu(_SEASON nSeason)
{
	//�ŵ�2��ö�پ��������жϣ��ܹ���������Ŀɶ���
	//������޲κ���˵����Ϊ�ļ�㣬��Ϊ������Ҫ���ĳ�����ֵ
	//�����Ƕ���
	switch (nSeason)
	{
	case spring:
		printf("��ë��");
		break;
	case summer:
		printf("������");
		break;
	case autumn:
		printf("��T��");
		break;
	case winter:
		printf("�����޷�");
		break;
	default:
		break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{


	return 0;
}

