// 8_5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include <time.h>
#include <errno.h>
#include <string.h>
int g_tmp = 0;
int g_tmpc[100];
void ysj(){
	int achar[10][10];
	
	for (int i = 0; i < 10;i++){
		//printf("1 ");
		int d = 0;
		for (int j = 0; j <= i;j++){
			
			if (j == 0  || j == i){
				achar[i][j] = 1; 
				printf("1 ");
			} else {
				achar[i][j] = achar[i - 1][j] + achar[i - 1][j - 1];
				printf("%d ", achar[i][j]);
				//printf("%d %d ", achar[i - 1][j], achar[i - 1][j-1]);
				
			}
			
			
		}
		//printf("1 ");
		printf("\n");
	 
	}
	int i = 0;
}
//作业1
void jiecheng(int numb){
	 
	int maxa = numb;
	int  ttmp = 1;
	int temp[10] = {1};
	int i = 0;
	for (i = 9; i > 0; i--)
	{
		//printf("%d * %d=%d+", maxa, i, maxa*i);
		if (i == maxa){
			temp[i] = i;
			maxa--;
		}
		else{
			temp[i] = 1;
		}
		
		//printf("%d *%d = %d\n", i, maxa, temp);
		//printf("%d * %d=\n", maxa, i, maxa*i);

	}
	ttmp = temp[0] * temp[1] * temp[2] * temp[3] * temp[4] * temp[5] * temp[6] * temp[7] * temp[8] * temp[9];
	printf("%d\n  ", ttmp);
	int a= 0;
	int aac[10];
	for (int i = 0; ttmp > 1; i++){
		aac[i] = ttmp % 10;
		if (aac[i] == 0){
			a++;			
		}
		ttmp = ttmp / 10;
		
	}
	printf("%d\n  ", a);
	for (int i = 5; i >= 0; i--){
		printf("%d", aac[i]);

	}

}
// 查看二进制后面的1
void jiecheng1(int numb){

	int maxa = numb;
	int  ttmp = 1;
	int temp[10] = { 1 };
	int i = 0;
	for (i = 9; i > 0; i--)
	{
		//printf("%d * %d=%d+", maxa, i, maxa*i);
		if (i == maxa){
			temp[i] = i;
			maxa--;
		}
		else{
			temp[i] = 1;
		}

		//printf("%d *%d = %d\n", i, maxa, temp);
		//printf("%d * %d=\n", maxa, i, maxa*i);

	}
	ttmp = temp[0] * temp[1] * temp[2] * temp[3] * temp[4] * temp[5] * temp[6] * temp[7] * temp[8] * temp[9];
	printf("%d\n  ", ttmp);
	int a = 0;
	int aac[32];
	for (int i = 0; i <= 31; i++){
		aac[i] = ((ttmp >> (31 - i)) & 1);
		a += (aac[i] == 0) ? 0 : 1;

	}
	printf("%d\n  ", a);
	for (int i = 0; i <= 31; i++){
		printf("%d", aac[i]);

	}

}
//作业2 九九乘法表
void jjxfb(){
	for (int i = 1; i < 10;i++){

		for (int j = 1; j <= i; j++){
			
			printf("%d X %d= %d  ",i,j,i*j);
		}
		printf("\n");
	}
}
//作业3 猜数字
void csz(){
	//int * time = 0;
	srand((unsigned)time(NULL));
	int n = rand() % (20);
	int jj = 0;
	int iplay = 0;
	for (; 1; jj++){
		
		printf("%5d请输入一个20之内的数字\n",jj);
		scanf_s("%d", &iplay);
		if (iplay == n){
			printf("恭喜你 猜成功了!\n");
			break;

		}
		else{
			if (iplay > n){ printf("猜大了\n", iplay); }
			else
			{
				printf("猜小了\n", iplay);
			}
		}
		printf("\n");
	}
}
//作业5  不明白什么意思
void sushu(){
	//int * time = 0;
	int jj = 0;
	int iplay = 0;
	for (; 1; jj++){

		printf("%5d请输入可以是素数的数字\n", jj);
		scanf_s("%d", &iplay);
		if (iplay %iplay == 0 && iplay%1==0){
			printf("素数!\n");
			//break;

		}
		else{
			 
				printf("非素数\n", iplay);
			 
		}
		printf("\n");
	}
}

//作业6  打印地址 不知道怎么打印整个整型的地址
void select_address(int b = 0){
	//int 
		scanf_s("%d", &b);
		//printf("%d\n", &int);
		printf("参数占用的空间：%d\n", sizeof(b));
		printf("参数的地址：%d\n", &b);
	 
}
//作业7
void keydown(){

	/* Display message until key is pressed. */
	while (!_kbhit())
	{
		//_cputs("Hit me!! ");

		/* Use _getch to throw key away. */
		printf("\nKey struck was '%c'\n", _getch());
	}

}

void changebigsmall(char bbr[]){
	int numb = strnlen_s(bbr, 100);
	for (int i = numb; i >= 0;i--){
		if (bbr[i] > 96 && bbr[i] < 123){
			bbr[i] -= 32;
		}
		else if(bbr[i] > 64 && bbr[i] < 91){
			bbr[i] += 32;
		}
		else
		{

		}
		
		
	}
	printf("%s", bbr);
	
}

int check_long(char bbr[]){
	int numb = strnlen_s(bbr, 100);
	return numb;
	

}
//用到一个全局数组和一个全局变量
int fib(int numb){ 
	g_tmpc[0] = 1;
	g_tmpc[1] = 1;
	for (int i = 1; i <= numb; i++){
		if (i > 1){
			g_tmpc[i] = g_tmpc[i - 1] + g_tmpc[i - 2];
		}
		if(i == numb){
			g_tmp = g_tmpc[i - 1] + g_tmpc[i - 2];
		}

		//printf("%d,",fibb[i]);
	}
	
	return g_tmp;


}

void jingjingjing(){
	for (int i = 1; i < 7; i++){

		for (int j = 1; j < i; j++){
			printf("#");
		}
		printf("\n");
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	//ysj();
	/*作业1
	int innumb = 0;
	scanf_s("%d", &innumb,1);
	jiecheng(innumb);*/
	//九九乘法表
	//jjxfb();
	//猜数字
	//csz();
	//素数
	//sushu();
	//打印地址
	//select_address(6);
	//作业7
	//keydown();
	//大小写转换
	/*
	printf("请输入一串字符\n");
	char aar[100];
	scanf_s("%s", aar,100);
	printf("%s", aar);
	changebigsmall(aar);
	*/
	//获取字符串长度
/*
	char iit[]="dsjkadsakdsakdsajxjxfdfff";
	int aa = check_long(iit);
	printf("%d", aa);*/

	//FIB算法验证查询
	/*int numba = fib(9);
	int i = 0;
	for (i = 20; i > 0; i--){
		if (g_tmpc[i] >0 && g_tmpc[i] < g_tmp){
		printf("%d,", g_tmpc[i]);
		}
	}*/
	jingjingjing();
	system("pause");
	return 0;
}
 
