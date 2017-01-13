#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
struct TIPHEAD{
	u_char vshlen;	//ip所使用的版本 + 首部长度(四字节的整数倍)
	u_char ser;		//服务类型 路由器使用该字段做流量优先的排序
	u_short tlen;	//ip长度+数据包长度
	u_short mark;	//标识符 一个唯一标示 用来区分数据报或数据分片的顺序
	u_short flag;	//标记 标示数据报是否是分片数据
	u_char livetime;//存活时间  定义 数据包的生存周期,路由器中转一次该值减1
	u_char protocol;//协议 用来识别数据包的上层协议类型
	u_short Checksum;//首部校验和 错误检测机制, 确认内容是否损坏或者被篡改
	u_long srcip;	//发送方主机IP
	u_long dstip;	//接收方主机IP
	//char aa[20];	数据[可选] 使用IP传递的实际数据 如果原始套接字发送的话 需要怎么发的 就怎么接受 不然值会对不上
};

//icmp头部
struct  ICMPheader{
	u_char i_type;
	u_char i_code;
	u_short i_checksum;
	u_short i_id;
	u_short i_seq; 
};
//发送ICMP协议
struct ECHOREQUEST{
	ICMPheader icmpheader;//ICMP协议头	
	int time;
	char data[32];
};
//接受ICMP协议
struct ECHORESPONSE{
	TIPHEAD iphead;//接受ICMP协议中----IP的头部
	ECHOREQUEST echorequest;//接受ICMP协议中----ICMP协议头
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
