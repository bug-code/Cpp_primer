#ifndef CODE6_51_H
#define CODE6_51_H
#include <iostream>
void f(){
    #ifndef NODEBUG
    std::cerr<<"The function is:"<<1<<std::endl;
    #endif
};
void f(int ){
    #ifndef NODEBUG
    std::cerr<<"The function is:"<<2<<std::endl;
    #endif
};

void f(int ,int ){
    #ifndef NODEBUG
    std::cerr<<"The function is:"<<3<<std::endl;
    #endif
};

void f(double ,double =3.14){
    #ifndef NODEBUG
    std::cerr<<"The function is:"<<4<<std::endl;
    #endif
};


#endif
