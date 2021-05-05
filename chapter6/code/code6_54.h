#ifndef CODE6_54_H
#define CODE6_54_H
#include <vector>
#include <string>
inline int int_add(int &a, int &b ){
    return a+b;
};

inline int int_minus(int &a , int &b){
    return a-b;
};

inline int int_times(int &a , int &b){
    return a*b;
};
inline int int_divide(int &a , int &b){
    return b != 0 ? a / b : 0;
};

// auto act_vec()->std::vector<int (*)(int& , int&)>{
//     std::vector<int (*)(int& , int&)>  funcPtr_vec; 
//     funcPtr_vec.push_back(int_add);
//     funcPtr_vec.push_back(int_minus);
//     funcPtr_vec.push_back(int_times);
//     funcPtr_vec.push_back(int_divide);
//     return funcPtr_vec;
// };

int compute_int(int &a , int &b , std::string &oper){
    std::vector<int (*)(int& , int&)>  funcPtr_vec{int_add  , int_minus , int_times , int_divide};
    auto beg = funcPtr_vec.begin();
    if (oper=="+")
    {
        int result = (*beg)(a,b); //?????????????????????????????????????????????????????
        return result;
    }

    
};



#endif