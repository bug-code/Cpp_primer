#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <iostream>
#include <functional>
#define NODEBUG
class Quote
{
    friend bool operator!=(const Quote& lhs , const Quote& rhs);
private:
    std::string bookNo;
protected:
    double price=0.0;
public:
    Quote()=default;
    Quote(const std::string& bookName , const double& _price ):bookNo(bookName) , price(_price){};
    /*拷贝构造函数*/
    Quote(const Quote& Q):bookNo(Q.bookNo) , price(Q.price){
        #ifndef NODEBUG
        std::cout<<"Quote 拷贝构造函数"<<std::endl;
        #endif
    }
    /*移动构造函数*/
    Quote(Quote&& Q) noexcept :bookNo(std::move(Q.bookNo)) , price(std::move(Q.price)){
        #ifndef NODEBUG
        std::cout<<"Quote 移动构造函数"<<std::endl;
        #endif
    }
    /*拷贝赋值运算符*/
    Quote& operator=(const Quote& Q){
        /*赋值运算符一定要处理自赋值问题*/
        if (Q!=*this)
        {
            bookNo=Q.bookNo;
            price = Q.price;
        }
        #ifndef NODEBUG
        std::cout<<"Quote 拷贝赋值运算符"<<std::endl;
        #endif
        return *this;
    }
    /*移动赋值运算符*/
    Quote& operator=(Quote&& Q) noexcept {
        if (Q !=*this)
        {
            bookNo=std::move(Q.bookNo);
            price=std::move(Q.price);
        }
        #ifndef NODEBUG
        std::cout<<"Quote 移动赋值运算符"<<std::endl;
        #endif
        return *this;
    }
    std::string  ISBN()const{return bookNo;}
    virtual double net_price(const size_t& n)const{return n*price;}
    virtual void debug(std::ostream& os);
    virtual Quote* clone()const &{return new Quote(*this);}
    virtual Quote* clone()&&{return new Quote(std::move(*this)); }
    ~Quote()=default;
};

inline bool operator!=(const Quote& lhs , const Quote& rhs){
    return lhs.bookNo!=rhs.bookNo && lhs.price!=rhs.price; 
}

inline void Quote::debug(std::ostream& os){
    os<<"ISBN： "<<bookNo<<" price:"<<price;
}

inline double print_total(std::ostream& os ,const Quote& quote , const size_t& n ){
    auto total_price = quote.net_price(n);
    os<<"ISBN："<<quote.ISBN()<<" # sold: "<<n<<" total price: "<<total_price<<std::endl;
    return total_price;
}
#endif
