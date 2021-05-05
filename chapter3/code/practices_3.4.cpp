#include <iostream>
#include <string>
#include "windows.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){

    //比较并输出较大字符串
    string str1 , str2;
    cin>> str1 >> str2;
    // if (str1!=str2)
    // {
    //     if (str1<=str2)
    //     {
    //         cout<<str2<<endl;
    //     }
    //     else
    //     {
    //         cout<<str1<<endl;
    //     }
        
    // }
    // else
    // {
    //     cout<< "its the same!!" <<endl;
    // }
    //比较字符串长度
    if (str1.size()!=str2.size())
    {
        if (str1.size()<=str2.size())
        {
            cout<<str2<<endl;
        }
        else
        {
            cout<<str1<<endl;
        }
        
    }
    else
    {
        cout<<"its same length"<<endl;
    }
    
    
    return 0;
}