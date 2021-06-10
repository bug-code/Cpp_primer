#include <iostream>
#include <string>
template<typename T> std::ostream& print(std::ostream &os , const T& t){
   return os<<t<<std::endl;
}
template<typename T , typename... Args> std::ostream& print(std::ostream &os , const T& t , const Args& ... rest){
    os<<t<<" , ";
    return print(os , rest...);
}
class myclass{
    int i;
    public:
        myclass(const int& v):i(v){}
};
int main(){
    print(std::cout , "fuck" , std::string("you") , 11 , 14.23 , 'f' , myclass(0) );
    return 0;
}