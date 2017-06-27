#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
/*
  功能：根据指定的网卡名，获取此网卡设备的IP地址、广播地址、掩码地址、MAC地址
  程序执行过程：
zl@ubuntu-zl:~/Github/KnowledgePoint/NetDevice$ ./a.out eth0
inet addr: 192.168.75.174 broad addr: 192.168.75.255 inet mask: 255.255.255.0 local mac:000c297afd6f

zl@ubuntu-zl:~/Github/KnowledgePoint/NetDevice$ ifconfig
eth0      Link encap:Ethernet  HWaddr 00:0c:29:7a:fd:6f
          inet addr:192.168.75.174  Bcast:192.168.75.255  Mask:255.255.255.0
          inet6 addr: fe80::20c:29ff:fe7a:fd6f/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:1042314 errors:0 dropped:0 overruns:0 frame:0
          TX packets:14853 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000
          RX bytes:74524337 (74.5 MB)  TX bytes:1679832 (1.6 MB)
          Interrupt:19 Base address:0x2000

lo        Link encap:Local Loopback
          inet addr:127.0.0.1  Mask:255.0.0.0
          inet6 addr: ::1/128 Scope:Host
          UP LOOPBACK RUNNING  MTU:16436  Metric:1
          RX packets:44407 errors:0 dropped:0 overruns:0 frame:0
          TX packets:44407 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:0
          RX bytes:3152910 (3.1 MB)  TX bytes:3152910 (3.1 MB)

*/

static void usage()
{
    printf("usage : ipconfig interface \n");
    exit(0);
}

int main(int argc,char **argv)
{
    struct sockaddr_in *addr;
    struct ifreq ifr;
    char *name,*address;
    int sockfd;

    if(argc != 2)  usage();
    else  name = argv[1];

    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    strncpy(ifr.ifr_name,name,IFNAMSIZ-1);

    if(ioctl(sockfd,SIOCGIFADDR,&ifr) == -1)
        perror("ioctl error"),exit(1);

    addr = (struct sockaddr_in *)&(ifr.ifr_addr);
    address = inet_ntoa(addr->sin_addr);
    printf("inet addr: %s ",address);

    if(ioctl(sockfd,SIOCGIFBRDADDR,&ifr) == -1)
        perror("ioctl error"),exit(1);

    addr = (struct sockaddr_in *)&ifr.ifr_broadaddr;
    address = inet_ntoa(addr->sin_addr);
    printf("broad addr: %s ",address);

    if(ioctl(sockfd,SIOCGIFNETMASK,&ifr) == -1)
        perror("ioctl error"),exit(1);
    addr = (struct sockaddr_in *)&ifr.ifr_addr;
    address = inet_ntoa(addr->sin_addr);
    printf("inet mask: %s ",address);

    if(ioctl(sockfd,SIOCGIFHWADDR,&ifr) == -1)
        perror("ioctl error"),exit(1);

    char mac_addr[30];

    sprintf(mac_addr,"%02x%02x%02x%02x%02x%02x",
            (unsigned char)ifr.ifr_hwaddr.sa_data[0],
            (unsigned char)ifr.ifr_hwaddr.sa_data[1],
            (unsigned char)ifr.ifr_hwaddr.sa_data[2],
            (unsigned char)ifr.ifr_hwaddr.sa_data[3],
            (unsigned char)ifr.ifr_hwaddr.sa_data[4],
            (unsigned char)ifr.ifr_hwaddr.sa_data[5]);

    printf("local mac:%s\n",mac_addr);

    close( sockfd );

    printf("\n");

    exit(0);
}
