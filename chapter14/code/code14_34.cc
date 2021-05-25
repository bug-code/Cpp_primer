#include <string>
#include <iostream>
class If_Then_Else 
{
private:
public:
    std::string operator()(const int& i ,const std::string& s1 , const std::string& s2 ){return i ? s1: s2;}
};

int main(){
    If_Then_Else ite;
    std::cout<< ite(1 , "fuck" , "you")<<std::endl;
    return 0;
}
