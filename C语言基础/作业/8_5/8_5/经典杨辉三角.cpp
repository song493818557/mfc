// 8_5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
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

void jiecheng(int numb){
	int maxa = 1;
	for (int i = numb; i == 0;i--){
		maxa = i * maxa;

	}
	printf("%d", maxa);

}
int _tmain(int argc, _TCHAR* argv[])
{
	//ysj();
	int innumb;
	printf("%d!", innumb);
	jiecheng(innumb);
	system("pause");
	return 0;
}

