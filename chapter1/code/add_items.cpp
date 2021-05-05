#include <iostream>
#include "Sales_item.h"
#include "windows.h"
int main(){
    Sales_item item1 , item2;
    std::cin >> item1 >>item2 ; 
    /*两条销售条目相加只是简单显示销售金额 销售均价*/
    std::cout<<item1+item2<<std::endl;
    system("pause");
    return 0;
}