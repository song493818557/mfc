// 8_5.cpp : �������̨Ӧ�ó������ڵ㡣
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
//��ҵ1
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
// �鿴�����ƺ����1
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
//��ҵ2 �žų˷���
void jjxfb(){
	for (int i = 1; i < 10;i++){

		for (int j = 1; j <= i; j++){
			
			printf("%d X %d= %d  ",i,j,i*j);
		}
		printf("\n");
	}
}
//��ҵ3 ������
void csz(){
	//int * time = 0;
	srand((unsigned)time(NULL));
	int n = rand() % (20);
	int jj = 0;
	int iplay = 0;
	for (; 1; jj++){
		
		printf("%5d������һ��20֮�ڵ�����\n",jj);
		scanf_s("%d", &iplay);
		if (iplay == n){
			printf("��ϲ�� �³ɹ���!\n");
			break;

		}
		else{
			if (iplay > n){ printf("�´���\n", iplay); }
			else
			{
				printf("��С��\n", iplay);
			}
		}
		printf("\n");
	}
}
//��ҵ5  ������ʲô��˼
void sushu(){
	//int * time = 0;
	int jj = 0;
	int iplay = 0;
	for (; 1; jj++){

		printf("%5d���������������������\n", jj);
		scanf_s("%d", &iplay);
		if (iplay %iplay == 0 && iplay%1==0){
			printf("����!\n");
			//break;

		}
		else{
			 
				printf("������\n", iplay);
			 
		}
		printf("\n");
	}
}

//��ҵ6  ��ӡ��ַ ��֪����ô��ӡ�������͵ĵ�ַ
void select_address(int b = 0){
	//int 
		scanf_s("%d", &b);
		//printf("%d\n", &int);
		printf("����ռ�õĿռ䣺%d\n", sizeof(b));
		printf("�����ĵ�ַ��%d\n", &b);
	 
}
//��ҵ7
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
//�õ�һ��ȫ�������һ��ȫ�ֱ���
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
	/*��ҵ1
	int innumb = 0;
	scanf_s("%d", &innumb,1);
	jiecheng(innumb);*/
	//�žų˷���
	//jjxfb();
	//������
	//csz();
	//����
	//sushu();
	//��ӡ��ַ
	//select_address(6);
	//��ҵ7
	//keydown();
	//��Сдת��
	/*
	printf("������һ���ַ�\n");
	char aar[100];
	scanf_s("%s", aar,100);
	printf("%s", aar);
	changebigsmall(aar);
	*/
	//��ȡ�ַ�������
/*
	char iit[]="dsjkadsakdsakdsajxjxfdfff";
	int aa = check_long(iit);
	printf("%d", aa);*/

	//FIB�㷨��֤��ѯ
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
 
