#ifndef CALL_TIMES_H
#define CALL_TIMES_H
#include <string>
#include <iostream>
int call_times(std::string str){
    static int times=0;
    std::string str1="fuck";
    std::cout<<str1<<" "<<str<<std::endl;
    return times++;
};
#endif