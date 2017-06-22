#include <stdio.h>
#include <map>
#include <stdint.h>
#include <ext/hash_map>
#include <iostream>

#include "mapkey64int.h"

using namespace __gnu_cxx;
using namespace std;

typedef hash_map<u_int64_t, int> MAPINT64;

void Director(const MAPINT64 &hashmapTest)
{
    MAPINT64::const_iterator ite;

    for(ite = hashmapTest.begin(); ite != hashmapTest.end(); ite++)
    {
        printf("--Director--key = %010lld----%llx, value=%d\n", ite->first, ite->first, ite->second);
    }

}

int main()
{
    printf("sizeof(long long)=%d, sizeof(long)=%d\n", sizeof(long long), sizeof(long));


    size_t test1 = 0x33445566;
    size_t test2 = 0x77889900;

    printf("sizeof(size_t) = %d, yihuo wei = %0x,%d\n", sizeof(size_t), test1^test2, test1^test2);

    test1 = 0x77889900;
    test2 = 0x33445566;

    printf("sizeof(size_t) = %d, yihuo wei = %0x,%d\n", sizeof(size_t), test1^test2, test1^test2);


    printf("sizeof int64_t = %d\n", sizeof(u_int64_t));

    MAPINT64 mapTest;

    mapTest.insert(make_pair(0x0000000000000011, 0));
    mapTest.insert(make_pair(0x1122334455667788, 1));
    mapTest.insert(make_pair(0x2233445566778899, 2));
    mapTest.insert(make_pair(0x3344556677889900, 3));
    mapTest.insert(make_pair(0x7788990033445566, 4));
    mapTest.insert(make_pair(0xFFFFFFF0FFFFFFFF, 5));
    mapTest.insert(make_pair(0xFFFFFFFFFFFFFFF0, 6));

    MAPINT64::iterator ite;
    ite = mapTest.find(0xFFFFFFF0FFFFFFFF);
    if(ite != mapTest.end())
    {
        printf("find1()---%llx----key=%lld-->value=%d\n", ite->first, ite->first, ite->second);
    }
    else
    {
        printf("----------------------------not find key\n");
    }


    ite = mapTest.find(0xFFFFFFFFFFFFFFF0);
    if(ite != mapTest.end())
    {
        printf("find2()---%llx----key=%lld-->value=%d\n", ite->first, ite->first, ite->second);
    }
    else
    {
        printf("----------------------------not find key\n");
    }

    Director(mapTest);

    hash_map<string,int> test;
    test["abc"] = 1;
    string strtest = "aaa";
    test[strtest] = 2;
    cout << test["abc"] << endl;
    cout << test["aaa"] << endl;

    return 0;
}
