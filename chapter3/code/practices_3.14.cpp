#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    int in_int;
    string str1;
    vector<int> vec1;
    vector<string> str_vec;
    // while (cin>>in_int)
    // {
    //     vec1.push_back(in_int);
    // }
    // for ( auto veci : vec1)
    // {
    //     cout<<veci<<" ";
    // }
    while (cin>>str1)
    {
        str_vec.push_back(str1);
    }    
    for(auto stri : str_vec){
        cout<<stri<<" ";
    }   
    return 0;
}
