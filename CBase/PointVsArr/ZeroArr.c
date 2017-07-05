#include <stdio.h>

//test结构中i和p指针，在C的编译器中保存的是相对地址——也就是说，他们的地址是相对于struct test的实例的。
struct test{
    int i;
    short c;
    char *p;
    char s[10];
};

struct line {
    int length;
    char contents[0]; // C99的玩法是：char contents[]; 没有指定数组长度
};

struct two{
    int a;
    int b;
};


int main()
{
    int ntest = 10;
    int *ptest = &ntest;

    printf("ntest 变量地址，用百分之x打印 = 0x%x\n", &ntest);
    printf("ptest 指针中存储地址，用百分之x打印 = 0x%x\n", ptest);
    printf("ptest 指针中存储地址，用百分之p打印 = %p\n", ptest);

    printf("----------------------------\n");

    struct two sTwo;
    sTwo.a = 1;
    sTwo.b = 2;
    struct two *pTwo = &sTwo;
    printf("pTwo指向的内存，即pTwo中存储的内存数据中a的值 = %d\n", pTwo->a);
    printf("pTwo指向的内存，即pTwo中存储的内存数据中b的值 = %d\n", pTwo->b);

    printf("----------------------------\n");

    struct test *pt=NULL;
    printf("pt中存储的地址用百分之x打印 = %x\n", pt);//pt中存储的地址
    printf("pt中存储的地址用百分之p打印 = %p\n", pt);
    printf("pt中存储i的地址用百分之x打印 = %x\n", &pt->i); //因为操作符优先级，我没有写成&(pt->i)
    printf("pt中存储i的地址用百分之p打印 = %p\n", &pt->i); //
//    printf("&i *i = %d\n",pt->i); //端错误(访问不存在的内存数据中的值)，访问量pt存储地址+偏移i相对大小后，内存中的数据，即为i的存储值
    printf("pt中存储c的地址用百分之x打印 = %x\n", &pt->c);
    printf("pt中存储c的地址用百分之p打印 = %p\n", &pt->c); //因为操作符优先级，我没有写成&(pt->i)
    printf("pt中存储p的地址用百分之x打印 = %x\n", &pt->p);
    printf("pt中存储p的地址用百分之p打印 = %p\n", &pt->p);
    printf("pt中存储s的地址用百分之x打印 = %x\n", pt->s); //等价于 printf("%x\n", &(pt->s) );
    printf("pt中存储s的地址用百分之p打印 = %p\n", pt->s);

    printf("--------------------------\n");

    int this_length=10;
    struct line *thisline = (struct line *)
            malloc (sizeof (struct line) + this_length);
    thisline->length = this_length;
    memset(thisline->contents, 'a', this_length);

    printf("thisline = %x\n", thisline);

    printf("thisline->contents = %x\n", thisline->contents);
    printf("thisline->contents中的内容：%s\n", thisline->contents);


    return 0;
}
/*
  执行结果：
zl@ubuntu-zl:~/yht/learn/c$ ./a.out
ntest 变量地址，用百分之x打印 = 0xbfdab4c8
ptest 指针中存储地址，用百分之x打印 = 0xbfdab4c8
ptest 指针中存储地址，用百分之p打印 = 0xbfdab4c8
----------------------------
pTwo指向的内存，即pTwo中存储的内存数据中a的值 = 1
pTwo指向的内存，即pTwo中存储的内存数据中b的值 = 2
----------------------------
pt中存储的地址用百分之x打印 = 0
pt中存储的地址用百分之p打印 = (nil)
pt中存储i的地址用百分之x打印 = 0
pt中存储i的地址用百分之p打印 = (nil)
pt中存储c的地址用百分之x打印 = 4
pt中存储c的地址用百分之p打印 = 0x4
pt中存储p的地址用百分之x打印 = 8
pt中存储p的地址用百分之p打印 = 0x8
pt中存储s的地址用百分之x打印 = c
pt中存储s的地址用百分之p打印 = 0xc
--------------------------
thisline = 96df008
thisline->contents = 96df00c
thisline->contents中的内容：aaaaaaaaaa

*/
