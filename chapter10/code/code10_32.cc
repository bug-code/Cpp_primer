#include <fstream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include "Sales_data.h"
using namespace std;

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

int main(){
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter10\\code\\sale_his.txt");
    ifstream ifs(fileName);
    vector<Sales_data> vec;
    if (ifs)
    {
        istream_iterator<Sales_data> in_saleDate(ifs) , eof_saleData;
        vec.assign(in_saleDate , eof_saleData);//需重载>>运算符
        sort(vec.begin() , vec.end() , compareIsbn);
        for (auto vecBeg = vec.cbegin() , vecEnd=vec.cend() , partEnd = vecBeg; vecBeg!=vecEnd ;   vecBeg =partEnd )
        {
            partEnd = find_if(vecBeg , vecEnd , [vecBeg](const Sales_data &data){return (*vecBeg).isbn() != data.isbn(); });
            cout<<(*vecBeg).isbn()<<" revenue: "<< accumulate(vecBeg , partEnd , 0.0 ,[](double a , const Sales_data &data2){return a+data2.getRevenue();} )<<endl;
        }
    }
    else
    {
        cerr<<"open file failed!"<<endl;
    }
    
    return 0 ;
}