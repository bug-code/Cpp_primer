#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::toupper;
int main(){

    vector<string> text_vec;
    string str ;
    auto b = text_vec.begin();
    while (cin>>str)
    {      
        text_vec.push_back(str);
    }
    for (auto &_char:(*b))
    {
        if (isalpha(_char))
        {
            _char = toupper(_char);
        }
        
    }
    cout<<*b<<endl;
    return 0 ;
}