#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::count_if;

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


int main(){
    vector<string> vecStr;
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter10\\code\\words.txt");
    addToVec(vecStr , fileName);
    int sz = 6;
    auto counts = count_if(vecStr.cbegin() , vecStr.cend() ,[sz](const string &s){return s.size() > sz ; } ) ;
    cout<<counts<<" " << (counts > 1 ? "words":"word")<<" of length "<<sz<<" or longer."<<endl;
}
