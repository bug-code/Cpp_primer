#include <iostream>
#include "Sales_item.h"
#include "windows.h"

int main(){
    Sales_item sum_items , item;
    while (std::cin >> item )
    {        
        sum_items =sum_items+ item;
    }
    std::cout<<"sum of items:\40"<<sum_items << std::endl;
    system("pause");
}