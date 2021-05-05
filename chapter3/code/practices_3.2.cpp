#include <iostream>
#include <string>
#include "windows.h"

using std::string ; 
using std::cin;
using std::cout;
using std::endl;
int  main(){
    // string line;
    // while (getline(cin , line))
    // {
    //     cout<<line<<endl;
    // }
    string word;
    while (cin>>word)
    {
        cout<<word<<endl;
    }
    

    return 0;
}