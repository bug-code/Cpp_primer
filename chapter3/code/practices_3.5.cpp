#include <iostream>
#include <string>
#include "windows.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
int main(){
    string str, sum_str , sum_str_blank;
    while (cin>>str)
    {
        sum_str = sum_str+str;
        sum_str_blank = sum_str_blank + " "+str;
    }
    cout<<sum_str<<endl;
    cout<<sum_str_blank<<endl;
    system("pause");
    return 0;
}