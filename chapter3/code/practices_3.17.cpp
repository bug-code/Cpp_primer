#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::toupper;

int main(){
    vector<string> vec_str;
    string str_val;
    while (cin>>str_val)
    {
        for ( auto &_char : str_val)
        {
           _char= toupper(_char);
        }
        
        vec_str.push_back(str_val);
    }

    for (auto &str : vec_str)
    {
        cout<<str<<endl;
    }
    return 0;
}