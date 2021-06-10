#include <iostream>
#include "Sales_data.h"
#include "hash_saledata.h"
#include <unordered_set>
#include <fstream>
#include <string>
#include <iterator>
int main(){
    unordered_multiset<Sales_data> SDset;
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter16\\code\\sale_his.txt");
    ifstream ifs(fileName);
    Sales_data data;
    while (ifs>>data)
    {
        SDset.insert(data);
    }
    for(auto beg=SDset.cbegin() , en = SDset.cend(); beg!=en ; ++beg){

        // cout << *beg<<endl;
        print(cout , *beg);
    }
    return 0;
}