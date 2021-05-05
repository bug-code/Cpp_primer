#ifndef CODE6_23_H
#define CODE6_23_H
#include <iostream>
void my_print(const int &val, const int *beg , const int *end){
    std::cout<<val<<std::endl;
    while (beg!=end)
        std::cout<<*beg++<<" "; 
    std::cout<<std::endl; 
};
#endif