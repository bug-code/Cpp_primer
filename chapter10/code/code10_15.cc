#include <iostream>
using std::cout;
using std::endl;

int main(){
    /*练习10.14*/
    auto f1 = [](const int &i1 , const int &i2 ){ return i1+i2; };
    cout<<f1(1,1)<<endl;
    /*练习10.15*/
    int i1 = 1;
    auto f2 = [i1](const int &i2){ return i1+i2;};
    cout<<f2(1)<<endl;
}