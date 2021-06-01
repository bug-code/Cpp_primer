#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "Disc_quote.h"
class Bulk_quote : public Disc_quote
{
    friend bool operator!=(const Bulk_quote& , const Bulk_quote&);
    friend bool operator!=(const Disc_quote&  , const Disc_quote&);
public:

    Bulk_quote()=default;
    //继承Disc_quote的构造函数，默认、拷贝、移动构造函数除外
    using Disc_quote::Disc_quote;//练习15.27 ， 与下面一条等价
    
    // Bulk_quote(const std::string& boolName , const double& _price ,const size_t& _min_tyq , const double& _discount)
    // :Disc_quote(boolName ,_price , _min_tyq , _discount ){}

    /*拷贝构造函数*/
    Bulk_quote(const Bulk_quote& B):Disc_quote(B){
        #ifndef NODEBUG
        std::cout<<"Bulk_quote拷贝构造函数"<<std::endl;
        #endif
    }
    /*移动构造函数*/
    Bulk_quote(Bulk_quote&& B) noexcept :Disc_quote(std::move(B)){
        #ifndef NODEBUG
        std::cout<<"Bulk_quote移动构造函数"<<std::endl;
        #endif
    }
    /*拷贝赋值运算符*/
    Bulk_quote& operator=(const Bulk_quote& );
    /*移动赋值运算符*/
    Bulk_quote& operator=(Bulk_quote&& ) noexcept;
    double net_price(const std::size_t& n)const override final{
        return n>=quantity ? quantity*price*discount+(n-quantity)*price : Quote::net_price(n);
    }
    void debug(std::ostream& os)override final{ 
        Quote::debug(os);
        #ifndef NODEBUG 
        os<<" min sold number to discount: "<<quantity<<" discount rate: "<<discount;
        #endif
    }
    Bulk_quote* clone()const & override final {return new Bulk_quote(*this);}
    Bulk_quote* clone()&& override final {return new Bulk_quote(std::move(*this));}
    ~Bulk_quote()=default;
};
bool operator!=(const Bulk_quote& rhs, const Bulk_quote& lhs){
    return Disc_quote(rhs) != Disc_quote(lhs);
}

/*拷贝赋值运算符*/
Bulk_quote& Bulk_quote::operator=(const Bulk_quote& B){
    if (B!=*this)
    {
        Disc_quote::operator=(B);
    }    
    #ifndef NODEBUG
    std::cout<<"Bulk_quote拷贝赋值运算符"<<std::endl;
    #endif
    return *this;
}
/*移动赋值运算符*/
Bulk_quote& Bulk_quote::operator=(Bulk_quote&& B) noexcept {
    if (B!=*this)
    {
        Disc_quote::operator=(std::move(B));
    }    
    #ifndef NODEBUG
    std::cout<<"Bulk_quote移动赋值运算符"<<std::endl;
    #endif
    return *this;
}

#endif