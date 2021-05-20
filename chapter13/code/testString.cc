#include "String.cc"
#include <iostream>
int main(){
    String s;
    char a[]("fuckyou");
    char *aptr = a;
    String s2(aptr);
    s= s2;
    for (auto beg=s.begin() , en=s.end(); beg!=en; ++beg)
    {
        std::cout<<*beg;
    }
    return 0;
}