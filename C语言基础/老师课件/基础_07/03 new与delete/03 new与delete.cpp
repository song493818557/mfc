// 03 new��delete.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int* p1 = (int *)malloc(sizeof(int) * 15);//ԭ���ķ�ʽ
	//malloc��һ������

	int* p2 = new int[15];//�µķ�ʽ
	int* p3 = new int(15);//Ҳ����������ֻ������һ��int��
	
	//new ��һ�������

	free(p1);//ԭ���ķ�ʽ

	delete  []p2;//�����������ռ�Ļ�����Ҫ����[]
	delete  p3;//ֻ������һ�����ͷŵ�ʱ��Ͳ��ü�[]


		
	return 0;
}

