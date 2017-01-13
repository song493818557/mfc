#pragma once
#include <winsock2.h>
#pragma  comment(lib ,"ws2_32.lib")

//ip头部
struct  IPHeader
{
	u_char vilen;		//版本+长度
	u_char ser;			//服务类型
	u_short totalLen;	//总长度
	u_short id;			//标示符
	u_short flag;		//标记+分片偏移
	u_char ttl;			//存活时间
	u_char protocol;	//协议
	u_short checkSum;	//校验和
	in_addr srcIP;		//源IP
	in_addr dstIP;		//目的IP
};
//icmp头部
struct ICMPHeader 
{
	u_char type;		//类型
	u_char code;		//代码
	u_short checkSum;	//校验和
	u_short id;			//标示
	u_short seq;		//序列号
};

struct ECHOREQUEST
{
	ICMPHeader icmpHeader;
	int time;
	char data[32];
};

struct ECHORESPONSE
{
	IPHeader ipHeader;
	ECHOREQUEST echoRequest;
	char fill[255];
};

// 计算校验和(16位二进制反码求和，算法细节不需要深究)
u_short checksum(u_short *buffer, int len)
{
	register int nleft = len;
	register u_short *w = buffer;
	register u_short answer;
	register int sum = 0;
	// 使用32bit的累加器，进行16bit的反馈计算
	while (nleft > 1) {
		sum += *w++;
		nleft -= 2;
	}
	// 补全奇数位
	if (nleft == 1) {
		u_short	u = 0;

		*(u_char *)(&u) = *(u_char *)w;
		sum += u;
	}
	// 将反馈的16bit从高位移至地位
	sum = (sum >> 16) + (sum & 0xffff);	/* add hi 16 to low 16 */
	sum += (sum >> 16);					/* add carry */
	answer = ~sum;						/* truncate to 16 bits */
	return (answer);
}
