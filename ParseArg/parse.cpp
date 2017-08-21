#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <string>
#include <vector>

/* 本程序用于对参数进行解析，对于此函数的详细解释，可参照《Linux 高级程序设计中文第三版》杨宗德 P64 */

using namespace std;

typedef enum
{
    TASK_SIDE_CTRL = 0,
    TASK_SIDE_INFO = 1,
    TASK_SIDE_BOTH = 2,
}TASK_SIDE;

typedef vector<string> STRING_ARG;

#define VERSION "0.0.0.0"

TASK_SIDE g_nTaskSide = TASK_SIDE_CTRL;
static long long g_nCpuMask = 0x01;
static string g_strDBConfPath;
static STRING_ARG g_arrTaskConfPath;

static bool g_bDebug = false;

static void ShowHelp(void)
{
    printf("Sync two db table\n"
           "./SyncSQL {--ctrl/info} {-b DB_CONFIG} {-t TASK_CONFIG [TASK_CONFIG2 [TASK_CONFIG3..]]} [-c CPU_MASK] [-dhv]\n"
           "--ctrl task run in ctrl side\n"
           "--info task run in info side\n"
           "-b     DB connect config\n"
           "-t     task config\n"
           "-c     task will run to CPU_MASK, default to 0x01\n"
           "-d     debug mode\n"
           "-h     show help\n"
           "-v     show version\n");
}

/// 读取命令行参数
/// return 是否需要推出
static bool ParseArg(int argc, char *argv[])
{
    int n = 0;
    char opt = '\0';
    const struct option options[] = {
        {"DBConfig",   1, 0, 'b'},
        {"TaskConfig", 1, 0, 't'},
        {"debug",      0, 0, 'd'},
        {"ctrl",       0, 0, 0},
        {"info",       0, 0, 0},
        {"both",       0, 0, 0},
        {"cpu_mask",   0, 0, 'c'},
        {"help",       0, 0, 'h'},
        {"version",    0, 0, 'v'},
        {0,            0, 0, 0}
    };

    while(opt = getopt_long(argc, argv, "b:t:c:hvd", options, &n))
    {
        switch (opt)
        {
        case 0:
            if(strcmp("ctrl", options[n].name) == 0)
            {
                g_nTaskSide = TASK_SIDE_CTRL;
            }
            else if(strcmp("info", options[n].name) == 0)
            {
                g_nTaskSide = TASK_SIDE_CTRL;
            }
            else if(strcmp("both", options[n].name) == 0)
            {
                g_nTaskSide = TASK_SIDE_CTRL;
            }
            else
            {
                ShowHelp();
                return true;
            }
            break;

        case 'b':
            g_strDBConfPath = optarg;
            break;

        case 'c':
            sscanf(optarg, "%lli", &g_nCpuMask);
            printf("set cpu mask:0x%02llx\n");
            break;

        case 't':
            g_arrTaskConfPath.push_back(optarg);
            break;

        case 'v':
            printf("%s\n", VERSION);
            return true;
            break;

        case 'd':
            g_bDebug = true;
            break;

        case 'h':
        default:
            ShowHelp();
            return true;
            break;
        }

    }

    for(n = optind; n < argc; n++)
    {
        g_arrTaskConfPath.push_back(optarg);
    }
    if(g_strDBConfPath.length() == 0 || g_arrTaskConfPath.size() == 0)
    {
        ShowHelp();
        return true;
    }

    //初始化参数处理下标，保证其他程序使用getopt时能够正确运行
    optind = 1;
    return false;
}

int main(int argc, char *argv[])
{

    if(ParseArg(argc, argv))
    {
        return 1;
    }

    return 0;
}
