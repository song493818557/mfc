// 03_����ͬ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int tu;
	for (int ji = 0; ji < 40; ji++)
	{
		for (tu = 0; tu < 40; tu++)
		{
			if (ji+tu==40&&ji*2+tu*4 == 110)
			{
				printf("���У�%d �����У�%d", ji, tu);
				break;
			}
		}
		if (tu!=40)
		{
			break;
		}
	}
	return 0;
}

