#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>
#include <vector>
class Sales_data
{
    friend std::istream &read(std::istream &is ,  Sales_data &item);
private:    
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;

public:
    std::string isbn() const{ return bookNo;}
    unsigned sold_units()const{return units_sold;}
    double getRevenue()const{return revenue;}

    Sales_data& combine(const Sales_data&);
    double ave_price() const;

    /*构造函数*/
    Sales_data()=default;
    Sales_data(const std::string &s):bookNo(s){}
    Sales_data(const std::string &s , unsigned n , double p):bookNo(s),units_sold(n),revenue(p*n){}
    Sales_data(std::istream &is){
        read(is,*this);
    }
    // Sales_data(){
    //     bookNo= "chris_goudan";
    //     units_sold = 0;
    //     revenue=0.0;
    // }

};

/////////////////////////函数声明/////////////////////
Sales_data add(const Sales_data &lhs ,const Sales_data &rhs );
std::ostream &print(std::ostream &os , const Sales_data &item);
std::istream &read(std::istream &is ,  Sales_data &item);
void print_sale_data(const std::vector<std::vector<Sales_data>> &total_data);
void print_sum( std::ostream &os , const std::vector<std::vector<Sales_data>> &total_data);
const std::vector<std::vector<Sales_data>> &save_sale_info( std::istream &is ,std::vector<std::vector<Sales_data>> &sales_data_total_vec);


/*成员函数*/

/*Sales_data构造函数*/


Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

inline double Sales_data::ave_price() const{
    if (units_sold)
    {
        return revenue/units_sold;
    }
    else
    {
        return 0 ;
    }
}

////////////////////////////////////////////////////////////////*接口，非成员函数*/

/*两项销售数据相加*/
Sales_data add(const Sales_data &lhs ,const Sales_data &rhs ){
    Sales_data total = lhs;
    total.combine(lhs);
    return total;
}
/*数据输出*/
std::ostream &print(std::ostream &os , const Sales_data &item){
    os<<item.isbn()<<" sale "<<item.sold_units()<<" units "
    <<" average prince is "<<item.ave_price()<<" revenue is "<<item.getRevenue()<<std::endl;
    return os;
}
/*读取数据*/
std::istream &read(std::istream &is ,  Sales_data &item){
    double price=0.0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue = item.units_sold*price;
    return is;
}



//输出每个bookNo的销售记录
void print_sale_data(const std::vector<std::vector<Sales_data>> &total_data){
    for (auto &i : total_data)
    {
        auto in_beg = i.begin() , in_end = i.end();
        std::string isbn = (*in_beg).isbn();
        std::cout<< isbn << " have "<<i.size()<<" recodes "<<std::endl;
    }
}

//输出每个isbn的总销售记录
void print_sum( std::ostream &os , const std::vector<std::vector<Sales_data>> &total_data){
    for (auto &i : total_data)
    {
        auto beg = i.begin() , end=i.end();
        Sales_data sum_data_same = *beg;
        ++beg;
        while (beg!=end)
        {
            sum_data_same= add(sum_data_same , *beg);
            ++beg;
        }
        print(os , sum_data_same);
    }
}

//输入并存储销售记录
const std::vector<std::vector<Sales_data>> &save_sale_info( std::istream &is ,std::vector<std::vector<Sales_data>> &sales_data_total_vec) {
    Sales_data data;
    while (read(is , data))
    {
        //判断data是否在sales-data_total_vec内
        bool notin_flag=true;
        auto out_beg = sales_data_total_vec.begin() , out_end=sales_data_total_vec.end();
        while (out_beg != out_end)
        {
            auto in_beg = (*out_beg).begin();
            if ((*in_beg).isbn()==data.isbn())
            {
                (*out_beg).push_back(data);
                notin_flag=false;
            }
            ++out_beg;
        }

        if (notin_flag)
        {
            std::vector<Sales_data> new_sales_data_vec;
            new_sales_data_vec.push_back(data);
            sales_data_total_vec.push_back(new_sales_data_vec);
        }
    }
    return sales_data_total_vec;
}



#endif