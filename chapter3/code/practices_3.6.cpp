#include <iostream>
#include <cctype>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    string str1;
    cin>>str1;
    /*范围for循环*/
    // for(auto &_char : str1){
    //     _char = 'X';
    // }
    
    /*while循环*/
    // decltype(str1.size()) str_index = 0;
    // while (str_index!=str1.size())
    // {
    //     str1[str_index]='X';
    //     ++str_index;
    // }

    /*传统for循环*/
    for (decltype(str1.size()) i = 0; i < str1.size(); i++)
    {
        str1[i] = 'X';
    }

    cout<<str1<<endl;
}