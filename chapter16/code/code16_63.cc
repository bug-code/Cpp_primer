#include "countVal.h"
#include <string>
#include <iostream>
int main(){
    std::vector<int> veci{1,2,43,56,6,3,3,3,3,};
    std::vector<double> vecd{15.45 ,  15.45 , 165.2  , 75.45 , 48.6};
    std::vector<std::string> vecs{"fuck" , "you" , "mother" , "fucker" , "fuck"};
    std::vector<const char*> vecC{"fuck" , "you" , "mother" , "fucker" , "fuck"};
    std::cout<<countVal(veci , 3)<<std::endl;
    std::cout<<countVal(vecd , 165.2)<<std::endl;
    std::cout<<countVal(vecs ,"fuck")<<std::endl;
    std::cout<<countVal(vecC  , "fuck")<<std::endl;
}