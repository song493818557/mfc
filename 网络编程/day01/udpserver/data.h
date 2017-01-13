#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

//ipͷ��
struct IPhead{
	u_char vislen;//�汾���ײ�����
	u_char ser;//��������
	u_short totallen; //�ܳ���
	u_short id;//��ʾ
	u_short flag;//���+��Ƭƫ��
	u_char ttl;//���ʱ��
	u_char protocol;//Э��
	u_short checkSum; //У���
	in_addr srcIP;//ԴIP
	in_addr dstIP;//Ŀ��IP 
};
//icmpͷ��
struct  ICMPheader
{
	u_char type;//����
	u_char code;//����
	u_short checkSum;//У���
	u_short id;//��ʾ
	u_short seq;//���к�
};

struct echoRequest{
	ICMPheader  icmpheader;
	char data[32];
	int time;  
};

struct ECHORESPONSE{
	IPhead iphead;
	echoRequest echoRequest;
	char fill[255]; 
	
};
u_short checksum(u_short *buffer, int len)
{
	register int nleft = len;
	register u_short *w = buffer;
	register u_short answer;
	register int sum = 0;
	// ʹ��32bit���ۼ���������16bit�ķ�������
	while (nleft > 1) {
		sum += *w++;
		nleft -= 2;
	}
	// ��ȫ����λ
	if (nleft == 1) {
		u_short	u = 0;

		*(u_char *)(&u) = *(u_char *)w;
		sum += u;
	}
	// ��������16bit�Ӹ�λ������λ
	sum = (sum >> 16) + (sum & 0xffff);	/* add hi 16 to low 16 */
	sum += (sum >> 16);					/* add carry */
	answer = ~sum;						/* truncate to 16 bits */
	return (answer);
}