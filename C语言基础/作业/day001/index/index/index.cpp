// index.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//day002 -1  比较三个数大小 输出
int getmax(int a, int b, int c){
	int temp;
	a > b ? temp=a : temp=b;
	return temp >c ? printf("%d\n", temp) : printf("%d\n", c);
	
}

//day002 -2 被357整除
void getaliquot(){
	int temp;
	scanf_s("%d", &temp);
	if (temp % 7 == 0 && temp % 3 == 0 && temp % 5 == 0)
	{
		printf("%d能被3 5 7整除\n", temp);
	}
	else if (temp % 7 == 0 && temp % 3 == 0){

		printf("%d能被7 5整除\n", temp);
	}
	else if (temp % 3 == 0 && temp % 5 == 0){

		printf("%d能被3 5整除\n", temp);
	}
	else if (temp % 7 == 0 && temp % 5 == 0){

		printf("%d能被5 7整除\n", temp);
	}
	else if (temp % 7 == 0  ){

		printf("%d能被 7整除\n", temp);
	}
	else if ( temp % 5 == 0){

		printf("%d能被5 整除\n", temp);
	}
	else if (temp % 3 == 0 && temp % 5 == 0){

		printf("%d能被3整除\n", temp);
	}
	else  {
		printf("%d不能被3 5 7整除\n", temp);
	}


}

//day002 - 6 获取能被9整除 余2的数
void get92quot(){
	for (int i = 9; i < 100;i++)
	{
		if (i%9 ==2)
		{
			printf("%d\n",i);
		}
	}

}
//day002 -7 输出0~999之间的所有水仙花数
void getsxh(){
	for (int i = 1; i < 10;i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (i*100 +j*10 +k == (i*i*i)+(j*j*j)+(k*k*k) )
				{
					printf("%d%d%d ", i, j, k);
				}
			}
		}
	}

}
//低四位反转
void changeint(){
	int n = 38;
	int bb = 0;
	for (int i = 0; i < 4;i++)
	{
		bb=(1 << i);
		 n ^= (1 << i);
		printf("bb= %d   n= %d\n", bb,n);
	}
	int b = 0;
	return;
}
//统计有多少个1
void numb1(int a ){
	int countb = 0;
	int counta = 0;
	while (a  > 1)
	{
		a % 2 == 1 ? countb++ : counta++;
		a = a / 2; 
		
	}
	a == 1 ? countb++ : counta++;

	printf("%d", countb);
}
//Helen公式 其中S=(A+B+c)/2; 
//三角形面积 =  s*(s-a)*(s-b)*(s-c)
void Helen(){
	int helennumber[3] = { 0 };
	while (true)
	{
		
		scanf_s("%d %d %d", &helennumber[0], &helennumber[1], &helennumber[2]);
		int a = helennumber[0];
		int b = helennumber[1];
		int c = helennumber[2];
		int s = (a+b+c) / 2;
		int area = s*(s - a)*(s - b)*(s - c);
		if ((a + b > c)&&(a + c > b)&&(c + b > a))
		{
			printf("面积为 %d\n", area);
		}
		else
		{
			printf("不能构成三角形\n");
		}
		if (area > 0 )
		{
			printf("面积为 %d\n", area);
		}
		else
		{
			printf("不能构成三角形\n");
		}


	}
	

}
/*
猴子吃桃问题 猴子第一天摘下若干个桃子 当天即吃了一半 又吃了一个 第二天吃了剩下的桃子的一半 又多吃了一个 直到第十天 只剩下一个桃子了 求第一天猴子摘下了多少个桃子
第一天 X%2+1
第二天 (X%2+1)%2+1
第三天 (X%2+1)%2+1
第四天 ((X%2+1)%2+1)%2+1
第五天 (X%2+1)%2+1
第六天 (X%2+1)%2+1
第七天 (X%2+1)%2+1
第八天 (X%2+1)%2+1
第九天 (X%2+1)%2+1
第10天   1
*/
void monkeyandpeach(){
	int allpeach = 0;
	int day = 10;
	int temp = 1;
	for (int i = day-1; i > 0; i--)
	{
		if (i== 9)
		{
			temp = temp * 2 + 1+1;
			printf("猴子第%d天有%d个桃子\n", i, temp);
			continue;
		}
		temp = temp * 2 + 1;
		printf("猴子第%d天有%d个桃子\n", i, temp);
	}

}
int _tmain(int argc, _TCHAR* argv[])
{

	//getmax(3,7, 4);
	//getaliquot();
	//get92quot();
	//getsxh();	
	//numb1(57);
	//changeint();
	//Helen();

	//monkeyandpeach();
	//int nArray[10] = {};
	//int nOffset = 3;
	//int *p = &nArray[0]; //(a); 初始 *p   =  narray[0]的地址
	//p = nArray;//(b); 将nArray的首地址赋给 p
	//p += nOffset; //(c)在nArray的首地址往后跳3个位置 也就等于nArray[3]的地址
	//p += 3;       //(d)在nArray[3]的地址往后跳3个位置  也就等于nArray[6]的地址
	//*p += 3; //(E)nArray[6]的值+3;
	//int bb = *(p + 3);    //(F)解引用nArray[9]的地址 应该是等于0
 
	return 0;
}

