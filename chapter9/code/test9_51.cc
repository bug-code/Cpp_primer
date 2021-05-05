#include "date.cc"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
void printDate(const date &dat){
    auto y =dat.getYear();
    auto  m= dat.getMonth();
    auto d = dat.getDay();
    cout<< y <<" 年 "<< m <<" 月 "<< d <<" 日 "<<endl;
}

int main(){
    date date0("January 12, 1900");
    date date1("1/12/1900");
    date date2("Jan 12 1900");
    printDate(date0);
    printDate(date1);
    printDate(date2);
    return 0;
}