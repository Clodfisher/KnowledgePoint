#include <stdio.h>
#include <ext/hash_map>
#include <string>
//#include <map>

using namespace __gnu_cxx;
using namespace std;

typedef hash_map<string, int> HASHMAP;
//typedef map<string, int> HASHMAP;

void Director(const HASHMAP &hashmapTest)
{
    HASHMAP::const_iterator ite;

    for(ite = hashmapTest.begin(); ite != hashmapTest.end(); ite++)
    {
        printf("----key = %s, value=%d\n", ite->first.c_str(), ite->second);
    }

}

int main()
{
    HASHMAP hashTest;
    string str1 = "0";
    string str2 = "1";
    string str3 = "2";


    int i = 0;
    hashTest.insert(make_pair(str1, i));
    hashTest.insert(make_pair(str2, i+1));
    hashTest.insert(make_pair(str3, i+2));


    Director(hashTest);

    return 0;

}
