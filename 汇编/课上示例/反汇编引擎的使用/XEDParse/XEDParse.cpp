// XEDParse.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//1. ����ͷ�ļ�
#include "XEDParse/XEDParse.h"

#ifdef _WIN64
#pragma comment (lib,"XEDParse/x64/XEDParse_x64.lib")
#else
#pragma comment (lib,"XEDParse/x86/XEDParse_x86.lib")
#endif // _WIN64

void printOpcode(const unsigned char* pOpcode , int nSize)
{
	for(int i = 0; i < nSize ; ++i)
	{
		printf("%02X " , pOpcode[ i ]);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{

	XEDPARSE xed = { 0 };

	
	do 
	{
		printf("��ַ ָ�");

		// ����ָ��ĵ�ַ�ͻ��ָ��
		scanf_s("%x" , &xed.cip);
		gets_s(xed.instr , XEDPARSE_MAXBUFSIZE);

		if(XEDPARSE_OK != XEDParseAssemble(&xed))
		{
			printf("ָ�����%s\n" , xed.error);
			continue;
		}

		printf("%08X : " , xed.cip );
		printOpcode(xed.dest , xed.dest_size);
		printf("\n");

		
	} while(*xed.instr);


	return 0;
}

