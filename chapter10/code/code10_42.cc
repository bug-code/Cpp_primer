#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
int main(){
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter10\\code\\words.txt");
    ifstream ifs(fileName);
    if (ifs)
    {
        istream_iterator<string> str_in(ifs) , str_eof;
        list<string> slst(str_in , str_eof);
        slst.sort();
        slst.unique();
        for_each(slst.cbegin() , slst.cend() , [](const string &s){cout<<s<<" ";});
    }
    else
    {
        cerr<<"open file failed! "<<endl;
    }
    
    return 0;
}