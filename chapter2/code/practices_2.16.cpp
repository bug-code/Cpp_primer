#include <iostream>
#include <windows.h>

int main(){

    // int i=0, &refi=i;
    // double d=3.1,&refd=d;
    // refd = refi;
    // std::cout<< refd<<std::endl;
    // i = refd;
    // std::cout<< i<<std::endl;
    // refi=d;
    // std::cout<< refi<<std::endl;
    // double D=3.14;
    // int i=0;
    // int &refD = i;
    // refD=D;
    // std::cout<< refD<<std::endl;

    // 指向引用的指针
    int i=10 , &refi = i;
    double j = 3.14 ; 
    int *pti = &j;
    std::cout<< pti<<std::endl;
    // system('pause');
    return 0;
}