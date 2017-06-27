#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <net/if.h>

/*
  函数作用：用于获取主机中的所有网卡名和网卡ip，以及通过网卡名取得网卡的唯一标识
  函数结果：
zl@ubuntu-zl:~/Github/KnowledgePoint/NetDevice$ ./a.out
interface(lo--->1)'s ip is 127.0.0.1
interface(eth0--->4)'s ip is 192.168.75.174
________________________________________________
zl@ubuntu-zl:~/Github/KnowledgePoint/NetDevice$ ifconfig
eth0      Link encap:Ethernet  HWaddr 00:0c:29:7a:fd:6f
          inet addr:192.168.75.174  Bcast:192.168.75.255  Mask:255.255.255.0
          inet6 addr: fe80::20c:29ff:fe7a:fd6f/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:1042641 errors:0 dropped:0 overruns:0 frame:0
          TX packets:15179 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000
          RX bytes:74644444 (74.6 MB)  TX bytes:1716372 (1.7 MB)
          Interrupt:19 Base address:0x2000

lo        Link encap:Local Loopback
          inet addr:127.0.0.1  Mask:255.0.0.0
          inet6 addr: ::1/128 Scope:Host
          UP LOOPBACK RUNNING  MTU:16436  Metric:1
          RX packets:44413 errors:0 dropped:0 overruns:0 frame:0
          TX packets:44413 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:0
          RX bytes:3153378 (3.1 MB)  TX bytes:3153378 (3.1 MB)

*/

int getInterfaceIP(const char* interface, char* ip)
{
    if (ip == NULL) {
        return -1;
    }

    struct ifaddrs* ifa = NULL;
    int rec = getifaddrs(&ifa);
    if (rec) {
        printf("getifaddrs error : %d\n", errno);
        return -1;
    }

    int code = 0;
    struct ifaddrs *ifp = ifa;
    for (; ifp != NULL; ifp = ifp->ifa_next) {
        if (ifp->ifa_addr && ifp->ifa_addr->sa_family == AF_INET
                && !strcmp (interface, ifp->ifa_name)) {
            strcpy(ip, inet_ntoa(((struct sockaddr_in*) ifp->ifa_addr)->sin_addr));
            code = 1;
            break;
        }
    }

    freeifaddrs(ifa);

    return code;
}

int getAllInterfaceIP(void)
{
    char ip[32] = {0};
    if (ip == NULL) {
        return -1;
    }

    struct ifaddrs* ifa = NULL;
    int rec = getifaddrs(&ifa);
    if (rec) {
        printf("getifaddrs error : %d\n", errno);
        return -1;
    }

    int code = 0;
    struct ifaddrs *ifp = ifa;
    for (; ifp != NULL; ifp = ifp->ifa_next) {
        if (ifp->ifa_addr && ifp->ifa_addr->sa_family == AF_INET)
        {
            strcpy(ip, inet_ntoa(((struct sockaddr_in*) ifp->ifa_addr)->sin_addr));
            unsigned int nNicIndex = if_nametoindex(ifp->ifa_name);
            printf("interface(%s--->%d)'s ip is %s\n", ifp->ifa_name, nNicIndex, ip);
            code = 1;
        }
    }

    freeifaddrs(ifa);

    return code;
}

int main(int argc, char** argv)
{
    //    if (argc < 2) {
    //        printf("usage : %s [eth0|eth1|lo]\n", argv[0]);
    //        return -1;
    //    }

    //    char ip[32] = {0};
    //    int rec = getInterfaceIP(argv[1], ip);
    //    if (rec > 0) {
    //        printf("interface(%s)'s ip is %s\n", argv[1], ip);
    //    }
    getAllInterfaceIP();

    printf("________________________________________________\n");
    return 0;
}
