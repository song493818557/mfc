// 6_00_�򵥸�ϰ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>

#include <stdlib.h>

int main()
{
	/*
	1.ָ��
	2.�ṹ��
	3.������
	4.ö���Լ�typedef
	5.�ѿռ�
	*/
	//1.ָ��
	//���� : һ������,�����洢��ַ
	//���� : ���� * ������;
	int * ptr = nullptr;
	//��ֵ : 
	int num = 999;
	ptr = &num;
	//ʹ�ó���: ��������,�����ڴ�,��������
	*ptr = 777;
	printf("%d %d ", num, *ptr);

	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	ptr = arr;
	//arr[5]    <->  ptr[5];	
	//*(arr + 5)<-> *(ptr + 5);
	
	//2.�ṹ��
	struct CLASSROOM
	{
		char * TeacherName2;
		char ClassName[100];
		char TeacherName[100];
		int  StudentCount;
	};
	CLASSROOM classRoom1 ;
	CLASSROOM classRoom2 = {0};
	CLASSROOM classRoom3 = { "������01","����ʦ",19 };

	strcpy_s(classRoom1.ClassName,100,"13��");
	strcpy_s(classRoom1.TeacherName, 100, "����ʦ");
	classRoom1.StudentCount = 35;

	classRoom2 = classRoom3; //ע��,�ѿռ�Ŀ���,ֻ�ǵ�ַ�Ŀ���(����ָ������,ǳ����)

	//3.������
	union NAME
	{
		char ChineseName[20];
		char EnglishName[100];
	};
	NAME yangName1;
	NAME yangName2 = {0};
	strcpy_s(yangName1.ChineseName, 20, "���");
	strcpy_s(yangName1.EnglishName, 100, "haijunyang_SDFGHRTYUFERTYUXCVNDFGHJGHJFGHJFGHJFGHJ");
	printf("%s \n", yangName1.ChineseName);
	printf("%s \n", yangName1.EnglishName);


	//4.ö���Լ�typedef
	enum DIRECTION
	{
		UP  = 0,
		DOWN,
		LEFT,
		RIGHT
	};
	//ö�ٱ���,�������ƴ˱����д洢��ֵ,�Ӷ����ٳ������ĸ���
	DIRECTION direction = LEFT;
	switch (direction)
	{
	case UP:
		printf("�����ƶ� \n");
		break;
	case DOWN:
		printf("�����ƶ� \n");
		break;
	case LEFT:
		printf("�����ƶ� \n");
		break;
	case RIGHT:
		printf("�����ƶ� \n");
		break;
	default:
		break;
	}

	//5.�ѿռ�
	int * pArr = (int *)malloc(sizeof(int)*10);
	if (pArr==nullptr)
	{
		printf("�����ڴ�ʧ�� \n");
		return 0;
	}
	memset(pArr, 0, sizeof(int) * 10);
	memcpy(pArr, arr, sizeof(int) * 10);
	for (int i = 0;i<10;i++)
	{
		printf("%d ", pArr[i]);
	}
	free(pArr);

    return 0;
}

