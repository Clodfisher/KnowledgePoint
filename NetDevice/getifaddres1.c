#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
  函数作用：采用getifaddres取得linux设备网卡中的一些信息
  测试结果：
zl@ubuntu-zl:~/Github/KnowledgePoint/NetDevice$./a.out
--------------0
lo  address family: 17 (AF_PACKET)
--------------1
eth0  address family: 17 (AF_PACKET)
--------------2
lo  address family: 2 (AF_INET)
    address: <127.0.0.1>
--------------3
eth0  address family: 2 (AF_INET)
    address: <192.168.75.174>
--------------4
lo  address family: 10 (AF_INET6)
    address: <::1>
--------------5
eth0  address family: 10 (AF_INET6)
    address: <fe80::20c:29ff:fe7a:fd6f%eth0>
zl@ubuntu-zl:~/Github/KnowledgePoint/NetDevice$ ifconfig
eth0      Link encap:Ethernet  HWaddr 00:0c:29:7a:fd:6f
          inet addr:192.168.75.174  Bcast:192.168.75.255  Mask:255.255.255.0
          inet6 addr: fe80::20c:29ff:fe7a:fd6f/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:1042663 errors:0 dropped:0 overruns:0 frame:0
          TX packets:15201 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000
          RX bytes:74653604 (74.6 MB)  TX bytes:1719006 (1.7 MB)
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

int main(int argc, char *argv[])
{
    struct ifaddrs *ifaddr, *ifa;
    int family, s;
    char host[NI_MAXHOST];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    /* Walk through linked list, maintaining head pointer so we
     *               can free list later */

    int itest = 0;
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        printf("--------------%d\n", itest++);
        if (ifa->ifa_addr == NULL)
            continue;

        family = ifa->ifa_addr->sa_family;

        /* Display interface name and family (including symbolic
         *                   form of the latter for the common families) */

        printf("%s  address family: %d%s\n",
               ifa->ifa_name, family,
               (family == AF_PACKET) ? " (AF_PACKET)" :
                                       (family == AF_INET) ?   " (AF_INET)" :
                                                               (family == AF_INET6) ?  " (AF_INET6)" : "");

        /* For an AF_INET* interface address, display the address */

        if (family == AF_INET || family == AF_INET6) {
            s = getnameinfo(ifa->ifa_addr,
                            (family == AF_INET) ? sizeof(struct sockaddr_in) :
                                                  sizeof(struct sockaddr_in6),
                            host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
            if (s != 0) {
                printf("getnameinfo() failed: %s\n", gai_strerror(s));
                exit(EXIT_FAILURE);
            }
            printf("\taddress: <%s>\n", host);
        }
    }

    freeifaddrs(ifaddr);
    exit(EXIT_SUCCESS);
}

