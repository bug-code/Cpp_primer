#include <iostream>
using std::cout;
using std::endl;

int main(){
    int i  = 10;
    auto f=[&i]()->bool{if(i!=0) {--i ; return false;} else return true; };
    for (size_t i = 0; i < 11; i++)
    {
        cout<<f()<<" "<<i<<endl;
    }
    
    return 0;
}