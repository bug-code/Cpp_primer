#include <iostream>
#include <string>
template<typename T , typename ... Args> void foo(const T& t , Args ... args ){
    std::cout<<sizeof...(Args)+1<<" ";
    std::cout<<sizeof...(args)<<std::endl;
}
int main(){
    int i=0;
    double d=1.2;
    std::string s="fuck you ";
    foo(i , s, 42 , d);
    foo(s,42,"mother fucker");
    foo(d,s);
    foo("fuck");
    return 0;    
}