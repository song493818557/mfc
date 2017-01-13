// BeaEngine反汇编引擎使用示例.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


// 添加以下宏
#define BEA_ENGINE_STATIC
#define BEA_USE_STDCALL
// 1. 包含BegEngine的头文件
//	Win32 是32位平台的程序可以使用的头文件
//	Win64 是64位平台的程序可以使用的头文件
#include "BeaEngine_4.1/Win32/headers/BeaEngine.h"

//2. 包含对应版本的静态库
#pragma comment (lib , "BeaEngine_4.1/Win32/Win32/Lib/BeaEngine.lib")

// 防止编译错误。
#pragma comment(linker, "/NODEFAULTLIB:\"crt.lib\"")



// 打印opcode
// const unsigned char* pOpcode ： opcode 的缓冲区首地址
// nSize ： opcdoe的字节数
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
		UIntPtr EIP;	// opcode所在的地址
		UInt64 VirtualAddr; // 保存opcode的缓冲区的首地址
		UInt32 SecurityBlock;
		char CompleteInstr[ INSTRUCT_LENGTH ]; // 转换出来的汇编指令
		UInt32 Archi; // 处理器的架构，可以是32位CPU，或是64位的CPU
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
	

	// 3. 配置结构体，初始化反汇编的opcode
	disAsm.EIP = (UIntPtr)opcode; // 保存opcode的缓冲区首地址
	disAsm.VirtualAddr = 0x401080 ; // opcode 指令的地址
	disAsm.Archi = 0; // 0 => 32 , 1 => 64
	disAsm.Options = 0x000; // masm 汇编指令格式

	int nOpcodeSize = sizeof(opcode); // opcode的字节数
	
	int nCount = 0;// 用于记录在循环当中，反汇编了多少个字节
	int nLen = 0 ; // 用于记录当前的汇编指令的字节数

	// 调用Disasm（）进行反汇编， 

	while(nCount < nOpcodeSize)
	{
		nLen = Disasm(&disAsm); // 每次只反汇编一条汇编指令， 并且返回当前得到的汇编指令的长度
		unsigned int uAddr = disAsm.VirtualAddr;
		
		printf("%08X | " , uAddr); // 打印地址
		printOpcode((const unsigned char*)disAsm.EIP , nLen); // 打印opcode
		printf(" | %s\n" ,  disAsm.CompleteInstr); // 打印反汇编指令


		nCount += nLen; // 累加已经反汇编的字节数
		disAsm.EIP += nLen; // 定位到下一条汇编指令
		disAsm.VirtualAddr += nLen; // 设置到下一条汇编指令的地址
	}





	return 0;
}

