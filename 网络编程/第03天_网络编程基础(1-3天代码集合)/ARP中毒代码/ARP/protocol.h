#pragma once
#include <windows.h>

#pragma pack(push, 1)

//��̫��ͷ��(14�ֽ�)
#define EPT_IP 0x0800       // eh_type: IP 
#define EPT_ARP 0x0806      // eh_type: ARP 
#define EPT_RARP 0x8035     // eh_type: RARP 
typedef struct eh_hdr
{
    UCHAR eh_dst[6];        // ���շ�MAC��ַ 
    UCHAR eh_src[6];        // ���ͷ�MAC��ַ 
    USHORT eh_type;         // �ϲ�Э������ 
}EH_HEADR, *P_EH_HEADR;

//arpӦ��/����(28�ֽ�)
#define ARP_HARDWARE 0x0001  // arp_hrd����̫��
#define ARP_REQUEST 0x0001   // arp_op�� ���� request 
#define ARP_REPLY 0x0002     // arp_op�� Ӧ�� reply 
typedef struct arp_hdr
{
    USHORT arp_hrd;          // Ӳ������ 
    USHORT arp_pro;          // Э������ 
    UCHAR  arp_hln;          // Ӳ����MAC����ַ���� 
    UCHAR  arp_pln;          // Э�飨IP ����ַ���� 
    USHORT arp_op;           // �����ͣ�����Ӧ��
    UCHAR  arp_sha[6];       // ���ͷ�Ӳ����ַ ��Ӧ��ʱ���˴�����ƭ��
    ULONG  arp_spa;          // ���ͷ�Э���ַ ��Ӧ��ʱ���˴�����ƭ��
    UCHAR  arp_tha[6];       // ���շ�Ӳ����ַ ������ʱ���˴����ã�
    ULONG  arp_tpa;          // ���շ�Э���ַ 
}ARP_HEADR, *P_ARP_HEADR;

//ARPЭ��ջ
typedef struct arp_Packet
{
    EH_HEADR ehhdr;
    ARP_HEADR arphdr;
} ARP_PACKET, *P_ARP_PACKET;

//IPЭ��
typedef struct ip_hdr
{
    UCHAR  ip_headlen : 4;    //4λͷ������
    UCHAR  ip_version : 4;    //4λIPЭ��汾��
    UCHAR  ip_tos;            //8λ��������TOS
    USHORT ip_total_len;      //16λ�ܳ���
    USHORT ip_ident;          //16λ��ʾ��
    USHORT ip_frag :13;       //13λƫ����
    USHORT ip_flags: 3;       //3λ��־λ
    UCHAR  ip_ttl;            //8λ����ʱ��TTL
    UCHAR  ip_proto;          //8λ�ϲ�Э�飨TCP,UDP��������
    USHORT ip_checksum;       //16λIP�ײ������
    UINT   ip_sourceIP;       //32λԴIP��ַ
    UINT   ip_destIP;         //32λĿ��IP��ַ
                              //ѡ���Լ����ݲ�����
}IP_HEADR, *P_IP_HEADR;

//TCPЭ��
typedef struct tcp_hdr
{
    USHORT tcp_sport;           //16λԴ�˿�
    USHORT tcp_dport;           //16λĿ�Ķ˿�
    UINT   tcp_seq;             //32λ���к�
    UINT   tcp_ack_seq;         //32λȷ�Ϻ�

    UCHAR  tcp_rst:4;           //4λ����
    UCHAR  tcp_dataoff:4;       //4λ�ײ�����(����ƫ��)

    USHORT tcp_flag_fin : 1;    //�ر�
    USHORT tcp_flag_syn : 1;    //��������
    USHORT tcp_flag_rst : 1;    //���ɵ���
    USHORT tcp_flag_psh : 1;    //��������
    USHORT tcp_flag_ack : 1;    //���ݰ�ȷ��
    USHORT tcp_flag_urg : 1;
    USHORT tcp_flag_reho: 1;    
    USHORT tcp_flag_cwr : 1;

    USHORT tcp_window;           //16λ���ڴ�С
    USHORT tcp_check;            //16λ�����
    USHORT tcp_urgptr;           //16λ��������ƫ����,flagΪtcp_flag_urgʱ��Ч
}TCP_HEADR,*P_TCP_HEADR;

//UDPЭ��
typedef struct udp_hdr//����UDP�ײ�
{
    USHORT udp_sport;           //16λԴ�˿�
    USHORT udp_dport;           //16λĿ�Ķ˿�
    USHORT udp_len;             //���ݰ����ֽڳ���
    USHORT udp_cksum;           //���ݰ���У���
}UDP_HEADR, P_UDP_HEADR;

//ICMPЭ��
typedef struct icmp_hdr //����ICMP�ײ�
{
    USHORT imcp_sport;
    USHORT imcp_dport;
    UCHAR  imcp_type;
    UCHAR  imcp_code;
    USHORT imcp_cksum;
    USHORT imcp_id;
    USHORT imcp_seq;
    ULONG  imcp_timestamp;
}ICMP_HEADR;

#pragma pack(pop)