// 8-8.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <memory.h>

struct _bookinfo
{
	char book_name[100];
	char author_name[20];
	double book_price;
}; _bookinfo  oneinfo{ "�������������ɵ�", "����", 44.50 };
bool initBook(_bookinfo, unsigned int nCount);
bool FreeAllRecource(_bookinfo, unsigned int nCount);
int _tmain(int argc, _TCHAR* argv[])
{
	int inumb[20][20] = { 1 };



	for (int i = 0; i < 15; i++){

		for (int j = 0; j < i - 1; j++){
			if (i > 2){
				inumb[i][j] = inumb[i - 1][j] + inumb[i - 1][j - 1];

				printf("%4d ", inumb[i][j]);

			}
			else
			{
				inumb[i][j] = 1;

				printf("%d ", inumb[i][j]);
			}
		}if (i > 1){
			printf("\n");
		}
	}

	return 0;
}

