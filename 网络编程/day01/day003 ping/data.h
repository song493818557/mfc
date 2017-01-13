#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
struct TIPHEAD{
	u_char vshlen;	//ip��ʹ�õİ汾 + �ײ�����(���ֽڵ�������)
	u_char ser;		//�������� ·����ʹ�ø��ֶ����������ȵ�����
	u_short tlen;	//ip����+���ݰ�����
	u_short mark;	//��ʶ�� һ��Ψһ��ʾ �����������ݱ������ݷ�Ƭ��˳��
	u_short flag;	//��� ��ʾ���ݱ��Ƿ��Ƿ�Ƭ����
	u_char livetime;//���ʱ��  ���� ���ݰ�����������,·������תһ�θ�ֵ��1
	u_char protocol;//Э�� ����ʶ�����ݰ����ϲ�Э������
	u_short Checksum;//�ײ�У��� ���������, ȷ�������Ƿ��𻵻��߱��۸�
	u_long srcip;	//���ͷ�����IP
	u_long dstip;	//���շ�����IP
	//char aa[20];	����[��ѡ] ʹ��IP���ݵ�ʵ������ ���ԭʼ�׽��ַ��͵Ļ� ��Ҫ��ô���� ����ô���� ��Ȼֵ��Բ���
};

//icmpͷ��
struct  ICMPheader{
	u_char i_type;
	u_char i_code;
	u_short i_checksum;
	u_short i_id;
	u_short i_seq; 
};
//����ICMPЭ��
struct ECHOREQUEST{
	ICMPheader icmpheader;//ICMPЭ��ͷ	
	int time;
	char data[32];
};
//����ICMPЭ��
struct ECHORESPONSE{
	TIPHEAD iphead;//����ICMPЭ����----IP��ͷ��
	ECHOREQUEST echorequest;//����ICMPЭ����----ICMPЭ��ͷ
	char fill[255];
};
// ����У���(16λ�����Ʒ�����ͣ��㷨ϸ�ڲ���Ҫ�)
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
