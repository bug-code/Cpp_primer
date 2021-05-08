#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Sales_data.h"
using std::string;
using std::vector;
using std::ifstream;
using std::stable_sort;

/*输入sale_data,并存储为vector*/
void saveDateToVec(vector<Sales_data> &vecSale , const string &fileName){
    ifstream ifs(fileName);
    if (ifs)
    {   
        Sales_data data;
        while (read(ifs ,data ))
        {
            vecSale.push_back(data);
        }
        
    }
    else
    {
        std::cerr<<"open file failed"<<std::endl;
    }
}

/*比较Sales_data对象isbn*/
bool compareIsbn(const Sales_data &data1 , const Sales_data &data2){
    auto isbn1 = data1.isbn() , isbn2 = data2.isbn();
    auto beg_isbn1 = 0 , beg_isbn2 = 0;
    auto symbolMark1 = isbn1.find('-'), symbolMark2=isbn2.find('-');
    while (true)
    {
        int number1 = std::stoi( isbn1.substr(beg_isbn1 , symbolMark1-beg_isbn1) ) , 
            number2 = std::stoi(isbn2.substr(beg_isbn2 , symbolMark2-beg_isbn2));
        if (number1 == number2 )
        {
            beg_isbn1 = symbolMark1+1;
            if (beg_isbn1 == isbn1.size()-1 || beg_isbn2 == isbn2.size()-1 )
            {
                return isbn1[beg_isbn1] < isbn2[beg_isbn2];
            }
            symbolMark1 = isbn1.find('-' , beg_isbn1);
            beg_isbn2 = symbolMark2+1;
            symbolMark2 = isbn2.find('-' , beg_isbn2);
        }
        else
        {
            return number1 < number2 ;
        }
    }
}
/*查看容器元素isbn*/
void printIsbn(const vector<Sales_data> &vec ){
    for (auto &i : vec)
    {
        std::cout<< i.isbn()<<std::endl;
    }
}


/*测试*/
int main(){
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter10\\code\\sale_his.txt");
    vector<Sales_data> vecSale;
    saveDateToVec(vecSale , fileName);
    stable_sort(vecSale.begin() , vecSale.end() , compareIsbn);
    printIsbn(vecSale);
    return 0;
}

