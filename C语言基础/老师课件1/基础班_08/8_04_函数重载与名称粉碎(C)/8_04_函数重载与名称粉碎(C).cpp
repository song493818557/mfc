// 8_04_�������������Ʒ���(C).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//����(���Ʒ�����ʵ��)
//1.��ͬ������
//2.ͬ������
//3.������һ��
int Add(int nNumA, int nNumB) {
	return nNumA + nNumB;
}
int Add(int nNumA, char cChar) {
	return nNumA + cChar;
}
extern "C" int Add(char nNumA, char cChar);

//����ֵ��ͬ���ܹ�������
// char Add(int nNumA, char nNumB) {
// 	return nNumA + nNumB;
// }
int main()
{
	Add(10, 20);
	Add(10, 'a');
	Add('a', 'b');
    return 0;
}

