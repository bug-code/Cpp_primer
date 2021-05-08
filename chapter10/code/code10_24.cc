#include <string>
#include <functional>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
using namespace std::placeholders;

bool chech_size(const int &i , const string &s){
    return i > s.size();
}
int main(){
    vector<int> vecStr{0,1,2,3,4,5,6,7,8,9};
    string markS = "NMSL";
    auto index_iter = find_if(vecStr.cbegin() , vecStr.cend() , bind(chech_size ,_1 , markS ));
    cout<<*index_iter<<endl;
}

