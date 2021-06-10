#include <iostream>
#include "debug_rep.h"
/*声明*/
template<typename T> std::ostream& print(std::ostream &os , const T& t);
template<typename T , typename... Args> std::ostream& print(std::ostream &os , const T& t , const Args& ... rest);
template<typename ... Args> std::ostream& errorMSG(std::ostream& os , const Args& ... rest);


/*定义*/
template<typename T> std::ostream& print(std::ostream &os , const T& t){
   return os<<t<<std::endl;
}
template<typename T , typename... Args> std::ostream& print(std::ostream &os , const T& t , const Args& ... rest){
    os<<t<<" ";
    return print(os , rest...);
}
template<typename ... Args> std::ostream& errorMSG(std::ostream& os , const Args& ... rest){
    return print(os,debug_rep(rest) ... );
}

int main(){
    errorMSG(std::cout , 1223 , "fuck" , 12.343 , 'f');
    return 0;
}