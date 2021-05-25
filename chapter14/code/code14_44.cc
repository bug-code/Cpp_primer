#include <functional>
#include <map>
#include <string>
#include <iostream>
int main(){
    std::function<int (int,int)> f1= std::plus<int>();
    std::function<int (int,int)> f2= std::minus<int>();
    std::function<int (int,int)> f3= std::multiplies<int>(); 
    std::function<int (int,int)> f4= std::divides<int>();
    std::map<std::string , std::function<int (int,int)>> comp{
        {"+",f1},
        {"-",f2},
        {"*",f3},
        {"/" ,f4}
    };
    std::cout<<comp["/"](4,2)<<std::endl;
    return 0;
}