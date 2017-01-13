#pragma once
#include <windows.h>

#define MESSAGEBUF 1024
enum MESSAGETYPE
{
	common = 1, // ������Ϣ������ͨ��Ϣ
	reg,		// ע����������Ϣ����Ҫ���ڿͻ��˸�����������
	login,		// ��¼
	file,		// �����ļ�������
	picture,	// ����ͼƬ������
	control,	// ����������������ͻ��˷�
	Anonymous
};

typedef struct _MESSAGE 
{
	MESSAGETYPE type;	// ��Ϣ����
	DWORD		len;	// ��Ϣ����
	union 
	{
		CHAR	buf[MESSAGEBUF];// ƽʱ������Ϣ�����
		struct
		{
			DWORD nameLen;		// �������ȣ���Ϊ�ͻ��˷�����name��password��һ��ġ�����
			CHAR name[50];		// ע���¼�����
			CHAR password[50];
		}reginfo;
	}info;
}MESSAGE;
