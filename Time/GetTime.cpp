#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <string>

using namespace std;

void sysLocalTime()
{//求出的为秒
    time_t             ec;
    struct tm         *p;

    time(&ec);
    p = localtime(&ec);

    printf("%d年%d月%d日%d时%d分%d秒\n", 1900+p->tm_year, 1+p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);

}

void sysUsecTime()
{//求出的为毫秒
    struct timeval    tv;
    struct timezone tz;

    struct tm         *p;

    gettimeofday(&tv, &tz);
    printf("tv_sec:%ld\n",tv.tv_sec);
    printf("tv_usec:%ld\n",tv.tv_usec);
    printf("tz_minuteswest:%d\n",tz.tz_minuteswest);
    printf("tz_dsttime:%d\n",tz.tz_dsttime);

    p = localtime(&tv.tv_sec);
    printf("time_now:%d年%d月%d日%d时%d分%d.%ld秒\n", 1900+p->tm_year, 1+p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec, tv.tv_usec);
}

void timecalfun()
{

    time_t timep;
    time(&timep);       //读取时间，秒数
    printf("ctime return:%s\n",ctime(&timep));//转换为字符串输出

    time_t timep1, timep2;
    time(&timep1);
    time(&timep2);
    printf("%s\n",asctime(gmtime(&timep1))); //转换为UCT时间，并已字符串输出
    printf("%s\n",asctime(localtime(&timep2))); //转换为UCT时间，并已字符串输出

    char buff[128];
    memset(buff,'\0',128);
    printf("globle time:");
    strftime(buff, 128, "%Z",gmtime(&timep1));        //提示时区
    printf("TZ=%s\n",buff);

    printf("local time:");
    strftime(buff, 128, "%Z",localtime(&timep2));        //提示时区
    printf("TZ=%s\n",buff);
}

int main(void)
{
    sysLocalTime();
    printf("============gettimeofday==============\n");

    sysUsecTime();
    printf("============timecalfun=======================\n");
    timecalfun();
    return 0;
}








