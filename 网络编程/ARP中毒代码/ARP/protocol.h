#pragma once
#include <windows.h>

#pragma pack(push, 1)

//以太网头部(14字节)
#define EPT_IP 0x0800       // eh_type: IP 
#define EPT_ARP 0x0806      // eh_type: ARP 
#define EPT_RARP 0x8035     // eh_type: RARP 
typedef struct eh_hdr
{
    UCHAR eh_dst[6];        // 接收方MAC地址 
    UCHAR eh_src[6];        // 发送方MAC地址 
    USHORT eh_type;         // 上层协议类型 
}EH_HEADR, *P_EH_HEADR;

//arp应答/请求(28字节)
#define ARP_HARDWARE 0x0001  // arp_hrd：以太网
#define ARP_REQUEST 0x0001   // arp_op： 请求 request 
#define ARP_REPLY 0x0002     // arp_op： 应答 reply 
typedef struct arp_hdr
{
    USHORT arp_hrd;          // 硬件类型 
    USHORT arp_pro;          // 协议类型 
    UCHAR  arp_hln;          // 硬件（MAC）地址长度 
    UCHAR  arp_pln;          // 协议（IP ）地址长度 
    USHORT arp_op;           // 包类型：请求、应答
    UCHAR  arp_sha[6];       // 发送发硬件地址 （应答时，此处可欺骗）
    ULONG  arp_spa;          // 发送方协议地址 （应答时，此处可欺骗）
    UCHAR  arp_tha[6];       // 接收方硬件地址 （请求时，此处无用）
    ULONG  arp_tpa;          // 接收方协议地址 
}ARP_HEADR, *P_ARP_HEADR;

//ARP协议栈
typedef struct arp_Packet
{
    EH_HEADR ehhdr;
    ARP_HEADR arphdr;
} ARP_PACKET, *P_ARP_PACKET;

//IP协议
typedef struct ip_hdr
{
    UCHAR  ip_headlen : 4;    //4位头部长度
    UCHAR  ip_version : 4;    //4位IP协议版本号
    UCHAR  ip_tos;            //8位服务类型TOS
    USHORT ip_total_len;      //16位总长度
    USHORT ip_ident;          //16位标示符
    USHORT ip_frag :13;       //13位偏移量
    USHORT ip_flags: 3;       //3位标志位
    UCHAR  ip_ttl;            //8位生存时间TTL
    UCHAR  ip_proto;          //8位上层协议（TCP,UDP或其他）
    USHORT ip_checksum;       //16位IP首部检验和
    UINT   ip_sourceIP;       //32位源IP地址
    UINT   ip_destIP;         //32位目的IP地址
                              //选项以及数据不定义
}IP_HEADR, *P_IP_HEADR;

//TCP协议
typedef struct tcp_hdr
{
    USHORT tcp_sport;           //16位源端口
    USHORT tcp_dport;           //16位目的端口
    UINT   tcp_seq;             //32位序列号
    UINT   tcp_ack_seq;         //32位确认号

    UCHAR  tcp_rst:4;           //4位保留
    UCHAR  tcp_dataoff:4;       //4位首部长度(数据偏移)

    USHORT tcp_flag_fin : 1;    //关闭
    USHORT tcp_flag_syn : 1;    //请求连接
    USHORT tcp_flag_rst : 1;    //不可到达
    USHORT tcp_flag_psh : 1;    //发送数据
    USHORT tcp_flag_ack : 1;    //数据包确认
    USHORT tcp_flag_urg : 1;
    USHORT tcp_flag_reho: 1;    
    USHORT tcp_flag_cwr : 1;

    USHORT tcp_window;           //16位窗口大小
    USHORT tcp_check;            //16位检验和
    USHORT tcp_urgptr;           //16位紧急数据偏移量,flag为tcp_flag_urg时有效
}TCP_HEADR,*P_TCP_HEADR;

//UDP协议
typedef struct udp_hdr//定义UDP首部
{
    USHORT udp_sport;           //16位源端口
    USHORT udp_dport;           //16位目的端口
    USHORT udp_len;             //数据包的字节长度
    USHORT udp_cksum;           //数据包的校验和
}UDP_HEADR, P_UDP_HEADR;

//ICMP协议
typedef struct icmp_hdr //定义ICMP首部
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