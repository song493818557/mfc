#include "stdafx.h"
#include "ctrl.h"
#include <stdlib.h>

void searchAllInfo(PASSWORD pwd[], int nCount)
{
	printf("==共计: %3d 条记录===================\n", nCount);
	for (size_t i = 0; i < nCount; i++)
	{
		printf("--ID: %3d----------------------\n", i);
		printf("目  标: %s \n", pwd[i].website);
		printf("用户名: %s \n", pwd[i].userName);
		printf("密  码: %s \n", pwd[i].passWord);
		printf("备  注: %s \n", pwd[i].note);
	}

	printf("\n");
	system("pause");
	system("cls");
}
void insertInfo(PASSWORD pwd[], int * pnCount)
{
	int i = *pnCount;
	if (i < 0 || i >= NUM)
	{
		printf("插入位置异常:%d \n", i);
		return;
	}
	printf("请输入<目标站点>\n");
	scanf_s("%s", pwd[i].website, 100);
	printf("请输入< 用户名 >\n");
	scanf_s("%s", pwd[i].userName, 100);
	printf("请输入<  密码  >\n");
	scanf_s("%s", pwd[i].passWord, 100);
	printf("请输入<备注信息>\n");
	scanf_s("%s", pwd[i].note, 100);

	(*pnCount)++;

	printf("\n");
	system("pause");
	system("cls");
}
void deleteInfo(PASSWORD pwd[], int * pnCount)
{
	int i = -1;
	printf("请输入待删除项<密码ID>\n");
	scanf_s("%d", &i);
	if (i < 0 || i >= NUM)
	{
		printf("删除位置异常:%d \n", i);
		return;
	}

	for (size_t j = i; j < *pnCount - 1; j++)
	{
		pwd[j] = pwd[j + 1];
	}

	(*pnCount)--;

	printf("\n");
	system("pause");
	system("cls");
}
void alterInfo(PASSWORD pwd[], int  nCount)
{
	int i = -1;
	printf("请输入待修改项<密码ID>\n");
	scanf_s("%d", &i);
	if (i < 0 || i >= NUM)
	{
		printf("修改位置异常:%d \n", i);
		return;
	}

	printf("--ID: %3d----------------------\n", i);
	printf("目  标: %s \n", pwd[i].website);
	printf("用户名: %s \n", pwd[i].userName);
	printf("密  码: %s \n", pwd[i].passWord);
	printf("备  注: %s \n", pwd[i].note);
	printf("~修改~\n");
	printf("请输入<目标站点>\n");
	scanf_s("%s", pwd[i].website, 100);
	printf("请输入< 用户名 >\n");
	scanf_s("%s", pwd[i].userName, 100);
	printf("请输入<  密码  >\n");
	scanf_s("%s", pwd[i].passWord, 100);
	printf("请输入<备注信息>\n");
	scanf_s("%s", pwd[i].note, 100);

	printf("\n");
	system("pause");
	system("cls");
}
void searchInfo(PASSWORD pwd[], int  nCount)
{
	char key[100] = { 0 };
	printf("请输入查找密码的关键字:\n");
	scanf_s("%s", key, 100);

	//找出所有匹配项
	int findPwd[100] = { 0 };
	int nfindCount = 0;
	for (size_t i = 0; i < nCount; i++)
	{
		if (strstr(pwd[i].website, key))
		{
			findPwd[nfindCount++] = i;
			continue;
		};
		if (strstr(pwd[i].userName, key))
		{
			findPwd[nfindCount++] = i;
			continue;
		};
		if (strstr(pwd[i].passWord, key))
		{
			findPwd[nfindCount++] = i;
			continue;
		};
		if (strstr(pwd[i].note, key))
		{
			findPwd[nfindCount++] = i;
			continue;
		};
	}

	//打印所有匹配项
	printf("==共计匹配: %3d 条记录===================\n", nfindCount);
	for (size_t i = 0; i < nfindCount; i++)
	{
		int pos = findPwd[i];
		printf("--ID: %3d----------------------\n", pos);
		printf("目  标: %s \n", pwd[pos].website);
		printf("用户名: %s \n", pwd[pos].userName);
		printf("密  码: %s \n", pwd[pos].passWord);
		printf("备  注: %s \n", pwd[pos].note);
	}

	printf("\n");
	system("pause");
	system("cls");
}

