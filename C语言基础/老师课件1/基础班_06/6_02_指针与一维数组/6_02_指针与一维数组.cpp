// 6_02_指针与一维数组.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo.h>

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };

	int i;
	int* p = arr;
	
	//数组名:数组类型的常量
	//       可以隐式的转换为数组所存储元素类型的指针
	printf("%s \n", typeid(arr).name());
	printf("%s \n", typeid(p).name());
	printf("%s \n", typeid(arr+0).name());
	printf("%s \n", typeid(arr[3]).name());
	printf("%s \n", typeid(&arr[3]).name());
	printf("%s \n", typeid(&arr).name());


	for (i = 0; i < 5; i++)
	{
		printf("a[%d]=%d, *(a+%d)=%d\n", i, arr[i], i, *(arr + i));
		printf("&a[%d]=%p, a+%d=%p\n", i, &arr[i], i, arr + i);
	}
	for (p = arr; p < arr + 5; p++)
	{
		printf("address:%p, value:%d\n", p, *p);
	}

    return 0;
}

