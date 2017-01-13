// 03_鸡兔同笼.cpp : 定义控制台应用程序的入口点。
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
				printf("鸡有：%d 兔子有：%d", ji, tu);
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

