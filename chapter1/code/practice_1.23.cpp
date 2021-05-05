#include <iostream>
#include "Sales_item.h"
#include <windows.h>

int main(){
    Sales_item cur_item , item ; 
    if (std::cin>> cur_item)
    {
        int cnt = 1;
        while(std::cin >> item)
        {
            if (compareIsbn(cur_item , item))
            {
                ++cnt;
            }
            else
            {
                std::cout<< cur_item.isbn() << "\40ocurr\40" << cnt <<"\40times"<<std::endl;
                cur_item = item;
                cnt=1;
            }     
        }
        std::cout<< cur_item.isbn() << "\40ocurr\40" << cnt <<"\40times"<<std::endl;
        system("pause");
    }
    
}