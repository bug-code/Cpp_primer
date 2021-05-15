#ifndef COMPARESTR
#define COMPARESTR
#include <string>
using std::string;
/*按字典顺序比较单词大小*/
bool compareStr(const string &s1 , const string  &s2){
    //前提字符串都是小写
    auto s1_beg = s1.cbegin() , s1_end=s2.cend();
    auto s2_beg = s2.cbegin() , s2_end=s2.cend();
    while (s1_beg!=s1_end && s2_beg!=s2_end)
    {
        if (*s1_beg != *s2_beg )
        {
            return *s1_beg < *s2_beg;
        }
        else
        {
            ++s1_beg;
            ++s2_beg;
        }
    }
    return s1.size()<s2.size();
}
#endif