#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    string in_str;
    cin>>in_str;
    if (!in_str.empty())
    {   string out_str;
        for ( auto &_char : in_str)
        {
            if (!ispunct(_char))
            {
                out_str =out_str+_char;
            }
        }
        in_str=out_str;
    }    
    cout<<in_str<<endl;
}