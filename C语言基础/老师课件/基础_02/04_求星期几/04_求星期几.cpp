// 04_求星期几.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int Num = 0;
	scanf_s("%d", &Num);

	switch (Num)
	{
	case 1:
		printf("星期一");
		break;
	case 2:
		printf("星期二");
		break;
	case 3:
		printf("星期三");
		break;
	case 4:
		printf("星期四");
		break;
	case 5:
		printf("星期五");
		break;
	case 6:
		printf("星期六");
		break;
	case 7:
		printf("星期天");
		break;
	default:
		break;
	}


	//if (Num == 1)
	//{
	//	printf("星期一");
	//}
	//else if (Num == 2)
	//{
	//	printf("星期二");
	//}
	//else if (Num == 3)
	//{
	//	printf("星期三");
	//}
	//else if (Num == 4)
	//{
	//	printf("星期四");
	//}
	//else if (Num == 5)
	//{
	//	printf("星期五");
	//}
	//else if (Num == 6)
	//{
	//	printf("星期六");
	//}
	//else if (Num == 7)
	//{
	//	printf("星期日");
	//}

	return 0;
}

