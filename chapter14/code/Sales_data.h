#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Sales_data
{
    friend istream& read(istream &is ,  Sales_data &item);
    friend istream& operator>>(istream &is , Sales_data &item); 
    friend ostream& operator<<(ostream &os , Sales_data &item);
    friend Sales_data operator+(const Sales_data&  , const Sales_data&); 
    /*练习14.6*/
    friend bool operator==(const Sales_data&  , const Sales_data&);
    friend bool operator!=(const Sales_data&  , const Sales_data&);
private:    
    string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;

public:
    string isbn() const{ return bookNo;}
    void setisbn(const string &s){ bookNo = s;}
    unsigned sold_units()const{return units_sold;}
    void setsSold_units(const unsigned &u){ units_sold = u;}
    double getRevenue()const{return revenue;}
    void setRevenue(const double &d){revenue=d;}

    /*赋值运算符*/ 
    Sales_data& operator=(const Sales_data&);  
    /*string类型赋值运算符*/
    Sales_data& operator=(const string&);
    /*重载复合加法赋值运算符*/
    Sales_data& operator+=(const Sales_data&);
    Sales_data& combine(const Sales_data&);
    double ave_price() const;

    /*构造函数*/
    Sales_data()=default;
    Sales_data(const string &s):bookNo(s){}
    //类类型转换运算符 , 练习14.45
    explicit operator string()const{return bookNo;}
    explicit operator unsigned()const{return units_sold;}
    Sales_data(const string &s , unsigned n , double p):bookNo(s),units_sold(n),revenue(p*n){}
    explicit Sales_data(istream &is){
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
ostream &print(ostream &os , const Sales_data &item);
istream &read(istream &is ,  Sales_data &item);
void print_sale_data(const vector<vector<Sales_data>> &total_data);
void print_sum( ostream &os , const vector<vector<Sales_data>> &total_data);
const vector<vector<Sales_data>> &save_sale_info( istream &is ,vector<vector<Sales_data>> &sales_data_total_vec);


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
/*重载加法运算符，左值*/
Sales_data operator+(const  Sales_data& lhs  ,const Sales_data& rhs){
    Sales_data  tmp = lhs;
    if (lhs.bookNo == rhs.bookNo )
    {
        tmp.units_sold +=rhs.units_sold;
        tmp.revenue += rhs.revenue;
    }
    else
    {
        cerr<<"bookNo is different"<<endl;
        //报错，抛出异常
    }
    return tmp;
}

/*相等判断符*/
bool operator==(const Sales_data& lhs , const Sales_data& rhs){
    return lhs.bookNo==rhs.bookNo && lhs.units_sold==rhs.units_sold && lhs.revenue==rhs.revenue;
}
/*不等判断符*/
bool operator!=(const Sales_data& lhs , const Sales_data& rhs){
    return !operator==(lhs , rhs);
}


/*重载赋值运算符*/
Sales_data& Sales_data::operator=(const Sales_data& data){
    bookNo = data.bookNo;
    units_sold = data.units_sold;
    revenue = data.revenue;
    return *this;
}
/*string类型赋值运算符*/
Sales_data& Sales_data::operator=(const string& s){
    bookNo = s;
    units_sold=0;
    revenue=0.0;
    return *this;
}


/*重载复合加法运算符*/
Sales_data& Sales_data::operator+=(const Sales_data& data){
    *this = *this+data;
    return *this;
}

/*重载输入>>运算符 练习14.9*/
istream& operator>>(istream &is , Sales_data &item){
    double price;
    is>>item.bookNo>>item.units_sold>>price;
    if (is)
    {
        item.revenue = item.units_sold*price;
    }
    else
    {
        item = Sales_data();
    }
    return is;
}

/*重载输出运算符<< 练习14.6*/
ostream& operator<<(ostream &os , Sales_data &item){
    os<<item.isbn()<<" sale "<<item.sold_units()<<" units "
    <<" average prince is "<<item.ave_price()<<" revenue is "<<item.getRevenue();
    return os;
}

/*数据输出*/
ostream &print(ostream &os , const Sales_data &item){
    os<<item.isbn()<<" sale "<<item.sold_units()<<" units "
    <<" average prince is "<<item.ave_price()<<" revenue is "<<item.getRevenue()<<endl;
    return os;
}
/*读取数据*/
istream &read(istream &is ,  Sales_data &item){
    double price=0.0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue = item.units_sold*price;
    return is;
}



//输出每个bookNo的销售记录
void print_sale_data(const vector<vector<Sales_data>> &total_data){
    for (auto &i : total_data)
    {
        auto in_beg = i.begin() , in_end = i.end();
        string isbn = (*in_beg).isbn();
        cout<< isbn << " have "<<i.size()<<" recodes "<<endl;
    }
}

//输出每个isbn的总销售记录
void print_sum( ostream &os , const vector<vector<Sales_data>> &total_data){
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
const vector<vector<Sales_data>> &save_sale_info( istream &is ,vector<vector<Sales_data>> &sales_data_total_vec) {
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
            vector<Sales_data> new_sales_data_vec;
            new_sales_data_vec.push_back(data);
            sales_data_total_vec.push_back(new_sales_data_vec);
        }
    }
    return sales_data_total_vec;
}



#endif