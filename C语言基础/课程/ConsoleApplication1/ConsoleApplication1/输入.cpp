#include<stdio.h>
#include<stdlib.h>
int main(void){

	int a = 100;
	int  b = 3;
	//scanf_s("%d", &a);
	printf("������1������");
	a = getchar();
	fflush(stdin);
	putchar(a);
	printf("��������1������");
	b = getchar();
	printf("a+b=%c  a=%c b = %c", a+b,a,b);
	system("pause");
	return 0;
}