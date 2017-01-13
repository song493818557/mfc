// 06 枚举.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//             春       夏      秋     冬
enum _SEASON{ spring, summer, autumn, winter };

#define PI 3.14

#define 春天 2
#define 夏天 5
#define 秋天 8
#define 冬天 10


//优点1：枚举变量，只能存储本枚举类型的数据，可以有效的降低出错概率
void ChuanYifu(_SEASON nSeason)
{
	//优点2：枚举经常用于判断，能够提升程序的可读性
	//相对于无参宏来说，更为的简便，因为并不需要关心常量的值
	//具体是多少
	switch (nSeason)
	{
	case spring:
		printf("穿毛衣");
		break;
	case summer:
		printf("穿短袖");
		break;
	case autumn:
		printf("穿T恤");
		break;
	case winter:
		printf("穿羽绒服");
		break;
	default:
		break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{


	return 0;
}

