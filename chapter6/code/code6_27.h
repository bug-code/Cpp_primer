#ifndef CODE6_27_H
#define CODE6_27_H

#include <initializer_list>
int add_param_list(std::initializer_list<int> int_list){
    int sum=0;
    for (const auto &i : int_list)
    {
        sum += i;
    }
    return sum;
};
#endif