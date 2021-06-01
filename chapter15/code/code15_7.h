#ifndef LIMIT_DISCOUNT_H
#define LIMIT_DISCOUNT_H
#include "Disc_quote.h"
class Limit_discount : public Disc_quote
{
public:
    Limit_discount()=default;
    
    Limit_discount(const std::string& bookName , const double& _price , const size_t& _limit_sold , const double& _limit_discount )
    :Disc_quote(bookName , _price ,_limit_sold , _limit_discount ){}

    double net_price(const size_t& sz)const override final
    {
        return sz>quantity ? quantity*price*discount+(sz-quantity)*price : sz*price*discount; 
    }
    void debug(std::ostream& os)override final{ 
        Quote::debug(os); 
        os<<" limit sold number: "<<quantity<<" limit discount: "<<discount;
    }
    ~Limit_discount()=default;
};
#endif