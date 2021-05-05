#ifndef INTERACT_FACT_H
#define INTERACT_FACT_H
#include <iostream>
#include <F:/code/C++_code/C++ note/Cpp_primer/chapter6/code/fact.h>
void interact_fact(){
    int input=0;
    while (input>=0)
    {
        std::cin>>input;
        if (input<0)
        {
            std::cout<<"number must => 0!!"<<std::endl;
            input=0;
        }
        else
        {
            int result = fact(input);
            std::cout<< result<<std::endl;
            break;       
        }
        
    }
};
#endif