#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*
  函数作用：
用于创建多级的子目录
  执行结果：
zl@ubuntu-zl:~/Github/KnowledgePoint/File/CreatDirs$ ./a.out
目录：/home
目录：/home/zl
目录：/home/zl/test
目录：/home/zl/test/learn
创建目录:/home/zl/test/learn
目录：/home/zl/test/learn/c++
创建目录:/home/zl/test/learn/c++
目录：/home/zl/test/learn/c++/Fstream
创建目录:/home/zl/test/learn/c++/Fstream
创建目录:/home/zl/test/learn/c++/Fstream/lj

*/

static void mkdirs(char *muldir)
{
    int i,len;
    char str[512];
    strncpy(str, muldir, 512);
    len=strlen(str);
    for( i=0; i<len; i++ )
    {
        if( str[i]=='/' && i != 0)
        {
            str[i] = '\0';
            printf("目录：%s\n", str);
            if( access(str,0)!=0 )
            {
                mkdir( str, 0777 );
                printf("创建目录:%s\n", str);
            }
            str[i]='/';
        }
    }
    if( len>0 && access(str,0)!=0 )
    {
        mkdir( str, 0777 );
        printf("创建目录:%s\n", str);
    }
    return;
}

int main()
{
     char cTesDir[] = "/home/zl/test/learn/c++/Fstream/lj";
     mkdirs(cTesDir);

     return 0;
}
