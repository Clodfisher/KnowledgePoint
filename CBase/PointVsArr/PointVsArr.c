#include <stdio.h>

typedef struct
{
	int num;
	int p[];//成员p指针常量，它并不存在存储指针的存储空间
}_BUF;

typedef struct
{
	int num;
	int *p1;
}_BUF1;

typedef struct
{
	int num;
	int p2[1];
}_BUF2;

int main()
{
	int nSize = sizeof(_BUF);
	int nSize1 = sizeof(_BUF1);
	int nSize2 = sizeof(_BUF2);

	printf("sizeof(_BUF) = %d, sizeof(_BUF1) = %d, sizeof(_BUF2) = %d\n", nSize, nSize1, nSize2);

	return 0;
}
