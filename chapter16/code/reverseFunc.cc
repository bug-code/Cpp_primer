#include <iostream>
template<typename F , typename T1 , typename T2> auto reveFunc(F f , T1 &&t1 , T2 &&t2)->decltype(*f) {
    f(std::forward<T2>(t2) , std::forward<T1>(t1));
} 
template<typename T> bool less(const T &t1 ,const T &t2){
    return t1<t2 ? true : false;
}

int main(){
    bool (*p)(const int & ,const int&) = less;
    // int i1 = 21 , i2 = 14;
    std::cout<< p(21  , 14)<<std::endl;
    std::cout << reveFunc(p , 21 , 14)<<std::endl;
    return 0;
}