void SaveInfoA(PASSWORD pwd[], int nCount)
{
	/*
	读写文件的固定套路
	1. 打开文件
	2. 读写文件
	3. 关闭文件
	*/

	//1. 打开文件
	FILE * pFile;
	errno_t err = fopen_s(&pFile, "data.txt", "w");
	if (err != 0)
	{
		return;
	}
	//2. 读写文件(字符putc/getc,字符串puts/gets,格式化字符串fprintf/fscanf_s)
	fprintf(pFile,"==共计: %3d 条记录===================\n", nCount);
	for (size_t i = 0; i < nCount; i++)
	{
		fprintf(pFile, "--ID: %3d----------------------\n", i);
		fprintf(pFile, "目  标: %s \n", pwd[i].website);
		fprintf(pFile, "用户名: %s \n", pwd[i].userName);
		fprintf(pFile, "密  码: %s \n", pwd[i].passWord);
		fprintf(pFile, "备  注: %s \n", pwd[i].note);
	}

	//3. 关闭文件
	fclose(pFile);

	printf("保存二进制文件成功 \n");
	system("pause");
	system("cls");
}
void SaveInfoB(PASSWORD pwd[], int nCount)
{
	/*
	读写文件的固定套路
	1. 打开文件
	2. 读写文件
	3. 关闭文件
	*/

	//1. 打开文件
	FILE * pFile;
	errno_t err = fopen_s(&pFile, "data.i", "wb");
	if (err != 0)
	{
		return;
	}
	//2. 读写文件(fwrite/fread)
	fwrite(&nCount,sizeof(nCount),1, pFile);  //当前密码个数
	fwrite(&g_size,sizeof(g_size), 1, pFile); //当前密码本容量(个数)
	//先加密,再存储
	int byteSize = sizeof(PASSWORD)*g_size;
	char * buf = (char *)pwd;
	for (size_t i = 0; i < byteSize; i++)
	{
		buf[i] ^= (i+ nCount + g_size);
	}
	size_t rlen = fwrite(pwd, sizeof(PASSWORD), g_size, pFile); //密码数组
	if (rlen != g_size)
	{
		printf("写入密码文件错误 \n");
		fclose(pFile);
		return;
	}

	//3. 关闭文件
	fclose(pFile);

	printf("保存二进制文件成功 \n");
	system("pause");
	system("cls");
}
void readInfo(PPASSWORD * ppPwd, int * pnCount)
{
	/*
	 读写文件的固定套路
	 1. 打开文件
	 2. 读写文件
	 3. 关闭文件
	*/

	//1. 打开文件
	FILE * pFile;
	errno_t err = fopen_s(&pFile,"data.i","rb"); 
	if (err!=0)
	{
		*ppPwd = (PPASSWORD)malloc(sizeof(PASSWORD)*NUM);
		g_size = NUM;
		return;
	}
	//2. 读写文件
	//先读取,再解密
	fread(pnCount, sizeof(int), 1, pFile);    //当前密码个数
	fread(&g_size, sizeof(g_size), 1, pFile); //当前密码本容量(个数)

	*ppPwd = (PPASSWORD)malloc(sizeof(PASSWORD)*g_size);
	size_t rlen = fread(*ppPwd, sizeof(PASSWORD), g_size, pFile); //密码数组
	if (rlen != g_size)
	{
		printf("读取密码文件错误 \n");
		fclose(pFile);
		return;
	}
	int byteSize = sizeof(PASSWORD)*g_size;
	char * buf = (char *)*ppPwd;
	for (size_t i = 0; i < byteSize; i++)
	{
		buf[i] ^= (i + *pnCount + g_size);
	}
	//3. 关闭文件
	fclose(pFile);
}
