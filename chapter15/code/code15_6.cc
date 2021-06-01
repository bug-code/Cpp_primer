// #include "Bulk_quote.h"
#include "code15_15.h"
#include "code15_7.h"
int main(){
    // Quote quo("fire" , 11);
    Bulk_quote blkq("fuck" , 12 , 10 , 0.7);
    // Limit_discount Ldis("you" , 16 , 14 , 0.6);
    // print_total(std::cout , quo , 10);
    // print_total(std::cout , blkq , 11) ; 
    // print_total(std::cout , Ldis , 20);
    // quo.debug(std::cout);
    // std::cout<<std::endl;
    // blkq.debug(std::cout);
    // std::cout<<std::endl; 
    // Ldis.debug(std::cout);
    std::cout<<std::endl;

    /*练习15.26*/
    Bulk_quote blkq1;
    blkq1 = blkq;

    Bulk_quote blkq2(blkq);
    
    Bulk_quote blkq3;
    blkq3 = std::move(blkq);
    
    Bulk_quote blkq4(std::move(blkq));
    return 0;
}