#ifndef BASKET_H
#define BASKET_H
#include "code15_15.h"
#include <memory>
#include <set>
class Basket
{
private:
    static bool compareISBN(const std::shared_ptr<Quote>& lhs , const std::shared_ptr<Quote>& rhs){return lhs->ISBN() < rhs->ISBN();}
    std::multiset<std::shared_ptr<Quote> , decltype(compareISBN)*> basket{compareISBN};
public:
    Basket()=default;
    //添加销售项
    void add_item(const std::shared_ptr<Quote>& sptr){ basket.insert(sptr);}
    //重载add_item函数，接受对象
    void add_item(const Quote& );//拷贝赋值
    void add_item(Quote&&);//移动赋值
    //打印每本书的总价和返回所有书的总价
    double total_prices(std::ostream&)const;
    ~Basket()=default;
};
inline double Basket::total_prices(std::ostream& os=std::cout)const{
    double sum =0.0;
    for (auto iter=basket.cbegin(); iter != basket.cend(); iter=basket.upper_bound(*iter))
    {
        sum+=print_total(os , **iter , basket.count(*iter));
    }
    os<<"Total Sale:"<<sum<<std::endl;
    return sum;
}
inline void Basket::add_item(const Quote& Q){
    basket.insert(std::shared_ptr<Quote>(Q.clone()));
}
inline void Basket::add_item(Quote&& Q){
    basket.insert(std::shared_ptr<Quote>(std::move(Q).clone()));
}

#endif