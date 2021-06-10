#include <vector>
#include <list>
#include <iostream>
template<typename T> void print(const T& t){
    for (auto beg = t.begin() , en = t.end(); beg != en; ++beg)
    {
        std::cout<<*beg<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    std::list<int> ilst{0,1,2,3,4,5};
    std::vector<int> vec{0,1,2,3,4,5};
    print(vec);
    print(ilst);
    return 0 ;
}