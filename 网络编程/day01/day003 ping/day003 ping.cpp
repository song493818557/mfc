// day003 ping.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "data.h"
//����ICMPЭ��
void sendtoEchorequest(SOCKET sock, sockaddr_in dstIP){
	static int id = 1;
	static int seq = 1;

	//����icmpЭ��ͷ
	ECHOREQUEST echorequest = { 0 };
	echorequest.time = GetTickCount();
	echorequest.icmpheader.i_id = id++;
	echorequest.icmpheader.i_seq = seq++;
	echorequest.icmpheader.i_type = 8;
	echorequest.icmpheader.i_code = 0;
	echorequest.icmpheader.i_checksum = checksum((u_short *)&echorequest, sizeof(echorequest));	
	//����icmpЭ��
	int size = sizeof(sockaddr);
	int re = sendto(sock, (char *)&echorequest, sizeof(ECHOREQUEST), 0, (sockaddr *)&dstIP, sizeof(dstIP));
	if (re == SOCKET_ERROR) printf("sendto error");
	return;
}
//����ICMPЭ��
void recvfromEchorequest(SOCKET sock, ECHORESPONSE * sponse, sockaddr_in  *dstIP){
	int size = sizeof(sockaddr);
	int re = recvfrom(sock, (char *)  sponse, sizeof(ECHORESPONSE), 0, (sockaddr  *)&dstIP, &size);
	if (re == SOCKET_ERROR) { printf("recvfrom error"); }
	return;

}
void Ping(char * host){
	SOCKET sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP); //����ԭʼ�׽���
	HOSTENT	*lphost = gethostbyname(host);	//��ȡ���ص�IP��ַ
	sockaddr_in dstIP = { 0 };
	dstIP.sin_family = AF_INET;
	dstIP.sin_addr.S_un.S_addr = *(u_long *)lphost->h_addr;//ǿת��IP��ַ
	for (int i=0; i < 4;i++)
	{
		//��������
		sendtoEchorequest(sock, dstIP);
		//��������
		ECHORESPONSE echoresponse = { 0 };
		recvfromEchorequest(sock, &echoresponse,&dstIP);
		int time = echoresponse.echorequest.time;
		//��ӡ��� ���� 61.135.169.125 �Ļظ�: �ֽ�=32 ʱ��=28ms TTL=56
		printf("���� %s �Ļظ�: �ֽ�=32 ʱ��=%sms TTL=22");
		printf("���� %s �Ļظ�: �ֽ�=32 ʱ��=%sms TTL=22",
			inet_ntoa(dstIP.sin_addr),
			GetTickCount() - time);

	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	while (1)
	{
		Ping("www.15pb.com");
		char in = getchar();
		if (in == 'q')  break;
	}
	return 0;
}

