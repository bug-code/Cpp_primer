#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H
#include "Quote.h"
class Disc_quote : public Quote
{
    friend bool operator!=(const Disc_quote&  , const Disc_quote&);
protected:
    size_t quantity=0;
    double discount=0.0;
public:
    Disc_quote()=default;
    Disc_quote(const std::string& _bookNo , const double& _price , const size_t& sz , const double& _discount)
    :Quote(_bookNo , _price),quantity(sz),discount(_discount){}
    /*拷贝构造函数*/
    Disc_quote(const Disc_quote& D);
    /*移动构造函数*/
    Disc_quote(Disc_quote&& D)noexcept;
    /*拷贝赋值运算符*/
    Disc_quote& operator=(const Disc_quote& D);
    /*移动赋值运算符*/
    Disc_quote& operator=(Disc_quote&& D) noexcept;
    virtual double net_price(const size_t& n)const override{return n>quantity ? n*price*discount : n*price;}
    virtual void debug(std::ostream& os)override{Quote::debug(os);os<<" quantity: "<<quantity<<" discount:"<<discount;}
    virtual Disc_quote* clone()const & override{ return new Disc_quote(*this); }
    virtual Disc_quote* clone() && override {return new Disc_quote(std::move(*this));}
    ~Disc_quote()=default;
};


bool operator!=(const Disc_quote& lhs , const Disc_quote& rhs){
    return Quote(lhs)!=Quote(rhs) && lhs.price!=rhs.price&& lhs.quantity!=rhs.quantity&& lhs.discount!=rhs.discount;
}

/*拷贝构造函数*/
inline Disc_quote::Disc_quote(const Disc_quote& D):Quote(D) , quantity(D.quantity), discount(D.discount){
    #ifndef NODEBUG
    std::cout<<"disc_quote 拷贝构造函数"<<std::endl;
    #endif
}
/*移动构造函数*/
inline Disc_quote::Disc_quote(Disc_quote&& D) noexcept :Quote(std::move(D)),quantity(std::move(D.quantity)),discount(std::move(D.discount)) {
    #ifndef NODEBUG
    std::cout<<"disc_quote 移动构造函数"<<std::endl;
    #endif
}
/*拷贝赋值运算符*/
inline Disc_quote& Disc_quote::operator=(const Disc_quote& D){
    if (D!=*this)
    {
        Quote::operator=(D);
        quantity = D.quantity;
        discount=D.discount;
    }
    #ifndef NODEBUG
    std::cout<<"Disc_quote拷贝赋值运算符"<<std::endl;
    #endif
    return *this;
}
/*移动赋值运算符*/
inline Disc_quote& Disc_quote::operator=(Disc_quote&& D) noexcept {
    if (D!=*this)
    {
        Quote::operator=(std::move(D));
        quantity = std::move(D.quantity);
        discount=std::move(D.discount);
    }
    #ifndef NODEBUG
        std::cout<<"Disc_quote移动赋值运算符"<<std::endl;
    #endif
    return *this;
}

#endif