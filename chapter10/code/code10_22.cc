#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

void addToVec(vector<string> &vec , const string &fileName){
    ifstream ifs(fileName);
    if (ifs)
    {
        string s;
        while (ifs>>s)
        {
            vec.push_back(s);
        }
    }
    else
    {
        std::cerr<<"open file failed"<<endl;
    }
}
bool lessThan(const string &s , const vector<string>::size_type &sz){
    return s.size()<=sz;
}

int main(){
    vector<string> vecStr;
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter10\\code\\words.txt");
    addToVec(vecStr , fileName);
    int sz = 6;
    auto counts = count_if(vecStr.cbegin() , vecStr.cend() , bind(lessThan  , _1 , sz) ) ;
    cout<<counts<<" " << (counts > 1 ? "words":"word")<<" of length "<<sz<<" or shorter."<<endl;
}