// 8_05_����������Ĭ��ֵ(C++).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
int Add(int nNumA)
{
	return nNumA ;
}
int Add(int nNumA, int nNumB = 1)
{
	return nNumA + nNumB;
}
//�����ҵ����˳���Ĭ�ϲ���
// int Add(int nNumA = 1, int nNumB , int nNumC = 1)
// {
// 	return nNumA + nNumB;
// }
int main()
{
	//Add(1);   //����������,��������֪��������һ������
	Add(1,2);
	return 0;
}

