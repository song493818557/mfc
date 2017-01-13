// 8-6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
void box(int array[40][40]){
	int temp = 0;
	for (int i = 0; i <= 40; i++){

		for (int j = 0; j <= 40; j++){
			if (i==0||i==40||j==0||j==40){
				array[i][j] = 1;
			}
			if (array[i][j] == 1){
				printf("■");
			}
			else{
				printf("  ");
			
			}
			
			/*
			array[i] = array[i] + array[n - i];
			array[n - i] = array[i] - array[n - i];
			array[i] = array[i] - array[n - i];*/
		}
		printf("\n");
	}
	int aac = 0;
	return;
}
int _tmain(int argc, _TCHAR* argv[])
{
	
	int arc[40][40] = { 0};
	int lenth_a = 6;
	int height_a = 6;
	box(arc);
	 
	
	
	return 0;
}

