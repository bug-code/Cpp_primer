#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using std::string;
using std::vector;
using std::partition;
using std::ifstream;
using std::cout;
using std::endl;
bool moreThan5(const string &str){
    return str.size() >= 5;
}
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

void printVec(vector<string>::const_iterator &beg , vector<string>::const_iterator &en ){
    while (beg != en)
    {
        cout<< *beg <<" ";
        ++beg;    
    }
    cout<<endl;
}

int main(){
    vector<string> vecStr;
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter10\\code\\words.txt");
    addToVec(vecStr , fileName);
    auto beg = vecStr.begin() , en = vecStr.end();
    partition(beg , en , moreThan5);
    auto cbeg = vecStr.cbegin() , cen = vecStr.cend();
    printVec(cbeg , cen);
    return 0;
}