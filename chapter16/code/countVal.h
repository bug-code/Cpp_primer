#ifndef COUNTVAL_H
#define COUNTVAL_H
#include <vector>
#include <string.h>
template<typename T , typename U> size_t countVal(const std::vector<T>& vec , const U& u){
    size_t cnt = 0;
    for (auto &&i : vec)
    {
        if (i==u)
            ++cnt;
    }
    return cnt;
}
template<> size_t countVal(const std::vector<const char*>& vec , const char* const &p){
    size_t cnt = 0;
    for (auto &&i : vec)
    {
        if (!(strcasecmp(i , p)))
            ++cnt;
    }
    return cnt;
}
#endif