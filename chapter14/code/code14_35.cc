#include <iostream>
#include <string>
#include <fstream>
#include <vector>
class PrintString
{
private:
    std::istream &is;
    char sep;
public:
    PrintString(std::istream& in=std::cin , char s='\n' ):is(in) ,sep(s){}
    std::string operator()(){
        std::string s;
        return std::getline(is , s) ? s:"";        
    }
    PrintString();
};
int main(){
    std::string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter14\\code\\hundredMiles.txt");
    std::ifstream ifs(fileName);
    PrintString pst(ifs);
    // std::cout<<pst()<<std::endl;
    // std::cout<<pst()<<std::endl;
    // std::cout<<pst()<<std::endl;
    /*练习14.36*/
    std::vector<std::string> vecS;
    while (true)
    {
        std::string s=pst();
        if (s!="")
        {
            vecS.push_back(s);
            continue;
        }
        break;
    }
    for (auto &&i : vecS)
    {
        std::cout<<i<<std::endl;
    }
    return 0 ;
}