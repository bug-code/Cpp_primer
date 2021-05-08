#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
int main(){
    string fileName("F:\\code\\C++_code\\C++ note\\Cpp_primer\\chapter10\\code\\words.txt");
    ifstream ifs(fileName);
    if (ifs)
    {
        istream_iterator<string> str_in(ifs) , str_eof;
        vector<string> vecStr(str_in , str_eof); 
        ostream_iterator<string> str_out(cout," ") ;
        copy(vecStr.cbegin() , vecStr.cend(),str_out);
        cout<<endl;      
    }
    else
    {
        cerr<< "open file failed!"<<endl;
    }
    return 0;
}