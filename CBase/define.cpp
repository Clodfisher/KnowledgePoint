/*
 * 作用：用于测试字符从的连接性，以及指编译器能够识别的最小语法单元（子串的连接）
 * 结果：
 * zl@ubuntu-zl:~/Github/KnowledgePoint/CBase$ g++ define.cpp 
 * zl@ubuntu-zl:~/Github/KnowledgePoint/CBase$ ./a.out 
 * schdule.conf
 * ../setting/schdule.conf
 * you can see
 * hello world
 * token9 = 9
 * token9 = 9
*/

#include <stdio.h>
#include <string>

using namespace std;

#define DEFAULT_NAME "schdule.conf"
#define DEFAULT_FILE "../setting/"DEFAULT_NAME
#define paster( n ) printf( "token" #n " = %d\n", token##n ) 

char g_str[] = "hello " "world";

int main()
{
	int token9 = 9;
	int token = 0;

	printf("%s\n", DEFAULT_NAME);
	printf("%s\n", DEFAULT_FILE);
	printf("%s\n", "you ""can see");
	printf("%s\n", g_str);

	printf("token" "9" " = %d\n", token9);
	paster(9);

	return 0;
}
