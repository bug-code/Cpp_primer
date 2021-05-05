#include <iostream>
#include "Sales_data.h"
#include "windows.h"
int main(){
    //读取两组销售记录
    Sales_Data data1 , data2;
    std::cin>>data1.bookNo>>data2.bookNo ;
    std::cout<<data1.bookNo<<data2.bookNo<<std::endl;
    if (data1.bookNo==data2.bookNo)
    {
        std::cout<<"its the same!!"<<std::endl;
    }
    system("pause");
}
