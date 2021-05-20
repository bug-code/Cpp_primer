#include <iostream>
#include "StrVec.cc"
class test
{
private:
    int i;
public:
    test(const int v=0 ):i(v){}
    test(const test& T):i(T.i){
        std::cout<<"拷贝构造函数"<<std::endl;}
    test& operator=(const test& T){
        i = T.i;
        std::cout<<"赋值运算符"<<std::endl;
        return *this;
    }
};



int main(){
    // int v1 = 1,  v2=2;
    // int *a = &v1;
    // int *b= &v2;
    // std::swap(a,b);
    // std::cout<<*a<<" "<<*b;

    // test a(1) , b(a);
    StrVec a  , a1;
    std::string s("fuck") , s1("you");
    a.push_back(s);
    a1=a;
    *a.begin()=s1;
    std::cout<<*a.begin()<<std::endl;
    a1.push_back(s1);
    auto s2 = *(a1.cbegin()+1);
    std::cout<<*a1.begin()<<s2<<std::endl;

    return 0;
}