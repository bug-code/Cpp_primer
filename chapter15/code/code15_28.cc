#include "code15_15.h"
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
int main(){
    std::vector<std::shared_ptr<Quote>> basket;
    //Quote对象
    basket.push_back(std::make_shared<Quote>("fuck" , 15));
    basket.push_back(std::make_shared<Disc_quote>("you" , 15 , 10 , 0.75));
    basket.push_back(std::make_shared<Bulk_quote>("asshole" , 15 , 10 , 0.75));
    std::for_each(basket.cbegin() , basket.cend() , [](const std::shared_ptr<Quote>& Qptr){std::cout<<Qptr->net_price(20)<<std::endl;});
    return 0;
}