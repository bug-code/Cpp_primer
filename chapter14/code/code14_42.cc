#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <algorithm>
#include <iostream>
int main(){
    std::vector<int> ivec;
    for (size_t i = 1000; i < 1060; ++i)
    {
        ivec.push_back(i);
    }
    std::cout<<"大于1024的数字有："<<std::count_if(ivec.cbegin() , ivec.cend() , std::bind(std::greater<int>() , std::placeholders::_1 , 1024) )<<"个"<<std::endl;

    std::transform(ivec.begin() , ivec.end()  , ivec.begin()  , std::bind(std::multiplies<int>() , std::placeholders::_1 , 2) );
    std::for_each(ivec.cbegin() , ivec.cend() , [](const int& i){std::cout<<i<<std::endl;});

    std::vector<std::string> vecS;
    std::string words("pooh pooh pooh pooh fuck you mother fucker");
    std::istringstream iss(words);
    std::string word;
    while (iss>>word)
    {
        vecS.push_back(word);
    }
    auto ptr = std::find_if(vecS.cbegin() , vecS.cend() , std::bind(std::not_equal_to<std::string>() , std::placeholders::_1 , "pooh"));
    std::cout<<"第一个非pooh的单词："<< *ptr<<std::endl;


    
    return 0;
}