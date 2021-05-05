#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "F:\\code\\C++_code\\C++ note\\Cpp_primer\\ch7_class\\code\\Sales_data.h"

using std::ifstream;
using std::string;
using std::cout;
using std::vector;
using std::endl;
using std::getline;

int main(int argc , char *argv[]){
    //读取文件名，第二个参数开始
    ifstream ifstrm(argv[1]);
    vector<Sales_data> vec_Sale_data;
    while (ifstrm)
    {
        Sales_data item;
        read(ifstrm , item);
        vec_Sale_data.push_back(item);
    }
    for (const auto &item : vec_Sale_data)
    {
            cout<<item.isbn()<<" sale "<<item.sold_units()<<" units "
            <<" average prince is "<<item.ave_price()<<" revenue is "
            <<item.getRevenue()<<std::endl;
    }
    return 0;
}