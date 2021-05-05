#include "Sales_data.h"
#include <vector>
#include <iostream>
int main(){
    std::vector<std::vector<Sales_data>> sales_data_total_vec;
    save_sale_info( std::cin, sales_data_total_vec);
    print_sale_data(sales_data_total_vec);
    print_sum(std::cout,sales_data_total_vec);

    //练习7.11
    //默认构造函数
    // Sales_data item1;
    // print(std::cout,item1);
    // //初始化bookNo构造函数
    // Sales_data item2("chris_goudan");
    // print(std::cout,item2);
    // //初始化所有值
    // Sales_data item3("chris_goudan" , 233 , 9.9);
    // print(std::cout,item3);
    // Sales_data item4(std::cin);
    // print(std::cout, item4);
    return 0;
}