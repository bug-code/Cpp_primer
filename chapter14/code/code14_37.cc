#include <vector>
#include <algorithm>
#include <string>
#include <string>
#include <sstream>
#include <iostream>
class isequal //等价于值捕获类型的lambda表达式
{
private:
    std::string s;
public:
    isequal(const std::string& str): s(str){}
    bool operator()(const std::string& str )const{return str==s;}
};
int main(){
    std::string s("hey fuck asshole");
    std::vector<std::string> vecS;
    std::istringstream iss(s);
    std::string tmps;
    while (iss>> tmps)
    {
        vecS.push_back(tmps);
    }
    
    std::replace_if(vecS.begin() , vecS.end() , isequal("fuck"), "duchbag");
    std::for_each(vecS.cbegin() , vecS.cend() , [](const std::string& s){std::cout<<s<<std::endl;});
    return 0;
}