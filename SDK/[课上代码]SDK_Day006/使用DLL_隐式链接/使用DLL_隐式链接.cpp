// ʹ��DLL_��ʽ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

// ��ʽ����ʹ��DLL
//����
// 1. ����ͷ�ļ�
//		���û��ͷ�ļ�, ����Ҫ�ֽ���������
// 2. ���뾲̬��
extern"C" int fun();
// ���뾲̬��
#pragma comment(lib,"����DLL.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	// 3. ֱ�ӵ��ú���
	fun();
	return 0;
}

