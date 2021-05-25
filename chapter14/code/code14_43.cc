#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
int main(){
    std::vector<int> ivec{7, 8 , 6 ,2 ,5 ,4 ,3 ,1};
    int inVal;
    std::cin>>inVal;
    std::modulus<int> mod;
    auto is_divisible = std::any_of(ivec.cbegin() , ivec.cend() , [&](const int& i){return 0==mod(inVal,i);});
    std::cout<<(is_divisible?"yes":"NO")<<std::endl;
    return 0;
}