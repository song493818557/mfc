#pragma once
#include <WinSock2.h>
#pragma comment(lib,"Ws2_32.lib") 
#include "Cmenu.h"

 
enum MESSAGETYPE
{
	common = 1, // ������Ϣ������ͨ��Ϣ
	reg,		// ע����������Ϣ����Ҫ���ڿͻ��˸�����������
	login,		// ��¼
	file,		// �����ļ�������
	picture,	// ����ͼƬ������
	control		// ����������������ͻ��˷�
};

typedef struct _MESSAGE 
{
	MESSAGETYPE type;		// ��Ϣ����
	DWORD		len;		// ��Ϣ����
	CHAR		buf[MESSAGEBUF];	// ���Ҫ���͵���Ϣ����󳤶�1024���ֽ�
}MESSAGE;
