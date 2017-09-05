#include <assert.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

/*
跨函数跳转（长跳转）：场景则常见于多进程的模块化处理系统中，用于回到特定（初始）状态。

我们假设，一个手机维修店有客户经理和维修工程师两个人。客户经理只是负责和客户沟通、订合同、收货、收钱，具体的维修工作由后者处理。工程师接到一个维修任务，
打开手机外壳后一看，就说三个字“没得搞”，然后外壳也不拧上，就直接扔掉，休息休息去忙下一个机器的维修。至于客户经理怎么和客户沟通，那不是工程师的事，最多拍个照片以做证明。

对于模块化的系统，我们假设也有两个进程，一个进程A负责计算，一个进程B负责通过socket或其他方式获取数据及发布计算结果。
两个进程之间协作，通过任务的方式推动而不是函数的方式调用。进程B，就如同维修工程师，当给入的数据无法计算或者计算导致错误时，
则直接长跳转到最初的状态，继续等待下一个任务。当然人性化一点，多少告知一下进程A，方便它给客户端一个交代。
*/

static jmp_buf jmp;

float a(float i, float j)
{
    if(0 == j)
    {
        printf("called longjimp......\n");

        longjmp(jmp, 2);
    }

    return i / j;
}

float b(float x1, float x2)
{
    return a(x1+x2, x1-x2);
}

int main(int argc, char* argv[])
{
    float x1, x2;

    assert(argc > 2);

    x1 = atof(argv[1]);
    x2 = atof(argv[2]);

    if(0 == setjmp(jmp))
    {
        printf("(%f + %f) / (%f - %f) = %f\n", x1, x2, x1, x2, b(x1, x2));
    }
    else
    {
        printf("(%f - %f) error!\n", x1, x2);
    }

    return 0;
}
