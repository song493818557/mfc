#include<stdio.h>
#include<stdlib.h>
int main(void){

	int a = 100;
	int  b = 3;
	//scanf_s("%d", &a);
	printf("请输入1个数字");
	a = getchar();
	fflush(stdin);
	putchar(a);
	printf("请再输入1个数字");
	b = getchar();
	printf("a+b=%c  a=%c b = %c", a+b,a,b);
	system("pause");
	return 0;
}