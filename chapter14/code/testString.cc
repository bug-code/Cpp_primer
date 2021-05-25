#include "String.cc"
int main(){
    String s1("fuck") , s2("you");
    auto s3=s1+s2;
    std::cout<< s3<<std::endl; 
    return 0;
}