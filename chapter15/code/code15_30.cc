#include "code15_15.h"
#include "Basket.h"
#include <iostream>
int main(){
    Quote Q("fuck" , 15);
    Disc_quote D("you" , 15 , 10 , 0.75);
    Bulk_quote B("asshole" , 15 , 10 , 0.75);
    Basket bskt;
    for (size_t i = 0; i < 15; i++)
    {
        bskt.add_item(Q);
    }
    for (size_t i = 0; i < 15; i++)
    {
        bskt.add_item(D);        
    }
    for (size_t i = 0; i < 15; i++)
    {
        bskt.add_item(B);
    }    
    std::cout<<bskt.total_prices()<<std::endl;
    return 0;
}