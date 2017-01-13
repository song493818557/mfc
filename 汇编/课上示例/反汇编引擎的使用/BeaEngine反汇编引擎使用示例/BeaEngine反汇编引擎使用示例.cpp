// BeaEngine���������ʹ��ʾ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


// ������º�
#define BEA_ENGINE_STATIC
#define BEA_USE_STDCALL
// 1. ����BegEngine��ͷ�ļ�
//	Win32 ��32λƽ̨�ĳ������ʹ�õ�ͷ�ļ�
//	Win64 ��64λƽ̨�ĳ������ʹ�õ�ͷ�ļ�
#include "BeaEngine_4.1/Win32/headers/BeaEngine.h"

//2. ������Ӧ�汾�ľ�̬��
#pragma comment (lib , "BeaEngine_4.1/Win32/Win32/Lib/BeaEngine.lib")

// ��ֹ�������
#pragma comment(linker, "/NODEFAULTLIB:\"crt.lib\"")



// ��ӡopcode
// const unsigned char* pOpcode �� opcode �Ļ������׵�ַ
// nSize �� opcdoe���ֽ���
void printOpcode(const unsigned char* pOpcode , int nSize)
{
	for(int i = 0; i < nSize ; ++i)
	{
		printf("%02X " , pOpcode[ i ]);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	DISASM disAsm = { 0 };
	/*
	typedef struct _Disasm
	{
		UIntPtr EIP;	// opcode���ڵĵ�ַ
		UInt64 VirtualAddr; // ����opcode�Ļ��������׵�ַ
		UInt32 SecurityBlock;
		char CompleteInstr[ INSTRUCT_LENGTH ]; // ת�������Ļ��ָ��
		UInt32 Archi; // �������ļܹ���������32λCPU������64λ��CPU
		UInt64 Options;
		INSTRTYPE Instruction;
		ARGTYPE Argument1;
		ARGTYPE Argument2;
		ARGTYPE Argument3;
		PREFIXINFO Prefix;
		UInt32 Reserved_[ 40 ];
	} DISASM , *PDISASM , *LPDISASM;
	*/

	unsigned char opcode[] =
	{
		"\x68\xE5\x30\x40\x00\x68\xE2\x30\x40\x00\xFF\x15\x08\x20\x40\x00\x83\xC4\x08\x68\x1A\x30\x40\x00\x68\xE2\x30\x40\x00\xFF\x15\x00\x20\x40\x00\x83\xC4\x08"
	};
	

	// 3. ���ýṹ�壬��ʼ��������opcode
	disAsm.EIP = (UIntPtr)opcode; // ����opcode�Ļ������׵�ַ
	disAsm.VirtualAddr = 0x401080 ; // opcode ָ��ĵ�ַ
	disAsm.Archi = 0; // 0 => 32 , 1 => 64
	disAsm.Options = 0x000; // masm ���ָ���ʽ

	int nOpcodeSize = sizeof(opcode); // opcode���ֽ���
	
	int nCount = 0;// ���ڼ�¼��ѭ�����У�������˶��ٸ��ֽ�
	int nLen = 0 ; // ���ڼ�¼��ǰ�Ļ��ָ����ֽ���

	// ����Disasm�������з���࣬ 

	while(nCount < nOpcodeSize)
	{
		nLen = Disasm(&disAsm); // ÿ��ֻ�����һ�����ָ� ���ҷ��ص�ǰ�õ��Ļ��ָ��ĳ���
		unsigned int uAddr = disAsm.VirtualAddr;
		
		printf("%08X | " , uAddr); // ��ӡ��ַ
		printOpcode((const unsigned char*)disAsm.EIP , nLen); // ��ӡopcode
		printf(" | %s\n" ,  disAsm.CompleteInstr); // ��ӡ�����ָ��


		nCount += nLen; // �ۼ��Ѿ��������ֽ���
		disAsm.EIP += nLen; // ��λ����һ�����ָ��
		disAsm.VirtualAddr += nLen; // ���õ���һ�����ָ��ĵ�ַ
	}





	return 0;
}

