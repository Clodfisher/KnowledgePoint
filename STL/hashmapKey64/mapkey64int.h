#include <stdio.h>
#include <stdint.h>
#include <ext/hash_map>
#include <string>

namespace __gnu_cxx
{
template<>
struct hash<long long>
{
    size_t operator()(long long __x) const
    {
        if (sizeof(__x) == sizeof(size_t))
            return __x;
        else
        {
            size_t nRec = (__x >> 32) ^ (__x & 0xFFFFFFFF);
            printf("hash value-------=%d\n", nRec);
            return nRec;
        }
    }
};

template<>
struct hash<unsigned long long>
{
    size_t operator()(unsigned long long __x) const
    {
        if (sizeof(__x) == sizeof(size_t))
            return __x;
        else
        {
            size_t nRec = (__x >> 32) ^ (__x & 0xFFFFFFFF);
            printf("hash value----unsigned--=%d\n", nRec);
            return nRec;
        }
    }
};

template<typename Traits, typename Allocator>
struct hash<std::basic_string<char, Traits, Allocator> >
{
    size_t operator()(const std::basic_string<char, Traits, Allocator>& __s) const
    {
        return __stl_hash_string(__s.c_str());
    }
};

}
