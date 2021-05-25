#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
class moreThan
{
private:
    size_t len;
public:
    moreThan(const size_t& sz):len(sz){}
    bool operator()(const std::string& s){ return s.size()>len;}
};

class lessThan
{
private:
    size_t len;
public:
    lessThan(const size_t& sz):len(sz){}
    bool operator()(const std::string& s){ return s.size()<=len;}
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

    std::cout<<"长度小于等于9数量：" << std::count_if(vecS.cbegin() , vecS.cend() , lessThan(9)) <<std::endl;
    std::cout<<"长度大于10数量：" << std::count_if(vecS.cbegin() , vecS.cend() , moreThan(10)) <<std::endl;
    
    return 0;
}