// Keystone��������ʹ��ʾ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//1. ����ͷ�ļ�
#include "keystone/keystone.h"

//2. ������̬��
#pragma comment (lib,"keystone/x86/keystone_x86.lib")


// ��ӡopcode
void printOpcode(const unsigned char* pOpcode , int nSize)
{
	for(int i = 0; i < nSize ; ++i)
	{
		printf("%02X " , pOpcode[ i ]);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	ks_engine *pengine = NULL;
	if(KS_ERR_OK != ks_open(KS_ARCH_X86 , KS_MODE_32 , &pengine))
	{
		printf("����������ʼ��ʧ��\n");
			return 0;
	}

	unsigned char* opcode = NULL; // ���õ���opcode�Ļ������׵�ַ
	unsigned int nOpcodeSize = 0; // ��������opcode���ֽ���
	
	// ���ָ��
	// ����ʹ�÷ֺţ����߻��з���ָ��ָ���
	char asmCode[] =
	{
		"mov eax,edx;mov eax,1;mov dword ptr ds:[eax],20"
	};

	int nRet = 0; // ���溯���ķ���ֵ�������жϺ����Ƿ�ִ�гɹ�
	size_t stat_count = 0; // ����ɹ�����ָ�������

	nRet = ks_asm(pengine , /* �����������ͨ��ks_open�����õ�*/
				  asmCode , /*Ҫת���Ļ��ָ��*/
				  0x401000 , /*���ָ�����ڵĵ�ַ*/
				  &opcode ,/*�����opcode*/
				  &nOpcodeSize ,/*�����opcode���ֽ���*/
				  &stat_count /*����ɹ�����ָ�������*/
				  );

	// ����ֵ����-1ʱ��������
	if(nRet == -1)
	{
		// ���������Ϣ
		// ks_errno ��ô�����
		// ks_strerror ��������ת�����ַ���������������ַ���
		printf("������Ϣ��%s\n",ks_strerror(ks_errno(pengine)));
		return 0;
	}

	printf("һ��ת����%d��ָ��\n" , stat_count);

	// ��ӡ��������opcode
	printOpcode(opcode , nOpcodeSize);

	// �ͷſռ�
	ks_free(opcode);
	// �رվ��
	ks_close(pengine);


	return 0;
}

