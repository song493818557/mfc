// 6_05_�ļ���д.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>

//1.���ַ���д
void testChar()
{
	//1.д���ݵ��ļ�
	FILE *fpFile;

	char szFileName[30] = {"D:\\hello.txt"};
	int  nPutChar;
// 	printf("Please enter a new file name:");
// 	scanf_s("%s", szFileName, _countof(szFileName));
	errno_t err = fopen_s(&fpFile, szFileName, "w+");
	if (err != 0) { return ; }

	while ('*' != (nPutChar = getchar()))
		fputc(nPutChar, fpFile);
	fclose(fpFile);

	//2.���ļ�������
	char cChar;
	fopen_s(&fpFile, szFileName, "r");
	while (EOF != (cChar = fgetc(fpFile)))
		putchar(cChar);
	fclose(fpFile);
}
//2.���ַ�����д
void testString()
{
	FILE *fpFile_in, *fpFile_out;
	char szStr[50];
	fopen_s(&fpFile_in,"D:\\hello.txt", "r");
	fopen_s(&fpFile_out,"D:\\world.txt", "w"); //fpFile_out = fopen("D:\\world.txt", "w");
	
	while (!feof(fpFile_in)) {
		fgets(szStr, 30, fpFile_in);
		fputs(szStr, fpFile_out);
	}
	fclose(fpFile_in);
	fclose(fpFile_out);

}
//3.����ʽ�ַ�����д
void testFormatStr()
{
	FILE *fpFile;
	int  nNum, nScore;
	char szName[20];
	fpFile = fopen("d:\\1.txt", "w");
	for (int i = 1; i <= 3; i++) {
		scanf_s("%s%10ld%d", szName, &nNum, &nScore);
		fprintf(fpFile, "%20s%10ld%5d\n", szName, nNum, nScore);
	}
	fclose(fpFile);
	fpFile = fopen("d:\\1.txt", "r");
	for (int i = 1; i <= 3; i++) {
		fscanf(fpFile, "%20s%10ld%5d\n", szName, &nNum, &nScore);
		printf("%20s%10ld%5d\n", szName, nNum, nScore);
	}
	fclose(fpFile);

}
//4.���ڴ���д
void testMen()
{
	struct _STUDENT {
		char szClass[6];
		char szName[10];
		int  nScore;
	}stcData[3] = { 0 }, stcStu = { 0 };
	FILE *fpFile = fopen("d:\\stu2", "wb+");
	for (int i = 0; i < 3; i++) {
		printf("\n\t������༶:");
		scanf("%s", stcData[i].szClass);
		// ......
	}
	if (fwrite(stcData, sizeof(stcStu), 3, fpFile) != 3) {
		printf("�ļ�����д������.\n");
		fclose(fpFile); exit(1);
	}
	fclose(fpFile);
	fpFile = fopen("d:\\stu2", "rb");
	
	for (int i = 0; i < 3; i++) {
		if (fread(&stcStu, sizeof(_STUDENT), 1, fpFile) == 1)
			printf("\t%6s%9s%5d\n", stcStu.szClass);
		else {
			printf("�ļ����ܶ�ȡ����.\n");
			fclose(fpFile); exit(1);
		}
	}
	fclose(fpFile);

}
int main()
{
	//testChar();
	testString();
	testFormatStr();
	testMen();

	//�����ļ�����
	//feof(fpFile);   //�Ƿ񵽴��ļ���β
	//rewind(fpFile); //�ļ�ָ������Ϊ��ʼ

	//fseek(fpFile, 0x123, SEEK_SET);//�ļ�ָ��ָ������λ��
	//ftell(fpFile);  //�ļ�ָ�뵱ǰ������
    return 0;
}

