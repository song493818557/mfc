#pragma once 
#include "Cmysql.h"
#include "Cbase64.h"
using std::vector;
using std::cin;
class Csocket
{
public:
	Csocket();
	Csocket(SOCKET sock, sockaddr_in addr);
	~Csocket();
	//�����߳� ר�����ڽ��ܿͻ�����Ϣ
	bool RecvSocket();
	//������Ϣ���߳�
	static DWORD WINAPI recvThread(_In_ LPVOID lpParameter); //��һ��ָ��
	//ɾ��sock
	 void DeleteSock();
	//֪ͨ����
	 void Leave();
	//������Ϣ,����֪ͨ�����ͻ��˵�������,�ų�sock
	 void SendSockMessage(MESSAGE &message,SOCKET sock = INVALID_SOCKET);
	//�ַ���Ϣ
	 int MyDispatchMessage(MESSAGE &message);
	 //reg 2
	 int Createnewuser(MESSAGE &message);
	 //login 3
	 int userlogin(MESSAGE &message);
	 //anonymous 4
	 void anonymous(string name = "123");
	 //�����û�
	 void searchuser(MESSAGE &message);
	 //��Ӻ���
	 void Addfriend(MESSAGE &message);

	 //1V1˽��
	 void Vchat(MESSAGE &message);
	 //��ѯ���������û�
	  void Alluser(MESSAGE &message);
	 static string Allsuser();
	 //�Զ���CMD����
	 static void Acmd();
	 //�Զ���SQL��ѯ
	 static void Defsql(string sql);
	 //ת���ļ�
	 void pushfile(MESSAGE &message);
	
public: 
	SOCKET m_sock;//SOCKET ������Ϣ
	Cbase64 base;//
	sockaddr_in m_addr;
	char m_name[NAMELENGTH];//�û��ǳ�?
	static Cmysql *db;
	static vector<Csocket*> vecClientSock;//������еĿͻ���������Ϣ
};

