#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "Quote.h"
class Bulk_quote : public Quote
{
private:
    size_t min_qty = 0;
    double discount=0.0;
public:
    Bulk_quote()=default;
    
    Bulk_quote(const std::string& boolName , const double& _price ,const size_t& _min_tyq , const double& _discount)
    :Quote(boolName , _price) , min_qty(_min_tyq) , discount(_discount){}

    double net_price(const std::size_t& n)const override final{return n>=min_qty ? n*price*discount : Quote::net_price(n);}
    void debug(std::ostream& os)override final{ Quote::debug(os); os<<" min sold number to discount: "<<min_qty<<" discount rate: "<<discount;}
    ~Bulk_quote()=default;
};
#endif