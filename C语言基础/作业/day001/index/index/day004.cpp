// index.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
//阶乘加统计后面0的个数
int factorial(int numb){
	int temp = 1;
	int ncount = 0;

	for (int i = numb; i > 0;i--)
	{
		temp *= i;
	}
	for (int i = 0; temp >= 9; )
	{
		i = temp % 10;
		if (i == 0)
		{
			ncount++; 
		}
		temp /= 10;
	}
	return ncount;

}
//兔子
int rabbit(){
	int temp = 0;
	int atemp[3] = { 0 }; 
	atemp[0]=1;
	//第一个月的兔子
	//第二个月的兔子
	//第三个月的兔子
	for (int i = 2; i <= 15;i++)
	{		
			atemp[2] += atemp[1];//将第二个月的转移到第三个月  到时候统一生兔子
			atemp[1] = atemp[0];//将上一批刚刚出生的兔子 转移到第二个月  			atemp[2] += atemp[1];
			atemp[0] = atemp[2];//刚刚出生的兔子 等于 第三个月的兔子值 
			printf("%d天:一个月的兔子%d 俩个月的兔子%d 三个月的兔子%d\n",i, atemp[0], atemp[1], atemp[2]);
	}
	temp = atemp[0] + atemp[1] + atemp[2];
	return temp;
}
//编写一个简易的PRINTF函数
void Myprintf(char szFormat[], int nNumb){ 
	char dFromat[] = "%d";
	char fFromat[] = "%f";
	char cFromat[] = "%c";
	if (dFromat[1] == szFormat[1] && dFromat[0] == szFormat[0])
	{
		printf("%d\n",nNumb);
	}
	else if (fFromat[1] == szFormat[1] && fFromat[0] == szFormat[0])
	{
		printf("%f\n", nNumb);
	}
	else if (cFromat[1] == szFormat[1] && cFromat[0] == szFormat[0])
	{
		printf("%c", nNumb);
	}
	return;

}
void deblank(char string[]){
	int temp = 0;
	char gg[100] = { NULL };
	int j = 0;
	for (int i = 0; string[i] != '\0';i++)
	{
		if (string[i] !=  ' ')
		{
			gg[j] = string[i]; 
			j++; 
			}
		
	}
	printf("%s", gg);

}



//统计字符串 不同字符出现的次数
void stringcount(){
	char string[] = "acdefghijkimnlpqrstuvwxyzxadfngemwqowieAZO";
	char Acount[26] = { 0 };
	int temp = 0;
	for (int i = 0; string[i] != '\0';i++)
	{
		if (string[i] > 96 && string[i] < 123) //截取所有的小写字母ASCII码的值
			{
				temp = string[i] - 97;
			}
		else if (string[i] > 64 && string[i] < 91) //截取所有大写字母ASCII码的值
			{
				temp = string[i] - 65;
			}
			Acount[temp]++;			
	}
	for (int i = 0; i < 26;i++)
	{
		char temp = 65 + i;
		printf("字母:%c  %d\n", temp, Acount[i]);
	}
	int i = 0;
}

//阶乘输出0-100的阶乘
int factoriala(int numb){
	//int carry, n, j;
	//int a[40001];
	//int digit;
	//int temp, i;
	//while (scanf("%d", &n) != EOF){
	//	a[0] = 1; digit = 1;
	//	for (i = 2; i <= n; i++)
	//	{
	//		for (carry = 0, j = 1; j <= digit; ++j)
	//		{
	//			temp = a[j - 1] * i + carry;
	//			a[j - 1] = temp % 10;
	//			carry = temp / 10;
	//		}
	//		while (carry)
	//		{
	//			//digit++;
	//			a[++digit - 1] = carry % 10;
	//			carry /= 10;
	//		}
	//	}

	//	for (int k = digit; k >= 1; --k)
	//		printf("%d", a[k - 1]);
	//	printf("\n");
	//	printf("length=%d\n", digit);
	//}
	/************************************************************************/
	/* [3][2][0][2][0][2][0][2][0][2][0][2][0][2][0][2][0][2][0][2][0][2][0]*/
	/* [0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]*/
	/* [0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]*/
	/* [0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]*/
	/* [0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]*/
	/* [0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]*/
	/************************************************************************/
	int atemp[1000] = { 0 };
	//int onetemp[1000] = { 0 };
	//int bb= _countof(atemp);
	//int ncount = 0;
	int tempa = 1;
//	int tempb = 0;
	int carry;
	int j;
	atemp[0] = 1;
	int lenth = 1;//当前数组的长度
	for (int i = 2; i <= numb; i++)//提取要阶乘的值
	{
		for (carry = 0, j = 1; j <= lenth;j++)//提取总的值的每个位数 与 阶乘的值 相乘 carry是保存个位数的?
		{
			tempa = atemp[j - 1] * i + carry;//从最低位开始乘  这个循环能确保阶乘 相除之后的永远是个位
			atemp[j - 1] = tempa % 10;//保存当前下标个位的值
			carry = tempa / 10;//保存当前下标个位以上的值
		}
		while (carry)//当CARRY 大于0 代表当前数组的最大长度不够
		{
			lenth++; //如果当前长度不够的话   
			atemp[lenth - 1] = carry % 10;//余值%10
			carry /= 10; //余值=余值除以10   
		}
	}
	for (int k = lenth; k >= 1;k--)
	{
		printf("%d", atemp[k - 1]);
	}
		printf("\n");
		printf("lenth:%d \n",lenth);
		return lenth;

}

int _tmain3(int argc, _TCHAR* argv[])
{
	int b;
	 // b= factorial(10);
	// b = rabbit();
	 /* Myprintf("%d",55);
	  Myprintf("%f", 55);
	  Myprintf("%c", 78);*/
	//deblank("he llo 15 pb");
	factoriala(99);
	//stringcount();
	 //d
	 return 0;
}

