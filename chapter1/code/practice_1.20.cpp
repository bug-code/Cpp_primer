#include <iostream>
#include "Sales_item.h"
#include <windows.h>

int main(){
    Sales_item item;
    while (std::cin>>item)
    {
        std::cout<< "out:"<<item<<std::endl;
    }
    
}