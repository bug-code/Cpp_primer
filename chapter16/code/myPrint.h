#ifndef MYPRINT_H
#define MYPRINT_H
#include <iostream>
template<typename T , unsigned U> void myprint(const T  (&arr)[U]){
    for (auto &&i : arr)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
#endif