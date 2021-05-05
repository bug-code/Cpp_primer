#ifndef CODE6_33_H
#define CODE6_33_H
/*递归输出函数*/
#include <vector>
#include <iostream>
#include <cassert>
void recurs_print(std::vector<int>::iterator beg , std::vector<int>::iterator end ){
    assert(end>beg); ///正常end应当大于beg，assert当表达式为假时执行。所以传入正常判断即可
   if (beg!=end)
    {
        #ifndef NODEBUG
        std::cerr<<end-beg<<" ";
        #endif
        std::cout<< *beg <<std::endl;
        recurs_print(++beg , end);
    }    
};
#endif