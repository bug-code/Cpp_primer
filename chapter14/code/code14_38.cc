#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
class equalLen
{
private:
    size_t len;
public:
    equalLen(const size_t& sz):len(sz){}
    bool operator()(const std::string& s){ return s.size()==len;}
};
int main(){
    std::string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter14\\code\\hundredMiles.txt");
    std::ifstream ifs(fileName);
    std::string line;
    std::vector<std::string> vecS;
    while (std::getline(ifs , line))
    {
        std::istringstream iss(line);
        std::string word;
        while (iss>>word)
        {
            vecS.push_back(word);
        }
    }
    for (size_t i = 1; i < 11; ++i)
    {
       std::cout<<"长度为 "<<i<< "数量：" << std::count_if(vecS.cbegin() , vecS.cend() , equalLen(i)) <<std::endl;
    }
    
    
    return 0;
}
