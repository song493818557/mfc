// 02 堆空间示例.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdlib.h>
int _tmain(int argc, _TCHAR* argv[])  {
	int *pResults, nNum;
	int a;
	scanf_s("%d", &nNum);
	if (!(pResults = (int*)malloc(nNum*sizeof(int))))
		return 0;
	for (int i = 0; i<nNum; i++)
		scanf_s("%d", pResults + i);
	    //scanf_s("%d", &pResults[i]);这两种方式是一样的。

	for (int i = 0; i<nNum; i++)
		printf("%5d", pResults[i]);
	free(pResults);//别忘记，最后释放它
	system("pause");
	return 0;
}
