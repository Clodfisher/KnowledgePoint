#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>

#define CONF_PATH "./IpMac.conf"

typedef struct StaticArpIpMac
{
    unsigned int nStaticIP;     //静态IP
    char cMac[6];               //静态MAC
}STATIC_ARP_IP_MAC;

unsigned char a2x(const char c)
{
    switch(c) {
    case '0'...'9':
        return (unsigned char)atoi(&c);
    case 'a'...'f':
        return 0xa + (c-'a');
    case 'A'...'F':
        return 0xa + (c-'A');
    default:
        goto error;
    }
error:
    exit(0);
}

/*convert a string,which length is 18, to a macaddress data type.*/
#define MAC_LEN_IN_BYTE 6
#define COPY_STR2MAC(mac,str)  \
    do { \
    for(int i = 0; i < MAC_LEN_IN_BYTE; i++) {\
    mac[i] = (a2x(str[i*3]) << 4) + a2x(str[i*3 + 1]);\
    }\
    } while(0)

int main(int argc, char **argv)
{
    //通过配置文件读取IP与MAC的对应关系

    FILE *pFopen;

    pFopen = fopen(CONF_PATH, "r");
    if(NULL == pFopen)
    {
        printf("配置文件读取失败！\n");
        return -1;
    }

    while(!feof(pFopen))
    {
        char cLineString[1024];
        memset(cLineString, 0, 1024);
        fgets(cLineString, 1024, pFopen);

        if('#' == cLineString[0])
        {
            continue;
        }

        //解析有效内容
            char cCopyString[1024] = "";
            strcpy(cCopyString, cLineString);

        char *pCopyString = cCopyString;
        char *pToken;
        char cDelim[] = " ,\n";
        int i = 0;//i = 0 ----IP , i = 1 ------MAC
        STATIC_ARP_IP_MAC sStaticArpIpMac;
        for(pToken = strsep(&pCopyString, cDelim); pToken != NULL; pToken = strsep(&pCopyString, cDelim))
        {
            if(0 == strcmp(pToken, ""))
            {
                continue;
            }
            if(i == 0)
            {//取得IP
                i = 1;
                printf("IP is %s", pToken);
            }
            else
            {
                i = 0;
                char macstr[18] = {0};
                strcpy(macstr, pToken);
                COPY_STR2MAC(sStaticArpIpMac.cMac, macstr);
                printf(" MAC is %02x:%02x:%02x:%02x:%02x:%02x\n",
                       (unsigned char)sStaticArpIpMac.cMac[0],
                       (unsigned char)sStaticArpIpMac.cMac[1],
                       (unsigned char)sStaticArpIpMac.cMac[2],
                       (unsigned char)sStaticArpIpMac.cMac[3],
                       (unsigned char)sStaticArpIpMac.cMac[4],
                       (unsigned char)sStaticArpIpMac.cMac[5]);
            }

        }
    }

    fclose(pFopen);

    return 0;
}

